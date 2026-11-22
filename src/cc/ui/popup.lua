local M = {}
local color = require('cc.color')

---@param widget ccui.Widget
---@param color_bg color4b_table
function M.pop(parent, widget, color_bg)
    widget:setAnchorPoint(cc.p(0.5, 0.5))
    widget:setIgnoreAnchorPointForPosition(false)
    local wsz = widget:getContentSize()
    local dir = cc.Director:getInstance()
    local sz = dir:getOpenGLView():getDesignResolutionSize()
    local ly = cc.LayerColor:create(color_bg or cc.c4b(0, 0, 0, 127), sz.x, sz.y)
    ly:setIgnoreAnchorPointForPosition(false)
    ly
            :addTo(widget)
            :setAnchorPoint(cc.p(0.5, 0.5))
            :setPosition(cc.p(wsz.x / 2, wsz.y / 2))
            :setLocalZOrder(-2)
    local mask = require('cc.ui.button').ButtonNull(sz)
    mask:addTo(widget)
    mask:setSwallowTouches(true)
    mask
            :setAnchorPoint(cc.p(0.5, 0.5))
            :setPosition(cc.p(wsz.x / 2, wsz.y / 2))
            :setContentSize(sz)
    mask:setLocalZOrder(-1)
    widget
            :addTo(parent)
            :setAnchorPoint(cc.p(0.5, 0.5))
            :setPosition(cc.p(sz.x / 2, sz.y / 2))
            :setLocalZOrder(100)
end

function M.popConfirm(parent, msg, cb)
    local w = ccui.Layout:create()
    w:setBackGroundColorType(1):setBackGroundColor(cc.c4b(240, 240, 240, 255))
    w:setContentSize(cc.size(200, 160))
    local lb = cc.Label:createWithSystemFont(msg or 'Confirm?', 'Arial', 20)
    lb:setTextColor(color.Black)
    lb:setHorizontalAlignment(cc.TEXT_ALIGNMENT_CENTER)
    lb:addTo(w):setPosition(100, 120)--:setAnchorPoint(cc.p(0.5,0.5))
    cb = cb or std.fvoid
    local btn1 = require('cc.ui.button').Button1(cc.size(72, 22), function()
        w:removeSelf()
        cb(true)
    end)
    btn1:addTo(w):setPosition(100 - 40 - 36, 50)
    btn1:setTitleFontSize(16):setTitleColor(color.Black)
    btn1:setTitleText('Yes')
    local btn2 = require('cc.ui.button').Button1(cc.size(72, 22), function()
        w:removeSelf()
        cb(false)
    end)
    btn2:addTo(w):setPosition(100 + 40 - 36, 50)
    btn2:setTitleFontSize(16):setTitleColor(color.Black)
    btn2:setTitleText('No')
    M.pop(parent, w)
end

return M
