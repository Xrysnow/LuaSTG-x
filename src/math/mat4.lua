---@class math.mat4
local M = {}
local vec3 = require('math.vec3')
local vec4 = require('math.vec4')
local quat = require('math.quaternion')
local type = type
local function xyz(x, y, z)
    if type(x) == 'number' then
        return x, y or x, z or y or x
    else
        return x.x, x.y, x.z
    end
end

M.__index = M

setmetatable(M, { __call = function(_, t)
    if type(t) == 'table' then
        local ret = {}
        for i = 1, 16 do
            ret[i] = t[i] or 0
        end
        return setmetatable(ret, M)
    else
        return M.identity()
    end
end })

function M:__add(other, out)
    local ret = out or M()
    if type(other) == 'number' then
        for i = 1, 16 do
            ret[i] = self[i] + other
        end
    else
        for i = 1, 16 do
            ret[i] = self[i] + other[i]
        end
    end
    return ret
end

function M:__sub(other, out)
    local ret = out or M()
    if type(other) == 'number' then
        for i = 1, 16 do
            ret[i] = self[i] - other
        end
    else
        for i = 1, 16 do
            ret[i] = self[i] - other[i]
        end
    end
    return ret
end

function M:__mul(other, out)
    local ret = out or M()
    if type(other) == 'number' then
        for i = 1, 16 do
            ret[i] = self[i] * other
        end
    else
        local m1_1, m1_2, m1_3, m1_4, m1_5, m1_6, m1_7, m1_8, m1_9, m1_10, m1_11, m1_12, m1_13, m1_14, m1_15, m1_16 = self[1], self[2], self[3], self[4], self[5], self[6], self[7], self[8], self[9], self[10], self[11], self[12], self[13], self[14], self[15], self[16]
        local m2_1, m2_2, m2_3, m2_4, m2_5, m2_6, m2_7, m2_8, m2_9, m2_10, m2_11, m2_12, m2_13, m2_14, m2_15, m2_16 = other[1], other[2], other[3], other[4], other[5], other[6], other[7], other[8], other[9], other[10], other[11], other[12], other[13], other[14], other[15], other[16]
        ret[1] = m1_1 * m2_1 + m1_5 * m2_2 + m1_9 * m2_3 + m1_13 * m2_4
        ret[2] = m1_2 * m2_1 + m1_6 * m2_2 + m1_10 * m2_3 + m1_14 * m2_4
        ret[3] = m1_3 * m2_1 + m1_7 * m2_2 + m1_11 * m2_3 + m1_15 * m2_4
        ret[4] = m1_4 * m2_1 + m1_8 * m2_2 + m1_12 * m2_3 + m1_16 * m2_4
        ret[5] = m1_1 * m2_5 + m1_5 * m2_6 + m1_9 * m2_7 + m1_13 * m2_8
        ret[6] = m1_2 * m2_5 + m1_6 * m2_6 + m1_10 * m2_7 + m1_14 * m2_8
        ret[7] = m1_3 * m2_5 + m1_7 * m2_6 + m1_11 * m2_7 + m1_15 * m2_8
        ret[8] = m1_4 * m2_5 + m1_8 * m2_6 + m1_12 * m2_7 + m1_16 * m2_8
        ret[9] = m1_1 * m2_9 + m1_5 * m2_10 + m1_9 * m2_11 + m1_13 * m2_12
        ret[10] = m1_2 * m2_9 + m1_6 * m2_10 + m1_10 * m2_11 + m1_14 * m2_12
        ret[11] = m1_3 * m2_9 + m1_7 * m2_10 + m1_11 * m2_11 + m1_15 * m2_12
        ret[12] = m1_4 * m2_9 + m1_8 * m2_10 + m1_12 * m2_11 + m1_16 * m2_12
        ret[13] = m1_1 * m2_13 + m1_5 * m2_14 + m1_9 * m2_15 + m1_13 * m2_16
        ret[14] = m1_2 * m2_13 + m1_6 * m2_14 + m1_10 * m2_15 + m1_14 * m2_16
        ret[15] = m1_3 * m2_13 + m1_7 * m2_14 + m1_11 * m2_15 + m1_15 * m2_16
        ret[16] = m1_4 * m2_13 + m1_8 * m2_14 + m1_12 * m2_15 + m1_16 * m2_16
    end
    return ret
