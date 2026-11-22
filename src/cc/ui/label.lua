--
local M = {}
local font_size = 14
if require('cocos.framework.device').isMobile then
    font_size = 30
end

local function set_align(label, hAlign, vAlign)
    if hAlign then
        hAlign = string.capitalize(hAlign)
        if vAlign then
            vAlign = string.capitalize(vAlign)
            if hAlign == vAlign then
                vAlign = ''
            end
        else
            if hAlign == 'Center' then
                vAlign = ''
            else
                vAlign = 'Center'
            end
        end
        local method = label['align' .. hAlign .. vAlign]
        if method then
            method()
        end
    end
end

---@return cc.Label
function M.create(str, fontSize)
    local lb = cc.Label:createWithSystemFont(str, 'Arial', fontSize or font_size)
    lb:setTextColor(cc.BLACK)
    lb:arrangeLeftCenter()
    return lb
end

---
---@param str string
---@param fontSize number @optional
---@param hAlign string @optional 'left'/'center'/'right'
---@param vAlign string @optional 'top'/'center'/'bottom'
---@return cc.Label
function M.TTF(str, fontSize, hAlign, vAlign)
    local lb = cc.Label:createWithTTF(str, 'font/WenQuanYiMicroHeiMono.ttf', fontSize or font_size)
    set_align(lb, hAlign, vAlign)
    return lb
end

---
---@param label cc.Label
---@param maxWidth number
function M.clampWidth(label, maxWidth)
    local sz = label:getContentSize()
    local w, _ = sz.x, sz.y
    if w <= maxWidth then
        return
    end
    label:setLineBreakWithoutSpace(true)
    label:setOverflow(cc.LabelOverflow.RESIZE_HEIGHT)
    label:setMaxLineWidth(maxWidth)
end

---
---@param label cc.Label
---@param size size_table
---@return ccui.ScrollView
function M.toScroll(label, size)
    M.clampWidth(label, size.width)
    local sz = label:getContentSize()
    local scr = ccui.ScrollView:create()
    scr:setContentSize(size)
    scr:addChild(label)
    label:arrangeLeftBottom()
    scr:setInnerContainerSize(cc.size(size.width, sz.y))
    return scr
end

--- fix position to make label clear
---@param label cc.Label
---@return cc.Label
function M.fixPosition(label)
    local sz = label:getContentSize()
    local ap = label:getAnchorPoint()
    local position = label:getPosition()
    local x, y = position.x, position.y
    local left = x - sz.x * ap.x
    local buttom = y - sz.y * ap.y
    label:setPositionX(x - left % 1)
    label:setPositionY(y - buttom % 1)
    return label
end

return M
