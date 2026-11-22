---
--- __init__.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---


--from '.' import '*'
for _, n in ipairs({ 'deepcopy', 'dump', 'functional', 'misc' }) do
    require('core_x.table.' .. n)
end

local pairs = pairs

---Clone a table
---from cocos2dx
---@param t table
---@return table
function table.clone(t)
    local lookup_table = {}
    local function _copy(object)
        if type(object) ~= "table" then
            return object
        elseif lookup_table[object] then
            return lookup_table[object]
        end
        local new_table = {}
        lookup_table[object] = new_table
        for key, value in pairs(object) do
            new_table[_copy(key)] = _copy(value)
        end
        return setmetatable(new_table, getmetatable(object))
    end
    return _copy(t)
end

---
---Copy values from source to target with default values.
---Example: table.deploy(self, params, { a = 1 })
---@param t object
---@param src table
---@param default table
---@param isclone boolean will use table.clone(src) if this is true.
function table.deploy(t, src, default, isclone)
    if default then
        for k, v in pairs(default) do
            t[k] = v
        end
    end
    if src then
        if isclone then
            src = table.clone(src)
        end
        for k, v in pairs(src) do
            t[k] = v
        end
    end
end

---
---Copy values from source to target when key is missing.
---@param t object
---@param src table
function table.supplement(t, src)
    if src then
        for k, v in pairs(src) do
            t[k] = t[k] or v
        end
    end
end

---@param t table
---@return boolean
function table.has(t, v)
    for _, _v in pairs(t) do
        if _v == v then
            return true
        end
    end
    return false
end

table.unpack = unpack

---
--- Returns a new table with all arguments stored into keys 1, 2, etc. and
--- with a field "`n`" with the total number of arguments. Note that the
--- resulting table may not be a sequence, if some arguments are **nil**.
---@return table
function table.pack(...)
    local ret = { ... }
    ret.n = #ret
    return ret
end
