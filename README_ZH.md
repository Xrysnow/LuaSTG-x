# LuaSTG-x

### [English Readme](README.md) | 中文简介

---

LuaSTG-x 是一个基于 [cocos](https://github.com/Xrysnow/cocos-x) 和 [LuaSTGPlus](https://github.com/9chu/LuaSTGPlus) 的多平台游戏引擎。其目标是为 [清版射击游戏](https://zh.wikipedia.org/wiki/%E6%B8%85%E7%89%88%E5%B0%84%E5%87%BB%E6%B8%B8%E6%88%8F) 和 [弹幕射击游戏](https://zh.wikipedia.org/wiki/%E5%BD%88%E5%B9%95%E5%B0%84%E6%93%8A%E9%81%8A%E6%88%B2) 提供好用的引擎。

---

## [图片演示](https://github.com/Xrysnow/LuaSTG-x/wiki/%E5%9B%BE%E7%89%87%E6%BC%94%E7%A4%BA) | [核心API手册（英文）](https://github.com/Xrysnow/LuaSTG-x/wiki/Core_API_Manual) | [更新日志](https://github.com/Xrysnow/LuaSTG-x/wiki/%E6%9B%B4%E6%96%B0%E6%97%A5%E5%BF%97)

## 下载

运行素材与完整发布版本下载：

- [百度网盘](https://pan.baidu.com/s/1HBgVs32_QVsUhJy8FPOHBg?pwd=lstg)
- [mega](https://mega.nz/folder/SAQmjbbR#kLBQU_UNMZwmoYJhnQZjZA)

## 主要特性

- 来自 [cocos](https://github.com/Xrysnow/cocos-x) 的完整游戏引擎功能
- [多平台音频引擎](https://github.com/Xrysnow/cocos-x/tree/main/cocos/audio)，支持声音效果
- [多平台视频引擎](https://github.com/Xrysnow/cocos-x/tree/main/cocos/video)，基于 FFmpeg
- [Live2D 支持](https://github.com/Xrysnow/cocos-x-live2d)
- [ImGui 支持](https://github.com/Xrysnow/cocos-x-imgui)
- 多线程优化

## 相关链接

- [LuaSTG-x GitHub Wiki](https://github.com/Xrysnow/LuaSTG-x/wiki)
- [LuaSTG-x Lua API 文档](https://xrysnow.github.io/lstgx_Doc)
- [百度贴吧](https://tieba.baidu.com/f?kw=luastg)
- [LuaSTG Wiki 网站](http://en.luastg.shoutwiki.com/wiki/Main_Page)
- [Bullet Hell Engines Discord 频道](https://discord.gg/4wNvvPHxeU)

## 编译指南

[详细编译指南](document/build/BUILD_ZH.md)

## 编译要求

- CMake 3.28+
- Android Studio 2025.1.1+ 和 NDK r30+
- 编译器支持 C++20 的 Linux (推荐使用Clang)
- macOS 14+ 和 Xcode 16.3+
- Windows 7+ 和 VS 2022+

## 运行要求

运行要求实际上由编译器决定，但大多数情况下应满足如下要求：

- Android 7.0+
- iOS 17+
- macOS 12+
- Windows 7+ 和 Visual C++ 运行时

注意，iOS 和 macOS 的版本要求是必须的，因为需要支持项目的 C++ 版本特性。

## 依赖图

LuaSTG-x\
├　[cocos-x](https://github.com/Xrysnow/cocos-x)\
│　　└ [cocos-x-external](https://github.com/Xrysnow/cocos-x-external)\
├　[cocos-x-imgui](https://github.com/Xrysnow/cocos-x-imgui)\
│　　├ [ImGui](https://github.com/ocornut/imgui)\
│　　├ [imgui_markdown](https://github.com/juliettef/imgui_markdown)\
│　　├ [ImGuiColorTextEdit](https://github.com/Xrysnow/ImGuiColorTextEdit)\
│　　└ [implot](https://github.com/epezent/implot)\
├　[cocos-x-live2d](https://github.com/Xrysnow/cocos-x-live2d) (可选)\
│　├ [CubismNativeFramework](https://github.com/Live2D/CubismNativeFramework)\
│　└ [Cubism SDK for Native](https://www.live2d.com/en/download/cubism-sdk/download-native)\
├　[lstgx_external](https://github.com/Xrysnow/lstgx_external)\
│　　├ [BurstLinker](https://github.com/Xrysnow/BurstLinker)\
│　　├ [libzippp](https://github.com/ctabin/libzippp)\
│　　│　└ [libzip](https://github.com/nih-at/libzip)\
│　　├ [Lua CJSON](https://kyne.com.au/~mark/software/lua-cjson.php)\
│　　├ [luafilesystem](http://keplerproject.github.io/luafilesystem)\
│　　├ [LPeg](http://www.inf.puc-rio.br/~roberto/lpeg)\
│　　├ [MicroTeX](https://github.com/Xrysnow/MicroTeX)\
│　　├ [nanosvg](https://github.com/memononen/nanosvg)\
│　　├ [NativeFileDialog](https://github.com/mlabbe/nativefiledialog)\
│　　└ [Yuescript](https://github.com/pigpigyyy/Yuescript) (可选)\
├　[lstgx_Math](https://github.com/Xrysnow/lstgx_Math)\
└　[lstgx_LuaCore](https://github.com/Xrysnow/lstgx_LuaCore)
