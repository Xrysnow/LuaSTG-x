local base = require('imgui.Widget')

---@class im.TabBar:im.Widget
local M = class('im.TabBar', base)
local im = imgui

function M:ctor(...)
    base.ctor(self, ...)
    if not self:getID() then
        self:setID('')
    end
end

function M:setID(id)
    self:setParam(1, id)
    return self
end

function M:getID()
    return self:getParam(1)
end

function M:setFlags(flag, ...)
    self:setParam(2, bit.bor(flag, ...))
    return self
end

function M:getFlags()
    return self:getParam(2)
end

function M:isOpen()
    return self:getReturn(1)
end

function M:_handler()
    im.pushID(tostring(self))
    local ret = { im.beginTabBar(unpack(self._param)) }
    im.popID()
    self._ret = ret
    if ret[1] then
        base._handler(self)
        im.endTabBar()
    end
end

return M
