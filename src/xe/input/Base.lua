local base = require('imgui.Widget')
---@class xe.input.Base:im.Widget
local M = class('xe.input.Base', base)

---@param node xe.SceneNode
function M:ctor(node, idx, type)
    base.ctor(self)
    assert(node and idx and type)
    ---@type xe.SceneNode
    self._node = node
    self._idx = idx
    self._type = type
end

function M:getValue()
    return self._value
end

function M:setValue(v)
    self._value = v
end

function M:getString()
    return M:getValue()
end

function M:getType()
    return self._type
end

function M:_setNodeValue(value)
    if value == nil then
        value = self:getValue()
    end
    self._node:setAttrEditType(self._idx, self._type)
    self._node:setAttrEditValue(self._idx, self._type, value)
end

function M:submit(value)
    self:_setNodeValue(value)
    require('xe.SceneTree').submit()
    self:_checkValid()
end

function M:getEditValue()
    local node = self._node
    local idx = self._idx
    return node:getAttrEditValue(idx, self._type) or node:getDefaultAttrValue(idx) or ''
end

function M:_checkValid()
    local ok, msg = self._node:checkAttrEdit(self._idx)
    if not ok then
        if not msg or msg == '' then
            msg = 'invalid'
        end
        self._error = msg
    else
        self._error = nil
    end
end

function M:getError()
    return self._error
end

function M:setError(v)
    self._error = v
end

return M
