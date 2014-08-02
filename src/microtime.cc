#include <node_version.h>

#if NODE_VERSION_AT_LEAST(0, 11, 1) && !defined(_MSC_VER)
    #include <sys/types.h>
#endif
#include <v8.h>
#include <node.h>

#include <errno.h>

#include <nan.h>

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

NAN_METHOD(Now) {
    NanScope();

    timeval t;
    int r = gettimeofday(&t, NULL);

    if (r < 0) {
        return NanThrowError(node::ErrnoException(errno, "gettimeofday"));
    }

    NanReturnValue(NanNew<v8::Number>((t.tv_sec * 1000000.0) + t.tv_usec));
}

NAN_METHOD(NowDouble) {
    NanScope();

    timeval t;
    int r = gettimeofday(&t, NULL);

    if (r < 0) {
        return NanThrowError(node::ErrnoException(errno, "gettimeofday"));
    }

    NanReturnValue(NanNew<v8::Number>(t.tv_sec + (t.tv_usec * 0.000001)));
}

NAN_METHOD(NowStruct) {
    NanScope();

    timeval t;
    int r = gettimeofday(&t, NULL);

    if (r < 0) {
        return NanThrowError(node::ErrnoException(errno, "gettimeofday"));
    }

    v8::Local<v8::Array> array = NanNew<v8::Array>(2);
    array->Set(NanNew<v8::Integer>(0), NanNew<v8::Number>((double)t.tv_sec));
    array->Set(NanNew<v8::Integer>(1), NanNew<v8::Number>((double)t.tv_usec));

    NanReturnValue(array);
}

void InitAll(v8::Handle<v8::Object> exports) {
    exports->Set(NanNew<v8::String>("now"),
            NanNew<v8::FunctionTemplate>(Now)->GetFunction());
    exports->Set(NanNew<v8::String>("nowDouble"),
            NanNew<v8::FunctionTemplate>(NowDouble)->GetFunction());
    exports->Set(NanNew<v8::String>("nowStruct"),
            NanNew<v8::FunctionTemplate>(NowStruct)->GetFunction());
}

NODE_MODULE(microtime, InitAll)
