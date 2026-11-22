local base = require('imgui.widgets.TreeNode')
---@class xe.ui.TreeNode:im.TreeNode
local M = class('xe.ui.TreeNode', base)
local im = imgui
local wi = require('imgui.Widget')
local _flags = bit.bor(
        im.TreeNodeFlags.OpenOnArrow,
        im.TreeNodeFlags.OpenOnDoubleClick,
        im.TreeNodeFlags.FramePadding,
        im.TreeNodeFlags.SpanAllAvailWidth,
        im.TreeNodeFlags.AllowItemOverlap)
M._height = 16

function M:ctor(text)
    base.ctor(self, text or '...')
    self._select = false
    self._onSelect = std.fvoid
    self._onUnselect = std.fvoid
    self._children = std.list()
    ---@type xe.ui.TreeNode
    self._parent = nil
    self._level = 0
    self._index = 1
    if not self:getString() then
        self:setString('-')
    end
end

function M:getIndex()
    return self._index
end
--- for_each iterator
function M:children()
    return self._children:iter()
end
---@return xe.ui.TreeNode
function M:getChildAt(idx)
    return self._children:at(idx)
end
function M:getChildrenCount()
    return self._children:size()
end
--- get count of all descendants
function M:getDescendantsCount()
    local ret = 0
    for i = 1, self:getChildrenCount() do
        ret = ret + 1 + self:getChildAt(i):getDescendantsCount()
    end
    return ret
end
function M:getLastDescendant(canBeThis)
    local count = self:getChildrenCount()
    if count == 0 then
        if canBeThis then
            return self
        else
            return
        end
    end
    return self:getChildAt(count):getLastDescendant(true)
end

function M:setString(str)
    self:setLabel(str)
end

function M:getString()
    return self:getLabel()
end

function M:insertChild(child)
    assert(iskindof(child, M.__cname), tostring(getclassname(child)))
    self:unfold()
    self._children:push_back(child)
    child._index = self._children:size()
    child:_setParentNode(self)
    self:addChild(child)
end

function M:insertChildAt(idx, child)
    assert(iskindof(child, M.__cname), tostring(getclassname(child)))
    self:unfold()
    if idx < 1 or idx > self._children:size() + 1 then
        error('invalid index ' .. idx)
    end

    for _, v in self._children:iter() do
        v:retain()
        v:removeSelf()
    end

    self._children:insert_at(idx, child)
    child:_setParentNode(self)
    self:_updateChildrenIndex()

    for _, v in self._children:iter() do
        self:addChild(v)
        if v ~= child then
            v:release()
        end
    end
end

function M:insertBefore(child)
    if self:isRoot() then
        return
    end
    self._parent:insertChildAt(self._index, child)
end
function M:insertAfter(child)
    if self:isRoot() then
        return
    end
    self._parent:insertChildAt(self._index + 1, child)
end
function M:deleteChild(child)
    assert(self:hasChild(child))
    self._children:remove_if(function(v)
        return type(v) == type(child) and tostring(v) == tostring(child)
    end)
    local view = self:getView()
    if view and view:getCurrent() == child then
        view:setCurrent(nil)
    end
    if child._onDelete then
        child:_onDelete()
    end
    child:removeSelf()
    self:_updateChildrenIndex()
end
function M:deleteChildAt(idx)
    idx = self:_checkChildIndex(idx)
    local child = self._children:at(idx)
    local view = self:getView()
    if view and view:getCurrent() == child then
        view:setCurrent(nil)
    end
    if child._onDelete then
        child:_onDelete()
    end
    child:removeSelf()
    self._children:erase_at(idx)
    self:_updateChildrenIndex()
end
function M:deleteAllChildren()
    for _ = 1, self:getChildrenCount() do
        self:deleteChildAt(1)
    end
end
function M:delete()
    if self:isRoot() then
        return
    end
    self._parent:deleteChildAt(self._index)
end

function M:setOnDelete(cb)
    self._onDelete = cb
end

function M:toggle_fold()
    if self:isFold() then
        self:unfold()
    else
        self:fold()
    end
end

function M:fold()
    self:setOpen(false)
end

