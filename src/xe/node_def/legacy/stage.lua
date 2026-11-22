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

local stageGroupName

local stagegroup = {
    { 'Name', 'stagegroup', CheckClassName },
    { 'Start life', 'any', CheckExpr },
    { 'Start power', 'any', CheckExpr },
    { 'Start faith', 'any', CheckExpr },
    { 'Start bomb', 'any', CheckExpr, '3' },
    { 'Allow practice', 'bool', CheckExpr },
    { 'Difficulty value', 'difficulty', CheckExpr, '1' },
    disptype    = {
        en = 'stage group',
        zh = '创建关卡组',
    },
    editfirst   = true,
    default     = { ["type"] = 'stagegroup', attr = { '', '2', '100', '50000', '3', 'true' } },
    allowchild  = { 'stage' },
    allowparent = { 'root', 'folder' },
    depth       = 0,
    totext      = function(nodedata)
        return string.format("stage group %q", nodedata.attr[1])
    end,
    tohead      = function(nodedata)
        stageGroupName = nodedata.attr[1]
        return string.format(
                "stage.group.New('menu', {}, %q, {lifeleft = %s, power = %s, faith = %s, bomb = %s}, %s, %s)\n",
                nodedata.attr[1], nodedata.attr[2], nodedata.attr[3], nodedata.attr[4], nodedata.attr[5], nodedata.attr[6], nodedata.attr[7])
    end,
    check       = function(nodedata)
        M.difficulty = nodedata.attr[1]
    end,
    checkafter  = function(nodedata)
        M.difficulty = nil
    end,
}
local stage_head_fmt = [[stage.group.AddStage('%s', '%s@%s', {lifeleft=%s,power=%s,faith=%s,bomb=%s}, %s)
stage.group.DefStageFunc('%s@%s', 'init', function(self)
    _init_item(self)
    difficulty = self.group.difficulty
    New(mask_fader, 'open')
    New(_G[lstg.var.player_name])
]]
local stage_foot = [[    task.New(self, function()
        while coroutine.status(self.task[1]) ~= 'dead' do
            task.Wait()
        end
        stage.group.FinishReplay()
        New(mask_fader, 'close')
        task.New(self, function()
            local _, bgm = EnumRes('bgm')
            for i = 1, 30 do
                for _, v in pairs(bgm) do
                    if GetMusicState(v) == 'playing' then
                        SetBGMVolume(v, 1 - i / 30)
                    end
                end
                task.Wait()
            end
        end)
        task.Wait(30)
        stage.group.FinishStage()
    end)
end)
]]
local stage = {
    { 'Name', 'any', CheckName },
    { 'Start life (practice)', 'any', CheckExpr },
    { 'Start power (practice)', 'any', CheckExpr },
    { 'Start faith (practice)', 'any', CheckExpr },
    { 'Start spell (practice)', 'any', CheckExpr },
    { 'Allow practice', 'bool', CheckExpr },
    disptype    = {
        en = 'stage',
        zh = '创建关卡',
    },
    editfirst   = true,
    allowparent = { 'stagegroup' },
    allowchild  = {},
    depth       = 1,
    default     = {
        expand   = true,
        ["type"] = 'stage',
        attr     = { '', '7', '300', '50000', '3', 'true' },
        child    = {
            { ["type"] = 'stagetask', attr = {} }
        }
    },
    totext      = function(nodedata)
        return string.format("stage %q", nodedata.attr[1])
    end,
    tohead      = function(nodedata)
        local ret = string.format(
                stage_head_fmt,
                stageGroupName,
                nodedata.attr[1],
                stageGroupName,
                nodedata.attr[2],
                nodedata.attr[3],
                nodedata.attr[4],
                nodedata.attr[5],
                nodedata.attr[6],
                nodedata.attr[1],
                stageGroupName)
        return ret
    end,
    tofoot      = function(nodedata)
        return stage_foot
    end,
}
local stagetask = {
    disptype     = {
        en = 'task for stage',
        zh = '添加关卡task',
    },
    allowparent  = {},
    forbiddelete = true,
    totext       = function(nodedata)
        return "create task"
    end,
    tohead       = function(nodedata)
        return "task.New(self, function()\n"
    end,
    tofoot       = function(nodedata)
        return "end)\n"
    end,
}
local stagefinish = {
    needancestor = { 'stage' },
    disptype     = {
        en = 'finish stage',
        zh = '结束关卡',
    },
    allowchild   = {},
    totext       = function(nodedata)
        return "finish current stage"
    end,
    tohead       = function(nodedata)
        return "if true then return end\n"
    end,
}
local stagegoto = {
    { 'Stage (index)', 'any', CheckExpr },
    disptype     = {
        en = 'go to stage',
        zh = '切换关卡',
    },
    needancestor = { 'stage' },
    allowchild   = {},
    totext       = function(nodedata)
        return "go to stage " .. nodedata.attr[1]
    end,
    tohead       = function(nodedata)
        return
        "New(mask_fader, 'close')\
        task.New(self, function()\
            local _, bgm = EnumRes('bgm')\
            for i = 1, 30 do \
                for _, v in pairs(bgm) do\
                    if GetMusicState(v) == 'playing' then\
                    SetBGMVolume(v, 1 - i / 30) end\
                end\
                task.Wait()\
        end end)\
        task.Wait(30)\
        stage.group.GoToStage(" .. nodedata.attr[1] .. ")\n"
    end,
}
local stagefinishgroup_head = [[New(mask_fader, 'close')
_stop_music()
task.Wait(30)
stage.group.FinishGroup()
]]
local stagefinishgroup = {
    disptype     = {
        en = 'finish stage group',
        zh = '结束关卡组',
    },
    needancestor = { 'stage' },
    allowchild   = {},
    totext       = function(nodedata)
        return "finish current game and return to title"
    end,
    tohead       = function(nodedata)
        return stagefinishgroup_head
    end,
}
local bgstage = {
    { 'Background', 'bgstage', CheckVName },
    disptype     = {
        en = 'set stage background',
        zh = '设置关卡背景',
    },
    needancestor = { 'stage' },
    allowchild   = {},
    totext       = function(nodedata)
        return string.format("set current stage's background to %q", nodedata.attr[1])
    end,
    tohead       = function(nodedata)
        return string.format("New(%s_background)\n", nodedata.attr[1])
    end,
}

local _def = {
    stagegroup       = stagegroup,
    stage            = stage,
    stagetask        = stagetask,
    stagefinish      = stagefinish,
    stagegoto        = stagegoto,
    stagefinishgroup = stagefinishgroup,
    bgstage          = bgstage,
}
for k, v in pairs(_def) do
    require('xe.node_def._def').DefineNode(k, v)
end
