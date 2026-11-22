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
local DefineNodes = require('xe.node_def._def').DefineNodes

local repeat_ = {
    { 'Count', 'any', CheckExpr },
    disptype     = {
        en = 'repeat+',
        zh = '循环+',
    },
    default      = { ["type"] = 'x_repeat', attr = { '_infinite' } },
    forbidparent = { 'root', 'folder' },
    totext       = "repeat $1 times",
    tohead       = "do\n\tlocal __end__ = int($1)\n"
            .. "\tfor __i__ = 1, __end__ do\n"
            .. "\t\tlocal __t__ = (__i__ - 1) / (__end__ - 1)\n",
    tofoot       = "\tend\nend\n",
    depth        = 2,
    icon         = 'advancedrepeat',
}

local repeat_var = {
    { 'Name', 'any', CheckVName,
      desc = 'var_name',
    },
    { 'Begin value', 'any', CheckExpr },
    { 'End value', 'any', CheckExpr },
    { 'Increment type', 'tween_type', CheckNonBlank },
    disptype    = {
        en = 'repeat+ variable',
        zh = '[循环+]变量',
    },
    default     = { ["type"] = 'x_repeat_var', attr = { '', '', '', '' } },
    allowparent = { 'x_repeat' },
    allowchild  = {},
    totext      = "$1: $2 -> $3 ($4)",
    tohead      = 'local __begin__ = $2\n'
            .. 'local $1 = __begin__ + math.tween.$4(__t__) * ($3 - __begin__)\n',
    depth       = 0,
    icon        = 'SinusoidalInterpolationVariable',
}

local repeat_var_inc = {
    { 'Name', 'any', CheckVName,
      desc = 'var_name',
    },
    { 'Begin value', 'any', CheckExpr },
    { 'Increment value', 'any', CheckExpr },
    { 'Increment type', 'tween_type', CheckNonBlank },
    disptype    = {
        en = 'repeat+ variable (increment)',
        zh = '[循环+]变量（增量）',
    },
    default     = { ["type"] = 'x_repeat_var_inc', attr = { '', '', '', '' } },
    allowparent = { 'x_repeat' },
    allowchild  = {},
    totext      = "$1: $2 -> + $3 ($4)",
    tohead      = 'local $1 = $2 + math.tween.$4(__t__) * $3\n',
    depth       = 0,
    icon        = 'SinusoidalInterpolationVariable',
}

DefineNodes {
    x_repeat         = repeat_,
    x_repeat_var     = repeat_var,
    x_repeat_var_inc = repeat_var_inc,
}
