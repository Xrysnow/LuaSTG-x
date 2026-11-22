---@class math.vec2
---@field x number
---@field y number
local M = {}

M.__index = M

setmetatable(M, { __call = function(_, x, y)
    local t = type(x)
    if t == 'number' then
        y = y or 0
    elseif t == 'table' then
        x, y = x.x, x.y
        x = x or 0
        y = y or 0
    elseif t == 'nil' then
        x, y = 0, 0
    else
        error('invalid argument')
    end
    return setmetatable({ ['.type'] = 'vec2', x = x, y = y }, M)
end })

function M:__add(other)
    return M(self.x + other.x, self.y + other.y)
end

function M:__sub(other)
    return M(self.x - other.x, self.y - other.y)
end

function M:__mul(other)
    if type(other) == 'table' then
        return M(self.x * other.x, self.y * other.y)
    elseif type(other) == 'number' then
        return M(self.x * other, self.y * other)
    else
        error('invalid operand in vec2.__mul')
    end
end

function M:__div(other)
    if type(other) == 'table' then
        return M(self.x / other.x, self.y / other.y)
    elseif type(other) == 'number' then
        return M(self.x / other, self.y / other)
    else
        error('invalid operand in vec2.__div')
    end
end

function M:__unm()
    return M(-self.x, -self.y)
end

function M:__eq(other)
    return self.x == other.x and self.y == other.y
end

function M:__tostring()
    return '<' .. self.x .. ',' .. self.y .. '>'
end

--------------------------------------------------

function M.one()
    return M(1, 1)
end

function M.zero()
    return M(0, 0)
end

--------------------------------------------------

function M:angle(other)
    if other then
        return math.atan2(self:cross(other), self:dot(other))
    else
        return math.atan2(self.y, self.x)
    end
end

function M:add(other)
    self.x = self.x + other.x
    self.y = self.y + other.y
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
end

function M:clone()
    return M(self.x, self.y)
end

function M:cross(other)
    return self.x * other.y - self.y * other.x
end

function M:distance(other)
    return math.sqrt(self:distanceSquared(other))
end

function M:distanceSquared(other)
    local dx = other.x - self.x
    local dy = other.y - self.y
    return (dx * dx + dy * dy)
end

function M:dot(other)
    return self.x * other.x + self.y * other.y
end

function M:fuzzyEquals(other, var)
    local dx = math.abs(other.x - self.x)
    local dy = math.abs(other.y - self.y)
    return dx <= var and dy <= var
end

function M:getClamped(min, max)
    local ret = self:clone()
    ret:clamp(min, max)
    return ret
end

--- Calculates midpoint between two points
function M:getMidpoint(other)
    return M((self.x + other.x) / 2, (self.y + other.y) / 2)
end

function M:getNormalized()
    local len = self:length()
    return M(self.x / len, self.y / len)
end

--- Calculates perpendicular of v, rotated 90 degrees counter-clockwise -- cross(v, perp(v)) >= 0
function M:getPerp()
    return M(-self.y, self.x)
end

--- Calculates the projection of this over other.
---@return math.vec2
function M:getProjection(other)
    return other * (self:dot(other) / other:dot(other))
end

function M:getRotateAround(point, angle)
    if point:isZero() then
        return self:getRotated(angle)
    else
        return point + (self - point):getRotated(angle)
    end
end

--- Complex multiplication of two points ("rotates" two points), or rotate a point by angle.
---@param other math.vec2|number vector or angle
---@return math.vec2
function M:getRotated(other)
    local x, y
    if type(other) == 'number' then
        x, y = math.cos(other), math.sin(other)
    else
        x, y = other.x, other.y
    end
    return M(self.x * x - self.y * y, self.x * y + self.y * x)
end

--- Calculates perpendicular of v, rotated 90 degrees clockwise -- cross(v, rperp(v)) <= 0
function M:getRPerp()
    return M(self.y, -self.x)
end

function M:getScaled(scalar)
    return M(self.x * scalar,
             self.y * scalar)
end

function M:isOne()
    return self.x == 1 and self.y == 1
end

function M:isZero()
    return self.x == 0 and self.y == 0
end

function M:length()
    return math.sqrt(self.x * self.x + self.y * self.y)
end

function M:lengthSquared()
    return self.x * self.x + self.y * self.y
end

function M:lerp(target, alpha)
    return self * (1.0 - alpha) + target * alpha
end

function M:negate()
    self.x = -self.x
    self.y = -self.y
end

function M:normalize()
    local len = self:length()
    self.x = self.x / len
    self.y = self.y / len
end

--- Rotates this vector by angle (specified in radians) around the given point.
function M:rotate(point, angle)
    local sinAngle = math.sin(angle)
    local cosAngle = math.cos(angle)
    if point:isZero() then
        local tempX = self.x * cosAngle - self.y * sinAngle
        self.y = self.y * cosAngle + self.x * sinAngle
        self.x = tempX
    else
        local tempX = self.x - point.x
        local tempY = self.y - point.y
        self.x = tempX * cosAngle - tempY * sinAngle + point.x
        self.y = tempY * cosAngle + tempX * sinAngle + point.y
    end
end

function M:scale(scalar)
    self.x = self.x * scalar
    self.y = self.y * scalar
end

function M:set(xx, yy, zz)
    self.x = xx
    self.y = yy
end

function M:setZero()
    self.x, self.y = 0, 0
end

function M:smooth(target, elapsedTime, responseTime)
    local delta = (target - self) * (elapsedTime / (elapsedTime + responseTime))
    self:add(delta)
end

function M:subtract(other)
    self.x = self.x - other.x
    self.y = self.y - other.y
end

--

function M:isFinite()
    return math.isfinite(self.x) and math.isfinite(self.y)
end

return M
