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

local codeblock = {
    { 'Title', 'any' },
    disptype     = {
        en = 'code block',
        zh = '添加代码块',
    },
    forbidparent = { 'root', 'folder' },
    totext       = function(nodedata)
        return nodedata.attr[1]
    end,
    tohead       = function(nodedata)
        return "do\n"
    end,
    tofoot       = function(nodedata)
        return "end\n"
    end,
}
local code = {
    { 'Code', 'code_lua', CheckCode },
    disptype   = {
        en = 'code',
        zh = '添加代码',
    },
    allowchild = {},
    editfirst  = true,
    totext     = function(nodedata)
        local code = nodedata.attr[1]
        local start, finish = string.find(nodedata.attr[1], '^.-\n')
        if start == nil then
            return code == '' and '(empty)' or code
        else
            return string.sub(code, 1, finish - 1) .. ' ...'
        end
    end,
    tohead     = function(nodedata)
        return nodedata.attr[1] .. "\n"
    end,
}
local comment = {
    { 'Comment', 'any' },
    disptype   = {
        en = 'comment',
        zh = '添加注释',
    },
    allowchild = {},
    editfirst  = true,
    totext     = function(nodedata)
        return "[comment] " .. nodedata.attr[1]
    end,
    tohead     = function(nodedata)
        return "--[[ " .. nodedata.attr[1] .. " --]]\n"
    end,
}
local variable = {
    { 'Name', 'any', CheckVName },
    { 'Initial value', 'any', CheckExprOmit },
    disptype     = {
        en = 'define variable',
        zh = '定义变量',
    },
    editfirst    = true,
    allowchild   = {},
    forbidparent = { 'root', 'folder' },
    totext       = function(nodedata)
        if IsBlank(nodedata.attr[2]) then
            return 'define local variable ' .. nodedata.attr[1]
        else
            return 'define local variable ' .. nodedata.attr[1] .. " = " .. nodedata.attr[2]
        end
    end,
    tohead       = function(nodedata)
        if IsBlank(nodedata.attr[2]) then
            return 'local ' .. nodedata.attr[1] .. "\n"
        else
            return 'local ' .. nodedata.attr[1] .. " = " .. nodedata.attr[2] .. "\n"
        end
    end,
}
local repeat_
repeat_ = {
    { 'Number of times', 'any', CheckExpr },
    { 'Var 1 name', 'any' },
    { 'Var 1 init value', 'any' },
    { 'Var 1 increment', 'any' },
    { 'Var 2 name', 'any' },
    { 'Var 2 init value', 'any' },
    { 'Var 2 increment', 'any' },
    { 'Var 3 name', 'any' },
    { 'Var 3 init value', 'any' },
    { 'Var 3 increment', 'any' },
    { 'Var 4 name', 'any' },
    { 'Var 4 init value', 'any' },
    { 'Var 4 increment', 'any' },
    disptype     = {
        en = 'repeat statement',
        zh = '循环语句',
    },
    default      = { ["type"] = 'repeat', attr = { '_infinite', '', '', '', '', '', '', '', '', '', '', '', '' } },
    forbidparent = { 'root', 'folder' },
    check        = function(nodedata)
        local attr = nodedata.attr
        for i = 2, 11, 3 do
            if not IsBlank(attr[i]) then
                local msg = CheckVName(attr[i])
                if msg then
                    return string.format("Attribution '%s' is invalid: %s", repeat_[i][1], msg)
                end
                msg = CheckExpr(attr[i + 1])
                if msg then
                    return string.format("Attribution '%s' is invalid: %s", repeat_[i + 1][1], msg)
                end
                msg = CheckExpr(attr[i + 2])
                if msg then
                    return string.format("Attribution '%s' is invalid: %s", repeat_[i + 2][1], msg)
                end
            end
        end
    end,
    totext       = function(nodedata)
        local ret = "repeat " .. nodedata.attr[1] .. " times"
        local attr = nodedata.attr
        for i = 2, 11, 3 do
            if not IsBlank(attr[i]) then
                ret = ret .. " (" .. attr[i] .. "=" .. attr[i + 1] .. ",increment " .. attr[i + 2] .. ")"
            end
        end
        return ret
    end,
    tohead       = function(nodedata)
        local ret = "do\n"
        local attr = nodedata.attr
        for i = 2, 11, 3 do
            if not IsBlank(attr[i]) then
                ret = ret .. string.format(
                        "\tlocal %s, %s = (%s), (%s)\n",
                        attr[i], "_d_" .. attr[i], attr[i + 1], attr[i + 2])
            end
        end
        return ret .. "\tfor _ = 1, " .. nodedata.attr[1] .. " do\n"
    end,
    tofoot       = function(nodedata)
        local ret = ""
        local attr = nodedata.attr
        for i = 2, 11, 3 do
            if not IsBlank(attr[i]) then
                ret = ret .. string.format("\t\t%s = %s + %s\n", attr[i], attr[i], "_d_" .. attr[i])
            end
        end
        return ret .. "\tend\nend\n"
    end,
    depth        = 2,
}
local break_ = {
    { 'Condition', 'any' },
    disptype     = {
        en = 'break statement',
        zh = 'break语句',
    },
    default      = { ["type"] = 'break', attr = { '' } },
    needancestor = { 'repeat', 'taskrepeat' },
    allowchild   = {},
    totext       = function(nodedata)
        if #nodedata.attr[1] == 0 then
            return "break"
        else
            return "if " .. nodedata.attr[1] .. " then break"
        end
    end,
    tohead       = function(nodedata)
        local t = nodedata.attr[1]
        if #t == 0 then
            t = 'true'
        end
        return "if " .. t .. " then break end\n"
    end,
}
local if_ = {
    { 'Condition', 'any', CheckExpr },
    disptype     = {
        en = 'if statement',
        zh = 'if语句',
    },
    editfirst    = true,
    forbidparent = { 'root', 'folder' },
    depth        = 0,
    allowchild   = {},
    totext       = function(nodedata)
        return "if " .. nodedata.attr[1]
    end,
    default      = {
        ["attr"] = { "" },
        ["type"] = "if",
        expand   = true,
        child    = {
            { ["attr"] = {}, ["type"] = "then" },
            { ["attr"] = {}, ["type"] = "else" }
        }
    },
    tohead       = function(nodedata)
        return "if " .. nodedata.attr[1] .. " then\n"
    end,
    tofoot       = function(nodedata)
        return "end\n"
    end,
}
local then_ = {
    disptype     = {
        en = 'then statement',
        zh = 'then语句',
    },
    totext       = function(nodedata)
        return "then"
    end,
    allowparent  = {},
    forbiddelete = true,
}
local else_ = {
    disptype     = {
        en = 'else statement',
        zh = 'else语句',
    },
    totext       = function(nodedata)
        return "else"
    end,
    allowparent  = {},
    forbiddelete = true,
    tohead       = function(nodedata)
        return "else\n"
    end,
}

local _def = {
    codeblock  = codeblock,
    code       = code,
    comment    = comment,
    variable   = variable,
    ['repeat'] = repeat_,
    ['break']  = break_,
    ['if']     = if_,
    ['then']   = then_,
    ['else']   = else_,
}
for k, v in pairs(_def) do
    require('xe.node_def._def').DefineNode(k, v)
end
