---@class ui.ListBox:ccui.ScrollView
local M = class('ui.ListBox', ccui.ScrollView)

function M:ctor(size, item_h)
    self.size = size or cc.size(192, 256)
    self.item_size = cc.size(self.size.width, item_h or 16)
    self:setContentSize(self.size)
    self:setBackGroundColorType(1)--:setBackGroundColor(cc.c3b(255, 200, 200))
    ---@type ccui.Button[]
    self._children = {}

    local hinter = require('cc.ui.sprite').White(self.item_size)
    hinter:addTo(self):setVisible(false):alignHCenter()
    hinter:setColor(cc.BLUE)
    self._hinter = hinter
end

function M:addItem(text)
    local idx = self:getItemCount() + 1
    local btn = require('cc.ui.button').ButtonNull(self.item_size, function()
        self:_select(idx)
    end)
    btn:addTo(self)
    table.insert(self._children, btn)
    local lb = require('cc.ui.label').create(text, 13)
    lb:addTo(btn):alignVCenter():alignLeft(6)
    btn.label = lb
    self:_updateLayout()
    if idx == 1 then
        self:_select(1)
    end
end

function M:getItemCount()
    return #self._children
end

function M:getIndex()
    return self._sel
end

function M:getString()
    if self._sel and self._children[self._sel] then
        return self._children[self._sel].label:getString()
    end
end

function M:reset()
    self._sel = nil
    for _, v in ipairs(self._children) do
        v:removeSelf()
    end
    self._hinter:setVisible(false)
    self:_updateLayout()
end

function M:setOnSelect(cb)
    self._onselect = cb
end

function M:selectString(str)
    for i, v in ipairs(self._children) do
        if v.label:getString() == str then
            self:_select(i)
            return
        end
    end
end

function M:_select(idx)
    if self._sel and self._children[self._sel] then
        self._children[self._sel].label:setTextColor(cc.BLACK)
    end
    local btn = self._children[idx]
    assert(btn and btn.label)
    btn.label:setTextColor(cc.WHITE)
    self._hinter:setVisible(true):alignTop((idx - 1) * self.item_size.height)
    self._sel = idx

    if self._onselect then
        self:_onselect()
    end
end

function M:_updateLayout()
    self:setInnerContainerSize(cc.size(
            self.size.width,
            math.max(self.item_size.height * self:getItemCount(), self.size.height)
    ))
    for i, v in ipairs(self._children) do
        v:alignLeft(0):alignTop((i - 1) * self.item_size.height)
    end
    if self._sel then
        self._hinter:alignTop((self._sel - 1) * self.item_size.height)
    end
end

return M
