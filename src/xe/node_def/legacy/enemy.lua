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

local enemydefine = {
    { 'Type name', 'typename', CheckClassName },
    disptype    = {
        en = 'define enemy',
        zh = '定义enemy',
    },
    editfirst   = true,
    allowparent = { 'root', 'folder' },
    allowchild  = { 'callbackfunc' },
    totext      = function(nodedata)
        return string.format("define enemy type %q", nodedata.attr[1])
    end,
    depth       = 0,
    watch       = 'enemydefine',
    default     = {
        ["attr"]   = {
            [1] = "",
        },
        ["type"]   = "enemydefine",
        ["expand"] = true,
        ["child"]  = {
            [1] = {
                ["attr"]   = { "", "1", "10", "0", "0", "0", "1", "false", "true", "false" },
                ["type"]   = "enemyinit",
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
        return string.format("_editor_class[%q] = Class(enemy)\n", M.className)
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
local enemyinit_head_fmt = [[_editor_class[%q].init = function(self, _x, _y, %s)
enemy.init(self, %s, %s, %s, %s, %s)
self.x, self.y = _x, _y
self.drop = { %s, %s, %s }
task.New(self, function()
    self.protect = true
    task.Wait(%s)
    self.protect = false
end)
]]
local enemyinit = {
    { 'Parameter list', 'any', CheckParam },
    { 'Style', 'selectenemystyle', CheckExpr },
    { 'Hit point', 'any', CheckExpr },
    { 'Drop power item', 'any', CheckExpr },
    { 'Drop faith item', 'any', CheckExpr },
    { 'Drop point item', 'any', CheckExpr },
    { 'Protect (nframes)', 'any', CheckExpr },
    { 'Clear bullets when die', 'bool', CheckExpr },
    { 'Delete when leave screen', 'bool', CheckExpr },
    { 'Taijutsu nashi', 'bool', CheckExpr },
    disptype     = {
        en = 'on create enemy',
        zh = '初始化enemy',
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
        return string.format(
                enemyinit_head_fmt, M.className, p, nodedata.attr[2], nodedata.attr[3], nodedata.attr[8], nodedata.attr[9], nodedata.attr[10], nodedata.attr[4], nodedata.attr[5], nodedata.attr[6], nodedata.attr[7])
    end,
    tofoot       = function(nodedata)
        return "end\n"
    end,
}
local enemycreate = {
    { 'Type name', 'selecttype', CheckNonBlank },
    { 'Position', 'pos', CheckPos },
    { 'Parameter', 'param', CheckExprOmit },
    disptype     = {
        en = 'create enemy',
        zh = '创建enemy',
    },
    editfirst    = true,
    forbidparent = { 'root', 'folder' },
    allowchild   = {},
    totext       = function(nodedata)
        return string.format("create enemy of type %q in (%s) with parameter %s",
                             nodedata.attr[1], nodedata.attr[2], nodedata.attr[3])
    end,
    tohead       = function(nodedata)
        local p
        if IsBlank(nodedata.attr[3]) then
            p = "_"
        else
            p = nodedata.attr[3]
        end
        return string.format("last = New(_editor_class[%q], %s, %s)\n",
                             nodedata.fullclassname, nodedata.attr[2], p)
    end,
    check        = function(nodedata)
        local class
        if M.difficulty and M.watchDict.enemydefine[nodedata.attr[1] .. ':' .. M.difficulty] then
            class = nodedata.attr[1] .. ':' .. M.difficulty
        elseif M.watchDict.enemydefine[nodedata.attr[1]] then
            class = nodedata.attr[1]
        else
            return string.format('enemy type %q does not exist', nodedata.attr[1])
        end
        if M.paramNumDict[class] ~= CalcParamNum(nodedata.attr[3]) then
            return "number of parameter is incorrect"
        end
        nodedata.fullclassname = class
    end,
}
local enemysimple = {
    { 'Style', 'selectenemystyle', CheckExpr },
    { 'Hit point', 'any', CheckExpr },
    { 'Position', 'pos', CheckPos },
    { 'Drop power item', 'any', CheckExpr },
    { 'Drop faith item', 'any', CheckExpr },
    { 'Drop point item', 'any', CheckExpr },
    { 'Protect (nframes)', 'any', CheckExpr },
    { 'Clear bullets when die', 'bool', CheckExpr },
    { 'Delete when leave screen', 'bool', CheckExpr },
    { 'Taijutsu nashi', 'bool', CheckExpr },
    disptype     = {
        en = 'create simple enemy with task',
        zh = '创建简单enemy',
    },
    forbidparent = { 'root', 'folder' },
    allowchild   = { 'task' },
    default      = {
        ['type'] = 'enemysimple',
        attr     = { '1', '10', 'self.x, self.y', '0', '0', '0', '1', 'false', 'false', 'false' }
    },
    totext       = function(nodedata)
        return string.format("create enemy in (%s)", nodedata.attr[3])
    end,
    tohead       = function(nodedata)
        local attr = {}
        for i = 1, 10 do
            attr[i] = nodedata.attr[i]
        end
        return string.format("last = New(EnemySimple, %s, %s, %s, {%s, %s, %s}, %s, %s, %s, %s, function(self)\n",
                             unpack(attr))
    end,
    tofoot       = function(nodedata)
        return "end)\n"
    end,
}
local _def = {
    enemydefine = enemydefine,
    enemyinit   = enemyinit,
    enemycreate = enemycreate,
    enemysimple = enemysimple,
}

for k, v in pairs(_def) do
    require('xe.node_def._def').DefineNode(k, v)
end
