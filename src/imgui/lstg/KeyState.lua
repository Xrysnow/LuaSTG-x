local base = require('imgui.Widget')
---@class im.lstg.KeyState:im.Widget
local M = class('im.lstg.KeyState', base)
local im = imgui
local keys = {
    { 'C', 'special' },
    { 'X', 'spell' },
    { '^', 'up' },
    { 'SH', 'slow' },
    { 'Z', 'shoot' },
    { '<', 'left' },
    { 'v', 'down' },
    { '>', 'right' },
}

function M:ctor(...)
    base.ctor(self, ...)
    local sz = im.vec2(36, 36)
    local sp = cc.Sprite:create()
    sp:addTo(self):setVisible(false)
    local id = 'im.lstg.KeyState'
    local function render(idx, c)
        local state = KeyState[keys[idx][2]]
        if state then
            im.pushStyleColor(im.Col.Button, c)
            im.pushStyleColor(im.Col.ButtonHovered, c)
            im.pushStyleColor(im.Col.ButtonActive, c)
        end
        im.button(keys[idx][1], sz)
        if state then
            im.popStyleColor(3)
        end
    end
    self:addChild(function()
        local c1 = im.getStyleColorVec4(im.Col.Button)
        local c2 = im.getStyleColorVec4(im.Col.ButtonHovered)
        im.pushStyleColor(im.Col.ButtonHovered, c1)
        im.pushStyleColor(im.Col.ButtonActive, c1)

        render(1, c2)
        im.sameLine()
        render(2, c2)
        im.sameLine()
        im.invisibleButton(id, sz)
        im.sameLine()
        render(3, c2)
        im.sameLine()
        im.invisibleButton(id, sz)

        render(4, c2)
        im.sameLine()
        render(5, c2)
        im.sameLine()
        render(6, c2)
        im.sameLine()
        render(7, c2)
        im.sameLine()
        render(8, c2)

        im.popStyleColor(2)
    end)
end

return M
