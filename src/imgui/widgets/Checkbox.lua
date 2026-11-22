local base = require('imgui.Widget')

---@class im.Checkbox:im.Widget
local M = class('im.Checkbox', base)

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

function M:setOnChange(f)
    self._onchange = f
    return self
end

function M:_handler()
    imgui.pushID(tostring(self))
    self._ret = { imgui.checkbox(unpack(self._param)) }
    imgui.popID()
    local last = self._param[2]
    local curr = self._ret[2]
    self._param[2] = curr
    if curr and self._oncheck then
        self:_oncheck()
    end
    if last ~= curr then
        self:_onchange(curr)
    end
    base._handler(self)
end

return M
