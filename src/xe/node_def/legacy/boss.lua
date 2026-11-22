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

local bossdefine_head_fmt1 = [[_editor_class[%q] = Class(boss)
_editor_class[%q].cards = {}
_editor_class[%q].name = %q
_editor_class[%q].init = function(self, cards)
    boss.init(self, %s, %q, cards, New(%s))
    self.difficulty = %q
end
_editor_class[%q].bgm = %q
_editor_class[%q]._bg = %s
_editor_class[%q].difficulty = %q
]]
local bossdefine_head_fmt2 = [[LoadTexture('anonymous:'..%q, %q)
bossimg_number_n = {%s}
--bossimg_number_m = {%s}
bosstexture_n, bosstexture_m = GetTextureSize('anonymous:'..%q)
bossimg_w, bossimg_h = bosstexture_n/%s, bosstexture_m/%s
for i = 1, %s do
	LoadImageGroup('anonymous:'..%q..i, 'anonymous:'..%q, 0, bossimg_h*(i-1), bossimg_w, bossimg_h, bossimg_number_n[i], 1, %s)
end
_editor_class[%q] = Class(boss)
_editor_class[%q].cards = {}
_editor_class[%q].name = %q
_editor_class[%q].init = function(self, cards)
	boss.init(self, %s, %q, cards, New(%s))
	self.difficulty = %q
	self.ani_intv = %s
	for i = 1, %s do self['img'..i] = {} end
	self.nn = {%s}
	self.mm = {%s}
	for i = 2, %s do self['ani'..i] = self.nn[i] - self.mm[i - 1] end
	for i = 1, %s do
		for j = 1, self.nn[i] do
			self['img'..i][j] = 'anonymous:'..%q..i..j
		end
	end
end
_editor_class[%q].bgm = %q
_editor_class[%q]._bg = %s
_editor_class[%q].difficulty = %q
]]
local bossdefine = {
    { 'Type name', 'typename', CheckClassName },
    { 'Displayed name', 'string', CheckNonBlank },
    { 'Position', 'pos', CheckPos },
    { 'Spell Card Background', 'selecttype' },
    { 'Image', 'resfile' }, --TODO: should use 'image'
    { 'nCol', 'number', CheckExpr },
    { 'nRow', 'number', CheckExpr },
    { 'Collision size', 'vec2', CheckExpr },
    { 'Animation interval', 'number', CheckExpr },
    { "Background", "any" },
    { "Background Music", "any" },
    { 'Number of imgs', 'any' },
    { 'Number of anis', 'any' },
    disptype    = {
        en = 'define boss',
        zh = '定义boss',
    },
    editfirst   = true,
    default     = {
        ["attr"]  = { "", "Name", "240,384", "", "", "4", "3", "16,16", "8", "", "", "4,4,4,4", "1,1,1" },
        ["type"]  = "bossdefine",
        expand    = true,
        ["child"] = {
            [1] = {
                ["attr"] = { "0,144", "60", "MOVE_NORMAL", },
                ["type"] = "bossmoveto",
            },
            [2] = {
                ["attr"]   = { "", "2", "15", "60", "600", "0", "0", "0", "false" },
                ["type"]   = "bossspellcard",
                ["expand"] = true,
                ["child"]  = {
                    [1] = {
                        ["attr"]   = {},
                        ["type"]   = "bossscstart",
                        ["expand"] = true,
                        ["child"]  = {
                            [1] = {
                                ["attr"]   = {
                                },
                                ["type"]   = "task",
                                ["expand"] = true,
                                ["child"]  = {
                                    [1] = {
                                        ["attr"] = { '0,144', '180', 'MOVE_NORMAL' },
                                        ["type"] = "taskmoveto",
                                    },
                                },
                            },
                        },
                    },
                    [2] = {
                        ["attr"] = {},
                        ["type"] = "bossscfinish",
                    },
                },
            },
        },
    },
    allowparent = { 'root', 'folder' },
    allowchild  = { 'bossspellcard', 'bossmoveto', 'dialog' },
    watch       = 'bossdefine',
    totext      = function(nodedata)
        return string.format("define boss %q", nodedata.attr[1])
    end,
    depth       = 0,
    tohead      = function(nodedata)
        M.className = nodedata.attr[1]
        local className = M.className
        M.difficulty = string.match(nodedata.attr[1], '^.+:(.+)$')
        local difficulty = M.difficulty
        if difficulty == nil or difficulty == '' then
            difficulty = 'All'
            M.difficulty = difficulty
        end
        local scbg, _bg
        if IsBlank(nodedata.attr[10]) then
            _bg = 'nil'
        else
            _bg = nodedata.attr[10]
        end
        if IsBlank(nodedata.attr[4]) then
            scbg = "spellcard_background"
        else
            scbg = string.format("_editor_class[%q]", nodedata.attr[4])
        end
        if IsBlank(nodedata.attr[5]) then
            return string.format(
                    bossdefine_head_fmt1,
                    className, className, className, nodedata.attr[2], className, nodedata.attr[3], nodedata.attr[2],
                    scbg, difficulty, className, nodedata.attr[11], className, _bg, className, difficulty)
        else
            --local fn = wx.wxFileName(nodedata.attr[5]):GetFullName()
            local fn = string.filename(nodedata.attr[5], true)
            return string.format(
            --"LoadImageGroupFromFile('anonymous:'..%q,%q,false,%s,%s,%s)"
                    bossdefine_head_fmt2,
                    fn, fn, nodedata.attr[12], nodedata.attr[13], fn, nodedata.attr[6], nodedata.attr[7],
                    nodedata.attr[7], fn, fn, nodedata.attr[8],
                    className, className, className, nodedata.attr[2], className, nodedata.attr[3], nodedata.attr[2], scbg, difficulty,
                    nodedata.attr[9], nodedata.attr[7], nodedata.attr[12], nodedata.attr[13],
                    nodedata.attr[7], nodedata.attr[7], fn,
                    className, nodedata.attr[11], className, _bg, className, difficulty)
        end
    end,
    tofoot      = function(nodedata)
        M.difficulty = nil
        return ''
    end,
    check       = function(nodedata)
        if not IsBlank(nodedata.attr[5]) then
            local absfn = MakeFullPath(nodedata.attr[5])
            if not absfn or absfn == '' then
                return string.format("Resource file %q does not exist", nodedata.attr[5])
            end
            --local fn = wx.wxFileName(nodedata.attr[5]):GetFullName()
            local fn = string.filename(nodedata.attr[5], true)
            if not CheckAnonymous(fn, absfn) then
                return string.format("Repeated resource file name %q", fn)
            end
            --local f, msg = io.open("editor\\tmp\\_pack_res.bat", "a")
            --if msg then
            --    return msg
            --end
            --f:write(string.format('..\\tools\\7z\\7z u -tzip -mcu=on "..\\game\\mod\\%s.zip" "%s"\n', outputName, absfn))
            --f:close()
            require('xe.Project').addPackRes(absfn, 'bossdefine')
        end
        local bg_type = nodedata.attr[4]
        if bg_type ~= '' and (not M.watchDict.bgdefine[bg_type]) then
            return string.format('background type %q does not exist', bg_type)
        end
        M.difficulty = string.match(nodedata.attr[1], '^.+:(.+)$')
    end,
    checkafter  = function(nodedata)
        M.difficulty = nil
    end,
}
local bossspellcard = {
    { 'Name', 'string' },
    { 'Protect time (seconds)', 'number', CheckExpr },
    { 'Full damage time (seconds)', 'number', CheckExpr },
    { 'Total time (seconds)', 'number', CheckExpr },
    { 'Hit point', 'any', CheckExpr },
    { 'Drop power', 'any', CheckExpr },
    { 'Drop faith', 'any', CheckExpr },
    { 'Drop point', 'any', CheckExpr },
    { 'Immune to bomb', 'bool', CheckExpr },
    { 'Performing action', 'bool', CheckExpr },
    disptype    = {
        en = 'add spell card',
        zh = '添加符卡',
    },
    default     = {
        ["attr"]   = { "", "2", "15", "60", "600", "0", "0", "0", "false", "false" },
        ["type"]   = "bossspellcard",
        ["expand"] = true,
        ["child"]  = {
            [1] = {
                ["attr"]   = {},
                ["type"]   = "bossscstart",
                ["expand"] = true,
                ["child"]  = {
                    [1] = {
                        ["attr"]   = {
                        },
                        ["type"]   = "task",
                        ["expand"] = true,
                        ["child"]  = {
                            [1] = {
                                ["attr"] = { '0,144', '180', 'MOVE_NORMAL' },
                                ["type"] = "taskmoveto",
                            },
                        },
                    },
                },
            },
            [2] = {
                ["attr"] = {},
                ["type"] = "bossscfinish",
            },
        },
    },
    depth       = 0,
    allowchild  = {},
    allowparent = { 'bossdefine' },
    totext      = function(nodedata)
        if IsBlank(nodedata.attr[1]) then
            return "non-spell card"
        else
            return string.format("spell card %q", nodedata.attr[1])
        end
    end,
    tohead      = function(nodedata)
        return string.format("_tmp_sc = boss.card.New(%q,%s,%s,%s,%s,{%s,%s,%s},%s)\n"
        , nodedata.attr[1], nodedata.attr[2], nodedata.attr[3], nodedata.attr[4], nodedata.attr[5], nodedata.attr[6], nodedata.attr[7], nodedata.attr[8], nodedata.attr[9])
    end,
    tofoot      = function(nodedata)
        local className = M.className
        if IsBlank(nodedata.attr[1]) then
            return string.format("table.insert(_editor_class[%q].cards,_tmp_sc)\n", className)
        else
            ---TODO: problem when nodedata.attr[10] convert to boolean
            if nodedata.attr[10] == false then
                return string.format("table.insert(_editor_class[%q].cards, _tmp_sc)\ntable.insert(_sc_table, {%q,%q,_tmp_sc,#_editor_class[%q].cards})\n", className, className, nodedata.attr[1], className)
            else
                return string.format("table.insert(_editor_class[%q].cards, _tmp_sc)\ntable.insert(_sc_table, {%q,%q,_tmp_sc,#_editor_class[%q].cards,%s})\n", className, className, nodedata.attr[1], className, nodedata.attr[10])
            end
        end
    end
}
local bossscstart = {
    allowparent  = { 'bossspellcard' },
    disptype     = {
        en = 'on start spell card',
        zh = '符卡开始事件',
    },
    forbiddelete = true,
    totext       = function(nodedata)
        return "on start"
    end,
    tohead       = function(nodedata)
        return "function _tmp_sc:init()\n"
    end,
    tofoot       = function(nodedata)
        return "end\n"
    end,
}
local bossscfinish = {
    allowparent  = { 'bossspellcard' },
    disptype     = {
        en = 'on finish spell card',
        zh = '符卡结束事件',
    },
    forbiddelete = true,
    totext       = function(nodedata)
        return "on finish"
    end,
    tohead       = function(nodedata)
        return "function _tmp_sc:del()\n"
    end,
    tofoot       = function(nodedata)
        return "end\n"
    end,
}
local dialog_head_fmt = [[_tmp_sc = boss.dialog.New(%s)
function _tmp_sc:init()
    lstg.player.dialog = %s
    _dialog_can_skip = %s
    self.dialog_displayer = New(dialog_displayer)
]]
local dialog = {
    { 'Can skip', 'bool', CheckExpr },
    { 'dialog', 'bool', CheckExpr },
    disptype    = {
        en = 'create dialog',
        zh = '创建对话',
    },
    default     = {
        ["attr"]   = { "true", "true" },
        ["type"]   = "dialog",
        ["expand"] = true,
        ["child"]  = { { ["type"] = 'dialogtask', attr = {} } }
    },
    allowchild  = {},
    allowparent = { 'bossdefine' },
    totext      = function(nodedata)
        return "dialog"
    end,
    tohead      = function(nodedata)
        return string.format(dialog_head_fmt, nodedata.attr[1], nodedata.attr[2], nodedata.attr[1])
    end,
    tofoot      = function(nodedata)
        return string.format("end\ntable.insert(_editor_class[%q].cards, _tmp_sc)\n", M.className)
    end
}
local dialogtask = {
    disptype     = {
        en = 'task for dialog',
        zh = '对话task',
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
local sentence = {
    { 'Image', 'image', CheckNonBlank },
    { 'Position', 'leftright', CheckNonBlank },
    { 'Text', 'any' },
    { 'Time (frames)', 'any', CheckExprOmit },
    { 'Scale', 'any', CheckExprOmit },
    editfirst    = true,
    disptype     = {
        en = 'add sentence of dialog',
        zh = '添加对话语句',
    },
    needancestor = { 'dialogtask' },
    allowchild   = {},
    totext       = function(nodedata)
        return string.format("%s %s %q", nodedata.attr[1], nodedata.attr[2], nodedata.attr[3])
    end,
    tohead       = function(nodedata)
        local t = nodedata.attr[4]
        local s = nodedata.attr[5]
        if t == "" then
            t = "nil"
        end
        if s == '' then
            return string.format("boss.dialog.sentence(self,%q,%q,%q,%s)\n", nodedata.attr[1], nodedata.attr[2], nodedata.attr[3], t)

        else
            return string.format("boss.dialog.sentence(self,%q,%q,%q,%s,%s)\n", nodedata.attr[1], nodedata.attr[2], nodedata.attr[3], t, nodedata.attr[5])
        end
    end,
}
local bosscreate_head_fmt = [[local _boss_wait = %s
local _ref = New(_editor_class[%q], _editor_class[%q].cards)
last = _ref
if _boss_wait then
    while IsValid(_ref) do
        task.Wait()
    end
end
]]
local bosscreate = {
    { 'Type name', 'selecttype', CheckNonBlank },
    { 'Wait', 'bool', CheckExpr },
    disptype     = {
        en = 'create boss',
        zh = '创建boss',
    },
    editfirst    = true,
    needancestor = { 'stage' },
    allowchild   = {},
    totext       = function(nodedata)
        return string.format("create boss %q", nodedata.attr[1])
    end,
    tohead       = function(nodedata)
        return string.format(bosscreate_head_fmt, nodedata.attr[2], nodedata.fullclassname, nodedata.fullclassname)
    end,
    check        = function(nodedata)
        local class
        local tname = nodedata.attr[1]
        if M.difficulty and M.watchDict.bossdefine[tname .. ':' .. M.difficulty] then
            class = tname .. ':' .. M.difficulty
        elseif M.watchDict.bossdefine[nodedata.attr[1]] then
            class = tname
        else
            return string.format('boss type %q does not exist', tname)
        end
        nodedata.fullclassname = class
    end,
}
local bossmoveto = {
    { 'Destination', 'any', CheckExpr },
    { 'nFrame', 'any', CheckExprOmit },
    { 'Mode', 'movetomode', CheckExprOmit },
    disptype    = {
        en = 'boss move to',
        zh = '移动boss',
    },
    allowparent = { 'bossdefine' },
    allowchild  = {},
    default     = { ["attr"] = { "0,144", "60", "MOVE_NORMAL" }, ["type"] = "bossmoveto" },
    totext      = function(nodedata)
        local nf
        if IsBlank(nodedata.attr[2]) then
            nf = '1'
        else
            nf = nodedata.attr[2]
        end
        return "move to (" .. nodedata.attr[1] .. ") in " .. nf .. " frame(s)"
    end,
    tohead      = function(nodedata)
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
        return string.format("table.insert(_editor_class[%q].cards, boss.move.New(%s,%s,%s))\n", M.className, nodedata.attr[1], nf, mode)
    end,
}
local bosscast = {
    { 'Time', 'any', CheckExpr },
    needancestor = { 'bossdefine' },
    disptype     = {
        en = 'play boss charging animation',
        zh = '播放boss蓄力动画',
    },
    default      = { ["attr"] = { '60' }, ["type"] = "bosscast" },
    allowchild   = {},
    totext       = function(nodedata)
        return string.format("play a cast animation in %s frame(s)", nodedata.attr[1])
    end,
    tohead       = function(nodedata)
        return string.format("boss.cast(self, %s)\n", nodedata.attr[1])
    end,
}
local bossshowaura = {
    { 'Show aura', 'bool', CheckExpr },
    disptype     = {
        en = 'show/hide boss aura',
        zh = '显示/隐藏boss法阵',
    },
    needancestor = { 'bossdefine' },
    allowchild   = {},
    totext       = function(nodedata)
        return "show/hide aura"
    end,
    tohead       = function(nodedata)
        return string.format("boss.show_aura(self, %s)\n", nodedata.attr[1])
    end,
}
local _def = {
    bossdefine    = bossdefine,
    bossspellcard = bossspellcard,
    bossscstart   = bossscstart,
    bossscfinish  = bossscfinish,
    dialog        = dialog,
    dialogtask    = dialogtask,
    sentence      = sentence,
    bosscreate    = bosscreate,
    bossmoveto    = bossmoveto,
    bosscast      = bosscast,
    bossshowaura  = bossshowaura,
}
for k, v in pairs(_def) do
    require('xe.node_def._def').DefineNode(k, v)
end
