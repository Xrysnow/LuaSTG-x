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
--[[ -- not used
local archiexpand = {
    { 'Style', 'bulletstyle', CheckExpr },
    { 'Color', 'color', CheckExpr },
    { 'Destroyable', 'bool', CheckExpr },
    { 'Auto Rotation', 'bool', CheckExpr },
    { 'Self Rotation Velocity', 'any', CheckExpr },
    { 'Center', 'any' },
    { 'Start Radius', 'any', CheckExpr },
    { 'Start Angle', 'any', CheckExpr },
    { 'Rotation Velocity', 'any', CheckExpr },
    { 'Radius Increment', 'any', CheckExpr },
    disptype     = {
        en = 'create a bullet flying along the Archimedes spiral',
        zh = '',
    },
    forbidparent = { 'root', 'folder' },
    allowchild   = {},
    default      = {
        ['type'] = 'archiexpand',
        ['attr'] = { 'arrow_big', 'COLOR_RED', 'true', 'true', '0', 'self', '0', '0', '0', '0' }
    },
    totext       = function(nodedata)
        return string.format('shoot a %s %s, it flying away from the (%s)',
                             nodedata.attr[2], nodedata.attr[1], nodedata.attr[6])
    end,
    tohead       = function(nodedata)
        local center = nodedata.attr[6]
        local _, _, a, b = string.find(center, '^(.*),(.*)$')
        if a then
            center = string.format('{ x = (%s), y = (%s) }', a, b)
        end
        return string.format('last = New(archiexpand, %s, %s, %s)\n',
                             table.concat(nodedata.attr, ", ", 1, 5),
                             center, table.concat(nodedata.attr, ", ", 7, 10))
    end
}
local archirotate = {
    { 'Style', 'bulletstyle', CheckExpr },
    { 'Color', 'color', CheckExpr },
    { 'Destroyable', 'bool', CheckExpr },
    { 'Auto Rotation', 'bool', CheckExpr },
    { 'Self Rotation Velocity', 'any', CheckExpr },
    { 'Center', 'any' },
    { 'Max Radius', 'any', CheckExpr },
    { 'Start Angle', 'any', CheckExpr },
    { 'Rotation Velocity', 'any', CheckExpr },
    { 'Time before rotation', 'any', CheckExpr },
    disptype     = {
        en = 'create a bullet flying along the Archimedes spiral',
        zh = '',
    },
    forbidparent = { 'root', 'folder' },
    allowchild   = {},
    default      = {
        ['type'] = 'archirotate',
        ['attr'] = { 'arrow_big', 'COLOR_RED', 'true', 'true', '0', 'self', '0', '0', '0', '0' }
    },
    totext       = function(nodedata)
        return string.format('shoot a %s %s, it flying around the (%s)',
                             nodedata.attr[2], nodedata.attr[1], nodedata.attr[6])
    end,
    tohead       = function(nodedata)
        local center = nodedata.attr[6]
        local _, _, a, b = string.find(center, '^(.*),(.*)$')
        if a then
            center = string.format('{ x = (%s), y = (%s) }', a, b)
        end
        return string.format('last = New(archirotate, %s, %s, %s)\n',
                             table.concat(nodedata.attr, ", ", 1, 5),
                             center, table.concat(nodedata.attr, ", ", 7, 10))
    end
}
local _def = {
    archiexpand = archiexpand,
    archirotate = archirotate,
}
for k, v in pairs(_def) do
    require('xe.node_def._def').DefineNode(k, v)
end
--]]
