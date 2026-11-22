---@class ui.TreeNode:ccui.Layout
local M = class('ui.TreeNode', ccui.Layout)

function M:ctor(icon, text, onSelect, onUnselect, param)
    self:setAnchorPoint(cc.p(0, 1))
    self._fold = false
    self._select = false
    self._onSelect = onSelect or std.fvoid
    self._onUnselect = onUnselect or std.fvoid
    self.param = param or {}
    self._h = self.param.item_h or 20

    local ico
    if type(icon) == 'string' then
        ico = cc.Sprite:create(icon)
    else
        ico = icon
    end
    assert(ico, "can't find icon " .. tostring(icon))
    ico:addTo(self):setPosition(cc.p(28, self._h / 2))

    ---@type button.toggle
    local toggle = require('cc.ui.ButtonToggle'):create(
            'editor/tree_toggle_on.png',
            'editor/tree_toggle_off.png',
            'editor/tree_toggle_off.png', 0)
    toggle:addTo(self):setPosition(cc.p(8, self._h / 2))
    toggle:addClickEvent(function()
        self:toggle_fold()
    end)
    self.toggle = toggle

    self._children = std.list()
    ---@type ui.TreeNode
    self._parent = nil
    self._level = 0
    self._index = 1
    self._selectTextColor = cc.WHITE
    self._unselectTextColor = self.param.text_color or cc.BLACK

    local xx = self.param.btn_offset or 48
    local lb = cc.Label:createWithSystemFont('_', 'Arial', math.floor(self._h * 0.6))
    lb:setHorizontalAlignment(cc.TEXT_ALIGNMENT_LEFT)
    lb:addTo(self):setAnchorPoint(cc.p(0, 0.5)):setPosition(cc.p(xx, self._h / 2))
    lb:setTextColor(self._unselectTextColor)
    self.lb = lb

    local btn = require('cc.ui.button').ButtonNull(cc.size(16, self._h), function()
        self:select()
    end)
    btn:addTo(self):setAnchorPoint(cc.p(0, 0.5)):setPosition(cc.p(xx - 2, self._h / 2))
    btn:setSwallowTouches(true)
    self.btn = btn

    local ly = cc.LayerColor:create(cc.c4b(0, 0, 255, 255), 16, self._h)
    ly:setIgnoreAnchorPointForPosition(false)
    ly:addTo(self):setAnchorPoint(cc.p(0, 0.5)):setPosition(cc.p(xx - 2, self._h / 2))
    ly:setLocalZOrder(-1):setVisible(false)
    self.selectBg = ly

    self:setString(text or '...')

    local _hidden = cc.Node:create()
    _hidden:addTo(self):setVisible(false)
    self._hidden = _hidden

    --self:setContentSize(cc.size(lb:getContentSize().x + 64, self._h))
    --self:setBackGroundColorType(1):setBackGroundColor(cc.c3b(127, 255, 127))
end

function M:setSelectColor(color)
    self.selectBg:setColor(color)
end

function M:setSelectTextColor(color)
    self._selectTextColor = color
    if self:isSelected() then
        self.lb:setTextColor(color)
    end
end

function M:getIndex()
    return self._index
end

--- for_each iterator
function M:children()
    return self._children:iter()
end

---@return ui.TreeNode
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
    self.lb:setString(str or '...')
    local w = self.lb:getContentSize().x
    self.btn:setContentSize(cc.size(w + 4, self._h))
    self.selectBg:setContentSize(cc.size(w + 4, self._h))
    self:setContentSize(cc.size(w + 56, self._h))
end

function M:getString()
    return self.lb:getString()
end

function M:setHeight(v)
    if self._h == v then
        return
    end
    self._h = v
    self:setString(self:getString())
    self:_updatePos()
end

function M:insertChild(child)
    assert(iskindof(child, 'ui.TreeNode'), 'got ' .. tostring(getclassname(child)))
    self:unfold()
    self._children:push_back(child)
    child._index = self._children:size()
    child:_setParentNode(self)
    self:addChild(child)
    self:_updatePos()
end

function M:insertChildAt(idx, child)
    assert(iskindof(child, 'ui.TreeNode'))
    self:unfold()
    if idx < 1 or idx > self._children:size() + 1 then
        error('invalid index ' .. idx)
    end
    self._children:insert_at(idx, child)
    child:_setParentNode(self)
    self:_updateChildrenIndex()
    self:addChild(child)
    self:_updatePos()
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
    if not self._fold then
        self:_updatePos()
    end
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
    if not self._fold then
        self:_updatePos()
    end
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
    if self._fold then
        self:unfold()
    else
        self:fold()
    end
end

function M:fold()
    if self._fold then
        return
    end
    self._fold = true
    for _, v in self._children:iter() do
        assert(v:getParent() == self)
        v:retain()
        v:removeSelf():addTo(self._hidden)
        v:release()
    end
    self:_updatePos()
end

function M:unfold()
    if not self._fold then
        return
    end
    self._fold = false
    for _, v in self._children:iter() do
        assert(v:getParent() == self._hidden)
        v:retain()
        v:removeSelf():addTo(self)
        v:release()
    end
    self:_updatePos()
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
    self.selectBg:setVisible(true)
    self.lb:setTextColor(self._selectTextColor)
    self:_onSelect()
    --if self:getView() then
    --    self:getView():setCurrent(self)
    --end
end

function M:unselect()
    if not self._select then
        return
    end
    self._select = false
    self.selectBg:setVisible(false)
    self.lb:setTextColor(self._unselectTextColor)
    self:_onUnselect()
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

---@return ui.TreeNode
function M:getParentNode()
    if self:isRoot() then
        return
    end
    return self._parent
end

function M:_setParentNode(node)
    assert(node and not self._parent)
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

function M:getCurrentHeight()
    local h = self:getContentSize().y
    if self._fold then
        return h
    else
        for i, v in self._children:iter() do
            h = h + v:getCurrentHeight()
        end
        return h
    end
end

function M:updatePosition(y_base)
    --Print(string.format('set pos %d, %d', self._level * 20, y_base))
    if self:isRoot() then
        self:setPosition(cc.p(0, y_base))
    else
        self:setPosition(cc.p(20, y_base))
    end
    if not self._fold then
        local y = 0 -- self:getContentSize().y
        for _, v in self._children:iter() do
            v:updatePosition(y)
            y = y - v:getCurrentHeight()
        end
    end
    --self.lb:setString(string.format('level=%d', self._level))
end

function M:_updatePos()
    local view = self:getView()
    if view then
        view:updatePosition()
    end
end

---@return ui.TreeView
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

---@return ui.TreeNode
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

function M:isRoot()
    return self._isroot
end

function M:isLeaf()
    return self:getChildrenCount() == 0
end

function M:getTreePrev()
    if self:isRoot() then
        return
    end
    local p = self:getParentNode()
    if p and self:getIndex() >= 2 then
        return p:getChildAt(self:getIndex() - 1):getLastDescendant(true)
    end
    return p
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
    p._children:erase_at(idx - 1)
    p._children:insert_at(idx, prev)
    p:_updateChildrenIndex()
    p:_updatePos()
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
    p._children:erase_at(idx + 1)
    p._children:insert_at(idx, next)
    p:_updateChildrenIndex()
    p:_updatePos()
end

return M
