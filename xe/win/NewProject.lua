local base = require('imgui.Widget')
---@class xe.NewProject:im.Widget
local M = class('xe.NewProject', base)
local im = imgui
local wi = base
local err = require('xe.logger').getLogger('New Project', 'error')
local _templates = { 'Empty', 'Single Stage', 'Single Spell Card', 'TouHou' }

function M:ctor()
    base.ctor(self)
    self:enableNodeEvents()

    local frame = wi._begin_end_wrapper(function()
        local sz = im.vec2(-1, -im.getFrameHeightWithSpacing())
        return im.beginChildFrame(im.getID('xe.newproj.content'), sz)
    end, im.endChildFrame)
    self:addChild(frame)

    self._sel = 1
    self._template = _templates[1]
    local group = wi.RadioButtonGroup(_templates, function(_, ii)
        self._sel = ii
        self._template = _templates[ii]
    end, 1)
    self._group = group

    frame:addChild(wi.Text('Template')):addChild(group):addChild(im.separator)

    self._path = ''

    local btn = wi.Button(require('xe.ifont').FolderOpen, function()
        self:_pickFolder()
    end)
    frame:addChildren(wi.Text('Folder'), btn, im.sameLine)
    frame:addChild(function()
        if self._path == '' then
            im.textDisabled('Select a folder')
        else
            im.textWrapped(self._path)
        end
    end)
    frame:addChild(im.separator)
    frame:addChild(wi.Text('Project name'))

    self._name = 'NewProj'
    local input = wi.InputText('', self._name)
    frame:addChild(input):addChild(function()
        if im.isItemDeactivatedAfterEdit() then
            local s = input:getString()
            s = self:_checkName(s)
            if not s then
                im.sameLine()
                im.text('Invalid name')
                self._name = ''
            else
                self._name = s
            end
        end
    end)

    local ok = wi.Button('OK', std.bind(self._ok, self))
    local cancel = wi.Button('Cancel', std.bind(self._cancel, self))
    self:addChildren(ok, im.sameLine, cancel)
end

function M:_ok()
    if self._path == '' or self._name == '' then
        return
    end
    local template = ('xe/templates/%s.txt'):format(self._template)
    local fu = cc.FileUtils:getInstance()
    local str = fu:getStringFromFile(template)
    if str == '' then
        err("can't find template %s", self._template)
        return
    end

    local folder = ('%s%s'):format(self._path, self._name)
    local lfs = lfs
    local ret, msg
    ret, msg = lfs.mkdir(fu:getSuitableFOpen(folder))
    if not ret then
        err("failed to create folder %s", folder)
        return
    end
    local path = ('%s/%s.lstgxproj'):format(folder, self._name)
    ret, msg = lfs.attributes(fu:getSuitableFOpen(path), 'mode')
    if ret then
        err("file %s already exists", path)
        return
    end
    local f = io.open_u8(path, 'wb+')
    if not f then
        err("failed to create file %s", path)
        return
    end
    f:write(str)
    f:close()

    require('xe.Project')._loadFromFile(path)
    --
    self:_cancel()
end

function M:_cancel()
    self:onExit()
    self:setVisible(false)
end

function M:onExit()
    self._folderToken = nil
    local request = self._folderRequest
    self._folderRequest = nil
    if request then request:cancel() end
end

function M:_pickFolder()
    if self._folderRequest then self._folderRequest:cancel() end
    local token = {}
    self._folderToken = token
    local function current()
        return self._folderToken == token and self:isRunning() and self:isVisible()
    end
    self._folderRequest = require('platform.FileDialog').folderPath(nil, function(path)
        self._folderRequest = nil
        self._path = path:sub(-1) == '/' and path or path .. '/'
    end, current)
end

local forbid = [[%*%/%\%|%:%"%<%>%?]]
local forbid_pattern = '[' .. forbid .. ']'
function M:_checkName(s)
    s = string.trim(s)
    if s:match(forbid_pattern) then
        return nil
    end
    return s
end

local _id = 'New Project'
function M:_handler()
    im.setNextWindowSize(im.vec2(200, 300), im.Cond.Once)
    im.openPopup(_id)
    if im.beginPopupModal(_id) then
        wi._handler(self)
        im.endPopup()
    end
end

return M
