---@class ui.Caption:cc.Node
local M = class('ui.Caption', cc.Node)

function M:ctor(title, bg_color, w, h, fontSize, fontColor)
    title = title or 'Dialog'
    bg_color = bg_color or cc.c4b(0, 136, 255, 255)
    fontSize = fontSize or math.round(h * 0.6)
    if not fontColor then
        fontColor = (color.gray(bg_color) > 0.5 * 255) and cc.BLACK or cc.WHITE
    end
    self._bg = cc.LayerColor:create(bg_color, w, h)
    self._bg:addTo(self)
    self._lb = require('cc.ui.label').create(title, fontSize)
    self._lb:addTo(self):setPosition(4, h / 2)
    self._lb:setTextColor(fontColor)
    self:setAnchorPoint(cc.p(0.5, 0.5))
    self:setContentSize(cc.size(w, h))
end

function M:setBackgroundColor(c)
    self._bg:setColor(c)
    if c.a then
        self._bg:setOpacity(c.a)
    end
end

function M:getBackgroundColor()
    local c = self._bg:getColor()
    local a = self._bg:getOpacity()
    return cc.c4b(c.r, c.g, c.b, a)
end

function M:setTextColor(c)
    self._lb:setTextColor(c)
end

function M:getTextColor()
    return self._lb:getTextColor()
end

function M:setTitle(title)
    self._lb:setString(title)
end

function M:getTitle()
    return self._lb:getString()
end

return M
