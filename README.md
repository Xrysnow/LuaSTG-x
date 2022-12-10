# LuaSTG-x

### [English Readme](README.md) | [中文简介](README_ZH.md)

---

LuaSTG-x is a multi-platform game engine based on [cocos2d-x](https://github.com/cocos2d/cocos2d-x) and [LuaSTGPlus](https://github.com/9chu/LuaSTGPlus). It is aimed at providing a powerful engine for building [STG](https://en.wikipedia.org/wiki/Shoot_%27em_up), especially [bullet hell](https://en.wikipedia.org/wiki/Shoot_%27em_up#Bullet_hell) games.

---

## [Gallery](https://github.com/Xrysnow/LuaSTG-x/wiki/Gallery) | [Core API Manual](https://github.com/Xrysnow/LuaSTG-x/wiki/Core_API_Manual) | [Changelog](https://github.com/Xrysnow/LuaSTG-x/wiki/Changelog)

## Download

Full release download:

- [mega](https://mega.nz/folder/WVAQwYzA#X9g-KiulLMUZfdn8DDV72g)
- [baidu](https://pan.baidu.com/s/11TeRowwODzz7ZjMEmeJkbA) (bmna)

## Main Features

- Complete 2D game engine functions from [cocos2d-x](https://github.com/cocos2d/cocos2d-x).
- [Multi-platform audio engine](https://github.com/Xrysnow/lstgx_Audio), supports audio effects.
- [Multi-platform video engine](https://github.com/Xrysnow/lstgx_Video) based on FFmpeg.
- Cocos Creator support from [creator_to_cocos2dx](https://github.com/cocos2d/creator_to_cocos2dx).
- [Live2D support with Lua binding](https://github.com/Xrysnow/cocos2d-x-live2d).
- [ImGui support with Lua binding](https://github.com/Xrysnow/cocos2d-x-imgui).
- Multi-thread optimizations.

## Relevant Link

- [LuaSTG-x GitHub Wiki](https://github.com/Xrysnow/LuaSTG-x/wiki)
- [LuaSTG-x Lua API Document](https://xrysnow.github.io/lstgx_Doc)
- [Baidu Tieba](https://tieba.baidu.com/f?kw=luastg)
- [LuaSTG Wiki Site](http://en.luastg.shoutwiki.com/wiki/Main_Page)
- [Bullet Hell Engines Discord Channel](https://discord.gg/4wNvvPHxeU)

## Build Instructions

1. Clone the repo and submodules from GitHub (or download from [release page](https://github.com/Xrysnow/LuaSTG-x/releases)).

        $ git clone --recursive https://github.com/Xrysnow/LuaSTG-x.git

2. Clone external libraries into `frameworks/cocos2d-x/external` (or download from [release page](https://github.com/Xrysnow/cocos2d-x-3rd-party-libs-bin/releases)).

        $ cd LuaSTG-x/frameworks/cocos2d-x/external
        $ git clone --recursive https://github.com/Xrysnow/cocos2d-x-3rd-party-libs-bin.git

3. Download extra files from Cubism SDK if you need live2d module. ([instructions](https://github.com/Xrysnow/cocos2d-x-live2d)).

4. Generate project using CMake ([instructions](https://github.com/cocos2d/cocos2d-x/blob/v4/cmake/README.md)).
   - If your target is Android platform, just open `frameworks/runtime-src/proj.android` with Android Studio.
   - If your target is macOS platform, add `-GXcode` parameter to CMake.
   - If your target is IOS platform, you can search for a bash script that helps to configure CMake.
   - If your target is macOS/IOS platform, you need to open `project setting -> TARGETS -> LuaSTG-x -> Build Phases -> Copy Files` and check `Code Sigh On Copy` for frameworks.
   - If your target is Linux platform, you need to execute `frameworks/cocos2d-x/install-deps-linux.sh` before using CMake. It's recommended to add `-GNinja` parameter to use `ninja` since default `make` is very slow.

5. Compile with your target compiler.

## Build Requirements

- CMake 3.20+
- Android Studio 2020.3.1+ and NDK r22+
- Linux with compiler supports C++17 (Clang is recommended)
- macOS 11.3+ and Xcode 13+
- Windows 7+ and VS 2019+

## Runtime Requirements

Runtime requirements is actually decided by your compiler, but in most cases they should satisfy these conditions:

- Android 5.0+
- iOS 13+
- macOS 10.15+
- Windows 7+ and visual c++ runtime

Note that iOS 13+ and macOS 10.15+ is always required for `std::filesystem` ([source](https://developer.apple.com/documentation/xcode-release-notes/xcode-11-release-notes)).

## Dependency Graph

LuaSTG-x\
├　[cocos2d-x](https://github.com/Xrysnow/cocos2d-x)\
├　[lstgx_Audio](https://github.com/Xrysnow/lstgx_Audio)\
│　　└ [openal-soft](https://github.com/kcat/openal-soft) (in lstgx_external)\
├　[lstgx_external](https://github.com/Xrysnow/lstgx_external)\
│　　├ [ANGLE](https://github.com/google/angle) (optional)\
│　　├ [BurstLinker](https://github.com/Xrysnow/BurstLinker)\
│　　├ [cLaTeXMath](https://github.com/NanoMichael/cLaTeXMath)\
│　　├ [FairyGUI](https://github.com/fairygui/FairyGUI-cocos2dx) (optional)\
│　　├ [FFmpeg](http://ffmpeg.org) (optional)\
│　　├ [libzippp](https://github.com/ctabin/libzippp)\
│　　│　└ [libzip](https://github.com/nih-at/libzip)\
│　　├ [Lua CJSON](https://kyne.com.au/~mark/software/lua-cjson.php)\
│　　├ [luafilesystem](http://keplerproject.github.io/luafilesystem)\
│　　├ [LPeg](http://www.inf.puc-rio.br/~roberto/lpeg)\
│　　├ [nanosvg](https://github.com/memononen/nanosvg)\
│　　├ [NativeFileDialog](https://github.com/mlabbe/nativefiledialog)\
│　　├ [libogg](https://xiph.org/ogg)\
│　　├ [openal-soft](https://github.com/kcat/openal-soft)\
│　　├ [yasio](https://github.com/yasio/yasio) (optional)\
│　　└ [Yuescript](https://github.com/pigpigyyy/Yuescript) (optional)\
├　[lstgx_Math](https://github.com/Xrysnow/lstgx_Math)\
├　[lstgx_LuaCore](https://github.com/Xrysnow/lstgx_LuaCore)\
├　[cocos2d-x-imgui](https://github.com/Xrysnow/cocos2d-x-imgui)\
│　　├ [ImGui](https://github.com/ocornut/imgui)\
│　　├ [imgui_markdown](https://github.com/juliettef/imgui_markdown)\
│　　├ [ImGuiColorTextEdit](https://github.com/Xrysnow/ImGuiColorTextEdit)\
│　　└ [implot](https://github.com/epezent/implot)\
├　[cocos2d-x-live2d](https://github.com/Xrysnow/cocos2d-x-live2d) (optional)\
│　├ [CubismNativeFramework](https://github.com/Live2D/CubismNativeFramework)\
│　└ [Cubism SDK for Native](https://www.live2d.com/en/download/cubism-sdk/download-native)\
├　[cocos2d-x-video](https://github.com/Xrysnow/cocos2d-x-video)\
│　　└ [FFmpeg](http://ffmpeg.org) (in lstgx_external)\
└　[creator_to_cocos2dx](https://github.com/Xrysnow/creator_to_cocos2dx)
