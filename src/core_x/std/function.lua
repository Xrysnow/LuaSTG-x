---
--- function.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---

std = std or {}

---
---bind
---@param f fun(...):any
---@return fun(...):any
function std.bind(f, ...)
    local argsSuper = { ... }
    local n1 = select("#", ...)
    return function(...)
        local args = { ... }
        local argsOut = { unpack(argsSuper, 1, n1) }
        for i, v in pairs(args) do
            argsOut[n1 + i] = v
        end
        return f(unpack(argsOut, 1, table.maxn(argsOut)))
    end
end

---
---handler
---@param f fun(obj:any,...):any
---@param obj any
---@return fun(...):any
function std.handler(f, obj)
    return function(...)
        return f(obj, ...)
    end
end

---
---Empty function.
std.fvoid = function()
end

---
---is_callable
---@param f table|fun(...):any
function std.is_callable(f)
    if type(f) == 'function' then
        return true
    elseif type(f) == 'table' then
        return getmetatable(f) and getmetatable(f).__call
    end
end

---
---make_once
---@param f fun(...):any
function std.make_once(f)
    local exe = false
    return function()
        if not exe then
            f()
            exe = true
        end
    end
end

---oparators

std.plus = function(a, b)
    return a + b
end
std.minus = function(a, b)
    return a - b
end
std.negate = function(a)
    return -a
end
std.multiplies = function(a, b)
    return a * b
end
std.divides = function(a, b)
    return a / b
end
std.modulus = function(a, b)
    return a % b
end
std.logical_and = function(a, b)
    return a and b
end
std.logical_or = function(a, b)
    return a or b
end
std.logical_not = function(a)
    return not a
end
std.equal_to = function(a, b)
    return a == b
end
std.not_equal_to = function(a, b)
    return a ~= b
end
std.greater = function(a, b)
    return a > b
end
std.less = function(a, b)
    return a < b
end
std.greater_equal = function(a, b)
    return a >= b
end
std.less_equal = function(a, b)
    return a <= b
end

---
---comparators
---@type table<string,fun(a:any,b:any):boolean>
---You can use following keys to get a comparator:
--->### '=='　'>='　'<='　'~='　'>'　'<'
---You can add '#' to the front of the key to compare length,
---or add 'f' and give a function to compare result of the function.
---Example:
--->`f1 = Function.comparator［'>='］`
--->`f2 = Function.comparator［'f>='］(f)`
std.comparator = {
    ['==']  = std.equal_to,
    ['>=']  = std.greater_equal,
    ['<=']  = std.less_equal,
    ['~=']  = std.not_equal_to,
    ['>']   = std.greater,
    ['<']   = std.less,

    ['#=='] = function(a, b)
        return #a == #b
    end,
    ['#>='] = function(a, b)
        return #a >= #b
    end,
    ['#<='] = function(a, b)
        return #a <= #b
    end,
    ['#~='] = function(a, b)
        return #a ~= #b
    end,
    ['#>']  = function(a, b)
        return #a > #b
    end,
    ['#<']  = function(a, b)
        return #a < #b
    end,

    ['f=='] = function(f)
        return function(a, b)
            return f(a) == f(b)
        end
    end,
    ['f>='] = function(f)
        return function(a, b)
            return f(a) >= f(b)
        end
    end,
    ['f<='] = function(f)
        return function(a, b)
            return f(a) <= f(b)
        end
    end,
    ['f~='] = function(f)
        return function(a, b)
            return f(a) ~= f(b)
        end
    end,
    ['f>']  = function(f)
        return function(a, b)
            return f(a) > f(b)
        end
    end,
    ['f<']  = function(f)
        return function(a, b)
            return f(a) < f(b)
        end
    end,
}

