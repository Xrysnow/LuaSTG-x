---
--- xclass.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---

local type = type
local pairs = pairs
local RawNew = lstg.RawNew

local callbacks = {
    init   = true,
    del    = true,
    frame  = true,
    render = true,
    colli  = true,
    kill   = true,
}

--- Create extended game object class.
--- You can use classname(...) to create an instance of game object.
--- Example: `classname = xclass(object)`
---@see object
---@param base object
---@param define table
---@return object
function xclass(base)
    local ret = Class(base, base)
    ret['.x'] = true
    if base and base['.3d'] then
        ret['.3d'] = true
    end
    local methods
    local function get_methods()
        for k, v in pairs(ret) do
            if type(v) == 'function' and type(k) == 'string' and not callbacks[k] then
                methods[k] = v
            end
        end
    end
    local mt = { __call = function(t, ...)
        local obj = RawNew(ret)
        if not methods then
            get_methods()
        end
        for k, v in pairs(methods) do
            obj[k] = v
        end
        ret[1](obj, ...)
        return obj
    end }
    return setmetatable(ret, mt)
end

