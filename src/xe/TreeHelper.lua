local M = { data = {}, imageIndex = {} }

local watch = {}
M.watch = watch
---@type table<xe.SceneNode,boolean>
watch.image = {}

function M.addWatch(key, node)
    watch[key][node] = true
end

---@param node xe.SceneNode
function M.removeWatch(node)
    local w = node:getConfig().watch
    if w then
        M.watch[w][node] = nil
    end
end

function M.clearWatch()
    for k, v in pairs(watch) do
        watch[k] = {}
    end
end

function M.Clone(Node)
    if type(Node) ~= 'table' then
        return Node
    else
        local ret = {}
        for k, v in pairs(Node) do
            ret[k] = M.Clone(v)
        end
        return ret
    end
end

function M.Serialize(o, tab)
    tab = tab or 0
    if type(o) == 'number' then
        return tostring(o)
    elseif type(o) == 'string' then
        return string.format('%q', o)
    elseif type(o) == 'boolean' then
        return tostring(o)
    elseif type(o) == 'nil' then
        return 'nil'
    elseif type(o) == 'table' then
        local r = '{\n'
        for k, v in pairs(o) do
            if type(k) == 'number' then
                k = '[' .. k .. ']'
            elseif type(k) == 'string' then
                k = string.format('[%q]', k)
            else
                error('cannot serialize a ' .. type(k) .. ' key')
            end
            r = r .. string.rep('\t', tab + 1) .. k .. '=' .. M.Serialize(v, tab + 1) .. ',\n'
        end
        return r .. string.rep('\t', tab) .. '}'
    else
        error('cannot serialize a ' .. type(o))
    end
end

function M.DeSerialize(s)
    local f = loadstring('return ' .. s)
    if not f then
        return
    end
    local ok, ret = pcall(f)
    if ok then
        return ret
    end
end

return M
