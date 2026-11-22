---@class math.quaternion
---@field x number
---@field y number
---@field z number
---@field w number
local M = {}
local vec3 = require('math.vec3')

M.__index = M

setmetatable(M, { __call = function(_, ...)
    local ret = setmetatable({ ['.type'] = 'quat', x = 0, y = 0, z = 0, w = 1 }, M)
    local arg = { ... }
    if #arg > 0 then
        ret:set(...)
    end
    return ret
end })

function M:__mul(other)
    if type(other) == 'table' then
        if other.w then
            -- Calculates the quaternion product of this quaternion with the given quaternion.
            local x = self.w * other.x + self.x * other.w + self.y * other.z - self.z * other.y
            local y = self.w * other.y - self.x * other.z + self.y * other.w + self.z * other.x
            local z = self.w * other.z + self.x * other.y - self.y * other.x + self.z * other.w
            local w = self.w * other.w - self.x * other.x - self.y * other.y - self.z * other.z
            return M(x, y, z, w)
        else
            -- Calculates the quaternion product of this quaternion with the given vec3.
            local qvec = vec3(self.x, self.y, self.z)
            local uv = qvec:cross(other)
            local uuv = qvec:cross(uv)
            uv = uv * (2.0 * self.w)
            uuv = uuv * 2.0
            return other + uv + uuv
        end
    else
        error('invalid operand in quat.__mul')
    end
end

function M:__eq(other)
    return self.x == other.x and self.y == other.y and self.z == other.z and self.w == other.w
end

function M:__tostring()
    return string.format('<%f,%f,%f,%f>', self.x, self.y, self.z, self.w)
end

--------------------------------------------------

function M.identity()
    return M(0, 0, 0, 1)
end

function M.zero()
    return M(0, 0, 0, 0)
end

function M:createFromRotationMatrix(mat)
    local ret = M()
    mat:getRotation(ret)
    return ret
end

function M:createFromAxisAngle(axis, angle)
    local ret = M()
    ret:set(axis, angle)
    return ret
end

--------------------------------------------------

local function lengthSquared(self)
    return self.x * self.x + self.y * self.y + self.z * self.z + self.w * self.w
end

local function slerpForSquad(q1, q2, t)
    -- This is a straight-forward implementation of the formula of slerp. It does not do any sign switching.
    local c = q1.x * q2.x + q1.y * q2.y + q1.z * q2.z + q1.w * q2.w

    if (math.abs(c) >= 1) then
        return q1:clone()
    end

    local omega = math.acos(c)
    local s = math.sqrt(1 - c * c)
    if math.abs(s) <= 0.00001 then
        return q1:clone()
    end

    local r1 = math.sin((1 - t) * omega) / s
    local r2 = math.sin(t * omega) / s
    local ret = M()
    ret.x = (q1.x * r1 + q2.x * r2)
    ret.y = (q1.y * r1 + q2.y * r2)
    ret.z = (q1.z * r1 + q2.z * r2)
    ret.w = (q1.w * r1 + q2.w * r2)
    return ret
end

--------------------------------------------------

function M:clone()
    return M(self.x, self.y, self.z, self.w)
end

function M:conjugate()
    self.x = -self.x
    self.y = -self.y
    self.z = -self.z
end

function M:fuzzyEquals(other, var)
    local dx = math.abs(other.x - self.x)
    local dy = math.abs(other.y - self.y)
    local dz = math.abs(other.z - self.z)
    local dw = math.abs(other.w - self.w)
    return dx <= var and dy <= var and dz <= var and dw <= var
end

function M:getConjugated()
    local ret = self:clone()
    ret:conjugate()
    return ret
end

function M:getInversed()
    local ret = self:clone()
    ret:inverse()
    return ret
end

function M:getNormalized()
    local ret = self:clone()
    ret:normalize()
    return ret
end

function M:isIdentity()
    return self.x == 0 and self.y == 0 and self.z == 0 and self.w == 1
end

function M:isZero()
    return self.x == 0 and self.y == 0 and self.z == 0 and self.w == 0
end

function M:inverse()
    local n = lengthSquared(self)
    if n == 1 then
        self:conjugate()
    else
        self.x = -self.x / n
        self.y = -self.y / n
        self.z = -self.z / n
        self.w = self.w / n
    end
end

--- Interpolates between two quaternions using linear interpolation.
---
--- The interpolation curve for linear interpolation between
--- quaternions gives a straight line in quaternion space.
function M:lerp(other, t)
    if t <= 0 then
        return self:clone()
    elseif t >= 1 then
        return other:clone()
    end
    local ret = M()
    local t1 = 1 - t
    ret.x = t1 * self.x + t * other.x
    ret.y = t1 * self.y + t * other.y
    ret.z = t1 * self.z + t * other.z
    ret.w = t1 * self.w + t * other.w
    return ret
end

function M:normalize()
    local n = lengthSquared(self)
    if n ~= 1 then
        n = 1 / math.sqrt(n)
        self.x = self.x * n
        self.y = self.y * n
        self.z = self.z * n
        self.w = self.w * n
    end
end

function M:multiply(other)
    self:set(self * other)
end

