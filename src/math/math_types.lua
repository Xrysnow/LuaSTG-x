---
--- math_types.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---

--
local M = {}

local ffi = ffi or require('ffi')
ffi.defines = ffi.defines or {}

for _, v in ipairs({
                       [[union u_32ToU32{int32_t x;uint32_t i;}]],
                       [[union u_64ToU64{int64_t x;uint64_t i;}]],
                       [[union u_FloatToU32{float x;uint32_t i;}]],
                       [[union u_DoubleToU64{double x;uint64_t i;}]] }) do
    if not ffi.defines[v] then
        ffi.cdef(v)
        ffi.defines[v] = true
    end
end

local int32_t = ffi.typeof('int32_t')
local uint32_t = ffi.typeof('uint32_t')
local int64_t = ffi.typeof('int64_t')
local uint64_t = ffi.typeof('uint64_t')
local float = ffi.typeof('float')
local double = ffi.typeof('double')

local unionI32 = ffi.typeof('union u_32ToU32')
local unionI64 = ffi.typeof('union u_64ToU64')
local unionF = ffi.typeof('union u_FloatToU32')
local unionD = ffi.typeof('union u_DoubleToU64')

local i32 = 2 ^ 32
local i64 = 2 ^ 64
local err_hex = "Can't convert it."
local err_len = "Param is too long."

local function trim(hex)
    if string.sub(hex, 1, 2) == '0x' then
        return string.sub(hex, 3)
    end
    return hex
end

local function hex2uint(hex)
    local len = string.len(hex)
    local i = len
    if len > 16 then
        error(err_len)
    end
    if len <= 8 then
        local ret = uint64_t(0)
        while i > 0 do
            local c = string.byte(hex, -i)
            local off
            if c >= 48 and c <= 57 then
                off = 48
            elseif c >= 97 and c <= 102 then
                off = 87
            elseif c >= 65 and c <= 70 then
                off = 55
            else
                error("Wrong letter in hex.")
            end
            ret = ret + (c - off) * 16 ^ (i - 1)
            i = i - 1
        end
        return ret
    else
        return hex2uint(string.sub(hex, 1, -9)) * i32 + hex2uint(string.sub(hex, -8))
    end
end

local function uint2chars(x, n)
    local ret = ''
    local ut = uint32_t
    if n > 4 then
        ut = uint64_t
    end
    local d = ut(256) ^ (n - 1)
    for i = 1, n do
        ret = ret .. string.char(tonumber(x / d))
        x = x % d
        d = d / 256
    end
    --to little-endian
    return ret:reverse()
end

