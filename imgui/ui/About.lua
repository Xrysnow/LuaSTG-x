local base = require('imgui.Widget')
---@class im.About:im.Widget
local M = class('im.About', base)
local im = imgui
local wi = base
local _platform = {
    'Windows', 'Linux', 'macOS', 'Android', 'iOS', }
local _languages = {
    'english', 'chinese', 'french', 'italian', 'german',
    'spanish', 'dutch', 'russian', 'korean', 'japanese',
    'hungarian', 'portuguese', 'arabic', 'norwegian', 'polish',
    'turkish', 'ukrainian', 'romanian', 'bulgarian', 'belarusian', }

-- Draw inside the current window so launchers and standalone windows share content.
function M.renderContent()
    local app = cc.Application:getInstance()
    local platform = _platform[app:getTargetPlatform() + 1]
    local lang = _languages[app:getCurrentLanguage() + 1] or 'unknown'
    local cfg = cc.Configuration:getInstance()
    local cc_version = cfg:getValue('cocos2d.x.version', 'N/A')
    local backend_device = cfg:getValue('renderer', 'N/A')
    local backend_version = cfg:getValue('version', 'N/A')
    local build_date = lstg.GetBuildDate and lstg.GetBuildDate() or 'N/A'
    local d = M._data

    im.pushFont(nil, im.getStyle().FontSizeBase * 1.5)
    im.textWrapped('LuaSTG-x')
    im.popFont()
    im.separator()
    im.textWrapped(i18n(d[1]))
    im.textWrapped(i18n(d[2]) .. ': https://github.com/Xrysnow/LuaSTG-x')
    im.text('')
    im.textWrapped(i18n(d[3]) .. ': ' .. build_date)
    im.textWrapped(i18n(d[4]) .. ': ' .. cc_version)
    im.textWrapped(i18n(d[5]) .. ': ' .. backend_device)
    im.textWrapped(i18n(d[6]) .. ': ' .. backend_version)
    im.textWrapped(i18n(d[7]) .. ': ' .. jit.version)
    im.textWrapped(i18n(d[8]) .. ': ' .. jit.arch)
    im.textWrapped(i18n(d[9]) .. ': ' .. platform)
    im.textWrapped(i18n(d[10]) .. ': ' .. lang:capitalize())
    im.text('')
    im.textWrapped('Copyright (C) 2018-2026 Xrysnow')
end

function M:ctor(isPopup)
    base.ctor(self)
    self._setting = setting.xe
    if isPopup == nil then
        isPopup = true
    end
    self._isPopup = isPopup
    self:addChild(function()
        local hh = -im.getFrameHeightWithSpacing()
        if not isPopup then
            hh = -1
        end

        if im.beginChild(im.getID('lstg.about'), im.vec2(-1, hh),
                im.ImGuiChildFlags.ImGuiChildFlags_FrameStyle) then
            M.renderContent()
        end
        im.endChild()
    end)

    if isPopup then
        local ok = wi.Button('OK', function()
            self:setVisible(false)
        end)
        self:addChildren(ok)
    end
end

local _id = 'About'
function M:_handler()
    if self._isPopup then
        im.setNextWindowSize(im.vec2(350, 350), im.Cond.Once)
        im.openPopup(_id)
        if im.beginPopupModal(_id) then
            wi._handler(self)
            im.endPopup()
        end
    else
        wi._handler(self)
    end
end

local function get_ins()
    return require('xe.main'):getInstance()._about
end

function M:show()
    if self == nil or self == M then
        self = get_ins()
    end
    self:setVisible(true)
    return self
end

function M.createWindow(...)
    local ret = require('imgui.widgets.Window')(...)
    ret:addChild(M(false))
    return ret
end

M._data = {
    {
        en = 'LuaSTG-x is a multi-platform game engine',
        zh = 'LuaSTG-x是一款跨平台游戏引擎',
    },
    {
        en = 'Project home page',
        zh = '项目主页',
    },
    {
        en = 'Build date',
        zh = '编译日期',
    },
    {
        en = 'Engine version',
        zh = '引擎版本',
    },
    {
        en = 'Render device name',
        zh = '渲染设备名称',
    },
    {
        en = 'Render device version',
        zh = '渲染设备版本',
    },
    {
        en = 'LuaJIT version',
        zh = 'LuaJIT版本',
    },
    {
        en = 'Architecture',
        zh = '架构',
    },
    {
        en = 'Platfrom',
        zh = '平台',
    },
    {
        en = 'Language',
        zh = '语言',
    },
}

return M
