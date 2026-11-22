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

local laserdefine = {
    { 'Type name', 'typename', CheckClassName },
    disptype    = {
        en = 'define laser',
        zh = '定义激光',
    },
    editfirst   = true,
    allowparent = { 'root', 'folder' },
    allowchild  = { 'callbackfunc' },
    totext      = function(nodedata)
        return string.format("define laser type %q", nodedata.attr[1])
    end,
    depth       = 0,
    watch       = 'laserdefine',
    default     = {
        ["attr"]   = {
            [1] = "",
        },
        ["type"]   = "laserdefine",
        ["expand"] = true,
        ["child"]  = {
            [1] = {
                ["attr"]   = { '', 'COLOR_RED', '64', '32', '64', '8', '0', '0' },
                ["type"]   = "laserinit",
                ["expand"] = true,
                ["child"]  = {
                    [1] = {
                        ["attr"]   = {
                        },
                        ["type"]   = "task",
                        ["expand"] = true,
                        ["child"]  = {
                            [1] = { ['type'] = 'laserturnon', attr = { '30', 'true', 'true' } },
                        },
                    },
                },
            },
        },
    },
    tohead      = function(nodedata)
        M.className = nodedata.attr[1]
        M.difficulty = string.match(nodedata.attr[1], '^.+:(.+)$')
        return string.format("_editor_class[%q] = Class(laser)\n", M.className)
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
local laserinit_head_fmt = [[_editor_class[%q].init = function(self, _x, _y, %s)
laser.init(self, %s, _x, _y, 0, %s, %s, %s, %s, %s, %s)
]]
local laserinit = {
    { 'Parameter list', 'any', CheckParam },
    { 'Color', 'color', CheckExpr },
    { 'Head length', 'any', CheckExpr },
    { 'Body length', 'any', CheckExpr },
    { 'Tail length', 'any', CheckExpr },
    { 'Width', 'any', CheckExpr },
    { 'Node size', 'any', CheckExpr },
    { 'Head', 'any', CheckExpr },
    disptype     = {
        en = 'on create laser',
        zh = '初始化激光',
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
        return string.format(laserinit_head_fmt, M.className, p, nodedata.attr[2], nodedata.attr[3], nodedata.attr[4], nodedata.attr[5], nodedata.attr[6], nodedata.attr[7], nodedata.attr[8])
    end,
    tofoot       = function(nodedata)
        return "end\n"
    end,
}
local lasercreate = {
    { 'Type name', 'selecttype', CheckNonBlank },
    { 'Position', 'pos', CheckPos },
    { 'Parameter', 'param', CheckExprOmit },
    disptype     = {
        en = 'create laser',
        zh = '创建激光',
    },
    editfirst    = true,
    default      = { ["type"] = 'lasercreate', attr = { '', 'self.x, self.y', '' } },
    forbidparent = { 'root', 'folder' },
    allowchild   = {},
    totext       = function(nodedata)
        return string.format("create laser of type %q with parameter %s", nodedata.attr[1], nodedata.attr[3])
    end,
    tohead       = function(nodedata)
        local p
        if IsBlank(nodedata.attr[3]) then
            p = "_"
        else
            p = nodedata.attr[3]
        end
        return string.format("last = New(_editor_class[%q], %s, %s)\n", nodedata.fullclassname, nodedata.attr[2], p)
    end,
    check        = function(nodedata)
        local class
        if M.difficulty and M.watchDict.laserdefine[nodedata.attr[1] .. ':' .. M.difficulty] then
            class = nodedata.attr[1] .. ':' .. M.difficulty
        elseif M.watchDict.laserdefine[nodedata.attr[1]] then
            class = nodedata.attr[1]
        else
            return string.format('laser type %q does not exist', nodedata.attr[1])
        end
        if M.paramNumDict[class] ~= CalcParamNum(nodedata.attr[3]) then
            return "number of parameter is incorrect"
        end
        nodedata.fullclassname = class
    end,
}
local laserturnon = {
    { 'Time (frames)', 'any', CheckExpr },
    { 'Play sound effect', 'bool', CheckExpr },
    { 'wait in this task', 'bool', CheckExpr },
    disptype     = {
        en = 'turn on laser',
        zh = '开启激光',
    },
    needancestor = { 'laserdefine', 'lasershooter' },
    default      = { ['type'] = 'laserturnon', attr = { '30', 'true' } },
    totext       = function(nodedata)
        return string.format("turn on in %s frame(s)", nodedata.attr[1])
    end,
    tohead       = function(nodedata)
        return string.format("laser._TurnOn(self, %s, %s, %s)\n", nodedata.attr[1], nodedata.attr[2], nodedata.attr[3])
    end,
}
local laserturnoff = {
    { 'Time (frames)', 'any', CheckExpr },
    { 'wait in this task', 'bool', CheckExpr },
    disptype     = {
        en = 'turn off laser',
        zh = '关闭激光',
    },
    needancestor = { 'laserdefine', 'lasershooter' },
    default      = { ['type'] = 'laserturnoff', attr = { '30' } },
    totext       = function(nodedata)
        return string.format("turn off in %s frame(s)", nodedata.attr[1])
    end,
    tohead       = function(nodedata)
        return string.format("laser._TurnOff(self, %s, %s)\n", nodedata.attr[1], nodedata.attr[2])
    end,
}
local laserturnhalfon = {
    { 'Time (frames)', 'any', CheckExpr },
    { 'wait in this task', 'bool', CheckExpr },
    disptype     = {
        en = 'turn half on laser',
        zh = '半开激光',
    },
    needancestor = { 'laserdefine', 'lasershooter' },
    default      = { ['type'] = 'laserturnhalfon', attr = { '30' } },
    totext       = function(nodedata)
        return string.format("turn half on in %s frame(s)", nodedata.attr[1])
    end,
    tohead       = function(nodedata)
        return string.format("laser._TurnHalfOn(self, %s, %s)\n", nodedata.attr[1], nodedata.attr[2])
    end,
}
local lasergrow = {
    { 'Time (frames)', 'any', CheckExpr },
    { 'Play sound effect', 'bool', CheckExpr },
    { 'wait in this task', 'bool', CheckExpr },
    disptype     = {
        en = 'grow laser',
        zh = '伸展激光',
    },
    needancestor = { 'laserdefine', 'lasershooter' },
    default      = { ['type'] = 'lasergrow', attr = { '30', 'true' } },
    totext       = function(nodedata)
        return string.format("grow in %s frame(s)", nodedata.attr[1])
    end,
    tohead       = function(nodedata)
        return string.format("laser.grow(self, %s, %s, %s)\n", nodedata.attr[1], nodedata.attr[2], nodedata.attr[3])
    end,
}
local laserchange = {
    { 'Laser', 'any', CheckExpr },
    { 'Image', 'any', CheckExpr },
    { 'Color', 'color', CheckExpr },
    disptype     = {
        en = 'change image and color of laser',
        zh = '更改激光类型与颜色',
    },
    forbidparent = { 'folder', 'root' },
    allowchild   = {},
    default      = { ['type'] = 'laserchange', attr = { 'self', '1', 'orginal' } },
    totext       = function(nodedata)
        return string.format("set %s's style to laser%s and color to %s", nodedata.attr[1], nodedata.attr[2], nodedata.attr[3])
    end,
    tohead       = function(nodedata)
        local ret
        if nodedata.attr[3] == 'original' then
            ret = ""
        else
            ret = "," .. nodedata.attr[3]
        end
        return string.format("laser.ChangeImage(%s, %s%s)\n", nodedata.attr[1], nodedata.attr[2], ret)
    end,
}
local _def = {
    laserdefine     = laserdefine,
    laserinit       = laserinit,
    lasercreate     = lasercreate,
    laserturnon     = laserturnon,
    laserturnoff    = laserturnoff,
    laserturnhalfon = laserturnhalfon,
    lasergrow       = lasergrow,
    laserchange     = laserchange,
}
for k, v in pairs(_def) do
    require('xe.node_def._def').DefineNode(k, v)
end
