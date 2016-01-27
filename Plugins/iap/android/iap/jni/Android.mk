LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE    := sdkbox
LOCAL_SRC_FILES := ../../sdkbox/libsdkbox.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := iap_static
LOCAL_SRC_FILES := ../libPluginIAP.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := iap
LOCAL_LDLIBS := -landroid -llog
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../../sdkbox-core/csc/protocols/share
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../../sdkbox-core/plugins/iap/share
LOCAL_SRC_FILES := ../../../sdkbox_iap_wrapper.cpp
LOCAL_WHOLE_STATIC_LIBRARIES := iap_static sdkbox
include $(BUILD_SHARED_LIBRARY)
