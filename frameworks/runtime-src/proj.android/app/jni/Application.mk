APP_STL := c++_shared

APP_CPPFLAGS := -frtti -DCC_ENABLE_CHIPMUNK_INTEGRATION=1 -fexceptions -std=c++14 -fsigned-char -Wno-extern-c-compat
APP_LDFLAGS := -latomic

APP_ABI := armeabi-v7a x86
APP_SHORT_COMMANDS := true


ifeq ($(NDK_DEBUG),1)
  APP_CPPFLAGS += -DCOCOS2D_DEBUG=1
  APP_OPTIM := debug
else
  APP_CPPFLAGS += -DNDEBUG
  APP_OPTIM := release
endif

LOCAL_ALLOW_UNDEFINED_SYMBOLS := true
