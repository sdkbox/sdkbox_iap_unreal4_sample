#!/bin/bash -e

# https://stackoverflow.com/questions/2870992/automatic-exit-from-bash-shell-script-on-error?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
# Automatic exit from bash shell script on error
# set -e


# 0. check ENV
if [ -z "$CSC_PATH" ]; then
    echo "Need to set CSC_PATH with /path/to/sdkbox-core"
    exit 1
fi
echo "CSC_PATH =" $CSC_PATH


# 1. Build plugin for Unreal engine
if [[ ! -d sdkbox-core ]]; then
    lxn -sv $CSC_PATH .
fi
pushd sdkbox-core
./build.py -g iap --host UnrealEngine4
popd
echo "Build SDKBox IAP Plugin Done."


# 2. copy IAP libs
cp -v sdkbox-core/plugins/iap/share/PluginIAP.h Plugins/Sdkbox/IAP/Source/SdkboxIAP/Classes/.

# jars
cp -v sdkbox-core/build/v3/csc/android/libs/sdkbox.jar                       Plugins/Sdkbox/IAP/lib/Android/.
cp -v sdkbox-core/build/v3/plugins/iap/android/libs/PluginIAP.jar            Plugins/Sdkbox/IAP/lib/Android/.

# ios statics
cp -v sdkbox-core/build/v3/csc/ios/sdkbox.framework/sdkbox                   Plugins/Sdkbox/IAP/lib/iOS/sdkbox.a
cp -v sdkbox-core/build/v3/plugins/iap/ios/PluginIAP.framework/PluginIAP     Plugins/Sdkbox/IAP/lib/iOS/PluginIAP.a

# android statics
cp -v sdkbox-core/build/v3/csc/android/jni/sdkbox/libs/armeabi-v7a/libsdkbox.a                  Plugins/Sdkbox/IAP/lib/Android/sdkbox.a
cp -v sdkbox-core/build/v3/plugins/iap/android/jni/pluginiap/libs/armeabi-v7a/libPluginIAP.a    Plugins/Sdkbox/IAP/lib/Android/PluginIAP.a

# poke out host
# sdkbox-core/poke.py Plugins/Sdkbox/IAP/lib/Android/sdkbox.a cocos2dx UnrealEngine4
# sdkbox-core/poke.py Plugins/Sdkbox/IAP/lib/iOS/sdkbox.a cocos2dx UnrealEngine4

echo "Copied SDKBox IAP files to Unreal Engine 4."
