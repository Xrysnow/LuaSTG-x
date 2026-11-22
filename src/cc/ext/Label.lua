---@type cc.Label
local Label = cc.Label
--cc.TEXT_ALIGNMENT_CENTER = 0x1
--cc.TEXT_ALIGNMENT_LEFT = 0x0
--cc.TEXT_ALIGNMENT_RIGHT = 0x2
--cc.VERTICAL_TEXT_ALIGNMENT_BOTTOM = 0x2
--cc.VERTICAL_TEXT_ALIGNMENT_CENTER = 0x1
--cc.VERTICAL_TEXT_ALIGNMENT_TOP = 0x0

function Label:arrangeLeftTop()
    self:setAlignment(0, 0)
    self:setAnchorPoint(cc.p(0, 1))
    return self
end

function Label:arrangeLeftCenter()
    self:setAlignment(0, 1)
    self:setAnchorPoint(cc.p(0, 0.5))
    return self
end

function Label:arrangeLeftBottom()
    self:setAlignment(0, 2)
    self:setAnchorPoint(cc.p(0, 0))
    return self
end

function Label:arrangeCenterTop()
    self:setAlignment(1, 0)
    self:setAnchorPoint(cc.p(0.5, 1))
    return self
end

function Label:arrangeCenter()
    self:setAlignment(1, 1)
    self:setAnchorPoint(cc.p(0.5, 0.5))
    return self
end

function Label:arrangeCenterBottom()
    self:setAlignment(1, 2)
    self:setAnchorPoint(cc.p(0.5, 0))
    return self
end

function Label:arrangeRightTop()
    self:setAlignment(2, 0)
    self:setAnchorPoint(cc.p(1, 1))
    return self
end

function Label:arrangeRightCenter()
    self:setAlignment(2, 1)
    self:setAnchorPoint(cc.p(1, 0.5))
    return self
end

function Label:arrangeRightBottom()
    self:setAlignment(2, 2)
    self:setAnchorPoint(cc.p(1, 0))
    return self
end
