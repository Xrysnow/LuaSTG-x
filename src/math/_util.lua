--
local M = {}
local floor = math.floor

local function swizzle_vec2(cls, c)
    local vec2 = require('math.vec2')
    local n = #c
    for i = 0, n * n - 1 do
        local i1 = i % n + 1
        local i2 = floor(i / n) % n + 1
        local k1, k2 = c[i1], c[i2]
        local k = ('%s%s'):format(k1, k2)
        if not cls[k] then
            cls[k] = function(self)
                return vec2(self[k1], self[k2])
            end
        end
    end
end
local function swizzle_vec3(cls, c)
    local vec3 = require('math.vec3')
    local n = #c
    for i = 0, n * n * n - 1 do
        local i1 = i % n + 1
        local i2 = floor(i / n) % n + 1
        local i3 = floor(i / (n * n)) % n + 1
        local k1, k2, k3 = c[i1], c[i2], c[i3]
        local k = ('%s%s%s'):format(k1, k2, k3)
        if not cls[k] then
            cls[k] = function(self)
                return vec3(self[k1], self[k2], self[k3])
            end
        end
    end
end
local function swizzle_vec4(cls, c)
    local vec4 = require('math.vec4')
    local n = #c
    for i = 0, n * n * n * n - 1 do
        local i1 = i % n + 1
        local i2 = floor(i / n) % n + 1
        local i3 = floor(i / (n * n)) % n + 1
        local i4 = floor(i / (n * n * n)) % n + 1
        local k1, k2, k3, k4 = c[i1], c[i2], c[i3], c[i4]
        local k = ('%s%s%s%s'):format(k1, k2, k3, k4)
        if not cls[k] then
            cls[k] = function(self)
                return vec4(self[k1], self[k2], self[k3], self[k4])
            end
        end
    end
end

function M.swizzleVec(cls, ...)
    local c = { ... }
    swizzle_vec2(cls, c)
    swizzle_vec3(cls, c)
    swizzle_vec4(cls, c)
end

return M
