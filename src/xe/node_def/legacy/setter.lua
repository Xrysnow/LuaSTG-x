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

local setv = {
    { 'Object', 'any', CheckExpr },
    { 'Velocity', 'any', CheckExpr },
    { 'Angle', 'any', CheckExpr },
    { 'Aim to player', 'bool', CheckExpr },
    { 'Set rotation', 'bool', CheckExpr },
    disptype     = {
        en = 'set velocity of object',
        zh = '设置object速度',
    },
    forbidparent = { 'folder', 'root' },
    allowchild   = {},
    default      = { ['type'] = 'setv', attr = { 'self', '3', '0', 'false', 'true' } },
    totext       = function(nodedata)
        local aim
        if nodedata.attr[4] == 'true' then
            aim = ' aim to player'
        else
            aim = ''
        end
        return string.format("set %s's velocity=%s angle=%s%s", nodedata.attr[1], nodedata.attr[2], nodedata.attr[3], aim)
    end,
    tohead       = function(nodedata)
        return string.format("SetV2(%s,%s,%s,%s,%s)\n", nodedata.attr[1], nodedata.attr[2], nodedata.attr[3], nodedata.attr[5], nodedata.attr[4])
    end,
}
local setcolor = {
    { 'Object', 'any', CheckExpr },
    { 'Blend mode', 'blend', CheckExprOmit },
    { 'Alpha', 'any', CheckExpr },
    { 'Red', 'any', CheckExpr },
    { 'Green', 'any', CheckExpr },
    { 'Blue', 'any', CheckExpr },
    disptype     = {
        en = 'set color and blend mode of object',
        zh = '设置object颜色与混合模式',
    },
    forbidparent = { 'folder', 'root' },
    allowchild   = {},
    default      = { ['type'] = 'setcolor', attr = { 'self', '', '255', '255', '255', '255' } },
    totext       = function(nodedata)
        return string.format("set %s's color to (%s,%s,%s,%s) and blend mode to %q", nodedata.attr[1], nodedata.attr[3], nodedata.attr[4], nodedata.attr[5], nodedata.attr[6], nodedata.attr[2])
    end,
    tohead       = function(nodedata)
        return string.format("_object.set_color(%s,%q,%s,%s,%s,%s)\n", nodedata.attr[1], nodedata.attr[2], nodedata.attr[3], nodedata.attr[4], nodedata.attr[5], nodedata.attr[6])
    end,
}
local objectsetimg = {
    { 'Object', 'any', CheckExpr },
    { 'Image', 'image', CheckNonBlank },
    disptype     = {
        en = 'set image of object',
        zh = '设置object图像',
    },
    forbidparent = { 'folder', 'root' },
    allowchild   = {},
    default      = { ['type'] = 'objectsetimg', attr = { 'self', '' } },
    totext       = function(nodedata)
        return string.format("set %s's image to %q", nodedata.attr[1], nodedata.attr[2])
    end,
    tohead       = function(nodedata)
        return string.format("%s.img = %q\n", nodedata.attr[1], nodedata.attr[2])
    end,
}
local unitforeach = {
    { 'Group', 'group', CheckExpr },
    disptype       = {
        en = 'iterate object of a group',
        zh = '遍历碰撞组中的object',
    },
    forbidparent   = { 'folder', 'root' },
    forbidancestor = { 'unitforeach' },
    totext         = function(nodedata)
        return string.format("for each unit in group %s", nodedata.attr[1])
    end,
    tohead         = function(nodedata)
        return string.format("for _, unit in ObjList(%s) do\n", nodedata.attr[1])
    end,
    tofoot         = function(nodedata)
        return "end\n"
    end,
}
local unitkill = {
    { 'Object', 'any', CheckExpr },
    { 'Trigger event callback', 'bool', CheckExpr },
    disptype     = {
        en = 'kill object',
        zh = '对object执行kill操作',
    },
    forbidparent = { 'folder', 'root' },
    allowchild   = {},
    default      = { ['type'] = 'unitkill', attr = { 'self', 'true' } },
    totext       = function(nodedata)
        return string.format("kill %s", nodedata.attr[1])
    end,
    tohead       = function(nodedata)
        return string.format("_kill(%s, %s)\n", nodedata.attr[1], nodedata.attr[2])
    end,
}
local unitdel = {
    { 'Object', 'any', CheckExpr },
    { 'Trigger event callback', 'bool', CheckExpr },
    disptype     = {
        en = 'delete object',
        zh = '对object执行delete操作',
    },
    forbidparent = { 'folder', 'root' },
    allowchild   = {},
    default      = { ['type'] = 'unitdel', attr = { 'self', 'true' } },
    totext       = function(nodedata)
        return string.format("delete %s", nodedata.attr[1])
    end,
    tohead       = function(nodedata)
        return string.format("_del(%s, %s)\n", nodedata.attr[1], nodedata.attr[2])
    end,
}
--
local setaccel = {
    { 'Object', 'any', CheckExpr },
    { 'Acceleration', 'any', CheckExpr },
    { 'Angle', 'any', CheckExpr },
    { 'Aim to player', 'bool', CheckExpr },
    disptype     = {
        en = 'set acceleration of object',
        zh = '设置object加速度',
    },
    forbidparent = { 'root', 'folder' },
    allowchild   = {},
    default      = { ['type'] = 'setaccel', ['attr'] = { 'self', '0.05', '0', 'false' } },
    totext       = function(nodedata)
        local ret
        if nodedata.attr[3] == 'original' then
            ret = "set acceleration of " .. nodedata.attr[2] .. " , at the velocity direction"
        else
            ret = "set acceleration of " .. nodedata.attr[2] .. " , angle of " .. nodedata.attr[3]
        end
        if nodedata.attr[4] == "true" then
            ret = ret .. ", aim to player"
        end
        return ret
    end,
    tohead       = function(nodedata)
        local rot = nodedata.attr[3]
        if rot == "original" then
            rot = "'original'"
        end
        return string.format("_set_a(%s, %s, %s, %s)\n", nodedata.attr[1], nodedata.attr[2], rot, nodedata.attr[4])
    end
}
local setgravity = {
    { 'Object', 'any', CheckExpr },
    { 'Gravity', 'any', CheckExpr },
    disptype     = {
        en = 'set gravity of object',
        zh = '设置object重力',
    },
    forbidparent = { 'root', 'folder' },
    allowchild   = {},
    default      = { ['type'] = 'setgravity', ['attr'] = { 'self', '0.05' } },
    totext       = function(nodedata)
        return "set gravity of " .. nodedata.attr[2]
    end,
    tohead       = function(nodedata)
        return string.format("_set_g(%s, %s)\n", nodedata.attr[1], nodedata.attr[2])
    end
}
local setfv = {
    { 'Object', 'any', CheckExpr },
    { 'Max velocity', 'any', CheckExpr },
    { 'Max X-velocity', 'any', CheckExpr },
    { 'Max Y-velocity', 'any', CheckExpr },
    disptype     = {
        en = 'set velocity limit of object',
        zh = '设置object速度限制',
    },
    forbidparent = { 'root', 'folder' },
    allowchild   = {},
    default      = { ['type'] = 'setfv', ['attr'] = { 'self', 'original', 'original', 'original' } },
    totext       = function(nodedata)
        local ret = "set "
        if nodedata.attr[2] ~= "original" then
            if ret ~= "set " then
                ret = ret .. ","
            end
            ret = ret .. " max velocity of " .. nodedata.attr[2]
        end
        if nodedata.attr[3] ~= "original" then
            if ret ~= "set " then
                ret = ret .. ","
            end
            ret = ret .. " max X-velocity of " .. nodedata.attr[3]
        end
        if nodedata.attr[4] ~= "original" then
            if ret ~= "set " then
                ret = ret .. ","
            end
            ret = ret .. " max Y-velocity of " .. nodedata.attr[4]
        end
        if ret == "set " then
            ret = ret .. "nothing"
        end
        return ret
    end,
    tohead       = function(nodedata)
        local attr = {}
        for i = 2, 4 do
            attr[i] = nodedata.attr[i]
        end
        local v, vx, vy = unpack(attr, 2, 4)
        if v == "original" then
            v = "'original'"
        end
        if vx == "original" then
            vx = "'original'"
        end
        if vy == "original" then
            vy = "'original'"
        end
        return string.format("_forbid_v(%s, %s, %s, %s)\n", nodedata.attr[1], v, vx, vy)
    end
}
--]]
local _def = {
    setv         = setv,
    setcolor     = setcolor,
    objectsetimg = objectsetimg,
    unitforeach  = unitforeach,
    unitkill     = unitkill,
    unitdel      = unitdel,

    setaccel     = setaccel,
    setgravity   = setgravity,
    setfv        = setfv,
}
for k, v in pairs(_def) do
    require('xe.node_def._def').DefineNode(k, v)
end
