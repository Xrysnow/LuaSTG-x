---@class ui.ColorPicker.EditHex:cc.Node
local M = class('ui.ColorPicker.EditHex', cc.Node)
local eb_sz = cc.size(96, 28)

function M:ctor(editBoxSize, onEdit)
    editBoxSize = editBoxSize or eb_sz
    local h = editBoxSize.height
    local fsz = math.floor(h * 0.7)
    self.lb = self:_createLabel('Hex:', fsz)
    self.lb:addTo(self):setPosition(cc.p(0, 0))

    local x0 = math.floor(fsz * 2.5)
    self.eb = self:_createEditBox(editBoxSize, onEdit)
    self.eb:addTo(self):setPosition(cc.p(x0, -h / 2))
end

local function _tohex(c)
    local a, r, g, b = c.a, c.r, c.g, c.b
    local ret = 0
    for i, v in ipairs({ b, g, r, a }) do
        ret = ret + math.round(v) * math.pow(0x100, i - 1)
    end
    return ret
end

local function _tocolor(val)
    val = math.clamp(math.round(val), 0, 0xFFFFFFFF)
    local ret = cc.c4b(0, 0, 0, 0)
    for i, v in ipairs({ 'b', 'g', 'r', 'a' }) do
        ret[v] = math.floor((val % math.pow(0x100, i)) / math.pow(0x100, i - 1))
    end
    return ret
end

function M:setValue(v)
    if type(v) == 'table' then
        --local str = string.format('(%d,%d,%d,%d) => %08X', v.a, v.r, v.g, v.b, _tohex(v))
        --Print(str)
        v = _tohex(v)
    end
    v = math.clamp(math.round(v), 0, 0xFFFFFFFF)
    if v == self:getValue() then
        return
    end
    self._set = true
    self.eb:setValue(v)
    self._set = false
end

function M:getValue()
    return _tocolor(self.eb:getValue())
end

function M:_createLabel(str, fontSize)
    return require('cc.ui.label').create(str, fontSize)
end

function M:_createEditBox(size, onEdit)
    local ret = require('cc.ui.property_input.common').hex(
            {}, size
    )
    if onEdit then
        ret._eb:addHandler('ended', function()
            if self._set then
                error('???')
            else
                onEdit()
            end
        end)
    end
    return ret
end

return M
