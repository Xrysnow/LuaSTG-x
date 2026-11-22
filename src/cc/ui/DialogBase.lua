---@class ui.DialogBase:ccui.Widget
local M = class('ui.DialogBase', ccui.Widget)

function M:ctor(title, size)
    local dir = cc.Director:getInstance()
    local sc = dir:getRunningScene()
    local glv = dir:getOpenGLView()
    local sz = glv:getDesignResolutionSize()
    local helper = require('cc.ui.helper')

    --self:setContentSize(sz)
    local ch = sc:getChildren()
    if #ch == 2 then
        for i = 1, 2 do
            if getclassname(ch[i]) ~= 'cc.Camera' then
                self:addTo(ch[i])
                break
            end
        end
    else
        --self:addTo(sc)
        error('!!!')
    end
    self:setLocalZOrder(99)

    local btn = require('cc.ui.button').ButtonNull(sz)
    btn:setOpacity(127)
    btn:setSwallowTouches(true)
    btn:setAnchorPoint(cc.p(0, 0))
    btn:addTo(self)
    self._btn = btn
    local glv = cc.Director:getInstance():getOpenGLView()
    self._btn:getEventDispatcher():addCustomEventListener('glview_window_resized', function()
        local dsize = glv:getDesignResolutionSize()
        btn:setContentSize(dsize)
    end)
    --btn:addClickEventListener(function()
    --    Print('click')
    --end)

    local la = ccui.Layout:create()
    self._la = la
    local la_sz = cc.size(
            math.min(sz.x, size.width),
            math.min(sz.y, size.height))
    la:setContentSize(la_sz)
    la:setBackGroundColorType(1):setBackGroundColor(cc.WHITE)
    la:addTo(self)
    helper.alignCenter(la)

    local shadow = require('cc.ui.sprite').FrameShadow(la_sz)
    shadow:addTo(la):setLocalZOrder(-2)
    helper.alignCenter(shadow)

    local cap = require('cc.ui.Caption')(title or 'Dialog', nil, la_sz.width, 22)
    self._cap = cap
    cap:addTo(la)
    helper.alignInner(cap, 0.5, 1)

    local clr = cap:getBackgroundColor()
    local dr = cc.DrawNode:create()
    dr:addTo(la)
    dr:setLineWidth(1)
    dr:drawRect(cc.p(0, 0), cc.p(la_sz.width, la_sz.height), cc.convertColor(clr, '4f'))

    require('cc.ui.helper').makeDraggable(la)
    self:setContentSize(sz)
end

function M:addButton(title, pos, callback, autoClose)
    local btn = require('cc.ui.button').Button1()
    btn:setTitleText(title)
    btn:addClickEventListener(function()
        if callback then
            callback()
        end
        if autoClose then
            self:removeSelf()
        end
    end)
    btn:addTo(self._la)
    if pos then
        btn:setPosition(pos)
    end
    require('cc.ui.helper').fixButtonLabel(btn)
    return btn
end

function M:setTitle(title)
    self._cap:setTitle(title)
end

---@return ccui.Layout
function M:getWidget()
    return self._la
end

function M:setOnConfirm(cb)
    self._confirm = cb
end

function M:setOnCancel(cb)
    self._cancel = cb
end

function M:addConfirmButton(title)
    return self:addButton(title or 'OK', nil, function()
        if self._confirm then
            self:_confirm()
        end
    end, true)
end

function M:addCancelButton(title)
    return self:addButton(title or 'Cancel', nil, function()
        if self._cancel then
            self:_cancel()
        end
    end, true)
end

function M:setContentSize(size)
    --self.super.setContentSize(self, size)
    --self._la:alignCenter()
    --self._btn:setContentSize(size)
    local width, height = size.x or size.width, size.y or size.height
    local position = self._la:getPosition()
    local x, y = position.x, position.y
    local sz = self._la:getContentSize()
    if x + sz.x > width then
        self._la:setPositionX(width - sz.x)
    end
    if y + sz.y > height then
        self._la:setPositionY(height - sz.y)
    end
    return self
end

return M
