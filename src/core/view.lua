lstg.view3d = {
    ---eye position
    eye  = { 0, 0, -1 },
    ---at position
    at   = { 0, 0, 0 },
    ---up vector
    up   = { 0, 1, 0 },
    ---field of view y (rad)
    fovy = PI_2,
    ---clipping plane, {near, far}
    z    = { 0, 2 },
    ---fog param, {start, end, color}
    fog  = { 0, 0, Color(0x00000000) }
}
lstg.scale_3d = 0.007 * screen.scale

local scale
local ui_vp_l, ui_vp_r, ui_vp_b, ui_vp_t
local ui_or_l, ui_or_r, ui_or_b, ui_or_t
local world_vp_l, world_vp_r, world_vp_b, world_vp_t
local world_or_l, world_or_r, world_or_b, world_or_t
local world
local _world_dirty = true

local function _log()
    local fmt = '%.1f, %.1f, %.1f, %.1f'
    local ui_vp = string.format(fmt, ui_vp_l, ui_vp_r, ui_vp_b, ui_vp_t)
    local ui_or = string.format(fmt, ui_or_l, ui_or_r, ui_or_b, ui_or_t)
    local world_vp = string.format(fmt, world_vp_l, world_vp_r, world_vp_b, world_vp_t)
    local world_or = string.format(fmt, world_or_l, world_or_r, world_or_b, world_or_t)
    local t = {
        ui_vp        = ui_vp, ui_or = ui_or,
        world_vp     = world_vp, world_or = world_or,
        screen_scale = screen.scale
    }
    SystemLog('view params:\n' .. stringify(t))
end

local function loadViewParams()
    local screen = screen
    local setting = setting

    scale = screen.scale

    ui_vp_l = 0
    ui_vp_r = setting.resx
    ui_vp_b = 0
    ui_vp_t = setting.resy
    ui_or_l = -screen.dx
    ui_or_r = (setting.resx / scale - screen.dx)
    ui_or_b = -screen.dy
    ui_or_t = (setting.resy / scale - screen.dy)

    world_vp_l = (world.scrl + screen.dx) * scale
    world_vp_r = (world.scrr + screen.dx) * scale
    world_vp_b = (world.scrb + screen.dy) * scale
    world_vp_t = (world.scrt + screen.dy) * scale
    world_or_l = world.l
    world_or_r = world.r
    world_or_b = world.b
    world_or_t = world.t

    _world_dirty = false
    --local x0,y0=WorldToScreen(0,0)
    --local x1,y1=WorldToScreen(1,1)
    --SystemLog(string.format('WorldToScreen: %f, %f, %f, %f',x0,y0,x1,y1))
    --_log()
    local check = world_or_l ~= world_or_r
    check = check and world_or_b ~= world_or_t
    if not check then
        _log()
        error('error in loadViewParams')
    end
    --assert(world_or_l~=world_or_r)
    --assert(world_or_b~=world_or_t)
end
local function _LoadViewParams()
    loadViewParams()
    _log()
end
lstg.loadViewParams = _LoadViewParams

local sqrt = math.sqrt
local tan = math.tan
local mt_world = {
    __index    = function(t, k)
        return world[k]
    end,
    __newindex = function(t, k, v)
        world[k] = v
        _world_dirty = true
    end
}
local function _set_mt()
    world = lstg.world
    --lstg.world = {}
    lstg.world = setmetatable({}, mt_world)
end
_set_mt()
loadViewParams()
local _last_world = lstg.world

local function _setViewMode(mode)
    lstg.viewmode = mode
    if mode == '3d' then
        local view3d = lstg.view3d
        local world_ = lstg.world
        SetViewport(
                world_vp_l, world_vp_r, world_vp_b, world_vp_t)
        SetPerspective(
                view3d.eye[1], view3d.eye[2], view3d.eye[3],
                view3d.at[1], view3d.at[2], view3d.at[3],
                view3d.up[1], view3d.up[2], view3d.up[3],
                view3d.fovy,
                (world_.r - world_.l) / (world_.t - world_.b),
                view3d.z[1], view3d.z[2])

        SetFog(view3d.fog[1], view3d.fog[2], view3d.fog[3])

        local dx, dy, dz = view3d.eye[1] - view3d.at[1], view3d.eye[2] - view3d.at[2], view3d.eye[3] - view3d.at[3]
        SetImageScale(
                sqrt(dx * dx + dy * dy + dz * dz) * 2
                        * tan(view3d.fovy * 0.5)
                        / (world_.scrr - world_.scrl))

    elseif mode == 'world' then
        SetViewport(
                world_vp_l, world_vp_r, world_vp_b, world_vp_t)
        SetOrtho(
                world_or_l, world_or_r, world_or_b, world_or_t)
        SetFog()
        --SetImageScale((world.r-world.l)/(world.scrr-world.scrl))--usually it is 1
        SetImageScale(1)

    elseif mode == 'ui' then
        SetViewport(
                ui_vp_l, ui_vp_r, ui_vp_b, ui_vp_t)
        SetOrtho(
                ui_or_l, ui_or_r, ui_or_b, ui_or_t)
        SetFog()
        SetImageScale(1)

    else
        error(i18n 'Invalid arguement for SetViewMode')
    end
