local base = require('xe.input.Base')
---@class xe.input.Code:xe.input.Base
local M = class('xe.input.Code', base)
local im = imgui
local wi = require('imgui.Widget')
local _id = 'Edit Code'
local PaletteIndex = im.ColorTextEdit.PaletteIndex

function M:ctor(node, idx, param)
    base.ctor(self, node, idx, 'code')
    param = param or {}

    local value = self:getEditValue()
    if value == '' then
        value = node:getAttrValue(idx) or ''
    end
    self._lang = 'txt'

    local input = im.ColorTextEdit()
    self._input = input

    input:setText(value)
    input:setPaletteLight()
    input:setShowWhitespaces(false)
    input:setAutoTooltip(false)
    --
    self:_applyTheme()
    --
    if param.lang == 'lua' then
        self._lang = 'lua'
        --input:setLanguageLua()
        local u = require('xe.util')
        local keywords = table.clone(u.getLuaKeywords())
        table.insert(keywords, 'self')
        input:setLanguageDefinition(
                'Lua', keywords, {}, {}, u.getLuaTokenRegex(), '--[[', ']]', '--')
        input:addLanguageIdentifier(require('xe.input.code_lua_doc'))
    end
    --
    input:addTo(self)

    self._title = 'Edit code'

    local icon = require('xe.ifont').Edit
    local btn = wi.Button(icon, function()
        self:_applyTheme()
        im.openPopup(_id)
        require('xe.main').backupKeyEvent()
        require('xe.main').setKeyEventEnabled(false)
    end)
    btn:addTo(self)

    local editor = wi.Widget(std.bind(self._render, self))
    editor:addTo(self)
    self._open = true
end

function M:_applyTheme()
    local theme = setting.xe.code_editor_theme
    local input = self._input
    if theme == 'Light' then
        input:setPalette(require('xe.util').getCodeLightPalette())
    elseif theme == 'Dark' then
        input:setPalette(require('xe.util').getCodeDarkPalette())
    elseif theme == 'Retro blue' then
        input:setPaletteRetroBlue()
    end
end

function M:_checkLua()
    return loadstring(self:getValue(), '')
end

function M:_render()
    im.setNextWindowSize(im.vec2(300, 350), im.Cond.Once)
    local ret = { im.beginPopupModal(_id, true, im.WindowFlags.MenuBar) }
    if self._open and not ret[2] then
        -- closed
        self:submit()
        require('xe.main').restoreKeyEvent()
    end
    self._open = ret[2]
    if ret[1] then
        self:_renderMenu()

        if self._lang == 'lua' and self._luaError then
            im.textWrapped(self._luaError)
        end

        local input = self._input
        local cpos = input:getCursorPosition()

        local font_scale = setting.xe.code_editor_font_scale
        local base_font_size = im.getStyle().FontSizeBase
        if font_scale then
            im.pushFont(nil, base_font_size * font_scale / 100)
        end

        --local hh = -im.getFrameHeightWithSpacing()
        local hh = -im.getTextLineHeightWithSpacing()
        local font = require('xe.main'):getInstance()._font_mono
        im.pushFont(font, (font and font.LegacySize or base_font_size) * (font_scale or 100) / 100)
        input:render(self._title, im.vec2(-1, hh), true)
        im.popFont()

        local dec = input:getHoveredDeclaration()
        local word = input:getHoveredWord()
        local idx = input:getHoveredWordIndex()
        if word ~= '' and dec ~= '' and idx == PaletteIndex.KnownIdentifier then
            im.setTooltip(('%s'):format(dec))
        end

        if font_scale then
            im.popFont()
        end

        im.text(('%6d/%6d %6d lines  | %s | %s'):format(
                cpos[1] + 1, cpos[2] + 1, input:getTotalLines(),
                input:isOverwrite() and 'Ovr' or 'Ins',
                self._lang:capitalize()))

        if not input:isReadOnly() then
            if im.checkKeyboard('ctrl', 's') then
                self:submit()
            end
        end

        im.endPopup()
    end
end

function M:_renderMenu()
    local input = self._input
    if im.beginMenuBar() then
        if im.beginMenu('File') then
            if im.menuItem('Save', 'Ctrl+S') then
                self:submit()
            end
            if self._lang == 'lua' then
                if im.menuItem('Check lua code') then
                    local _, msg = self:_checkLua()
                    self._luaError = msg
                end
            end
            im.endMenu()
        end
        if im.beginMenu('View') then
            local show_space = input:isShowingWhitespaces()
            if im.menuItem('Show whitespaces', '', show_space) then
                input:setShowWhitespaces(not show_space)
            end
            local show_short_tab = input:isShowingShortTabGlyphs()
            if im.menuItem('Show short tab', '', show_short_tab) then
                input:setShowShortTabGlyphs(not show_short_tab)
            end
            im.endMenu()
        end
        im.endMenuBar()
    end
end

function M:getValue()
    return self._input:getText()
end

function M:setValue(v)
    self._input:setText(v)
end

return M
