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

local task = {
    disptype = {
        en = 'create task',
        zh = '创建task',
    },
    needancestor = {
        'enemydefine', 'bossdefine', 'objectdefine',
        'laserdefine', 'laserbentdefine',
        'bulletdefine', 'rebounderdefine',
        'enemysimple', 'renderimage',
        'task', 'stagetask', 'tasker', 'bglayer'
    },
    totext       = function(nodedata)
        return "create task"
    end,
    tohead       = function(nodedata)
        return "task.New(self,function()\n"
    end,
    tofoot       = function(nodedata)
        return "end)\n"
    end,
}
local tasker = {
    disptype = {
        en = 'create independent task',
        zh = '创建独立task',
    },
    forbidparent = { 'root', 'folder' },
    totext       = function(nodedata)
        return "create tasker"
    end,
    tohead       = function(nodedata)
        return "New(tasker, function()\n"
    end,
    tofoot       = function(nodedata)
        return "end)\n"
    end,
}
local taskclear = {
    disptype = {
		en = 'clear task',
		zh = '清空task',
	},
    needancestor = { 'enemydefine', 'bossdefine', 'objectdefine', 'laserdefine', 'laserbentdefine', 'bulletdefine', 'rebounderdefine' },
    allowchild   = {},
    totext       = function(nodedata)
        return "clear all task(s)"
    end,
    tohead       = function(nodedata)
        return "task.Clear(self)\n"
    end,
}
local taskwait = {
    { 'nFrame', 'any', CheckExpr },
    disptype = {
		en = 'task wait',
		zh = 'task等待',
	},
    default      = { ["type"] = 'taskwait', attr = { '60' } },
    needancestor = { 'task', 'stagetask', 'dialogtask', 'tasker' },
    allowchild   = {},
    totext       = function(nodedata)
        return "wait " .. nodedata.attr[1] .. " frame(s)"
    end,
    tohead       = function(nodedata)
        return "task._Wait(" .. nodedata.attr[1] .. ")\n"
    end,
}
local taskrepeat
taskrepeat = {
    { 'Number of times', 'any', CheckExpr },
    { 'Interval (in frames)', 'any', CheckExpr },
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
    disptype = {
		en = 'task repeat',
		zh = 'task repeat',
	},
    default      = { ["type"] = 'taskrepeat', attr = { '_infinite', '60', '', '', '', '', '', '', '', '', '', '', '', '' } },
    needancestor = { 'task', 'stagetask', 'dialogtask', 'tasker' },
    check        = function(nodedata)
        local attr = nodedata.attr
        for i = 3, 12, 3 do
            if not IsBlank(attr[i]) then
                local msg = CheckVName(attr[i])
                if msg then
                    return string.format("Attribution '%s' is invalid: %s", taskrepeat[i][1], msg)
                end
                msg = CheckExpr(attr[i + 1])
                if msg then
                    return string.format("Attribution '%s' is invalid: %s", taskrepeat[i + 1][1], msg)
                end
                msg = CheckExpr(attr[i + 2])
                if msg then
                    return string.format("Attribution '%s' is invalid: %s", taskrepeat[i + 2][1], msg)
                end
            end
        end
    end,
    totext       = function(nodedata)
        local ret = "repeat " .. nodedata.attr[1] .. " times"
        local attr = nodedata.attr
        if not IsBlank(attr[2]) then
            ret = ret .. ",interval " .. attr[2] .. " frame(s)"
        end
        for i = 3, 12, 3 do
            if not IsBlank(attr[i]) then
                ret = ret .. " (" .. attr[i] .. "=" .. attr[i + 1] .. ",increment " .. attr[i + 2] .. ")"
            end
        end
        return ret
    end,
    tohead       = function(nodedata)
        local ret = "do "
        local attr = nodedata.attr
        for i = 3, 12, 3 do
            if not IsBlank(attr[i]) then
                ret = ret .. string.format("local %s, %s = (%s),(%s) ", attr[i], "_d_" .. attr[i], attr[i + 1], attr[i + 2])
            end
        end
        return ret .. "for _ = 1, " .. nodedata.attr[1] .. " do\n"
    end,
    tofoot       = function(nodedata)
        local ret = ""
        local attr = nodedata.attr
        if not IsBlank(attr[2]) then
            ret = ret .. "    task._Wait(" .. attr[2] .. ")\n"
        end
        for i = 3, 12, 3 do
            if not IsBlank(attr[i]) then
                ret = ret .. string.format("%s = %s + %s ", attr[i], attr[i], "_d_" .. attr[i])
            end
        end
        return ret .. "end end\n"
    end,
}
local taskbreak = {
    { 'Condition', 'any' },
    default      = { ["type"] = 'taskbreak', attr = { '' } },
    needancestor = { 'repeat', 'taskrepeat' },
    disptype = {
		en = 'break repeat',
		zh = '跳出repeat',
	},
    allowchild   = {},
    totext       = function(nodedata)
        if #nodedata.attr[1] == 0 then
            return "jump of the current repeat"
        else
            return "if " .. nodedata.attr[1] .. " then jump of the current repeat"
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
local taskreturn = {
    needancestor = { 'task', 'dialogtask', 'tasker' },
    disptype = {
		en = 'terminate task',
		zh = '结束task',
	},
    allowchild   = {},
    totext       = function(nodedata)
        return "terminate current task"
    end,
    tohead       = function(nodedata)
        return "do return end\n"
    end,
}
local taskmoveto = {
    { 'Destination', 'any', CheckExpr },
    { 'nFrame', 'any', CheckExprOmit },
    { 'Mode', 'movetomode', CheckExprOmit },
    disptype = {
		en = 'task move to',
		zh = '创建移动task',
	},
    needancestor = { 'task', 'dialogtask', 'tasker' },
    allowchild   = {},
    default      = {
        ["attr"] = { "0,0", "60", "MOVE_NORMAL" },
        ["type"] = "taskmoveto"
    },
    totext       = function(nodedata)
        local nf
        if IsBlank(nodedata.attr[2]) then
            nf = '1'
        else
            nf = nodedata.attr[2]
        end
        return "move to (" .. nodedata.attr[1] .. ") in " .. nf .. " frame(s)"
    end,
    tohead       = function(nodedata)
        local nf, mode
        if IsBlank(nodedata.attr[2]) then
            nf = '1'
        else
            nf = nodedata.attr[2]
        end
        if IsBlank(nodedata.attr[3]) then
            mode = 'MOVE_NORMAL'
        else
            mode = nodedata.attr[3]
        end
        return string.format("task.MoveTo(%s,%s,%s)\n", nodedata.attr[1], nf, mode)
    end,
}
local taskBeziermoveto = {
    { 'nFrame', 'any', CheckExprOmit },
    { 'Mode', 'movetomode', CheckExprOmit },
    { 'Point 1', 'any', CheckExpr },
    { 'Point 2', 'any', },
    { 'Point 3', 'any', },
    { 'Point 4', 'any', },
    { 'Point 5', 'any', },
    disptype = {
		en = 'move to by Bezier Curve',
		zh = '创建移动task（贝塞尔曲线）',
	},
    needancestor = { 'task', 'dialogtask', 'tasker' },
    allowchild   = {},
    default      = {
        ["attr"] = { "60", "MOVE_NORMAL", "0,0", "", "", "", "" },
        ["type"] = "taskBeziermoveto"
    },
    totext       = function(nodedata)
        local nf
        if IsBlank(nodedata.attr[1]) then
            nf = '1'
        else
            nf = nodedata.attr[1]
        end
        local str = nodedata.attr[3]
        for i = 4, 7 do
            if IsBlank(nodedata.attr[i]) then
                break
            else
                str = str .. '),(' .. nodedata.attr[i]
            end
        end
        return "move to (" .. str .. ") in " .. nf .. " frame(s) by Bezier Curve"
    end,
    tohead       = function(nodedata)
        local nf, mode
        if IsBlank(nodedata.attr[1]) then
            nf = '1'
        else
            nf = nodedata.attr[1]
        end
        if IsBlank(nodedata.attr[2]) then
            mode = 'MOVE_NORMAL'
        else
            mode = nodedata.attr[2]
        end
        local str = nodedata.attr[3]
        for i = 4, 7 do
            if IsBlank(nodedata.attr[i]) then
                break
            else
                str = str .. ',' .. nodedata.attr[i]
            end
        end
        return string.format("task.BezierMoveTo(%s,%s,%s)\n", nf, mode, str)
    end,
}
--
local taskbosswander = {
    { 'nFrame', 'any', CheckExprOmit },
    { 'X Range', 'any', CheckExprOmit },
    { 'Y Range', 'any', CheckExprOmit },
    { 'X Amplitude', 'any', CheckExprOmit },
    { 'Y Amplitude', 'any', CheckExprOmit },
    { 'Movement Mode', 'movetomode', CheckExprOmit },
    { 'Direction Mode', 'directmode', CheckExprOmit },
    disptype = {
		en = 'task boss wander',
		zh = '创建boss游走task',
	},
    default        = {
        ["attr"] = { "60", "-96,96", "112,144", "16,32", "8,16", "MOVE_NORMAL", "MOVE_X_TOWARDS_PLAYER" },
        ["type"] = "taskbosswander"
    },
    needancestor   = { 'task', 'tasker' },
    forbidancestor = { 'bulletdefine', 'laserdefine', 'laserbentdefine', 'enemydefine' },
    allowchild     = {},
    totext         = function(nodedata)
        local nf
        if IsBlank(nodedata.attr[1]) then
            nf = '1'
        else
            nf = nodedata.attr[1]
        end
        if IsBlank(nodedata.attr[2]) then
            nodedata.attr[2] = "-96,96"
        end
        if IsBlank(nodedata.attr[3]) then
            nodedata.attr[3] = "112,144"
        end
        if IsBlank(nodedata.attr[4]) then
            nodedata.attr[4] = "16,32"
        end
        if IsBlank(nodedata.attr[5]) then
            nodedata.attr[5] = "8,16"
        end
        local mmode, dmode
        if IsBlank(nodedata.attr[6]) then
            mmode = "MOVE_NORMAL"
        else
            mmode = nodedata.attr[6]
        end
        if IsBlank(nodedata.attr[7]) then
            dmode = "MOVE_X_TOWARDS_PLAYER"
        else
            dmode = nodedata.attr[7]
        end
        return "boss wander " .. nf .. " frame(s), range of (" .. nodedata.attr[2] .. "):(" .. nodedata.attr[3] .. "), " ..
                "X amplitude of " .. nodedata.attr[4] .. ", " .. "Y amplitude of " .. nodedata.attr[5] .. "," .. mmode .. ", " .. dmode
    end,
    tohead         = function(nodedata)
        local nf
        if IsBlank(nodedata.attr[1]) then
            nf = '1'
        else
            nf = nodedata.attr[1]
        end
        if IsBlank(nodedata.attr[2]) then
            nodedata.attr[2] = "-96,96"
        end
        if IsBlank(nodedata.attr[3]) then
            nodedata.attr[3] = "112,144"
        end
        if IsBlank(nodedata.attr[4]) then
            nodedata.attr[4] = "16,32"
        end
        if IsBlank(nodedata.attr[5]) then
            nodedata.attr[5] = "8,16"
        end
        local mmode, dmode
        if IsBlank(nodedata.attr[6]) then
            mmode = "MOVE_NORMAL"
        else
            mmode = nodedata.attr[6]
        end
        if IsBlank(nodedata.attr[7]) then
            dmode = "MOVE_X_TOWARDS_PLAYER"
        else
            dmode = nodedata.attr[7]
        end
        return string.format(
                "task.MoveToPlayer(%s,%s,%s,%s,%s,%s,%s)\n",
                nf, nodedata.attr[2], nodedata.attr[3],
                nodedata.attr[4], nodedata.attr[5], mmode, dmode)
    end,
}
local _def = {
    task             = task,
    tasker           = tasker,
    taskclear        = taskclear,
    taskwait         = taskwait,
    taskrepeat       = taskrepeat,
    taskbreak        = taskbreak,
    taskreturn       = taskreturn,
    taskmoveto       = taskmoveto,
    taskBeziermoveto = taskBeziermoveto,
    taskbosswander   = taskbosswander,
}
for k, v in pairs(_def) do
    require('xe.node_def._def').DefineNode(k, v)
end
