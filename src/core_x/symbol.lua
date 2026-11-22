---@class lstg.symbol
local sym = {}

lstg_sym.Operator:registBase()

local sym_op = require('core_x.symbol_op')
for k, v in pairs(sym_op) do
    sym[k] = v
end
sym.tonumber = sym.toNumber
sym.tobool = sym.toBool

local varType = {
    Number  = 0,
    Boolean = 1,
    String  = 2,
}

local mt = {
    __add = function(op1, op2)
        return sym.add(op1, op2)
    end,
    __sub = function(op1, op2)
        return sym.sub(op1, op2)
    end,
    __mul = function(op1, op2)
        return sym.mul(op1, op2)
    end,
    __div = function(op1, op2)
        return sym.div(op1, op2)
    end,

    __mod = function(op1, op2)
        return sym.fmod(op1, op2)
    end,
    __pow = function(op1, op2)
        return sym.pow(op1, op2)
    end,
    __unm = function(op1)
        return sym.sub(sym.number(0), op1)
    end,

    __eq  = function(op1, op2)
        return sym.eq(op1, op2)
    end,
    __le  = function(op1, op2)
        SystemLog(string.format('le of %s, %s', tostring(op1), tostring(op2)))
        return sym.le(op1, op2)
    end,
    __lt  = function(op1, op2)
        SystemLog(string.format('lt of %s, %s', tostring(op1), tostring(op2)))
        return sym.lt(op1, op2)
    end,
}

for _, vv in ipairs({ 'Operand', 'Number', 'Boolean', 'Operator', 'Assigment' }) do
    for k, v in pairs(mt) do
        lstg_sym[vv][k] = v
    end
end

local _num_op = {
    'add',
    'sub',
    'mul',
    'div',
}

local _attr = {
    x      = 0,
    y      = 1,
    dx     = 2,
    dy     = 3,
    rot    = 4,
    omiga  = 5,
    timer  = 6,
    vx     = 7,
    vy     = 8,
    ax     = 9,
    ay     = 10,
    layer  = 11,
    group  = 12,
    hide   = 13,
    bound  = 14,
    navi   = 15,
    colli  = 16,
    status = 17,
    hscale = 18,
    vscale = 19,
    class  = 20,
    a      = 21,
    b      = 22,
    rect   = 23,
    img    = 24,
    ani    = 25,
}
local _attr_number = {
    x      = 0,
    y      = 1,
    dx     = 2,
    dy     = 3,
    rot    = 4,
    omiga  = 5,
    timer  = 6,
    vx     = 7,
    vy     = 8,
    ax     = 9,
    ay     = 10,
    layer  = 11,
    group  = 12,
    hscale = 18,
    vscale = 19,
    a      = 21,
    b      = 22,
    ani    = 25,
}
local _attr_bool = {
    hide  = 13,
    bound = 14,
    navi  = 15,
    colli = 16,
}

function sym.getFeildNumber(k)
    assert(type(k) == 'string')
    return lstg_sym.Number:createWithObjProperty(k)
end

function sym.getFeildBoolean(k)
    assert(type(k) == 'string')
    return lstg_sym.Boolean:createWithObjProperty(k)
end

local obj_mt = {
    __index    = function(self, k)
        local ret
        if _attr_number[k] then
            ret = sym.getFeildNumber(k)
        elseif _attr_bool[k] then
            ret = sym.getFeildBoolean(k)
        else
            --error('')
            ret = sym.getFeildNumber(k)
        end
        --Print('index got '..tostring(ret))
        return ret
    end,
    __newindex = function(self, k, v)
        local tp = type(v)
        if tp == 'number' then
            v = sym.toNumber(v)
        elseif tp == 'boolean' then
            v = sym.toBool(v)
        end
        assert(type(v) == 'userdata')
        local s = lstg_sym.Assigment:createWithObjProperty(k, v)
        self.__blk:push(s)
    end,
}

local env = {}

for k, v in pairs(sym) do
    env[k] = v
end

for i, v in ipairs({ 'sin', 'cos', 'tan' }) do
    env[v] = function(op)
        return sym[v](sym.deg2rad(op))
    end
end

for i, v in ipairs({ 'asin', 'acos', 'atan' }) do
    env[v] = function(op)
        return sym.rad2deg(sym[v](op))
    end
end

setmetatable(env, { __index = _G })

local _curr_fun
local _curr_blk
local _last_local
local _last_locals = {}
local _in_setlocal = false
local _last_set = {}
local _last_line

local function trace_local(event, line)
    local fun = debug.getinfo(2, 'f').func
    if fun ~= _curr_fun or _in_setlocal then
        return
    end
    if _last_line ~= line then
        _last_line = line
        _last_set = {}
    end
    --Print(string.format('------ line %d', line))
    local lcs = {}
    local lcv = {}
    for i = 1, 255 do
        local name, v = debug.getlocal(2, i)
        if not name then
            break
        end
        if name:sub(1, 1) ~= '(' and name ~= 'self' then
            table.insert(lcs, name)
            lcv[name] = { v, i }
        end
    end
    --local last = lcs[#lcs]
    --if last and last ~= _last_local then
    --    _last_local = last
    --    Print(string.format('new local: %s = %s', last, tostring(lcv[last][0])))
    --end
    --Print(stringify(lcv))
    local new_lcv = {}
    for k, vv in pairs(lcv) do
        new_lcv[k] = vv
        local v = vv[1]
        local i = vv[2]
        if not _last_set[i] then
            local lst = _last_locals[k]
            if not lst or tostring(v) ~= tostring(lst[1]) then
                --Print(string.format('local %s has new value: %s to %s', k, tostring(v), tostring(lst and lst[1])))
                local tp = type(v)
                if tp == 'number' then
                    v = sym.toNumber(v)
                elseif tp == 'boolean' then
                    v = sym.toBool(v)
                elseif tp == 'userdata' then
                else
                    error('wrong type: ' .. tp)
                end
                local a = lstg_sym.Assigment:create(v)
                assert(a, string.format('rvalue type=%d, cls=%s', v:getType(), tostring(v['.classname'])))
                _in_setlocal = true
                --Print('set local to ' .. tostring(a))
                debug.setlocal(2, i, a)
                _in_setlocal = false
                _curr_blk:push(a)
                new_lcv[k] = { a, i }
                _last_set[i] = true
            end
        end
    end
    --Print('set local finished')
    _last_locals = new_lcv
end

function sym.compile(fun)
    _last_local = nil
    _last_locals = {}
    _last_line = nil
    _curr_fun = fun
    local blk = lstg_sym.Block:create()
    assert(blk)
    _curr_blk = blk
    blk:retain()
    local obj = {
        __blk = blk,
    }
    setmetatable(obj, obj_mt)

    local n = debug.getinfo(fun, 'u').nups
    assert(n)
    local ups = {}
    for i = 1, n do
        local name, uv = debug.getupvalue(fun, i)
        --Print(tostring(name))
        --Print(tostring(uv))
        table.insert(ups, uv)
        if env[name] then
            debug.setupvalue(fun, i, env[name])
        end
    end

    local ret
    setfenv(fun, env)
    debug.sethook(trace_local, "l")
    ret = { fun(obj) }
    debug.sethook()

    for i = 1, n do
        debug.setupvalue(fun, i, ups[i])
    end
    setfenv(fun, _G)
    for i, v in ipairs(ret) do
        blk:addOutputNode(v)
    end
    _curr_blk = nil
    _curr_fun = nil
    return blk
end

local function __()
    _G.cond = sym.cond
    _G = sym
end



return sym
