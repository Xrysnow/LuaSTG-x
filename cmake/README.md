# Linux runtime deployment

On native Linux, linking also creates a movable runtime directory at
`<build>/deploy/LuaSTG-x/<config>/` containing the executable, its non-system
shared libraries, `src/`, and `res/`. An empty build type omits `<config>`.

Refresh it after changing resources or prebuilt libraries:

```sh
cmake --build <build> --target deploy-LuaSTG-x
```

For multi-config generators, select the configuration:

```sh
cmake --build <build> --target deploy-LuaSTG-x --config Release
```

Copy the whole deployment directory; `bin/` remains the development output.
Deployment requires `objdump` and enabled RPATH. The destination still needs
compatible Linux system libraries. Libraries under `/lib`, `/lib32`, `/lib64`,
`/usr/lib`, `/usr/lib32`, and `/usr/lib64`, and plugins loaded only through
`dlopen`, are not bundled.

Refresh updates/adds files without removing old files. Use a fresh build directory
when a distribution must exclude obsolete resources or dependencies.

# Apple FFmpeg

Apple builds use the expanded avbuild FFmpeg 9.0 lite package at
`frameworks/external/ffmpeg/prebuilt_apple/`: `FFmpeg.xcframework` and its matching
`include/` directory. CMake uses these files directly, without extracting or
copying the package during configuration. The original archive is retained in
`_misc/_external/ffmpeg-9.0/`.

Preserve the macOS framework's relative symbolic links (`Versions/Current`,
`FFmpeg`, and `Resources`). On Windows, enable Developer Mode and Git's
`core.symlinks=true` in the repository containing the package. Directory links
must be created as directory symbolic links, and native Windows link targets
must use backslashes; Git normalizes them to forward slashes for other platforms.
The package's `.gitattributes` disables line-ending conversion inside the
XCFramework so that signed files retain their original bytes.

CMake 3.28 or newer links the XCFramework through `ext_ffmpeg` and selects the
platform slice. The package includes macOS arm64/x86_64, iOS arm64, and iOS
simulator arm64/x86_64 slices; other engine dependencies may restrict which
architectures the complete application can build.
The arm64 slices require macOS 11 or newer and iOS 14 or newer for the simulator;
the iOS device slice has a lower deployment minimum.

Use the Xcode generator (`-G Xcode`) for automatic framework embedding and
code signing with the application's signing settings. Other generators copy
the selected framework into the app's `Frameworks` directory after linking;
signing the completed app remains a separate deployment step.
Apple prebuilt libraries are maintained only in `prebuilt_apple`.
