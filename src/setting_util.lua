local M = {}

function M.format_json(str)
    local ret = ''
    local indent = '    '
    local level = 0
    local in_string = false
    for i = 1, #str do
        local s = string.sub(str, i, i)
        if s == '{' and (not in_string) then
            level = level + 1
            ret = ret .. '{\n' .. string.rep(indent, level)
        elseif s == '}' and (not in_string) then
            level = level - 1
            ret = string.format(
                    '%s\n%s}', ret, string.rep(indent, level))
        elseif s == '"' then
            in_string = not in_string
            ret = ret .. '"'
        elseif s == ':' and (not in_string) then
            ret = ret .. ': '
        elseif s == ',' and (not in_string) then
            ret = ret .. ',\n'
            ret = ret .. string.rep(indent, level)
        elseif s == '[' and (not in_string) then
            level = level + 1
            ret = ret .. '[\n' .. string.rep(indent, level)
        elseif s == ']' and (not in_string) then
            level = level - 1
            ret = string.format(
                    '%s\n%s]', ret, string.rep(indent, level))
        else
            ret = ret .. s
        end
    end
    return ret
end

local function isval(s)
    return s == 'boolean' or s == 'number' or s == 'string'
end

function M.compare(t1, t2)
    for k, v in pairs(t1) do
        local v2 = t2[k]
        if v2 == nil then
            return false
        end
        local ty = type(v)
        if ty ~= type(v2) then
            return false
        end
        if isval(ty) then
            if v ~= v2 then
                return false
            end
        elseif ty == 'table' then
            return M.compare(v, v2)
        else
            return false
        end
    end
    return true
end

return M
