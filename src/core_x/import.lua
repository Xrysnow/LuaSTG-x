---
--- import.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---


local function ListFiles(rootpath, pathes)
    pathes = pathes or {}
    assert(rootpath)
    local files = plus.EnumFiles(rootpath)
    for i, v in ipairs(files) do
        if not v.isDirectory then
            table.insert(pathes, v.fullPath)
        end
    end
    return pathes
end

local function GetExtension(str)
    return str:match(".+%.(%w+)$")
end

local function ListScripts(rootpath)
    local fs = ListFiles(rootpath)
    local ret = {}
    for i, v in pairs(fs) do
        if GetExtension(v) == 'lua' then
            table.insert(ret, string.sub(v, 1))
        end
    end
    return ret
end

local function GetFolder(filePath, slash)
    local p1 = string.match(filePath, "^(.*)\\")
    local p2 = string.match(filePath, "^(.*)/")
    local ret
    if p1 and p2 then
        ret = (#p1 > #p2) and p1 or p2
    else
        ret = p1 or p2
    end
    if slash and ret and ret:sub(-1) ~= '/' then
        ret = ret .. '/'
    end
    return ret
end

local _IN_FROM = false
local _FROM_PATH = ''

---指定导入模块的位置，只能以根目录为基准
---@param path string
---@return void
function from(path)
    if not _IN_FROM then
        _FROM_PATH = path
        if path == '' then
            _FROM_PATH = string.sub(_FROM_PATH, 1, -2)
        elseif path == '.' then
            --使用同级目录
            local p = debug.getinfo(2, "S").source
            _FROM_PATH = GetFolder(p)
            assert(_FROM_PATH, 'FROM_PATH not exist at ' .. p)
            --SystemLog('\nfrom: search in ' .. _FROM_PATH)
            --SystemLog(stringify(ListScripts(_FROM_PATH)))
        end
        _IN_FROM = true
    else
        error('Incomplete from ... import.')
    end
end

---导入模块，以当前目录、from目录或根目录为基准
---@param module string
---@return void
function import(module)
    module = string.gsub(module, '\\', '/')
    module = string.gsub(module, '//', '/')
    --module = string.gsub(module, '\\\\', '\\')
    assert(module and module ~= '', 'import: module is null!')
    if not _IN_FROM then
        --先查找同级目录
        local p = debug.getinfo(2, "S").source
        p = GetFolder(p, true)
        assert(p and p ~= '', 'import: can not find source root of ' .. module)
        local p1 = p .. module .. '.lua'
        if plus.FileExists(p1) then
            Include(p1)
            return
        end
        local p2 = p .. module .. '/__init__.lua'
        if plus.FileExists(p2) then
            Include(p2)
            return
        end
        --再查找根目录
        local p3 = './' .. module .. '/__init__.lua'
        if plus.FileExists(p3) then
            Include(p3)
            return
        end
        local err = string.format('Can not find module %s at:\n%s\n%s\n%s',
                module, p1, p2, p3)
        --Print(err)
        error(err)
    else
        _IN_FROM = false
        if module == '*' then
            local fs = ListScripts(_FROM_PATH)
            for i, v in pairs(fs) do
                Include(v)
            end
        else
            --Include(_FROM_PATH .. '/' .. module .. '.lua')
            import(_FROM_PATH .. '/' .. module)
        end
    end
end
