local base = require('imgui.widgets.Window')
---@class xe.SceneEditor:im.Window
local M = class('xe.SceneEditor', base)
local im = imgui
local wi = require('imgui.Widget')

function M:ctor()
    base.ctor(self, 'Scene Editor')
    self:addChild(function()
        if im.isWindowFocused(im.FocusedFlags.ChildWindows) then
            self:_handleKeyboard()
        end
    end)

    self._toolbar = require('xe.tools.ToolBar')()
    self:addChild(self._toolbar)

    self._toolpanel = require('xe.tools.ToolPanel')()
    self:addChild(self._toolpanel)
    self._toolpanel:disableAll()

    local win = wi.ChildWindow('xe.scene.tree', im.vec2(-1, -1), true)
    self:addChild(win)
    self._treewin = win

    -- replace default navigation in tree
    win:addChild(function()
        self:_handleNav()
        if im.isWindowFocused(im.FocusedFlags.ChildWindows) then
            self:_handleTreeKeyboard()
        end
    end)

    local setting = setting.xe
    local style = wi.style(nil, {
        [im.StyleVar.FramePadding] = function()
            local v = setting.editor_tree_padding or 0
            return im.vec2(v, v)
        end
    })
    style:addTo(win)

    self._tree = require('xe.SceneTree')()
    self._tree:addTo(style)

    self._game = require('xe.win.GameView')()
    self._game:addTo(self):setVisible(false)
end

---@return xe.SceneTree
function M:getTree()
    return self._tree
end

function M:setEditor()
    self._toolbar:setVisible(true)
    self._toolpanel:setVisible(true)
    self._treewin:setVisible(true)
    self._game:setVisible(false)
end

function M:setGame()
    self._toolbar:setVisible(false)
    self._toolpanel:setVisible(false)
    self._treewin:setVisible(false)
    self._game:setVisible(true)
end

local kbNav, gpNav
local kbNavFlag = im.ConfigFlags.NavEnableKeyboard
local gpNavFlag = im.ConfigFlags.NavEnableGamepad
local disabled
function M:_handleNav()
    if im.isWindowFocused() then
        if not disabled then
            kbNav = im.configFlagCheck(kbNavFlag)
            gpNav = im.configFlagCheck(gpNavFlag)
            disabled = true
        end
        im.configFlagDisable(kbNavFlag, gpNavFlag)
    else
        disabled = false
        if kbNav then
            im.configFlagEnable(kbNavFlag)
        end
        if gpNav then
            im.configFlagEnable(gpNavFlag)
        end
    end
end

function M:_handleKeyboard()
    -- only handle node operations
    if self._treewin:isVisible() then
        -- editor
        local tool = require('xe.ToolMgr')
        local t = {
            { 'ctrl', 'c', tool.copy },
            { 'ctrl', 'x', tool.cut },
            { 'ctrl', 'v', tool.paste },
            { 'delete', nil, tool.delete },
        }
        for _, v in ipairs(t) do
            if im.checkKeyboard(v[1], v[2]) then
                v[3]()
                break
            end
        end
    end
end

function M:_handleTreeKeyboard()
    if self._treewin:isVisible() then
        -- tree navigation
        local tree = self._tree
        local cur = tree:getCurrent()
        if not cur then
            return
        end
        local skip = { 'ctrl', 'alt', 'shift' }
        for _, v in ipairs(skip) do
            if im.checkKeyboard(v) then
                return
            end
        end

        if im.checkKeyboard('up') then
            local prev = cur:getBrotherPrev()
            if prev then
                prev = prev:getLastVisibleChild()
            end
            if not prev then
                prev = cur:getParentNode()
            end
            if prev then
                prev:select()
            end
        elseif im.checkKeyboard('down') then
            local next
            if not cur:isFold() and cur:getChildrenCount() > 0 then
                next = cur:getChildAt(1)
            end
            if not next then
                next = cur:getBrotherNext()
            end
            if not next then
                local p = cur:getParentNode()
                local idx = cur:getIndex()
                while p do
                    if p:getChildrenCount() > idx then
                        next = p:getChildAt(idx + 1)
                    else
                        idx = p:getIndex()
                    end
                    if next then
                        break
                    end
                    p = p:getParentNode()
                end
            end
            if next then
                next:select()
            end
        elseif im.checkKeyboard('left') then
            if cur:getChildrenCount() > 0 then
                cur:fold()
            end
        elseif im.checkKeyboard('right') then
            if cur:getChildrenCount() > 0 then
                cur:unfold()
            end
        end
    end
end

M.KeyEvent = {
    { 'ctrl', 'n', 'new' },
    { 'ctrl', 'o', 'open' },
    { 'ctrl', 's', 'save' },
    { 'ctrl', 'w', 'close' },
    { 'f7', nil, 'build' },
    { 'f6', nil, 'debugStage' },
    { 'shift', 'f6', 'debugSC' },
    { 'f5', nil, 'run' },

    { 'alt', 'up', 'moveUp' },
    { 'alt', 'down', 'moveDown' },
    { 'ctrl', 'up', 'insertBefore' },
    { 'ctrl', 'down', 'insertAfter' },
    { 'ctrl', 'right', 'insertChild' },
}

return M