end

function M:__div(other)
    if type(other) == 'number' then
        local ret = M()
        for i = 1, 16 do
            ret[i] = self[i] / other
        end
        return ret
    else
        return self * other:getInversed()
    end
end

function M:__unm()
    local ret = M()
    for i = 1, 16 do
        ret[i] = -self[i]
    end
    return ret
end

function M:__eq(other)
    for i = 1, 16 do
        if self[i] ~= other[i] then
            return false
        end
    end
    return true
end

function M:__tostring()
    return string.format(
            '%f\t%f\t%f\t%f\n%f\t%f\t%f\t%f\n%f\t%f\t%f\t%f\n%f\t%f\t%f\t%f',
            unpack(self, 1, 16))
end

--------------------------------------------------

---@return math.mat4
function M.one()
    return setmetatable(
            { 1, 1, 1, 1,
              1, 1, 1, 1,
              1, 1, 1, 1,
              1, 1, 1, 1, }, M)
end

---@return math.mat4
function M.zero()
    return setmetatable(
            { 0, 0, 0, 0,
              0, 0, 0, 0,
              0, 0, 0, 0,
              0, 0, 0, 0, }, M)
end

---@return math.mat4
function M.identity()
    return setmetatable(
            { 1, 0, 0, 0,
              0, 1, 0, 0,
              0, 0, 1, 0,
              0, 0, 0, 1, }, M)
end

--------------------------------------------------
-- create projection
--------------------------------------------------

---createLookAt
---@param eye math.vec3
---@param target math.vec3
---@param up math.vec3
---@return math.mat4
function M:createLookAt(eye, target, up)
    up = up:getNormalized()
    local zaxis = (eye - target):getNormalized()
    local xaxis = up:cross(zaxis):getNormalized()
    local yaxis = zaxis:cross(xaxis):getNormalized()
    local m = M()
    m[1] = xaxis.x
    m[2] = yaxis.x
    m[3] = zaxis.x
    m[4] = 0.0
    m[5] = xaxis.y
    m[6] = yaxis.y
    m[7] = zaxis.y
    m[8] = 0.0
    m[9] = xaxis.z
    m[10] = yaxis.z
    m[11] = zaxis.z
    m[12] = 0.0
    m[13] = -xaxis:dot(eye)
    m[14] = -yaxis:dot(eye)
    m[15] = -zaxis:dot(eye)
    m[16] = 1.0
    return m
end

---createPerspective
---@param fovy number
---@param aspect number
---@param n number
---@param f number
---@return math.mat4
function M:createPerspective(fovy, aspect, n, f)
    local f_n = 1 / (f - n)
    local factor = 1 / math.tan(fovy * 0.5)
    local m = M.zero()
    m[1] = 1 / aspect * factor
    m[6] = factor
    m[11] = (-f - n) * f_n
    m[12] = -1
    m[15] = -2 * f * n * f_n
    return m
end

---createOrthographic
---@param width number
---@param height number
---@param zNearPlane number
---@param zFarPlane number
---@return math.mat4
function M:createOrthographic(width, height, zNearPlane, zFarPlane)
    local halfWidth = width / 2.0
    local halfHeight = height / 2.0
    return M:createOrthographicOffCenter(-halfWidth, halfWidth, -halfHeight, halfHeight, zNearPlane, zFarPlane)
end

---createOrthographicOffCenter
---@param left number
---@param right number
---@param bottom number
---@param top number
---@param zNearPlane number
---@param zFarPlane number
---@return math.mat4
function M:createOrthographicOffCenter(left, right, bottom, top, zNearPlane, zFarPlane)
    assert(right ~= left)
    assert(top ~= bottom)
    assert(zFarPlane ~= zNearPlane)

    local m = M.zero()
    m[1] = 2 / (right - left)
    m[6] = 2 / (top - bottom)
    m[11] = 2 / (zNearPlane - zFarPlane)

    m[13] = (left + right) / (left - right)
    m[14] = (top + bottom) / (bottom - top)
    m[15] = (zNearPlane + zFarPlane) / (zNearPlane - zFarPlane)
    m[16] = 1
    return m
end

