--- version info
_luastg_version = 0x1000
_luastg_min_support = 0x1000

local __internal = {}
for k, v in pairs(lstg) do
    _G[k] = v
    __internal = v
end
lstg._internal = __internal
require('core.respool')

UnitList = ObjList
GetnUnit = GetnObj
cjson = cjson or json
math.mod = math.mod or math.fmod
string.gfind = string.gfind or string.gmatch
collectgarbage("setpause", 100)

for _, ns in ipairs({ cc, ccb, ccui, lstg }) do
    for _, v in pairs(ns) do
        local mt = getmetatable(v)
        if mt and (v.create or v.new) then
            if v.create then
                mt.__call = function(t, ...)
                    return t:create(...)
                end
            else
                mt.__call = function(t, ...)
                    return t:new(...)
                end
            end
        end
    end
end

function Serialize(o)
    if type(o) == 'table' then
        function visitTable(t)
            local ret = {}
            if getmetatable(t) and getmetatable(t).data then
                t = getmetatable(t).data
            end
            for k, v in pairs(t) do
                if type(v) == 'table' then
                    ret[k] = visitTable(v)
                else
                    ret[k] = v
                end
            end
            return ret
        end
        o = visitTable(o)
    end
    return cjson.encode(o)
end

function DeSerialize(s)
    return cjson.decode(s)
end

--- keycode
KEY = require('keycode')

default_setting = require('default_setting')
setting = default_setting

function DoFile(path)
    Print('[load] ' .. path)
    return lstg.DoFile(path)
end

DoFile('plus/plus.lua')
DoFile('stringify.lua')
--require('forward')
require('api')
if plus.isMobile() then
    _G['Print'] = function(...)
        local args = { ... }
        local narg = select('#', ...)
        for i = 1, narg do
            args[i] = tostring(args[i])
        end
        SystemLog(table.concat(args, '\t'))
    end
else
    _G['Print'] = function(...)
        local args = { ... }
        local narg = select('#', ...)
        for i = 1, narg do
            args[i] = tostring(args[i])
        end
        lstg.Print(table.concat(args, '\t'))
        if lstg._onPrint then
            lstg._onPrint(...)
        end
    end
end
print = Print

--if plus.isDesktop() then
require('imgui.__init__')
--end

local setting_util = require('setting_util')
local str = Serialize(default_setting)
str = setting_util.format_json(str)
if not setting_util.compare(DeSerialize(str), default_setting) then
    error(i18n 'error in parsing setting')
end

local FU = cc.FileUtils:getInstance()
local setting_path = plus.getWritablePath() .. 'setting'
local _setting = {}

function lstg.loadSettingFile()
    local f = FU:getStringFromFile(setting_path)
    setting = DeSerialize(Serialize(default_setting))
    _setting = setting
    setting = {}
    setmetatable(setting, {
        __newindex = function(t, k, v)
            --rawset(t, k, v)
            _setting[k] = v
            if k == 'res_ratio' then
                local ratio = v[1] / v[2]
                setting.resx = math.ceil(setting.resy * ratio / 2) * 2
                --setting.windowsize_w = math.ceil(setting.windowsize_h * ratio / 2) * 2
            elseif k == 'resy' then
                local ratio = setting.res_ratio[1] / setting.res_ratio[2]
                setting.resx = math.ceil(v * ratio / 2) * 2
            --elseif k == 'windowsize_h' then
            --    local ratio = setting.res_ratio[1] / setting.res_ratio[2]
            --    setting.windowsize_w = math.ceil(setting.windowsize_h * ratio / 2) * 2
            end
        end,
        __index    = _setting
    })

    if f and f ~= '' then
        local s = DeSerialize(f)
        for k, v in pairs(s) do
            if k ~= 'gamepad_actions' or (type(v) == 'table' and v.version == default_setting.gamepad_actions.version) then
                setting[k] = v
            end
        end
    end
end

function lstg.saveSettingFile()
    assert(setting and getmetatable(setting))
    local t = getmetatable(setting).__index
    local s = setting_util.format_json(Serialize(t))
    assert(setting_util.compare(DeSerialize(s), t))
    local saved
    if lstg.SaveSettingsAtomically then
        saved = lstg.SaveSettingsAtomically(setting_path, s)
    else
        saved = FU:writeStringToFile(s, setting_path)
    end
    if not saved then
        error(('failed to save settings to %q'):format(setting_path))
    end
    return true
end

lstg.loadSettingFile()

if _ARGS and #_ARGS >= 2 then
    assert(loadstring(_ARGS[2]))()
    setting.mod_info = nil
end
if start_game then
    require('app.views.MainScene').setSkip(true, true)
end

local glv = cc.Director:getInstance():getOpenGLView()

SetSplash(true)
SetTitle(require('config').getWindowTitle(setting))
if plus.os == 'android' then
    assert(SetDesignResolution(setting.resx, setting.resy))
else
    local changed = ChangeVideoMode(
            setting.windowsize_w,
            setting.windowsize_h,
            setting.windowed,
            setting.vsync
    )
    if not changed and not setting.windowed then
        if ChangeVideoMode(setting.windowsize_w, setting.windowsize_h, true, setting.vsync) then
            setting.windowed = true
            SystemLog('fullscreen unavailable; started in windowed mode')
        end
    end
end
if setting.render_skip == 1 then
    SetFPS(30)
else
    SetFPS(60)
end
SetSEVolume(setting.sevolume / 100)
SetBGMVolume(setting.bgmvolume / 100)

--require('app.views.MainScene').setSkip(true, true)
--cheat = true

function lstg.loadSetting(change_vm)
    --if change_vm and (not setting.windowed) then
    --    ChangeVideoMode(0,0,false, setting.vsync)
    --else
    --    SetVsync(setting.vsync)
    --end
    SetVsync(setting.vsync)
    glv:setDesignResolutionSize(
            setting.resx, setting.resy, cc.ResolutionPolicy.SHOW_ALL)
    SetTitle(setting.mod)
    --SetWindowed(setting.windowed)
    --SetFPS(60)
    --SetVsync(true)
    SetSEVolume(setting.sevolume / 100)
    SetBGMVolume(setting.bgmvolume / 100)
    lstg.calcScreen()
    lstg.loadViewParams()
    _SetBound()
    local pe = {
        --"LoadFX",
        "PushRenderTarget",
        "PopRenderTarget",
        "PostEffect",
        "PostEffectCapture",
        "PostEffectApply",
        --"SetShaderUniform",
    }
    if setting.posteffect then
        --for _, v in ipairs(pe) do
        --    _G[v] = _G[v] or lstg[v]
        --end
    else
        --for _, v in ipairs(pe) do
        --    _G[v] = function()
        --    end
        --end
    end

    local size = glv:getDesignResolutionSize()
    SystemLog(string.format('DesignRes = %d, %d', size.x, size.y))
    size = glv:getFrameSize()
    SystemLog(string.format('FrameSize = %d, %d', size.x, size.y))
    SystemLog(string.format('Scale     = %.3f, %.3f', glv:getScaleX(), glv:getScaleY()))
    --SystemLog('setting = \n' .. stringify(_setting))
    --SystemLog('screen = \n' .. stringify(screen))
end

--SetResLoadInfo(true)
--require("jit.opt").start("sizemcode=1024", "maxmcode=1024")

DoFile('core/__init__.lua')
