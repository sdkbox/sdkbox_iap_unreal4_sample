cp sdkbox-core/plugins/iap/share/PluginIAP.h Plugins/Sdkbox/IAP/Source/SdkboxIAP/Classes/.

# jars
cp sdkbox-core/build/v3/csc/android/libs/sdkbox.jar                       Plugins/Sdkbox/IAP/lib/Android/.
cp sdkbox-core/build/v3/plugins/iap/android/libs/PluginIAP.jar            Plugins/Sdkbox/IAP/lib/Android/.

# ios statics
cp sdkbox-core/build/v3/csc/ios/sdkbox.framework/sdkbox                   Plugins/Sdkbox/IAP/lib/iOS/sdkbox.a
cp sdkbox-core/build/v3/plugins/iap/ios/PluginIAP.framework/PluginIAP     Plugins/Sdkbox/IAP/lib/iOS/PluginIAP.a

# android statics
cp sdkbox-core/build/v3/csc/android/jni/sdkbox/libs/armeabi-v7a/libsdkbox.a                  Plugins/Sdkbox/IAP/lib/Android/sdkbox.a
cp sdkbox-core/build/v3/plugins/iap/android/jni/pluginiap/libs/armeabi-v7a/libPluginIAP.a    Plugins/Sdkbox/IAP/lib/Android/PluginIAP.a

# poke out host
# sdkbox-core/poke.py Plugins/Sdkbox/IAP/lib/Android/sdkbox.a cocos2dx UnrealEngine4
# sdkbox-core/poke.py Plugins/Sdkbox/IAP/lib/iOS/sdkbox.a cocos2dx UnrealEngine4

echo Copied SDKBOX files to Unreal Engine 4.
