local base = require('imgui.Widget')

---@class im.RadioButton:im.Widget
local M = class('im.RadioButton', base)

function M:ctor(...)
    base.ctor(self, ...)
end

function M:setLabel(label)
    self:setParam(1, label)
    return self
end

function M:getLabel()
    return self:getParam(1)
end

function M:setChecked(b)
    self:setParam(2, b)
    return self
end

---@return boolean
function M:isChecked()
    return self:getParam(2)
end

---@return boolean
function M:isPressed()
    return self:getReturn(1)
end

function M:setOnCheck(f)
    self._oncheck = f
    return self
end

function M:setActiveChecker(f)
    self._checker = f
    return self
end

function M:_handler()
    if self._checker then
        self._param[2] = self:_checker()
    end
    imgui.pushID(tostring(self))
    self._ret = { imgui.radioButton(self._param[1], self._param[2]) }
    imgui.popID()
    local pressed = self._ret[1]
    if pressed and self._oncheck then
        self:_onclick()
    end
    base._handler(self)
end

return M
