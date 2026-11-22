--
local M = {}
local types

function M.load()
    if types then
        return types
    end
    types = {}
    local s = cc.FileUtils:getInstance():getStringFromFile('CrazyStorm/set.txt')
    assert(#s > 0)
    local lines = string.split(s, '\n')
    for _, v in ipairs(lines) do
        assert(#v > 0)
        local arr = string.split(v, '_')
        local function toInt(i)
            local n = tonumber(arr[i])
            return n and math.floor(n)
        end
        assert(#arr >= 9, #arr)
        local type = toInt(1)
        local rect = {}
        for i = 1, 4 do
            rect[i] = toInt(i + 1)
        end
        rect.X = rect[1]
        rect.Y = rect[2]
        rect.Width = rect[3]
        rect.Height = rect[4]
        --
        local origin = { toInt(6), toInt(7) }
        origin.X = origin[1]
        origin.Y = origin[2]
        --local origin0 = { toInt(6), toInt(7) }
        local pdr0 = toInt(8)
        local color = toInt(9) or -1
        --types[type] = {
        --    rect    = rect,
        --    origin  = origin,
        --    origin0 = origin,
        --    pdr0    = pdr0,
        --    color   = color,
        --}
        table.insert(types, {
            rect    = rect,
            origin  = origin,
            origin0 = origin,
            pdr0    = pdr0,
            color   = color,
            type    = type,
        })
    end
    return types
end

return M