---createBillboard
---@param objectPosition math.vec3
---@param cameraPosition math.vec3
---@param cameraUpVector math.vec3
---@param cameraForwardVector math.vec3
---@return math.mat4
function M:createBillboard(objectPosition, cameraPosition, cameraUpVector, cameraForwardVector)
    local delta = cameraPosition - objectPosition
    local isSufficientDelta = delta:lengthSquared() > 1e-6

    local m = M.identity()
    m[4] = objectPosition.x
    m[8] = objectPosition.y
    m[12] = objectPosition.z

    -- As per the contracts for the 2 variants of createBillboard, we need
    -- either a safe default or a sufficient distance between object and camera.
    if (cameraForwardVector or isSufficientDelta) then
        local target = isSufficientDelta and cameraPosition or (objectPosition - cameraForwardVector)

        -- A billboard is the inverse of a lookAt rotation
        local lookAt = M:createLookAt(objectPosition, target, cameraUpVector)
        m[1] = lookAt[1]
        m[2] = lookAt[5]
        m[3] = lookAt[9]
        m[5] = lookAt[2]
        m[6] = lookAt[6]
        m[7] = lookAt[10]
        m[9] = lookAt[3]
        m[10] = lookAt[7]
        m[11] = lookAt[11]
    end
    return m
end

--------------------------------------------------

function M:createScale(x, y, z)
    local m = M.identity()
    x, y, z = xyz(x, y, z)
    m[1] = x
    m[6] = y
    m[11] = z
    return m
end

function M:createRotationFromQuaternion(q)
    local x2 = q.x + q.x
    local y2 = q.y + q.y
    local z2 = q.z + q.z

    local xx2 = q.x * x2
    local yy2 = q.y * y2
    local zz2 = q.z * z2
    local xy2 = q.x * y2
    local xz2 = q.x * z2
    local yz2 = q.y * z2
    local wx2 = q.w * x2
    local wy2 = q.w * y2
    local wz2 = q.w * z2

    local m = M.identity()
    m[1] = 1.0 - yy2 - zz2
    m[2] = xy2 + wz2
    m[3] = xz2 - wy2
    m[4] = 0.0
    m[5] = xy2 - wz2
    m[6] = 1.0 - xx2 - zz2
    m[7] = yz2 + wx2
    m[8] = 0.0
    m[9] = xz2 + wy2
    m[10] = yz2 - wx2
    m[11] = 1.0 - xx2 - yy2
    m[12] = 0.0
    m[13] = 0.0
    m[14] = 0.0
    m[15] = 0.0
    m[16] = 1.0
    return m
end

function M:createRotationFromAxisAngle(axis, angle)
    local x = axis.x
    local y = axis.y
    local z = axis.z

    -- Make sure the input axis is normalized.
    local n = x * x + y * y + z * z
    if (n ~= 1.0) then
        -- Not normalized.
        n = math.sqrt(n)
        -- Prevent divide too close to zero.
        if (n > 0.000001) then
            n = 1.0 / n
            x = x * n
            y = y * n
            z = z * n
        end
    end

    local c = math.cos(angle)
    local s = math.sin(angle)

    local t = 1.0 - c
    local tx = t * x
    local ty = t * y
    local tz = t * z
    local txy = tx * y
    local txz = tx * z
    local tyz = ty * z
    local sx = s * x
    local sy = s * y
    local sz = s * z

    local m = M.identity()
    m[1] = c + tx * x
    m[2] = txy + sz
    m[3] = txz - sy
    m[4] = 0.0
    m[5] = txy - sz
    m[6] = c + ty * y
    m[7] = tyz + sx
    m[8] = 0.0
    m[9] = txz + sy
    m[10] = tyz - sx
    m[11] = c + tz * z
    m[12] = 0.0
    m[13] = 0.0
    m[14] = 0.0
    m[15] = 0.0
    m[16] = 1.0
    return m
end

function M:createRotationX(angle)
    local m = M.identity()
    local c, s = math.cos(angle), math.sin(angle)
    m[6] = c
    m[7] = s
    m[10] = -s
    m[11] = c
    return m
end

function M:createRotationY(angle)
    local m = M.identity()
    local c, s = math.cos(angle), math.sin(angle)
    m[1] = c
    m[3] = -s
    m[9] = s
    m[11] = c
    return m
end

function M:createRotationZ(angle)
    local m = M.identity()
    local c, s = math.cos(angle), math.sin(angle)
    m[1] = c
    m[2] = s
    m[5] = -s
    m[6] = c
    return m
