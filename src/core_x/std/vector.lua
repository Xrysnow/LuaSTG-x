---
--- vector.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---

std = std or {}

---@class vector
local vector = {}
std.vector = vector

local function ctor(T)
    local ret = {}
    ret._T = T
    setmetatable(ret, {
        __index = vector
    })
    return ret
end
local mt = { __call = function(op, param)
    local ty = type(param)
    if std.isvector(param) then
        return param:copy()
    elseif std.is_callable(param) then
        return ctor(param)
    elseif ty == 'table' then
        local ret = ctor()
        for i = 1, #param do
            ret[i] = param[i]
        end
        return ret
    elseif ty == 'number' or ty == 'string' or ty == 'boolean' then
        return ctor(function()
            return param
        end)
    elseif param == nil then
        return ctor()
    else
        error("Can't construct vector from " .. tostring(param))
    end
end }
setmetatable(vector, mt)


-------------------------------------------------
---vector
-------------------------------------------------


--element access---------------------------------

function vector:front()
    return assert(self[1])
end

function vector:back()
    return assert(self[#self])
end

function vector:at(n)
    if n > #self or n < 1 then
        error('Index out of range.')
    end
    return assert(self[n])
end

--capacity---------------------------------------

function vector:empty()
    return self:size() == 0
end

function vector:size()
    return #self
end

function vector:resize(n, val)
    for i = n + 1, self:size() do
        self[i] = nil
    end
    if val then
        for i = self:size() + 1, n do
            self[i] = val
        end
    elseif self._T then
        for i = self:size() + 1, n do
            self[i] = self._T()
        end
    end
end

--modifiers--------------------------------------

function vector:clear()
    self:erase(1, self:size())
end

function vector:erase(n, m)
    m = m or n
    local ne = m - n + 1
    for i = n, self:size() do
        self[i] = self[i + ne]
    end
end

function vector:push_back(v)
    self[#self + 1] = assert(v)
end

function vector:pop_back()
    local ret = self[#self]
    self[#self] = nil
    return ret
end

function vector:remove(v)
    local idx
    if type(v) == 'userdata' then
        for i, _v in ipairs(self) do
            if type(_v) == type(v) and tostring(_v) == tostring(v) then
                idx = i
                break
            end
        end
    else
        for i, _v in ipairs(self) do
            if _v == v then
                idx = i
                break
            end
        end
    end
    if idx then
        self:erase(idx)
        return true
    end
end

function vector:remove_all(v)
    local flag = true
    while flag do
        flag = self:remove(v)
    end
end

--allocator--------------------------------------

function vector:get_allocator()
    return self._T
end

--copy-------------------------------------------

---copy
---@return vector
function vector:copy()
    local ret = vector(self._T)
    for i = 1, self:size() do
        ret[i] = self[i]
    end
    return ret
end

function std.isvector(v)
    return getmetatable(v) == mt
end

