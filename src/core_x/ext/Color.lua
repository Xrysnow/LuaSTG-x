---@type lstg.Color
local M = {}

local Color = lstg.Color
local mt = getmetatable(Color())
M = mt[1]

local math = math
local tonumber = tonumber
local tostring = tostring
local string = string

local function to_rad(x)
    return x / 180 * math.pi
end
local function to_deg(x)
    return x / math.pi * 180
end

-- ctor
mt[4] = function(self, s)
    self:parse(s)
end

function M:reverse(rev_alpha)
    local r, g, b, a = self:unpack()
    if rev_alpha then
        self:set(255 - r, 255 - g, 255 - b, 255 - a)
    else
        self:set(255 - r, 255 - g, 255 - b)
    end
    return self
end

function M:gray()
    local r, g, b, _ = self:unpack()
    local gray = r * 0.299 + g * 0.587 + b * 0.114
    return self:set(gray, gray, gray)
end

---@return number,number,number
function M:toYUV()
    local r, g, b, _ = self:unpack()
    local y = 0.299 * r + 0.587 * g + 0.114 * b
    local cb = -0.169 * r - 0.331 * g + 0.499 * b + 128
    local cr = 0.499 * r - 0.418 * g - 0.0813 * b + 128
    return y / 255, cb / 255, cr / 255
end

function M:fromYUV(y, cb, cr)
    y, cb, cr = y * 255, cb * 255, cr * 255
    local r = y + 1.402 * (cr - 128)
    local g = y - 0.344 * (cb - 128) - 0.714 * (cr - 128)
    local b = y + 1.772 * (cb - 128)
    return self:set(r, g, b)
end

local pi_3 = math.pi / 3
local function fromcx(h_, c, x)
    local h = math.floor(h_)
    if h == 0 then
        return c, x, 0
    elseif h == 1 then
        return x, c, 0
    elseif h == 2 then
        return 0, c, x
    elseif h == 3 then
        return 0, x, c
    elseif h == 4 then
        return x, 0, c
    elseif h == 5 then
        return c, 0, x
    else
        return 0, 0, 0
    end
end

local norm = M.unpackFloat

---@return number,number,number
function M:toHSI()
    local r, g, b = norm(self)
    local i = (r + g + b) / 3
    local s = 1 - math.min(r, g, b) / i
    local t1, t2 = r - g, r - b
    local theta = math.acos((t1 + t2) / 2 / math.sqrt(t1 * t1 + t2 * (g - b)))
    local h = theta
    if g < b then
        h = 2 * math.pi - theta
    end
    return to_deg(h), s, i
end

function M:fromHSI(h, s, i)
    h = to_rad(h)
    local h_ = h / pi_3
    local z = 1 - math.abs(h_ % 2 - 1)
    local ch = 3 * i * s / (1 + z)
    local x = ch * z
    local r1, g1, b1 = fromcx(h_, ch, x)
    local m = i * (1 - s)
    return self:setFloat(r1 + m, g1 + m, b1 + m)
end

---@return number,number,number
function M:toHSV()
    local r, g, b = norm(self)
    local max = math.max(r, g, b)
    local min = math.min(r, g, b)
    local h = 0
    local div = max - min
    if min == max then
        h = 0
    elseif max == r then
        h = pi_3 * (g - b) / div
    elseif max == g then
        h = pi_3 * (2 + (b - r) / div)
    elseif max == b then
        h = pi_3 * (4 + (r - g) / div)
    end
    if h < 0 then
        h = h + math.pi * 2
    end
    local s = 0
    if max ~= 0 then
        s = div / max
    end
    local v = max / 255
    return to_deg(h), s, v
end

function M:fromHSV(h, s, v)
    h = to_rad(h)
    local ch = v * s
    local h_ = h / pi_3
    local x = ch * (1 - math.abs(h_ % 2 - 1))
    local r1, g1, b1 = fromcx(h_, ch, x)
    local m = v - ch
    return self:setFloat(r1 + m, g1 + m, b1 + m)
end

