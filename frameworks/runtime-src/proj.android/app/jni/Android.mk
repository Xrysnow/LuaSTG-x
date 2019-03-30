LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)


LOCAL_MODULE := cocos2dlua_shared

LOCAL_MODULE_FILENAME := libcocos2dlua

#LOCAL_SRC_FILES := \
#../../../Classes/AppDelegate.cpp \
#hellolua/main.cpp
#LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../Classes

############################################################

# 配置自己的源文件目录和源文件后缀名
MY_FILES_PATH  :=  $(LOCAL_PATH) \
                   $(LOCAL_PATH)/../../../Classes \
#                   $(LOCAL_PATH)/../../../external/ffmpeg \
                   $(LOCAL_PATH)/../../../external/OggDecoder \
                   $(LOCAL_PATH)/../../../external/OpenalSoft
#                   $(LOCAL_PATH)/../../../external

MY_FILES_SUFFIX := %.cpp %.c

# 递归遍历目录下的所有的文件
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

# 获取相应的源文件
MY_ALL_FILES := $(foreach src_path,$(MY_FILES_PATH), $(call rwildcard,$(src_path),*.*) )
MY_ALL_FILES := $(MY_ALL_FILES:$(MY_CPP_PATH)/./%=$(MY_CPP_PATH)%)
MY_SRC_LIST  := $(filter $(MY_FILES_SUFFIX),$(MY_ALL_FILES))
MY_SRC_LIST  := $(MY_SRC_LIST:$(LOCAL_PATH)/%=%)

# 去除字串的重复单词
define uniq =
  $(eval seen :=)
  $(foreach _,$1,$(if $(filter $_,${seen}),,$(eval seen += $_)))
  ${seen}
endef

# 递归遍历获取所有目录
MY_ALL_DIRS := $(dir $(foreach src_path,$(MY_FILES_PATH), $(call rwildcard,$(src_path),*/) ) )
MY_ALL_DIRS := $(call uniq,$(MY_ALL_DIRS))

# 赋值给NDK编译系统
LOCAL_SRC_FILES  := $(MY_SRC_LIST)
LOCAL_C_INCLUDES := $(MY_ALL_DIRS)

############################################################

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END

LOCAL_STATIC_LIBRARIES := cocos2d_lua_static
LOCAL_SHARED_LIBRARIES := libffmpeg-prebuilt libogg-prebuilt libvorbis-prebuilt libvorbisfile-prebuilt libopenal-prebuilt

LOCAL_STATIC_LIBRARIES += creator_reader      # add dependence
LOCAL_STATIC_LIBRARIES += creator_reader_lua  # for lua project
LOCAL_STATIC_LIBRARIES += libLive2DCubismCore

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-add-path, $(LOCAL_PATH)/../../../../cocos2d-x)
$(call import-add-path, $(LOCAL_PATH)/../../../../runtime-src/Classes)
$(call import-add-path, $(LOCAL_PATH)/../../../../runtime-src/external)

# external
$(call import-module, OggDecoder/prebuilt_android/ogg)
$(call import-module, OggDecoder/prebuilt_android/vorbis)
$(call import-module, OggDecoder/prebuilt_android/vorbisfile)
$(call import-module, OpenalSoft/prebuilt_android)
$(call import-module, ffmpeg/prebuilt_android)
$(call import-module, Cubism/lib/android)
# reader
$(call import-module, reader)


$(call import-module, cocos/scripting/lua-bindings/proj.android)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
