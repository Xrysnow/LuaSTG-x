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

local folder = {
    { 'Title', 'string' },
    disptype    = {
        en = 'Folder',
        zh = '文件夹',
    },
    allowparent = { 'root', 'folder' },
    depth       = 0,
    totext      = function(nodedata)
        return nodedata.attr[1]
    end,
}

require('xe.node_def._def').DefineNode('folder', folder)
