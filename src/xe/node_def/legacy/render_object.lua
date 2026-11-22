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
--
local renderimage = {
    { 'image', 'string', CheckNonBlank },
    { 'Position', 'pos', CheckPos },
    { 'Rotation', 'any', CheckExpr },
    { 'Horizonal scale', 'any', CheckExpr },
    { 'Vertical scale', 'any', CheckExpr },
    { 'Layer', 'layer', CheckExpr },
    disptype = {
		en = 'render',
		zh = '',
	},
    default      = { ["type"] = 'renderimage', attr = { 'leaf', 'self.x, self.y', '0', '1.0', '1.0', 'LAYER_BG' } },
    forbidparent = { 'root', 'folder' },
    allowchild   = { 'task' },
    totext       = function(nodedata)
        return 'draw ' .. nodedata.attr[1] .. ' at (' .. nodedata.attr[2] .. ')'
    end,
    tohead       = function(nodedata)
        return string.format("New(RenderObject, self, %s, function(self)\n", table.concat(nodedata.attr, ", "))
    end,
    tofoot       = function(nodedata)
        return "end)\n"
    end
}
local _def = {
    renderimage = renderimage,
}
for k, v in pairs(_def) do
    require('xe.node_def._def').DefineNode(k, v)
end
--]]
