---@class ui.ColorPicker.EditRGB:cc.Node
local M = class('ui.ColorPicker.EditRGB', cc.Node)
--local eb_sz = cc.size(56, 28)

function M:ctor(editBoxSize, onEdit)
    --editBoxSize = editBoxSize or eb_sz
    local h = editBoxSize.height
    local fsz = math.floor(h * 0.7)
    local dx = editBoxSize.width + fsz * 2
    self.lb_R = self:_createLabel('R:', fsz)
    self.lb_R:addTo(self):setPosition(cc.p(0, 0))
    self.lb_G = self:_createLabel('G:', fsz)
    self.lb_G:addTo(self):setPosition(cc.p(dx, 0))
    self.lb_B = self:_createLabel('B:', fsz)
    self.lb_B:addTo(self):setPosition(cc.p(dx * 2, 0))

    local x0 = 24
    self.eb_R = self:_createEditBox(editBoxSize, onEdit)
    self.eb_R:addTo(self):setPosition(cc.p(x0, -h / 2))
    self.eb_G = self:_createEditBox(editBoxSize, onEdit)
    self.eb_G:addTo(self):setPosition(cc.p(x0 + dx, -h / 2))
    self.eb_B = self:_createEditBox(editBoxSize, onEdit)
    self.eb_B:addTo(self):setPosition(cc.p(x0 + dx * 2, -h / 2))
end

local function _eq(v1, v2)
    for k, v in pairs(v1) do
        if v ~= v2[k] then
            return false
        end
    end
    return true
end

function M:setValue(c3b)
    if _eq(c3b, self:getValue()) then
        return
    end
    self._set = true
    self.eb_R:setValue(c3b.r)
    self.eb_G:setValue(c3b.g)
    self.eb_B:setValue(c3b.b)
    self._set = false
end

function M:getValue()
    return cc.c3b(
            self.eb_R:getValue(),
            self.eb_G:getValue(),
            self.eb_B:getValue()
    )
end

function M:_createLabel(str, fontSize)
    return require('cc.ui.label').create(str, fontSize)
end

function M:_createEditBox(size, onEdit)
    local ret = require('cc.ui.property_input.common').integer(
            { min = 0, max = 255 }, size
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
