---@class lstg.mbg.Execution
local M = {}
--local M = class('lstg.mbg.Execution')
local Math = require('game.mbg._math')
local MathHelper = Math
local float = { Parse = function(s)
    return tonumber(s)
end }

function M:ctor()
    self.parentid = 0
    self.id = 0
    self.change = 0
    self.changetype = 0
    self.changevalue = 0
    self.region = ""
    self.value = 0
    self.time = 0
    self.ctime = 0
    self.NeedDelete = false
end

function M:clone()
    local ret = M()
    for k, v in pairs(self) do
        ret[k] = v
    end
    return ret
end

function M:update(objects)
    if (self.changetype == 0) then
        local v = self.changevalue
        if v == 0 then
            if (self.change == 0) then
                objects.fx = (objects.fx * (self.ctime - 1) + self.value) / self.ctime
            elseif (self.change == 1) then
                objects.fx = objects.fx + self.value / self.time
            elseif (self.change == 2) then
                objects.fx = objects.fx - self.value / self.time
            end
        elseif v == 1 then
            if (self.change == 0) then
                objects.fy = (objects.fy * (self.ctime - 1) + self.value) / self.ctime
            elseif (self.change == 1) then
                objects.fy = objects.fy + self.value / self.time
            elseif (self.change == 2) then
                objects.fy = objects.fy - self.value / self.time
            end
        elseif v == 2 then
            if (self.change == 0) then
                objects.r = (objects.r * (self.ctime - 1) + self.value) / self.ctime
            elseif (self.change == 1) then
                objects.r = objects.r + self.value / self.time
            elseif (self.change == 2) then
                objects.r = objects.r - self.value / self.time
            end
        elseif v == 3 then
            if (self.change == 0) then
                objects.rdirection = (objects.rdirection * (self.ctime - 1) + self.value) / self.ctime
            elseif (self.change == 1) then
                objects.rdirection = objects.rdirection + self.value / self.time
            elseif (self.change == 2) then
                objects.rdirection = objects.rdirection - self.value / self.time
            end
        elseif v == 4 then
            if (self.change == 0) then
                objects.tiao = math.floor((objects.tiao * (self.ctime - 1) + self.value) / self.ctime)
            elseif (self.change == 1) then
                objects.tiao = objects.tiao + math.floor(self.value / self.time)
            elseif (self.change == 2) then
                objects.tiao = objects.tiao - math.floor(self.value / self.time)
            end
        elseif v == 5 then
            if (self.change == 0) then
                objects.t = math.floor((objects.t * (self.ctime - 1) + self.value) / self.ctime)
            elseif (self.change == 1) then
                objects.t = objects.t + math.floor(self.value / self.time)
            elseif (self.change == 2) then
                objects.t = objects.t - math.floor(self.value / self.time)
            end
        elseif v == 6 then
            if (self.change == 0) then
                objects.fdirection = (objects.fdirection * (self.ctime - 1) + self.value) / self.ctime
            elseif (self.change == 1) then
                objects.fdirection = objects.fdirection + self.value / self.time
            elseif (self.change == 2) then
                objects.fdirection = objects.fdirection - self.value / self.time
            end
        elseif v == 7 then
            if (self.change == 0) then
                objects.range = math.floor((objects.range * (self.ctime - 1) + self.value) / self.ctime)
            elseif (self.change == 1) then
                objects.range = objects.range + math.floor(self.value / self.time)
            elseif (self.change == 2) then
                objects.range = objects.range - math.floor(self.value / self.time)
            end
        elseif v == 8 then
            if (self.change == 0) then
                objects.speed = (objects.speed * (self.ctime - 1) + self.value) / self.ctime
            elseif (self.change == 1) then
                objects.speed = objects.speed + self.value / self.time
            elseif (self.change == 2) then
                objects.speed = objects.speed - self.value / self.time
            end
            objects.speedx = objects.speed * Math.Cos(MathHelper.ToRadians(objects.speedd))
            objects.speedy = objects.speed * Math.Sin(MathHelper.ToRadians(objects.speedd))
        elseif v == 9 then
            if (self.change == 0) then
                objects.speedd = (objects.speedd * (self.ctime - 1) + self.value) / self.ctime
            elseif (self.change == 1) then
                objects.speedd = objects.speedd + self.value / self.time
            elseif (self.change == 2) then
                objects.speedd = objects.speedd - self.value / self.time
            end
            objects.speedx = objects.speed * Math.Cos(MathHelper.ToRadians(objects.speedd))
            objects.speedy = objects.speed * Math.Sin(MathHelper.ToRadians(objects.speedd))
        elseif v == 10 then
            if (self.change == 0) then
                objects.aspeed = (objects.aspeed * (self.ctime - 1) + self.value) / self.ctime
            elseif (self.change == 1) then
                objects.aspeed = objects.aspeed + self.value / self.time
            elseif (self.change == 2) then
                objects.aspeed = objects.aspeed - self.value / self.time
            end
            objects.aspeedx = objects.aspeed * Math.Cos(MathHelper.ToRadians(objects.aspeedd))
            objects.aspeedy = objects.aspeed * Math.Sin(MathHelper.ToRadians(objects.aspeedd))
        elseif v == 11 then
            if (self.change == 0) then
                objects.aspeedd = (math.floor((objects.aspeedd * (self.ctime - 1) + self.value) / self.ctime))
            elseif (self.change == 1) then
                objects.aspeedd = objects.aspeedd + self.value / self.time
            elseif (self.change == 2) then
                objects.aspeedd = objects.aspeedd - self.value / self.time
            end
            objects.aspeedx = objects.aspeed * Math.Cos(MathHelper.ToRadians(objects.aspeedd))
            objects.aspeedy = objects.aspeed * Math.Sin(MathHelper.ToRadians(objects.aspeedd))
        elseif v == 12 then
            if (self.change == 0) then
                objects.sonlife = math.floor((objects.sonlife * (self.ctime - 1) + self.value) / self.ctime)
            elseif (self.change == 1) then
                objects.sonlife = objects.sonlife + math.floor(self.value / self.time)
            elseif (self.change == 2) then
                objects.sonlife = objects.sonlife - math.floor(self.value / self.time)
            end
        elseif v == 13 then
            if (self.change == 0) then
                objects.type = (objects.type * (self.ctime - 1) + self.value) / self.ctime
            elseif (self.change == 1) then
                objects.type = objects.type + self.value / self.time
            elseif (self.change == 2) then
                objects.type = objects.type - self.value / self.time
            end
        elseif v == 14 then
            if (self.change == 0) then
                objects.wscale = (objects.wscale * (self.ctime - 1) + self.value) / self.ctime
            elseif (self.change == 1) then
                objects.wscale = objects.wscale + self.value / self.time
            elseif (self.change == 2) then
                objects.wscale = objects.wscale - self.value / self.time
            end
        elseif v == 15 then
            if (self.change == 0) then
                objects.hscale = (objects.hscale * (self.ctime - 1) + self.value) / self.ctime
            elseif (self.change == 1) then
                objects.hscale = objects.hscale + self.value / self.time
            elseif (self.change == 2) then
                objects.hscale = objects.hscale - self.value / self.time
            end
        elseif v == 16 then
            if (self.change == 0) then
                objects.colorR = (math.floor((objects.colorR * (self.ctime - 1) + self.value) / self.ctime))
            elseif (self.change == 1) then
                objects.colorR = objects.colorR + self.value / self.time
            elseif (self.change == 2) then
                objects.colorR = objects.colorR - self.value / self.time
            end
        elseif v == 17 then
            if (self.change == 0) then
                objects.colorG = (math.floor((objects.colorG * (self.ctime - 1) + self.value) / self.ctime))
            elseif (self.change == 1) then
                objects.colorG = objects.colorG + self.value / self.time
            elseif (self.change == 2) then
                objects.colorG = objects.colorG - self.value / self.time
            end
        elseif v == 18 then
            if (self.change == 0) then
                objects.colorB = (math.floor((objects.colorB * (self.ctime - 1) + self.value) / self.ctime))
            elseif (self.change == 1) then
                objects.colorB = objects.colorB + self.value / self.time
            elseif (self.change == 2) then
                objects.colorB = objects.colorB - self.value / self.time
            end
        elseif v == 19 then
            if (self.change == 0) then
                objects.alpha = (objects.alpha * (self.ctime - 1) + self.value) / self.ctime
            elseif (self.change == 1) then
                objects.alpha = objects.alpha + self.value / self.time
            elseif (self.change == 2) then
                objects.alpha = objects.alpha - self.value / self.time
            end
        elseif v == 20 then
            if (self.change == 0) then
                objects.head = (objects.head * (self.ctime - 1) + self.value) / self.ctime
            elseif (self.change == 1) then
                objects.head = objects.head + self.value / self.time
            elseif (self.change == 2) then
                objects.head = objects.head - self.value / self.time
            end
        elseif v == 21 then
            if (self.change == 0) then
                objects.sonspeed = (objects.sonspeed * (self.ctime - 1) + self.value) / self.ctime
            elseif (self.change == 1) then
                objects.sonspeed = objects.sonspeed + self.value / self.time
            elseif (self.change == 2) then
                objects.sonspeed = objects.sonspeed - self.value / self.time
            end
        elseif v == 22 then
            if (self.change == 0) then
                objects.sonspeedd = (math.floor((objects.sonspeedd * (self.ctime - 1) + self.value) / self.ctime))
            elseif (self.change == 1) then
                objects.sonspeedd = objects.sonspeedd + self.value / self.time
            elseif (self.change == 2) then
                objects.sonspeedd = objects.sonspeedd - self.value / self.time
            end
        elseif v == 23 then
            if (self.change == 0) then
                objects.sonaspeed = (objects.sonaspeed * (self.ctime - 1) + self.value) / self.ctime
            elseif (self.change == 1) then
                objects.sonaspeed = objects.sonaspeed + self.value / self.time
            elseif (self.change == 2) then
                objects.sonaspeed = objects.sonaspeed - self.value / self.time
            end
        elseif v == 24 then
            if (self.change == 0) then
                objects.sonaspeedd = (math.floor((objects.sonaspeedd * (self.ctime - 1) + self.value) / self.ctime))
            elseif (self.change == 1) then
                objects.sonaspeedd = objects.sonaspeedd + self.value / self.time
            elseif (self.change == 2) then
                objects.sonaspeedd = objects.sonaspeedd - self.value / self.time
            end
        elseif v == 25 then
            if (self.change == 0) then
                objects.xscale = (objects.xscale * (self.ctime - 1) + self.value) / self.ctime
            elseif (self.change == 1) then
                objects.xscale = objects.xscale + self.value / self.time
            elseif (self.change == 2) then
                objects.xscale = objects.xscale - self.value / self.time
            end
        elseif v == 26 then
            if (self.change == 0) then
                objects.yscale = (objects.yscale * (self.ctime - 1) + self.value) / self.ctime
            elseif (self.change == 1) then
                objects.yscale = objects.yscale + self.value / self.time
            elseif (self.change == 2) then
                objects.yscale = objects.yscale - self.value / self.time
            end
        elseif v == 27 then
            if (self.value > 0) then
                objects.Mist = true
            end
            if (self.value <= 0) then
                objects.Mist = false
            end
        elseif v == 28 then
            if (self.value > 0) then
                objects.Dispel = true
            end
            if (self.value <= 0) then
                objects.Dispel = false
            end
        elseif v == 29 then
            if (self.value > 0) then
                objects.Blend = true
            end
            if (self.value <= 0) then
                objects.Blend = false
            end
        elseif v == 30 then
            if (self.value > 0) then
                objects.Afterimage = true
            end
            if (self.value <= 0) then
                objects.Afterimage = false
            end
        elseif v == 31 then
            if (self.value > 0) then
                objects.Outdispel = true
            end
            if (self.value <= 0) then
                objects.Outdispel = false
            end
        elseif v == 32 then
            if (self.value > 0) then
                objects.Invincible = true
            end
            if (self.value <= 0) then
                objects.Invincible = false
            end
        end
    elseif (self.changetype == 1) then
        local v = self.changevalue
        if v == 0 then
            if (self.change == 0) then
                objects.fx = self.value
            elseif (self.change == 1) then
                objects.fx = objects.fx + self.value
            elseif (self.change == 2) then
                objects.fx = objects.fx - self.value
            end
        elseif v == 1 then
            if (self.change == 0) then
                objects.fy = self.value
            elseif (self.change == 1) then
                objects.fy = objects.fy + self.value
            elseif (self.change == 2) then
                objects.fy = objects.fy - self.value
            end
        elseif v == 2 then
            if (self.change == 0) then
                objects.r = self.value
            elseif (self.change == 1) then
                objects.r = objects.r + self.value
            elseif (self.change == 2) then
                objects.r = objects.r - self.value
            end
        elseif v == 3 then
            if (self.change == 0) then
                objects.rdirection = self.value
            elseif (self.change == 1) then
                objects.rdirection = objects.rdirection + self.value
            elseif (self.change == 2) then
                objects.rdirection = objects.rdirection - self.value
            end
        elseif v == 4 then
            if (self.change == 0) then
                objects.tiao = math.floor(self.value)
            elseif (self.change == 1) then
                objects.tiao = objects.tiao + math.floor(self.value)
            elseif (self.change == 2) then
                objects.tiao = objects.tiao - math.floor(self.value)
            end
        elseif v == 5 then
            if (self.change == 0) then
                objects.t = math.floor(self.value)
            elseif (self.change == 1) then
                objects.t = objects.t + math.floor(self.value)
            elseif (self.change == 2) then
                objects.t = objects.t - math.floor(self.value)
            end
        elseif v == 6 then
            if (self.change == 0) then
                objects.fdirection = self.value
            elseif (self.change == 1) then
                objects.fdirection = objects.fdirection + self.value
            elseif (self.change == 2) then
                objects.fdirection = objects.fdirection - self.value
            end
        elseif v == 7 then
            if (self.change == 0) then
                objects.range = math.floor(self.value)
            elseif (self.change == 1) then
                objects.range = objects.range + math.floor(self.value)
            elseif (self.change == 2) then
                objects.range = objects.range - math.floor(self.value)
            end
        elseif v == 8 then
            if (self.change == 0) then
                objects.speed = self.value
            elseif (self.change == 1) then
                objects.speed = objects.speed + self.value
            elseif (self.change == 2) then
                objects.speed = objects.speed - self.value
            end
            objects.speedx = objects.speed * Math.Cos(MathHelper.ToRadians(objects.speedd))
            objects.speedy = objects.speed * Math.Sin(MathHelper.ToRadians(objects.speedd))
        elseif v == 9 then
            if (self.change == 0) then
                objects.speedd = self.value
            elseif (self.change == 1) then
                objects.speedd = objects.speedd + self.value
            elseif (self.change == 2) then
                objects.speedd = objects.speedd - self.value
            end
            objects.speedx = objects.speed * Math.Cos(MathHelper.ToRadians(objects.speedd))
            objects.speedy = objects.speed * Math.Sin(MathHelper.ToRadians(objects.speedd))
        elseif v == 10 then
            if (self.change == 0) then
                objects.aspeed = self.value
            elseif (self.change == 1) then
                objects.aspeed = objects.aspeed + self.value
            elseif (self.change == 2) then
                objects.aspeed = objects.aspeed - self.value
            end
            objects.aspeedx = objects.aspeed * Math.Cos(MathHelper.ToRadians(objects.aspeedd))
            objects.aspeedy = objects.aspeed * Math.Sin(MathHelper.ToRadians(objects.aspeedd))
        elseif v == 11 then
            if (self.change == 0) then
                objects.aspeedd = self.value
            elseif (self.change == 1) then
                objects.aspeedd = objects.aspeedd + self.value
            elseif (self.change == 2) then
                objects.aspeedd = objects.aspeedd - self.value
            end
            objects.aspeedx = objects.aspeed * Math.Cos(MathHelper.ToRadians(objects.aspeedd))
            objects.aspeedy = objects.aspeed * Math.Sin(MathHelper.ToRadians(objects.aspeedd))
        elseif v == 12 then
            if (self.change == 0) then
                objects.sonlife = math.floor(self.value)
            elseif (self.change == 1) then
                objects.sonlife = objects.sonlife + math.floor(self.value)
            elseif (self.change == 2) then
                objects.sonlife = objects.sonlife - math.floor(self.value)
            end
        elseif v == 13 then
            if (self.change == 0) then
                objects.type = (math.floor(self.value))
            elseif (self.change == 1) then
                objects.type = objects.type + (math.floor(self.value))
            elseif (self.change == 2) then
                objects.type = objects.type - (math.floor(self.value))
            end
        elseif v == 14 then
            if (self.change == 0) then
                objects.wscale = self.value
            elseif (self.change == 1) then
                objects.wscale = objects.wscale + self.value
            elseif (self.change == 2) then
                objects.wscale = objects.wscale - self.value
            end
        elseif v == 15 then
            if (self.change == 0) then
                objects.hscale = self.value
            elseif (self.change == 1) then
                objects.hscale = objects.hscale + self.value
            elseif (self.change == 2) then
                objects.hscale = objects.hscale - self.value
            end
        elseif v == 16 then
            if (self.change == 0) then
                objects.colorR = self.value
            elseif (self.change == 1) then
                objects.colorR = objects.colorR + self.value
            elseif (self.change == 2) then
                objects.colorR = objects.colorR - self.value
            end
        elseif v == 17 then
            if (self.change == 0) then
                objects.colorG = self.value
            elseif (self.change == 1) then
                objects.colorG = objects.colorG + self.value
            elseif (self.change == 2) then
                objects.colorG = objects.colorG - self.value
            end
        elseif v == 18 then
            if (self.change == 0) then
                objects.colorB = self.value
            elseif (self.change == 1) then
                objects.colorB = objects.colorB + self.value
            elseif (self.change == 2) then
                objects.colorB = objects.colorB - self.value
            end
        elseif v == 19 then
            if (self.change == 0) then
                objects.alpha = self.value
            elseif (self.change == 1) then
                objects.alpha = objects.alpha + self.value
            elseif (self.change == 2) then
                objects.alpha = objects.alpha - self.value
            end
        elseif v == 20 then
            if (self.change == 0) then
                objects.head = self.value
            elseif (self.change == 1) then
                objects.head = objects.head + self.value
            elseif (self.change == 2) then
                objects.head = objects.head - self.value
            end
        elseif v == 21 then
            if (self.change == 0) then
                objects.sonspeed = self.value
            elseif (self.change == 1) then
                objects.sonspeed = objects.sonspeed + self.value
            elseif (self.change == 2) then
                objects.sonspeed = objects.sonspeed - self.value
            end
        elseif v == 22 then
            if (self.change == 0) then
                objects.sonspeedd = self.value
            elseif (self.change == 1) then
                objects.sonspeedd = objects.sonspeedd + self.value
            elseif (self.change == 2) then
                objects.sonspeedd = objects.sonspeedd - self.value
            end
        elseif v == 23 then
            if (self.change == 0) then
                objects.sonaspeed = self.value
            elseif (self.change == 1) then
                objects.sonaspeed = objects.sonaspeed + self.value
            elseif (self.change == 2) then
                objects.sonaspeed = objects.sonaspeed - self.value
            end
        elseif v == 24 then
            if (self.change == 0) then
                objects.sonaspeedd = self.value
            elseif (self.change == 1) then
                objects.sonaspeedd = objects.sonaspeedd + self.value
            elseif (self.change == 2) then
                objects.sonaspeedd = objects.sonaspeedd - self.value
            end
        elseif v == 25 then
            if (self.change == 0) then
                objects.xscale = self.value
            elseif (self.change == 1) then
                objects.xscale = objects.xscale + self.value
            elseif (self.change == 2) then
                objects.xscale = objects.xscale - self.value
            end
        elseif v == 26 then
            if (self.change == 0) then
                objects.yscale = self.value
            elseif (self.change == 1) then
                objects.yscale = objects.yscale + self.value
            elseif (self.change == 2) then
                objects.yscale = objects.yscale - self.value
            end
        elseif v == 27 then
            if (self.value > 0) then
                objects.Mist = true
            end
            if (self.value <= 0) then
                objects.Mist = false
            end
        elseif v == 28 then
            if (self.value > 0) then
                objects.Dispel = true
            end
            if (self.value <= 0) then
                objects.Dispel = false
            end
        elseif v == 29 then
            if (self.value > 0) then
                objects.Blend = true
            end
            if (self.value <= 0) then
                objects.Blend = false
            end
        elseif v == 30 then
            if (self.value > 0) then
                objects.Afterimage = true
            end
            if (self.value <= 0) then
                objects.Afterimage = false
            end
        elseif v == 31 then
            if (self.value > 0) then
                objects.Outdispel = true
            end
            if (self.value <= 0) then
                objects.Outdispel = false
            end
        elseif v == 32 then
            if (self.value > 0) then
                objects.Invincible = true
            end
            if (self.value <= 0) then
                objects.Invincible = false
            end
        end
    elseif (self.changetype == 2) then
        local v = self.changevalue
        if v == 0 then
            if (self.change == 0) then
                objects.fx = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.fx = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.fx = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
        elseif v == 1 then
            if (self.change == 0) then
                objects.fy = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.fy = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.fy = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
        elseif v == 2 then
            if (self.change == 0) then
                objects.r = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.r = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.r = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
        elseif v == 3 then
            if (self.change == 0) then
                objects.rdirection = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.rdirection = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.rdirection = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
        elseif v == 4 then
            if (self.change == 0) then
                objects.tiao = math.floor(float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime))))
            elseif (self.change == 1) then
                objects.tiao = math.floor(float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime))))
            elseif (self.change == 2) then
                objects.tiao = math.floor(float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime))))
            end
        elseif v == 5 then
            if (self.change == 0) then
                objects.t = math.floor(float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime))))
            elseif (self.change == 1) then
                objects.t = math.floor(float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime))))
            elseif (self.change == 2) then
                objects.t = math.floor(float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime))))
            end
        elseif v == 6 then
            if (self.change == 0) then
                objects.fdirection = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.fdirection = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.fdirection = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
        elseif v == 7 then
            if (self.change == 0) then
                objects.range = math.floor(float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime))))
            elseif (self.change == 1) then
                objects.range = math.floor(float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime))))
            elseif (self.change == 2) then
                objects.range = math.floor(float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime))))
            end
        elseif v == 8 then
            if (self.change == 0) then
                objects.speed = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.speed = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.speed = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
            objects.speedx = objects.speed * Math.Cos(MathHelper.ToRadians(objects.speedd))
            objects.speedy = objects.speed * Math.Sin(MathHelper.ToRadians(objects.speedd))
        elseif v == 9 then
            if (self.change == 0) then
                objects.speedd = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.speedd = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.speedd = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
            objects.speedx = objects.speed * Math.Cos(MathHelper.ToRadians(objects.speedd))
            objects.speedy = objects.speed * Math.Sin(MathHelper.ToRadians(objects.speedd))
        elseif v == 10 then
            if (self.change == 0) then
                objects.aspeed = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.aspeed = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.aspeed = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
            objects.aspeedx = objects.aspeed * Math.Cos(MathHelper.ToRadians(objects.aspeedd))
            objects.aspeedy = objects.aspeed * Math.Sin(MathHelper.ToRadians(objects.aspeedd))
        elseif v == 11 then
            if (self.change == 0) then
                objects.aspeedd = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.aspeedd = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.aspeedd = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
            objects.aspeedx = objects.aspeed * Math.Cos(MathHelper.ToRadians(objects.aspeedd))
            objects.aspeedy = objects.aspeed * Math.Sin(MathHelper.ToRadians(objects.aspeedd))
        elseif v == 12 then
            if (self.change == 0) then
                objects.sonlife = math.floor(float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime))))
            elseif (self.change == 1) then
                objects.sonlife = math.floor(float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime))))
            elseif (self.change == 2) then
                objects.sonlife = math.floor(float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime))))
            end
        elseif v == 13 then
            if (self.change == 0) then
                objects.type = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.type = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.type = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
        elseif v == 14 then
            if (self.change == 0) then
                objects.wscale = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.wscale = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.wscale = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
        elseif v == 15 then
            if (self.change == 0) then
                objects.hscale = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.hscale = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.hscale = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
        elseif v == 16 then
            if (self.change == 0) then
                objects.colorR = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.colorR = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.colorR = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
        elseif v == 17 then
            if (self.change == 0) then
                objects.colorG = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.colorG = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.colorG = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
        elseif v == 18 then
            if (self.change == 0) then
                objects.colorB = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.colorB = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.colorB = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
        elseif v == 19 then
            if (self.change == 0) then
                objects.alpha = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.alpha = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.alpha = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
        elseif v == 20 then
            if (self.change == 0) then
                objects.head = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.head = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.head = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
        elseif v == 21 then
            if (self.change == 0) then
                objects.sonspeed = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.sonspeed = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.sonspeed = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
        elseif v == 22 then
            if (self.change == 0) then
                objects.sonspeedd = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.sonspeedd = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.sonspeedd = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
        elseif v == 23 then
            if (self.change == 0) then
                objects.sonaspeed = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.sonaspeed = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.sonaspeed = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
        elseif v == 24 then
            if (self.change == 0) then
                objects.sonaspeedd = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.sonaspeedd = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.sonaspeedd = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
        elseif v == 25 then
            if (self.change == 0) then
                objects.xscale = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.xscale = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.xscale = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
        elseif v == 26 then
            if (self.change == 0) then
                objects.yscale = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.yscale = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.yscale = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
        elseif v == 27 then
            if (self.value > 0) then
                objects.Mist = true
            end
            if (self.value <= 0) then
                objects.Mist = false
            end
        elseif v == 28 then
            if (self.value > 0) then
                objects.Dispel = true
            end
            if (self.value <= 0) then
                objects.Dispel = false
            end
        elseif v == 29 then
            if (self.value > 0) then
                objects.Blend = true
            end
            if (self.value <= 0) then
                objects.Blend = false
            end
        elseif v == 30 then
            if (self.value > 0) then
                objects.Afterimage = true
            end
            if (self.value <= 0) then
                objects.Afterimage = false
            end
        elseif v == 31 then
            if (self.value > 0) then
                objects.Outdispel = true
            end
            if (self.value <= 0) then
                objects.Outdispel = false
            end
        elseif v == 32 then
            if (self.value > 0) then
                objects.Invincible = true
            end
            if (self.value <= 0) then
                objects.Invincible = false
            end
        end
    end
    self.ctime = self.ctime - 1
    if (self.changetype == 2 and self.ctime == -1) then
        self.NeedDelete = true
        return
    end
    if (self.changetype ~= 2 and self.ctime == 0) then
        self.NeedDelete = true
    end
end

local mt = {
    __call = function()
        local ret = {}
        M.ctor(ret)
        ret.clone = M.clone
        ret.update = M.update
        return ret
    end
}
setmetatable(M, mt)

return M
