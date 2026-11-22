local base = require('imgui.widgets.Window')
---@class xe.AssetsManager:im.Window
local M = class('xe.AssetsManager', base)
local im = imgui
local wi = require('imgui.Widget')

function M:ctor()
    base.ctor(self, 'Assets')

    local ifont = require('xe.ifont')
    local btn_open = wi.Button(ifont.ExternalLinkAlt, function()
        self._tree:openCurrentFile()
    end)
    self:addChild(btn_open)

    local win = wi.ChildWindow('xe.assets.tree', im.vec2(-1, -1), true)
    self:addChild(win)
    self._treewin = win

    self._tree = require('xe.assets.AssetsTree')()
    self._tree:addTo(win)
end

---@return xe.AssetsTree
function M:getTree()
    return self._tree
end

return M
