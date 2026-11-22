local base = require('imgui.Widget')

---@class im.Selectable:im.Widget
local M = class('im.Selectable', base)

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

function M:setSelected(label)
    self:setParam(2, label)
    return self
end

function M:getSelected()
    return self:getParam(2)
end

function M:setFlags(flag, ...)
    self:setParam(3, bit.bor(flag, ...))
    return self
end

function M:getFlags()
    return self:getParam(3)
end

function M:setContentSize(size)
    base.setContentSize(self, size)
    self:setParam(4, imgui.size(size))
    return self
end

function M:getContentSize()
    return imgui.toccsize(self:getParam(4))
end

function M:setOnSelect(f)
    self._onsel = f
    return self
end

function M:_handler()
    local ret
    imgui.pushID(tostring(self))
    ret = { imgui.selectable(unpack(self._param)) }
    imgui.popID()
    self._ret = ret
    if ret[1] and self._onsel then
        self:_onsel()
    end
    base._handler(self)
end

return M
