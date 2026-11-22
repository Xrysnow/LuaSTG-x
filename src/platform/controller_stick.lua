---@class VitrualController:cc.Layer
local M = class("VitrualController", cc.Layer)

function M:ctor(keys, position, scale)
    if self.onCreate then
        self:onCreate(keys, position, scale)
    end
end

function M:onTouchesEnded(touches, event)
    for _, touch in ipairs(touches) do
        if touch:getId() == self.touch_id then
            self:releaseTouch()
            break
        end
    end
end

function M:releaseTouch()
    self.touch_id = nil
    self.is_active = false
    self:_deactive()
end

function M:onTouchesBegan(touches, event)
    if self.touch_id ~= nil then
        return
    end
    for _, touch in ipairs(touches) do
        local pos = self:convertToNodeSpace(touch:getLocation())
        if cc.pGetLength(pos) < 100 * self.scale_ then
            self.touch_id = touch:getId()
            self.is_active = true
            self:_active(pos)
            break
        end
    end
end

function M:onTouchesMove(touches, event)
    for _, touch in ipairs(touches) do
        if touch:getId() == self.touch_id then
            self:_update(self:convertToNodeSpace(touch:getLocation()))
            break
        end
    end
end

function M:onCreate(keys, position, scale)
    self.position_ = position
    scale = scale or 1
    self.scale_ = scale

    cc.Image:setPNGPremultipliedAlphaEnabled(true)

    local joystick_bg = cc.Sprite:create("res/joystick_bg.png")
    self.joystick_bg = joystick_bg
    joystick_bg:setScale(1.0 * scale)
    self:addChild(joystick_bg)

    local joystick = cc.Sprite:create("res/joystick.png")
    joystick:setScale(1.8 * scale)
    self.joystick = joystick
    self:addChild(joystick)

    cc.Image:setPNGPremultipliedAlphaEnabled(false)

    self.setter = require('cc.key_setter')(keys)
    local k1, k2, k3, k4 = keys[1], keys[2], keys[3], keys[4]
    self.states = {
        { [k1] = true, [k2] = false, [k3] = false, [k4] = false },
        { [k1] = true, [k2] = true, [k3] = false, [k4] = false },
        { [k1] = false, [k2] = true, [k3] = false, [k4] = false },
        { [k1] = false, [k2] = true, [k3] = true, [k4] = false },
        { [k1] = false, [k2] = false, [k3] = true, [k4] = false },
        { [k1] = false, [k2] = false, [k3] = true, [k4] = true },
        { [k1] = false, [k2] = false, [k3] = false, [k4] = true },
        { [k1] = true, [k2] = false, [k3] = false, [k4] = true },
        { [k1] = false, [k2] = false, [k3] = false, [k4] = false },
    }
    local stick_d = 48 * scale
    local stick_pos = {}
    for i = 1, 8 do
        local a = math.pi / 2 - (i - 1) * math.pi / 4
        stick_pos[i] = cc.pMul(cc.pForAngle(a), stick_d)
    end
    stick_pos[9] = cc.p(0, 0)
    self.stick_pos = stick_pos
    self.is_active = false

    local listener = cc.EventListenerTouchAllAtOnce:create()

    listener:registerScriptHandler(function(...)
        self:onTouchesBegan(...)
    end, cc.Handler.EVENT_TOUCHES_BEGAN)
    listener:registerScriptHandler(function(...)
        self:onTouchesEnded(...)
    end, cc.Handler.EVENT_TOUCHES_ENDED)
    listener:registerScriptHandler(function(...)
        self:onTouchesMove(...)
    end, cc.Handler.EVENT_TOUCHES_MOVED)
    listener:registerScriptHandler(function(...)
        self:onTouchesEnded(...)
    end, cc.Handler.EVENT_TOUCHES_CANCELLED)
    local eventDispatcher = self:getEventDispatcher()
    eventDispatcher:addEventListenerWithSceneGraphPriority(listener, self)
    local background = cc.EventListenerCustom:create('event_come_to_background', function()
        self:releaseTouch()
    end)
    eventDispatcher:addEventListenerWithSceneGraphPriority(background, self)
    local projection = cc.EventListenerCustom:create(cc.Director.EVENT_PROJECTION_CHANGED, function()
        self:releaseTouch()
    end)
    eventDispatcher:addEventListenerWithSceneGraphPriority(projection, self)
    self:registerScriptHandler(function(tag)
        if tag == 'exit' then
            self:releaseTouch()
        end
    end)

end

function M:_set_state(n)
    self.setter:setMulti(self.states[n])
end

function M:_set_pos(n)
    self.joystick:setPosition(self.stick_pos[n])
end

function M:_active(pos)
    self:_update(pos)
end

function M:_deactive()
    self:_set_state(9)
    self:_set_pos(9)
end

local pi = math.pi
function M:_update(pos)
    --print("seayoung udpate", direction.x, direction.y, distance)
    if not self.is_active then
        return
    end
    local p0 = cc.p(0, 0)
    local distance = cc.pGetDistance(p0, pos)
    local direction = cc.pNormalize(cc.pSub(pos, p0))
    if distance > 24 * self.scale_ then
        local angle = math.atan2(direction.y, direction.x)
        local idx = math.ceil((angle + pi) * 8 / pi)
        idx = (14 - math.floor(idx / 2)) % 8 + 1
        assert(1 <= idx and idx <= 8)
        self:_set_state(idx)
        self:_set_pos(idx)
    else
        self:_deactive()
    end

end

return M

