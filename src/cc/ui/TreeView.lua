---@class ui.TreeView:ccui.ScrollView
local M = class('ui.TreeView', ccui.ScrollView)

function M:ctor()
    self:setLayoutType(ccui.LayoutType.VERTICAL)
    self:setAnchorPoint(cc.p(0, 0))
    self:getInnerContainer():setAnchorPoint(cc.p(0, 0))
    self:getInnerContainer():setIgnoreAnchorPointForPosition(false)
    self:setBounceEnabled(false)
    self:setBackGroundColorType(1):setBackGroundColor(cc.c3b(255, 255, 255))
    self:setIgnoreAnchorPointForPosition(false)
    self._level = -1
    self._isview = true
end

function M:_setRoot(node)
    --Print('set root')
    assert(not self.root)
    ---@type ui.TreeNode
    self.root = node
    self.root._isroot = true
    self.root:_setParentNode(self)
    self.root:addTo(self)
    local sz = self:getContentSize()
    self:setInnerContainerSize(sz)
    self:setInnerContainerPosition(cc.p(0, 0))
    self.root:updatePosition(sz.y)
end

function M:setCurrent(node)
    if self.current then
        self.current:unselect()
    end
    self.current = node
end

function M:getCurrent()
    return self.current
end

function M:updatePosition()
    --Print('---------------')
    local in_pos = self:getInnerContainerPosition()
    local in_sz = self:getInnerContainerSize()
    local sz = self:getContentSize()
    local l1, l2, l3
    if sz.y >= in_sz.y then
        l1, l3 = 0, 0
        l2 = in_sz.y
    else
        l1 = -in_pos.y
        l2 = sz.y
        l3 = in_sz.y - l1 - l2
    end
    assert(l1 >= 0 and l2 >= 0 and l3 >= 0, string.format('got %.1f,%.1f,%.1f', l1, l2, l3))
    --Print(string.format('got %.1f,%.1f,%.1f', l1, l2, l3))

    local target_y, pos_y
    local h = self.root:getCurrentHeight()
    local dh = h - in_sz.y

    if h <= sz.y then
        target_y = sz.y
        pos_y = 0
    else
        target_y = h
        if dh < 0 then
            if l3 == 0 then
                pos_y = sz.y - h
            else
                local l_ = l1 + l2 + dh
                if l_ < sz.y then
                    pos_y = 0
                else
                    pos_y = sz.y - l_
                end
            end
        else
            --if l3 == 0 then
            --    pos_y = sz.y - h
            --else
            --    pos_y = in_pos.y - dh
            --end
            pos_y = in_pos.y - dh
        end
    end

    --Print(string.format('h=%d, posy=%d', h, pos_y))
    --TODO: inner size
    self:setInnerContainerSize(cc.size(sz.x, h))
    self:setInnerContainerPosition(cc.p(0, pos_y))
    self.root:updatePosition(target_y)
end

function M:setContentSize(size)
    self.super.setContentSize(self, size)
    if self.root then
        self:updatePosition()
    end
    return self
end

return M
