local base = require('imgui.Widget')
---@class xe.ui.TreeView:im.Widget
local M = class('xe.ui.TreeView', base)
local im = imgui

function M:ctor(...)
    base.ctor(self, ...)
    self._level = -1
    self._isview = true
end

function M:_setRoot(node)
    if node then
        assert(not self.root)
        ---@type xe.ui.TreeNode
        self.root = node
        self.root._isroot = true
        self.root:_setParentNode(self)
        self.root:addTo(self)
    else
        self.root = nil
    end
end

function M:getRoot()
    return self.root
end

function M:setCurrent(node)
    if self._cur and self._cur ~= node then
        self._cur:unselect()
    end
    self._cur = node
end
---@return xe.ui.TreeNode
function M:getCurrent()
    return self._cur
end

return M
