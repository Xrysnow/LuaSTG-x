---@class lstg.mbg.BLExecution
local M = class('lstg.mbg.BLExecution')
local Math = require('game.mbg._math')
local MathHelper = Math
local float = { Parse = function(s)
    return tonumber(s)
end }

function M:ctor()
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

function M:update(objects)
    if (self.changetype == 1) then
        local v = self.changevalue
        if v == 0 then
            if (self.change == 0) then
                objects.life = math.floor(self.value)
            elseif (self.change == 1) then
                objects.life = objects.life + math.floor(self.value)
            elseif (self.change == 2) then
                objects.life = objects.life - math.floor(self.value)
            end
        elseif v == 1 then
            if (self.change == 0) then
                objects.type = math.floor(self.value)
            elseif (self.change == 1) then
                objects.type = objects.type + math.floor(self.value)
            elseif (self.change == 2) then
                objects.type = objects.type - math.floor(self.value)
            end
        elseif v == 2 then
            if (self.change == 0) then
                objects.wscale = self.value
            elseif (self.change == 1) then
                objects.wscale = objects.wscale + self.value
            elseif (self.change == 2) then
                objects.wscale = objects.wscale - self.value
            end
        elseif v == 3 then
            if (self.change == 0) then
                objects.longs = self.value
            elseif (self.change == 1) then
                objects.longs = objects.longs + self.value
            elseif (self.change == 2) then
                objects.longs = objects.longs - self.value
            end
        elseif v == 4 then
            if (self.change == 0) then
                objects.alpha = self.value
            elseif (self.change == 1) then
                objects.alpha = objects.alpha + self.value
            elseif (self.change == 2) then
                objects.alpha = objects.alpha - self.value
            end
        elseif v == 5 then
            if (self.change == 0) then
                objects.speed = self.value
            elseif (self.change == 1) then
                objects.speed = objects.speed + self.value
            elseif (self.change == 2) then
                objects.speed = objects.speed - self.value
            end
            objects.speedx = objects.xscale * objects.speed * Math.Cos(MathHelper.ToRadians(objects.speedd))
            objects.speedy = objects.yscale * objects.speed * Math.Sin(MathHelper.ToRadians(objects.speedd))
        elseif v == 6 then
            if (self.change == 0) then
                objects.speedd = self.value
            elseif (self.change == 1) then
                objects.speedd = objects.speedd + self.value
            elseif (self.change == 2) then
                objects.speedd = objects.speedd - self.value
            end
            objects.speedx = objects.xscale * objects.speed * Math.Cos(MathHelper.ToRadians(objects.speedd))
            objects.speedy = objects.yscale * objects.speed * Math.Sin(MathHelper.ToRadians(objects.speedd))
        elseif v == 7 then
            if (self.change == 0) then
                objects.aspeed = self.value
            elseif (self.change == 1) then
                objects.aspeed = objects.aspeed + self.value
            elseif (self.change == 2) then
                objects.aspeed = objects.aspeed - self.value
            end
            objects.aspeedx = objects.xscale * objects.aspeed * Math.Cos(MathHelper.ToRadians(objects.aspeedd))
            objects.aspeedy = objects.yscale * objects.aspeed * Math.Sin(MathHelper.ToRadians(objects.aspeedd))
        elseif v == 8 then
            if (self.change == 0) then
                objects.aspeedd = self.value
            elseif (self.change == 1) then
                objects.aspeedd = objects.aspeedd + self.value
            elseif (self.change == 2) then
                objects.aspeedd = objects.aspeedd - self.value
            end
            objects.aspeedx = objects.xscale * objects.aspeed * Math.Cos(MathHelper.ToRadians(objects.aspeedd))
            objects.aspeedy = objects.yscale * objects.aspeed * Math.Sin(MathHelper.ToRadians(objects.aspeedd))
        elseif v == 9 then
            if (self.change == 0) then
                objects.xscale = self.value
            elseif (self.change == 1) then
                objects.xscale = objects.xscale + self.value
            elseif (self.change == 2) then
                objects.xscale = objects.xscale - self.value
            end
        elseif v == 10 then
            if (self.change == 0) then
                objects.yscale = self.value
            elseif (self.change == 1) then
                objects.yscale = objects.yscale + self.value
            elseif (self.change == 2) then
                objects.yscale = objects.yscale - self.value
            end
        elseif v == 11 then
            if (self.value > 0) then
                objects.Blend = true
            end
            if (self.value <= 0) then
                objects.Blend = false
            end
        elseif v == 12 then
            if (self.value > 0) then
                objects.Outdispel = true
            end
            if (self.value <= 0) then
                objects.Outdispel = false
            end
        elseif v == 13 then
            if (self.value > 0) then
                objects.Invincible = true
            end
            if (self.value <= 0) then
                objects.Invincible = false
            end
        end
    elseif (self.changetype == 0) then
        local v = self.changevalue
        if v == 0 then
            if (self.change == 0) then
                objects.life = math.floor((objects.life * (self.ctime - 1) + self.value) / self.ctime)
            elseif (self.change == 1) then
                objects.life = objects.life + math.floor(self.value / self.time)
            elseif (self.change == 2) then
                objects.life = objects.life - math.floor(self.value / self.time)
            end
        elseif v == 1 then
            if (self.change == 0) then
                objects.type = math.floor((objects.type * (self.ctime - 1) + self.value) / self.ctime)
            elseif (self.change == 1) then
                objects.type = objects.type + math.floor(self.value / self.time)
            elseif (self.change == 2) then
                objects.type = objects.type - math.floor(self.value / self.time)
            end
        elseif v == 2 then
            if (self.change == 0) then
                objects.wscale = (objects.wscale * (self.ctime - 1) + self.value) / self.ctime
            elseif (self.change == 1) then
                objects.wscale = objects.wscale + self.value / self.time
            elseif (self.change == 2) then
                objects.wscale = objects.wscale - self.value / self.time
            end
        elseif v == 3 then
            if (self.change == 0) then
                objects.longs = (objects.longs * (self.ctime - 1) + self.value) / self.ctime
            elseif (self.change == 1) then
                objects.longs = objects.longs + self.value / self.time
            elseif (self.change == 2) then
                objects.longs = objects.longs - self.value / self.time
            end
        elseif v == 4 then
            if (self.change == 0) then
                objects.alpha = (objects.alpha * (self.ctime - 1) + self.value) / self.ctime
            elseif (self.change == 1) then
                objects.alpha = objects.alpha + self.value / self.time
            elseif (self.change == 2) then
                objects.alpha = objects.alpha - self.value / self.time
            end
        elseif v == 5 then
            if (self.change == 0) then
                objects.speed = (objects.speed * (self.ctime - 1) + self.value) / self.ctime
            elseif (self.change == 1) then
                objects.speed = objects.speed + self.value / self.time
            elseif (self.change == 2) then
                objects.speed = objects.speed - self.value / self.time
            end
            objects.speedx = objects.xscale * objects.speed * Math.Cos(MathHelper.ToRadians(objects.speedd))
            objects.speedy = objects.yscale * objects.speed * Math.Sin(MathHelper.ToRadians(objects.speedd))
        elseif v == 6 then
            if (self.change == 0) then
                objects.speedd = (objects.speedd * (self.ctime - 1) + self.value) / self.ctime
            elseif (self.change == 1) then
                objects.speedd = objects.speedd + self.value / self.time
            elseif (self.change == 2) then
                objects.speedd = objects.speedd - self.value / self.time
            end
            objects.speedx = objects.xscale * objects.speed * Math.Cos(MathHelper.ToRadians(objects.speedd))
            objects.speedy = objects.yscale * objects.speed * Math.Sin(MathHelper.ToRadians(objects.speedd))
        elseif v == 7 then
            if (self.change == 0) then
                objects.aspeed = (objects.aspeed * (self.ctime - 1) + self.value) / self.ctime
            elseif (self.change == 1) then
                objects.aspeed = objects.aspeed + self.value / self.time
            elseif (self.change == 2) then
                objects.aspeed = objects.aspeed - self.value / self.time
            end
            objects.aspeedx = objects.xscale * objects.aspeed * Math.Cos(MathHelper.ToRadians(objects.aspeedd))
            objects.aspeedy = objects.yscale * objects.aspeed * Math.Sin(MathHelper.ToRadians(objects.aspeedd))
        elseif v == 8 then
            if (self.change == 0) then
                objects.aspeedd = (objects.aspeedd * (self.ctime - 1) + self.value) / self.ctime
            elseif (self.change == 1) then
                objects.aspeedd = objects.aspeedd + self.value / self.time
            elseif (self.change == 2) then
                objects.aspeedd = objects.aspeedd - self.value / self.time
            end
            objects.aspeedx = objects.xscale * objects.aspeed * Math.Cos(MathHelper.ToRadians(objects.aspeedd))
            objects.aspeedy = objects.yscale * objects.aspeed * Math.Sin(MathHelper.ToRadians(objects.aspeedd))
        elseif v == 9 then
            if (self.change == 0) then
                objects.xscale = (objects.xscale * (self.ctime - 1) + self.value) / self.ctime
            elseif (self.change == 1) then
                objects.xscale = objects.xscale + self.value / self.time
            elseif (self.change == 2) then
                objects.xscale = objects.xscale - self.value / self.time
            end
        elseif v == 10 then
            if (self.change == 0) then
                objects.yscale = (objects.yscale * (self.ctime - 1) + self.value) / self.ctime
            elseif (self.change == 1) then
                objects.yscale = objects.yscale + self.value / self.time
            elseif (self.change == 2) then
                objects.yscale = objects.yscale - self.value / self.time
            end
        elseif v == 11 then
            if (self.value > 0) then
                objects.Blend = true
            end
            if (self.value <= 0) then
                objects.Blend = false
            end
        elseif v == 12 then
            if (self.value > 0) then
                objects.Outdispel = true
            end
            if (self.value <= 0) then
                objects.Outdispel = false
            end
        elseif v == 13 then
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
                objects.life = math.floor(float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime))))
            elseif (self.change == 1) then
                objects.life = math.floor(float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime))))
            elseif (self.change == 2) then
                objects.life = math.floor(float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime))))
            end
        elseif v == 1 then
            if (self.change == 0) then
                objects.type = math.floor(float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime))))
            elseif (self.change == 1) then
                objects.type = math.floor(float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime))))
            elseif (self.change == 2) then
                objects.type = math.floor(float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime))))
            end
        elseif v == 2 then
            if (self.change == 0) then
                objects.wscale = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.wscale = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.wscale = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
        elseif v == 3 then
            if (self.change == 0) then
                objects.longs = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.longs = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.longs = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
        elseif v == 4 then
            if (self.change == 0) then
                objects.alpha = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.alpha = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.alpha = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
        elseif v == 5 then
            if (self.change == 0) then
                objects.speed = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.speed = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.speed = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
            objects.speedx = objects.xscale * objects.speed * Math.Cos(MathHelper.ToRadians(objects.speedd))
            objects.speedy = objects.yscale * objects.speed * Math.Sin(MathHelper.ToRadians(objects.speedd))
        elseif v == 6 then
            if (self.change == 0) then
                objects.speedd = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.speedd = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.speedd = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
            objects.speedx = objects.xscale * objects.speed * Math.Cos(MathHelper.ToRadians(objects.speedd))
            objects.speedy = objects.yscale * objects.speed * Math.Sin(MathHelper.ToRadians(objects.speedd))
        elseif v == 7 then
            if (self.change == 0) then
                objects.aspeed = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.aspeed = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.aspeed = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
            objects.aspeedx = objects.xscale * objects.aspeed * Math.Cos(MathHelper.ToRadians(objects.aspeedd))
            objects.aspeedy = objects.yscale * objects.aspeed * Math.Sin(MathHelper.ToRadians(objects.aspeedd))
        elseif v == 8 then
            if (self.change == 0) then
                objects.aspeedd = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.aspeedd = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.aspeedd = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
            objects.aspeedx = objects.xscale * objects.aspeed * Math.Cos(MathHelper.ToRadians(objects.aspeedd))
            objects.aspeedy = objects.yscale * objects.aspeed * Math.Sin(MathHelper.ToRadians(objects.aspeedd))
        elseif v == 9 then
            if (self.change == 0) then
                objects.xscale = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.xscale = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.xscale = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
        elseif v == 10 then
            if (self.change == 0) then
                objects.yscale = float.Parse(self.region) + (self.value - float.Parse(self.region)) * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 1) then
                objects.yscale = float.Parse(self.region) + self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            elseif (self.change == 2) then
                objects.yscale = float.Parse(self.region) - self.value * Math.Sin(MathHelper.ToRadians(360 / self.time * (self.time - self.ctime)))
            end
        elseif v == 11 then
            if (self.value > 0) then
                objects.Blend = true
            end
            if (self.value <= 0) then
                objects.Blend = false
            end
        elseif v == 12 then
            if (self.value > 0) then
                objects.Outdispel = true
            end
            if (self.value <= 0) then
                objects.Outdispel = false
            end
        elseif v == 13 then
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

return M