---@return number,number,number
function M:toHSL()
    local r, g, b = norm(self)
    local max = math.max(r, g, b)
    local min = math.min(r, g, b)
    local h = 0
    local div = max - min
    if min == max then
        h = 0
    elseif max == r then
        h = pi_3 * (g - b) / div
    elseif max == g then
        h = pi_3 * (2 + (b - r) / div)
    elseif max == b then
        h = pi_3 * (4 + (r - g) / div)
    end
    if h < 0 then
        h = h + math.pi * 2
    end
    local s = 0
    if max ~= 0 and min ~= 1 then
        s = div / (1 - math.abs(max + min - 1))
    end
    local l = (max + min) / 2
    return to_deg(h), s, l
end

function M:fromHSL(h, s, l)
    h = to_rad(h)
    local ch = (1 - math.abs(2 * l - 1)) * s
    local h_ = h / pi_3
    local x = ch * (1 - math.abs(h_ % 2 - 1))
    local r1, g1, b1 = fromcx(h_, ch, x)
    local m = l - ch / 2
    return self:setFloat(r1 + m, g1 + m, b1 + m)
end

function M:setHue(h)
    local _, s, l = self:toHSL()
    self:fromHSL(to_rad(h), s, l)
    return self
end

function M:setSaturation(s)
    local h, _, l = self:toHSL()
    self:fromHSL(h, s, l)
    return self
end

function M:setLightness(l)
    local h, s, _ = self:toHSL()
    self:fromHSL(h, s, l)
    return self
end

local function _toXYZ(v)
    if (v > 0.04045) then
        return math.pow((v + 0.055) / 1.055, 2.4)
    else
        return v / 12.92
    end
end

--- Convert RGB to CIEXYZ.
--- Gamma=2.2, sRGB
---@return number,number,number
function M:toXYZ()
    local r, g, b = norm(self)
    r, g, b = _toXYZ(r), _toXYZ(g), _toXYZ(b)
    local x = r * 0.436052025 + g * 0.385081593 + b * 0.143087414
    local y = r * 0.222491598 + g * 0.716886060 + b * 0.060621486
    local z = r * 0.013929122 + g * 0.097097002 + b * 0.714185470
    return x, y, z
end

local function _toLAB(v)
    if (v > 0.008856) then
        return math.pow(v, 1 / 3)
    else
        return 7.787 * v + 4 / 29
    end
end

-- Reference White Point D65
local WP_X = 95.047
local WP_Y = 100
local WP_Z = 108.883

--- Gamma=2.2, sRGB, white point D65
---@return number,number,number
function M:toLAB()
    local x, y, z = self:toXYZ()
    x, y, z = x * 100, y * 100, z * 100
    x, y, z = _toLAB(x / WP_X), _toLAB(y / WP_Y), _toLAB(z / WP_Z)
    local l = 116 * x - 16
    local a = 500 * (x - y)
    local b = 200 * (y - z)
    return l, a, b
end

function M:deltaE(other)
    local l1, a1, b1 = self:toLAB()
    local l2, a2, b2 = other:toLAB()
    local d1, d2, d3 = l1 - l2, a1 - a2, b1 - b2
    return math.sqrt(d1 * d1, d2 * d2, d3 * d3)
end

function M:toTable()
    local r, g, b, a = self:unpack()
    return { a = a, r = r, g = g, b = b }
end

--------------------------------------------------
-- parsing
--------------------------------------------------

