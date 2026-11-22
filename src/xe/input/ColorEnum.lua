local base = require('xe.input.Base')
---@class xe.input.ColorEnum:xe.input.Base
local M = class('xe.input.ColorEnum', base)
local im = imgui
local wi = require('imgui.Widget')
local cache = cc.Director:getInstance():getTextureCache()
local colors = {
    COLOR_DEEP_RED      = 1,
    COLOR_RED           = 2,
    COLOR_DEEP_PURPLE   = 3,
    COLOR_PURPLE        = 4,
    COLOR_DEEP_BLUE     = 5,
    COLOR_BLUE          = 6,
    COLOR_ROYAL_BLUE    = 7,
    COLOR_CYAN          = 8,
    COLOR_DEEP_GREEN    = 9,
    COLOR_GREEN         = 10,
    COLOR_CHARTREUSE    = 11,
    COLOR_YELLOW        = 12,
    COLOR_GOLDEN_YELLOW = 13,
    COLOR_ORANGE        = 14,
    COLOR_DEEP_GRAY     = 15,
    COLOR_GRAY          = 16,
}
M._colors = colors
for i = 1, 16 do
    colors[i] = table.keyof(colors, i)
end

---@param node xe.SceneNode
function M:ctor(node, idx)
    base.ctor(self, node, idx, 'color_enum')
    local value = node:getAttrValue(idx)
    if not colors[value] then
        value = self:getEditValue() or colors[1]
    end
    self._value = value
    self._sel = colors[value]

    local tex = cache:addImage('xe/color_enum.png')
    local images = {}
    for i, v in ipairs(colors) do
        local xx = (i - 1) % 4 * 64
        local yy = math.floor((i - 1) / 4) * 64
        local sp = cc.Sprite:createWithTexture(tex, cc.rect(xx, yy, 64, 64))
        sp:addTo(self):setVisible(false)
        images[i] = sp
    end
    self._img = images

    local btn = wi.Button('', function()
        im.openPopup('xe.input.ColorEnum')
    end, im.Dir.Down, 'arrow')
    self:addChild(btn)
    self:addChild(function()
        self:_render()
        im.sameLine()
        im.text(self._value)
    end)
end

function M:_render()
    if im.beginPopup('xe.input.ColorEnum') then
        if self:_renderColorSelector() then
            im.closeCurrentPopup()
        end
        im.endPopup()
    end
end

function M:_renderColorSelector(nCol)
    nCol = nCol or 4
    local w = im.getWindowWidth()
    local spa = im.getStyle().ItemSpacing
    local spaw = spa.x
    local size = im.p(32, 32)
    if nCol == -1 then
        local count = math.floor((w - spaw) / (size.x + spaw))
        nCol = math.max(count, 1)
    end
    local dl = im.getWindowDrawList()

    local ret, any_ret
    for i = 1, #colors do
        local p = im.getCursorScreenPos()
        local sp = self._img[i]
        ret = im.imageButton(sp, size, 0)
        if ret then
            local old = self._sel
            if old ~= i then
                self._sel = i
                self._value = colors[i]
                self:submit()
            end
            any_ret = true
        end
        if self._sel == i then
            dl:addRect(p, cc.pAdd(p, size), im.getColorU32(im.Col.ButtonActive), 0, 0, 3)
        end
        if i % nCol ~= 0 and i < #colors then
            im.sameLine()
        end
    end
    return any_ret
end

return M
