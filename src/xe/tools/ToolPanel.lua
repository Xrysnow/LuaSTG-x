local base = require('imgui.Widget')
---@class xe.ToolPanel:im.Widget
local M = class('editor.ToolPanel', base)
local im = imgui
local wi = require('imgui.Widget')

function M:ctor()
    base.ctor(self, 'Tools')
    --self:setFlags(
    --        im.WindowFlags.NoTitleBar,
    --        im.WindowFlags.HorizontalScrollbar)
    self._panels = {}
    self._btns = {}
    self._tabbar = wi.TabBar('xe.tools.TabBar')
    self:addChild(self._tabbar)

    local def = require('xe.node_def._def')
    def.regist()
    local data = require('xe.tools.data')
    for _, v in ipairs(data) do
        local tab = self:_createTab(v.label)
        for i, item in ipairs(v.content) do
            --assert(item.name:sub(1, 7) == 'Insert_')
            local name = item.name--:sub(8)
            local icon_name = string.filename(item.bitmap or '')
            local d = def.getDefine(name)
            if d and d.icon then
                icon_name = d.icon
            end
            local icon = require('xe.node.icon').getIcon(icon_name)
            local tooltip = name
            if d and d.disptype then
                tooltip = i18n(d.disptype)
            end
            local function f()
                require('xe.main').getEditor():getTree():newNode(name)
            end
            local btn, btn2 = tab:addContent(icon, tooltip, f)
            if i < #v.content then
                tab:addChild(im.sameLine)
            end
            self._btns[name] = { btn, btn2 }
        end
    end
end

function M:_createTab(title)
    local panel = require('xe.tools.TabContent')(title)
    panel:addTo(self._tabbar)
    table.insert(self._panels, panel)
    return panel
end

function M:disable(name)
    local t = self._btns[name]
    if not t then
        return
    end
    t[1]:setVisible(false)
    t[2]:setVisible(true)
end

function M:enable(name)
    local t = self._btns[name]
    if not t then
        return
    end
    t[1]:setVisible(true)
    t[2]:setVisible(false)
end

function M:disableAll()
    for k, v in pairs(self._btns) do
        v[1]:setVisible(false)
        v[2]:setVisible(true)
    end
end

function M:enableAll()
    for k, v in pairs(self._btns) do
        v[1]:setVisible(true)
        v[2]:setVisible(false)
    end
end

return M
