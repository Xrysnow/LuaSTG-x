# LuaSTG-x 各平台编译指引

本文介绍从获取源码、准备依赖到构建和运行 LuaSTG-x 的流程。先完成通用准备，再选择目标平台；功能模块、构建类型和部署目标按项目需要选择。

本文面向完整的 LuaSTG-x 源码仓库。除特别说明外，所有命令均在**包含顶层 `CMakeLists.txt` 的仓库根目录**执行。示例中的 `build/` 位于该目录内，工具路径请替换为自己的安装位置。

## 目录

- [通用准备](#通用准备)
- [Windows](#windows)
- [Linux](#linux)
- [Android](#android)
- [macOS](#macos)
- [iOS](#ios)
- [常见问题](#常见问题)

## 通用准备

### 选择构建入口

| 平台 | 构建入口 | 架构示例 | 构建约束 |
| --- | --- | --- | --- |
| Windows | 顶层 CMake，Visual Studio 生成器 | x64 | 要求 MSVC；完整应用的其他架构需另行核对依赖 |
| Linux | 顶层 CMake，Ninja 生成器 | x86_64 | Live2D Core 的 Linux 导入路径固定为 x86_64 |
| Android | `frameworks/runtime-src/proj.android/` 中的 Gradle 工程 | arm64-v8a；可另建 x86_64 | LuaJIT 构建适配只接受这两个 ABI |
| macOS | 顶层 CMake，Xcode 生成器 | arm64；可另建 x86_64 | 每个构建目录只使用一个架构 |
| iOS | 顶层 CMake，Xcode 生成器 | 设备 arm64；模拟器 arm64 或 x86_64 | 单架构构建；LuaJIT 使用解释器模式，真机安装需要签名 |

下文以 Debug 和单架构演示命令。Release 的切换方法见各平台小节；增加其他架构时，需要同时满足引擎、源码依赖及预编译库的要求。

### 源码与递归子模块

首次获取源码时，连同递归子模块一起克隆：

```sh
git clone --recurse-submodules https://github.com/Xrysnow/LuaSTG-x.git
cd LuaSTG-x
```

已有仓库可用以下命令补齐其登记版本的子模块：

```sh
git submodule update --init --recursive
```

`frameworks/cocos-x/` 及其内部依赖、`frameworks/Live2D/Framework/`、`src/` 等都必须完整。直接下载 GitHub 自动生成的源码 ZIP 不会包含子模块内容。LuaJIT 源码快照还需要已解析为数字的 `.relver`，或保留可读取的子模块 Git 元数据。

### 准备构建工具

- CMake **3.28 或更新版本**。Windows 使用 VS 2026 生成器时，需要 CMake **4.2 或更新版本**，见 [CMake 的生成器说明](https://cmake.org/cmake/help/latest/generator/Visual%20Studio%2018%202026.html)。Android 使用工程指定的 CMake 版本。
- 支持 C++20 的编译器及配套标准库；各平台工具链见后文。
- Git，以及 OpenSSL、LuaJIT 构建所需的宿主工具。即使主工程使用 Ninja 或 Xcode，相关依赖仍可能需要 GNU make 和 Perl。
- 使用独立的构建目录。切换生成器、编译器、目标架构、SDK 或依赖工具时，新建目录，避免复用不兼容的缓存。

当前 LuaJIT 构建适配只接受 **Debug、Release**。Ninja 等单配置生成器必须设置 `CMAKE_BUILD_TYPE`；Visual Studio、Xcode 等多配置生成器必须将 `CMAKE_CONFIGURATION_TYPES` 限定为 `Debug`、`Release` 或 `Debug;Release`，构建时再使用 `--config` 选择。不要保留生成器默认的 `RelWithDebInfo`、`MinSizeRel`。

### 选择功能模块

下表列出源码定义的默认值，构建示例不重复指定这些值。`LSTGX_NO_*` 使用反向含义：`ON` 表示关闭该模块。

| CMake 变量 | 默认值 | 作用 |
| --- | --- | --- |
| `LSTGX_NO_LIVE2D` | `OFF` | 启用 Live2D，需要额外准备 Cubism Core SDK |
| `CC_ENABLE_VIDEO_TEXTURE` | `ON` | 启用视频纹理、FFmpeg 链接及 Lua `video` 注册 |
| `LSTGX_NO_YUESCRIPT` | `ON` | 关闭 YueScript |
| `LSTGX_NO_FAIRY_GUI` | `OFF` | 允许启用 FairyGUI，同时要求 `CC_ENABLE_EXT_FAIRYGUI=ON` |
| `CC_LUA_BINDING_CHECKS` | `AUTO` | Lua 绑定诊断随 Debug 状态变化；可显式指定 `ON`、`OFF` |

在配置命令末尾追加 `-D变量名=值` 即可选择功能，例如 `-DLSTGX_NO_YUESCRIPT=OFF`。Android 的参数传递方式见 Android 小节。

FairyGUI 默认启用。若已有缓存曾将 `CC_ENABLE_EXT_FAIRYGUI` 设为 `OFF`，恢复时要同时设置 `-DLSTGX_NO_FAIRY_GUI=OFF -DCC_ENABLE_EXT_FAIRYGUI=ON`。

渲染模块固定使用 gfx。`LSTGX_USE_GFX`、ANGLE 开关和旧的 `LSTGX_NO_VIDEO` 已不再作为有效配置入口；视频使用 `CC_ENABLE_VIDEO_TEXTURE`。

### Live2D SDK

默认启用 Live2D，需要自行取得 **Cubism SDK for Native 5-r.5**。从 SDK 中复制 `Core` 的 `include/`、`lib/`、`dll/` 等目录到：

```text
frameworks/Live2D/Core/
├── CMakeLists.txt       # 保留仓库提供的文件
├── include/
├── lib/
└── dll/
```

SDK 下载入口见 [Live2D 官方页面](https://www.live2d.com/en/download/cubism-sdk/download-native/)。SDK 文件由忽略规则排除，需要单独准备；同时保持仓库登记的 Framework 子模块版本。不要用 SDK 示例中的构建文件覆盖这里的 `CMakeLists.txt`。

若不需要 Live2D，可在首次配置时使用 `-DLSTGX_NO_LIVE2D=ON`，并检查自己的 Lua 脚本是否仍调用 Live2D 接口。

### 依赖由谁提供

安装前先区分构建工具与目标库。仓库已经组织编译或提供二进制的库，无需再通过系统包管理器安装同名开发包。

| 依赖类型 | 主要内容 | 开发者需要准备什么 |
| --- | --- | --- |
| 随源码构建 | OpenSSL、LuaJIT、curl、libpng、libjpeg-turbo、OpenAL、GLFW 等 | 完整的递归子模块，以及编译器、Perl、make 等构建工具 |
| 平台相关的 FreeType | Linux 使用系统库；其他平台由仓库源码构建 | 仅 Linux 需要 FreeType 2.11+ 开发包 |
| 仓库预编译库 | FFmpeg、非 iOS 平台的 zlib 等 | 对应平台和架构的文件；保留目录结构及符号链接，无需全局安装 |
| 平台 SDK / 系统接口 | Windows SDK、Android SDK/NDK、Apple SDK，Linux 的窗口、图形、音频接口 | 所选平台的 SDK 或系统开发包，见各平台小节 |
| 单独分发的 SDK | Live2D Cubism Core | 启用 Live2D 时按上一节放置 SDK |

Linux 虽有 PNG、ZLIB 的 CMake 查找调用，但项目已为它们指定仓库内的头文件和库；不需要另行安装 `libpng-dev`、`zlib1g-dev`。iOS 的 zlib 由所选 SDK 提供。

OpenSSL 使用仓库固定的源码和构建配置。首次 CMake 配置会准备并编译依赖、执行链接探测，因此配置阶段可能耗时较长。Windows 输出 DLL，其他平台输出静态 PIC 库。工具选择及并行选项见 [OpenSSL 构建说明](../../frameworks/cocos-x/external/openssl/README.md)。

### 管理构建目录

建议用 `build/<平台>-<架构>-<配置>` 命名构建目录。更换编译器、生成器、SDK 或架构时使用新目录；日常修改源码后，重复执行对应的 `cmake --build` 命令即可。需要调整功能开关时，重新执行配置命令，再构建目标。

## Windows

### 环境准备

- Windows 宿主及 Visual Studio 2022 或更新版本，安装“使用 C++ 的桌面开发”、MSVC 和 Windows SDK。引擎要求 MSVC 1930 或更新版本。
- 根据已安装的 Visual Studio 选择生成器：VS 2022 使用 `Visual Studio 17 2022`；VS 2026 使用 `Visual Studio 18 2026`，后者要求 CMake 4.2+。下文以 VS 2022 为例。
- 原生 Windows Perl，例如 Strawberry Perl。确保 `perl.exe` 在 PATH 中，或通过 `CC_OPENSSL_PERL` 显式指定；不能使用 Git/MSYS Perl 来构建 Windows 目标的 OpenSSL。
- 确认 `frameworks/cocos-x/tools/nasm/nasm.exe` 存在。OpenSSL x86/x64 构建使用项目提供的 NASM。

### 配置与编译

在 PowerShell 中配置 x64 Debug：

```powershell
cmake -S . -B build/windows-x64-debug `
  -G "Visual Studio 17 2022" -A x64 `
  -DCMAKE_CONFIGURATION_TYPES=Debug `
  -DCMAKE_TRY_COMPILE_CONFIGURATION=Debug

cmake --build build/windows-x64-debug --config Debug --target LuaSTG-x --parallel
```

`--parallel` 使用构建工具的默认并行度，也可追加任务数以控制资源占用。需要指定 Perl 时，在配置命令中追加完整参数，例如 `"-DCC_OPENSSL_PERL=C:/Tools/Strawberry/perl/bin/perl.exe"`。

Release 使用独立的 `build/windows-x64-release` 目录，将上述两个配置变量以及 `--config` 都改为 `Release`。若确实需要双配置工程，配置时使用 `"-DCMAKE_CONFIGURATION_TYPES=Debug;Release"`，并保留明确的探测配置；首次配置也会准备对应的 OpenSSL 依赖。

OpenSSL 默认使用所选 VS 的 nmake。需要并行构建 OpenSSL 时，可按其构建说明选用 jom；这不是编译应用的必需工具。应用及依赖应保持一致的 CRT：Debug 使用 `/MDd`，Release 使用 `/MD`。

### 产物与开发运行

Debug 可执行文件位于：

```text
build/windows-x64-debug/bin/LuaSTG-x/Debug/LuaSTG-x.exe
```

构建会向程序目录复制目标依赖 DLL 和 PVRVFrame 的 EGL/GLES DLL。保留这些运行库，包括选择其他渲染后端时仍会部署的 DLL。

Windows 构建目录不自动组成完整的游戏发行包。开发时可以保持仓库根目录为工作目录，使程序找到 `src/`、`res/`：

```powershell
& .\build\windows-x64-debug\bin\LuaSTG-x\Debug\LuaSTG-x.exe --console
```

在 Visual Studio 中调试时，也应将调试工作目录设为源码根目录。分发时需要另外收集资源、MOD 及匹配的 VC++ 运行库；不要只复制 EXE。

## Linux

### 环境准备

以下以 Debian/Ubuntu 系的原生 x86_64 环境为例。系统需要支持项目 C++20 代码和标准库功能的 GCC 或 Clang，以及 CMake 3.28+。依赖安装脚本会准备 GNU C/C++ 工具链、Ninja、make、Perl、pkg-config、binutils、Git 和系统开发包：

```sh
bash frameworks/cocos-x/install-deps-linux.sh
```

脚本在显示软件包列表并取得确认后调用 apt-get；已有的软件包由包管理器处理，无需重复手动安装。它不会安装 OpenSSL、curl、OpenAL、GLFW、PNG 或 zlib 的独立开发包，这些库使用仓库提供的源码或预编译文件。

系统开发包包括：

- X11 / XCB、Wayland、xkbcommon 和 OpenGL：窗口与图形接口。GLFW 默认同时编译 X11 和 Wayland 后端。
- ALSA、PulseAudio：源码构建的 OpenAL 所需音频后端接口。
- GTK3、Fontconfig、FreeType 2.11+：文本输入、字体发现与字体渲染。

CMake 需自行选用满足版本要求的安装。若使用 Clang，另外准备 `clang` 及兼容的 C++ 标准库。其他发行版使用各自包管理器安装对应工具和系统接口；运行应用还需要图形会话与显卡驱动。

### 配置与编译

```sh
cmake -S . -B build/linux-x86_64-debug -G Ninja \
  -DCMAKE_BUILD_TYPE=Debug

cmake --build build/linux-x86_64-debug --target LuaSTG-x --parallel
```

默认使用环境中的 C/C++ 编译器。选用 Clang 时，在首次配置中追加 `-DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++`；选用 GCC 时可显式指定 `gcc`、`g++`。Release 使用新目录并设置 `-DCMAKE_BUILD_TYPE=Release`；单配置 Ninja 的配置由此变量决定。

### 产物与部署

开发可执行文件位于 `build/linux-x86_64-debug/bin/LuaSTG-x/LuaSTG-x`。构建还会生成包含可执行文件、非系统共享库、`src/` 和 `res/` 的运行目录：

```text
build/linux-x86_64-debug/deploy/LuaSTG-x/Debug/
```

仅修改资源或预编译库后，可显式刷新部署目录：

```sh
cmake --build build/linux-x86_64-debug --target deploy-LuaSTG-x
cd build/linux-x86_64-debug/deploy/LuaSTG-x/Debug
./LuaSTG-x
```

部署要求 `objdump` 和 RPATH 支持，不要设置 `CMAKE_SKIP_RPATH` 或 `CMAKE_SKIP_INSTALL_RPATH`。复制时保留整个部署目录及库的符号链接。系统库及仅通过 `dlopen` 加载的插件不会自动打包，目标机器仍需兼容的系统环境。刷新不会删除旧文件，制作干净发行目录时使用新构建目录。详见 [Linux 部署说明](../../cmake/README.md#linux-runtime-deployment)。

## Android

### 环境准备

通过 Android Studio 打开 `frameworks/runtime-src/proj.android/`，或使用其中的 Gradle Wrapper。APK 应由 Gradle 构建，单独编译 CMake 目标 `cocos2dlua` 不会生成完整 APK。

| 项目 | 工程要求或默认值 |
| --- | --- |
| Gradle Wrapper | 8.14 |
| Android Gradle Plugin | 8.11.0 |
| JDK | 至少 17；可使用与 Wrapper 兼容的 JDK 21 |
| Android SDK Platform | 35 |
| SDK Build Tools | 准备 35.0.0（AGP 8.11 默认版本） |
| NDK | **30.0.16248370** |
| CMake（Android SDK 内） | **4.1.2** |
| minSdk / targetSdk | 24 / 35 |
| 默认 ABI 列表 | `arm64-v8a:x86_64` |

这些版本由 Gradle 工程声明，并非宿主机器的配置示例。Wrapper 与 Android Gradle Plugin 由工程管理，无需全局安装 Gradle。NDK、CMake 是精确版本，不能只安装任意“r30+”或任意新版 CMake。JDK/Build Tools 要求可对照 [AGP 8.11 兼容表](https://developer.android.com/build/releases/agp-8-11-0-release-notes)。Java 源码的 `VERSION_11` 不等于 Gradle 可以使用 JDK 11 启动。

设置 `JAVA_HOME` 指向包含 `javac` 的 JDK，`ANDROID_HOME` 指向 Android SDK；Android Studio 中也需选择相同的 Gradle JDK。SDK 路径可写入本机的 `local.properties`，不要提交机器专用路径。

### Linux / macOS 宿主

另外准备宿主原生的 Perl、GNU make 和 C 编译器，以构建 OpenSSL 及 LuaJIT 的宿主工具。使用与宿主系统对应的 Android SDK/NDK。

```sh
# 将路径替换为本机安装位置。
export JAVA_HOME=/absolute/path/to/jdk-21
export ANDROID_HOME=/absolute/path/to/Android/Sdk

bash frameworks/runtime-src/proj.android/gradlew \
  -p frameworks/runtime-src/proj.android \
  :LuaSTG-x:assembleDebug -PPROP_APP_ABI=arm64-v8a
```

### Windows 宿主

Windows 上构建 Android 目标需要额外的宿主工具配置：

- 一个完整的 MSYS 环境，例如已有的 Git for Windows/MSYS 安装，包含 `usr/bin/bash.exe`、`sh.exe`、`perl.exe` 和 `msys-2.0.dll`。
- 原生 Windows GNU make，以及用于 LuaJIT 宿主工具的 MinGW GCC；这些宿主工具不能由 Android NDK 编译器替代。
- MSYS Perl 的 `File::Spec`、`IPC::Cmd`、`Locale::Maketext::Simple`、`JSON::PP`、`Pod::Usage`、`ExtUtils::MakeMaker` 模块。精简的 Git Perl 可能缺少其中部分模块。

以下在 PowerShell 执行，所有工具路径均为示例，需替换为本机已安装的位置：

```powershell
$env:JAVA_HOME = 'C:/Tools/jdk-21'
$env:ANDROID_HOME = 'C:/Tools/Android/Sdk'

.\frameworks\runtime-src\proj.android\gradlew.bat `
  -p frameworks/runtime-src/proj.android `
  :LuaSTG-x:assembleDebug -PPROP_APP_ABI=arm64-v8a `
  -PCC_OPENSSL_ANDROID_WINDOWS_HOST=ON `
  "-PCC_OPENSSL_MSYS_ROOT=C:/Tools/msys64" `
  "-PCC_OPENSSL_MAKE=C:/Tools/mingw64/bin/mingw32-make.exe" `
  "-PCC_LUAJIT_MSYS_ROOT=C:/Tools/msys64" `
  "-PCC_LUAJIT_MAKE=C:/Tools/mingw64/bin/mingw32-make.exe" `
  "-PCC_LUAJIT_HOST_CC=C:/Tools/mingw64/bin/gcc.exe"
```

若 MSYS Perl 缺少模块，可指定 `"-PCC_OPENSSL_PERL5LIB=C:/absolute/path/to/perl-overlay"`；overlay 必须是已经准备好的普通 `.pm` 文件目录，不包含 DLL、XS 二进制或符号链接。也可使用自带完整模块的 MSYS Perl。不要将 Windows NDK 与 WSL Perl/make 混用。

Android Studio 同样需要这些参数，可将对应的 Gradle 项目属性写入用户级 `~/.gradle/gradle.properties`，例如 `CC_OPENSSL_ANDROID_WINDOWS_HOST=ON`、`CC_OPENSSL_MSYS_ROOT=C:/Tools/msys64` 等；去掉命令行的 `-P` 前缀，使用自己的实际路径。

### ABI、功能开关与 Release

- `-PPROP_APP_ABI=arm64-v8a` 构建单 ABI；`-PPROP_APP_ABI=x86_64` 用于对应环境；默认值会同时构建两个 ABI。当前不要使用旧注释列出的 `armeabi-v7a` 或 `x86`，LuaJIT 适配会拒绝它们。
- `-PCC_ENABLE_VIDEO_TEXTURE=OFF` 可以关闭视频。`app/build.gradle` 已显式转发此属性及指定的 `CC_OPENSSL_*`、`CC_LUAJIT_*` 宿主工具参数。
- `LSTGX_NO_LIVE2D` 等其他 CMake 功能开关尚未作为同名 Gradle 属性转发。按需在 `app/build.gradle` 的 `defaultConfig.externalNativeBuild.cmake` 中追加 `arguments "-DLSTGX_NO_LIVE2D=ON"` 等参数，保留现有参数；仅传 `-PLSTGX_NO_LIVE2D=ON` 不会生效。
- Release 任务为 `:LuaSTG-x:assembleRelease`。签名通过 `RELEASE_STORE_FILE`、`RELEASE_STORE_PASSWORD`、`RELEASE_KEY_ALIAS`、`RELEASE_KEY_PASSWORD` 配置，保存在用户级配置中；未配置签名时产物不能作为已签名安装包使用。开发调试使用 Debug APK；发布时使用签名的 Release 包。

### 产物与资源

直接使用 Wrapper 构建时，Debug APK 位于：

```text
frameworks/runtime-src/proj.android/app/build/outputs/apk/debug/
```

模块名是 `LuaSTG-x`，实际模块目录是 `app/`。Gradle 自动将仓库根目录的 `src/`、`res/` 同步至变体的生成 assets；手写资源放入 `app/manual-assets/`，与生成资源重名会报错。旧的 `app/assets/` 不再打包，详见 [资源说明](../../frameworks/runtime-src/proj.android/app/ASSETS.md)。

## macOS

### 环境准备

在 Mac 上安装支持项目 C++20 代码和标准库的完整 Xcode 及所需组件，完成许可和首次启动设置。宿主 macOS 版本应满足所选 Xcode 的要求。另需 CMake 3.28+、Git、原生 Perl 和 GNU make。

先检查实际选中的工具链及 SDK：

```sh
xcode-select -p
xcodebuild -version
xcodebuild -showsdks
```

下文以 arm64 和 macOS 12.0 部署目标演示。架构按目标机器选择，部署版本需同时满足所用 SDK 和各依赖的最低系统要求；它与构建宿主的 macOS 版本不同。LuaJIT、OpenSSL 均要求显式指定单个架构、SDK 和部署目标，不能直接使用 `arm64;x86_64` 生成通用应用。

### 配置与编译

```sh
cmake -S . -B build/macos-arm64-debug -G Xcode \
  -DCMAKE_CONFIGURATION_TYPES=Debug \
  -DCMAKE_TRY_COMPILE_CONFIGURATION=Debug \
  -DCMAKE_OSX_SYSROOT=macosx \
  -DCMAKE_OSX_ARCHITECTURES=arm64 \
  -DCMAKE_OSX_DEPLOYMENT_TARGET=12.0

cmake --build build/macos-arm64-debug --config Debug --target LuaSTG-x --parallel
```

可用 Xcode 打开生成的 `build/macos-arm64-debug/LuaSTG-x.xcodeproj`。Intel 目标使用独立目录并将架构设为 `x86_64`，同时核对所有依赖；Release 使用独立目录，将配置变量和 `--config` 改为 `Release`。

### 应用包与 Framework

Debug 应用包位于：

```text
build/macos-arm64-debug/bin/LuaSTG-x/Debug/LuaSTG-x.app
```

脚本和资源随应用包构建。需要运行时可执行 `open build/macos-arm64-debug/bin/LuaSTG-x/Debug/LuaSTG-x.app`。

启用视频时，CMake 使用 `frameworks/cocos-x/external/ffmpeg-prebuilt/apple/` 下的 `FFmpeg.xcframework` 及配套 `include/`。保留 Framework 内的相对符号链接；从 Windows 复制源码时尤其要检查链接是否仍有效。

Xcode 生成器已配置 FFmpeg 的自动嵌入及 Code Sign On Copy，无需手工添加复制阶段。实际签名身份应匹配本机环境；面向他人分发的正式签名、公证及发布包制作需另行完成。其他生成器只有复制 Framework 的后处理，完成包的签名仍需单独处理。详见 [Apple FFmpeg 说明](../../cmake/README.md#apple-ffmpeg)。

## iOS

### 环境准备

需要 Mac、完整 Xcode 及对应的 iOS / iOS Simulator SDK，工具要求与 macOS 小节相同。使用 CMake 内建的 iOS 平台支持，工程默认 iOS 部署目标为 **17.0**。设备和模拟器使用各自独立的目录，每个目录只配置一个架构。

| 目标 | `CMAKE_SYSTEM_NAME` | `CMAKE_OSX_SYSROOT` | `CMAKE_OSX_ARCHITECTURES` |
| --- | --- | --- | --- |
| iPhone / iPad 真机 | `iOS` | `iphoneos` | `arm64` |
| Apple Silicon 模拟器 | `iOS` | `iphonesimulator` | `arm64` |
| Intel 模拟器 | `iOS` | `iphonesimulator` | `x86_64` |

LuaJIT 构建适配会为设备和模拟器设置不同的目标三元组，并用 macOS SDK 构建需要在宿主运行的工具。iOS 使用 LuaJIT 的解释器模式，不启用运行时 JIT。

Live2D 仍需准备完整的 Cubism Core SDK，包括 `Core/lib/ios/` 中设备和模拟器、Debug 和 Release 对应的目录。视频使用 Apple FFmpeg XCFramework 中的对应切片。

iOS 的 zlib 头文件和链接 stub 来自所选 SDK，无需安装独立 zlib。真机和模拟器的库即使同为 arm64，也不能互换。

### arm64 模拟器 Debug

以下命令生成模拟器应用。仅需编译时可禁用签名；安装运行前应使用符合目标环境的签名设置，见本节末尾。

```sh
cmake -S . -B build/ios-simulator-arm64-debug -G Xcode \
  -DCMAKE_SYSTEM_NAME=iOS \
  -DCMAKE_CONFIGURATION_TYPES=Debug \
  -DCMAKE_TRY_COMPILE_CONFIGURATION=Debug \
  -DCMAKE_OSX_SYSROOT=iphonesimulator \
  -DCMAKE_OSX_ARCHITECTURES=arm64 \
  -DCMAKE_OSX_DEPLOYMENT_TARGET=17.0

cmake --build build/ios-simulator-arm64-debug --config Debug --target LuaSTG-x --parallel
```

Intel 模拟器使用新目录，并将 `CMAKE_OSX_ARCHITECTURES` 改为 `x86_64`。

### arm64 真机 Debug

真机应用需要开发团队和签名配置。先按本节末尾准备相应参数，再配置工程：

```sh
cmake -S . -B build/ios-device-arm64-debug -G Xcode \
  -DCMAKE_SYSTEM_NAME=iOS \
  -DCMAKE_CONFIGURATION_TYPES=Debug \
  -DCMAKE_TRY_COMPILE_CONFIGURATION=Debug \
  -DCMAKE_OSX_SYSROOT=iphoneos \
  -DCMAKE_OSX_ARCHITECTURES=arm64 \
  -DCMAKE_OSX_DEPLOYMENT_TARGET=17.0

cmake --build build/ios-device-arm64-debug --config Debug --target LuaSTG-x --parallel
```

不要在同一构建目录中通过切换 `-sdk` 混用设备和模拟器，也不要启用 `CMAKE_IOS_INSTALL_COMBINED`。Release 应在新目录中将配置变量和 `--config` 改为 `Release`。

### 产物、Framework 与签名

两个示例的应用包均位于各自构建目录下的：

```text
bin/LuaSTG-x/Debug/LuaSTG-x.app
```

构建会收集脚本、资源及应用元数据。iOS 默认使用的 OpenAL Framework 会复制到 `Frameworks/soft_oal.framework`；启用视频时，也会复制选中的 `Frameworks/FFmpeg.framework`。Xcode 生成器配置了 Framework 嵌入与 Code Sign On Copy，实际签名遵循应用的签名设置。

需要真机安装时，在配置命令中追加自己的开发团队和应用标识，例如：

```text
-DCMAKE_XCODE_ATTRIBUTE_DEVELOPMENT_TEAM=YOUR_TEAM_ID
-DCMAKE_XCODE_ATTRIBUTE_CODE_SIGN_STYLE=Automatic
-DMACOSX_BUNDLE_GUI_IDENTIFIER=com.example.luastgx
```

`MACOSX_BUNDLE_GUI_IDENTIFIER` 默认为 `com.xrysnow.lstgx`，同时设置应用 plist 和 Xcode 的 Product Bundle Identifier。签名还需本机有效证书、匹配的 Provisioning Profile 及开发者账户配置；可在生成的 Xcode 工程中检查 Signing & Capabilities。仅需编译、不需要安装时，可在独立目录中追加 `-DCMAKE_XCODE_ATTRIBUTE_CODE_SIGNING_ALLOWED=NO`；未签名产物不能直接安装到真机。

## 常见问题

| 现象 | 检查方向 |
| --- | --- |
| 首次配置长时间停在 OpenSSL | 配置阶段包含依赖编译；先看输出和构建目录中的日志，确认 Perl、make/MSVC 等宿主工具是否正确 |
| 升级构建适配后提示 OpenSSL identity changed | 新建构建目录，或使用 `cmake --fresh` 并保留原有工具、配置与功能参数，使依赖探测重新执行；不要手改身份缓存 |
| 提示只支持 Debug / Release | 单配置设置 `CMAKE_BUILD_TYPE`；多配置限定 `CMAKE_CONFIGURATION_TYPES`，不要只传构建阶段的 `--config` |
| 找不到 Cubism Core 头文件或库 | 检查 SDK 版本、`Core/` 目录层次及目标架构；递归拉取子模块不会提供被忽略的 SDK 文件 |
| Android Windows 宿主的 Perl 模块报错 | 检查实际使用的是 MSYS Perl，以及它的模块/overlay；原生 Windows 目标的 Perl 要求与此不同 |
| Android 参数看似没有生效 | 检查 `app/build.gradle` 是否转发该 Gradle 属性；`-P` 项目属性不会自动变成同名 `-D` CMake 变量 |
| Windows 程序找不到启动脚本 | 保持源码根目录为开发工作目录，或准备完整运行目录中的 `src/`、`res/` 及游戏数据 |
| Linux 部署报缺少库、RPATH 或 objdump | 安装 binutils、恢复 RPATH 支持，并核对链接依赖；不要跳过失败的依赖扫描 |
| Apple 报缺少架构、SDK 或部署版本 | 首次配置显式指定 `CMAKE_OSX_ARCHITECTURES`、`CMAKE_OSX_SYSROOT`、`CMAKE_OSX_DEPLOYMENT_TARGET` |
| Apple FFmpeg Framework 不完整 | 检查 XCFramework、配套头文件及符号链接；保留原文件字节，不手工改写已签名包 |
| iOS 模拟器链接到真机对象 | 检查 SDK、架构及设备/模拟器依赖切片；zlib 应使用 SDK 链接 stub，Cubism Core 应使用对应的 simulator 目录 |

复用已有目录前先检查 `CMakeCache.txt` 中的源码路径、生成器、架构、配置与功能开关。构建故障应从源码配置和工具环境解决，不手改生成的工程或缓存。
