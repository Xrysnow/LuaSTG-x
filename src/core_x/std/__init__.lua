---
--- __init__.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---

std = std or {}

--from '.' import '*'
for _, n in ipairs({ 'algorithm', 'function', 'list', 'try', 'using', 'vector' }) do
    require('core_x.std.' .. n)
end

---switch
---@param val any
---@param cases table
function std.switch(val, cases)
    if cases[val] then
        return cases[val]()
    end
    if cases['default'] then
        return cases['default']()
    end
end

--

local function _err()
    error("Can't modify a const table.")
end

function std.make_const(v)
    local ret = {}
    local mt = {
        __index    = v,
        __newindex = _err
    }
    setmetatable(ret, mt)
    return ret
end

function std.is_const(v)
    local mt = getmetatable(v)
    return mt and mt.__newindex == _err
end

function std.unconst(v)
    local mt = getmetatable(v)
    if mt and mt.__newindex == _err then
        return mt.__index
    else
        return v
    end
end

--

function std.with(t, f)
    return setfenv(f, t)()
end
