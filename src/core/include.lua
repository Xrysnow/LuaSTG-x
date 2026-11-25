local FU = cc.FileUtils:getInstance()
---已包含的脚本
lstg.included = {}

---脚本搜索路径
lstg.current_script_path = { '' }
local parentHits = setmetatable({}, { __mode = 'k' })

---
--- 包含（执行）脚本文件
---@param filename string
---@return any 脚本返回值
function Include(filename)
    filename = tostring(filename)
    filename = string.gsub(filename, '\\', '/')
    local paths = lstg.current_script_path
    local hits = parentHits[paths]
    if not hits then
        hits = {}
        parentHits[paths] = hits
    end
    local hit
    if filename:sub(1, 1) == '~' then
        local relative = filename:sub(2)
        local parent = hits[#paths]
        if parent then
            hit = FU:findSibling(parent, relative)
        else
            hit = FU:findFile(paths[#paths] .. relative)
        end
    else
        hit = FU:findFile(filename)
    end
    if not hit then
        error(string.format('%s: %s', i18n "can't find script", filename))
    end
    local key = hit.adapterId .. ':' .. hit.entryKey
    if not lstg.included[key] then
        local source = hit.nativePath or hit.entryKey
        local data, err = FU:readFile(hit)
        if not data then
            error(('failed to read %q (error %d)'):format(filename, err.code))
        end
        local script = assert(loadstring(data, '@' .. source))
        local index = #paths + 1
        paths[index] = source:match('^.*[/\\]') or ''
        hits[index] = hit
        lstg.included[key] = true
        local ok, result = pcall(script)
        paths[index] = nil
        hits[index] = nil
        if not ok then
            lstg.included[key] = nil
            error(result, 0)
        end
        return result
    end
end