local function chars2uint(c)
    assert(#c <= 8, err_len)
    local ut = uint32_t
    if #c > 4 then
        ut = uint64_t
    end
    local ret = ut(0)
    --little-endian
    for i = 0, #c - 1 do
        ret = ret + ut(256) ^ i * string.byte(c, i + 1)
    end
    return ret
end

---
local Int = {}
M.Int = Int

Int.max = 2 ^ 31 - 1
Int.min = -2 ^ 31

function Int.tobytes(x)
    if x <= Int.max and x >= Int.min then
        return uint2chars(uint32_t(x), 4)
    end
    error(err_hex)
end

function Int.frombytes(b)
    assert(#b <= 4, err_len)
    local n = unionI32()
    n.i = chars2uint(b)
    return tonumber(n.x)
end

function Int.tohex(x)
    if x <= Int.max and x >= Int.min then
        return bit.tohex(tonumber(int32_t(x)))
    end
    error(err_hex)
end

function Int.fromhex(h)
    assert(string.len(trim(h)) <= 4, err_len)
    local n = unionI32()
    n.i = hex2uint(trim(h))
    return tonumber(n.x)
end

---
---## Better use with ctype.
local Int64 = {}
M.Int64 = Int64

Int64.max = 2 ^ 63 - 1
Int64.min = -2 ^ 63
Int64.cmin = int64_t(-2 ^ 31) ^ 2 * 2
Int64.cmax = Int64.cmin - 1

function Int64.tobytes(x)
    if x <= Int64.cmax and x >= Int64.cmin then
        return uint2chars(uint64_t(x), 8)
    end
    error(err_hex)
end

---## Return ctype instead of number.
function Int64.frombytes(b)
    local n = unionI64()
    n.i = chars2uint(b)
    return n.x
end

function Int64.tohex(x)
    if x <= Int64.cmax and x >= Int64.cmin then
        local n = int64_t(x)
        return bit.tohex(tonumber(n.i / i32)) .. bit.tohex(tonumber(n.i % i32))
    end
    error(err_hex)
end

---## Return ctype instead of number.
function Int64.fromhex(h)
    local n = unionI64()
    n.i = hex2uint(trim(h))
    return n.x
end

---
local UInt = {}
M.UInt = UInt

UInt.max = 2 ^ 32 - 1
UInt.min = 0

function UInt.tobytes(x)
    if x <= UInt.max and x >= UInt.min then
        return uint2chars(uint32_t(x), 4)
    end
    error(err_hex)
end

function UInt.frombytes(b)
    assert(#b <= 4, err_len)
    return tonumber(chars2uint(b))
end

function UInt.tohex(x)
    if x <= UInt.max and x >= UInt.min then
        return bit.tohex(tonumber(uint32_t(x)))
    end
    error(err_hex)
end

function UInt.fromhex(h)
    assert(string.len(trim(h)) <= 4, err_len)
    return tonumber(hex2uint(trim(h)))
end

---
---## Better use with ctype.
local UInt64 = {}
M.UInt64 = UInt64

UInt64.max = 2 ^ 64 - 1
UInt64.min = 0
UInt64.cmax = uint64_t(-1)
UInt64.cmin = uint64_t(0)

function UInt64.tobytes(x)
    if x <= UInt64.cmax and x >= UInt64.cmin then
        return uint2chars(uint64_t(x), 8)
    end
    error(err_hex)
end

---## Return ctype instead of number.
function UInt64.frombytes(b)
    return chars2uint(b)
end

function UInt64.tohex(x)
    if x <= UInt64.cmax and x >= UInt64.cmin then
        local n = uint64_t(x)
        return bit.tohex(tonumber(n.i / i32)) .. bit.tohex(tonumber(n.i % i32))
    end
    error(err_hex)
end

---## Return ctype instead of number.
function UInt64.fromhex(h)
    return hex2uint(trim(h))
end

---
---## Possible loss of precision, be careful.
local Float = {}
M.Float = Float

local f1 = unionF({ 1e39 })
local f2 = unionF({ -1e39 })
f1.i = f1.i - 1
f2.i = f2.i - 1
Float.max = tonumber(f1.x)
Float.min = tonumber(f2.x)
Float.cmax = f1.x
Float.cmin = f2.x
Float.eps = 1.19209290E-7

function Float.tobytes(x)
    if x <= Float.max and x >= Float.min then
        local n = unionF()
        n.x = x
        return uint2chars(n.i, 4)
    end
    error(err_hex)
end

function Float.frombytes(b)
    assert(#b <= 4, err_len)
    local n = unionF()
    n.i = chars2uint(b)
    return tonumber(n.x)
end

function Float.tohex(x)
    if x < Float.max and x > Float.min then
        local n = unionF(x)
        return bit.tohex(tonumber(n.i))
    end
    error(err_hex)
end

function Float.fromhex(h)
    assert(string.len(trim(h)) <= 4, err_len)
    local n = unionF()
    n.i = hex2uint(trim(h))
    return tonumber(n.x)
end

---
local Double = {}
M.Double = Double

local d1 = unionD({ 1e309 })
local d2 = unionD({ -1e309 })
d1.i = d1.i - 1
d2.i = d2.i - 1

Double.max = tonumber(d1.x)
Double.min = tonumber(d2.x)
Double.cmax = d1.x
Double.cmin = d2.x
Double.eps = 1.084202172485504E-19

function Double.tobytes(x)
    local n = unionD()
    n.x = x
    return uint2chars(n.i, 8)
end

function Double.frombytes(b)
    local n = unionD()
    n.i = chars2uint(b)
    return tonumber(n.x)
end

function Double.tohex(x)
    local n = unionD(x)
    return bit.tohex(tonumber(n.i / i32)) .. bit.tohex(tonumber(n.i % i32))
end

function Double.fromhex(h)
    local n = unionD()
    n.i = hex2uint(trim(h))
    return tonumber(n.x)
end

---

M.int32_t = ffi.typeof('int32_t')     ---## ctype for int32_t from ffi
M.uint32_t = ffi.typeof('uint32_t')    ---## ctype for uint32_t from ffi
M.int64_t = ffi.typeof('int64_t')     ---## ctype for int64_t from ffi
M.uint64_t = ffi.typeof('uint64_t')    ---## ctype for uint64_t from ffi
M.float = ffi.typeof('float')       ---## ctype for float from ffi
M.double = ffi.typeof('double')      ---## ctype for double from ffi

return M
