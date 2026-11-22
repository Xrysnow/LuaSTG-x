---@class lstg.mbg.Event
local M = {}
--local M = class('lstg.mbg.Event')

function M:ctor(idx)
    self.index = assert(idx)
    self.tag = "新事件组"
    self.t = 1
    self.loop = 0
    self.addtime = 0
    self.special = 0
    ---@type mbg.Event[]
    self.events = {}
    ---@type lstg.mbg.EventRead[]
    self.results = {}
end

function M:clone()
    local ret = M(self.index)
    for k, v in pairs(self) do
        ret[k] = table.deepcopy(v)
    end
    return ret
end

local logic_map = { [0] = '且', [1] = '或' }
local op_map = { [0] = '>', [1] = '<', [2] = '=' }

---@param e mbg.Event
function M:addBatchParentEvent(e)
    local EventRead = require('game.mbg.EventRead')
    local Main = require('game.mbg.Main')
    --
    local Condition = e.Condition
    local Action = e.Action
    --
    local key = tostring(Condition.First.LValue)
    local opreator = op_map[Condition.First.Operator] or ''
    local opreator2 = ''
    local collector = ''
    if Condition.Second then
        opreator2 = op_map[Condition.Second.Expr.Operator]
        collector = logic_map[Condition.Second.LogicOp]
    end
    local res, special = 0, 0
    local condition, condition2
    condition = tonumber(Condition.First.RValue) or tostring(Condition.First.RValue)
    if Condition.Second then
        condition2 = tonumber(Condition.Second.Expr.RValue) or tostring(Condition.Second.Expr.RValue)
    end
    -- data action
    if Action.RValue then
        local change
        local contype, contype2
        local changetype, changevalue, changename

        if Action.RValue == '自身' then
            special = 3
        elseif Action.RValue == '自机' then
            special = 4
        end
        local rvalue, rvalue_rand = Action.RValue, nil
        if rvalue:contains('+') then
            rvalue, rvalue_rand = unpack(rvalue:split('+'))
        end
        -- 变化到/增加/减少
        change = Action.Operator
        res = tonumber(tostring(rvalue)) or 0
        contype = Main.conditions[key]
        contype2 = contype
        changetype = Action.TweenFunction
        changevalue = Main.results[tostring(Action.LValue)]
        changename = changevalue
        --
        local eventRead = EventRead()
        eventRead.condition = condition
        --eventRead.result = '' -- not used
        if condition2 then
            eventRead.condition2 = condition2
        end
        eventRead.contype = assert(contype)
        eventRead.contype2 = assert(contype2)
        eventRead.opreator = opreator
        eventRead.opreator2 = opreator2
        eventRead.collector = collector
        eventRead.change = assert(change)
        eventRead.changetype = assert(changetype)
        eventRead.changevalue = assert(changevalue)
        eventRead.changename = assert(changename)
        eventRead.res = res
        eventRead.special = special
        if rvalue_rand then
            eventRead.rand = tonumber(tostring(rvalue_rand)) or 0
        end
        eventRead.times = Action.TweenTime
        if Action.Times then
            eventRead.time = Action.Times
        end
        table.insert(self.results, eventRead)
    elseif Action.Command then
        -- command action
        if Action.Command == '恢复到初始状态' then
            special = 1
        elseif Action.Command == '额外发射' then
            special = 2
        end
        --
        local eventRead = EventRead()
        eventRead.special = special
        eventRead.opreator = opreator
        eventRead.opreator2 = opreator2
        eventRead.condition = condition
        if condition2 then
            eventRead.condition2 = condition2
        end
        eventRead.contype = assert(Main.conditions[key])
        eventRead.contype2 = assert(Main.conditions[key])
        eventRead.collector = collector
        table.insert(self.results, eventRead)
    end
end

---@param e mbg.Event
function M:addBatchChildEvent(e)
    local EventRead = require('game.mbg.EventRead')
    local Main = require('game.mbg.Main')
    --
    local Condition = e.Condition
    local Action = e.Action
    --
    local key = tostring(Condition.First.LValue)
    local opreator = op_map[Condition.First.Operator] or ''
    local opreator2 = ''
    local collector = ''
    if Condition.Second then
        opreator2 = op_map[Condition.Second.Expr.Operator]
        collector = logic_map[Condition.Second.LogicOp]
    end
    local res, special = 0, 0
    local condition, condition2
    condition = tonumber(Condition.First.RValue) or tostring(Condition.First.RValue)
    if Condition.Second then
        condition2 = tonumber(Condition.Second.Expr.RValue) or tostring(Condition.Second.Expr.RValue)
    end
    -- data action
    if Action.RValue then
        local change
        local contype, contype2
        local changetype, changevalue, changename

        if Action.RValue == '自身' then
            special = 3
        elseif Action.RValue == '自机' then
            special = 4
        elseif Action.RValue == '中心' then
            special = 5
            opreator = ''
        end
        local rvalue, rvalue_rand = Action.RValue, nil
        if rvalue:contains('+') then
            rvalue, rvalue_rand = unpack(rvalue:split('+'))
        end
        -- 变化到/增加/减少
        change = Action.Operator
        res = tonumber(tostring(rvalue)) or 0
        contype = Main.conditions2[key]
        contype2 = contype
        changetype = Action.TweenFunction
        changevalue = Main.results2[tostring(Action.LValue)]
        changename = changevalue
        --
        local eventRead = EventRead()
        eventRead.condition = condition
        --eventRead.result = '' -- not used
        if condition2 then
            eventRead.condition2 = condition2
        end
        eventRead.contype = assert(contype)
        eventRead.contype2 = assert(contype2)
        eventRead.opreator = opreator
        eventRead.opreator2 = opreator2
        eventRead.collector = collector
        eventRead.change = assert(change)
        eventRead.changetype = assert(changetype)
        eventRead.changevalue = assert(changevalue)
        eventRead.changename = assert(changename)
        eventRead.res = res
        eventRead.special = special
        if rvalue_rand then
            eventRead.rand = tonumber(tostring(rvalue_rand)) or 0
        end
        eventRead.times = Action.TweenTime
        if Action.Times then
            eventRead.time = Action.Times
        end
        table.insert(self.results, eventRead)
        print(stringify(eventRead))
    elseif Action.Command then
        -- command action
    end
end

function M:addLaserParentEvent(e)
    --TODO
end

function M:addLaserChildEvent(e)
    --TODO
end

function M:addCoverParentEvent(e)
    --TODO
end

function M:addCoverChildEvent(e)
    --TODO
end

local mt = {
    __call = function(_, idx)
        local ret = {}
        M.ctor(ret, idx)
        ret.clone = M.clone
        ret.addBatchParentEvent = M.addBatchParentEvent
        ret.addBatchChildEvent = M.addBatchChildEvent
        ret.addLaserParentEvent = M.addLaserParentEvent
        ret.addLaserChildEvent = M.addLaserChildEvent
        ret.addCoverParentEvent = M.addCoverParentEvent
        ret.addCoverChildEvent = M.addCoverChildEvent
        return ret
    end
}
setmetatable(M, mt)

return M
