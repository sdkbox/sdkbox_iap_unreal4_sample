cp sdkbox-core/plugins/iap/share/PluginIAP.h Plugins/SdkboxIAP/Source/SdkboxIAP/Classes/.

# jars
cp sdkbox-core/build/v3/csc/android/libs/sdkbox.jar                       Plugins/SdkboxIAP/lib/Android/.
cp sdkbox-core/build/v3/plugins/iap/android/libs/PluginIAP.jar            Plugins/SdkboxIAP/lib/Android/.

# ios statics
cp sdkbox-core/build/v3/csc/ios/sdkbox.framework/sdkbox                   Plugins/SdkboxIAP/lib/iOS/sdkbox.a
cp sdkbox-core/build/v3/plugins/iap/ios/PluginIAP.framework/PluginIAP     Plugins/SdkboxIAP/lib/iOS/PluginIAP.a

# temp android static libs
cp sdkbox-core/build/v3/csc/android/jni/sdkbox/libs_c++_static/armeabi-v7a/libsdkbox.a                  Plugins/iap/android/sdkbox/.
cp sdkbox-core/build/v3/plugins/iap/android/jni/pluginiap/libs_c++_static/armeabi-v7a/libPluginIAP.a    Plugins/iap/android/iap/.

echo Copied SDKBOX files to Unreal Engine 4.

# poke out host
sdkbox-core/poke.py Plugins/iap/android/sdkbox/libsdkbox.a cocos2dx UnrealEngine4
sdkbox-core/poke.py Plugins/SdkboxIAP/lib/iOS/sdkbox.a cocos2dx UnrealEngine4

# build the android .so
pushd Plugins/iap/android/iap
ndk-build
if [ $? -eq 0 ]
then
  echo Android Done.
else
  echo "Failed to build Android libs"
  popd
  exit 1
fi
cp libs/armeabi-v7a/libiap.so ../../../../Plugins/SdkboxIAP/lib/Android/.
popd