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

local laserbentdefine = {
    { 'Type name', 'typename', CheckClassName },
    disptype    = {
        en = 'define bent laser',
        zh = '定义曲线激光',
    },
    editfirst   = true,
    allowparent = { 'root', 'folder' },
    allowchild  = { 'callbackfunc' },
    totext      = function(nodedata)
        return string.format("define bent laser type %q", nodedata.attr[1])
    end,
    depth       = 0,
    watch       = 'laserbentdefine',
    default     = {
        ["attr"]   = {
            [1] = "",
        },
        ["type"]   = "laserbentdefine",
        ["expand"] = true,
        ["child"]  = {
            [1] = {
                ["attr"]   = { '', 'COLOR_RED', '32', '8', '4', '0' },
                ["type"]   = "laserbentinit",
                ["expand"] = true,
                ["child"]  = {
                    [1] = {
                        ["attr"] = {},
                        ["type"] = "task",
                    },
                },
            },
        },
    },
    tohead      = function(nodedata)
        M.className = nodedata.attr[1]
        M.difficulty = string.match(nodedata.attr[1], '^.+:(.+)$')
        return string.format("_editor_class[%q] = Class(laser_bent)\n", M.className)
    end,
    tofoot      = function(nodedata)
        M.difficulty = nil
        return ''
    end,
    check       = function(nodedata)
        M.difficulty = string.match(nodedata.attr[1], '^.+:(.+)$')
    end,
    checkafter  = function(nodedata)
        M.difficulty = nil
    end,
}
local laserbentinit_head_fmt = [[_editor_class[%q].init = function(self, _x, _y, %s)
laser_bent.init(self, %s, _x, _y, %s, %s, %s, %s)
]]
local laserbentinit = {
    { 'Parameter list', 'any', CheckParam },
    { 'Color', 'color', CheckExpr },
    { 'Length (in frames)', 'any', CheckExpr },
    { 'Width', 'any', CheckExpr },
    { 'Sampling', 'any', CheckExpr },
    { 'Node', 'any', CheckExpr },
    disptype     = {
        en = 'on create bent laser',
        zh = '初始化曲线激光',
    },
    allowparent  = {},
    forbiddelete = true,
    totext       = function(nodedata)
        return string.format("on create: (%s)", nodedata.attr[1])
    end,
    tohead       = function(nodedata)
        local p
        if IsBlank(nodedata.attr[1]) then
            p = '_'
        else
            p = nodedata.attr[1]
        end
        local attr = {}
        for i = 2, 6 do
            attr[i] = nodedata.attr[i]
        end
        return string.format(
                laserbentinit_head_fmt,
                M.className, p, unpack(attr, 2, 6))
    end,
    tofoot       = function(nodedata)
        return "end\n"
    end,
}
local laserbentcreate = {
    { 'Type name', 'selecttype', CheckNonBlank },
    { 'Position', 'pos', CheckPos },
    { 'Parameter', 'param', CheckExprOmit },
    disptype     = {
        en = 'create bent laser',
        zh = '创建曲线激光',
    },
    editfirst    = true,
    default      = { ["type"] = 'laserbentcreate', attr = { '', 'self.x, self.y', '' } },
    forbidparent = { 'root', 'folder' },
    allowchild   = {},
    totext       = function(nodedata)
        return string.format("create bent laser of type %q with parameter %s", nodedata.attr[1], nodedata.attr[3])
    end,
    tohead       = function(nodedata)
        local p
        if IsBlank(nodedata.attr[3]) then
            p = "_"
        else
            p = nodedata.attr[3]
        end
        return string.format("last=New(_editor_class[%q],%s,%s)\n", nodedata.fullclassname, nodedata.attr[2], p)
    end,
    check        = function(nodedata)
        local class
        if M.difficulty and M.watchDict.laserbentdefine[nodedata.attr[1] .. ':' .. M.difficulty] then
            class = nodedata.attr[1] .. ':' .. M.difficulty
        elseif M.watchDict.laserbentdefine[nodedata.attr[1]] then
            class = nodedata.attr[1]
        else
            return string.format('bent laser type %q does not exist', nodedata.attr[1])
        end
        if M.paramNumDict[class] ~= CalcParamNum(nodedata.attr[3]) then
            return "number of parameter is incorrect"
        end
        nodedata.fullclassname = class
    end,
}
local _def = {
    laserbentdefine = laserbentdefine,
    laserbentinit   = laserbentinit,
    laserbentcreate = laserbentcreate,
}

for k, v in pairs(_def) do
    require('xe.node_def._def').DefineNode(k, v)
end
