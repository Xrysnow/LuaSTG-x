local base = require('imgui.Widget')

---@class im.TabItem:im.Widget
local M = class('im.TabItem', base)
local im = imgui

function M:ctor(...)
    base.ctor(self, ...)
    self._closable = type(self:getParam(2)) == 'boolean'
    cc.Node.setName(self, self:getName())
end

function M:setName(name)
    cc.Node.setName(self, name)
    self:setParam(1, name)
    return self
end

function M:getName()
    return self:getParam(1)
end

function M:setClosed(b)
    if self:isClosable() then
        self:setParam(2, b)
    end
    return self
end

function M:isClosed()
    if self:isClosable() then
        return self:getParam(2)
    else
        return false
    end
end

function M:setFlags(flag, ...)
    self:setParam(3, bit.bor(flag, ...))
    return self
end

function M:getFlags()
    return self:getParam(3)
end

function M:setClosable(b)
    b = b and true or false
    if self._closable ~= b then
        if b then
            self:setParam(2, true)
        else
            self:setParam(2, nil)
        end
    end
    self._closable = b
end

function M:isClosable()
    return self._closable
end

function M:isOpen()
    return self:getReturn(1)
end

function M:_handler()
    im.pushID(tostring(self))
    local ret = { im.beginTabItem(unpack(self._param)) }
    im.popID()
    self._ret = ret
    if ret[2] then
        -- closable
        self._param[2] = ret[2]
    end
    if ret[1] then
        base._handler(self)
        im.endTabItem()
    end
end

return M
