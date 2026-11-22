local base = require('imgui.widgets.TabItem')
---@class xe.TabContent:im.TabItem
local M = class('xe.TabContent', base)
local im = imgui
local wi = require('imgui.Widget')

function M:ctor(title)
    base.ctor(self, title)
end

function M:addContent(icon, tooltip, cb)
    local sp = icon
    local scale = lstg.WindowHelper:getInstance():getDpiScale()
    local btn, btn_disable = require('xe.util').createButton(sp, 2, scale)
    self:addChild(btn):addChild(btn_disable)
    if cb then
        btn:setOnClick(cb)
    end

    if tooltip then
        self:addChild(function()
            if im.isItemHovered() then
                im.setTooltip(tooltip)
            end
        end)
    end

    return btn, btn_disable
end

return M
