--
local M = {}

---@param node cc.Node
function M.alignCenter(node)
    M.alignInner(node, 0.5, 0.5)
end

---@param node cc.Node
function M.alignHCenter(node)
    M.alignInnerX(node, 0.5)
end

---@param node cc.Node
function M.alignVCenter(node)
    M.alignInnerY(node, 0.5)
end

---@param node cc.Node
---@param ratio_x number
---@param ratio_y number
function M.alignInner(node, ratio_x, ratio_y)
    local p = node:getParent()
    if not p then
        return
    end
    local psz = p:getContentSize()
    local sz = node:getContentSize()
    local anc = node:getAnchorPoint()
    local offset = cc.p(sz.x * anc.x, sz.y * anc.y)
    local posx = (psz.x - sz.x) * ratio_x
    local posy = (psz.y - sz.y) * ratio_y
    local pos = cc.pAdd(cc.p(posx, posy), offset)
    node:setPosition(pos)
end

---@param node cc.Node
---@param ratio_x number
function M.alignInnerX(node, ratio_x)
    local p = node:getParent()
    if not p then
        return
    end
    local psz = p:getContentSize()
    local sz = node:getContentSize()
    local anc = node:getAnchorPoint()
    local posx = (psz.x - sz.x) * ratio_x
    posx = posx + sz.x * anc.x
    node:setPositionX(posx)
end

---@param node cc.Node
---@param ratio_y number
function M.alignInnerY(node, ratio_y)
    local p = node:getParent()
    if not p then
        return
    end
    local psz = p:getContentSize()
    local sz = node:getContentSize()
    local anc = node:getAnchorPoint()
    local posy = (psz.y - sz.y) * ratio_y
    posy = posy + sz.y * anc.y
    node:setPositionY(posy)
end

---@param btn ccui.Button
function M.fixButtonLabel(btn)
    local lb = btn:getTitleRenderer()
    if lb then
        require('cc.ui.label').fixPosition(lb)
    end
end

---@param node cc.Node
function M.addFrame(node, color, width)
    M.makeFrame(node, color, width):addTo(node)
end

---@param node cc.Node
function M.makeFrame(node, color, width)
    width = width or 1
    color = color or cc.BLACK
    color = cc.convertColor(color, '4f')
    local dr = cc.DrawNode:create()
    dr:setLineWidth(width)
    --local sz = node:getContentSize()
    --local w, h = sz.x or sz.width, sz.y or sz.height
    --TODO: fix
    width = width / node:getScale()
    --dr:drawLine(cc.p(-width, -width / 2), cc.p(w + width, -width / 2), color)
    --dr:drawLine(cc.p(-width, h + width / 2), cc.p(w + width, h + width / 2), color)
    --dr:drawLine(cc.p(-width / 2, -width), cc.p(-width / 2, h + width), color)
    --dr:drawLine(cc.p(w + width / 2, -width), cc.p(w + width / 2, h + width), color)
    dr.setContentSize = function(this, size)
        dr:clear()
        local sz = size
        local w, h = sz.x or sz.width, sz.y or sz.height
        dr:drawLine(cc.p(-width, -width / 2), cc.p(w + width, -width / 2), color)
        dr:drawLine(cc.p(-width, h + width / 2), cc.p(w + width, h + width / 2), color)
        dr:drawLine(cc.p(-width / 2, -width), cc.p(-width / 2, h + width), color)
        dr:drawLine(cc.p(w + width / 2, -width), cc.p(w + width / 2, h + width), color)
    end
    dr:setContentSize(node:getContentSize())
    return dr
end

---@param widget ccui.Widget
function M.makeDraggable(widget, limited)
    local _last_touch
    local glv = cc.Director:getInstance():getOpenGLView()
    widget:setTouchEnabled(true)
    widget:addTouchEventListener(function(sender, e)
        if e == ccui.TouchEventType.moved then
            local p = widget:getTouchMovePosition()
            if _last_touch then
                local delta = cc.pSub(p, _last_touch)
                local position = widget:getPosition()
                local x, y = position.x, position.y
                local xx, yy = x + delta.x, y + delta.y
                if limited then
                    local sz = glv:getDesignResolutionSize()
                    local size = widget:getContentSize()
                    xx = math.max(0, math.min(xx, sz.x - size.x))
                    yy = math.max(0, math.min(yy, sz.y - size.y))
                end
                widget:setPosition(cc.p(xx, yy))
            end
            _last_touch = p
        else
            _last_touch = nil
        end
    end)
end

local function _constrain_tonumber(str)
    local ret
    if str:sub(-2) == 'px' then
        ret = tonumber(str:sub(1, -3))
        if ret then
            ret = math.max(ret, 2)
        end
    elseif str:sub(-1) == '%' then
        local n = tonumber(str:sub(1, -2))
        if n then
            ret = math.clamp(n / 100, 0, 1)
        end
    else
        ret = tonumber(str)
    end
    return ret
end

function M.parseConstrainParam(param)
    local ret = table.clone(param)
    if type(ret[1]) == 'string' then
        ret[1] = _constrain_tonumber(ret[1])
    end
    ret.preffered = ret[1]
    for _, k in ipairs({ 'min', 'max' }) do
        if type(ret[k]) == 'string' then
            ret[k] = _constrain_tonumber(ret[k])
        end
        if ret[k] and ret[k] < 0 then
            ret[k] = 0
        end
    end
    return ret
end

function M.solveConstrain(sumMax, pref1, min1, max1, pref2, min2, max2)
    if pref1 and pref2 then
        local sum = pref1 + pref2
        if sum <= sumMax then
            return pref1, pref2
        end
        if min1 + min2 >= sumMax then
            return min1, min2
        end
        local d1 = pref1 - min1
        local d2 = pref2 - min2
        if d1 == 0 and d2 == 0 then
            d1 = 1e-3
        end
        return math.solveLiner(d2, -d1, min1 * pref2 - pref1 * min2, 1, 1, sumMax)
    elseif pref1 then
        if pref1 + max2 <= sumMax then
            return pref1, max2
        end
        if pref1 + min2 >= sumMax then
            return math.max(min1, sumMax - min2), min2
        end
        return pref1, sumMax - pref1
    elseif pref2 then
        if pref2 + max1 <= sumMax then
            return max1, pref2
        end
        if pref2 + min1 >= sumMax then
            return min1, math.max(min2, sumMax - min1)
        end
        return sumMax - pref2, pref2
    else
        if min1 + min2 >= sumMax then
            return min1, min2
        end
        if max1 + max2 <= sumMax then
            return max1, max2
        end
        local d1 = max1 - min1
        local d2 = min1 - min2
        if d1 == 0 and d2 == 0 then
            d1 = 1e-3
        end
        return math.solveLiner(d2, -d1, min1 * max2 - max1 * min2, 1, 1, sumMax)
    end
end

return M
