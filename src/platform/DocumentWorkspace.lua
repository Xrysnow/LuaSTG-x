-- Materialize a provider directory for editor tools that need sibling files.
local M = {}
local native, fu = cc.FileDialog, cc.FileUtils:getInstance()
local serial = 0

local function reserve(kind, parent)
    local root = fu:ensureAppDirectory(kind, parent)
    if root.status ~= 0 then return nil, 'Application directory unavailable' end
    for _ = 1, 64 do
        serial = serial + 1
        local path = ('%s%d-%d'):format(root.path, os.time(), serial)
        if lfs.mkdir(fu:getSuitableFOpen(path)) then return path end
    end
    return nil, 'Could not reserve a working directory'
end

local function safe(name)
    return type(name) == 'string' and name ~= '' and name ~= '.' and name ~= '..' and not name:find('[/\\:%c]')
end

function M.prepared(name, prepare, consume)
    if not safe(name) then print('Invalid export name'); return end
    local root, err = reserve(1, 'editor-export')
    if not root then print(err); return end
    local path = root .. '/' .. name
    local function cleanup()
        fu:removeFile(path)
        lfs.rmdir(fu:getSuitableFOpen(root))
    end
    local ok, written = pcall(prepare, path)
    if not ok or not written then cleanup(); print('Could not prepare ' .. name); return end
    local consumed, message = pcall(consume, path, cleanup)
    if not consumed then cleanup(); print(message) end
end

function M.copy(directory, callback, isCurrent)
    local root, err = reserve(0, 'editor-workspaces')
    if not root then print(err); return end
    local pending = {{ doc = directory, path = root, depth = 0 }}
    local files, directories = {}, {root}
    local remaining, count = 512 * 1024 * 1024, 0
    local function fail(message)
        for _, path in ipairs(files) do fu:removeFile(path) end
        for i = #directories, 1, -1 do lfs.rmdir(fu:getSuitableFOpen(directories[i])) end
        if message then print(message) end
    end
    local function step()
        local item = table.remove(pending)
        if isCurrent and not isCurrent() then return fail() end
        if not item then
            print('Editing local working copy: ' .. root)
            return callback(root)
        end
        local function complete(result)
            if item.file and result.status == 'ok' then files[#files + 1] = item.path end
            if isCurrent and not isCurrent() then return fail() end
            if result.status ~= 'ok' then return fail(result.error and result.error.message or 'Copy cancelled') end
            if item.file then
                local size = fu:getFileSize(item.path)
                if size < 0 or size > remaining then return fail('Project byte limit exceeded') end
                remaining = remaining - size
            else
                if result.nextPage then item.page = result.nextPage; pending[#pending + 1] = item end
                for _, doc in ipairs(result.documents) do
                    count = count + 1
                    local info = doc:info()
                    if count > 8192 or item.depth >= 32 or not safe(info.displayName) then
                        return fail('Project contains too many entries or an unsupported name')
                    end
                    local path = item.path .. '/' .. info.displayName
                    local file = info.kind == 'file'
                    if not file then
                        if not lfs.mkdir(fu:getSuitableFOpen(path)) then return fail('Cannot create ' .. path) end
                        directories[#directories + 1] = path
                    end
                    pending[#pending + 1] = {doc = doc, path = path, depth = item.depth + 1, file = file}
                end
            end
            step()
        end
        local request, error
        if item.file then
            request, error = native.importFile(item.doc, {destination = item.path, maxBytes = remaining}, complete)
        else
            request, error = native.listChildren(item.doc, {pageToken = item.page, limit = 128}, complete)
        end
        if not request then fail(error.message) end
    end
    step()
end

-- Project files refer to assets relative to their containing directory. A
-- provider-backed project therefore needs the user to grant its whole folder.
function M.openProject(directory, callback, isCurrent)
    local dialogs = require('platform.FileDialog')
    local director = cc.Director:getInstance()
    local scene = director:getRunningScene()
    local function current()
        return director:getRunningScene() == scene and (not isCurrent or isCurrent())
    end
    local function chooseFolder()
        return dialogs.folderPath(directory, function(root)
            local ok, found, message = pcall(function()
                local project
                local entries, directory = lfs.dir(fu:getSuitableFOpen(root))
                for entry in entries, directory do
                    local lower = entry:lower()
                    if lower:match('%.lstgxproj$') or lower:match('%.luastg$') then
                        local path = root .. '/' .. entry
                        if lfs.attributes(fu:getSuitableFOpen(path), 'mode') == 'file' then
                            if project then
                                directory:close()
                                return nil, 'Select a folder containing one project file'
                            end
                            project = path
                        end
                    end
                end
                return project, 'No project file in the selected folder'
            end)
            if not ok then print(found)
            elseif found then callback(found)
            else print(message) end
        end, current)
    end
    if not native.capabilities().chooseSaveTarget then return chooseFolder() end
    local request, error = native.openFiles({filters = {{label = 'Project', extensions = {'lstgxproj', 'luastg'}}},
        allowAllFiles = false, initialDirectory = directory and native.fromLocalPath(directory, 'directory')}, function(result)
        if not current() then return end
        if result.status == 'ok' then
            local path = result.documents[1]:tryGetLocalPath()
            if path then callback((path:gsub('\\', '/'))) else chooseFolder() end
        elseif result.error then print(result.error.message) end
    end)
    if not request then print(error.message) end
    return request
end

return M
