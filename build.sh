cp sdkbox-core/plugins/iap/share/PluginIAP.h Plugins/SdkboxIAP/Source/SdkboxIAP/Classes/.

# jars
cp sdkbox-core/build/v3/csc/android/libs/sdkbox.jar                       Plugins/SdkboxIAP/lib/Android/.
cp sdkbox-core/build/v3/plugins/iap/android/libs/PluginIAP.jar            Plugins/SdkboxIAP/lib/Android/.

# ios statics
cp sdkbox-core/build/v3/csc/ios/sdkbox.framework/sdkbox                   Plugins/SdkboxIAP/lib/iOS/sdkbox.a
cp sdkbox-core/build/v3/plugins/iap/ios/PluginIAP.framework/PluginIAP     Plugins/SdkboxIAP/lib/iOS/PluginIAP.a

# android statics
cp sdkbox-core/build/v3/csc/android/jni/sdkbox/libs/armeabi-v7a/libsdkbox.a                  Plugins/SdkboxIAP/lib/Android/sdkbox.a
cp sdkbox-core/build/v3/plugins/iap/android/jni/pluginiap/libs/armeabi-v7a/libPluginIAP.a    Plugins/SdkboxIAP/lib/Android/PluginIAP.a

# poke out host
sdkbox-core/poke.py Plugins/SdkboxIAP/lib/Android/sdkbox.a cocos2dx UnrealEngine4
sdkbox-core/poke.py Plugins/SdkboxIAP/lib/iOS/sdkbox.a cocos2dx UnrealEngine4

echo Copied SDKBOX files to Unreal Engine 4.