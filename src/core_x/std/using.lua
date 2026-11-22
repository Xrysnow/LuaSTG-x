---
--- using.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---

std = std or {}

local USINGS = {}

local function _ToGlobalTable(name)
    local t = {}
    string.gsub(name, '[^%.]+', function(w)
        table.insert(t, w)
    end)
    local n = _G
    for i = 1, #t do
        n = n[t[i]]
        if not n then
            return nil
        end
    end
    return n
end

function std.using(name)
    if type(name) == 'string' then
        name = _ToGlobalTable(name)
        assert(name ~= _G)
    end
    assert(type(name) == 'table')
    local p = debug.getinfo(2, "S").source
    if not USINGS[p] then
        USINGS[p] = { [0] = _G }
        local env = {}
        setmetatable(env, {
            __index = function(t, key)
                for _, v in pairs(USINGS[p]) do
                    if v[key] then
                        return v[key]
                    end
                end
            end
        })
        setfenv(2, env)
    end
    table.insert(USINGS[p], name)
end

function std.unusing(name)
    if type(name) == 'string' then
        name = _ToGlobalTable(name)
    end
    local p = debug.getinfo(2, "S").source
    if USINGS[p] then
        for k, v in pairs(USINGS[p]) do
            if v == name then
                USINGS[p][k] = nil
            end
        end
    end
end
