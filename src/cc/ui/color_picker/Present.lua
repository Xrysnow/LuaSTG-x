---@class ui.ColorPicker.Present:cc.Node
local M = class('ui.ColorPicker.Present', cc.Node)

function M:ctor(init_color)
    init_color = init_color or cc.c4b(255, 255, 255, 255)
    self._bg = cc.Sprite:create('ui/color_picker/present_bg.png')
    local sz = self._bg:getContentSize()
    self._bg:addTo(self):setPosition(sz.x / 2, sz.y / 2)
    self._ly = cc.LayerColor:create(init_color, sz.x, sz.y)
    --self._ly:setIgnoreAnchorPointForPosition(false):setAnchorPoint(cc.p(0.5, 0.5))
    self._ly:addTo(self)
end

function M:setValue(c4b)
    self._ly:setColor(c4b)
    self._ly:setOpacity(c4b.a)
end

return M