function M:unfold()
    self:setOpen(true)
end

function M:unfoldToThis()
    local p = self:getParentNode()
    while p do
        p:unfold()
        p = p:getParentNode()
    end
end

function M:isFold()
    return self._fold
end

function M:toggle_select()
    if self._select then
        self:unselect()
    else
        self:select()
    end
end

function M:select()
    if self._select then
        return
    end
    self._select = true
    if self._onSelect then
        self:_onSelect()
    end
end

function M:unselect()
    if not self._select then
        return
    end
    self._select = false
    if self._onUnselect then
        self:_onUnselect()
    end
end

function M:isSelected()
    return self._select
end
function M:setOnSelect(cb)
    self._onSelect = cb
end
function M:setOnUnselect(cb)
    self._onUnselect = cb
end
function M:getParentNode()
    if self:isRoot() then
        return
    end
    return self._parent
end
function M:_setParentNode(node)
    assert(node)
    if node == self._parent then
        return
    end
    assert(not self._parent,
           ('%s already has parent %s, try to set %s'):format(self, self._parent, node))
    self._parent = node
    self._level = node._level + 1
end
function M:_updateChildrenIndex()
    local i = 1
    for _, v in self._children:iter() do
        v._index = i
        i = i + 1
    end
end
function M:hasChild(node)
    for _, v in self._children:iter() do
        if type(v) == type(node) and tostring(v) == tostring(node) then
            return true
        end
    end
    return false
end
function M:_checkChildIndex(idx)
    idx = math.floor(idx)
    if idx < 1 or idx > self._children:size() then
        error(string.format('invalid index %d, should in range [1, %d]', idx, self._children:size()))
    end
    return idx
end
---@return xe.ui.TreeView
function M:getView()
    local p = self._parent
    local ret
    while p do
        ret = p
        p = p._parent
    end
    if ret and ret._isview then
        return ret
    end
end
---@return xe.ui.TreeNode
function M:getRoot()
    local p = self._parent
    local ret
    while p do
        ret = p
        p = p._parent
    end
    if ret._isview then
        return ret.root
    end
end
---@return boolean
function M:isRoot()
    return self._isroot
end
function M:isLeaf()
    return self:getChildrenCount() == 0
end

function M:getLastVisibleChild()
    if self:isFold() then
        return self
    else
        local n = self:getChildrenCount()
        if n == 0 then
            return self
        else
            return self:getChildAt(n):getLastVisibleChild()
        end
    end
end

function M:getTreeNext()
    if self:getChildrenCount() >= 1 then
        return self:getChildAt(1)
    end
    local p = self:getParentNode()
    local ic = self:getIndex()
    while p do
        if p:getChildrenCount() > ic then
            return p:getChildAt(ic + 1)
        end
        ic = p:getIndex()
        p = p:getParentNode()
    end
end
function M:getBrotherPrev()
    if self:isRoot() then
        return
    end
    local p = self:getParentNode()
    if p and self:getIndex() >= 2 then
        return p:getChildAt(self:getIndex() - 1)
    end
end
function M:getBrotherNext()
    if self:isRoot() then
        return
    end
    local p = self:getParentNode()
    if p and p:getChildrenCount() > self:getIndex() then
        return p:getChildAt(self:getIndex() + 1)
    end
end

function M:moveUp()
    local p = self:getParentNode()
    if self:isRoot() or not p then
        return
    end
    local idx = self:getIndex()
    if idx <= 1 then
        return
    end
    local prev = p:getChildAt(idx - 1)
    prev:retain()
    p:deleteChildAt(idx - 1)
    p:insertChildAt(idx, prev)
    prev:release()
    self:select()
end
function M:moveDown()
    local p = self:getParentNode()
    if self:isRoot() or not p then
        return
    end
    local idx = self:getIndex()
    if idx >= p:getChildrenCount() then
        return
    end
    local next = p:getChildAt(idx + 1)
    next:retain()
    p:deleteChildAt(idx + 1)
    p:insertChildAt(idx, next)
    next:release()
    self:select()
end

