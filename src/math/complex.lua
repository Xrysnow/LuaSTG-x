---
---@class math.complex
local M = {}

local ffi = require('ffi')

local istype = ffi.istype
local newffi = ffi.new

local type = type
local select = select
local tonumber = tonumber
local tostring = tostring

local e = math.exp(1)
local pi = math.pi
local abs = math.abs
local exp = math.exp
local log = math.log
local cos = math.cos
local sin = math.sin
local cosh = math.cosh
local sinh = math.sinh
local sqrt = math.sqrt
local atan2 = math.atan2
local floor = math.floor

--Locally used and desirable functions--

local function re(n)
    return istype("complex", n) and n.re or type(n) == "number" and n or 0
end

local function im(n)
    return istype("complex", n) and n.im or 0
end

---@return ffi.cdata
local function complex(re, im)
    return newffi("complex", re or 0, im or 0)
end

local function rect(r, phi)
    --r*e^(i*phi) -> x+iy
    return complex(r * cos(phi), r * sin(phi))
end

---@return number
local function arg(z)
    --Lol, no documentation
    return atan2(im(z), re(z))
end

local function ln(c)
    --Natural logarithm
    local r1, i1 = re(c), im(c)
    return complex(log(r1 ^ 2 + i1 ^ 2) / 2, atan2(i1, r1))
end
-----------------------------------------

--Complex number metatable--
local complex_mt = {
    __add      = function(c1, c2)
        return complex(re(c1) + re(c2), im(c1) + im(c2))
    end,
    __sub      = function(c1, c2)
        return complex(re(c1) - re(c2), im(c1) - im(c2))
    end,
    __mul      = function(c1, c2)
        local r1, i1, r2, i2 = re(c1), im(c1), re(c2), im(c2)
        return complex(r1 * r2 - i1 * i2, r1 * i2 + r2 * i1)
    end,
    __div      = function(c1, c2)
        local r1, i1, r2, i2 = re(c1), im(c1), re(c2), im(c2)
        local rsq = r2 ^ 2 + i2 ^ 2
        return complex((r1 * r2 + i1 * i2) / rsq, (r2 * i1 - r1 * i2) / rsq)
    end,
    __pow      = function(c1, c2)
        --Aww ye
        local r1, i1, r2, i2 = re(c1), im(c1), re(c2), im(c2)
        local rsq = r1 ^ 2 + i1 ^ 2
        if rsq == 0 then
            --Things work better like this.
            if r2 == 0 and i2 == 0 then
                return 1
            end
            return 0
        end
        local phi = atan2(i1, r1)
        return rect(rsq ^ (r2 / 2) * exp(-i2 * phi), i2 * log(rsq) / 2 + r2 * phi)
    end,
    __unm      = function(c)
        return complex(-re(c), -im(c))
    end,
    __tostring = function(c)
        local r, i = re(c), im(c)
        if i == 0 then
            return tostring(r)
        elseif r == 0 then
            if i == 1 then
                return "i"
            elseif i == -1 then
                return "-i"
            end
            return i .. "i"
        elseif i < 0 then
            if i == -1 then
                return r .. "-i"
            end
            return r .. i .. "i"
        else
            if i == 1 then
                return r .. "+i"
            end
            return r .. "+" .. i .. "i"
        end
    end
}
----------------------------

--Allow complex arguments for regular math functions--
--Note that all these functions still work for regular numbers!
--The added bonus is that they can handle things like (-1)^0.5. (=i)

local i = complex(0, 1)

M.e = e
M.i = i
M.pi = pi
M.re = re
M.im = im
M.complex = complex
M.arg = arg
M.rect = rect
M.ln = ln

function M.abs(c)
    --This always returns a pure real value
    return sqrt(re(c) ^ 2 + im(c) ^ 2)
end

function M.diff(c)
    return re(c) ^ 2 - im(c) ^ 2
end

function M.exp(c)
    return e ^ c
end

function M.sqrt(c)
    local num = istype("complex", c) and c ^ 0.5 or complex(c) ^ 0.5
    if im(num) == 0 then
        return re(num)
    end
    return num
end

--Trig functions

function M.sin(c)
    local r, i = re(c), im(c)
    return complex(sin(r) * cosh(i), cos(r) * sinh(i))
end
function M.cos(c)
    local r, i = re(c), im(c)
    return complex(cos(r) * cosh(i), sin(r) * sinh(i))
end
function M.tan(c)
    local r, i = 2 * re(c), 2 * im(c)
    local div = cos(r) + cosh(i)
    return complex(sin(r) / div, sinh(i) / div)
end

--Hyperbolic trig functions

function M.sinh(c)
    local r, i = re(c), im(c)
    return complex(cos(i) * sinh(r), sin(i) * cosh(r))