end

function M:createTranslation(x, y, z)
    local m = M.identity()
    x, y, z = xyz(x, y, z)
    m[13] = x
    m[14] = y
    m[15] = z
    return m
end

function M:createTransform(translation, scale, quaternion)
    local m = M.identity()
    if quaternion then
        m:rotateByQuaternion(quaternion)
    end
    if translation then
        m[13] = translation.x
        m[14] = translation.y
        m[15] = translation.z
    end
    if scale and scale ~= 1 then
        local sx, sy, sz
        if type(scale) == 'number' then
            sx, sy, sz = scale, scale, scale
        else
            sx, sy, sz = scale.x, scale.y, scale.z
        end
        for i = 1, 3 do
            m[i] = m[i] * sx
        end
        for i = 5, 7 do
            m[i] = m[i] * sy
        end
        for i = 9, 11 do
            m[i] = m[i] * sz
        end
    end
    return m
end

--------------------------------------------------

function M:setIdentity()
    for i, v in ipairs({ 1, 0, 0, 0,
                         0, 1, 0, 0,
                         0, 0, 1, 0,
                         0, 0, 0, 1, }) do
        self[i] = v
    end
end

function M:setZero()
    for i = 1, 16 do
        self[i] = 0
    end
end

--------------------------------------------------

function M:add(other)
    self:__add(other, self)
end

function M:subtract(other)
    self:__sub(other, self)
end

function M:multiply(other)
    self:__mul(other, self)
end

function M:negate()
    for i = 1, 16 do
        self[i] = -self[i]
    end
end

function M:getNegated()
    return -self
end

--------------------------------------------------

function M:clone()
    return M(self)
end

function M:decompose(out_scale, out_rotation, out_translation)
    if out_translation then
        -- Extract the translation.
        out_translation.x = self[13]
        out_translation.y = self[14]
        out_translation.z = self[15]
    end
    if not out_scale and not out_rotation then
        return true
    end
    -- Extract the scale.
    -- This is simply the length of each axis (row/column) in the matrix.
    local xaxis = vec3(self[1][1], self[1][2], self[1][3])
    local scaleX = xaxis:length()

    local yaxis = vec3(self[2][1], self[2][2], self[2][3])
    local scaleY = yaxis:length()

    local zaxis = vec3(self[3][1], self[3][2], self[3][3])
    local scaleZ = zaxis:length()

    -- Determine if we have a negative scale (true if determinant is less than zero).
    -- In this case, we simply negate a single axis of the scale.
    local det = self:determinant()
    if (det < 0) then
        scaleZ = -scaleZ
    end
    if out_scale then
        out_scale.x = scaleX
        out_scale.y = scaleY
        out_scale.z = scaleZ
    end
    if not out_rotation then
        return true
    end

    local MATH_TOLERANCE = 2e-37
    local MATH_EPSILON = 1e-6

    -- Scale too close to zero, can't decompose rotation.
    if (scaleX < MATH_TOLERANCE or scaleY < MATH_TOLERANCE or math.abs(scaleZ) < MATH_TOLERANCE) then
        return false
    end

    -- Factor the scale out of the matrix axes.
    xaxis:scale(1.0 / scaleX)
    yaxis:scale(1.0 / scaleY)
    zaxis:scale(1.0 / scaleZ)

    -- Now calculate the rotation from the resulting matrix (axes).
    local trace = xaxis.x + yaxis.y + zaxis.z + 1.0

    if (trace > MATH_EPSILON) then
        local s = 0.5 / math.sqrt(trace)
        out_rotation.w = 0.25 / s
        out_rotation.x = (yaxis.z - zaxis.y) * s
        out_rotation.y = (zaxis.x - xaxis.z) * s
        out_rotation.z = (xaxis.y - yaxis.x) * s
    else
        -- Note: since xaxis, yaxis, and zaxis are normalized,
        -- we will never divide by zero in the code below.
        if (xaxis.x > yaxis.y and xaxis.x > zaxis.z) then
            local s = 0.5 / math.sqrt(1.0 + xaxis.x - yaxis.y - zaxis.z)
            out_rotation.w = (yaxis.z - zaxis.y) * s
            out_rotation.x = 0.25 / s
            out_rotation.y = (yaxis.x + xaxis.y) * s
            out_rotation.z = (zaxis.x + xaxis.z) * s
        elseif (yaxis.y > zaxis.z) then
            local s = 0.5 / math.sqrt(1.0 + yaxis.y - xaxis.x - zaxis.z)
            out_rotation.w = (zaxis.x - xaxis.z) * s
            out_rotation.x = (yaxis.x + xaxis.y) * s
            out_rotation.y = 0.25 / s
            out_rotation.z = (zaxis.y + yaxis.z) * s
        else
            local s = 0.5 / math.sqrt(1.0 + zaxis.z - xaxis.x - yaxis.y)
            out_rotation.w = (xaxis.y - yaxis.x) * s
            out_rotation.x = (zaxis.x + xaxis.z) * s
            out_rotation.y = (zaxis.y + yaxis.z) * s
            out_rotation.z = 0.25 / s
        end
    end
    return true
