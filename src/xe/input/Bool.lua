local base = require('xe.input.Base')
---@class xe.input.Bool:xe.input.Base
local M = class('xe.input.Bool', base)
local im = imgui
local wi = require('imgui.Widget')
local map = { ['true'] = true, ['false'] = false }
local function toboolean(s)
    return map[s]
end

---@param node xe.SceneNode
function M:ctor(node, idx)
    base.ctor(self, node, idx, 'bool')

    local value = node:getAttrEditValue(idx, self._type)
    if type(value) ~= 'boolean' then
        value = node:getAttrValue(idx)
        if map[value] ~= nil then
            value = map[value]
        else
            value = map[node:getDefaultAttrValue(idx)]
        end
    end
    if type(value) ~= 'boolean' then
        value = false
    end

    self._value = tostring(value)

    local cb = wi.Checkbox('', toboolean(self._value), function(_, v)
        self._value = v and 'true' or 'false'
        self:submit()
    end)
    self:addChild(cb)
end

function M:setValue(v)
    if type(v) == 'boolean' then
        v = tostring(v)
    end
    assert(v == 'true' and v == 'false')
    self._value = v
end

return M
