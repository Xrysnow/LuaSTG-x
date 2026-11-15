--
local cc = cc
local dir = cc.Director:getInstance()
local fu = cc.FileUtils:getInstance()
local _iniFile = 'imgui.ini'
local _globalSchedule
local _canToggle = true

---@return cc.Layer
function imgui.create()
    local la = imgui.createLayer()
    local base = require('imgui.Widget')
    la._handler = base._handler
    la.addChild = base.addChild
    imgui.draw = function()
        base.handler(la)
    end
    -- toggle with grave key
    local e = cc.EventListenerKeyboard:create()
    e:registerScriptHandler(function(k)
        if k == 123 and _canToggle then
            imgui.setVisible(not imgui.isVisible())
        end
    end, cc.Handler.EVENT_KEYBOARD_PRESSED)
    dir:getEventDispatcher():addEventListenerWithFixedPriority(e, 1)
    -- load
    local iniPath = plus.os == 'android' and (plus.getWritablePath() .. _iniFile) or _iniFile
    local ini = fu:getStringFromFile(iniPath)
    if #ini > 0 then
        imgui.loadIniSettingsFromMemory(ini, #ini)
        print(('read %q from %q'):format(_iniFile, fu:fullPathForFilename(iniPath)))
    else
        print(('read %q failed'):format(_iniFile))
    end
    if not _globalSchedule then
        _globalSchedule = dir:getScheduler():scheduleScriptFunc(function()
            -- auto save ini
            local io = imgui.getIO()
            if io.WantSaveIniSettings then
                local path = plus.getWritablePath() .. _iniFile
                fu:writeStringToFile(imgui.saveIniSettingsToMemory(), path)
                io.WantSaveIniSettings = false
            end
            -- check error
            --if imgui.error then
            --    error(imgui.error)
            --end
        end, 0, false)
    end
    return la
end

local layerName = '::imgui::'
local listener1
local listener2
local localZOrder = 0

---@return cc.Layer
function imgui.on(target)
    local get = imgui.get()
    if get then
        return get
    end
    require('imgui.__init__')
    local la = imgui.create()
    if target then
        target:addChild(la, localZOrder, layerName)
    else
        local sc = dir:getRunningScene()
        sc:addChild(la, localZOrder, layerName)
    end
    if listener1 or listener2 then
        return la
    end
    local e = dir:getEventDispatcher()
    local im = la
    local la_detached = false
    listener1 = e:addCustomEventListener(
            cc.Director.EVENT_BEFORE_SET_NEXT_SCENE, function()
                im = imgui.get()
                if im then
                    im:retain()
                    im:removeSelf()
                    la_detached = true
                end
            end
    )
    listener2 = e:addCustomEventListener(
            cc.Director.EVENT_AFTER_SET_NEXT_SCENE, function()
                if im and la_detached then
                    dir:getRunningScene():addChild(im, localZOrder, layerName)
                    im:release()
                    la_detached = false
                end
            end
    )
    local io = imgui.getIO()
    -- enable docking
    io.ConfigFlags = bit.bor(io.ConfigFlags, imgui.ConfigFlags.DockingEnable)
    local st = imgui.getStyle()
    st.DisplaySafeAreaPadding = cc.p(30, 30)
    st.TabBorderSize = 1
    st.TabRounding = 0
    st.ScrollbarRounding = 0
    return la
end

---@return cc.Layer
function imgui.get()
    local scene = dir:getRunningScene()
    return scene and scene:getChildByName(layerName)
end

function imgui.off()
    dir:getRunningScene():removeChildByName(layerName)
    if _globalSchedule then
        dir:getScheduler():unscheduleScriptEntry(_globalSchedule)
        _globalSchedule = nil
    end
end

function imgui.isVisible()
    local la = imgui.get()
    if la then
        return la:isVisible()
    else
        return false
    end
end

function imgui.setVisible(b)
    b = b and true or false
    local la = imgui.get()
    if la then
        la:setVisible(b)
    end
    setting.imgui_visible = b
end

function imgui.hide()
    imgui.setVisible(false)
end

function imgui.show()
    imgui.setVisible(true)
end
--- set if imgui can be toggled by keyboard
function imgui.setToggleEnable(b)
    _canToggle = b
end

function imgui.clear()
    local la = imgui.get()
    if la then
        la:removeAllChildren()
    end
end

--

local keycode = require('imgui.keycode')
---
---@param key string @key name
function imgui.checkKeyboard(key, ...)
    local args = { key, ... }
    if #args == 0 then
        return false
    end
    local io = imgui.getIO()
    local osx = io.ConfigMacOSXBehaviors
    local shift = io.KeyShift
    local ctrl, alt
    if osx then
        ctrl = io.KeySuper
        alt = io.KeyCtrl
    else
        ctrl = io.KeyCtrl
        alt = io.KeyAlt
    end
    for _, v in ipairs(args) do
        local ty = type(v)
        if ty == 'string' then
            v = string.upper(v)
            if v == 'SHIFT' then
                if not shift then
                    return false
                end
            elseif v == 'CTRL' then
                if not ctrl then
                    return false
                end
            elseif v == 'ALT' then
                if not alt then
                    return false
                end
            else
                v = assert(keycode[v], ('invalid value %q'):format(v))
                if not imgui.isKeyPressed(v) then
                    return false
                end
            end
        elseif ty == 'number' then
            if not imgui.isKeyPressed(v) then
                return false
            end
        else
            error(('invalid param type %q'):format(ty))
        end
    end
    return true
end

--

function imgui.p(x, y)
    return cc.p(x or 0, y or 0)
end

function imgui.vec2(x, y)
    return cc.p(x, y)
end

function imgui.vec4(x, y, z, w)
    return cc.vec4(x, y, z, w)
end
local function clamp(v, lo, hi)
    return math.min(hi, math.max(v, lo))
end
---@return vec4_table
function imgui.color(...)
    local arg = { ... }
    if #arg == 1 then
        arg = arg[1]
        local ty = type(arg)
        if ty == 'number' then
            arg = clamp(arg, 0, 0xFFFFFFFF)
            local b = bit.band(arg, 0xFF) / 0xFF
            local g = bit.band(arg, 0xFF00) / 0xFF00
            local r = bit.band(arg, 0xFF0000) / 0xFF0000
            local a = bit.band(arg, 0xFF000000) / 0xFF000000
            return cc.vec4(r, g, b, a)
        end
        if arg.r then
            local a = 1
            if arg.a then
                a = arg.a / 255
            end
            return cc.vec4(arg.r / 255, arg.g / 255, arg.b / 255, a)
        elseif arg.x then
            return arg
        end
    elseif #arg >= 3 then
        local a = 1
        if arg[4] then
            a = arg[4] / 255
        end
        return cc.vec4(arg[1] / 255, arg[2] / 255, arg[3] / 255, a)
    end
    return cc.vec4(0, 0, 0, 0)
end
---@return number @ABGR
function imgui.color32(...)
    local arg = { ... }
    if #arg == 1 then
        arg = arg[1]
        local ty = type(arg)
        if ty == 'number' then
            arg = clamp(arg, 0, 0xFFFFFFFF)
            -- ARGB -> ABGR
            local b = bit.band(arg, 0xFF)
            local g = bit.band(arg, 0xFF00)
            local r = bit.band(arg, 0xFF0000)
            local a = bit.band(arg, 0xFF000000)
            return a + b * 0x10000 + g + r / 0x10000
        end
        if arg.r then
            local a = 0xFF
            if arg.a then
                a = clamp(arg.a, 0, 0xFF)
            end
            return imgui.color32(arg.r, arg.g, arg.b, arg.a)
        elseif arg.x then
            return imgui.colorConvertFloat4ToU32(arg)
        end
    elseif #arg >= 3 then
        local a = 0xFF000000
        if arg[4] then
            a = clamp(arg[4], 0, 0xFF) * 0x1000000
        end
        local r = clamp(arg[1], 0, 0xFF)
        local g = clamp(arg[2], 0, 0xFF) * 0x100
        local b = clamp(arg[3], 0, 0xFF) * 0x10000
        return a + b + g + r
    end
    return 0
end

function imgui.c4b(r, g, b, a)
    return cc.vec4(r / 255, g / 255, b / 255, a / 255)
end

function imgui.c3b(r, g, b)
    return cc.vec4(r / 255, g / 255, b / 255, 1)
end

function imgui.size(...)
    local arg = { ... }
    if #arg == 1 then
        arg = arg[1]
        if arg.width then
            return cc.p(arg.width, arg.height)
        elseif arg.x then
            return cc.p(arg.x, arg.y)
        end
    elseif #arg >= 2 then
        return cc.p(arg[1], arg[2])
    end
    return cc.p(0, 0)
end

---
---@param imVec4 ImVec4
---@return color4b_table
function imgui.tocc4b(imVec4)
    return {
        r = imVec4.x * 255,
        g = imVec4.y * 255,
        b = imVec4.z * 255,
        a = imVec4.w * 255
    }
end

---
---@param imVec2 ImVec2
---@return size_table
function imgui.toccsize(imVec2)
    return imVec2
end

function imgui.getColorU32(idx, alpha_mul)
    alpha_mul = alpha_mul or 1
    local v = imgui.getStyleColorVec4(idx)
    if v then
        v.w = v.w * imgui.getStyle().Alpha * alpha_mul
        return imgui.colorConvertFloat4ToU32(v)
    else
        return 0
    end
end

function imgui.getStyleColorU32(idx)
    local v = imgui.getStyleColorVec4(idx)
    if v then
        return imgui.colorConvertFloat4ToU32(v)
    else
        return 0
    end
end

function imgui.unpack(t)
    return unpack(t, 1, table.maxn(t))
end

function imgui.configFlagCheck(flag)
    return bit.band(imgui.getIO().ConfigFlags, flag) > 0
end

function imgui.configFlagEnable(flag, ...)
    local io = imgui.getIO()
    for _, v in ipairs({ flag, ... }) do
        io.ConfigFlags = bit.bor(io.ConfigFlags, v)
    end
end

function imgui.configFlagDisable(flag, ...)
    local io = imgui.getIO()
    for _, v in ipairs({ flag, ... }) do
        io.ConfigFlags = bit.band(io.ConfigFlags, bit.bnot(v))
    end
end

function imgui.ImFontConfig.__call()
    return {}
end

local GlyphRanges = {}
imgui.GlyphRanges = GlyphRanges
--- Basic Latin, Extended Latin
GlyphRanges.Default = 0
--- Default + Korean characters
GlyphRanges.Korean = 1
--- Default + Hiragana, Katakana, Half-Width, Selection of 2999 Ideographs
GlyphRanges.Japanese = 2
--- Default + Half-Width + Japanese Hiragana/Katakana + full set of about 21000 CJK Unified Ideographs
GlyphRanges.ChineseFull = 3
--- Default + Half-Width + Japanese Hiragana/Katakana + set of 2500 CJK Unified Ideographs for common simplified Chinese
GlyphRanges.ChineseSimplifiedCommon = 4
--- Default + about 400 Cyrillic characters
GlyphRanges.Cyrillic = 5
--- Default + Thai characters
GlyphRanges.Thai = 6
--- Default + Vietname characters
GlyphRanges.Vietnamese = 7

local GlyphRangesDefault = {
    0x0020, 0x00FF, -- Basic Latin + Latin Supplement
    0,
}
local GlyphRangesKorean = {
    0x0020, 0x00FF, -- Basic Latin + Latin Supplement
    0x3131, 0x3163, -- Korean alphabets
    0xAC00, 0xD79D, -- Korean characters
    0,
}
local GlyphRangesChineseFull = {
    0x0020, 0x00FF, -- Basic Latin + Latin Supplement
    0x2000, 0x206F, -- General Punctuation
    0x3000, 0x30FF, -- CJK Symbols and Punctuations, Hiragana, Katakana
    0x31F0, 0x31FF, -- Katakana Phonetic Extensions
    0xFF00, 0xFFEF, -- Half-width characters
    0x4e00, 0x9FAF, -- CJK Ideograms
    0,
}
local GlyphRangesCyrillic = {
    0x0020, 0x00FF, -- Basic Latin + Latin Supplement
    0x0400, 0x052F, -- Cyrillic + Cyrillic Supplement
    0x2DE0, 0x2DFF, -- Cyrillic Extended-A
    0xA640, 0xA69F, -- Cyrillic Extended-B
    0,
}
local GlyphRangesThai = {
    0x0020, 0x00FF, -- Basic Latin
    0x2010, 0x205E, -- Punctuations
    0x0E00, 0x0E7F, -- Thai
    0,
}
local GlyphRangesVietnamese = {
    0x0020, 0x00FF, -- Basic Latin
    0x0102, 0x0103,
    0x0110, 0x0111,
    0x0128, 0x0129,
    0x0168, 0x0169,
    0x01A0, 0x01A1,
    0x01AF, 0x01B0,
    0x1EA0, 0x1EF9,
    0,
}
