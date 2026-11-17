local base = require('xe.input.Base')
---@class xe.input.Path:xe.input.Base
local M = class('xe.input.Path', base)
local im = imgui
local wi = require('imgui.Widget')
local log = require('xe.logger').log
local _res = {
    loadsound      = true,
    loadbgm        = true,
    loadimage      = true,
    loadtexture    = true,
    loadimagegroup = true,
    loadani        = true,
    loadparticle   = true,
    loadFX         = true, }

---@param node xe.SceneNode
function M:ctor(node, idx, wildCard, isFolder)
    base.ctor(self, node, idx, 'path')
    local value = node:getAttrValue(idx) or ''
    self._value = value

    local btn = wi.Button(require('xe.ifont').FolderOpen, function()
        self:_open(wildCard, isFolder)
    end)

    self:addChild(btn):addChild(im.sameLine)

    local nt = node:getType()
    if nt == 'loadimage' then
        self:addChild(wi.Button(require('xe.ifont').FolderOpen, function()
            local path = self._value
            require('xe.image.util').create(path:filename(), path)
        end))
    end

    self:addChild(function()
        local txt = self._value
        local popup
        if #txt > 30 then
            txt = '...' .. txt:sub(-27, -1)
            popup = true
        end
        im.textWrapped(txt)
        --im.text(txt)
        if popup and im.isItemHovered() then
            im.setTooltip(self._value)
        end
    end)
end

function M:_open(wildCard, isFolder)
    local project = require('xe.Project')
    local dir = project.getDir()
    if not dir then return end
    local generation = project.getGeneration()
    local node = self._node
    local nt = node:getType()
    local tree = require('xe.main').getTree()
    local function current()
        return project.getGeneration() == generation and self:isRunning() and tree:getCurrent() == node
    end
    local dialogs = require('platform.FileDialog')
    local function selected(path)
        if not current() then return end
        local root = dir:sub(-1) == '/' and dir or dir .. '/'
        if path:starts_with(root) then
            self:_applyPath(path:sub(#root + 1), nt, path)
        elseif isFolder then
            self:_applyPath(path, nt, path)
        else
            local name = path:filename(true)
            local target = root .. name
            if cc.FileUtils:getInstance():isFileExist(target) then
                log(('file %s already exists'):format(name), 'warn')
                self:_applyPath(name, nt, target)
                return
            end
            local src = cc.FileDialog.fromLocalPath(path)
            local request, err = cc.FileDialog.importFile(src, {destination = target}, function(result)
                if not current() then return end
                if result.status == 'ok' then
                    self:_applyPath(name, nt, target)
                elseif result.error then log(result.error.message, 'error') end
            end)
            if not request then log(err.message, 'error') end
        end
    end
    if isFolder then dialogs.folderPath(dir, selected, current) else dialogs.openPath(wildCard, dir, selected) end
end

function M:_applyPath(path, nt, absolutePath)
    self._value = path
    if _res[nt] then
        -- set res name to file name
        local prop = require('xe.main').getProperty()
        prop:setValue(2, string.filename(path))
        if nt == 'loadparticle' then
            local f, msg = io.open_u8(absolutePath, 'rb')
            if f == nil then
                log(msg, "error", nt)
            else
                local s = f:read(1)
                f:close()
                if s then prop:setValue(3, 'parimg' .. (s:byte(1) + 1)) end
            end
        end
    end
    self:submit()
end

return M
