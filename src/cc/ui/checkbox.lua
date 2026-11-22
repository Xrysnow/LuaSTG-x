local M = {}

---@return ccui.CheckBox
function M.createBase(scale, cb)
    local p = 'res/editor/checkbox_'
    local ret = ccui.CheckBox:create(
            p .. 'normal.png',
            p .. 'normal_pressed.png',
            p .. 'active.png',
            p .. 'disabled.png',
            p .. 'active_disabled.png'
    )
    if scale then
        ret:setScale(scale)
    end
    if cb then
        ret:addEventListener(cb)
    end
    return ret
end

---@param checkBox ccui.CheckBox
---@param text string
---@return ccui.Text
function M.addLabel(checkBox, text)
    local lb = ccui.Text:create(text, 'Arial', 14)
    lb:setTouchEnabled(true)
    lb:addTouchEventListener(function(sender, e)
        if e == ccui.TouchEventType.ended then
            checkBox:setSelected(not checkBox:isSelected())
        end
    end)
    lb:setTextColor(cc.BLACK):addTo(checkBox):alignLeft(24):alignVCenter()
    --require('ui.label').fixPosition(lb)
    require('cc.ui.label').fixPosition(lb:getVirtualRenderer())
    return lb
end

return M
