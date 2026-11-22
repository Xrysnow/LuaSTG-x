--
local M = {}
local FU = cc.FileUtils:getInstance()

function M.changeLogPath(path, preservePrevious)
    local lp = lstg.LogSystem:getInstance():getPath()
    if lp ~= path then
        if lstg.LogSystem:getInstance():changePath(path) then
            if not preservePrevious then
                os.remove(lp)
            end
            SystemLog(('change log path to %q'):format(path))
        else
            SystemLog(('failed to change log path to %q'):format(path))
            return false
        end
    end
    return true
end

-- Configure a physical path, then consume FileUtils' normalized result.
-- Directory creation belongs to the writer (including LogSystem.changePath).
local function setWritablePath(path)
    if not FU:setWritablePath(path) then
        error(('failed to configure writable path %q'):format(path))
    end
    local normalized = FU:getWritablePath()
    if normalized == '' then
        error('the writable path is unavailable')
    end
    return normalized
end

function M.changeWritablePath()
    local ret
    local osname = lstg.GetPlatform()
    if osname == 'android' then
        local native = require('platform.android.native')
        local path = native.getInternalDataPath()
        if not path or path == '' then
            error('internal app storage is unavailable')
        end
        -- Match the native files directory used by the log before Lua starts.
        -- Do not add shared storage or imported scripts to the search paths.
        ret = setWritablePath(path)
        if not M.changeLogPath(ret .. 'lstg_log.txt', true) then
            error(('failed to open app log in %q'):format(ret))
        end
    elseif osname == 'mac' then
        local home = os.getenv('HOME')
        if home and #home > 1 then
            -- use Documents
            local path = home .. '/Documents/lstg'
            if FU:isDirectoryExist(path) then
                path = setWritablePath(path)
                if M.changeLogPath(path .. 'lstg_log.txt') then
                    FU:addSearchPath(path)
                    ret = path
                end
            end
        end

        if not ret then
            -- use Resources
            local native = require('platform.apple.native')
            local p = native.getBundleResourcesDirectory()
            if p and #p > 1 and FU:isDirectoryExist(p) then
                local path = setWritablePath(p)
                if M.changeLogPath(path .. 'lstg_log.txt') then
                    FU:addSearchPath(path)
                    ret = path
                else
                    error(('failed to open app log in %q'):format(path))
                end
            end
        end
    elseif osname == 'windows' or osname == 'linux' then
        -- Resolve against the CWD of this call, independently of resource paths.
        ret = setWritablePath('./')
    end
    ret = ret or FU:getWritablePath()
    if ret == '' then
        error('the writable path is unavailable')
    end
    SystemLog(('set local writable path to %q'):format(ret))
    return ret
end

function M.enumMods(path, root_name)
    local ret = {}
    root_name = root_name or 'root.lua'
    local files = plus.EnumFiles(path)
    for i, v in ipairs(files) do
        if v.isDirectory then
            if plus.FileExists(path .. v.name .. '/' .. root_name) then
                table.insert(ret, v)
            end
        else
            if string.lower(v.name:match(".+%.(%w+)$") or '') == 'zip' then
                v.name = v.name:sub(1, -5)
                assert(v.name ~= '')
                table.insert(ret, v)
            end
        end
    end
    table.sort(ret, function(a, b)
        if a.isDirectory ~= b.isDirectory then
            return a.isDirectory
        end
        return a.name < b.name
    end)
    return ret
end

function M.enumAvailableMods()
    local ret = M.enumMods(plus.getWritablePath() .. 'mod/')
    if lstg.GetPlatform() == 'android' then
        local names = {}
        for _, v in ipairs(ret) do names[v.name] = true end
        for _, v in ipairs(M.enumMods('mod/')) do
            if not v.isDirectory then
                -- ResourcePack opens disk files. Never hand it an APK asset path.
                SystemLog(('bundled ZIP mod %q requires import to app storage'):format(v.name))
            elseif not names[v.name] then
                v.bundled = true
                table.insert(ret, v)
            end
        end
    end
    return ret
end

return M