end
function M.cosh(c)
    local r, i = re(c), im(c)
    return complex(cos(i) * cosh(r), sin(i) * sinh(r))
end
function M.tanh(c)
    local r, i = 2 * re(c), 2 * im(c)
    local div = cos(i) + cosh(r)
    return complex(sinh(r) / div, sin(i) / div)
end

--Caution! Mathematical laziness beyond this point!

--Inverse trig functions

function M.asin(c)
    return -i * ln(i * c + (1 - c ^ 2) ^ 0.5)
end
function M.acos(c)
    return pi / 2 + i * ln(i * c + (1 - c ^ 2) ^ 0.5)
end
function M.atan(c)
    local r2, i2 = re(c), im(c)
    local c3, c4 = complex(1 - i2, r2), complex(1 + r2 ^ 2 - i2 ^ 2, 2 * r2 * i2)
    return complex(arg(c3 / c4 ^ 0.5), -ln(M.abs(c3) / M.abs(c4) ^ 0.5))
end
function M.atan2(c2, c1)
    --y,x
    local r1, i1, r2, i2 = re(c1), im(c1), re(c2), im(c2)
    if r1 == 0 and i1 == 0 and r2 == 0 and i2 == 0 then
        --Indeterminate
        return 0
    end
    local c3, c4 = complex(r1 - i2, i1 + r2), complex(r1 ^ 2 - i1 ^ 2 + r2 ^ 2 - i2 ^ 2, 2 * (r1 * i1 + r2 * i2))
    return complex(arg(c3 / c4 ^ 0.5), -ln(M.abs(c3) / M.abs(c4) ^ 0.5))
end

--Inverse hyperbolic trig functions. Why do they all look different but give correct results!? e.e

function M.asinh(c)
    return ln(c + (1 + c ^ 2) ^ 0.5)
end
function M.acosh(c)
    return 2 * ln((c - 1) ^ 0.5 + (c + 1) ^ 0.5) - log(2)
end
function M.atanh(c)
    return (ln(1 + c) - ln(1 - c)) / 2
end

--Miscellaneous functions

function M.zeta(s, accuracy)
    local sum = 0
    for n = 1, accuracy or 10000 do
        sum = sum + n ^ -s
    end
    return sum
end

--End of non-optimized terrors.

--- Linear integration, evenly spaced slices
--- f=function(x),low=0,high=100,slices=10000
function M.lintegrate(f, H, L, n)
    n = n or floor(10 * sqrt(H))
    L = L or 0
    local LH = H - L
    local A = (f(L) + f(H)) / 2
    for x = 1, n - 1 do
        A = A + f(L + LH * x / n)
    end
    return A / n
end

--- log: Complex base logarithm! Two arguments (b=c1,z=c2) gives log_b(z), which is identical to log(c2)/log(c1).
function M.log(c2, c1)
    local r1, i1 = re(c1), im(c1)
    local r2, i2 = re(c2), im(c2)
    local r3, i3 = log(r1 ^ 2 + i1 ^ 2) / 2, atan2(i1, r1)
    local r4, i4 = log(r2 ^ 2 + i2 ^ 2) / 2, atan2(i2, r2)
    local rsq = r4 ^ 2 + i4 ^ 2
    return complex((r3 * r4 + i3 * i4) / rsq, (r4 * i3 - r3 * i4) / rsq)
end

M.pow = complex_mt.__pow

---------------------------------------------------------------------------

--These are just some useful tools when working with complex numbers.--

--- polar: x+iy -> r*e^(i*phi) One complex argument, or two real arguments can be given.
--- This is basically return abs(z),arg(z)
function M.polar(cx, oy)
    local x, y
    if oy then
        x, y = cx, oy
    else
        x, y = re(cx), im(cx)
    end
    return sqrt(x ^ 2 + y ^ 2), atan2(y, x)
end

--- cx: Define complex numbers from a string.
function M.cx(a, b)
    local r, i_ = 0, 0
    if type(a) == "string" and type(b) == "nil" then
        local query = a:gsub("[^%d.+-i]", "")
        if #query > 0 then
            for sgn, im_ in query:gmatch '([+-]*)(%d*%.?%d*)i' do
                i_ = i_ + (-1) ^ select(2, sgn:gsub("-", "")) * (tonumber(im_) or 1)
            end
            for sgn, re_ in query:gsub("[+-]*%d*%.?%d*i", ""):gmatch '([+-]*)(%d*%.?%d*)()' do
                r = r + (-1) ^ select(2, sgn:gsub("-", "")) * (tonumber(re_) or #sgn > 0 and 1 or 0)
            end
        end
    else
        r, i_ = tonumber(a) or 0, tonumber(b) or 0
    end
    return complex(r, i_)
end

-----------------------------------------------------------------------

ffi.metatype(ffi.typeof('complex'), complex_mt)

return M
