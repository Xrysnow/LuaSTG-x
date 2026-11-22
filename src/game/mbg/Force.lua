---@class lstg.mbg.Force
local M = {}
--local M = class('lstg.mbg.Batch')
local Player = require('game.mbg.Player')
local Time = require('game.mbg.Time')
local Main = require('game.mbg.Main')
local Math = require('game.mbg._math')
--local MathHelper = Math

M.record = 0

local function _ctor(data)
    local ret = {}
    M.ctor(ret, data)
    ret.update = M.update
    ret.clone = M.clone
    ret.copy = M.copy
    ret.getLayer = M.getLayer
    return ret
end

---@param data mbg.ForceField
function M:ctor(data)
    -- private
    self.clcount = 0
    self.clwait = 0
    -- public
    self.Selecting = false
    self.NeedDelete = false
    self.Searched = 0
    self.id = 0
    self.parentid = 0
    self.parentcolor = 0
    self.x = 0
    self.y = 0
    --- 起始
    self.begin = 0
    --- 持续
    self.life = 0
    self.halfw = 0
    self.halfh = 0
    --- 启用圆形
    self.Circle = false
    --- 类型
    self.type = 0
    --- 编号
    self.controlid = 0
    --- 速度
    self.speed = 0
    --- 速度方向
    self.speedd = 0
    self.speedx = 0
    self.speedy = 0
    --- 加速度
    self.aspeed = 0
    self.aspeedx = 0
    self.aspeedy = 0
    --- 加速度方向
    self.aspeedd = 0
    self.addaspeed = 0
    --- 力场加速度方向
    self.addaspeedd = 0
    --- 中心吸力
    self.Suction = false
    --- 中心斥力
    self.Repulsion = false
    --- 力场加速度
    self.addspeed = 0
    self.Parentevents = {}
    ---@type lstg.mbg.Force
    self.copys = nil
    if not data then
        return
    end
    local function value(v)
        return v.RandValue
    end
    self._data = data
    self.rand = _ctor()
    --
    self.id = data["ID"]
    self.parentid = data["层ID"]
    self.x = data["位置坐标"].X
    self.y = data["位置坐标"].Y
    self.begin = data["生命"].Begin
    self.life = data["生命"].LifeTime
    self.halfw = data["半高"]
    --assert(type(self.halfw) == 'number')
    self.halfh = data["半宽"]
    --assert(type(self.halfh) == 'number')
    self.Circle = data["启用圆形"]
    self.type = data["类型"]
    self.controlid = data["控制ID"]
    self.speed = value(data["运动"].Speed)
    self.speedd = value(data["运动"].SpeedDirection)
    self.aspeed = value(data["运动"].Acceleration)
    self.aspeedd = value(data["运动"].AccelerationDirection)
    self.addspeed = data["力场加速度"]
    self.addaspeedd = data["力场加速度方向"]
    self.Suction = data["中心吸力"]
    self.Repulsion = data["中心斥力"]
    --self.addspeed = data["影响速度"]
end