function M:set(...)
    local arg = { ... }
    if #arg == 1 then
        arg = arg[1]
        if #arg == 16 then
            -- Sets the quaternion equal to the rotational part of the specified matrix.
            arg:getRotation(self)
        else
            -- Sets the elements of this quaternion to a copy of the specified quaternion.
            self.x = arg.x
            self.y = arg.y
            self.z = arg.z
            self.w = arg.w
        end
    elseif #arg == 2 then
        -- Sets the quaternion equal to the rotation from the specified axis and angle.
        local axis = arg[1]
        local angle = arg[2]
        local normal = vec3(axis.x, axis.y, axis.z)
        normal:normalize()
        local halfAngle = angle * 0.5
        local sinHalfAngle = math.sin(halfAngle)
        self.w = math.cos(halfAngle)
        self.x = normal.x * sinHalfAngle
        self.y = normal.y * sinHalfAngle
        self.z = normal.z * sinHalfAngle
    elseif #arg == 4 then
        -- Sets the elements of the quaternion to the specified values.
        self.x = arg[1]
        self.y = arg[2]
        self.z = arg[3]
        self.w = arg[4]
    end
end

function M:setIdentity()
    self.x = 0
    self.y = 0
    self.z = 0
    self.w = 1
end

--- Interpolates over a series of quaternions using spherical spline interpolation.
---
--- Spherical spline interpolation provides smooth transitions between different
--- orientations and is often useful for animating models or cameras in 3D.
---
--- Note: For accurate interpolation, the input quaternions must be unit.
--- This method does not automatically normalize the input quaternions,
--- so it is up to the caller to ensure they call normalize beforehand, if necessary.
function M.squad(q1, q2, s1, s2, t)
    local dstQ = slerpForSquad(q1, q2, t)
    local dstS = slerpForSquad(s1, s2, t)
    return slerpForSquad(dstQ, dstS, 2 * t * (1 - t))
end

--- Interpolates between two quaternions using spherical linear interpolation.
---
--- Spherical linear interpolation provides smooth transitions between different
--- orientations and is often useful for animating models or cameras in 3D.
---
--- Note: For accurate interpolation, the input quaternions must be at (or close to) unit length.
--- This method does not automatically normalize the input quaternions, so it is up to the
--- caller to ensure they call normalize beforehand, if necessary.
function M:slerp(other, t)
    -- Fast slerp implementation by kwhatmough:
    -- It contains no division operations, no trig, no inverse trig
    -- and no sqrt. Not only does this code tolerate small constraint
    -- errors in the input quaternions, it actually corrects for them.
    if t <= 0 then
        return self:clone()
    elseif t >= 1 or self == other then
        return other:clone()
    end
    local q1x, q1y, q1z, q1w = self.x, self.y, self.z, self.w
    local q2x, q2y, q2z, q2w = other.x, other.y, other.z, other.w

    local halfY, alpha, beta
    local u, f1, f2a, f2b
    local ratio1, ratio2
    local halfSecHalfTheta, versHalfTheta
    local sqNotU, sqU

    local cosTheta = q1w * q2w + q1x * q2x + q1y * q2y + q1z * q2z

    -- As usual in all slerp implementations, we fold theta.
    alpha = cosTheta >= 0 and 1.0 or -1.0
    halfY = 1.0 + alpha * cosTheta

    -- Here we bisect the interval, so we need to fold t as well.
    f2b = t - 0.5
    u = f2b >= 0 and f2b or -f2b
    f2a = u - f2b
    f2b = f2b + u
    u = u + u
    f1 = 1.0 - u

    -- One iteration of Newton to get 1-cos(theta / 2) to good accuracy.
    halfSecHalfTheta = 1.09 - (0.476537 - 0.0903321 * halfY) * halfY
    halfSecHalfTheta = halfSecHalfTheta * (1.5 - halfY * halfSecHalfTheta * halfSecHalfTheta)
    versHalfTheta = 1.0 - halfY * halfSecHalfTheta

    -- Evaluate series expansions of the coefficients.
    sqNotU = f1 * f1
    ratio2 = 0.0000440917108 * versHalfTheta
    ratio1 = -0.00158730159 + (sqNotU - 16.0) * ratio2
    ratio1 = 0.0333333333 + ratio1 * (sqNotU - 9.0) * versHalfTheta
    ratio1 = -0.333333333 + ratio1 * (sqNotU - 4.0) * versHalfTheta
    ratio1 = 1.0 + ratio1 * (sqNotU - 1.0) * versHalfTheta

    sqU = u * u
    ratio2 = -0.00158730159 + (sqU - 16.0) * ratio2
    ratio2 = 0.0333333333 + ratio2 * (sqU - 9.0) * versHalfTheta
    ratio2 = -0.333333333 + ratio2 * (sqU - 4.0) * versHalfTheta
    ratio2 = 1.0 + ratio2 * (sqU - 1.0) * versHalfTheta

    -- Perform the bisection and resolve the folding done earlier.
    f1 = f1 * ratio1 * halfSecHalfTheta
    f2a = f2a * ratio2
    f2b = f2b * ratio2
    alpha = alpha * f1 + f2a
    beta = f1 + f2b

    -- Apply final coefficients to a and b as usual.
    local w = alpha * q1w + beta * q2w
    local x = alpha * q1x + beta * q2x
    local y = alpha * q1y + beta * q2y
    local z = alpha * q1z + beta * q2z

    -- This final adjustment to the quaternion's length corrects for
    -- any small constraint error in the inputs q1 and q2 But as you
    -- can see, it comes at the cost of 9 additional multiplication
    -- operations. If this error-correcting feature is not required,
    -- the following code may be removed.
    f1 = 1.5 - 0.5 * (w * w + x * x + y * y + z * z)
    w = w * f1
    x = x * f1
    y = y * f1
    z = z * f1
    return M(x, y, z, w)
end

--- Converts this Quaternion4f to axis-angle notation. The axis is normalized.
---@return math.vec3, number
function M:toAxisAngle()
    local q = self:getNormalized()
    local axis = vec3(q.x, q.y, q.z)
    axis:normalize()
    return axis, 2 * math.acos(q.w)
end

return M
