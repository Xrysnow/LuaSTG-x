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
--[[
local rebounderdefine = {
    { 'Type name', 'typename', CheckClassName },
    disptype = {
		en = 'define rebounder',
		zh = '',
	},
    editfirst   = true,
    allowparent = { 'root', 'folder' },
    allowchild  = { 'callbackfunc' },
    totext      = function(nodedata)
        return string.format("define rebounder type %q", nodedata.attr[1])
    end,
    depth       = 0,
    watch       = 'rebounder',
    default     = {
        ["attr"]   = { "" },
        ["type"]   = "rebounderdefine",
        ["expand"] = true,
        ["child"]  = {
            [1] = {
                ["attr"] = { "" },
                ["type"] = "rebounderinit",
            },
        },
    },
    tohead      = function(nodedata)
        M.className = string.match(nodedata.attr[1], '^(.+):.+$') or nodedata.attr[1]
        return string.format("_editor_class[%q] = Class(rebounder)\n", M.className)
    end,
    tofoot      = function(nodedata)
        return ''
    end,
}
local rebounderinit_head_fmt = [[_editor_class[%q].init = function(self, _x, _y, _length, _angle, %s)
    rebounder.init(self, _x, _y, _length, _angle)
]]
local rebounderinit = {
    { 'Parameter list', 'any', CheckParam },
    disptype = {
		en = 'on create rebounder',
		zh = '',
	},
    allowparent  = {},
    forbiddelete = true,
    totext       = function(nodedata)
        return string.format("on create: (%s)", nodedata.attr[1])
    end,
    tohead       = function(nodedata)
        local p
        if IsBlank(nodedata.attr[1]) then
            p = "_"
        else
            p = nodedata.attr[1]
        end
        return string.format(rebounderinit_head_fmt,
                             M.className, p, nodedata.attr[2], nodedata.attr[3], nodedata.attr[4], nodedata.attr[5])
    end,
    tofoot       = function(nodedata)
        return "end\n"
    end,
}
local reboundercreate = {
    { 'Type name', 'selecttype', CheckNonBlank },
    { 'Position', 'pos', CheckPos },
    { 'Parameter', 'param', CheckExprOmit },
    { 'Length', 'any', CheckExpr },
    { 'Angle', 'any', CheckExpr },
    disptype = {
		en = 'create rebounder',
		zh = '',
	},
    editfirst    = true,
    default      = { ["type"] = 'reboundercreate', attr = { '', '0,0', '', '128', '0' } },
    forbidparent = { 'root', 'folder' },
    allowchild   = {},
    totext       = function(nodedata)
        return string.format("create rebounder of type %q at (%s) with parameter %s", nodedata.attr[1], nodedata.attr[2], nodedata.attr[3])
    end,
    tohead       = function(nodedata)
        local p
        if IsBlank(nodedata.attr[3]) then
            p = "_"
        else
            p = nodedata.attr[3]
        end
        return string.format("last = New(_editor_class[%q], %s, %s, %s, %s)\n", nodedata.fullclassname,
                             nodedata.attr[2], nodedata.attr[4], nodedata.attr[5], p)
    end,
    check        = function(nodedata)
        local class
        if M.watchDict.rebounder[nodedata.attr[1]] then
            class = nodedata.attr[1]
        else
            return string.format('rebounder type %q does not exist', nodedata.attr[1])
        end
        if M.paramNumDict[class] ~= CalcParamNum(nodedata.attr[3]) then
            return "number of parameter is incorrect"
        end
        nodedata.fullclassname = class
    end,
}
local simplerebounder = {
    { "Position", "any", CheckPos },
    { "Length", 'any', CheckExpr },
    { "Angle", "any", CheckExpr },
    disptype     = "create a simple rebounder",
    default      = { ["type"] = "simplerebounder", attr = { "0,0", "128", "0" } },
    forbidparent = { "root", "folder" },
    allowchild   = {},
    totext       = function(nodedata)
        return string.format("create a simple rebounder at (%s), length of %s, angle of %s",
                             nodedata.attr[1], nodedata.attr[2], nodedata.attr[3])
    end,
    tohead       = function(nodedata)
        return string.format("last = New(rebounder, %s)\n", table.concat(nodedata.attr, ", "))
    end
}
local _def = {
    rebounderdefine = rebounderdefine,
    rebounderinit   = rebounderinit,
    reboundercreate = reboundercreate,
    simplerebounder = simplerebounder,
}
for k, v in pairs(_def) do
    require('xe.node_def._def').DefineNode(k, v)
end
--]]
