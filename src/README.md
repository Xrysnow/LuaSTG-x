# lstgx_LuaCore

Core Lua scripts of [LuaSTG-x](https://github.com/Xrysnow/LuaSTG-x).

## Instructions

- `app`: defines what will be loaded when the engine starts.
- `audio`: helpers for audio engine.
- `cc`: helpers for cocos things.
- `cocos`, `packages.mvc`: provided by cocos.
- `core`: provide core APIs. Should not loaded by the user.
- `core_x`: provide support for other modules. Should not loaded by the user.
- `game`: helpers and experimental codes for games.
- `i18n`: i18n module.
- `imgui`: imgui helpers.
- `l2d`: live2d helpers.
- `math`: math extension.
- `platform`: platform dependent codes.
- `plus`: ported from LuaSTGPlus.
- `shader`: default shaders.
- `util`: utilities.
- `video`: optional video API compatibility; load `require("video.compat")` after video registration to support the old Player interface.
