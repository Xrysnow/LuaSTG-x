local base = require('imgui.Widget')

---@class im.CollapsingHeader:im.Widget
local M = class('im.CollapsingHeader', base)

function M:ctor(...)
    base.ctor(self, ...)
    self._closable = type(self:getParam(2)) == 'boolean'
end

function M:setLabel(label)
    self:setParam(1, label)
    return self
end

function M:getLabel()
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
    self:setParam(self:isClosable() and 3 or 2, bit.bor(flag, ...))
    return self
end

function M:getFlags()
    return self:getParam(self:isClosable() and 3 or 2)
end

function M:setClosable(b)
    b = b and true or false
    if self._closable ~= b then
        if b then
            self:setParam(3, self:getParam(2))
            self:setParam(2, true)
        else
            self:setParam(3, nil)
            self:setParam(2, self:getParam(3))
        end
    end
    self._closable = b
end

function M:isClosable()
    return self._closable
end

function M:setOpen(b)
    self._needopen = b
    return self
end

function M:isOpen()
    if self._needopen ~= nil then
        return self._needopen
    else
        return self:getReturn(1)
    end
end

function M:_handler()
    if self._needopen ~= nil then
        imgui.setNextItemOpen(self._needopen)
        self._needopen = nil
    end
    imgui.pushID(tostring(self))
    local ret = { imgui.collapsingHeader(unpack(self._param)) }
    imgui.popID()
    if ret[2] then
        -- closable
        self._param[2] = ret[2]
    end
    self._ret = ret
    if ret[1] then
        base._handler(self)
    end
end

return M