end

---@return number
function M:determinant()
    local a0 = self[1] * self[6] - self[2] * self[5]
    local a1 = self[1] * self[7] - self[3] * self[5]
    local a2 = self[1] * self[8] - self[4] * self[5]
    local a3 = self[2] * self[7] - self[3] * self[6]
    local a4 = self[2] * self[8] - self[4] * self[6]
    local a5 = self[3] * self[8] - self[4] * self[7]
    local b0 = self[9] * self[14] - self[10] * self[13]
    local b1 = self[9] * self[15] - self[11] * self[13]
    local b2 = self[9] * self[16] - self[12] * self[13]
    local b3 = self[10] * self[15] - self[11] * self[14]
    local b4 = self[10] * self[16] - self[12] * self[14]
    local b5 = self[11] * self[16] - self[12] * self[15]
    return a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0
end

function M:getInversed()
    local a0 = self[1] * self[6] - self[2] * self[5]
    local a1 = self[1] * self[7] - self[3] * self[5]
    local a2 = self[1] * self[8] - self[4] * self[5]
    local a3 = self[2] * self[7] - self[3] * self[6]
    local a4 = self[2] * self[8] - self[4] * self[6]
    local a5 = self[3] * self[8] - self[4] * self[7]
    local b0 = self[9] * self[14] - self[10] * self[13]
    local b1 = self[9] * self[15] - self[11] * self[13]
    local b2 = self[9] * self[16] - self[12] * self[13]
    local b3 = self[10] * self[15] - self[11] * self[14]
    local b4 = self[10] * self[16] - self[12] * self[14]
    local b5 = self[11] * self[16] - self[12] * self[15]
    local det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0
    local inverse = M()
    inverse[1] = self[6] * b5 - self[7] * b4 + self[8] * b3
    inverse[2] = -self[2] * b5 + self[3] * b4 - self[4] * b3
    inverse[3] = self[14] * a5 - self[15] * a4 + self[16] * a3
    inverse[4] = -self[10] * a5 + self[11] * a4 - self[12] * a3
    inverse[5] = -self[5] * b5 + self[7] * b2 - self[8] * b1
    inverse[6] = self[1] * b5 - self[3] * b2 + self[4] * b1
    inverse[7] = -self[13] * a5 + self[15] * a2 - self[16] * a1
    inverse[8] = self[9] * a5 - self[11] * a2 + self[12] * a1
    inverse[9] = self[5] * b4 - self[6] * b2 + self[8] * b0
    inverse[10] = -self[1] * b4 + self[2] * b2 - self[4] * b0
    inverse[11] = self[13] * a4 - self[14] * a2 + self[16] * a0
    inverse[12] = -self[9] * a4 + self[10] * a2 - self[12] * a0
    inverse[13] = -self[5] * b3 + self[6] * b1 - self[7] * b0
    inverse[14] = self[1] * b3 - self[2] * b1 + self[3] * b0
    inverse[15] = -self[13] * a3 + self[14] * a1 - self[15] * a0
    inverse[16] = self[9] * a3 - self[10] * a1 + self[11] * a0
    return inverse / det
end

function M:inverse()
    self:set(self:getInversed())
end

--------------------------------------------------

function M:getScale()
    local ret = vec3()
    self:decompose(ret, nil, nil)
    return ret
end

function M:getRotation()
    local ret = quat()
    self:decompose(nil, ret, nil)
    return ret
