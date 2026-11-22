---
--- color.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---

---
---@class x.color
color = color or {}
--local color = color
local math = math
local Color = Color

function color.lerp(c1, c2, a)
    return c1 + (c2 - c1) * a
end

function color.clamp(c, min, max)
    return Color(
            math.clamp(c.a, min.a, max.a),
            math.clamp(c.r, min.r, max.r),
            math.clamp(c.g, min.g, max.g),
            math.clamp(c.b, min.b, max.b))
end

function color.reverse(c)
    return color.White - c
end

function color.gray(c)
    local r, g, b = c.r, c.g, c.b
    return r * 0.299 + g * 0.587 + b * 0.114
end

function color.gray_mean(c)
    local r, g, b = c.r, c.g, c.b
    return (r + g + b) / 3
end

function color.gray_adobe(c)
    local r, g, b = c.r, c.g, c.b
    return (r ^ 2.2 * 0.2973 + g ^ 2.2 * 0.6274 + b ^ 2.2 * 0.0753) ^ (1 / 2.2)
end

---Convert RGB to YUV.
---Reference: [YUV](https://en.wikipedia.org/wiki/YUV)
function color.toYUV(c)
    local r, g, b = c.r, c.g, c.b
    local y = 0.299 * r + 0.587 * g + 0.114 * b
    local u = -0.169 * r - 0.331 * g + 0.499 * b + 128
    local v = 0.499 * r - 0.418 * g - 0.0813 * b + 128
    return { y = y, u = u, v = v }
end

---Convert YUV to RGB.
---Reference: [YUV](https://en.wikipedia.org/wiki/YUV)
---@return number,number,number
function color.fromYUV(c)
    local y, u, v = c.y, c.u, c.v
    local r = y + 1.402 * (v - 128)
    local g = y - 0.344 * (u - 128) - 0.714 * (v - 128)
    local b = y + 1.772 * (u - 128)
    return r, g, b
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

function color.toHSI(c)
    local r, g, b = c.r / 255, c.g / 255, c.b / 255
    local i = (r + g + b) / 3
    local s = 1 - math.min(r, g, b) / i
    local t1, t2 = r - g, r - b
    local theta = math.acos((t1 + t2) / 2 / math.sqrt(t1 * t1 + t2 * (g - b)))
    local h = theta
    if g < b then
        h = 2 * math.pi - theta
    end
    return { h = h, s = s, i = i }
end

---Convert HSI to RGB.
---Reference: [HSL and HSV](https://en.wikipedia.org/wiki/HSL_and_HSV)
---@return number,number,number
function color.fromHSI(c)
    local h, s, i = c.h, c.s, c.i
    local h_ = h / pi_3
    local z = 1 - math.abs(h_ % 2 - 1)
    local ch = 3 * i * s / (1 + z)
    local x = ch * z
    local r1, g1, b1 = fromcx(h_, ch, x)
    local m = i * (1 - s)
    return r1 + m, g1 + m, b1 + m
end

---Convert HSV to RGB.
---Reference: [HSL and HSV](https://en.wikipedia.org/wiki/HSL_and_HSV)
---@return number,number,number
function color.fromHSV(c)
    local h, s, v = c.h, c.s, c.v
    local ch = v * s
    local h_ = h / pi_3
    local x = ch * (1 - math.abs(h_ % 2 - 1))
    local r1, g1, b1 = fromcx(h_, ch, x)
    local m = v - ch
    return r1 + m, g1 + m, b1 + m
end

---Convert RGB to HSV.
---Reference: [HSL and HSV](https://en.wikipedia.org/wiki/HSL_and_HSV)
---@return table
function color.toHSV(c)
    local r, g, b = c.r, c.g, c.b
    r, g, b = r / 255, g / 255, b / 255
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
    local v = max
    return { h = h, s = s, v = v }
end

---Convert HSL to RGB.
---Reference: [HSL and HSV](https://en.wikipedia.org/wiki/HSL_and_HSV)
---@return number,number,number
function color.fromHSL(c)
    local h, s, l = c.h, c.s, c.l
    local ch = (1 - math.abs(2 * l - 1)) * s
    local h_ = h / pi_3
    local x = ch * (1 - math.abs(h_ % 2 - 1))
    local r1, g1, b1 = fromcx(h_, ch, x)
    local m = l - ch / 2
    return r1 + m, g1 + m, b1 + m
end

---Convert RGB to HSL.
---Reference: [HSL and HSV](https://en.wikipedia.org/wiki/HSL_and_HSV)
---@return table
function color.toHSL(c)
    local r, g, b = c.r, c.g, c.b
    r, g, b = r / 255, g / 255, b / 255
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
    return { h = h, s = s, l = l }
end

local function _toXYZ(v)
    if (v > 0.04045) then
        return math.pow((v + 0.055) / 1.055, 2.4)
    else
        return v / 12.92
    end
end

---Convert RGB to CIEXYZ.
---Gamma=2.2, sRGB
function color.toXYZ(c)
    local r, g, b = c.r / 255, c.g / 255, c.b / 255
    r, g, b = _toXYZ(r), _toXYZ(g), _toXYZ(b)
    local x = r * 0.436052025 + g * 0.385081593 + b * 0.143087414
    local y = r * 0.222491598 + g * 0.716886060 + b * 0.060621486
    local z = r * 0.013929122 + g * 0.097097002 + b * 0.714185470
    return { x = x, y = y, z = z }
end

local function _toLAB(v)
    if (v > 0.008856) then
        return math.pow(v, 1 / 3)
    else
        return 7.787 * v + 4 / 29
    end
end

--Reference White Point D65
local WP_X = 95.047
local WP_Y = 100
local WP_Z = 108.883

---Convert RGB to CIELAB.
---Gamma=2.2, sRGB, white point D65
---Reference: [Lab color space](https://en.wikipedia.org/wiki/Lab_color_space)
function color.toLAB(c)
    c = color.toXYZ(c)
    local x, y, z = c.x * 100, c.y * 100, c.z * 100
    x, y, z = _toLAB(x / WP_X), _toLAB(y / WP_Y), _toLAB(z / WP_Z)
    local l = 116 * x - 16
    local a = 500 * (x - y)
    local b = 200 * (y - z)
    return { l = l, a = a, b = b }
end

--- Convert RGB to CIELAB.
--- Gamma=2.2, sRGB, white point D65
--- Reference: [Lab color space](https://en.wikipedia.org/wiki/Lab_color_space)
function color.deltaE(c1, c2)
    c1 = color.toLAB(c1)
    c2 = color.toLAB(c2)
    return math.EuclideanDistance({ c1.l, c1.a, c1.b }, { c2.l, c2.a, c2.b })
end

function color.normBytes(...)
    local arg = { ... }
    local ret = {}
    for _, v in ipairs(arg) do
        table.insert(ret, math.clamp(math.round(v), 0, 0xFF))
    end
    return unpack(ret)
end

function color.normFloats(...)
    local arg = { ... }
    local ret = {}
    for _, v in ipairs(arg) do
        table.insert(ret, math.clamp(v, 0, 1))
    end
    return unpack(ret)
end

return color
