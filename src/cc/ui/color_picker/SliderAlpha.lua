---@class ui.SliderAlpha:cc.Node
local M = class('ui.SliderAlpha', cc.Node)
local path = 'ui/color_picker/'
local vert = { { -1, -1 }, { -1, 1 }, { 1, 1 }, { 1, -1 }, { -1, -1 } }
local c1 = 250 / 255
local c2 = 150 / 255
local hw, hh = 6, 128
local length = 256
local rot = -90

function M:ctor(onSlide)
    self._slider = ccui.Slider:create(
            path .. 'trans_bar.png',
            path .. 'slider.png'
    )
    self._slider:addTo(self):setRotation(rot)
    if onSlide then
        self._slider:addEventListener(function()
            onSlide()
        end)
    end

    local frame = cc.DrawNode:create()
    frame:setLineWidth(1):addTo(self._slider):setPosition(cc.p(128, 6)):setRotation(rot)
    frame:setLocalZOrder(-1)

    local _trans_bg = cc.Sprite:create(path .. 'trans_bar_bg.png')
    _trans_bg:setScaleY(-1)
    _trans_bg:addTo(self._slider):setPosition(cc.p(128, 6)):setLocalZOrder(-1)

    for i, c in ipairs({ cc.c4f(c1, c1, c1, 1), cc.c4f(c2, c2, c2, 1) }) do
        for j = 1, 4 do
            local v1 = vert[j]
            local v2 = vert[j + 1]
            local p1 = cc.p(v1[1] * (hw + i - 1), v1[2] * (hh + i - 1))
            local p2 = cc.p(v2[1] * (hw + i), v2[2] * (hh + i))
            frame:drawLine(p1, p2, c)
        end
    end

    --for i = 0, 255 do
    --    self:setValue(i)
    --    local got = self:getValue()
    --    if got ~= i then
    --        error(string.format('test failed: expected %f, got %f', i, got))
    --    end
    --end
end

function M:getValue()
    local position = self._slider:getSlidBallRenderer():getPosition()
    local x, _ = position.x, position.y
    local v = x / length * 255
    return math.clamp(math.round(v), 0, 255)
end

function M:setValue(v)
    v = math.clamp(math.round(v), 0, 255)
    if v == self:getValue() then
        return
    end
    self._slider:setPercent(v / 255 * 100)
    local position = self._slider:getSlidBallRenderer():getPosition()
    local _, y = position.x, position.y
    self._slider:getSlidBallRenderer():setPosition(v / 255 * length, y)
end

function M:setHintColor(c)
    self._slider:getVirtualRenderer():setColor(c)
end

return M
