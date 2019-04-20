# LuaSTG-x

LuaSTG-x is a multi-platform game engine based on [cocos2d-x](https://github.com/cocos2d/cocos2d-x) and [LuaSTGPlus](https://github.com/9chu/LuaSTGPlus). It is aimed at providing a powerful engine for building [STG](https://en.wikipedia.org/wiki/Shoot_%27em_up), especially [bullet hell](https://en.wikipedia.org/wiki/Shoot_%27em_up#Bullet_hell) games.

## Build Instructions

1. Clone the repo and submodules from GitHub.

        $ git clone --recursive https://github.com/Xrysnow/LuaSTG-x.git

2. Execute `download-deps.py` to download and install dependencies (need python 2.7).

        $ cd LuaSTG-x
        $ python frameworks/cocos2d-x/download-deps.py

3. Download extra files from Cubism SDK ([instructions](https://github.com/Xrysnow/lstgx_external)).
4. Generate project using CMake ([instructions](https://github.com/cocos2d/cocos2d-x/blob/v3/cmake/README.md)).

        $ mkdir build
        $ cd build
        $ cmake ..

5. Compile with your target compiler.

## Build Requirements

- Mac OS X 10.7+, Xcode 8+
- or Ubuntu 14.04+, CMake 3.1+
- or Windows 7+, VS 2015+
- Python 2.7.5+
- NDK r16+ and Android Studio 3.0.0+ to build Android games

## Runtime Requirements

- Android 4.0+
- iOS 8.0+
- OS X v10.9+
- Windows 7+

## Main Features

- Complete 2D game engine functions from [cocos2d-x](https://github.com/cocos2d/cocos2d-x).
- [Math library](https://github.com/Xrysnow/lstgx_Math) with rich functions.
- [Multi-platform audio engine](https://github.com/Xrysnow/lstgx_Audio) based on cocos2d-x's, modified to support A-B loop playback.
- [Multi-platform video engine](https://github.com/Xrysnow/lstgx_Video) based on FFmpeg.
- Cocos Creator support from [creator_to_cocos2dx](https://github.com/cocos2d/creator_to_cocos2dx).
- Live2D support based on [Cubism SDK](https://live2d.github.io/).
- Multi-thread optimizations.
- Console window on desktop platforms.
