# LuaSTG-x

LuaSTG-x is a multi-platform game engine based on [cocos2d-x](https://github.com/cocos2d/cocos2d-x) and [LuaSTGPlus](https://github.com/9chu/LuaSTGPlus). It is aimed at providing a powerful engine for building [STG](https://en.wikipedia.org/wiki/Shoot_%27em_up), especially [bullet hell](https://en.wikipedia.org/wiki/Shoot_%27em_up#Bullet_hell) games.

## Build Instructions

1. Clone the repo and submodules from GitHub (or download from release).

        $ git clone --recursive https://github.com/Xrysnow/LuaSTG-x.git

2. Clone external libraries into `frameworks/cocos2d-x/external` (or download from release).

        $ cd LuaSTG-x/frameworks/cocos2d-x/external
        $ git clone https://github.com/Xrysnow/cocos2d-x-3rd-party-libs-bin.git

3. Download extra files from Cubism SDK ([instructions](https://github.com/Xrysnow/cocos2d-x-live2d)).

4. Generate project using CMake ([instructions](https://github.com/cocos2d/cocos2d-x/blob/v4/cmake/README.md)).

        $ mkdir build
        $ cd build
        $ cmake ..

5. Compile with your target compiler.

## Build Requirements

- CMake 3.10+
- Android Studio 3.3.0+ and NDK r16+
- OS X 10.9+ and Xcode 9+
- or Linux with CC supports c++11
- or Windows 7+ and VS 2017+

## Runtime Requirements

Runtime requirements is actually decided by your compiler, but in most cases they should satisfy these conditions:

- Android 4.0+
- iOS 8.0+
- OS X v10.9+
- Windows 7+ and visual c++ runtime

## Main Features

- Complete 2D game engine functions from [cocos2d-x](https://github.com/cocos2d/cocos2d-x).
- [Multi-platform audio engine](https://github.com/Xrysnow/lstgx_Audio), supports audio effects.
- [Multi-platform video engine](https://github.com/Xrysnow/lstgx_Video) based on FFmpeg.
- Cocos Creator support from [creator_to_cocos2dx](https://github.com/cocos2d/creator_to_cocos2dx).
- [Live2D support with Lua binding](https://github.com/Xrysnow/cocos2d-x-live2d).
- [ImGui support with Lua binding](https://github.com/Xrysnow/cocos2d-x-imgui).
- Multi-thread optimizations.
- Console window on desktop platforms.

## Dependency Graph

LuaSTG-x\
©À¡¡[cocos2d-x](https://github.com/Xrysnow/cocos2d-x)\
©À¡¡[lstgx_Audio](https://github.com/Xrysnow/lstgx_Audio)\
©¦¡¡¡¡©¸ [openal-soft](https://github.com/kcat/openal-soft) (in lstgx_external)\
©À¡¡[lstgx_external](https://github.com/Xrysnow/lstgx_external)\
©¦¡¡¡¡©À [BurstLinker](https://github.com/Xrysnow/BurstLinker)\
©¦¡¡¡¡©À [luafilesystem](http://keplerproject.github.io/luafilesystem)\
©¦¡¡¡¡©À [LPeg](http://www.inf.puc-rio.br/~roberto/lpeg)\
©¦¡¡¡¡©À [NativeFileDialog](https://github.com/mlabbe/nativefiledialog)\
©¦¡¡¡¡©À [libogg](https://xiph.org/ogg)\
©¦¡¡¡¡©À [openal-soft](https://github.com/kcat/openal-soft)\
©¦¡¡¡¡©À [cLaTeXMath](https://github.com/NanoMichael/cLaTeXMath)\
©¦¡¡¡¡©À [FFmpeg](http://ffmpeg.org)\
©¦¡¡¡¡©À [nanosvg](https://github.com/memononen/nanosvg)\
©¦¡¡¡¡©¸ [libzippp](https://github.com/ctabin/libzippp)\
©¦¡¡¡¡¡¡©¸ [libzip](https://github.com/nih-at/libzip)\
©À¡¡[lstgx_Math](https://github.com/Xrysnow/lstgx_Math)\
©À¡¡[lstgx_LuaCore](https://github.com/Xrysnow/lstgx_LuaCore)\
©À¡¡[cocos2d-x-imgui](https://github.com/Xrysnow/cocos2d-x-imgui)\
©¦¡¡¡¡©¸ [ImGui](https://github.com/ocornut/imgui)\
©À¡¡[cocos2d-x-live2d](https://github.com/Xrysnow/cocos2d-x-live2d)\
©¦¡¡©À [CubismNativeFramework](https://github.com/Xrysnow/CubismNativeFramework)\
©¦¡¡©¸ [Cubism SDK for Native](https://www.live2d.com/en/download/cubism-sdk/download-native)\
©À¡¡[cocos2d-x-video](https://github.com/Xrysnow/cocos2d-x-video)\
©¦¡¡¡¡©¸ [FFmpeg](http://ffmpeg.org) (in lstgx_external)\
©¸¡¡[creator_to_cocos2dx](https://github.com/Xrysnow/creator_to_cocos2dx)
