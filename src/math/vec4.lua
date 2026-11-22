---@class math.vec4
---@field x number
---@field y number
---@field z number
---@field w number
local M = {}

M.__index = M

setmetatable(M, { __call = function(_, x, y, z, w)
    local t = type(x)
    if t == 'number' then
        y = y or 0
        z = z or 0
        w = w or 0
    elseif t == 'table' then
        x, y, z, w = x.x, x.y, x.z, x.w
        x = x or 0
        y = y or 0
        z = z or 0
        w = w or 0
    elseif t == 'nil' then
        x, y, z, w = 0, 0, 0, 0
    else
        error('invalid argument')
    end
    return setmetatable({ ['.type'] = 'vec4', x = x, y = y, z = z, w = w }, M)
end })

function M:__add(other)
    return M(self.x + other.x, self.y + other.y, self.z + other.z, self.w + other.w)
end

function M:__sub(other)
    return M(self.x - other.x, self.y - other.y, self.z - other.z, self.w - other.w)
end

function M:__mul(other)
    if type(other) == 'table' then
        return M(self.x * other.x, self.y * other.y, self.z * other.z, self.w * other.w)
    elseif type(other) == 'number' then
        return M(self.x * other, self.y * other, self.z * other, self.w * other)
    else
        error('invalid operand in vec4.__mul')
    end
end

function M:__div(other)
    if type(other) == 'table' then
        return M(self.x / other.x, self.y / other.y, self.z / other.z, self.w / other.w)
    elseif type(other) == 'number' then
        return M(self.x / other, self.y / other, self.z / other, self.w / other)
    else
        error('invalid operand in vec4.__div')
    end
end

function M:__unm()
    return M(-self.x, -self.y, -self.z, -self.w)
end

function M:__eq(other)
    return self.x == other.x and self.y == other.y and self.z == other.z and self.w == other.w
end

function M:__tostring()
    return string.format('<%f,%f,%f,%f>', self.x, self.y, self.z, self.w)
end

--------------------------------------------------

function M.one()
    return M(1, 1, 1, 1)
end

function M.zero()
    return M(0, 0, 0, 0)
end

--------------------------------------------------

function M:add(other)
    self.x = self.x + other.x
    self.y = self.y + other.y
    self.z = self.z + other.z
    self.w = self.w + other.w
end

function M:clamp(min, max)
    if (self.x < min.x) then
        self.x = min.x
    end
    if (self.x > max.x) then
        self.x = max.x
    end
    if (self.y < min.y) then
        self.y = min.y
    end
    if (self.y > max.y) then
        self.y = max.y
    end
    if (self.z < min.z) then
        self.z = min.z
    end
    if (self.z > max.z) then
        self.z = max.z
    end
    if (self.w < min.w) then
        self.w = min.w
    end
    if (self.w > max.w) then
        self.w = max.w
    end
end

function M:clone()
    return M(self.x, self.y, self.z, self.w)
end

function M:distance(other)
    return math.sqrt(self:distanceSquared(other))
end

function M:distanceSquared(other)
    local dx = other.x - self.x
    local dy = other.y - self.y
    local dz = other.z - self.z
    local dw = other.w - self.w
    return dx * dx + dy * dy + dz * dz + dw * dw
end

function M:dot(other)
    return self.x * other.x + self.y * other.y + self.z * other.z + self.w * other.w
end

function M:fuzzyEquals(other, var)
    local dx = math.abs(other.x - self.x)
    local dy = math.abs(other.y - self.y)
    local dz = math.abs(other.z - self.z)
    local dw = math.abs(other.w - self.w)
    return dx <= var and dy <= var and dz <= var and dw <= var
end

function M:getClamped(min, max)
    local ret = self:clone()
    ret:clamp(min, max)
    return ret
end

function M:getNormalized()
    local len = self:length()
    return M(self.x / len, self.y / len, self.z / len, self.w / len)
end

function M:getScaled(scalar)
    return M(self.x * scalar,
             self.y * scalar,
             self.z * scalar,
             self.w * scalar)
end

function M:isOne()
    return self.x == 1 and self.y == 1 and self.z == 1 and self.w == 1
end

function M:isZero()
    return self.x == 0 and self.y == 0 and self.z == 0 and self.w == 0
end

function M:length()
    return math.sqrt(self.x * self.x + self.y * self.y + self.z * self.z + self.w * self.w)
end

function M:lengthSquared()
    return self.x * self.x + self.y * self.y + self.z * self.z + self.w * self.w
end

function M:lerp(target, alpha)
    return self * (1.0 - alpha) + target * alpha
end

function M:negate()
    self.x = -self.x
    self.y = -self.y
    self.z = -self.z
    self.w = -self.w
end

function M:normalize()
    local len = self:length()
    self.x = self.x / len
    self.y = self.y / len
    self.z = self.z / len
    self.w = self.w / len
end

function M:scale(scalar)
    self.x = self.x * scalar
    self.y = self.y * scalar
    self.z = self.z * scalar
    self.w = self.w * scalar
end

function M:set(xx, yy, zz, ww)
    self.x = xx
    self.y = yy
    self.z = zz
    self.w = ww
end

function M:setZero()
    self.x, self.y, self.z, self.w = 0, 0, 0, 0
end

function M:smooth(target, elapsedTime, responseTime)
    local delta = (target - self) * (elapsedTime / (elapsedTime + responseTime))
    self:add(delta)
end

function M:subtract(other)
    self.x = self.x - other.x
    self.y = self.y - other.y
    self.z = self.z - other.z
    self.w = self.w - other.w
end

--

function M:isFinite()
    return math.isfinite(self.x) and math.isfinite(self.y)
            and math.isfinite(self.z) and math.isfinite(self.w)
end

return M
