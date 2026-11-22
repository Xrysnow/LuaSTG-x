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

local connect = {
    { 'Master', 'any', CheckExpr },
    { 'Servant', 'any', CheckExpr },
    { 'Damage transfer', 'any', CheckExpr },
    { 'Connect death', 'bool', CheckExpr },
    disptype     = {
        en = 'bind servant',
        zh = '绑定使魔',
    },
    default      = {
        ['type'] = 'connect',
        attr     = { 'self', 'last', '0', 'true' }
    },
    forbidparent = { 'root', 'folder' },
    allowchild   = {},
    totext       = function(nodedata)
        return string.format('set %s as servant of %s', nodedata.attr[2], nodedata.attr[1])
    end,
    tohead       = function(nodedata)
        local attr = {}
        for i = 1, 4 do
            attr[i] = nodedata.attr[i]
        end
        return string.format('_connect(%s, %s, %s, %s)\n', unpack(attr, 1, 4))
    end,
}
local setrelpos = {
    { 'Position', 'pos', CheckPos },
    { 'Rotation', 'any', CheckExpr, 'self.rot' },
    { 'Follow rotation of master', 'bool', CheckExpr, 'false' },
    disptype     = {
        en = 'set relative position',
        zh = '设置相对位置',
    },
    default      = {
        ['type'] = 'setrelpos',
        attr     = { '0, 0', 'self.rot', 'false' }
    },
    needancestor = { 'enemydefine', 'objectdefine', 'laserdefine', 'laserbentdefine', 'bulletdefine' },
    forbidparent = { 'enemyinit', 'objectinit', 'laserinit', 'laserbentinit', 'bulletinit' },
    allowchild   = {},
    totext       = function(nodedata)
        local ret = string.format('set position to (%s) relatively to master, set rot to %s', nodedata.attr[1], nodedata.attr[2])
        if nodedata.attr[3] == 'true' then
            ret = ret .. ', follow master\'s rot'
        end
        return ret
    end,
    tohead       = function(nodedata)
        local attr = {}
        for i = 1, 3 do
            attr[i] = nodedata.attr[i]
        end
        return string.format('_set_rel_pos(self, %s, %s, %s)\n', unpack(attr, 1, 3))
    end,
}
local _def = {
    connect   = connect,
    setrelpos = setrelpos,
}
for k, v in pairs(_def) do
    require('xe.node_def._def').DefineNode(k, v)
end
