-- 0 - disable debug info, 1 - less debug info, 2 - verbose debug info
DEBUG = 0

-- Load the cocos framework helpers.
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

local json = require('cocos.cocos2d.json')
local defaults = require('default_setting')

local settingPath = 'setting'
if lstg.GetPlatform() == 'android' then
    local path = require('platform.android.native').getInternalDataPath()
    assert(path and path ~= '', 'internal app storage is unavailable')
    settingPath = path:gsub('/+$', '') .. '/setting'
end
local f = cc.FileUtils:getInstance():getStringFromFile(settingPath)
local settings = {}
if #f > 0 then
    local ok, decoded = pcall(json.decode, f)
    if ok and type(decoded) == 'table' then
        settings = decoded
    end
end

--- setting used for initialization
---@type lstg.setting
M.setting = setmetatable(settings, { __index = defaults })

-- Hosts can set CC_WINDOW_TITLE before startup. The launcher also calls this
-- after loading settings from the platform's writable directory.
function M.getWindowTitle(setting)
    if type(CC_WINDOW_TITLE) == 'string' then return CC_WINDOW_TITLE end
    if type(setting.window_title) == 'string' then return setting.window_title end
    return defaults.window_title
end

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

local function rect(_x, _y, _width, _height)
    return { x = _x, y = _y, width = _width, height = _height }
end
if not view then
    local setting = M.setting
    local title = M.getWindowTitle(setting)
    if not setting.windowed then
        view = cc.GLViewImpl:createWithFullScreen(title)
    end
    -- Locked/disconnected displays may not expose a fullscreen mode.
    if not view then
        local frame = rect(0, 0, setting.windowsize_w, setting.windowsize_h)
        if isDesktop and setting.resizable then
            view = cc.GLViewImpl:createWithRect(title, frame, 1, true)
        else
            view = cc.GLViewImpl:createWithRect(title, frame)
        end
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
