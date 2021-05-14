# LuaSTG-x

## [English Readme](README.md) | [中文简介](README_ZH.md)

---

LuaSTG-x 是一个基于 [cocos2d-x](https://github.com/cocos2d/cocos2d-x) 和 [LuaSTGPlus](https://github.com/9chu/LuaSTGPlus) 的多平台游戏引擎。其目标是为 [清版射击游戏](https://zh.wikipedia.org/wiki/%E6%B8%85%E7%89%88%E5%B0%84%E5%87%BB%E6%B8%B8%E6%88%8F) 和 [弹幕射击游戏](https://zh.wikipedia.org/wiki/%E5%BD%88%E5%B9%95%E5%B0%84%E6%93%8A%E9%81%8A%E6%88%B2) 提供好用的引擎。

---

## [图片演示](https://github.com/Xrysnow/LuaSTG-x/wiki/%E5%9B%BE%E7%89%87%E6%BC%94%E7%A4%BA) | [核心API手册（英文）](https://github.com/Xrysnow/LuaSTG-x/wiki/Core_API_Manual) | [更新日志](https://github.com/Xrysnow/LuaSTG-x/wiki/%E6%9B%B4%E6%96%B0%E6%97%A5%E5%BF%97)

---

## 下载

完整发布版本下载：

- [百度网盘](https://pan.baidu.com/s/11TeRowwODzz7ZjMEmeJkbA) (提取码：bmna)
- [mega](https://mega.nz/folder/WVAQwYzA#X9g-KiulLMUZfdn8DDV72g)

## 主要特性

- 来自 [cocos2d-x](https://github.com/cocos2d/cocos2d-x) 的完整 2D 游戏引擎功能
- [多平台的音频引擎](https://github.com/Xrysnow/lstgx_Audio)，支持声音效果
- [多平台的视频引擎](https://github.com/Xrysnow/lstgx_Video)，基于 FFmpeg
- 基于 [creator_to_cocos2dx](https://github.com/cocos2d/creator_to_cocos2dx) 的 Cocos Creator 支持
- [Live2D 支持及 Lua 绑定](https://github.com/Xrysnow/cocos2d-x-live2d)
- [ImGui 支持及 Lua 绑定](https://github.com/Xrysnow/cocos2d-x-imgui)
- 多线程优化

## 相关链接

- [LuaSTG-x GitHub Wiki](https://github.com/Xrysnow/LuaSTG-x/wiki)
- [LuaSTG-x Lua API 文档](https://xrysnow.github.io/lstgx_Doc)
- [百度贴吧](https://tieba.baidu.com/f?kw=luastg)
- [LuaSTG Wiki 网站](http://en.luastg.shoutwiki.com/wiki/Main_Page)
- [Bullet Hell Engines Discord 频道](https://discordapp.com/invite/TYvazgV)

## 编译指南

1. 克隆本仓库及子模块（或从 [release 页面](https://github.com/Xrysnow/LuaSTG-x/releases) 下载）

        $ git clone --recursive https://github.com/Xrysnow/LuaSTG-x.git

2. 克隆外部库至 `frameworks/cocos2d-x/external` （或从 [release 页面](https://github.com/Xrysnow/cocos2d-x-3rd-party-libs-bin/releases) 下载）

        $ cd LuaSTG-x/frameworks/cocos2d-x/external
        $ git clone https://github.com/Xrysnow/cocos2d-x-3rd-party-libs-bin.git

3. 若需要使用 live2d 模块，请下载 Cubism SDK （[指南](https://github.com/Xrysnow/cocos2d-x-live2d)）

4. 使用 CMake 生成工程文件 ([指南](https://github.com/cocos2d/cocos2d-x/blob/v4/cmake/README.md)).
   - 若目标为安卓平台，只需用 Android Studio 打开 `frameworks/runtime-src/proj.android`
   - 若目标为 macOS 平台，需要向 cmake 添加 `-GXcode` 参数
   - 若目标为 IOS 平台，需要额外设置 cmake ，你可以找到一些 bash 脚本来实现
   - 若目标为 macOS/IOS 平台，需要打开 `project setting -> TARGETS -> LuaSTG-x -> Build Phases -> Copy Files` 并为 frameworks 勾选 `Code Sigh On Copy`

5. 使用编译器进行编译

## 编译要求

- CMake 3.15+
- Android Studio 3.3.0+ 和 NDK r16+
- OS X 10.9+ 和 Xcode 9+
- 或编译器支持 c++11 的 Linux
- 或 Windows 7+ 和 VS 2019+

## 运行要求

运行要求实际上由编译器决定，但大多数情况下应满足如下要求：

- Android 5.0+
- iOS 8.0+
- OS X 10.9+
- Windows 7+ 和 visual c++ 运行时

## 依赖图

LuaSTG-x\
├　[cocos2d-x](https://github.com/Xrysnow/cocos2d-x)\
├　[lstgx_Audio](https://github.com/Xrysnow/lstgx_Audio)\
│　　└ [openal-soft](https://github.com/kcat/openal-soft) （在 lstgx_external 中）\
├　[lstgx_external](https://github.com/Xrysnow/lstgx_external)\
│　　├ [BurstLinker](https://github.com/Xrysnow/BurstLinker)\
│　　├ [luafilesystem](http://keplerproject.github.io/luafilesystem)\
│　　├ [LPeg](http://www.inf.puc-rio.br/~roberto/lpeg)\
│　　├ [NativeFileDialog](https://github.com/mlabbe/nativefiledialog)\
│　　├ [libogg](https://xiph.org/ogg)\
│　　├ [openal-soft](https://github.com/kcat/openal-soft)\
│　　├ [cLaTeXMath](https://github.com/NanoMichael/cLaTeXMath)\
│　　├ [FFmpeg](http://ffmpeg.org)\
│　　├ [nanosvg](https://github.com/memononen/nanosvg)\
│　　└ [libzippp](https://github.com/ctabin/libzippp)\
│　　　└ [libzip](https://github.com/nih-at/libzip)\
├　[lstgx_Math](https://github.com/Xrysnow/lstgx_Math)\
├　[lstgx_LuaCore](https://github.com/Xrysnow/lstgx_LuaCore)\
├　[cocos2d-x-imgui](https://github.com/Xrysnow/cocos2d-x-imgui)\
│　　├ [ImGui](https://github.com/ocornut/imgui)\
│　　├ [imgui_markdown](https://github.com/juliettef/imgui_markdown)\
│　　├ [ImGuiColorTextEdit](https://github.com/Xrysnow/ImGuiColorTextEdit)\
│　　└ [implot](https://github.com/epezent/implot)\
├　[cocos2d-x-live2d](https://github.com/Xrysnow/cocos2d-x-live2d)\
│　├ [CubismNativeFramework](https://github.com/Live2D/CubismNativeFramework)\
│　└ [Cubism SDK for Native](https://www.live2d.com/en/download/cubism-sdk/download-native)\
├　[cocos2d-x-video](https://github.com/Xrysnow/cocos2d-x-video)\
│　　└ [FFmpeg](http://ffmpeg.org) （在 lstgx_external 中）\
└　[creator_to_cocos2dx](https://github.com/Xrysnow/creator_to_cocos2dx)
