#include <jni.h>
#include <string>

void third(){
    assert(1==0);
}

int second(){
    third();
    return 2;
}

int first(){
    second();
    return 1;
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_harndkcrash_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    first();
    return env->NewStringUTF(hello.c_str());
}


