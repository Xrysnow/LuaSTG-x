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

local playsound = {
    { 'Sound name', 'sound', CheckNonBlank },
    { 'Volume', 'number', CheckExpr },
    { 'Pan', 'audio_pan', CheckExpr },
    { 'not use default vol', 'bool' },
    disptype     = {
        en = 'play sound',
        zh = '播放音效',
    },
    default      = { ["type"] = "playsound", attr = { 'tan00', '0.1', 'self.x/256', false } },
    allowchild   = {},
    forbidparent = { 'root', 'folder' },
    totext       = function(nodedata)
        return string.format("play sound %q volume %s", nodedata.attr[1], nodedata.attr[2])
    end,
    tohead       = function(nodedata)
        if IsBlank(nodedata.attr[4]) then
            nodedata.attr[4] = false
        end
        return string.format("PlaySound(%q,%s,%s,%s)\n", nodedata.attr[1], nodedata.attr[2], nodedata.attr[3], nodedata.attr[4])
    end,
    check        = function(nodedata)
        local _snd = M.getSoundList()
        if not (M.watchDict.sound[nodedata.attr[1]] or _snd[nodedata.attr[1]]) then
            return string.format('sound %q does not exist', nodedata.attr[1])
        end
    end,
}
local loadsound = {
    { 'File path', 'resfile', CheckNonBlank },
    { 'Resource name', 'string', CheckNonBlank },
    disptype    = {
        en = 'load sound',
        zh = '加载音效',
    },
    editfirst   = true,
    watch       = 'sound',
    allowchild  = {},
    allowparent = { 'root', 'folder' },
    totext      = function(nodedata)
        return string.format("load sound %q from %q", nodedata.attr[2], nodedata.attr[1])
    end,
    tohead      = function(nodedata)
        local attr = nodedata.attr
        --local path = string.filename(attr[1], true)
        return string.format("LoadSound(%q, %q)\n", attr[2], attr[1])
    end,
    check       = function(nodedata)
        local _snd = M.getSoundList()
        if _snd[nodedata.attr[2]] then
            return string.format("Duplicated resource name %q (name already exists in THlib)", nodedata.attr[2])
        end
        if M.checkSoundName[nodedata.attr[2]] == nil then
            M.checkSoundName[nodedata.attr[2]] = true
        else
            return string.format("Duplicated resource name %q", nodedata.attr[2])
        end
        local absfn = MakeFullPath(nodedata.attr[1])
        if not absfn or absfn == '' then
            return string.format("Resource file %q does not exist", nodedata.attr[1])
        end
        local fn = string.filename(nodedata.attr[1], true)
        if not CheckResFileInPack(fn) then
            return string.format("Duplicated resource file name %q", fn)
        end
        require('xe.Project').addPackRes(absfn, 'loadsound')
    end
}
local playbgm = {
    { 'Music name', 'string', CheckNonBlank },
    disptype     = {
        en = 'play background music',
        zh = '播放背景音乐',
    },
    allowchild   = {},
    forbidparent = { 'root', 'folder' },
    totext       = function(nodedata)
        return string.format("play background music %q", nodedata.attr[1])
    end,
    tohead       = function(nodedata)
        return string.format("LoadMusicRecord(%q) _play_music(%q)\n", nodedata.attr[1], nodedata.attr[1])
    end,
}
local pausebgm = {
    disptype     = {
        en = 'pause background music',
        zh = '暂停背景音乐',
    },
    allowchild   = {},
    forbidparent = { 'root', 'folder' },
    totext       = function(nodedata)
        return "pause background music"
    end,
    tohead       = function(nodedata)
        return "_pause_music()\n"
    end,
}
local resumebgm = {
    disptype     = {
        en = 'resume background music',
        zh = '恢复背景音乐',
    },
    allowchild   = {},
    forbidparent = { 'root', 'folder' },
    totext       = function(nodedata)
        return "resume background music"
    end,
    tohead       = function(nodedata)
        return "_resume_music()\n"
    end,
}
local stopbgm = {
    disptype     = {
        en = 'stop background music',
        zh = '停止背景音乐',
    },
    allowchild   = {},
    forbidparent = { 'root', 'folder' },
    totext       = function(nodedata)
        return "stop background music"
    end,
    tohead       = function(nodedata)
        return "_stop_music()\n"
    end,
}
local _def = {
    playsound = playsound,
    loadsound = loadsound,
    playbgm   = playbgm,
    pausebgm  = pausebgm,
    resumebgm = resumebgm,
    stopbgm   = stopbgm,
}
for k, v in pairs(_def) do
    require('xe.node_def._def').DefineNode(k, v)
end
