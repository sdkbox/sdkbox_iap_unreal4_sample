/*****************************************************************************
Copyright © 2015 SDKBOX Inc.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*****************************************************************************/

#include "PluginIAP.h"

#ifdef __ANDROID__
#include <jni.h>
#include <android/log.h>

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
    __android_log_print(ANDROID_LOG_ERROR, "SDKBOX IAP", "JNI_OnLoad ENTER");
        
	JNIEnv* env = 0;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_4) != JNI_OK) {
        return -1;
    }

	extern void JNICALL Java_com_sdkbox_plugin_SDKBox_nativeInit(JNIEnv *env, jobject thiz);
    Java_com_sdkbox_plugin_SDKBox_nativeInit(env, 0);

    __android_log_print(ANDROID_LOG_ERROR, "SDKBOX IAP", "JNI_OnLoad returning JNI_VERSION_1_4");

    return JNI_VERSION_1_4;
}

JNIEXPORT void sdkbox_IAP_purchase(const char* name)
{
    __android_log_print(ANDROID_LOG_ERROR, "SDKBOX IAP", "sdkbox_IAP_purchase");
    sdkbox::IAP::purchase(name);
}

#ifdef __cplusplus
}
#endif

#endif//__ANDROID__