function M:update()
    if self.clcount == 1 then
        self.clwait = self.clwait + 1
        if self.clwait > 15 then
            self.clwait = 0
            self.clcount = 0
        end
    end
    local layer = self:getLayer()
    if not Time.Playing then
        self.aspeedx = self.aspeed * Math.Cos(Math.ToRadians(self.aspeedd))
        self.aspeedy = self.aspeed * Math.Sin(Math.ToRadians(self.aspeedd))
        self.speedx = self.speed * Math.Cos(Math.ToRadians(self.speedd))
        self.speedy = self.speed * Math.Sin(Math.ToRadians(self.speedd))
        self.begin = math.floor(Math.Clamp(
                self.begin, layer.begin, (1 + layer['end'] - layer.begin)))
        self.life = math.floor(Math.Clamp(
                self.life, 1, (layer['end'] - layer.begin + 2 - self.begin)))
    end
    if Time.Playing and (Time.now >= self.begin and Time.now <= self.begin + self.life - 1) then
        local now = Time.now
        self.speedx = self.speedx + self.aspeedx
        self.speedy = self.speedy + self.aspeedy
        self.x = self.x + self.speedx
        self.y = self.y + self.speedy
        if self.Circle then
            if Math.Sqrt(((self.x - 4 - Player.position.X) * (self.x - 4 - Player.position.X) + (self.y + 16 - Player.position.Y) * (self.y + 16 - Player.position.Y))) <= Math.Max(self.halfw, self.halfh) then
                if self.Suction then
                    local degrees = Math.ToDegrees(Main.Twopointangle(self.x - 4, self.y + 16, Player.position.X, Player.position.Y))
                    Player.position.X = Player.position.X + self.addspeed * Math.Cos(Math.ToRadians(degrees))
                    Player.position.Y = Player.position.Y + self.addspeed * Math.Sin(Math.ToRadians(degrees))
                elseif self.Repulsion then
                    local num3 = Math.ToDegrees(Main.Twopointangle(self.x - 4, self.y + 16, Player.position.X, Player.position.Y))
                    Player.position.X = Player.position.X + self.addspeed * Math.Cos(Math.ToRadians(180 + num3))
                    Player.position.Y = Player.position.Y + self.addspeed * Math.Sin(Math.ToRadians(180 + num3))
                else
                    Player.position.X = Player.position.X + self.addspeed * Math.Cos(Math.ToRadians(self.addaspeedd))
                    Player.position.Y = Player.position.Y + self.addspeed * Math.Sin(Math.ToRadians(self.addaspeedd))
                end
                -- player position limit
                --[[
                if (Player.position.X <= 4.5 + Player.add)
                    Player.position.X = 4.5 + Player.add
                if (Player.position.X >= 625.5 - Player.add)
                    Player.position.X = 625.5 - Player.add
                if (Player.position.Y <= 4.5)
                    Player.position.Y = 4.5
                if (Player.position.Y >= 475.5)
                    Player.position.Y = 475.5
                --]]
            end
        elseif Math.Abs(self.x - 4 - Player.position.X) <= self.halfw and Math.Abs(self.y + 16 - Player.position.Y) <= self.halfh then
            if self.Suction then
                local degrees2 = Math.ToDegrees(Main.Twopointangle(self.x - 4, self.y + 16, Player.position.X, Player.position.Y))
                Player.position.X = Player.position.X + self.addspeed * Math.Cos(Math.ToRadians(degrees2))
                Player.position.Y = Player.position.Y + self.addspeed * Math.Sin(Math.ToRadians(degrees2))
            elseif self.Repulsion then
                local num4 = Math.ToDegrees(Main.Twopointangle(self.x - 4, self.y + 16, Player.position.X, Player.position.Y))
                Player.position.X = Player.position.X + self.addspeed * Math.Cos(Math.ToRadians(180 + num4))
                Player.position.Y = Player.position.Y + self.addspeed * Math.Sin(Math.ToRadians(180 + num4))
            else
                Player.position.X = Player.position.X + self.addspeed * Math.Cos(Math.ToRadians(self.addaspeedd))
                Player.position.Y = Player.position.Y + self.addspeed * Math.Sin(Math.ToRadians(self.addaspeedd))
            end
            -- player position limit
        end
        -- barrage
        local barrages = layer.Barrages
        for _, barrage in ipairs(barrages) do
            if barrage.Force then
                if self.Circle then
                    if self.type == 0 then
                        if Math.Sqrt(((self.x - 4 - barrage.x) * (self.x - 4 - barrage.x) + (self.y + 16 - barrage.y) * (self.y + 16 - barrage.y))) <= Math.Max(self.halfw, self.halfh) then
                            if self.Suction then
                                local degrees3 = Math.ToDegrees(Main.Twopointangle(self.x - 4, self.y + 16, barrage.x, barrage.y))
                                barrage.speedx = barrage.speedx + barrage.xscale * self.addaspeed * Math.Cos(Math.ToRadians(degrees3))
                                barrage.speedy = barrage.speedy + barrage.yscale * self.addaspeed * Math.Sin(Math.ToRadians(degrees3))
                            elseif self.Repulsion then
                                local num5 = Math.ToDegrees(Main.Twopointangle(self.x - 4, self.y + 16, barrage.x, barrage.y))
                                barrage.speedx = barrage.speedx + barrage.xscale * self.addaspeed * Math.Cos(Math.ToRadians(180 + num5))
                                barrage.speedy = barrage.speedy + barrage.yscale * self.addaspeed * Math.Sin(Math.ToRadians(180 + num5))
                            else
                                barrage.speedx = barrage.speedx + barrage.xscale * self.addaspeed * Math.Cos(Math.ToRadians(self.addaspeedd))
                                barrage.speedy = barrage.speedy + barrage.yscale * self.addaspeed * Math.Sin(Math.ToRadians(self.addaspeedd))
                            end
                        end
                    elseif self.type == 1 and (barrage.parentid == self.controlid - 1 and Math.Sqrt(((self.x - 4 - barrage.x) * (self.x - 4 - barrage.x) + (self.y + 16 - barrage.y) * (self.y + 16 - barrage.y))) <= Math.Max(self.halfw, self.halfh)) then
                        if self.Suction then
                            local degrees4 = Math.ToDegrees(Main.Twopointangle(self.x - 4, self.y + 16, barrage.x, barrage.y))
                            barrage.speedx = barrage.speedx + barrage.xscale * self.addaspeed * Math.Cos(Math.ToRadians(degrees4))
                            barrage.speedy = barrage.speedy + barrage.yscale * self.addaspeed * Math.Sin(Math.ToRadians(degrees4))
                        elseif self.Repulsion then
                            local num6 = Math.ToDegrees(Main.Twopointangle(self.x - 4, self.y + 16, barrage.x, barrage.y))
                            barrage.speedx = barrage.speedx + barrage.xscale * self.addaspeed * Math.Cos(Math.ToRadians(180 + num6))
                            barrage.speedy = barrage.speedy + barrage.yscale * self.addaspeed * Math.Sin(Math.ToRadians(180 + num6))
                        else
                            barrage.speedx = barrage.speedx + barrage.xscale * self.addaspeed * Math.Cos(Math.ToRadians(self.addaspeedd))
                            barrage.speedy = barrage.speedy + barrage.yscale * self.addaspeed * Math.Sin(Math.ToRadians(self.addaspeedd))
                        end
                    end
                elseif self.type == 0 then
                    if Math.Abs(self.x - 4 - barrage.x) <= self.halfw and Math.Abs(self.y + 16 - barrage.y) <= self.halfh then
                        if self.Suction then
                            local degrees5 = Math.ToDegrees(Main.Twopointangle(self.x - 4, self.y + 16, barrage.x, barrage.y))
                            barrage.speedx = barrage.speedx + barrage.xscale * self.addaspeed * Math.Cos(Math.ToRadians(degrees5))
                            barrage.speedy = barrage.speedy + barrage.yscale * self.addaspeed * Math.Sin(Math.ToRadians(degrees5))
                        elseif self.Repulsion then
                            local num7 = Math.ToDegrees(Main.Twopointangle(self.x - 4, self.y + 16, barrage.x, barrage.y))
                            barrage.speedx = barrage.speedx + barrage.xscale * self.addaspeed * Math.Cos(Math.ToRadians(180 + num7))
                            barrage.speedy = barrage.speedy + barrage.yscale * self.addaspeed * Math.Sin(Math.ToRadians(180 + num7))
                        else
                            barrage.speedx = barrage.speedx + barrage.xscale * self.addaspeed * Math.Cos(Math.ToRadians(self.addaspeedd))
                            barrage.speedy = barrage.speedy + barrage.yscale * self.addaspeed * Math.Sin(Math.ToRadians(self.addaspeedd))
                        end
                    end
                elseif self.type == 1 and (barrage.parentid == self.controlid - 1 and Math.Abs(self.x - 4 - barrage.x) <= self.halfw and Math.Abs(self.y + 16 - barrage.y) <= self.halfh) then
                    if self.Suction then
                        local degrees6 = Math.ToDegrees(Main.Twopointangle(self.x - 4, self.y + 16, barrage.x, barrage.y))
                        barrage.speedx = barrage.speedx + barrage.xscale * self.addaspeed * Math.Cos(Math.ToRadians(degrees6))
                        barrage.speedy = barrage.speedy + barrage.yscale * self.addaspeed * Math.Sin(Math.ToRadians(degrees6))
                    elseif self.Repulsion then
                        local num8 = Math.ToDegrees(Main.Twopointangle(self.x - 4, self.y + 16, barrage.x, barrage.y))
                        barrage.speedx = barrage.speedx + barrage.xscale * self.addaspeed * Math.Cos(Math.ToRadians(180 + num8))
                        barrage.speedy = barrage.speedy + barrage.yscale * self.addaspeed * Math.Sin(Math.ToRadians(180 + num8))
                    else
                        barrage.speedx = barrage.speedx + barrage.xscale * self.addaspeed * Math.Cos(Math.ToRadians(self.addaspeedd))
                        barrage.speedy = barrage.speedy + barrage.yscale * self.addaspeed * Math.Sin(Math.ToRadians(self.addaspeedd))
                    end
                end
            end
        end
    end
end

function M:clone()
    local ret = M()
    for k, v in pairs(self) do
        ret[k] = table.deepcopy(v)
    end
    return ret
end

function M:copy()
    local ret = M()
    for k, v in pairs(self) do
        ret[k] = v
    end
    return ret
end

function M:getLayer()
    local Layer = require('game.mbg.Layer')
    return Layer.LayerArray[self.parentid + 1]
end

local mt = {
    __call = function(_, data)
        return _ctor(data)
    end
}
setmetatable(M, mt)

return M
