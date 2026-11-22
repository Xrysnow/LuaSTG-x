local M = require('xe.node_def._checker')
local CalcParamNum = M.CalcParamNum
local CheckName = M.CheckName
local CheckVName = M.CheckVName
local CheckExpr = M.CheckExpr
local CheckPos = M.CheckPos
local CheckExprOmit = M.CheckExprOmit
local CheckCode = M.CheckCode
local CheckParam = M.CheckParam
local CheckNonBlank = M.CheckNonBlank
local CheckClassName = M.CheckClassName
local IsBlank = M.IsBlank
local CheckResFileInPack = M.CheckResFileInPack
local CheckAnonymous = M.CheckAnonymous
local MakeFullPath = M.MakeFullPath

local eventType
local event_type_dict = { frame = true, render = true, colli = true, kill = true, del = true }

local callbackfunc = {
    { 'Event type', 'event', CheckNonBlank },
    disptype    = {
        en = 'define event callback',
        zh = '定义事件回调',
    },
    default     = {
        expand   = true,
        ['type'] = 'callbackfunc',
        attr     = { 'frame' },
        child    = {
            { ['type'] = 'defaultaction', attr = {} }
        }
    },
    allowparent = { 'enemydefine', 'bossdefine', 'objectdefine', 'laserdefine', 'laserbentdefine', 'bulletdefine', 'rebounderdefine' },
    totext      = function(nodedata)
        return "on " .. nodedata.attr[1]
    end,
    tohead      = function(nodedata)
        eventType = nodedata.attr[1]
        if nodedata.attr[1] ~= 'colli' then
            return string.format("_editor_class[%q].%s = function(self)\n", M.className, nodedata.attr[1])
        else
            return string.format("_editor_class[%q].colli = function(self, other)\n", M.className)
        end
    end,
    tofoot      = function(nodedata)
        return "end\n"
    end,
    check       = function(nodedata)
        if not event_type_dict[nodedata.attr[1]] then
            return string.format("unknown event type %q", nodedata.attr[1])
        end
    end,
}
local defaultaction = {
    disptype    = {
        en = 'do event callback',
        zh = '执行事件回调',
    },
    allowchild  = {},
    allowparent = { 'callbackfunc' },
    totext      = function(nodedata)
        return "do default action"
    end,
    tohead      = function(nodedata)
        if eventType == 'colli' then
            return "self.class.base.colli(self, other)\n"
        else
            return string.format("self.class.base.%s(self)\n", eventType)
        end
    end
}
local _def = {
    callbackfunc  = callbackfunc,
    defaultaction = defaultaction,
}
for k, v in pairs(_def) do
    require('xe.node_def._def').DefineNode(k, v)
end
