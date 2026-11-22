local M = {}

local chars = {
    'ABCDEFGHIJKLM',
    'NOPQRSTUVWXYZ',
    'abcdefghijklm',
    'nopqrstuvwxyz',
    '0123456789+-=',
    '.,!?@:;[]()_/',
    '{}|~^#$%&* \1\2',
}
local rows = #chars
local cols = #chars[1]

local pos = { 1, 1 }
local current_char = 'A'
local input = ''
local MAX_LENGTH = 8

local function getChar(x, y)
    if chars[y] then
        local c = string.sub(chars[y], x, x)
        return (c ~= '') and c or nil
    end
end

function M:update()
    local k = GetLastKey()
    for _, v in ipairs({ 'left', 'right', 'up', 'down' }) do
        if k == setting.keys[v] then
            self:step(v)
            break
        end
    end
    if k == setting.keys.spell then
        if #input == 0 then
            self:returnToList()
        else
            self:_back()
        end
    elseif k == setting.keys.shoot then
        if current_char == '\1' then
            self:_back()
        elseif current_char=='\2' then
            self:_end()
        else
            self:input()
        end
    end
end

local _dirs = {
    left  = { -1, 0 },
    right = { 1, 0 },
    up    = { 0, -1 },
    down  = { 0, 1 },
}
function M:step(dir)
    local d = _dirs[dir]
    assert(d)
    local x = pos[1] + d[1]
    local y = pos[2] + d[2]
    x = (x - 1) % cols + 1
    y = (y - 1) % rows + 1
    pos = { x, y }
    self:moveTo(pos)
end

function M:moveTo(p)
    pos = p
    current_char = getChar(pos[1], pos[2])
    assert(current_char)
end

function M:moveToChar(c)
    assert(c)
    local x, y
    for i = 1, rows do
        for j = 1, cols do
            if getChar(j, i) == c then
                x, y = j, i
            end
        end
    end
    if x and y then
        self:moveTo({ x, y })
        assert(current_char == c)
    end
end

function M:input()
    self:_input(current_char)
end

function M:_input(c)
    assert(type(c) == 'string')
    if #input == MAX_LENGTH then
        input = string.sub(input, 1, -2)
    end
    input = input .. c
end

function M:_back()
    input = string.sub(input, 1, -2)
end

function M:_end()
end

function M:returnToList()
    --
end

return M
