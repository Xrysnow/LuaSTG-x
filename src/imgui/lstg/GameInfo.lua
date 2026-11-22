local base = require('imgui.widgets.Window')

---@class im.lstg.GameInfo:im.Window
local M = class('im.lstg.GameInfo', base)
local im = imgui

function M:ctor(...)
    base.ctor(self, ...)
    self:setFlags(im.WindowFlags.HorizontalScrollbar)
    local wi = require('imgui.Widget')
    self:addChildChain(
            wi.TreeNode('Game Resource'),
            require('imgui.lstg.GameResInfo')())
    self:addChildChain(
            wi.TreeNode('THlib Info'),
            require('imgui.lstg.THlibInfo')())
    self:addChildChain(
            wi.TreeNode('Performance'),
            require('imgui.lstg.PerformanceInfo')())

    self:addChildChain(
            wi.TreeNode('KeyState'),
            require('imgui.lstg.KeyState')())
end

return M
