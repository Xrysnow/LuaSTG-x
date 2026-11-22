--
local M = {}
local im = imgui
local wi = require('imgui.Widget')

function M.checkExp(str)
    str = '_=\n' .. str
    local f, msg = loadstring(str, '')
    if not f then
        msg = msg:gsub([[%[string ""%]:2: ]], '')
        msg = msg:gsub([[%[string ""%]:]], '')
        return false, msg
    end
    return true
end

function M.splitParam(s)
    if string.match(s, "^[%s]*$") then
        return {}
    end
    local pos = { 0 }
    local ret = {}
    local b1 = 0
    local b2 = 0
    for i = 1, #s do
        local c = string.byte(s, i)
        if b1 == 0 and b2 == 0 and c == 44 then
            table.insert(pos, i)
        elseif c == 40 then
            b1 = b1 + 1
        elseif c == 41 then
            b1 = b1 - 1
        elseif c == 123 then
            b2 = b2 + 1
        elseif c == 125 then
            b2 = b2 - 1
        end
    end
    table.insert(pos, #s + 1)
    for i = 1, #pos - 1 do
        local str = s:sub(pos[i] + 1, pos[i + 1] - 1)
        str = string.trim(str)
        table.insert(ret, str)
    end
    return ret
end

local _keyword = {
    'and', 'break', 'do', 'else', 'elseif', 'end', 'false', 'for',
    'function', 'if', 'in', 'local', 'nil', 'not', 'or', 'repeat',
    'return', 'then', 'true', 'until', 'while', 'goto'
}
for k, v in pairs(_keyword) do
    _keyword[v] = true
end
local punctuation = [[%!%"%#%$%%%&%'%(%)%*%+%,%-%.%/%:%;%<%=%>%?%@%[%\%]%^%`%{%|%}%~]]

function M.checkIdentifier(s)
    s = string.trim(s)
    if _keyword[s] then
        return false
    end
    if s:match('^[0-9]') then
        return false
    end
    if s:match('[ \t\n\r\v\f]') then
        return false
    end
    if s:match('[' .. punctuation .. ']') then
        return false
    end
    return true
end

---@param sp cc.Sprite
function M.createButton(sp, padding, scale)
    padding = padding or 4
    scale = scale or 1
    padding = padding * scale
    local sz = sp:getContentSize()
    sz.x = sz.x * scale
    sz.y = sz.y * scale
    sp:setScale(scale)

    local btn = require('imgui.widgets.ImageButton')(sp)
    btn:setContentSize(sz):setFramePadding(padding)

    local node = cc.Node:create()
    local delta = padding * 2 - 2
    node:setContentSize(cc.size(sz.x + delta, sz.y + delta))
    local tint = im.vec4(1, 1, 1, 1)
    local btn_disable = wi.Widget(function()
        im.ccNode(node, tint, im.getStyleColorVec4(im.Col.Border))
    end)
    btn_disable:setVisible(false)
    node:addTo(btn_disable):setVisible(false)
    sp:addTo(node):setPosition(sz.x / 2 + padding - 1, sz.y / 2 + padding - 1)
    local ProgramType = require('cc.enum').ProgramType
    sp:setProgramState(ProgramType.GRAY_SCALE)
    sp:setBlendFunc({ src = ccb.BlendFactor.SRC_ALPHA, dst = ccb.BlendFactor.ONE_MINUS_SRC_ALPHA })

    return btn, btn_disable
end

function M.createTextButton(str, padding, cb, color)
    local vars = {
        [im.StyleVar.FramePadding] = padding,
    }
    local colors1 = {
        [im.Col.Text] = color,
    }
    local style1 = wi.style(colors1, vars)
    local btn = wi.Button(str)
    btn:addTo(style1)
    if cb then
        btn:setOnClick(cb)
    end

    local colors2 = {
        [im.Col.Button] = im.vec4(0, 0, 0, 0),
        [im.Col.ButtonActive] = im.vec4(0, 0, 0, 0),
        [im.Col.ButtonHovered] = im.vec4(0, 0, 0, 0),
        [im.Col.Text] = function()
            return im.getStyleColorVec4(im.Col.TextDisabled)
        end,
    }
    local style2 = wi.style(colors2, vars)
    style2:setVisible(false)
    local btn2 = wi.Button(str)
    btn2:addTo(style2)

    return style1, style2
end

local PaletteIndex = im.ColorTextEdit.PaletteIndex
-- ABGR
local darkPalette = {
    0xFFC8C8C8, -- Default,
    0xFFD69A56, -- Keyword,
    0xFFA8CEB5, -- Number,
    0xFF859DD6, -- String,
    0xFF3E54CC, -- CharLiteral,
    0xFFC8C8C8, -- Punctuation,
    0xFF808040, -- Preprocessor,
    0xFFC8C8C8, -- Identifier,
    0xFF8B8B00, -- KnownIdentifier,
    0xFFFF3D48, -- PreprocIdentifier,
    0xFF4AA657, -- Comment,
    0xFF559762, -- MultiLineComment,
    0xFF000000, -- Background,
    0xFFBBBBBB, -- Cursor,
    0x80a0a0a0, -- Selection,
    0x80ff2000, -- ErrorMarker,
    0xFF5AC2C2, -- Breakpoint,
    0xFF858585, -- LineNumber,
    0x32a0a0a0, -- CurrentLineFill,
    0x40a0a0a0, -- CurrentLineFillInactive,
    0x40a0a0a0, -- CurrentLineEdge,
}
local lightPalette = table.clone(darkPalette)
lightPalette[PaletteIndex.Default + 1] = 0xFF404040
lightPalette[PaletteIndex.Background + 1] = 0xFFFFFFFF
lightPalette[PaletteIndex.Cursor + 1] = 0xFF404040
lightPalette[PaletteIndex.Punctuation + 1] = 0xFF404040
lightPalette[PaletteIndex.Identifier + 1] = 0xFF404040
lightPalette[PaletteIndex.Selection + 1] = 0x80606060
lightPalette[PaletteIndex.Breakpoint + 1] = 0xFF28CAFF

function M.getCodeDarkPalette()
    return darkPalette
end
function M.getCodeLightPalette()
    return lightPalette
end

local luaKeywords = {
    "and", "break", "do", "else", "elseif", "end", "false", "for", "function", "if", "in", "local", "nil", "not", "or", "repeat", "return", "then", "true", "until", "while", "goto"
}
function M.getLuaKeywords()
    return luaKeywords
end
local luaBuiltin = {
    -- function
    "assert", "collectgarbage", "dofile", "error", "getmetatable", "ipairs", "load", "loadfile", "next", "pairs", "pcall", "print", "rawequal", "rawget", "rawset", "require", "select", "setmetatable", "tonumber", "tostring", "type", "xpcall",
    -- constants
    "_G", "_VERSION",
    -- library
    "coroutine", "package", "utf8", "string", "table", "math", "io", "os", "debug", "bit", "ffi", "jit",
}
function M.getLuaBuiltin()
    return luaBuiltin
end
local luaToken = {
    { "\\.\\s*([a-zA-Z_][a-zA-Z0-9_]*)\\s*\\(", PaletteIndex.Breakpoint },
    { "\\.\\s*([a-zA-Z_][a-zA-Z0-9_]*)", PaletteIndex.CharLiteral },
    { "\\:\\s*([a-zA-Z_][a-zA-Z0-9_]*)", PaletteIndex.Identifier },
    { "L?\\\"(\\\\.|[^\\\"])*\\\"", PaletteIndex.String },
    { "\\\'[^\\\']*\\\'", PaletteIndex.String },
    { "0[xX][0-9a-fA-F]+[uU]?[lL]?[lL]?", PaletteIndex.Number },
    { "[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)([eE][+-]?[0-9]+)?[fF]?", PaletteIndex.Number },
    { "[+-]?[0-9]+[Uu]?[lL]?[lL]?", PaletteIndex.Number },
}
for i, v in ipairs(luaBuiltin) do
    local k = ([[[^\B\.\:]?\s*(%s)\b]]):format(v)
    table.insert(luaToken, { k, PaletteIndex.KnownIdentifier })
end
table.insert(luaToken, { "[a-zA-Z_][a-zA-Z0-9_]*", PaletteIndex.Identifier })
table.insert(luaToken, { "[\\[\\]\\{\\}\\!\\%\\^\\&\\*\\(\\)\\-\\+\\=\\~\\|\\<\\>\\?\\/\\;\\,\\.\\:]",
                         PaletteIndex.Punctuation })
function M.getLuaTokenRegex()
    return luaToken
end

return M
