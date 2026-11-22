--
local M = {}

local fu = cc.FileUtils:getInstance()

local const_files = { 'core/const.lua' }
for _, f in ipairs(const_files) do
    local file = fu:getStringFromFile(f)
    if #file > 0 then
        file:gsub('\n(%w+)%s*=%s*([^\r\n]*)', function(s1, s2)
            M[s1] = ('%s'):format(s2)
        end)
    end
end

local func_files = {
    'core/corefunc.lua',
    'core/file.lua',
    'core/global.lua',
    'core/include.lua',
    'core/input.lua',
    'core/math.lua',
    'core/resources.lua',
    'core/respool.lua',
    'core/status.lua',
    'core/view.lua',
}
for _, f in ipairs(func_files) do
    local file = fu:getStringFromFile(f)
    if #file > 0 then
        local comments, funcs = {}, {}
        local func_map = {}
        file:gsub('()\r?\n%-%-%-%s*([^\r\n]*)()', function(p1, s, p2)
            table.insert(comments, { p1, p2, s })
        end)
        file:gsub('()\r?\nfunction (%w+)%(', function(pos, s)
            table.insert(funcs, { pos, s })
            func_map[pos] = s
        end)

        if #funcs > 0 and #comments > 0 then
            local c_blocks = { comments[1] }
            for j = 1, #comments - 1 do
                local prev = comments[j]
                local curr = comments[j + 1]
                if prev[2] == curr[1] then
                    -- consecutive
                    local last = c_blocks[#c_blocks]
                    local str = last[3] .. '\n' .. curr[3]
                    c_blocks[#c_blocks] = { prev[1], curr[2], str }
                else
                    table.insert(c_blocks, curr)
                end
            end
            for _, v in ipairs(c_blocks) do
                local fn = func_map[v[2]]
                if fn and fn ~= '' then
                    M[fn] = v[3]
                end
            end
        end
    end
end

return M
