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

local patch = {
    { 'path', 'resfile', CheckNonBlank },
    editfirst   = true,
    allowparent = { 'root', 'folder' },
    allowchild  = {},
    totext      = function(nodedata)
        --local fname = wx.wxFileName(nodedata.attr[1]):GetFullName()
        local fname = string.filename(nodedata.attr[1], true)
        return string.format("patch %q", fname)
    end,
    tohead      = function(nodedata)
        --local fname = wx.wxFileName(nodedata.attr[1]):GetFullName()
        local fname = string.filename(nodedata.attr[1], true)
        return string.format("Include(%q)\n", fname)
    end,
    check       = function(nodedata)
        local absfn = MakeFullPath(nodedata.attr[1])
        if not absfn or absfn == '' then
            return string.format("Resource file %q does not exist", nodedata.attr[1])
        end
        --local fn = wx.wxFileName(nodedata.attr[1]):GetFullName()
        local fn = string.filename(nodedata.attr[1], true)
        if not CheckResFileInPack(fn) then
            return string.format("Repeated resource file name %q", fn)
        end
        --local f, msg = io.open("editor\\tmp\\_pack_res.bat", "a")
        --if msg then
        --    return msg
        --end
        --f:write(string.format('..\\tools\\7z\\7z u -tzip -mcu=on "..\\game\\mod\\%s.zip" "%s"\n', outputName, absfn))
        --f:write(string.format('cd /D "%s" \n', wx.wxFileName(absfn):GetPath(wx.wxPATH_GET_VOLUME)))
        --f:write(string.format('"%s\\..\\tools\\7z\\7z" u -tzip -mcu=on "%s\\mod\\%s.zip" THlib\n', cwd, cwd, outputName))
        --f:write(string.format('cd /D "%s" \n', cwd))
        --f:close()
        require('xe.Project').addPackRes(absfn, 'patch')
    end
}
local _def = {
    patch = patch,
}
for k, v in pairs(_def) do
    require('xe.node_def._def').DefineNode(k, v)
end
