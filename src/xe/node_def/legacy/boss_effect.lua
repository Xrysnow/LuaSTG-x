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

local pactrometer = {
    { 'Position', 'pos', CheckPos },
    disptype     = {
        en = 'create boss charging effect',
        zh = '创建boss蓄力特效',
    },
    default      = { ["type"] = 'pactrometer', attr = { 'self.x, self.y' } },
    forbidparent = { 'root', 'folder' },
    allowchild   = {},
    totext       = function(nodedata)
        return 'pactrometer in (' .. nodedata.attr[1] .. ')'
    end,
    tohead       = function(nodedata)
        return 'New(boss_cast_ef, ' .. nodedata.attr[1] .. ')\n'
    end,
}
local explode = {
    { 'Position', 'pos', CheckPos },
    disptype     = {
        en = 'create boss explode effect',
        zh = '创建boss死亡特效',
    },
    default      = { ["type"] = 'explode', attr = { 'self.x, self.y' } },
    forbidparent = { 'root', 'folder' },
    allowchild   = {},
    totext       = function(nodedata)
        return 'explode in (' .. nodedata.attr[1] .. ')'
    end,
    tohead       = function(nodedata)
        return 'New(boss_death_ef, ' .. nodedata.attr[1] .. ')\n'
    end,
}
local _def = {
    pactrometer = pactrometer,
    explode     = explode,
}
for k, v in pairs(_def) do
    require('xe.node_def._def').DefineNode(k, v)
end
