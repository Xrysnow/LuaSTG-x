-- 0 - disable debug info, 1 - less debug info, 2 - verbose debug info
DEBUG = 0

-- use framework, will disable all deprecated API, false - use legacy API
CC_USE_FRAMEWORK = true

-- show FPS on screen
CC_SHOW_FPS = true

-- disable create unexpected global variable
CC_DISABLE_GLOBAL = false

-- for module display
CC_DESIGN_RESOLUTION = {
    width = 1708,
    height = 960,
    autoscale = "SHOW_ALL",
    callback = function(framesize)
        return { autoscale = "SHOW_ALL" }
    end
}

--
local M = {}

require('cocos.cocos2d.json')
local json = cjson or json

local settingPath = 'setting'
if lstg.GetPlatform() == 'android' then
    local path = require('platform.android.native').getInternalDataPath()
    assert(path and path ~= '', 'internal app storage is unavailable')
    settingPath = path:gsub('/+$', '') .. '/setting'
end
local f = cc.FileUtils:getInstance():getStringFromFile(settingPath)
local ok, ret
if #f > 0 then
    ok, ret = pcall(json.decode, f)
end
if not ok or not ret then
    ok, ret = pcall(require, 'default_setting')
    if not ok or not ret then
        lstg.SystemLog(tostring(ret))
    end
end

--- setting used for initialization
---@type lstg.setting
M.setting = ret

local desktop = { windows = true, mac = true, linux = true }
local isDesktop = desktop[lstg.GetPlatform()]
M.setting.resizable = true
--M.setting.transparent = true

if isDesktop and M.setting.transparent then
    -- GLFW_TRANSPARENT_FRAMEBUFFER
    lstg.WindowHelper:getInstance():hint(0x0002000A, 1)
    cc.Director:getInstance():setClearColor({ r = 0, g = 0, b = 0, a = 0 })
end

local director = cc.Director:getInstance()
local view = director:getOpenGLView()
local title = 'LuaSTG-x'

local function rect(_x, _y, _width, _height)
    return { x = _x, y = _y, width = _width, height = _height }
end
if not view then
    local setting = M.setting
    local width = 960
    local height = 640
    if CC_DESIGN_RESOLUTION then
        if CC_DESIGN_RESOLUTION.width then
            width = CC_DESIGN_RESOLUTION.width
        end
        if CC_DESIGN_RESOLUTION.height then
            height = CC_DESIGN_RESOLUTION.height
        end
    end
    if setting then
        local w = setting.windowsize_w or width
        local h = setting.windowsize_h or height
        if setting.windowed then
            if setting.resizable and isDesktop then
                view = cc.GLViewImpl:createWithRect(title, rect(0, 0, w, h), 1, true)
            else
                view = cc.GLViewImpl:createWithRect(title, rect(0, 0, w, h))
            end
        else
            view = cc.GLViewImpl:createWithFullScreen(title)
            if not view then
                -- Locked/disconnected displays may not expose a fullscreen mode.
                view = cc.GLViewImpl:createWithRect(title, rect(0, 0, w, h), 1, true)
            end
        end
    else
        view = cc.GLViewImpl:createWithRect(title, rect(0, 0, width, height))
    end
    director:setOpenGLView(view)
    if lstg.GetPlatform() == 'linux' then
        view:setIcon('icon.png')
    end
    if cc.Configuration then
        local cfg = cc.Configuration:getInstance()
        local backend_device = cfg:getValue('renderer', 'N/A')
        local backend_version = cfg:getValue('version', 'N/A')
        lstg.SystemLog(('Backend device: %s'):format(backend_device))
        lstg.SystemLog(('Backend version: %s'):format(backend_version))
    end
end

return M
