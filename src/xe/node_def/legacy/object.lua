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

local objectdefine = {
    { 'Type name', 'typename', CheckClassName },
    disptype    = {
        en = 'define object',
        zh = '定义object',
    },
    editfirst   = true,
    allowparent = { 'root', 'folder' },
    allowchild  = { 'callbackfunc' },
    totext      = function(nodedata)
        return string.format("define object type %q", nodedata.attr[1])
    end,
    depth       = 0,
    watch       = 'objectdefine',
    default     = {
        ["attr"]   = {
            [1] = "",
        },
        ["type"]   = "objectdefine",
        ["expand"] = true,
        ["child"]  = {
            [1] = {
                ["attr"]   = { '', 'leaf', 'LAYER_ENEMY_BULLET', 'GROUP_ENEMY_BULLET', 'false', 'true', 'false', '10', 'true' },
                ["type"]   = "objectinit",
                ["expand"] = true,
                ["child"]  = {
                    [1] = {
                        ["attr"]  = {
                        },
                        ["type"]  = "task",
                        ["child"] = {
                        },
                    },
                },
            },
        },
    },
    tohead      = function(nodedata)
        M.className = nodedata.attr[1]
        M.difficulty = string.match(nodedata.attr[1], '^.+:(.+)$')
        return string.format("_editor_class[%q] = Class(_object)\n", M.className)
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
local objectinit_head_fmt = [[_editor_class[%q].init = function(self, _x, _y, %s)
self.x, self.y = _x, _y
self.img = %q
self.layer = %s
self.group = %s
self.hide = %s
self.bound = %s
self.navi = %s
self.hp = %s
self.maxhp = %s
self.colli = %s
self._servants = {}
self._blend, self._a, self._r, self._g, self._b = '', 255, 255, 255, 255
]]
local objectinit = {
    { 'Parameter list', 'any', CheckParam },
    { 'Image', 'image', CheckNonBlank },
    { 'Layer', 'layer', CheckExpr },
    { 'Group', 'group', CheckExpr },
    { 'Hide', 'bool', CheckExpr },
    { 'Bound', 'bool', CheckExpr },
    { 'Auto rotation', 'bool', CheckExpr },
    { 'Hit point', 'any', CheckExpr },
    { 'Collision', 'bool', CheckExpr },
    disptype     = {
        en = 'on create object',
        zh = '初始化object',
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
        return string.format(
                objectinit_head_fmt,
                M.className, p, nodedata.attr[2], nodedata.attr[3], nodedata.attr[4], nodedata.attr[5], nodedata.attr[6], nodedata.attr[7], nodedata.attr[8], nodedata.attr[8], nodedata.attr[9])
    end,
    tofoot       = function(nodedata)
        return "end\n"
    end,
    --[[check=function(nodedata)
        if not (M.watchDict.image[nodedata.attr[2] ] or nodedata.attr[2]=='leaf') then return string.format('image %q does not exist',nodedata.attr[2]) end
    end,--]]
}
local objectcreate = {
    { 'Type name', 'selecttype', CheckNonBlank },
    { 'Position', 'pos', CheckPos },
    { 'Parameter', 'param', CheckExprOmit },
    disptype     = {
        en = 'create object',
        zh = '创建object',
    },
    editfirst    = true,
    default      = { ["type"] = 'objectcreate', attr = { '', 'self.x, self.y', '' } },
    forbidparent = { 'root', 'folder' },
    allowchild   = {},
    totext       = function(nodedata)
        return string.format("create object of type %q at (%s) with parameter %s", nodedata.attr[1], nodedata.attr[2], nodedata.attr[3])
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
        if M.difficulty and M.watchDict.objectdefine[nodedata.attr[1] .. ':' .. M.difficulty] then
            class = nodedata.attr[1] .. ':' .. M.difficulty
        elseif M.watchDict.objectdefine[nodedata.attr[1]] then
            class = nodedata.attr[1]
        else
            return string.format('object type %q does not exist', nodedata.attr[1])
        end
        if M.paramNumDict[class] ~= CalcParamNum(nodedata.attr[3]) then
            return ("number of parameter is incorrect, expect %d, but got %d"):format(
                    M.paramNumDict[class], CalcParamNum(nodedata.attr[3]))
        end
        nodedata.fullclassname = class
    end,
}
local _def = {
    objectdefine = objectdefine,
    objectinit   = objectinit,
    objectcreate = objectcreate,
}
for k, v in pairs(_def) do
    require('xe.node_def._def').DefineNode(k, v)
end
