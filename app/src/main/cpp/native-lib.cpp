#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_rx_jnitests_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_rx_jnitests_MainActivity_getStr(JNIEnv *env, jobject instance, jstring s_) {
    //获取字符串指针，必须使用指针，不能使用char strContent[],因为GetStringUTFChars()返回值为const char *;
    const char *strContent = env->GetStringUTFChars(s_, JNI_FALSE);
    char str[] = "欢迎你的到来！";
    //字符串拼接,实现strContent+str1,因为strcat的第一个参数必须为非const类型(可变)，所以不能直接使用strcat()
    //创建一个新的字符串指针
    char *strTemp = (char *) malloc(strlen(strContent) + strlen(str) + 1);
    //拷贝常量到字符串指针
    strcpy(strTemp, strContent);
    //拼接str1到strTemp
    strcat(strTemp, str);
    //返回一个utf的jstring
    return env->NewStringUTF(strTemp);
}