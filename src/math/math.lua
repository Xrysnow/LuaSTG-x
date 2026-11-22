---
--- math.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---

--local math = math
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

if not math.cbrt then
    ---@param v number
    ---@return number
    function math.cbrt(v)
        return pow(v, 1 / 3)
    end
end

if not math.clamp then
    ---@param v number
    ---@param lo number
    ---@param hi number
    ---@return number
    function math.clamp(v, lo, hi)
        return min(hi, max(v, lo))
    end
end

if not math.hypot then
    ---@param v1 number
    ---@param v2 number
    ---@return number
    function math.hypot(v1, v2)
        return sqrt(v1 * v1 + v2 * v2)
    end
end

if not math.lerp then
    ---@param v1 number
    ---@param v2 number
    ---@param a number
    ---@return number
    function math.lerp(v1, v2, a)
        return v1 + (v2 - v1) * a
    end
end

if not math.remainder then
    ---C++ std::remainder
    ---C# Math.IEEERemainder
    ---@param v1 number
    ---@param v2 number
    ---@return number
    function math.remainder(v1, v2)
        return v1 - v2 * math.round(v1 / v2)
    end
end

if not math.round then
    ---@param v number
    ---@return number
    function math.round(v)
        local f, c = floor(v), ceil(v)
        if v - f < c - v then
            return f
        else
            return c
        end
    end
end

if not math.gcd then
    ---@param m number
    ---@param n number
    ---@return number
    function math.gcd(m, n)
        local M = abs(floor(m))
        local N = abs(floor(n))
        if M == 0 then
            return N
        end
        if N == 0 then
            return M
        end
        while N > 0 do
            local tmp = M % N
            M = N
            N = tmp
        end
        return M
    end
end

if not math.lcm then
    ---@param m number
    ---@param n number
    ---@return number
    function math.lcm(m, n)
        local M = abs(floor(m))
        local N = abs(floor(n))
        return M / math.gcd(M, N) * N
    end
end

if math.tgamma and not math.beta then
    local gamma = math.tgamma
    ---@param x number
    ---@param y number
    ---@return number
    function math.beta(x, y)
        return gamma(x) * gamma(y) / gamma(x + y)
    end
end

--- solve:
--- a1 x + b1 y = c1
--- a2 x + b2 y = c2
---@return number,number,boolean
function math.solveLiner(a1, b1, c1, a2, b2, c2)
    local den = a2 * b1 - a1 * b2
    return (c2 * b1 - c1 * b2) / den, (c1 * a2 - c2 * a1) / den, den == 0
end

--------------------------------------------------
-- from Python
--------------------------------------------------

function math.divmod(x, y)
    local mod = x % y
    return (x - mod) / y, mod
end

local _rad_to_deg = 180 / pi

function math.degrees(x)
    return x * _rad_to_deg
end

function math.radians(x)
    return x / _rad_to_deg
end

function math.isclose(a, b, rel_tol, abs_tol)
    rel_tol = rel_tol and abs(rel_tol) or 1e-9
    abs_tol = abs_tol and abs(abs_tol) or 0
    return abs(a - b) <= max(rel_tol * max(abs(a), abs(b)), abs_tol)
end

function math.isqrt(n)
    return floor(sqrt(n))
end

--

--- Round to nearest integer towards zero.
function math.fix(x)
    if x > 0 then
        return floor(x)
    else
        return ceil(x)
    end
end

--

--- Calculates log(exp(v1) + exp(v2)).
---@param v1 number
---@param v2 number
---@return number
function math.logaddexp(v1, v2)
    return log(exp(v1) + exp(v2))
end

--- Calculates log2(2^v1 + 2^v2).
---@param x number
---@param y number
---@return number
function math.logaddexp2(v1, v2)
    return math.log2(math.exp2(v1) + math.exp2(v2))
end

--- Return floor(x/y).
---@param v1 number
---@param v2 number
---@return number
function math.floor_divide(x, y)
    return floor(x / y)
end

--- Returns -1 if x < 0, 0 if x==0, 1 if x > 0. nan is returned for nan inputs.
---@param x number
---@return number @-1, 0, 1
function math.sign(x)
    if x > 0 then
        return 1
    elseif x < 0 then
        return -1
    elseif x == 0 then
        return 0
    else
        return 0 / 0
    end
end

--- Compute the Heaviside step function.
---@param x1 number
---@param x2 number
---@return number
function math.heaviside(x1, x2)
    if x1 < 0 then
        return 0
    elseif x1 > 1 then
        return 1
    else
        return x2
    end
end

--- Return the normalized sinc function.
function math.sinc(x)
    if -2e-4 < x and x < 2e-4 then
        return 1 - x ^ 2 / 6
    end
    local p = pi * x
    return sin(p) / p
end

--------------------------------------------------
-- from Microsoft.Xna.Framework.MathHelper
--------------------------------------------------

---C# MathHelper.Barycentric
---@param v1 number
---@param v2 number
---@param v3 number
---@param a1 number
---@param a2 number
---@return number
function math.barycentric(v1, v2, v3, a1, a2)
    return (v1 + (a1 * (v2 - v1))) + (a2 * (v3 - v1))
end

---C# MathHelper.SmoothStep
---@param v1 number
---@param v2 number
---@param a number
---@return number
function math.smoothstep(v1, v2, a)
    a = math.clamp(a, 0, 1)
    return math.lerp(v1, v2, a * a * (3 - 2 * a))
end

---C# MathHelper.WrapAngle
---@return number
---@param v number
function math.wrapangle(v)
    local a = math.remainder(v, pix2)
    if a <= -pi then
        return a + pix2
    elseif a > pi then
        return a - pix2
    else
        return a
    end
end

--------------------------------------------------
-- metrics
--------------------------------------------------

function math.EuclideanDistance(v1, v2)
    local sum = 0
    for i = 1, #v1 do
        local d = v1[i] - v2[i]
        sum = sum + d * d
    end
    return sqrt(sum)
end

function math.ManhattanDistance(v1, v2)
    local sum = 0
    for i = 1, #v1 do
        sum = sum + abs(v1[i] - v2[i])
    end
    return sum
end

function math.ChebyshevDistance(v1, v2)
    local ret = 0
    for i = 1, #v1 do
        local d = abs(v1[i] - v2[i])
        if d > ret then
            ret = d
        end
    end
    return ret
end

function math.MinkowskiDistance(v1, v2, p)
    local sum = 0
    for i = 1, #v1 do
        sum = sum + pow(abs(v1[i] - v2[i]), p)
    end
    return pow(sum, 1 / p)
end

--------------------------------------------------
-- special number
--------------------------------------------------

local inf = 1 / 0
local ninf = -1 / 0

--TODO: cdata float

if not math.isinf then
    --- v == +/-inf
    function math.isinf(v)
        return v == inf or v == ninf
    end
end

if not math.isfinite then
    --- v is not positive infinity, negative infinity, or NaN
    function math.isfinite(v)
        return v ~= inf and v ~= ninf and v == v
    end
end

if not math.isnan then
    function math.isnan(v)
        return v ~= v
    end
end

--------------------------------------------------
-- fibonacci
--------------------------------------------------

local _fib_cache

---@param n number
---@return number
function math.fibonacci(n)
    if n < 1 then
        return 0
    end
    if n > 1476 then
        error('n is too big')
    end
    if not _fib_cache then
        _fib_cache = { 1, 1 }
        local f1, f2 = 1, 1
        local fn = 0
        for i = 3, 1476 do
            fn = f1 + f2
            f1 = f2
            f2 = fn
            _fib_cache[i] = fn
        end
    end
    return _fib_cache[n]
end
