---@class lstg.CameraRoaming
local M = class('lstg.CameraRoaming')
local vec3 = require('math.vec3')
local mat4 = require('math.mat4')
local quat = require('math.quaternion')

function M:ctor()
    self:loadFromGame()
    self:saveStatus()
    self._rotFactor = 2e-4
    self._moveFactor = 1e-2
    self._vFront = 0
    self._vRight = 0
    self._vUp = 0
    self._oRight = 0
    self._oUp = 0
end

function M:dtor()
    self:_disable()
end

local function getUp(up, front)
    local right = front:cross(up)
    return right:cross(front):getNormalized()
end

local _save = {
    '_pos',
    '_front',
    '_up',
}

function M:saveStatus()
    local save = {}
    for _, v in ipairs(_save) do
        save[v] = self[v]:clone()
    end
    save._fovy = self._fovy
    save._zn = self._zn
    save._zf = self._zf
    self._save = save
end

function M:loadStatus()
    local save = self._save
    if not save then
        return
    end
    for _, v in ipairs(_save) do
        self[v] = save[v]:clone()
    end
    self._fovy = save._fovy
    self._zn = save._zn
    self._zf = save._zf
end

function M:loadFromGame()
    local v = lstg.view3d
    self._pos = vec3(unpack(v.eye))
    self._front = (vec3(unpack(v.at)) - self._pos):getNormalized()
    self._up = getUp(vec3(unpack(v.up)), self._front)
    self._fovy = v.fovy
    self._zn = v.z[1]
    self._zf = v.z[2]
    assert(self._pos:isFinite())
    assert(self._front:isFinite())
    assert(self._up:isFinite())
end

local function _unpack(vec)
    return vec.x, vec.y, vec.z
end

function M:setGame()
    local v = lstg.view3d
    v.eye = { _unpack(self._pos) }
    v.at = { _unpack(self._front + self._pos) }
    v.up = { _unpack(self._up) }
    v.fovy = self._fovy
    v.z = { self._zn, self._zf }
end

function M:moveFront(v)
    self._pos = self._pos + self._front * v
end

function M:moveUp(v)
    self._pos = self._pos + self._up * v
end

function M:moveRight(v)
    local right = self._front:cross(self._up):getNormalized()
    self._pos = self._pos + right * v
end

function M:rotateUp(v)
    local right = self._front:cross(self._up)
    local r = mat4:createRotationFromAxisAngle(right, v)
    self._front = vec3(r:transformVector(self._front))
    self._up = vec3(r:transformVector(self._up))
end

function M:rotateRight(v)
    local r = mat4:createRotationFromAxisAngle(self._up, v)
    self._front = vec3(r:transformVector(self._front))
end

function M:rotateUR(up, right)
    local q1 = quat:createFromAxisAngle(self._front:cross(self._up), up * 2)
    local q2 = quat:createFromAxisAngle(self._up, right * 2)
    local r = mat4:createRotationFromQuaternion(q1:slerp(q2, 0.5))
    self._front = vec3(r:transformVector(self._front))
    self._up = vec3(r:transformVector(self._up))
end

function M:setEnable(b)
    if b then
        self:_enable()
    else
        self:_disable()
    end
end

function M:isEnabled()
    return self._enabled
end

function M:_enable()
    if self._enabled then
        return
    end
    local lis = cc.EventListenerTouchAllAtOnce:create()
    local on = false
    local p0
    lis:registerScriptHandler(function(touches, event)
        on = true
        p0 = cc.p(touches[1]:getLocation())
    end, cc.Handler.EVENT_TOUCHES_BEGAN)
    lis:registerScriptHandler(function(touches, event)
        on = false
        p0 = nil
    end, cc.Handler.EVENT_TOUCHES_ENDED)
    lis:registerScriptHandler(function(touches, event)
        if not on then
            return
        end
        local p = cc.p(touches[1]:getLocation())
        local dx, dy = p0.x - p.x, p0.y - p.y
        p0 = p
        dx, dy = dx * self._rotFactor, dy * self._rotFactor
        --self:rotateUR(dy * self._rotFactor, dx * self._rotFactor)
        if math.abs(dx) > math.abs(dy) then
            self:rotateRight(dx)
        else
            self:rotateUp(dy)
        end
        self:setGame()
    end, cc.Handler.EVENT_TOUCHES_MOVED)
    local e = cc.Director:getInstance():getEventDispatcher()
    e:addEventListenerWithFixedPriority(lis, 1)
    self._touchLis = lis
    --
    local lk = require('cc.ListenerKeyboard')
    local stop_vu = function()
        self._vUp = 0
    end
    local stop_vr = function()
        self._vRight = 0
    end
    local stop_vf = function()
        self._vFront = 0
    end
    local s = tostring(self)
    local key_hdl_name = {}
    for i = 1, 6 do
        key_hdl_name[i] = s .. i
    end
    self._key_hdl_name = key_hdl_name
    lk.addHandler(key_hdl_name[1], 'w', function()
        self._vUp = self._moveFactor
    end, stop_vu)
    lk.addHandler(key_hdl_name[2], 's', function()
        self._vUp = -self._moveFactor
    end, stop_vu)
    lk.addHandler(key_hdl_name[3], 'd', function()
        self._vRight = self._moveFactor
    end, stop_vr)
    lk.addHandler(key_hdl_name[4], 'a', function()
        self._vRight = -self._moveFactor
    end, stop_vr)
    lk.addHandler(key_hdl_name[5], 'q', function()
        self._vFront = self._moveFactor
    end, stop_vf)
    lk.addHandler(key_hdl_name[6], 'e', function()
        self._vFront = -self._moveFactor
    end, stop_vf)


    --local lis_m = cc.EventListenerMouse()
    --lis_m:registerScriptHandler(function(event)
    --    local sc = event:getScrollY()
    --    self:moveFront(sc * self._moveFactor)
    --    print('EVENT_MOUSE_SCROLL')
    --end, cc.Handler.EVENT_MOUSE_SCROLL)
    --e:addEventListenerWithFixedPriority(lis, 1)
    --self._mouseLis = lis_m

    local scene = cc.Director:getInstance():getRunningScene()
    local node = cc.Node:create()
    node:scheduleUpdateWithPriorityLua(function()
        self:_update()
    end, 1)
    node:addTo(scene)
    self._node = node
    --
    self._enabled = true
end

function M:_disable()
    if not self._enabled then
        return
    end
    local e = cc.Director:getInstance():getEventDispatcher()
    e:removeEventListener(self._touchLis)
    --e:removeEventListener(self._mouseLis)
    local lk = require('cc.ListenerKeyboard')
    for i, v in ipairs(self._key_hdl_name) do
        lk.removeHandler(v)
    end
    self._node:removeSelf()
    self._node = nil
    --
    self._enabled = false
end

function M:_update()
    if self._enabled then
        self:moveUp(self._vUp)
        self:moveRight(-self._vRight)
        self:moveFront(self._vFront)
        self:setGame()
    end
end

return M
