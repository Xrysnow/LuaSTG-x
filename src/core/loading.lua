local FU = cc.FileUtils:getInstance()

local function physicalFile(path)
    for _, adapter in ipairs(FU:getReadAdapters()) do
        if adapter.kind == 'physical' then
            local hit = FU:findFileIn(adapter.id, path)
            if hit and hit.nativePath then
                return hit.nativePath
            end
        end
    end
end

---
function lstg.loadData()
    local wp = plus.getWritablePath()
    for _, v in ipairs({ 'data', 'data_assets', 'background' }) do
        local possible_dir = { v .. '/', wp .. v .. '/' }
        local possible_zip = { v .. '.zip', wp .. v .. '.zip' }
        local find = false
        for _, dir in ipairs(possible_dir) do
            if FU:isDirectoryExist(dir) then
                local fp = FU:fullPathForDirectory(dir)
                if fp ~= '' then
                    FU:addSearchPath(fp)
                    SystemLog(string.format(i18n "load %s from local path %q", v, fp))
                    find = true
                    break
                end
            end
        end
        if not find then
            for _, zip in ipairs(possible_zip) do
                local fp = physicalFile(zip)
                if fp then
                    SystemLog(string.format(i18n "load %s from %q", v, fp))
                    LoadPack(fp)
                    find = true
                    break
                end
            end
        end
        if not find then
            Print(string.format('%s %q', i18n "can't find", v))
            --Print(stringify(possible_dir), stringify(possible_zip))
        end
    end
end

--

lstg.eventDispatcher:addListener('load.THlib.after', function()
    Include('game/after_load.lua')
end, 1, 'load.data.x')

function lstg.loadMod()
    local p = plus.getWritablePath()
    assert(type(setting.mod) == 'string' and setting.mod ~= ''
            and setting.mod ~= '.' and setting.mod ~= '..'
            and not setting.mod:find('[/\\]'), 'invalid mod name')
    if plus.os == 'android' and setting.mod_info and setting.mod_info.bundled then
        p = ''
    end
    if p ~= '' and p:sub(-1) ~= '/' and p:sub(-1) ~= '\\' then
        p = p .. '/'
    end
    local path = p .. 'mod/' .. setting.mod
    local dir, zip = true, true
    if setting.mod_info then
        dir = setting.mod_info.isDirectory
        zip = not dir
    end
    if dir and plus.FileExists(path .. '/root.lua') then
        FU:addSearchPath(path)
        SystemLog(string.format(i18n 'load mod %q from local path', setting.mod))
    elseif zip and physicalFile(path .. '.zip') then
        SystemLog(string.format(i18n 'load mod %q from zip file', setting.mod))
        LoadPack(path .. '.zip')
    else
        error(string.format('%s: %s', i18n "can't find mod", path))
    end
    SetResourceStatus('global')
    lstg.loadPlugins()

    lstg.eventDispatcher:dispatchEvent('load.THlib.before')
    Include('root.lua')
    lstg.eventDispatcher:dispatchEvent('load.THlib.after')
    DoFile('core/score.lua')

    RegisterClasses()
    SetTitle(setting.mod)
    SetResourceStatus('stage')
end

function lstg.enumPlugins()
    --local p = plus.getWritablePath() .. 'plugin/'
    local p = 'plugin/'
    if not FU:isDirectoryExist(p) then
        SystemLog('no direcory for plugin')
        return {}
    end
    local path = FU:fullPathForDirectory(p)
    FU:addSearchPath(path)
    SystemLog(string.format('enum plugins in %q', path))
    local ret = {}
    local files = plus.EnumFiles(path)
    for i, v in ipairs(files) do
        -- skip name start with dot
        if v.name:sub(1, 1) ~= '.' then
            if v.isDirectory then
                if plus.FileExists(path .. v.name .. '/__init__.lua') then
                    table.insert(ret, v)
                end
            else
                if string.lower(string.fileext(v.name)) == 'zip' then
                    v.name = v.name:sub(1, -5)
                    assert(v.name ~= '')
                    table.insert(ret, v)
                end
            end
        end
    end
    return ret
end

plugin = {}
local plugin_list = {}

function lstg.loadPlugins()
    local files = lstg.enumPlugins()
    for i, v in ipairs(files) do
        local name = v.name
        if v.isDirectory then
            local fp = string.format('plugin/%s/__init__.lua', name)
            if FU:isFileExist(fp) then
                SystemLog(string.format(i18n 'load plugin %q from local path', name))
                Include(fp)
            end
        else
            local fp = physicalFile('plugin/' .. name .. '.zip')
            if fp then
                SystemLog(string.format(i18n 'load plugin %q from zip file', name))
                LoadPack(fp)
                Include(name .. '/__init__.lua')
            end
        end
        table.insert(plugin_list, v)
    end
end

function lstg.getPluginList()
    return plugin_list
end