local t_insert = table.insert
local t_remove = table.remove
---@return xe.ui.TreeNode[]
function M:arrayDFS()
    local t = {}
    local stack = { self }
    while #stack > 0 do
        t_insert(t, stack[#stack])
        stack[#stack] = nil
        for _, v in self._children:iter_rev() do
            t_insert(stack, v)
        end
    end
    return t
end
---@return xe.ui.TreeNode[]
function M:arrayBFS()
    local t = {}
    local queue = { self }
    while #queue > 0 do
        t_insert(t, queue[1])
        t_remove(queue, 1)
        for _, v in self._children:iter() do
            t_insert(queue, v)
        end
    end
    return t
end

function M:_handler()
    self._cursor = im.getCursorScreenPos()
    self:_renderIcon()
    self:_renderIndentLine()

    if self._needopen ~= nil then
        im.setNextItemOpen(self._needopen)
        self._needopen = nil
    end
    local flags = _flags
    if self:isSelected() then
        flags = bit.bor(flags, im.TreeNodeFlags.Selected)
    end
    local is_leaf = self:isLeaf()
    if is_leaf then
        flags = bit.bor(flags,
                        im.TreeNodeFlags.Leaf,
                        im.TreeNodeFlags.NoTreePushOnOpen)
    end
    local str = self._param[1]
    assert(str)
    if str == '' then
        --str = ('[%s] select: %s'):format(self:getType(), self._select)
        --str = ('[%s] icon: %s'):format(self:getType(), self._icon)
        --str = ('[%s] idx: %s'):format(self:getType(), self._index)
    end
    if self._icon then
        str = '     ' .. str
    end
    local ret = { im.treeNodeEx(tostring(self), flags, str) }
    if im.isItemClicked() then
        self:select()
    end
    if self._renderContextItem then
        if im.beginPopupContextItem() then
            self:_renderContextItem()
            im.endPopup()
        end
    end

    if self:isRoot() then
        local cursor = im.getCursorScreenPos()
        M._height = cursor.y - self._cursor.y
    end

    self._ret = ret
    local fold_last = self._fold
    if ret[1] then
        self._fold = false
        wi._handler(self)
        -- pop when return true
        if not is_leaf then
            im.treePop()
        end
    else
        self._fold = true
    end
    if fold_last ~= self._fold and self._onFoldChange then
        self:_onFoldChange(self._fold)
    end
end

local round = math.round
local function pAdd(p1, p2)
    return { x = round(p1.x + p2.x), y = round(p1.y + p2.y) }
end

function M:_renderIcon()
    if not self._icon then
        return
    end
    local p = self._cursor
    local h = M._height
    local dl = im.getWindowDrawList()
    local padding = im.getStyle().FramePadding
    local spacing = im.getStyle().ItemSpacing
    local a = pAdd(p, cc.p(
            im.getTextLineHeight() + padding.x,
            h / 2 - 16 / 2 - spacing.y / 2))
    local b = pAdd(a, cc.p(16, 16))
    dl:addImage(self._icon, a, b)
end

function M:_renderIndentLine()
    if self:isFold() or self:getChildrenCount() == 0 then
        return
    end
    local next = self:getBrotherNext()
    if not next then
        return
    end
    local p1 = self._cursor
    local p2 = next._cursor
    if not p1 or not p2 then
        return
    end
    local color
    if self:isSelected() then
        color = im.getColorU32(im.Col.ButtonActive)
    else
        color = im.getColorU32(im.Col.Border)
    end
    local is_leaf = next:isLeaf()
    local h = im.getTextLineHeightWithSpacing()
    local xx = h / 2 + 1
    local cc = cc
    p1 = pAdd(p1, cc.p(xx, h * 0.9))
    if is_leaf then
        p2 = pAdd(p2, cc.p(xx, h * 0.4))
    else
        p2 = pAdd(p2, cc.p(xx, -h * 0.2))
    end
    local dl = im.getWindowDrawList()
    dl:addLine(p1, p2, color, 1)
    if is_leaf then
        p2 = pAdd(p2, cc.p(1, 0))
        local p3 = pAdd(p2, cc.p(h * 0.2, 0))
        dl:addLine(p2, p3, color, 1)
    end
end

return M
