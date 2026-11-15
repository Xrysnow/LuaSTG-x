local base = require('imgui.widgets.Window')

---@class im.StyleSetting:im.Window
local M = class('im.StyleSetting', base)
local im = imgui

function M:ctor(...)
    base.ctor(self, ...)
    local sel = -1
    self:addChild(function()
        local ret
        local style = im.getStyle()
        --
        im.textUnformatted('Global font scale')
        im.pushID('sliderFloat')
        ret, style.FontScaleMain = im.sliderFloat('', style.FontScaleMain, 0.5, 2)
        im.popID()

        im.sameLine()
        ret = im.button('Reset')
        if ret then
            style.FontScaleMain = 1
        end
        im.separator()
        --
        local new_sel
        im.textUnformatted('Select theme')
        im.pushID('combo')
        ret, new_sel = im.combo('', sel, { 'Dark', 'Classic', 'Light' })
        im.popID()

        if new_sel ~= sel then
            if new_sel == 0 then
                im.styleColorsDark()
            elseif new_sel == 1 then
                im.styleColorsClassic()
            elseif new_sel == 2 then
                im.styleColorsLight()
            end
        end
        sel = new_sel
    end)
end

return M
