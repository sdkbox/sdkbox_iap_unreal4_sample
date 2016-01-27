LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE    := sdkbox_static
LOCAL_SRC_FILES := ../libsdkbox.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := sdkbox
LOCAL_STATIC_LIBRARIES := sdkbox_static
include $(BUILD_SHARED_LIBRARY)
