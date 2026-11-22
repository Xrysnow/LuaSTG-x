---@class ui.MessageBox:cc.Node
local M = class('ui.MessageBox', cc.Node)

function M:ctor(title, msg, param)
    param = param or {}

    local dir = cc.Director:getInstance()
    local sc = dir:getRunningScene()
    local glv = dir:getOpenGLView()
    local sz = glv:getDesignResolutionSize()
    local helper = require('cc.ui.helper')
    local size_min = param.minSize
    local size_max = param.maxSize
    if plus.isDesktop() then
        size_min = size_min or cc.size(200 - 24, 40)
        size_max = size_max or cc.size(600 - 24, 300)
    else
        size_min = size_min or cc.size(sz.x / 3, sz.x / 3)
        size_max = size_max or cc.size(sz.x / 2, sz.x / 2)
    end

    self:setContentSize(sz)
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
    --btn:addClickEventListener(function()
    --    Print('click')
    --end)

    local lb = require('cc.ui.label').TTF(msg or 'Massage', param.fontSize)
    lb:setTextColor(cc.BLACK)
    require('cc.ui.label').clampWidth(lb, size_max.width)
    local sz = lb:getContentSize()
    local txt = lb
    if sz.y > size_max.height then
        txt = require('cc.ui.label').toScroll(lb, size_max)
    else
        lb:arrangeLeftBottom()
    end
    sz = txt:getContentSize()

    local la = ccui.Layout:create()
    self._la = la
    local la_sz = cc.size(
            math.max(sz.x, size_min.width) + 24,
            math.max(sz.y, size_min.height) + 22 + 24 + 46)
    la:setContentSize(la_sz)
    la:setBackGroundColorType(1):setBackGroundColor(cc.WHITE)
    la:addTo(self)
    helper.alignCenter(la)

    txt:addTo(la)
    if sz.y < size_min.height then
        txt:setPosition(12, 46 + 12 + (size_min.height - sz.y) / 2)
    else
        txt:setPosition(12, 46 + 12)
    end

    local shadow = require('cc.ui.sprite').FrameShadow(la_sz)
    shadow:addTo(la):setLocalZOrder(-2)
    helper.alignCenter(shadow)

    local la2 = ccui.Layout:create()
    la2:setContentSize(cc.size(la_sz.width, 46))
    la2:setBackGroundColorType(1):setBackGroundColor(cc.c3b(240, 240, 240))
    la2:addTo(la)
    helper.alignInner(la2, 0.5, 0)

    local cap = require('cc.ui.Caption')(title or 'Message', nil, la_sz.width, 22)
    self._cap = cap
    cap:addTo(la)
    helper.alignInner(cap, 0.5, 1)

    local clr = cap:getBackgroundColor()
    local dr = cc.DrawNode:create()
    dr:addTo(la)
    dr:setLineWidth(1)
    dr:drawRect(cc.p(0, 0), cc.p(la_sz.width, la_sz.height), cc.convertColor(clr, '4f'))

    if plus.isMobile() then
        local scale = sz.y / 720
        scale = scale * 1.5
        la:setScale(scale)
    end
end

function M:addButton(title, pos, callback, autoRemove)
    local btn = require('cc.ui.button').Button1()
    btn:setTitleText(title)
    btn:addClickEventListener(function()
        if callback then
            callback()
        end
        if autoRemove then
            self:removeSelf()
        end
    end)
    btn:addTo(self._la):setPosition(pos)
    require('cc.ui.helper').fixButtonLabel(btn)
    return btn
end

function M:setTitle(title)
    self._cap:setTitle(title)
end

function M.OK(title, msg, onConfirm, param)
    local ret = M(title, msg, param)
    local sz = ret._la:getContentSize()
    ret:addButton('OK', cc.p(sz.x - 90, 35), onConfirm, true)
    return ret
end

function M.OK_Cancel(title, msg, onConfirm, onCancel)
    local ret = M(title, msg)
    local sz = ret._la:getContentSize()
    Print(sz.x, sz.y)
    ret:addButton('OK', cc.p(sz.x - 172, 35), onConfirm, true)
    ret:addButton('Cancel', cc.p(sz.x - 90, 35), onCancel, true)
    return ret
end

function M.Yes_Cancel(title, msg, onConfirm, onCancel)
    local ret = M(title, msg)
    local sz = ret._la:getContentSize()
    Print(sz.x, sz.y)
    ret:addButton('Yes', cc.p(sz.x - 172, 35), onConfirm, true)
    ret:addButton('Cancel', cc.p(sz.x - 90, 35), onCancel, true)
    return ret
end

function M.Yes_No_Cancel(title, msg, onConfirm, onReject, onCancel)
    local ret = M(title, msg)
    local sz = ret._la:getContentSize()
    Print(sz.x, sz.y)
    ret:addButton('Yes', cc.p(sz.x - 254, 35), onConfirm, true)
    ret:addButton('No', cc.p(sz.x - 172, 35), onReject, true)
    ret:addButton('Cancel', cc.p(sz.x - 90, 35), onCancel, true)
    return ret
end

return M