end
lstg.forceSetViewMode = _setViewMode

--- 设置视角模式: 3d world ui
--- 'world': 对应lstrg.world
--- 'ui': 对应screen坐标系
--- '3d': 对应lstg.view3d
---@param mode string
function SetViewMode(mode)
    if lstg.world ~= _last_world then
        _last_world = lstg.world
        _set_mt()
        loadViewParams()
    elseif _world_dirty then
        loadViewParams()
    elseif lstg.viewmode == mode then
        return
    end
    _setViewMode(mode)
end

---设置3D变量
function Set3D(key, a, b, c)
    if key == 'fog' then
        a = tonumber(a or 0)
        b = tonumber(b or 0)
        lstg.view3d.fog = { a, b, c }
        return
    end
    a = tonumber(a or 0)
    b = tonumber(b or 0)
    c = tonumber(c or 0)
    if key == 'eye' then
        lstg.view3d.eye = { a, b, c }
    elseif key == 'at' then
        lstg.view3d.at = { a, b, c }
    elseif key == 'up' then
        lstg.view3d.up = { a, b, c }
    elseif key == 'fovy' then
        lstg.view3d.fovy = a
    elseif key == 'z' then
        lstg.view3d.z = { a, b }
    end
end

---重置3D变量
function Reset3D()
    lstg.view3d.eye = { 0, 0, -1 }
    lstg.view3d.at = { 0, 0, 0 }
    lstg.view3d.up = { 0, 1, 0 }
    lstg.view3d.fovy = PI_2
    lstg.view3d.z = { 1, 2 }
    lstg.view3d.fog = { 0, 0, Color(0x00000000) }
end

local function getViewModeInfo(mode)
    local ret = ''
    if mode == '3d' then
        local view3d = lstg.view3d
        local vp = string.format(
                'vp: (%.1f, %.1f, %.1f, %.1f)',
                world_vp_l, world_vp_r, world_vp_b, world_vp_t)
        local eye = string.format(
                'eye: (%.1f, %.1f, %.1f)',
                view3d.eye[1], view3d.eye[2], view3d.eye[3])
        local at = string.format(
                'at: (%.1f, %.1f, %.1f)',
                view3d.at[1], view3d.at[2], view3d.at[3])
        local up = string.format(
                'up: (%.1f, %.1f, %.1f)',
                view3d.up[1], view3d.up[2], view3d.up[3])
        local others = string.format(
                'fovy: %.2f z: (%.1f, %.1f)',
                view3d.fovy, view3d.z[1], view3d.z[2])
        ret = string.format(
                '%s\n%s\n%s\n%s\n%s',
                vp, eye, at, up, others)
    elseif mode == 'world' then
        local vp = string.format(
                'vp: (%.1f, %.1f, %.1f, %.1f)',
                world_vp_l, world_vp_r, world_vp_b, world_vp_t)
        local or_ = string.format(
                'or: (%.1f, %.1f, %.1f, %.1f)',
                world_or_l, world_or_r, world_or_b, world_or_t)
        ret = string.format(
                '%s\n%s',
                vp, or_)
    elseif mode == 'ui' then
        local vp = string.format(
                'vp: (%.1f, %.1f, %.1f, %.1f)',
                ui_vp_l, ui_vp_r, ui_vp_b, ui_vp_t)
        local or_ = string.format(
                'or: (%.1f, %.1f, %.1f, %.1f)',
                ui_or_l, ui_or_r, ui_or_b, ui_or_t)
        ret = string.format(
                '%s\n%s',
                vp, or_)
    end
    return ret
end
lstg.getViewModeInfo = getViewModeInfo

