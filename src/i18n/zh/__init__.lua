--

local function get_string_map()
    local ret = {}
    for _, v in ipairs({ 'string_editor', 'string_core' }) do
        table.insert(ret, require('i18n.zh.' .. v))
    end
    return ret
end

local _string_maps = get_string_map()

---@class i18n.zh:i18n
local M = {}

function M.string(str)
    for _, v in ipairs(_string_maps) do
        local lower = string.lower(str)
        if v[str] then
            return v[str]
        end
        if v[lower] then
            return v[lower]
        end
    end
    return str
end

return M
