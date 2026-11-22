---@type lstg.symbol
local sym = {}

local Number = lstg_sym.Number
local Bool = lstg_sym.Boolean
--local varType = {
--    Number  = 0,
--    Boolean = 1,
--    String  = 2,
--}

local op = {}
setmetatable(op, {
    __index = function(t, k)
        local operator = lstg_sym.Operator:create(k)
        assert(operator, "can't find operator " .. k)
        return function(...)
            local args = { ... }
            for i, v in ipairs(args) do
                operator:addInput(v)
            end
            assert(operator:check(), 'wrong arg number for ' .. k)
            return operator
        end
    end
})

function sym.number(v)
    v = tonumber(v)
    assert(type(v) == 'number')
    return Number:createWithValue(v)
end

function sym.bool(v)
    assert(type(v) == 'boolean')
    return Bool:createWithValue(v)
end

function sym.toNumber(x)
    local t = type(x)
    if t == 'number' then
        return Number:createWithValue(x)
    elseif t == 'userdata' then
        --if x:getType() == varType.Number then
        return x
        --end
    end
    error('wrong type: ' .. t)
end

function sym.toBool(x)
    local t = type(x)
    if t == 'boolean' then
        return Bool:createWithValue(x)
    elseif t == 'userdata' then
        --if x:getType() == varType.Number then
        return x
        --end
    end
    error('wrong type: ' .. t)
end

local toNumber = sym.toNumber
local toBool = sym.toBool

function sym.nearbyint(x)
    return op.nearbyint(toNumber(x))
end
function sym.cbrt(x)
    return op.cbrt(toNumber(x))
end
function sym.hypot(x1, x2)
    return op.hypot(toNumber(x1), toNumber(x2))
end
function sym.tan(x)
    return op.tan(toNumber(x))
end
function sym.eq(x1, x2)
    return op.eq(toNumber(x1), toNumber(x2))
end
function sym.asin(x)
    return op.asin(toNumber(x))
end
function sym.le(x1, x2)
    return op.le(toNumber(x1), toNumber(x2))
end
function sym.sub(x1, x2)
    return op.sub(toNumber(x1), toNumber(x2))
end
function sym.atan2(x1, x2)
    return op.atan2(toNumber(x1), toNumber(x2))
end
function sym.exp2(x)
    return op.exp2(toNumber(x))
end
function sym.add(x1, x2)
    return op.add(toNumber(x1), toNumber(x2))
end
function sym.sqrt(x)
    return op.sqrt(toNumber(x))
end
function sym.lt(x1, x2)
    return op.lt(toNumber(x1), toNumber(x2))
end
function sym.abs(x)
    return op.abs(toNumber(x))
end
function sym.pow(x1, x2)
    return op.pow(toNumber(x1), toNumber(x2))
end
function sym.mul(x1, x2)
    return op.mul(toNumber(x1), toNumber(x2))
end
function sym.trunc(x)
    return op.trunc(toNumber(x))
end
function sym.log10(x)
    return op.log10(toNumber(x))
end
function sym.sin(x)
    return op.sin(toNumber(x))
end
function sym.log2(x)
    return op.log2(toNumber(x))
end
function sym.fmod(x1, x2)
    return op.fmod(toNumber(x1), toNumber(x2))
end
function sym.atan(x)
    return op.atan(toNumber(x))
end
function sym.cos(x)
    return op.cos(toNumber(x))
end
function sym.ceil(x)
    return op.ceil(toNumber(x))
end
function sym.remainder(x1, x2)
    return op.remainder(toNumber(x1), toNumber(x2))
end
function sym.acos(x)
    return op.acos(toNumber(x))
end
function sym.log(x)
    return op.log(toNumber(x))
end
function sym.expm1(x)
    return op.expm1(toNumber(x))
end
function sym.floor(x)
    return op.floor(toNumber(x))
end
function sym.exp(x)
    return op.exp(toNumber(x))
end
function sym.div(x1, x2)
    return op.div(toNumber(x1), toNumber(x2))
end
function sym.log1p(x)
    return op.log1p(toNumber(x))
end
function sym.round(x)
    return op.round(toNumber(x))
end

function sym.deg2rad(x)
    return op.mul(x, sym.number(math.pi / 180))
end

function sym.rad2deg(x)
    return op.mul(x, sym.number(180 / math.pi))
end

function sym.And(x1, x2)
    return op['and'](toBool(x1), toBool(x2))
end

function sym.Or(x1, x2)
    return op['or'](toBool(x1), toBool(x2))
end

function sym.Not(x)
    return op['not'](toBool(x))
end

function sym.cond(x1, x2, x3)
    return op.cond(toBool(x1), toNumber(x2), toNumber(x3))
end

function sym.between(x, lo, hi)
    return sym.And(sym.lt(x, hi), sym.lt(lo, x))
end

return sym
