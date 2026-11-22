---@class button.toggle:ccui.Button
local M = class('button.toggle', function(...)
    return ccui.Button:create(...)
end)

function M:ctor()
    self.pressed = self:getRendererClicked()
    self.pressed:setVisible(false)
    self:addTouchEventListener(function(sender, e)
        if e == ccui.TouchEventType.began then
            self:onTouchBegan(sender, e)
            return true
        elseif e == ccui.TouchEventType.moved then
            self:onTouchMoved(sender, e)
        elseif e == ccui.TouchEventType.ended then
            self:onTouchEnded(sender, e)
        end
    end)
    self.clicked = false
    self:addClickEventListener(function()
        self.clicked = not self.clicked
        self.pressed:setVisible(self.clicked)
        self:onClick()
    end)
    self._clickEvent = {}
end

function M:setClicked(b)
    self.clicked = b
    self.pressed:setVisible(self.clicked)
    if b then
        self:onClick()
    end
end

function M:onTouchBegan(sender, e)
end

function M:onTouchMoved(sender, e)
end

function M:onTouchEnded(sender, e)
end

function M:onClick()
    for i, v in ipairs(self._clickEvent) do
        v()
    end
end

function M:addClickEvent(cb)
    assert(type(cb) == 'function')
    table.insert(self._clickEvent, cb)
end

function M:clearClickEvent(cb)
    self._clickEvent = {}
end

function M:createBase(size, text, textcolor, pos)
    local ret = self:create(
            'res/editor/base_button_normal.png',
            'res/editor/base_button_pressed.png',
            'res/editor/base_button_disabled.png',
            0)
    ret:setScale9Enabled(true)
    ret:setCapInsets(cc.rect(1, 1, 30, 30))
    ret:setContentSize(size)
    ret:setAnchorPoint(cc.p(0, 1))
    ret:setPosition(pos or cc.p(0, 0))
    ret:setTitleText(text or '')
    ret:setTitleColor(textcolor or cc.c3b(0, 0, 0))
    return ret
end

return M
