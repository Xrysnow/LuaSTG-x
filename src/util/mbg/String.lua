--- Created by Xrysnow.
--- DateTime: 2018/2/1 20:57
--- Update: 2018/2/1

local mbg = require('util.mbg.main')

---@class mbg.String @String
local String = {}
mbg.String = String

function String:byte(i, j)
    return self.string:byte(i, j)
end

---@param pattern string
---@param init number
---@param plain boolean
---@return number, number
function String:find(pattern, init, plain)
    if pattern.string then
        pattern = pattern.string
    end
    local f1, f2 = self.string:find(pattern, init, plain)
    return f1 or -1, f2 or -1
end

---@param pattern string
---@param init number
---@param plain boolean
---@return number, number
function String:findlast(pattern, init, plain)
    local n1 = init or 1
    n1 = n1 - 1
    local n2, f1, f2
    repeat
        n1, n2 = self.string:find(pattern, n1 + 1, plain)
        f1, f2 = n1 or f1, n2 or f2
    until not n1
    if not f1 then
        return -1
    end
    return f1, f2
end

function String:gmatch(pattern)
    return self.string:gmatch(pattern)
end

function String:gsub(pattern, repl, n)
    return self.string:gsub(pattern, repl, n)
end

---@return number
function String:len()
    return self.string:len()
end

function String:lower()
    return String(self.string:lower())
end

function String:tolower()
    self.string = self.string:lower()
    return self
end

function String:match(pattern, init)
    return self.string:match(pattern, init)
end

function String:rep(n)
    return String(self.string:rep(n))
end

function String:reverse()
    return String(self.string:reverse())
end

function String:toreverse()
    self.string = self.string:reverse()
    return self
end

function String:sub(i, j)
    return String(self.string:sub(i, j))
end

function String:tosub(i, j)
    self.string = self.string:sub(i, j)
    return self
end

function String:upper()
    return String(self.string:upper())
end

function String:toupper()
    self.string = self.string:upper()
    return self
end

function String:trim(inplace)
    local s = self.string:match '^()%s*$' and '' or self.string:match '^%s*(.*%S)'
    if inplace then
        self.string = s
        return self
    else
        return String(s)
    end
end

function String:peek()
    local s = self:head():tostring()
    if s == '' then
        return -1
    else
        return s:byte()
    end
end

function String:head()
    return String(self.string:sub(1, 1))
end

function String:tail()
    return String(self.string:sub(-1))
end

function String:read(n)
    assert(not self:isempty(), "Can't read from empty string.")
    n = n or 1
    local ret = self.string:sub(1, n)
    self:tosub(n + 1)
    return String(ret)
end

---@return mbg.String
function String:readline()
    local n = self.string:find('\n')
    if not n then
        return self:readall()
    end
    local ret = self:read(n - 1)
    self:read()
    return ret
end

---@return mbg.String
function String:readall()
    local ret = self:copy()
    self:clear()
    return ret
end

function String:isempty()
    return #self.string == 0
end

function String:ischar()
    return #self.string == 1
end

function String:clear()
    self.string = ''
end

---@return mbg.String
function String:copy()
    return String(self)
end

---@return string
function String:tostring()
    return self.string
end

function String:tonumber()
    assert(tonumber(self.string))
    return tonumber(self.string)
end

function String:toint()
    return math.floor(self:tonumber())
end

function String:equalto(s)
    local str = s.string or s
    return self.string == str
end

function String:contains(s)
    return self.string:find(s) ~= nil
end

---split
---@param ... string @separator
---@return string[]
function String:split(...)
    local arg = { ... }
    assert(#arg > 0)
    local s = self.string
    local ret = {}
    for _, v in pairs(arg) do
        s = string.gsub(s, v, '\1')
    end
    string.gsub(s, '[^\1]+', function(w)
        table.insert(ret, w)
    end)
    return ret
end

function String:tocharsW()
    return String.SplitText(self.string)
end

function String:utf8len()
    local len = string.len(self.string)
    local left = len
    local cnt = 0
    local arr = { 0, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc }
    while left ~= 0 do
        local tmp = string.byte(self.string, -left)
        local i = #arr
        while arr[i] do
            if tmp >= arr[i] then
                left = left - i
                break
            end
            i = i - 1
        end
        cnt = cnt + 1
    end
    return cnt
end

String.string = ''

---@param s string optional
---@return mbg.String
local function _String(s)
    local ret = {}
    for k, v in pairs(String) do
        ret[k] = v
    end

    if s then
        if type(s) == 'string' then
            ret.string = s
        else
            ret.string = s.string or ''
        end
    end
    setmetatable(ret, getmetatable(String))
    return ret
end

local mt = {
    __add      = function(op1, op2)
        return _String(op1.string .. op2.string)
    end,
    __concat   = function(op1, op2)
        return _String(op1.string .. op2.string)
    end,
    __eq       = function(op1, op2)
        return op1:equalto(op2)
    end,
    __len      = function(op)
        --This will not work.
        return #op.string
    end,
    __tostring = function(op)
        return op.string
    end,
    __call     = function(op, s)
        return _String(s)
    end,
    __index    = function(op, key)
        if type(key) == 'number' then
            return op.string:sub(key, key)
        end
    end
}
setmetatable(String, mt)

---Split string to chars. It can deal with wide chars.
---@param str string
---@return string[]
function String.SplitText(str)
    local list = {}
    local len = string.len(str)
    local i = 1
    while i <= len do
        local c = string.byte(str, i)
        local shift = 1
        if c > 0 and c <= 127 then
            shift = 1
        elseif (c >= 192 and c <= 223) then
            shift = 2
        elseif (c >= 224 and c <= 239) then
            shift = 3
        elseif (c >= 240 and c <= 247) then
            shift = 4
        end
        local char = string.sub(str, i, i + shift - 1)
        i = i + shift
        table.insert(list, char)
    end
    return list
end

---Split string by \n, consecutive \n will turn into ''
---### Example: 'a[\n]b[\n\n]c' -> {'a', 'b', '', 'c'}
---@param str string
---@return string[]
function String.SplitLines(str)
    local t = {}
    local ss = String.SplitText(str)
    local i = 1
    t[1] = ''
    for _, v in pairs(ss) do
        if v ~= '\n' then
            t[i] = t[i] .. v
        else
            i = i + 1
            t[i] = ''
        end
    end
    return t
end

return String
