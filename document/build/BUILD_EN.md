# Building LuaSTG-x

This guide covers obtaining the source, preparing dependencies, building, and running LuaSTG-x. Complete the common setup first, then follow the section for your target platform. Choose features, build configurations, and deployment targets to suit your project.

This guide assumes a complete LuaSTG-x source checkout. Unless stated otherwise, run all commands from **the repository root containing the top-level `CMakeLists.txt`**. The example `build/` directories are relative to that root. Replace example tool paths with your own installation paths.

## Contents

- [Common setup](#common-setup)
- [Windows](#windows)
- [Linux](#linux)
- [Android](#android)
- [macOS](#macos)
- [iOS](#ios)
- [Troubleshooting](#troubleshooting)

## Common setup

### Choose a build entry point

| Platform | Entry point | Example architectures | Constraints |
| --- | --- | --- | --- |
| Windows | Top-level CMake, Visual Studio generator | x64 | Requires MSVC; other application architectures require checking all dependencies |
| Linux | Top-level CMake, Ninja generator | x86_64 | The Linux Live2D Core import path is fixed to x86_64 |
| Android | Gradle project in `frameworks/runtime-src/proj.android/` | arm64-v8a; x86_64 can be built separately | The LuaJIT build adapter accepts only these two ABIs |
| macOS | Top-level CMake, Xcode generator | arm64; x86_64 can be built separately | Use one architecture per build directory |
| iOS | Top-level CMake, Xcode generator | arm64 devices; arm64 or x86_64 simulators | Single-architecture builds; LuaJIT runs in interpreter mode; device installation requires signing |

The examples use Debug and a single architecture. Each platform section explains how to switch to Release. Additional architectures must be supported by the engine, source dependencies, and prebuilt libraries alike.

### Obtain the source and recursive submodules

For a new checkout, clone the repository with its recursive submodules:

```sh
git clone --recurse-submodules https://github.com/Xrysnow/LuaSTG-x.git
cd LuaSTG-x
```

For an existing checkout, populate submodules at the revisions recorded by the repository:

```sh
git submodule update --init --recursive
```

Directories such as `frameworks/cocos-x/` and its dependencies, `frameworks/Live2D/Framework/`, and `src/` must be complete. GitHub's automatically generated source ZIP archives do not include submodule contents. LuaJIT source snapshots also need either a `.relver` file resolved to a numeric version or readable submodule Git metadata.

### Prepare build tools

- CMake **3.28 or newer**. The VS 2026 generator on Windows requires CMake **4.2 or newer**; see the [CMake generator documentation](https://cmake.org/cmake/help/latest/generator/Visual%20Studio%2018%202026.html). For Android, use the CMake version specified by the Gradle project.
- A compiler and standard library supporting the project's C++20 code. Platform-specific toolchains are described below.
- Git and the host tools required to build OpenSSL and LuaJIT. Dependencies may still require GNU make and Perl even when the main project uses Ninja or Xcode.
- Separate build directories. Create a new directory when changing generators, compilers, architectures, SDKs, or dependency tools to avoid incompatible cached settings.

The LuaJIT build adapter accepts only **Debug and Release**. With single-configuration generators such as Ninja, set `CMAKE_BUILD_TYPE`. With multi-configuration generators such as Visual Studio and Xcode, restrict `CMAKE_CONFIGURATION_TYPES` to `Debug`, `Release`, or `Debug;Release`, then select a configuration with `--config` when building. Do not retain the generator's default `RelWithDebInfo` or `MinSizeRel` configurations.

### Select features

The following defaults are defined by the source; the build examples do not repeat them. The `LSTGX_NO_*` options are inverted: `ON` disables the corresponding module.

| CMake variable | Default | Effect |
| --- | --- | --- |
| `LSTGX_NO_LIVE2D` | `OFF` | Enables Live2D; requires a separately supplied Cubism Core SDK |
| `CC_ENABLE_VIDEO_TEXTURE` | `ON` | Enables video textures, FFmpeg linking, and registration of the Lua `video` API |
| `LSTGX_NO_YUESCRIPT` | `ON` | Disables YueScript |
| `LSTGX_NO_FAIRY_GUI` | `OFF` | Allows FairyGUI; also requires `CC_ENABLE_EXT_FAIRYGUI=ON` |
| `CC_LUA_BINDING_CHECKS` | `AUTO` | Lua binding diagnostics follow the Debug configuration; can be explicitly set to `ON` or `OFF` |

Append `-DVARIABLE=VALUE` to a CMake configure command to select features, for example `-DLSTGX_NO_YUESCRIPT=OFF`. Android parameter forwarding is covered in its platform section.

FairyGUI is enabled by default. If an existing cache has `CC_ENABLE_EXT_FAIRYGUI=OFF`, re-enable it with both `-DLSTGX_NO_FAIRY_GUI=OFF` and `-DCC_ENABLE_EXT_FAIRYGUI=ON`.

The rendering module uses gfx. `LSTGX_USE_GFX`, ANGLE options, and the old `LSTGX_NO_VIDEO` option are no longer configuration entry points. Use `CC_ENABLE_VIDEO_TEXTURE` for video support.

### Live2D SDK

Live2D is enabled by default and requires **Cubism SDK for Native 5-r.5**, obtained separately. Copy the SDK's `Core` contents, including `include/`, `lib/`, and `dll/`, into:

```text
frameworks/Live2D/Core/
├── CMakeLists.txt       # Keep the file supplied by the repository
├── include/
├── lib/
└── dll/
```

Download the SDK from the [Live2D website](https://www.live2d.com/en/download/cubism-sdk/download-native/). SDK files are excluded by Git ignore rules and must be supplied separately. Keep the Framework submodule at the revision recorded by the repository. Do not replace this directory's `CMakeLists.txt` with build files from SDK examples.

If you do not need Live2D, configure with `-DLSTGX_NO_LIVE2D=ON` and check that your Lua scripts do not require its API.

### Where dependencies come from

Distinguish build tools from target libraries before installing packages. Libraries already built or supplied as binaries by the repository do not need separate development packages from a system package manager.

| Dependency type | Examples | What to prepare |
| --- | --- | --- |
| Built from bundled source | OpenSSL, LuaJIT, curl, libpng, libjpeg-turbo, OpenAL, GLFW, and others | Complete recursive submodules and build tools such as the compiler, Perl, and make |
| Platform-dependent FreeType | System library on Linux; bundled source on other platforms | FreeType 2.11+ development package on Linux only |
| Bundled prebuilt libraries | FFmpeg, zlib on non-iOS platforms, and others | Files matching the target platform and architecture; preserve directory layouts and symbolic links; no global installation is needed |
| Platform SDKs and system interfaces | Windows SDK, Android SDK/NDK, Apple SDKs, Linux windowing, graphics, and audio interfaces | The target platform's SDK or system development packages, as listed below |
| Separately distributed SDK | Live2D Cubism Core | Place the SDK as described above when enabling Live2D |

Although Linux configuration calls CMake's PNG and ZLIB discovery routines, the project supplies their bundled header and library locations. There is no need to install `libpng-dev` or `zlib1g-dev` separately. On iOS, zlib comes from the selected SDK.

OpenSSL uses the source and build settings pinned by the repository. Initial CMake configuration prepares and builds dependencies and runs link probes, so this step can take some time. Windows builds DLLs; other platforms build static PIC libraries. See the [OpenSSL build documentation](../../frameworks/cocos-x/external/openssl/README.md) for tool selection and parallel build options.

### Manage build directories

A useful naming convention is `build/<platform>-<architecture>-<configuration>`. Use a new directory when changing the compiler, generator, SDK, or architecture. For routine source edits, rerun the corresponding `cmake --build` command. After changing feature options, rerun configuration before building.

## Windows

### Prerequisites

- A Windows host with Visual Studio 2022 or newer, including the **Desktop development with C++** workload, MSVC, and the Windows SDK. The engine requires MSVC version 1930 or newer.
- Select the generator for your installed Visual Studio: `Visual Studio 17 2022` for VS 2022, or `Visual Studio 18 2026` for VS 2026. The latter requires CMake 4.2+. The example below uses VS 2022.
- Native Windows Perl, such as Strawberry Perl. Put `perl.exe` on PATH or specify `CC_OPENSSL_PERL`. Git/MSYS Perl cannot build OpenSSL for a Windows target.
- Ensure `frameworks/cocos-x/tools/nasm/nasm.exe` exists. OpenSSL x86/x64 builds use this bundled NASM executable.

### Configure and build

Configure x64 Debug in PowerShell:

```powershell
cmake -S . -B build/windows-x64-debug `
  -G "Visual Studio 17 2022" -A x64 `
  -DCMAKE_CONFIGURATION_TYPES=Debug `
  -DCMAKE_TRY_COMPILE_CONFIGURATION=Debug

cmake --build build/windows-x64-debug --config Debug --target LuaSTG-x --parallel
```

`--parallel` uses the build tool's default parallelism. Append a job count to limit resource use. To select Perl explicitly, append a complete argument such as `"-DCC_OPENSSL_PERL=C:/Tools/Strawberry/perl/bin/perl.exe"` to the configure command.

For Release, use a separate `build/windows-x64-release` directory and change both configuration variables and `--config` to `Release`. For a project containing both configurations, configure with `"-DCMAKE_CONFIGURATION_TYPES=Debug;Release"` and keep an explicit probe configuration. Initial configuration also prepares the corresponding OpenSSL dependencies.

OpenSSL defaults to nmake from the selected Visual Studio installation. To build OpenSSL in parallel, select jom as described in its documentation; jom is optional. Keep the application and dependencies on matching CRT settings: `/MDd` for Debug and `/MD` for Release.

### Output and development runs

The Debug executable is located at:

```text
build/windows-x64-debug/bin/LuaSTG-x/Debug/LuaSTG-x.exe
```

The build copies dependency DLLs and PVRVFrame EGL/GLES DLLs into the executable directory. Keep these runtime libraries, including those deployed when using other rendering backends.

The Windows build directory is not a complete game distribution. During development, use the repository root as the working directory so the program can locate `src/` and `res/`:

```powershell
& .\build\windows-x64-debug\bin\LuaSTG-x\Debug\LuaSTG-x.exe --console
```

Set the debugging working directory to the source root in Visual Studio as well. For distribution, also collect resources, MODs, and the matching Visual C++ runtime; copying the EXE alone is insufficient.

## Linux

### Prerequisites

The example targets a native x86_64 Debian/Ubuntu environment. Use GCC or Clang with support for the project's C++20 code and standard library features, and CMake 3.28+. The dependency script installs the GNU C/C++ toolchain, Ninja, make, Perl, pkg-config, binutils, Git, and system development packages:

```sh
bash frameworks/cocos-x/install-deps-linux.sh
```

The script displays the package list and asks for confirmation before invoking apt-get. The package manager handles packages already installed. The script does not request separate OpenSSL, curl, OpenAL, GLFW, PNG, or zlib development packages; these libraries use bundled source or prebuilt files.

System development packages cover:

- X11/XCB, Wayland, xkbcommon, and OpenGL for windowing and graphics. GLFW builds both X11 and Wayland backends by default.
- ALSA and PulseAudio interfaces for the OpenAL audio backends built from source.
- GTK3, Fontconfig, and FreeType 2.11+ for text input, font discovery, and font rendering.

Select a CMake installation that meets the version requirement separately. To use Clang, also install `clang` and a compatible C++ standard library. On other distributions, install equivalent tools and system interfaces with the native package manager. Running the application also requires a graphical session and graphics drivers.

### Configure and build

```sh
cmake -S . -B build/linux-x86_64-debug -G Ninja \
  -DCMAKE_BUILD_TYPE=Debug

cmake --build build/linux-x86_64-debug --target LuaSTG-x --parallel
```

CMake uses the environment's C/C++ compilers by default. To select Clang, append `-DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++` during initial configuration. For GCC, explicitly select `gcc` and `g++` if needed. For Release, use a new directory with `-DCMAKE_BUILD_TYPE=Release`; this variable selects the configuration for single-configuration Ninja builds.

### Output and deployment

The development executable is `build/linux-x86_64-debug/bin/LuaSTG-x/LuaSTG-x`. The build also creates a runnable directory containing the executable, non-system shared libraries, `src/`, and `res/`:

```text
build/linux-x86_64-debug/deploy/LuaSTG-x/Debug/
```

After changing only resources or prebuilt libraries, refresh the deployment directory explicitly:

```sh
cmake --build build/linux-x86_64-debug --target deploy-LuaSTG-x
cd build/linux-x86_64-debug/deploy/LuaSTG-x/Debug
./LuaSTG-x
```

Deployment requires `objdump` and RPATH support. Do not set `CMAKE_SKIP_RPATH` or `CMAKE_SKIP_INSTALL_RPATH`. Copy the entire deployment directory and preserve library symbolic links. System libraries and plugins loaded only through `dlopen` are not automatically packaged, so the target machine still needs a compatible system environment. Refreshing does not remove stale files; use a new build directory when preparing a clean distribution. See the [Linux deployment documentation](../../cmake/README.md#linux-runtime-deployment).

## Android

### Prerequisites

Open `frameworks/runtime-src/proj.android/` in Android Studio, or use its Gradle Wrapper. Build APKs through Gradle: building only the CMake target `cocos2dlua` does not produce a complete APK.

| Component | Project requirement or default |
| --- | --- |
| Gradle Wrapper | 8.14 |
| Android Gradle Plugin | 8.11.0 |
| JDK | At least 17; JDK 21 is also compatible with the Wrapper |
| Android SDK Platform | 35 |
| SDK Build Tools | Install 35.0.0, the AGP 8.11 default |
| NDK | **30.0.16248370** |
| CMake in the Android SDK | **4.1.2** |
| minSdk / targetSdk | 24 / 35 |
| Default ABI list | `arm64-v8a:x86_64` |

These reflect the Gradle project's declarations and tool requirements, rather than an example host configuration. The project manages the Wrapper and Android Gradle Plugin; no global Gradle installation is required. NDK and CMake versions are exact: an arbitrary "r30+" NDK or newer CMake is not a substitute. Refer to the [AGP 8.11 compatibility table](https://developer.android.com/build/releases/agp-8-11-0-release-notes) for JDK and Build Tools requirements. Java source compatibility set to `VERSION_11` does not mean Gradle can run on JDK 11.

Set `JAVA_HOME` to a JDK containing `javac`, and `ANDROID_HOME` to the Android SDK. Select the same Gradle JDK in Android Studio. The SDK path can also be stored in the local `local.properties` file; do not commit machine-specific paths.

### Linux and macOS hosts

Prepare native host Perl, GNU make, and a C compiler for OpenSSL and LuaJIT's host tools. Use the Android SDK/NDK distribution for your host operating system.

```sh
# Replace these paths with your local installation paths.
export JAVA_HOME=/absolute/path/to/jdk-21
export ANDROID_HOME=/absolute/path/to/Android/Sdk

bash frameworks/runtime-src/proj.android/gradlew \
  -p frameworks/runtime-src/proj.android \
  :LuaSTG-x:assembleDebug -PPROP_APP_ABI=arm64-v8a
```

### Windows hosts

Android builds on Windows need additional host tools:

- A complete MSYS environment, such as an existing Git for Windows/MSYS installation, containing `usr/bin/bash.exe`, `sh.exe`, `perl.exe`, and `msys-2.0.dll`.
- Native Windows GNU make and MinGW GCC for LuaJIT's host tools. The Android NDK compiler cannot replace these host tools.
- The MSYS Perl modules `File::Spec`, `IPC::Cmd`, `Locale::Maketext::Simple`, `JSON::PP`, `Pod::Usage`, and `ExtUtils::MakeMaker`. Minimal Git Perl installations may omit some of them.

Run the following in PowerShell, replacing all example tool paths with your installed locations:

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

If MSYS Perl lacks modules, set `"-PCC_OPENSSL_PERL5LIB=C:/absolute/path/to/perl-overlay"`. The overlay must be an existing directory of plain `.pm` files, without DLLs, XS binaries, or symbolic links. Alternatively, use MSYS Perl with a complete module installation. Do not mix a Windows NDK with WSL Perl or make.

Android Studio needs the same parameters. Store the corresponding Gradle project properties in the user-level `~/.gradle/gradle.properties`, for example `CC_OPENSSL_ANDROID_WINDOWS_HOST=ON` and `CC_OPENSSL_MSYS_ROOT=C:/Tools/msys64`. Omit the command-line `-P` prefix and use your actual paths.

### ABIs, features, and Release

- `-PPROP_APP_ABI=arm64-v8a` builds a single ABI; use `-PPROP_APP_ABI=x86_64` for that target environment. The default builds both ABIs. Do not use `armeabi-v7a` or `x86` from older comments: the LuaJIT adapter rejects them.
- `-PCC_ENABLE_VIDEO_TEXTURE=OFF` disables video. `app/build.gradle` explicitly forwards this property and the supported `CC_OPENSSL_*` and `CC_LUAJIT_*` host-tool properties.
- Other CMake feature options, such as `LSTGX_NO_LIVE2D`, are not forwarded from same-named Gradle properties. Add arguments such as `arguments "-DLSTGX_NO_LIVE2D=ON"` to `defaultConfig.externalNativeBuild.cmake` in `app/build.gradle` as needed, preserving existing arguments. Passing only `-PLSTGX_NO_LIVE2D=ON` has no effect.
- The Release task is `:LuaSTG-x:assembleRelease`. Configure signing through `RELEASE_STORE_FILE`, `RELEASE_STORE_PASSWORD`, `RELEASE_KEY_ALIAS`, and `RELEASE_KEY_PASSWORD`, stored in user-level configuration. Without signing configuration, the output is not a signed installation package. Use Debug APKs for development and debugging, and signed Release packages for distribution.

### Output and resources

When building directly through the Wrapper, Debug APKs are located in:

```text
frameworks/runtime-src/proj.android/app/build/outputs/apk/debug/
```

The module is named `LuaSTG-x`, but its directory is `app/`. Gradle synchronizes the repository's `src/` and `res/` into generated assets for each variant. Place manually maintained assets in `app/manual-assets/`; collisions with generated assets cause an error. The legacy `app/assets/` directory is not packaged. See the [asset documentation](../../frameworks/runtime-src/proj.android/app/ASSETS.md).

## macOS

### Prerequisites

Install a full Xcode distribution supporting the project's C++20 code and standard library requirements, including its required components. Complete license acceptance and first-launch setup. The host macOS version must meet the selected Xcode version's requirements. Also prepare CMake 3.28+, Git, native Perl, and GNU make.

Check the selected toolchain and available SDKs:

```sh
xcode-select -p
xcodebuild -version
xcodebuild -showsdks
```

The example uses arm64 and a macOS 12.0 deployment target. Select the architecture for the target machine. The deployment version must satisfy both the SDK and all dependencies' minimum system requirements; it is distinct from the build host's macOS version. LuaJIT and OpenSSL require an explicit single architecture, SDK, and deployment target. You cannot directly use `arm64;x86_64` to produce a universal application.

### Configure and build

```sh
cmake -S . -B build/macos-arm64-debug -G Xcode \
  -DCMAKE_CONFIGURATION_TYPES=Debug \
  -DCMAKE_TRY_COMPILE_CONFIGURATION=Debug \
  -DCMAKE_OSX_SYSROOT=macosx \
  -DCMAKE_OSX_ARCHITECTURES=arm64 \
  -DCMAKE_OSX_DEPLOYMENT_TARGET=12.0

cmake --build build/macos-arm64-debug --config Debug --target LuaSTG-x --parallel
```

You can open the generated `build/macos-arm64-debug/LuaSTG-x.xcodeproj` in Xcode. For an Intel target, use a separate directory, select `x86_64`, and check all dependencies. For Release, use a separate directory and change the configuration variables and `--config` to `Release`.

### Application bundle and frameworks

The Debug application bundle is located at:

```text
build/macos-arm64-debug/bin/LuaSTG-x/Debug/LuaSTG-x.app
```

Scripts and resources are included when building the bundle. Launch it with `open build/macos-arm64-debug/bin/LuaSTG-x/Debug/LuaSTG-x.app`.

With video enabled, CMake uses `FFmpeg.xcframework` and the accompanying `include/` directory under `frameworks/cocos-x/external/ffmpeg-prebuilt/apple/`. Preserve relative symbolic links inside the framework, especially when transferring source files from Windows.

The Xcode generator configures automatic FFmpeg embedding and Code Sign On Copy, so no manual copy phase is required. Select a signing identity available on your machine. Distribution signing, notarization, and packaging remain separate steps. Other generators provide a post-build framework copy step only; signing the completed bundle must be handled separately. See the [Apple FFmpeg documentation](../../cmake/README.md#apple-ffmpeg).

## iOS

### Prerequisites

Use a Mac with full Xcode and the appropriate iOS/iOS Simulator SDKs. Other tool requirements match the macOS section. The project uses CMake's built-in iOS platform support and defaults to an iOS deployment target of **17.0**. Use separate directories for devices and simulators, with one architecture per directory.

| Target | `CMAKE_SYSTEM_NAME` | `CMAKE_OSX_SYSROOT` | `CMAKE_OSX_ARCHITECTURES` |
| --- | --- | --- | --- |
| Physical iPhone/iPad | `iOS` | `iphoneos` | `arm64` |
| Apple Silicon simulator | `iOS` | `iphonesimulator` | `arm64` |
| Intel simulator | `iOS` | `iphonesimulator` | `x86_64` |

The LuaJIT adapter sets distinct target triples for devices and simulators and uses the macOS SDK to build tools that run on the host. On iOS, LuaJIT runs in interpreter mode without runtime JIT compilation.

Live2D requires the complete Cubism Core SDK, including the device/simulator and Debug/Release directories under `Core/lib/ios/`. Video support uses the matching slice of the Apple FFmpeg XCFramework.

The iOS zlib headers and link stub come from the selected SDK; no separate zlib installation is needed. Device and simulator libraries are not interchangeable, even when both use arm64.

### arm64 simulator Debug

The following commands build a simulator application. Signing can be disabled for compilation alone. For installation and execution, use signing settings appropriate to the target environment, as described at the end of this section.

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

For an Intel simulator, use a new directory and set `CMAKE_OSX_ARCHITECTURES=x86_64`.

### arm64 device Debug

Device applications require a development team and signing configuration. Prepare the parameters described at the end of this section and add them when configuring:

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

Do not switch `-sdk` to mix device and simulator builds in the same directory, and do not enable `CMAKE_IOS_INSTALL_COMBINED`. For Release, use a new directory and change the configuration variables and `--config` to `Release`.

### Output, frameworks, and signing

Both examples produce an application bundle at the following path relative to their respective build directories:

```text
bin/LuaSTG-x/Debug/LuaSTG-x.app
```

The build collects scripts, resources, and application metadata. The default iOS OpenAL framework is copied to `Frameworks/soft_oal.framework`. With video enabled, the selected `Frameworks/FFmpeg.framework` is also copied. The Xcode generator configures framework embedding and Code Sign On Copy; actual signing follows the application's signing settings.

For device installation, append your development team and application identifier to the configure command, for example:

```text
-DCMAKE_XCODE_ATTRIBUTE_DEVELOPMENT_TEAM=YOUR_TEAM_ID
-DCMAKE_XCODE_ATTRIBUTE_CODE_SIGN_STYLE=Automatic
-DMACOSX_BUNDLE_GUI_IDENTIFIER=com.example.luastgx
```

`MACOSX_BUNDLE_GUI_IDENTIFIER` defaults to `com.xrysnow.lstgx` and sets both the application plist identifier and Xcode's Product Bundle Identifier. Signing also requires a valid local certificate, a matching provisioning profile, and developer account configuration. Check Signing & Capabilities in the generated Xcode project. For compilation without installation, use a separate build directory and append `-DCMAKE_XCODE_ATTRIBUTE_CODE_SIGNING_ALLOWED=NO`. Unsigned output cannot be installed directly on a physical device.

## Troubleshooting

| Symptom | What to check |
| --- | --- |
| Initial configuration spends a long time on OpenSSL | Configuration includes dependency compilation. Read the output and build-directory logs; check host tools such as Perl, make, and MSVC |
| OpenSSL reports an identity change after updating build integration | Use a new build directory, or `cmake --fresh` with the original tool, configuration, and feature arguments to rerun dependency probes. Do not edit identity caches manually |
| Only Debug/Release configurations are accepted | Set `CMAKE_BUILD_TYPE` for single-configuration generators or restrict `CMAKE_CONFIGURATION_TYPES` for multi-configuration generators; passing only build-time `--config` is insufficient |
| Cubism Core headers or libraries are missing | Check the SDK version, `Core/` directory layout, and target architecture. Recursive submodule initialization does not supply ignored SDK files |
| Perl module errors when building Android on Windows | Check that MSYS Perl is being used and that its modules/overlay are available. Native Windows targets have different Perl requirements |
| Android parameters appear to have no effect | Check whether `app/build.gradle` forwards the property. A `-P` Gradle property does not automatically become a same-named `-D` CMake variable |
| Windows cannot find startup scripts | Use the source root as the development working directory, or provide a complete runtime directory with `src/`, `res/`, and game data |
| Linux deployment reports missing libraries, RPATH, or objdump | Install binutils, enable RPATH support, and check linked dependencies. Do not bypass a failed dependency scan |
| Apple configuration reports a missing architecture, SDK, or deployment version | Explicitly set `CMAKE_OSX_ARCHITECTURES`, `CMAKE_OSX_SYSROOT`, and `CMAKE_OSX_DEPLOYMENT_TARGET` during initial configuration |
| The Apple FFmpeg framework is incomplete | Check the XCFramework, accompanying headers, and symbolic links. Preserve the original files rather than manually rewriting signed bundles |
| An iOS simulator build links device objects | Check the SDK, architecture, and device/simulator dependency slices. zlib should use the SDK link stub, and Cubism Core should use the matching simulator directory |

Before reusing a build directory, check its `CMakeCache.txt` for the source path, generator, architecture, configuration, and feature settings. Fix build issues in source configuration or the tool environment rather than manually editing generated projects or caches.
