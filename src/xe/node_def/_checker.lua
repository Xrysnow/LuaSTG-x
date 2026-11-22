--
local M = {}

M.checkSoundName = {}
M.checkImageName = {}
M.checkAniName = {}
M.checkParName = {}
M.checkBgmName = {}
M.checkAnonymous = {}
M.checkResFile = {}
M.checkClassName = {}
M.watchDict = {}
M.paramNumDict = {}

M.className = nil
M.difficulty = nil
M.parimg = {}
for i = 1, 16 do
    M.parimg['parimg' .. i] = true
end

function M.reset()
    M.checkSoundName = {}
    M.checkImageName = {}
    M.checkAniName = {}
    M.checkParName = {}
    M.checkBgmName = {}
    M.checkAnonymous = {}
    M.checkResFile = {}
    M.checkClassName = {}
    M.watchDict = {}
    M.paramNumDict = {}
    M.className = nil
    M.difficulty = nil
end

local err_str = {
    name          = {
        en = "must be a string of letters, digits, spaces, and underscores, not beginning with a space",
        zh = "必须由字母、数字、下划线和空格组成，不能由空格开始",
    },
    vname         = {
        en = "must be a string of letters, digits, and underscores, not beginning with a digit",
        zh = "必须由字母、数字和下划线组成，不能由数字开始",
    },
    not_empty     = {
        en = "can not be empty",
        zh = "不能为空",
    },
    param_count   = {
        en = "wrong number of parameters: %d, was expecting %d",
        zh = "参数数量错误：%d， 需要 %d",
    },
    dup_type      = {
        en = "duplicated type name %q",
        zh = "重复的类型名称 %q",
    },
    dup_res       = {
        en = "duplicated resource name %q",
        zh = "重复的资源名称 %q",
    },
    res_not_exist = {
        en = "resource file %q does not exist",
        zh = "资源文件 %q 不存在",
    },
}

function M.CalcParamNum(s)
    if string.match(s, "^[%s]*$") then
        return 0
    end
    local b1 = 0
    local b2 = 0
    local ret = 1
    for i = 1, #s do
        local c = string.byte(s, i)
        if b1 == 0 and b2 == 0 and c == 44 then
            -- ','
            ret = ret + 1
        elseif c == 40 then
            -- '('
            b1 = b1 + 1
        elseif c == 41 then
            -- ')'
            b1 = b1 - 1
        elseif c == 123 then
            -- '{'
            b2 = b2 + 1
        elseif c == 125 then
            -- '}'
            b2 = b2 - 1
        end
    end
    return ret
end
local CalcParamNum = M.CalcParamNum

function M.CheckName(s)
    if string.match(s, "^[%w_][%w_ ]*$") == nil then
        return i18n(err_str.name)
    end
end
function M.CheckVName(s)
    if string.match(s, "^[%a_][%w_]*$") == nil then
        return i18n(err_str.vname)
    end
end
function M.CheckExpr(s)
    if string.match(s, "^[%s]*$") then
        return i18n(err_str.not_empty)
    end
    local _, msg = loadstring("return " .. s)
    if msg ~= nil then
        return msg
    end
end
function M.CheckPos(s)
    if string.match(s, "^[%s]*$") then
        return i18n(err_str.not_empty)
    end
    local _, msg = loadstring("return " .. s)
    if msg ~= nil then
        return msg
    end
    local np = CalcParamNum(s)
    if np ~= 2 then
        return i18n(err_str.param_count, np, 2)
    end
end
function M.CheckExprOmit(s)
    local _, msg = loadstring("return " .. s)
    if msg ~= nil then
        return msg
    end
end
function M.CheckCode(s)
    local _, msg = loadstring(s)
    if msg ~= nil then
        return msg
    end
end
function M.CheckParam(s)
    local _, msg = loadstring("return function(" .. s .. ") end")
    if msg ~= nil then
        return msg
    end
end
function M.CheckNonBlank(s)
    if string.match(s, "^[%s]*$") then
        return i18n(err_str.not_empty)
    end
end
function M.CheckClassName(s)
    if string.match(s, "^[%s]*$") then
        return i18n(err_str.not_empty)
    else
        if M.checkClassName[s] then
            return i18n(err_str.dup_type, s)
        else
            M.checkClassName[s] = true
        end
    end
end
function M.IsBlank(s)
    if not s then
        return true
    end
    if string.match(s, "^[%s]*$") then
        return true
    else
        return false
    end
end
--- if name is not already saved in `checkResFile`, save it and return true, otherwise return false
function M.CheckResFileInPack(name)
    if M.checkResFile[name] == nil then
        M.checkResFile[name] = true
        return true
    else
        return false
    end
end
function M.CheckAnonymous(name, fullname)
    if M.checkResFile[name] == nil then
        M.checkResFile[name] = true
        M.checkAnonymous[name] = fullname
        return true
    else
        if M.checkAnonymous[name] == fullname then
            return true
        else
            return false
        end
    end
end

function M.MakeFullPath(path)
    return cc.FileUtils:getInstance():fullPathForFilename(path)
end

function M.AddPackRes(path, name, check, from_type)
    if check[name] == nil then
        check[name] = true
    else
        return i18n(err_str.dup_res, name)
    end
    local absfn = M.MakeFullPath(path)
    if not absfn or absfn == '' then
        return i18n(err_str.res_not_exist, path)
    end
    local fn = string.filename(path, true)
    if not M.CheckResFileInPack(fn) then
        return i18n(err_str.dup_res, fn)
    end
    require('xe.Project').addPackRes(absfn, from_type)
end

function M.AddPackBgm(path, name, from_type)
    local absfn = M.MakeFullPath(path)
    if not absfn or absfn == '' then
        return i18n(err_str.res_not_exist, path)
    end
    if M.checkBgmName[name] == nil then
        M.checkBgmName[name] = path
        --local fn = wx.wxFileName(nodedata.attr[1]):GetFullName()
        local fn = string.filename(path, true)
        if not M.CheckResFileInPack(fn) then
            return i18n(err_str.dup_res, fn)
        end
        require('xe.Project').addPackRes(absfn, from_type)
    else
        if M.checkBgmName[name] ~= path then
            return i18n(err_str.dup_res, name)
        end
    end
end

local _sound = {}
local _load = 'LoadSound'
local _old = _G[_load]
_G[_load] = function(name, path)
    _sound[name] = path
end
DoFile('THlib/se/se.lua')
_G[_load] = _old
function M.getSoundList()
    return _sound
end

return M
