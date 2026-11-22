---@class ui.ColorPicker.EditAlpha:cc.Node
local M = class('ui.ColorPicker.EditAlpha', cc.Node)
local eb_sz = cc.size(56, 28)

function M:ctor(editBoxSize, onEdit)
    editBoxSize = editBoxSize or eb_sz
    local h = editBoxSize.height
    local fsz = math.floor(h * 0.7)
    --local dx = editBoxSize.width + fsz * 2
    self.lb_A = self:_createLabel('A:', fsz)
    self.lb_A:addTo(self):setPosition(cc.p(0, 0))

    local x0 = 24
    self.eb_A = self:_createEditBox(editBoxSize, onEdit)
    self.eb_A:addTo(self):setPosition(cc.p(x0, -h / 2))
end

function M:setValue(v)
    v = math.clamp(math.round(v), 0, 255)
    if v == self:getValue() then
        return
    end
    self._set = true
    self.eb_A:setValue(v)
    self._set = false
end

function M:getValue()
    return self.eb_A:getValue()
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
