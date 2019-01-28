#include <errno.h>

#include <napi.h>

#if defined(_MSC_VER)
#include <time.h>
#include <windows.h>

// Pick GetSystemTimePreciseAsFileTime or GetSystemTimeAsFileTime depending
// on which is available at runtime.
typedef VOID(WINAPI *WinGetSystemTime)(LPFILETIME);
static WinGetSystemTime getSystemTime = NULL;

struct timezone {
  int tz_minuteswest;
  int tz_dsttime;
};

int gettimeofday(struct timeval *tv, struct timezone *tz) {
  FILETIME ft;
  (*getSystemTime)(&ft);
  unsigned long long t = ft.dwHighDateTime;
  t <<= 32;
  t |= ft.dwLowDateTime;
  t /= 10;
  t -= 11644473600000000ULL;
  tv->tv_sec = (long)(t / 1000000UL);
  tv->tv_usec = (long)(t % 1000000UL);

  return 0;
}
#else
#include <sys/time.h>
#endif

// A very basic version of Node::ErrnoException since Napi doesn't expose it
Napi::Error ErrnoException(Napi::Env env, int errorno) {
  Napi::Error e = Napi::Error::New(env, strerror(errorno));
  e.Set("syscall", Napi::String::New(env, "gettimeofday"));
  e.Set("errno", Napi::Number::New(env, errno));
  // NOTE: in Node::ErrnoException this would be the string of the code
  // like "EFAULT", just simplify with the number here.
  e.Set("code", Napi::Number::New(env, errno));
  return e;
}

Napi::Value Now(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  timeval t;
  int r = gettimeofday(&t, NULL);

  if (r < 0) {
    ErrnoException(env, errno).ThrowAsJavaScriptException();
    return env.Null();
  }

  return Napi::Number::New(env, ((t.tv_sec * 1000000.0) + t.tv_usec));
}

Napi::Value NowDouble(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  timeval t;
  int r = gettimeofday(&t, NULL);
  if (r < 0) {
    ErrnoException(env, errno).ThrowAsJavaScriptException();
    return env.Null();
  }

  return Napi::Number::New(env, t.tv_sec + (t.tv_usec * 0.000001));
}

Napi::Value NowStruct(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  timeval t;
  int r = gettimeofday(&t, NULL);

  if (r < 0) {
    ErrnoException(env, errno).ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Array array = Napi::Array::New(env, 2);
  array.Set((uint32_t)0, (double)t.tv_sec);
  array.Set((uint32_t)1, (double)t.tv_usec);

  return array;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "now"), Napi::Function::New(env, Now));
  exports.Set(Napi::String::New(env, "nowDouble"),
              Napi::Function::New(env, NowDouble));
  exports.Set(Napi::String::New(env, "nowStruct"),
              Napi::Function::New(env, NowStruct));
#if defined(_MSC_VER)
  getSystemTime = (WinGetSystemTime)GetProcAddress(
      GetModuleHandle(TEXT("kernel32.dll")), "GetSystemTimePreciseAsFileTime");
  if (getSystemTime == NULL) {
    getSystemTime = &GetSystemTimeAsFileTime;
  }
#endif
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init);
