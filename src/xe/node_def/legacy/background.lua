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

local bgdefine_head_fmt = [[_editor_class[%q] = Class(_spellcard_background)
_editor_class[%q].init = function(self)
    _spellcard_background.init(self)
]]
local bgdefine = {
    { 'Type name', 'typename', CheckClassName },
    disptype    = {
        en = 'define background',
        zh = '定义背景',
    },
    editfirst   = true,
    allowparent = { 'root', 'folder' },
    watch       = 'bgdefine',
    allowchild  = { 'bglayer' },
    totext      = function(nodedata)
        return string.format("define background type %q", nodedata.attr[1])
    end,
    tohead      = function(nodedata)
        return string.format(bgdefine_head_fmt, nodedata.attr[1], nodedata.attr[1])
    end,
    tofoot      = function(nodedata)
        return 'end\n'
    end,
}
local bglayer = {
    { 'Image', 'image', CheckNonBlank },
    { 'Is tile', 'bool', CheckExpr },
    { 'x', 'gop', CheckExpr },
    { 'y', 'gop', CheckExpr },
    { 'rot', 'gop', CheckExpr },
    { 'vx', 'gop', CheckExpr },
    { 'vy', 'gop', CheckExpr },
    { 'omiga', 'gop', CheckExpr },
    { 'Blend mode', 'blend', CheckExprOmit },
    { 'hscale', 'gop', CheckExpr },
    { 'vscale', 'gop', CheckExpr },
    --{'Extra init action','any',CheckCode},
    --{'Extra frame action','any',CheckCode},
    disptype    = {
        en = 'add background layer',
        zh = '添加背景层',
    },
    editfirst   = true,
    default     = {
        ["type"] = 'bglayer',
        attr     = { '', 'false', '0', '0', '0', '0', '0', '0', '', '1', '1' },
        expand   = true,
        child    = {
            { ["type"] = "bginit" },
            { ['type'] = "bgframe" },
            { ['type'] = "bgrender" }
        },
    },
    allowparent = { 'bgdefine' },
    allowchild  = { 'bginit', 'bgframe', 'bgrender' },
    totext      = function(nodedata)
        return string.format("layer %q", nodedata.attr[1])
    end,
    tohead      = function(nodedata)
        --local attr = nodedata.attr
        --local init_code, frame_code
        --if IsBlank(attr[12]) then  init_code='nil' else  init_code=string.format('function(self) %s end',attr[12]) end
        --if IsBlank(attr[13]) then frame_code='nil' else frame_code=string.format('function(self) %s end',attr[13]) end
        local attr = {}
        for i = 1, 11 do
            attr[i] = nodedata.attr[i]
        end
        return string.format(
                '_spellcard_background.AddLayer(self,%q,%s,%s,%s,%s,%s,%s,%s,%q,%s,%s,\n',
                unpack(attr, 1, 11)
        )
    end,
    tofoot      = function(nodedata)
        return ")\n"
    end,
    check       = function(nodedata)
        --if not M.watchDict.imageonly[nodedata.attr[1]] then
        --    return string.format('image %q does not exist',nodedata.attr[1])
        --end
    end
}
local bginit = {
    allowparent = { 'bglayer' },
    --allowchild={"task"},
    totext      = function(nodedata)
        return "on create"
    end,
    tohead      = function(nodedata)
        return "function(self)\nself.task ={}\n"
    end,
    tofoot      = function(nodedata)
        return "end,\n"
    end,
}
local bgframe = {
    allowparent = { 'bglayer' },
    --allowchild={"task"},
    totext      = function(nodedata)
        return "on frame"
    end,
    tohead      = function(nodedata)
        return "function(self)\ntask.Do(self)\n"
    end,
    tofoot      = function(nodedata)
        return "end,\n"
    end,
}
local bgrender = {
    allowparent = { 'bglayer' },
    --allowchild={"task"},
    totext      = function(nodedata)
        return "on render"
    end,
    tohead      = function(nodedata)
        return "function(self)\ntask.Do(self)\n"
    end,
    tofoot      = function(nodedata)
        return "end\n"
    end,
}

local _def = {
    bgdefine = bgdefine,
    bglayer  = bglayer,
    bginit   = bginit,
    bgframe  = bgframe,
    bgrender = bgrender,
}
for k, v in pairs(_def) do
    require('xe.node_def._def').DefineNode(k, v)
end
