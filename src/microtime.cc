#include <v8.h>
#include <node.h>

#include <errno.h>

#if defined(_MSC_VER)
    #include <time.h>
    #include <windows.h>

    // The closest thing to gettimeofday in Windows is GetSystemTimeAsFileTime
    // so stub out a gettimeofday() method that uses this
    // NOTE: When I tested on Windows XP, it only gave me about 10ms accuracy
    // (but at least it compiles)

    struct timezone {
        int  tz_minuteswest;
        int  tz_dsttime;
    };

    int gettimeofday(struct timeval *tv, struct timezone *tz) {
        FILETIME ft;
        GetSystemTimeAsFileTime(&ft);
        unsigned long long t = ft.dwHighDateTime;
        t <<= 32;
        t |= ft.dwLowDateTime;
        t /= 10;
        t -= 11644473600000000ULL;
        tv->tv_sec = (long) (t / 1000000UL);
        tv->tv_usec = (long) (t % 1000000UL);

        return 0;
    }
#else
    #include <sys/time.h>
#endif

using namespace v8;
using namespace node;

static Handle<Value> Now(const Arguments &args) {
    HandleScope scope;

    timeval t;
    int r = gettimeofday(&t, NULL);

    if (r < 0) {
        return ThrowException(ErrnoException(errno, "gettimeofday"));
    }

    return scope.Close(Number::New((t.tv_sec * 1000000.0) + t.tv_usec));
}

static Handle<Value> NowDouble(const Arguments &args) {
    HandleScope scope;

    timeval t;
    int r = gettimeofday(&t, NULL);

    if (r < 0) {
        return ThrowException(ErrnoException(errno, "gettimeofday"));
    }

    return scope.Close(Number::New(t.tv_sec + (t.tv_usec * 0.000001)));
}

static Handle<Value> NowStruct(const Arguments &args) {
    HandleScope scope;

    timeval t;
    int r = gettimeofday(&t, NULL);

    if (r < 0) {
        return ThrowException(ErrnoException(errno, "gettimeofday"));
    }

    Local<Array> array = Array::New(2);
    array->Set(Integer::New(0), Uint32::New(t.tv_sec));
    array->Set(Integer::New(1), Uint32::New(t.tv_usec));

    return scope.Close(array);
}

extern "C"
void init( Handle<Object> target ) {
    HandleScope scope;

    NODE_SET_METHOD(target, "now", Now);
    NODE_SET_METHOD(target, "nowDouble", NowDouble);
    NODE_SET_METHOD(target, "nowStruct", NowStruct);
}
NODE_MODULE(microtime,init)
