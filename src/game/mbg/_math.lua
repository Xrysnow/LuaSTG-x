--
local M = {}
local pi = math.pi
local pix2 = math.pi * 2
local abs = math.abs
local acos = math.acos
local asin = math.asin
local atan = math.atan
local atan2 = math.atan2
local ceil = math.ceil
local cos = math.cos
local cosh = math.cosh
local deg = math.deg
local exp = math.exp
local floor = math.floor
local fmod = math.fmod
local frexp = math.frexp
local ldexp = math.ldexp
local log = math.log
local log10 = math.log10
local max = math.max
local min = math.min
local modf = math.modf
local pow = math.pow
local rad = math.rad
local random = math.random
local randomseed = math.randomseed
local sin = math.sin
local sinh = math.sinh
local sqrt = math.sqrt
local tan = math.tan
local tanh = math.tanh

function M.Min(...)
    return min(...)
end

function M.Max(...)
    return max(...)
end

function M.Sin(x)
    return sin(x)
end

function M.Cos(x)
    return cos(x)
end

function M.Atan(x)
    return atan(x)
end

function M.Sqrt(x)
    return sqrt(x)
end

function M.Abs(x)
    return abs(x)
end

function M.Clamp(x, lo, hi)
    return min(hi, max(x, lo))
end

function M.ToDegrees(x)
    return x / pi * 180
end

function M.ToRadians(x)
    return x / 180 * pi
end

function M.Lerp(value1, value2, amount)
    return value1 + (value2 - value1) * amount
end

return M
