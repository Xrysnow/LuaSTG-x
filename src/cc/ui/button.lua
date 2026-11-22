--
local M = {}
local default_size = cc.size(75, 25)
local font_size = 13
if require('cocos.framework.device').isMobile then
    font_size = 30
end

---@param btn ccui.Button
------@param size size_table
local function set_size(btn, size)
    btn:setContentSize(size)
    require('cc.ui.helper').fixButtonLabel(btn)
end

---@return ccui.Button
function M.BaseButton(size, cb, title)
    local ret = ccui.Button:create(
            'editor/base_button_normal.png',
            'editor/base_button_pressed.png',
            'editor/base_button_disabled.png', 0)
    ret:setScale9Enabled(true)
    ret:setCapInsets(cc.rect(2, 2, 28, 28))
    ret:setAnchorPoint(cc.p(0, 1))
    ret:setTitleColor(cc.c3b(0, 0, 0))
    ret:setTitleFontName('Arial')
    ret:setTitleFontSize(font_size)
    if title then
        ret:setTitleText(title)
    end
    set_size(ret, size or default_size)
    if cb then
        ret:addClickEventListener(cb)
    end
    return ret
end

---@return ccui.Button
function M.Button1(size, cb, title)
    local ret = ccui.Button:create(
            'editor/button1_normal.png',
            'editor/button1_pressed.png',
            'editor/button1_normal.png', 0)
    ret:setScale9Enabled(true)
    ret:setCapInsets(cc.rect(2, 2, 28, 28))
    ret:setAnchorPoint(cc.p(0, 1))
    ret:setTitleColor(cc.c3b(0, 0, 0))
    ret:setTitleFontName('Arial')
    ret:setTitleFontSize(font_size)
    if title then
        ret:setTitleText(title)
    end
    set_size(ret, size or default_size)
    if cb then
        ret:addClickEventListener(cb)
    end
    return ret
end

---@return ccui.Button
function M.ButtonNull(size, cb, title)
    local ret = ccui.Button:create(
            'editor/null.png',
            'editor/null.png',
            'editor/null.png', 0)
    ret:setScale9Enabled(true)
    ret:setCapInsets(cc.rect(2, 2, 4, 4))
    ret:setAnchorPoint(cc.p(0, 1))
    ret:setTitleFontSize(font_size)
    if title then
        ret:setTitleText(title)
    end
    set_size(ret, size or default_size)
    if cb then
        ret:addClickEventListener(cb)
    end
    return ret
end

return M
