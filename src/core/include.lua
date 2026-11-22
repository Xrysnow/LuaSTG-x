local FU = cc.FileUtils:getInstance()
---已包含的脚本
lstg.included = {}

---脚本搜索路径
lstg.current_script_path = { '' }

---
--- 包含（执行）脚本文件
---@param filename string
---@return any 脚本返回值
function Include(filename)
    filename = tostring(filename)
    filename = string.gsub(filename, '\\', '/')
    filename = string.gsub(filename, '//', '/')
    local f = filename
    filename = FU:fullPathForFilename(f)
    if not plus.FileExists(filename) then
        error(string.format('%s: %s', i18n "can't find script", f))
    end

    if string.sub(filename, 1, 1) == '~' then
        filename = lstg.current_script_path[#lstg.current_script_path] .. string.sub(filename, 2)
    end
    if not lstg.included[filename] then
        local i, j = string.find(filename, '^.+[\\/]+')
        if i then
            table.insert(lstg.current_script_path, string.sub(filename, i, j))
        else
            table.insert(lstg.current_script_path, '')
        end
        lstg.included[filename] = true
        local ret = DoFile(filename)
        lstg.current_script_path[#lstg.current_script_path] = nil
        return ret
    end
end

