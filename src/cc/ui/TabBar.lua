---@class ui.TabBar:cc.Node
local M = class('TabBar', function()
    return cc.Node:create()
end)

local _sptag = 1

function M:ctor(fontsize)
    self._fontsize = fontsize or 12
    self:setAnchorPoint(cc.p(0, 1))
    ---@type ccui.Button[]
    self.tabs = {}
    ---@type cc.Node[]
    self.contents = {}
    self._tabpos = 0
    self._tabh = 19
    self._active = -1
end

function M:addTab(text, content, callback)
    local tab = ccui.Button:create(
            'res/editor/tabbar_normal.png',
            'res/editor/tabbar_normal.png',
            'res/editor/tabbar_normal.png', 0)
    table.insert(self.tabs, tab)
    tab:setAnchorPoint(cc.p(0, 1))
    tab:setZoomScale(0)
    tab:setScale9Enabled(true)
    assert(tab:isScale9Enabled())
    tab:setCapInsets(cc.rect(2, 2, 4, 4))
    local lb = cc.Label:createWithSystemFont(text, 'Arial', self._fontsize)
    lb:setTextColor(cc.c4b(0, 0, 0, 255))
    local width = lb:getContentSize().x + 12
    tab:setContentSize(cc.size(width, self._tabh))
    tab:setTitleLabel(lb)
    lb:setLocalZOrder(2)

    local sp = ccui.Scale9Sprite:create('res/editor/tabbar_active.png')
    sp:setCapInsets(cc.rect(2, 2, 4, 4))
    sp:setContentSize(cc.size(width, self._tabh + 2))
    tab:addProtectedChild(sp, 1, _sptag)

    sp:setAnchorPoint(cc.p(0, 0))
    sp:setPosition(cc.p(0, 0))
    sp:setVisible(false)

    tab:addTo(self)
    tab:setPosition(cc.p(self._tabpos, 2))
    self._tabpos = self._tabpos + width

    assert(iskindof(content, 'cc.Node'))
    table.insert(self.contents, content)
    self:addChild(content)
    content:setAnchorPoint(cc.p(0, 1))
    content:setPosition(cc.p(0, self._tabh))
    local i = #self.tabs
    tab:addClickEventListener(function()
        self:active(i, callback)
    end)
end

function M:active(index, callback)
    if index < 1 or index > #self.tabs then
        return
    end
    if self._active == index then
        return
    end
    self._active = index
    for i, v in ipairs(self.contents) do
        v:setVisible(false)
    end
    for i, v in ipairs(self.tabs) do
        v:getProtectedChildByTag(_sptag):setVisible(false)
        v:getTitleRenderer():setPositionY(self._tabh / 2)
    end
    local content=self.contents[index]
    if content then
        content:setVisible(true)
    end
    local tab = self.tabs[index]
    tab:getProtectedChildByTag(_sptag):setVisible(true)
    tab:getTitleRenderer():setPositionY(self._tabh / 2 + 2)
    if callback then
        callback()
    end
end

return M
