--
local M = {}

---@return string,string
local function checkReturn(ret)
    if ret ~= '' then
        return ret:gsub('\\', '/')
    end
    local err = lstg.FileDialog:getLastError()
    if err == 'cancel' then
        --return
    else
        print(string.format('got error in FileDialog: %s', err))
        --return
    end
    return nil, err
end

local function makeFilter(filter)
    if not filter then
        return ''
    end
    local str = ''
    if type(filter) == 'string' then
        str = filter
    else
        for _, f in ipairs(filter) do
            if type(f) == 'string' then
                str = str .. f .. ';'
            else
                str = str .. table.concat(f, ',') .. ';'
            end
        end
        str = str:sub(1, -2)
    end
    return str
end

local function splitFilter(filter)
    filter = makeFilter(filter)
    local ret = {}
    for _, v in ipairs(string.split(filter, ';') or {}) do
        for _, u in ipairs(string.split(v, ',') or {}) do
            table.insert(ret, u)
        end
    end
    return ret
end

--- File dialog for 'open'
--- If successed, return path. If cancelled, return nil and 'cancel'. If failed, return nil and message.
---@param filter string|table
---@param defaultPath string
function M.open(filter, defaultPath)
    --TODO: move to cpp
    if defaultPath and jit.os == 'Windows' then
        defaultPath = defaultPath:gsub('/', '\\')
    end
    return checkReturn(lstg.FileDialog:open(makeFilter(filter), defaultPath or ''))
end

---
---@param filter string|table
---@param defaultPath string
function M.openMultiple(filter, defaultPath)
    local ret = lstg.FileDialog:openMultiple(makeFilter(filter), defaultPath or '')
    if #ret > 0 then
        return ret
    end
    local err = lstg.FileDialog:getLastError()
    if err == 'cancel' then
        --return
    else
        Print(string.format('got error in FileDialog: %s', err))
    end
    return nil, err
end

---
---@param filter string|table
---@param defaultPath string
function M.save(filter, defaultPath)
    local path, msg = checkReturn(lstg.FileDialog:save(makeFilter(filter), defaultPath or ''))
    if path and string.fileext(path) == '' then
        local ext = splitFilter(filter)[1]
        if ext and ext ~= '' then
            path = path .. '.' .. ext
        end
    end
    return path, msg
end

---
---@param defaultPath string
function M.pickFolder(defaultPath)
    return checkReturn(lstg.FileDialog:pickFolder(defaultPath or ''))
end

-- A logical request spans the native selection and any following import. Legacy
-- callers keep one numeric ID and can cancel whichever operation is current.
local native = cc.FileDialog
local active = {}
local nextId = 2 ^ 31
local function start(callback, submit)
    assert(type(callback) == 'function', 'a completion callback is required')
    local id = nextId
    nextId = nextId + 1
    local function finish(result)
        if not active[id] then return end
        active[id] = nil
        result.requestId = id
        callback(result)
    end
    local function attach(request, err)
        if request then active[id] = request end
        return request, err
    end
    local request, err = submit(finish, attach)
    if not request then return nil, err and err.message or 'document request failed' end
    return id
end

local function legacy(result)
    local status = result.status
    if status == 'ok' then status = 'success'
    elseif result.error and result.error.code == 'permissionDenied' then status = 'denied' end
    local message = result.error and result.error.message or ''
    if status == 'cancelled' and message == '' then
        message = result.cancelReason == 'caller' and 'Request cancelled by caller' or 'User cancelled the document picker'
    end
    return { status = status, path = '', uri = '', message = message,
        error = result.error, effect = result.effect, cancelReason = result.cancelReason }
end

function M.cancel(id)
    local request = active[id]
    return request and request:cancel() == 'accepted' or false
end

