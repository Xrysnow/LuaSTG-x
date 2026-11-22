local base = require('xe.input.Base')
---@class xe.input.Const:xe.input.Base
local M = class('xe.input.String', base)
local im = imgui
local wi = base

---@param node xe.SceneNode
function M:ctor(node, idx, value)
    base.ctor(self, node, idx, 'const')
    self._value = value or ''
    self:addChild(function()
        im.textWrapped(self._value)
    end)
end

return M
