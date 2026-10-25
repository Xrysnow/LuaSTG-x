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