local function options(filter, directory)
    local filters = {}
    for group in makeFilter(filter):gmatch('[^;]+') do
        local extensions = {}
        for ext in group:gmatch('[^,]+') do extensions[#extensions + 1] = ext end
        filters[#filters + 1] = { label = group, extensions = extensions }
    end
    return { filters = filters, allowAllFiles = #filters == 0,
        initialDirectory = directory and native.fromLocalPath(directory, 'directory') or nil }
end

local function selectPaths(opts, copyAll, callback)
    return start(callback, function(finish, attach)
        return attach(native.openFiles(opts, function(selection)
            local result = legacy(selection)
            if selection.status ~= 'ok' then return finish(result) end
            local paths = {}
            local function advance(index)
                while index <= #selection.documents do
                    local doc = selection.documents[index]
                    local path = not copyAll and doc:tryGetLocalPath()
                    if not path then
                        local request, err = attach(native.importFile(doc, {}, function(copied)
                            if copied.status ~= 'ok' then return finish(legacy(copied)) end
                            paths[index] = copied.documents[1]:tryGetLocalPath():gsub('\\', '/')
                            advance(index + 1)
                        end))
                        if not request then finish(legacy({status = 'error', error = err})) end
                        return
                    end
                    paths[index] = path:gsub('\\', '/')
                    index = index + 1
                end
                result.path, result.paths = paths[1], paths
                finish(result)
            end
            advance(1)
        end))
    end)
end

function M.importAsync(mime, callback)
    return selectPaths({ filters = {{ mimeTypes = {mime or '*/*'} }}, allowAllFiles = false }, true, callback)
end

function M.exportPath(source, suggestedName, mime, callback)
    local doc, err = native.fromLocalPath(source)
    if not doc then return nil, err.message end
    return start(callback, function(finish, attach)
        return attach(native.exportFile({ suggestedName = suggestedName or '',
            contentType = { mimeTypes = {mime or 'application/octet-stream'} } }, doc, function(exported)
            local result = legacy(exported)
            if result.status == 'success' and exported.destination then
                result.uri = exported.destination:legacyAndroidUri()
            end
            result.displayName = exported.displayName
            finish(result)
        end))
    end)
end

function M.exportAsync(source, suggestedName, mime, callback)
    assert(type(source) == 'string', 'an app-owned source path is required')
    if lstg.GetPlatform() == 'android' then
        source = require('platform.android.native').canonicalAppOwnedDocumentSource(source)
        if not source then return nil, 'An app-owned source file is required' end
    end
    return M.exportPath(source, suggestedName, mime, callback)
end

-- Editor continuations receive paths only after scoped documents have been imported.
function M.openPaths(filter, directory, multiple, callback)
    local opts = options(filter, directory)
    opts.allowMultiple = multiple
    return selectPaths(opts, false, callback)
end

local function notify(result)
    if result.status == 'error' or result.status == 'denied' then print(result.message) end
end
function M.openPath(filter, directory, callback)
    local id, err = M.openPaths(filter, directory, false, function(result)
        if result.status == 'success' then callback(result.path) else notify(result) end
    end)
    if not id then print(err) end
    return id
end

function M.selectDirectory(directory, callback)
    local r, err = native.pickFolder(options(nil, directory), function(result)
        if result.status == 'ok' then callback(result.documents[1])
        elseif result.error then print(result.error.message) end
    end)
    if not r then print(err.message) end
    return r
end

-- Folder-based tools can consume the grant themselves. Path-only editors work
-- in an app-owned copy when the selected directory needs a provider grant.
function M.folderPath(directory, callback, isCurrent)
    return M.selectDirectory(directory, function(doc)
        if isCurrent and not isCurrent() then return end
        local path = doc:tryGetLocalPath()
        if path then return callback((path:gsub('\\', '/'))) end
        require('platform.DocumentWorkspace').copy(doc, callback, isCurrent)
    end)
end

function M.exportPrepared(name, mime, prepare)
    return require('platform.DocumentWorkspace').prepared(name, prepare, function(path, done)
        local document, err = native.fromLocalPath(path)
        if not document then done(); print(err.message); return end
        local request, error = native.exportFile({ suggestedName = name,
            contentType = { mimeTypes = {mime or 'application/octet-stream'} } }, document, function(result)
            done()
            notify(legacy(result))
        end)
        if not request then done(); print(error.message) end
    end)
end

return M
