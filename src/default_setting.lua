--
local KEY = require('keycode')
---@class lstg.setting
local M = {
    allowsnapshot  = true,
    username       = 'User',
    font           = '',
    timezone       = 8,
    resx           = 1706,
    resy           = 960,
    windowed       = true,
    vsync          = true,
    sevolume       = 100,
    bgmvolume      = 100,

    keys           = {
        up      = KEY.UP,
        down    = KEY.DOWN,
        left    = KEY.LEFT,
        right   = KEY.RIGHT,
        slow    = KEY.SHIFT,
        shoot   = KEY.Z,
        spell   = KEY.X,
        special = KEY.SPACE,
    },
    keysys         = {
        repfast         = KEY.CTRL,
        repslow         = KEY.ALT,
        menu            = KEY.ESCAPE,
        snapshot        = KEY.HOME,

        toggle_collider = KEY.F8,
    },
    -- note: key codes in [keys] and [keysys] should be mutex

    posteffect     = true,
    res_ratio      = { 16, 9 },
    -- desktop
    window_title   = 'LuaSTG-x',
    windowsize_w   = 1708,
    windowsize_h   = 960,
    -- mobile
    orientation    = 'landscape',
    touchkey       = true,

    controller_map = {
        keys   = {
            up      = { 14 },
            down    = { 16 },
            left    = { 19 },
            right   = { 15 },
            slow    = { 05 },
            shoot   = { 09 },
            spell   = { 04 },
            special = { 07 },
        },
        keysys = {
            repfast  = { 01, true },
            repslow  = { 01, false },
            menu     = { 06 },
            snapshot = { 10 },
        },
    },
    gamepad_actions = {
        version = 2,
        slot = 0,
        keys = {
            up = 'dpup', down = 'dpdown', left = 'dpleft', right = 'dpright',
            slow = 'leftshoulder', shoot = 'south', spell = 'east', special = 'west',
        },
        keysys = { repfast = '+righttrigger', repslow = '+lefttrigger', menu = 'start', snapshot = 'back' },
    },
    gamepad_hardware = {},
    gamepad_preferred = '',
    --
    render_skip    = 0,
    --
    imgui_visible  = false,
    xe             = {
        frame_size             = { 1280, 720 },
        -- editor
        auto_save              = true,
        editor_tree_padding    = 0,
        editor_tree_indent     = nil,
        prop_se_play           = true,
        -- debug
        cheat                  = false,
        debug_sc_current_only  = false,
        -- project
        pack_to_engine_path    = false,
        -- code
        code_editor_font_scale = 100,
        code_editor_theme      = 'Light',
        -- UI
        theme                  = 'Light',
    }
}

return M
