--
local M = {}

---@param size size_table
---@param color color3b_table
---@return ccui.RadioButton
function M.create(size, color)
    local ret = ccui.RadioButton:create(
            'ui/RadioButton/white_uncheck.png',
            'ui/RadioButton/white_check.png')
    ret:setColor(color or cc.BLACK)
    if size then
        --ret:setContentSize(size)
        local sz = ret:getContentSize()
        ret:setScale(size.width / sz.x, size.height / sz.y)
    end
    ret:setZoomScale(0)
    return ret
end

return M
