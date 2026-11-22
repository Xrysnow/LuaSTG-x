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

local bulletdefine = {
    { 'Type name', 'typename', CheckClassName },
    disptype    = {
        en = 'define bullet',
        zh = '定义子弹',
    },
    editfirst   = true,
    allowparent = { 'root', 'folder' },
    allowchild  = { 'callbackfunc' },
    totext      = function(nodedata)
        return string.format("define bullet type %q", nodedata.attr[1])
    end,
    depth       = 0,
    watch       = 'bulletdefine',
    default     = {
        ["attr"]   = { "" },
        ["type"]   = "bulletdefine",
        ["expand"] = true,
        ["child"]  = {
            [1] = {
                ["attr"] = { "", "arrow_big", "COLOR_RED", "true", "true" },
                ["type"] = "bulletinit",
            },
        },
    },
    tohead      = function(nodedata)
        M.className = nodedata.attr[1]
        M.difficulty = string.match(nodedata.attr[1], '^.+:(.+)$')
        return string.format("_editor_class[%q] = Class(bullet)\n", M.className)
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
local bulletinit_head_fmt = [[_editor_class[%q].init = function(self, _x, _y, %s)
bullet.init(self, %s, %s, %s, %s)
self.x, self.y=_x, _y
]]
local bulletinit = {
    { 'Parameter list', 'any', CheckParam },
    { 'Style', 'bulletstyle', CheckExpr },
    { 'Color', 'color', CheckExpr },
    { 'Stay on create', 'bool', CheckExpr },
    { 'Destroyable', 'bool', CheckExpr },
    disptype     = {
        en = 'on create bullet',
        zh = '子弹初始化',
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
        local attr = {}
        for i = 2, 5 do
            attr[i] = nodedata.attr[i]
        end
        return string.format(
                bulletinit_head_fmt,
                M.className, p, unpack(attr, 2, 5))
    end,
    tofoot       = function(nodedata)
        return "end\n"
    end,
}
local bulletcreate = {
    { 'Type name', 'selecttype', CheckNonBlank },
    { 'Position', 'pos', CheckPos },
    { 'Parameter', 'param', CheckExprOmit },
    disptype     = {
        en = 'create bullet',
        zh = '创建子弹',
    },
    editfirst    = true,
    default      = { ["type"] = 'bulletcreate', attr = { '', 'self.x,self.y', '' } },
    forbidparent = { 'root', 'folder' },
    allowchild   = {},
    totext       = function(nodedata)
        local attr = {}
        for i = 1, 3 do
            attr[i] = nodedata.attr[i]
        end
        return string.format("create bullet of type %q at (%s) with parameter %s", unpack(attr, 1, 3))
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
        if M.difficulty and M.watchDict.bulletdefine[nodedata.attr[1] .. ':' .. M.difficulty] then
            class = nodedata.attr[1] .. ':' .. M.difficulty
        elseif M.watchDict.bulletdefine[nodedata.attr[1]] then
            class = nodedata.attr[1]
        else
            return string.format('bullet type %q does not exist', nodedata.attr[1])
        end
        if M.paramNumDict[class] ~= CalcParamNum(nodedata.attr[3]) then
            return "number of parameter is incorrect"
        end
        nodedata.fullclassname = class
    end,
}
local bulletcreatestraight = {
    { 'Style', 'bulletstyle', CheckExpr },
    { 'Color', 'color', CheckExpr },
    { 'Position', 'pos', CheckPos },
    { 'Velocity', 'any', CheckExpr },
    { 'Angle', 'any', CheckExpr },
    { 'Aim to player', 'bool', CheckExpr },
    { 'Rotation Velocity', 'any', CheckExpr },
    { 'Stay on create', 'bool', CheckExpr },
    { 'Destroyable', 'bool', CheckExpr },
    { 'Time', 'any' },
    { 'Rebound', 'bool', CheckExpr },
    { 'Acceleration', 'any' },
    { 'Accel Angle', 'any' },
    { 'Max Velocity', 'any' },
    { 'Shuttle', 'bool', CheckExpr },
    disptype     = {
        en = 'create simple bullet',
        zh = '创建简单子弹',
    },
    default      = {
        ['type'] = 'bulletcreatestraight',
        attr     = { 'arrow_big', 'COLOR_RED', 'self.x,self.y', '3', '0', 'false', '0', 'true', 'true', '0', 'false', '0', '0', '0', 'false' }
    },
    forbidparent = { 'root', 'folder' },
    allowchild   = {},
    totext       = function(nodedata)
        local ret = string.format("create simple bullet %s,%s at (%s)   v=%s,angle=%s", nodedata.attr[1], nodedata.attr[2], nodedata.attr[3], nodedata.attr[4], nodedata.attr[5])
        if nodedata.attr[6] == 'true' then
            ret = ret .. ", aim to player"
        end
        if #nodedata.attr[10] ~= 0 and nodedata.attr[10] ~= '0' then
            ret = ret .. ", after " .. nodedata.attr[10] .. " frames"
        end
        if nodedata.attr[15] == 'true' then
            ret = ret .. ", break through the screen"
        end
        if nodedata.attr[11] == 'true' then
            ret = ret .. ", rebound when touching the wall"
        end
        return ret
    end,
    tohead       = function(nodedata)
        if #nodedata.attr[10] == 0 then
            nodedata.attr[10] = '0'
        end
        if #nodedata.attr[12] == 0 then
            nodedata.attr[12] = '0'
        end
        if #nodedata.attr[13] == 0 then
            nodedata.attr[13] = '0'
        end
        if #nodedata.attr[14] == 0 then
            nodedata.attr[14] = '0'
        end
        local aca = nodedata.attr[13]
        if nodedata.attr[13] == 'original' then
            aca = "'original'"
        end
        return string.format("last = New(_straight,%s,%s,%s,%s)\n",
                             table.concat(nodedata.attr, ",", 1, 12), aca, nodedata.attr[14], nodedata.attr[15])
    end,
}
local bulletcreatestraightex = {
    { 'Style', 'bulletstyle', CheckExpr },
    { 'Color', 'color', CheckExpr },
    { 'Position', 'pos', CheckPos },
    { 'Number', 'number', CheckExpr },
    { 'Interval (in frames)', 'number', CheckExpr },
    { 'Velocity start', 'number', CheckExpr },
    { 'Velocity end', 'number', CheckExpr },
    { 'Angle', 'number', CheckExpr },
    { 'Angle spread', 'number', CheckExpr },
    { 'Aim to player', 'bool', CheckExpr },
    { 'Rotation Velocity', 'number', CheckExpr },
    { 'Stay on create', 'bool', CheckExpr },
    { 'Destroyable', 'bool', CheckExpr },
    { 'Time', 'number' },
    { 'Rebound', 'bool', CheckExpr },
    disptype     = {
        en = 'create simple bullets',
        zh = '创建简单子弹组',
    },
    default      = {
        ['type'] = 'bulletcreatestraightex',
        attr     = { 'arrow_big', 'COLOR_RED', 'self.x, self.y', '5', '0', '3', '4', '0', '0', 'false', '0', 'true', 'true', '0', 'false' }
    },
    forbidparent = { 'root', 'folder' },
    allowchild   = {},
    totext       = function(nodedata)
        local attr = nodedata.attr
        local ret = string.format("create %s simple bullet(s) %s,%s at (%s)   interval=%s,v=%s~%s,angle=%s,spread=%s", attr[4], attr[1], attr[2], attr[3], attr[5], attr[6], attr[7], attr[8], attr[9])
        if attr[10] == 'true' then
            ret = ret .. ", aim to player"
        end
        if #nodedata.attr[14] ~= 0 and nodedata.attr[14] ~= '0' then
            ret = ret .. ", after " .. nodedata.attr[14] .. " frames"
        end
        if nodedata.attr[15] == 'true' then
            ret = ret .. ", rebound when touching the wall"
        end
        return ret
    end,
    tohead       = function(nodedata)
        if #nodedata.attr[14] == 0 then
            nodedata.attr[14] = '0'
        end
        return string.format("_create_bullet_group(%s, self)\n", table.concat(nodedata.attr, ","))
    end,
}
local bulletclear = {
    { 'Convert to faith items', 'bool', CheckExpr },
    { 'Clear indestructible', 'bool', CheckExpr },
    disptype     = {
        en = 'clear bullet',
        zh = '创建默认消弹效果',
    },
    default      = { ["type"] = 'bulletclear', attr = { 'true', 'false' } },
    forbidparent = { 'root', 'folder' },
    allowchild   = {},
    totext       = function(nodedata)
        return "clear all bullets"
    end,
    tohead       = function(nodedata)
        return string.format("_clear_bullet(%s, %s)\n", nodedata.attr[1], nodedata.attr[2])
    end,
}
local bulletchangestyle = {
    { 'Bullet', 'any', CheckExpr },
    { 'Style', 'bulletstyle', CheckExpr },
    { 'Color', 'color', CheckExpr },
    disptype     = {
        en = 'change style and color of bullet',
        zh = '更改弹型与颜色',
    },
    forbidparent = { 'folder', 'root' },
    allowchild   = {},
    default      = { ['type'] = 'bulletchangestyle', attr = { 'self', 'arrow_big', 'COLOR_RED' } },
    totext       = function(nodedata)
        return string.format("set %s's style to %s and color to %s", nodedata.attr[1], nodedata.attr[2], nodedata.attr[3])
    end,
    tohead       = function(nodedata)
        return string.format("ChangeBulletImage(%s, %s, %s)\n", nodedata.attr[1], nodedata.attr[2], nodedata.attr[3])
    end,
}
--
local highlight = {
    { 'Style', 'bulletstyle', CheckExpr },
    { 'Color', 'color', CheckExpr },
    { 'On/Off', 'bool', CheckExpr },
    default      = { ["type"] = 'highlight', attr = { 'arrow_big', 'COLOR_RED', 'true' } },
    forbidparent = { 'root', 'folder' },
    allowchild   = {},
    totext       = function(nodedata)
        local ret = 'turn '
        if nodedata.attr[3] == 'true' then
            ret = ret .. 'on '
        else
            ret = ret .. 'off '
        end
        return ret .. 'the highlight of ' .. nodedata.attr[1] .. ', color of ' .. nodedata.attr[2]
    end,
    tohead       = function(nodedata)
        return string.format("ChangeBulletHighlight(%s)\n", table.concat(nodedata.attr, ","))
    end
}
--]]
local _def = {
    bulletdefine           = bulletdefine,
    bulletinit             = bulletinit,
    bulletcreate           = bulletcreate,
    bulletcreatestraight   = bulletcreatestraight,
    bulletcreatestraightex = bulletcreatestraightex,
    bulletclear            = bulletclear,
    bulletchangestyle      = bulletchangestyle,

    highlight              = highlight,
}
for k, v in pairs(_def) do
    require('xe.node_def._def').DefineNode(k, v)
end
