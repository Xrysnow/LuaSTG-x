---
--- stringify.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---


--from https://gist.github.com/Deco/3985043

local _stringify

_stringify = function(stack, this, spacing_h, spacing_v, space_n, parsed)
    local this_type = type(this)
    if this_type == "string" then
        stack[#stack + 1] = (
                spacing_v ~= "\n" and string.gsub(string.format("%q", this), "\\\n", "\\n")
                        or string.format("%q", this)
        )
    elseif this_type == "boolean" then
        stack[#stack + 1] = this and "true" or "false"
    elseif this_type == "number" then
        stack[#stack + 1] = tostring(this)
    elseif this_type == "function" then
        local info = debug.getinfo(this, "S")
        stack[#stack + 1] = "function"
        stack[#stack + 1] = ":("
        if not info or info.what == "C" then
            stack[#stack + 1] = "[C]"
        else
            --[[local param_list = debug.getparams(this)
            for param_i = 1, #param_list do
                stack[#stack+1] = param_list[param_i]
            end]]
        end
        stack[#stack + 1] = ")"
    elseif this_type == "table" then
        if parsed[this] then
            stack[#stack + 1] = "<" .. tostring(this) .. ">"
        else
            parsed[this] = true
            stack[#stack + 1] = "{" .. spacing_v
            for key, val in pairs(this) do
                stack[#stack + 1] = string.rep(spacing_h, space_n) .. "["
                _stringify(stack, key, spacing_h, spacing_v, space_n + 1, parsed)
                stack[#stack + 1] = "] = "
                _stringify(stack, val, spacing_h, spacing_v, space_n + 1, parsed)
                stack[#stack + 1] = "," .. spacing_v
            end
            stack[#stack + 1] = string.rep(spacing_h, space_n - 1) .. "}"
        end
    elseif this_type == "nil" then
        stack[#stack + 1] = "nil"
    else
        stack[#stack + 1] = this_type .. "<" .. tostring(this) .. ">"
    end
end

--- 序列化为字符串
function stringify(this, docol, spacing_h, spacing_v, preindent)
    local stack = {}
    _stringify(
            stack,
            this,
            spacing_h or "    ", spacing_v or "\n",
            (tonumber(preindent) or 0) + 1,
            {}
    )
    return table.concat(stack)
end