end

function M:getTranslation()
    local ret = vec3()
    self:decompose(nil, nil, ret)
    return ret
end

--------------------------------------------------

function M:getUpVector()
    return vec3(self[5], self[6], self[7])
end

function M:getDownVector()
    return vec3(-self[5], -self[6], -self[7])
end

function M:getLeftVector()
    return vec3(-self[1], -self[2], -self[3])
end

function M:getRightVector()
    return vec3(self[1], self[2], self[3])
end

function M:getForwardVector()
    return vec3(-self[9], -self[10], -self[11])
end

function M:getBackVector()
    return vec3(self[9], self[10], self[11])
end


--------------------------------------------------

function M:rotateByQuaternion(q)
    local r = M:createRotationFromQuaternion(q)
    self:multiply(r)
end

function M:rotateByAxisAngle(axis, angle)
    local r = M:createRotationFromAxisAngle(axis, angle)
    self:multiply(r)
end

function M:rotateX(angle)
    local r = M:createRotationX(angle)
    self:multiply(r)
end

function M:rotateY(angle)
    local r = M:createRotationY(angle)
    self:multiply(r)
end

function M:rotateY(angle)
    local r = M:createRotationY(angle)
    self:multiply(r)
end

--------------------------------------------------

function M:scale(x, y, z)
    self:multiply(M:createScale(x, y, z))
end

function M:getScaled(x, y, z)
    return self * M:createScale(x, y, z)
end

function M:translate(x, y, z)
    self:multiply(M:createTranslation(x, y, z))
end

function M:getTranslated(x, y, z)
    return self * M:createTranslation(x, y, z)
end

--------------------------------------------------

function M:transpose()
    self[2], self[5] = self[5], self[2]
    self[3], self[9] = self[9], self[3]
    self[4], self[13] = self[13], self[4]
    self[7], self[10] = self[10], self[7]
    self[8], self[14] = self[14], self[8]
    self[12], self[15] = self[15], self[12]
end

function M:getTransposed()
    return M({ self[1], self[5], self[9], self[13],
               self[2], self[6], self[10], self[14],
               self[3], self[7], self[11], self[15],
               self[4], self[8], self[12], self[16], })
end

--------------------------------------------------

function M:set(...)
    local arg = { ... }
    if #arg == 1 then
        local m = arg[1]
        for i = 1, 16 do
            self[i] = m[i]
        end
    elseif #arg == 16 then
        for i = 1, 16 do
            self[i] = arg[i]
        end
    end
end

function M:transformVector(x, y, z, w)
    if type(x) == 'number' then
        y = y or 0
        z = z or 0
        w = w or 1
    else
        x, y, z, w = x.x, x.y, x.z, x.w
        w = w or 1
    end
    local xx = x * self[1] + y * self[5] + z * self[9] + w * self[13]
    local yy = x * self[2] + y * self[6] + z * self[10] + w * self[14]
    local zz = x * self[3] + y * self[7] + z * self[11] + w * self[15]
    local ww = x * self[4] + y * self[8] + z * self[12] + w * self[16]
    return vec4(xx, yy, zz, ww)
end

--------------------------------------------------
-- linalg
--------------------------------------------------

function M:det()
    return self:determinant()
end

--- Raise a square matrix to the (integer) power `n`.
---
--- For positive integers `n`, the power is computed by repeated matrix
--- squarings and matrix multiplications. If ``n == 0``, the identity matrix
--- of the same shape as M is returned. If ``n < 0``, the inverse
--- is computed and then raised to the ``abs(n)``.
---
---@param n number
---@return math.mat4
function M:matrix_power(n)
    n = math.floor(n)
    if n == 0 then
        return M.identity()
    end
    local a = self
    if n < 0 then
        n = math.abs(n)
        a = self:getInversed()
    end
    if n == 1 then
        return a
    elseif n == 2 then
        return a * a
    elseif n == 3 then
        return a * a * a
    end
    local z, bit, ret
    while n > 0 do
        if not z then
            z = a
        else
            z = z * z
        end
        n, bit = math.divmod(n, 2)
        if bit > 0 then
            if not ret then
                ret = z
            else
                ret = ret * z
            end
        end
    end
    return ret
end

---@return number
function M:trace()
    return self[1] + self[6] + self[11] + self[16]
end

return M
