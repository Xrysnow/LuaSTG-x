local base = require('xe.input.Base')
---@class xe.input.Enum:xe.input.Base
local M = class('xe.input.Enum', base)
local im = imgui
local wi = require('imgui.Widget')

---@param node xe.SceneNode
function M:ctor(node, idx, items)
    base.ctor(self, node, idx, 'enum')

    if not items or #items == 0 then
        items = { '' }
    end
    local map = {}
    for i, v in ipairs(items) do
        map[v] = i
    end
    local value = self:getEditValue()
    if not map[value] then
        value = node:getAttrValue(idx) or ''
        if not map[value] then
            value = items[1]
        end
    end
    self._value = value
    self._sel = map[value]

    local selector = wi.Combo('', items, self._sel)
    selector:setOnChange(function(_, _, ii)
        self._sel = ii
        self._value = assert(items[ii])
        self:submit()
    end)
    self:addChild(function()
        im.setNextItemWidth(-1)
    end):addChild(selector)
end

return M
