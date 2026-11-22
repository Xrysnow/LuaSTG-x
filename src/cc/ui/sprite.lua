--
local M = {}

---@return ccui.Scale9Sprite
function M.Frame(size, color, scale)
    local ret = ccui.Scale9Sprite:create('ui/frame_white.png')
    ret:setCapInsets(cc.rect(3, 3, 2, 2))
    scale = scale or 1
    if size then
        ret:setContentSize(cc.size(size.width / scale, size.height / scale))
    end
    ret:setScale(scale)
    if color then
        ret:setColor(color)
        if color.a then
            ret:setOpacity(color.a)
        end
    end
    return ret
end

---@param size size_table
---@return ccui.Scale9Sprite
function M.FrameShadow(size)
    local ret = ccui.Scale9Sprite:create('ui/frame_shadow.png')
    ret:setCapInsets(cc.rect(28, 29, 23, 27))
    ret:setContentSize(cc.size(size.width - 2 + 28 * 2, size.height - 2 + 29 * 2))
    return ret
end

---@param size size_table
---@return cc.Sprite
function M.White(size)
    local ret = cc.Sprite:create('dummy.png')
    if size then
        ret:setScale(size.width / 2, size.height / 2)
    end
    return ret
end

return M
