local base = require('imgui.Widget')

---@class im.TreeNode:im.Widget
local M = class('im.TreeNode', base)

function M:ctor(...)
    base.ctor(self, ...)
    self._id = tostring(self)
end

function M:setLabel(label)
    self:setParam(1, label)
    return self
end

function M:getLabel()
    return self:getParam(1)
end

function M:setFlags(flag, ...)
    self:setParam(2, bit.bor(flag, ...))
    return self
end

function M:getFlags()
    return self:getParam(2)
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
    local ret = { imgui.treeNodeEx(self._id, self._param[2] or 0, self._param[1]) }
    self._ret = ret
    if ret[1] then
        base._handler(self)
        -- pop when return true
        imgui.treePop()
    end
end

return M