local hex = {
    [2] = { '#g', 'rgb' },
    [3] = { '#gg', 'rgb' },
    [4] = { '#rgb', 'rgb' },
    [5] = { '#rgba', 'rgb' },
    [7] = { '#rrggbb', 'rgb' },
    [9] = { '#aarrggbb', 'rgb' },
}
local s3 = {
    hsl = { 'hsl', 'hsl' },
    hsv = { 'hsv', 'hsv' },
    rgb = { 'rgb', 'rgb' },
}
local s4 = {
    hsla = { 'hsla', 'hsl' },
    hsva = { 'hsva', 'hsv' },
    rgba = { 'rgba', 'rgb' },
}
local function string_format(s)
    local t
    if s:sub(1, 1) == '#' then
        t = hex[#s]
    else
        t = s4[s:sub(1, 4)] or s3[s:sub(1, 3)]
    end
    if t then
        -- format, colorspace
        return t[1], t[2]
    end
end

local parsers = {}

parsers['#g'] = function(s)
    local gray = tonumber(s:sub(2, 2), 16)
    if not gray then
        return
    end
    gray = (gray * 16 + gray) / 255
    return gray, gray, gray
end

local function parse_rgba(s)
    local r = tonumber(s:sub(2, 2), 16)
    local g = tonumber(s:sub(3, 3), 16)
    local b = tonumber(s:sub(4, 4), 16)
    if not (r and g and b) then
        return
    end
    r = (r * 16 + r) / 255
    g = (g * 16 + g) / 255
    b = (b * 16 + b) / 255
    if #s == 5 then
        local a = tonumber(s:sub(5, 5), 16)
        if not a then
            return
        end
        return r, g, b, (a * 16 + a) / 255
    else
        return r, g, b
    end
end
parsers['#rgb'] = parse_rgba
parsers['#rgba'] = parse_rgba

parsers['#gg'] = function(s)
    local gray = tonumber(s:sub(2, 3), 16)
    if not gray then
        return
    end
    gray = gray / 255
    return gray, gray, gray
end

local function parse_rrggbbaa(s)
    local r = tonumber(s:sub(2, 3), 16)
    local g = tonumber(s:sub(4, 5), 16)
    local b = tonumber(s:sub(6, 7), 16)
    if not (r and g and b) then
        return
    end
    r = r / 255
    g = g / 255
    b = b / 255
    if #s == 9 then
        local a = tonumber(s:sub(8, 9), 16)
        if not a then
            return
        end
        return r, g, b, a / 255
    else
        return r, g, b
    end
end
parsers['#rrggbb'] = parse_rrggbbaa
parsers['#rrggbbaa'] = parse_rrggbbaa
parsers['#aarrggbb'] = function(s)
    local a = tonumber(s:sub(2, 3), 16)
    local r = tonumber(s:sub(4, 5), 16)
    local g = tonumber(s:sub(6, 7), 16)
    local b = tonumber(s:sub(8, 9), 16)
    if not (r and g and b and a) then
        return
    end
    return r / 255, g / 255, b / 255, a / 255
end

local rgb_patt = '^rgb%s*%(([^,]+),([^,]+),([^,]+)%)$'
local rgba_patt = '^rgba%s*%(([^,]+),([^,]+),([^,]+),([^,]+)%)$'

local function np(s)
    local p = s and tonumber((s:match '^([^%%]+)%%%s*$'))
    return p and p * .01
end

local function n255(s)
    local n = tonumber(s)
    return n and n / 255
end

parsers.rgba = function(s)
    local r, g, b, a = s:match(rgba_patt)
    r = np(r) or n255(r)
    g = np(g) or n255(g)
    b = np(b) or n255(b)
    a = np(a) or tonumber(a)
    if not (r and g and b and a) then
        return
    end
    return r, g, b, a
end

parsers.rgb = function(s)
    local r, g, b = s:match(rgb_patt)
    r = np(r) or n255(r)
    g = np(g) or n255(g)
    b = np(b) or n255(b)
    if not (r and g and b) then
        return
    end
    return r, g, b
end

local hsl_patt = '^hsl%s*%(([^,]+),([^,]+),([^,]+)%)$'
local hsla_patt = '^hsla%s*%(([^,]+),([^,]+),([^,]+),([^,]+)%)$'

local hsv_patt = hsl_patt:gsub('hsl', 'hsv')
local hsva_patt = hsla_patt:gsub('hsla', 'hsva')

local function parser_pa(patt)
    return function(s)
        local h, s, x, a = s:match(patt)
        h = tonumber(h)
        s = np(s) or tonumber(s)
        x = np(x) or tonumber(x)
        a = np(a) or tonumber(a)
        if not (h and s and x and a) then
            return
        end
        return h, s, x, a
    end
end
parsers.hsla = parser_pa(hsla_patt)
parsers.hsva = parser_pa(hsva_patt)

local function parser_p(patt)
    return function(s)
        local h, s, x = s:match(patt)
        h = tonumber(h)
        s = np(s) or tonumber(s)
        x = np(x) or tonumber(x)
        if not (h and s and x) then
            return
        end
        return h, s, x
    end
end
parsers.hsl = parser_p(hsl_patt)
parsers.hsv = parser_p(hsv_patt)

local function parse(s)
    local fmt, space = string_format(s)
    if not fmt then
        return
    end
    local p = parsers[fmt]
    if not p then
        return
    end
    return space, p(s)
end

function M:parse(s)
    s = tostring(s)
    local space, x, y, z, w = parse(s)
    if not x then
        error(("can't parse %q"):format(s))
    end
    if w then
        self.a = w * 255
    else
        self.a = 255
    end
    if space == 'rgb' then
        self:setFloat(x, y, z)
    elseif space == 'hsl' then
        self:fromHSL(to_rad(x), y, z)
    elseif space == 'hsv' then
        self:fromHSV(to_rad(x), y, z)
    end
    return self
end

--------------------------------------------------
-- formatting
--------------------------------------------------

local format_spaces = {
    ['#']         = 'rgb',
    ['#rrggbbaa'] = 'rgb',
    ['#aarrggbb'] = 'rgb',
    ['#rrggbb']   = 'rgb',
    ['#rgba']     = 'rgb', ['#rgb'] = 'rgb',
    rgba          = 'rgb', rgb = 'rgb',
    hsla          = 'hsl', hsl = 'hsl',
    ['hsla%']     = 'hsl', ['hsl%'] = 'hsl',
    hsva          = 'hsv', hsv = 'hsv',
    ['hsva%']     = 'hsv', ['hsv%'] = 'hsv',
    rgba32        = 'rgb', argb32 = 'rgb',
}

function M:format(fmt)
    if fmt == nil then
        fmt = '#'
    end
    fmt = tostring(fmt)
    local dest_space = format_spaces[fmt]
    if not dest_space then
        error(('invalid format %q'):format(fmt))
    end
    local x, y, z
    local a = self.a
    if dest_space == 'rgb' then
        x, y, z = self:unpack()
    elseif dest_space == 'hsl' then
        x, y, z = self:toHSL()
    elseif dest_space == 'hsv' then
        x, y, z = self:toHSV()
    end
    if fmt == '#' then
        fmt = '#aarrggbb'
    end
    if fmt == '#rrggbbaa' or fmt == '#rrggbb' then
        return string.format(
                fmt == '#rrggbbaa' and '#%02x%02x%02x%02x' or '#%02x%02x%02x',
                x, y, z, a)
    elseif fmt == '#aarrggbb' then
        return string.format('#%02x%02x%02x%02x', a, x, y, z)
    elseif fmt == '#rgba' or fmt == '#rgb' then
        local factor = 1 / 255 * 15
        return string.format(
                fmt == '#rgba' and '#%1x%1x%1x%1x' or '#%1x%1x%1x',
                x * factor, y * factor, z * factor, a * factor)
    elseif fmt == 'rgba' or fmt == 'rgb' then
        return string.format(
                fmt == 'rgba' and 'rgba(%d,%d,%d,%.2g)' or 'rgb(%d,%d,%d)',
                x, y, z, a / 255)
    elseif fmt:sub(-1) == '%' then
        --hsl|v(a)%
        return string.format(
                #fmt == 5 and '%s(%d,%d%%,%d%%,%.2g)' or '%s(%d,%d%%,%d%%)',
                fmt:sub(1, -2),
                x, y * 100, z * 100, a / 255)
    elseif fmt == 'rgba32' then
        return x * 2 ^ 24 + y * 2 ^ 16 + z * 2 ^ 8 + a
    elseif fmt == 'argb32' then
        return tostring(self.argb)
    else
        --hsl|v(a)
        return string.format(
                #fmt == 4 and '%s(%d,%.2g,%.2g,%.2g)' or '%s(%d,%.2g,%.2g)',
                fmt, x, y, z, a / 255)
    end
end

return M
