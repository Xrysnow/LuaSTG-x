--
local KEY = require('keycode')
local Button, Axis = cc.gamepad.Button, cc.gamepad.Axis
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
        version = 3,
        slot = 0,
        keys = {
            up = Button.DpadUp, down = Button.DpadDown, left = Button.DpadLeft, right = Button.DpadRight,
            slow = Button.LeftShoulder, shoot = Button.South, spell = Button.East, special = Button.West,
        },
        keysys = {
            repfast = { axis = Axis.RightTrigger, sign = 1 },
            repslow = { axis = Axis.LeftTrigger, sign = 1 },
            menu = Button.Start, snapshot = Button.Back,
        },
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
