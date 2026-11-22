---@class lstg.mbg.BExecution
local M = {}
--local M = class('lstg.mbg.BExecution')
local Math = require('game.mbg._math')
local MathHelper = Math

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

local function CosDeg(x)
    return Math.Cos(MathHelper.ToRadians(x))
end
local function SinDeg(x)
    return Math.Sin(MathHelper.ToRadians(x))
end

local function _updateSpeed(objects)
    objects.speedx = objects.xscale * objects.speed * CosDeg(objects.speedd)
    objects.speedy = objects.yscale * objects.speed * SinDeg(objects.speedd)
end
local function _updateASpeed(objects)
    objects.aspeedx = objects.xscale * objects.aspeed * CosDeg(objects.aspeedd)
    objects.aspeedy = objects.yscale * objects.aspeed * SinDeg(objects.aspeedd)
end

local Type1Map = {}
for i = 0, 14 do
    Type1Map[i] = {}
end
local function makeType1(change, key)
    if change == 0 then
        return function(v, o)
            o[key] = v
        end
    elseif (change == 1) then
        return function(v, o)
            o[key] = o[key] + v
        end
    elseif (change == 2) then
        return function(v, o)
            o[key] = o[key] - v
        end
    end
end
local function makeType1Int(change, key)
    local floor = math.floor
    if change == 0 then
        return function(v, o)
            o[key] = floor(v)
        end
    elseif (change == 1) then
        return function(v, o)
            o[key] = o[key] + floor(v)
        end
    elseif (change == 2) then
        return function(v, o)
            o[key] = o[key] - floor(v)
        end
    end
end
local function makeType1Ex(change, key, f)
    if change == 0 then
        return function(v, o)
            o[key] = v
            f(o)
        end
    elseif (change == 1) then
        return function(v, o)
            o[key] = o[key] + v
            f(o)
        end
    elseif (change == 2) then
        return function(v, o)
            o[key] = o[key] - v
            f(o)
        end
    end
end
for change = 0, 2 do
    Type1Map[0][change] = makeType1Int(change, 'life')
    Type1Map[1][change] = makeType1Int(change, 'type')
    Type1Map[2][change] = makeType1(change, 'wscale')
    Type1Map[3][change] = makeType1(change, 'hscale')
    Type1Map[4][change] = makeType1(change, 'R')
    Type1Map[5][change] = makeType1(change, 'G')
    Type1Map[6][change] = makeType1(change, 'B')
    Type1Map[7][change] = makeType1(change, 'alpha')
    Type1Map[8][change] = makeType1(change, 'head')
    Type1Map[9][change] = makeType1Ex(change, 'speed', _updateSpeed)
    Type1Map[10][change] = makeType1Ex(change, 'speedd', _updateSpeed)
    Type1Map[11][change] = makeType1Ex(change, 'aspeed', _updateASpeed)
    Type1Map[12][change] = makeType1Ex(change, 'aspeedd', _updateASpeed)
    Type1Map[13][change] = makeType1(change, 'xscale')
    Type1Map[14][change] = makeType1(change, 'yscale')
end

--

local Type0Map = {}
for i = 0, 14 do
    Type0Map[i] = {}
end
local function makeType0(change, key)
    if change == 0 then
        return function(v, o, self)
            local ct = self.ctime
            o[key] = (o[key] * (ct - 1) + v) / ct
        end
    elseif (change == 1) then
        return function(v, o, self)
            o[key] = o[key] + v / self.time
        end
    elseif (change == 2) then
        return function(v, o, self)
            o[key] = o[key] - v / self.time
        end
    end
end
local function makeType0Int(change, key)
    local floor = math.floor
    if change == 0 then
        return function(v, o, self)
            local ct = self.ctime
            o[key] = floor((o[key] * (ct - 1) + v) / ct)
        end
    elseif (change == 1) then
        return function(v, o, self)
            o[key] = o[key] + floor(v / self.time)
        end
    elseif (change == 2) then
        return function(v, o, self)
            o[key] = o[key] - floor(v / self.time)
        end
    end
end
local function makeType0Ex(change, key, f)
    if change == 0 then
        return function(v, o, self)
            local ct = self.ctime
            o[key] = (o[key] * (ct - 1) + v) / ct
            f(o)
        end
    elseif (change == 1) then
        return function(v, o, self)
            o[key] = o[key] + v / self.time
            f(o)
        end
    elseif (change == 2) then
        return function(v, o, self)
            o[key] = o[key] - v / self.time
            f(o)
        end
    end
end
for change = 0, 2 do
    Type0Map[0][change] = makeType0Int(change, 'life')
    Type0Map[1][change] = makeType0Int(change, 'type')
    Type0Map[2][change] = makeType0(change, 'wscale')
    Type0Map[3][change] = makeType0(change, 'hscale')
    Type0Map[4][change] = makeType0(change, 'R')
    Type0Map[5][change] = makeType0(change, 'G')
    Type0Map[6][change] = makeType0(change, 'B')
    Type0Map[7][change] = makeType0(change, 'alpha')
    Type0Map[8][change] = makeType0(change, 'head')
    Type0Map[9][change] = makeType0Ex(change, 'speed', _updateSpeed)
    Type0Map[10][change] = makeType0Ex(change, 'speedd', _updateSpeed)
    Type0Map[11][change] = makeType0Ex(change, 'aspeed', _updateASpeed)
    Type0Map[12][change] = makeType0Ex(change, 'aspeedd', _updateASpeed)
    Type0Map[13][change] = makeType0(change, 'xscale')
    Type0Map[14][change] = makeType0(change, 'yscale')
end

--

local Type2Map = {}
for i = 0, 14 do
    Type2Map[i] = {}
end
local function makeType2(change, key)
    if change == 0 then
        return function(v, o, regin, factor)
            o[key] = regin + (v - regin) * factor
        end
    elseif (change == 1) then
        return function(v, o, regin, factor)
            o[key] = regin + v * factor
        end
    elseif (change == 2) then
        return function(v, o, regin, factor)
            o[key] = regin - v * factor
        end
    end
end
local function makeType2Int(change, key)
    local floor = math.floor
    if change == 0 then
        return function(v, o, regin, factor)
            o[key] = floor(regin + (v - regin) * factor)
        end
    elseif (change == 1) then
        return function(v, o, regin, factor)
            o[key] = floor(regin + v * factor)
        end
    elseif (change == 2) then
        return function(v, o, regin, factor)
            o[key] = floor(regin - v * factor)
        end
    end
end
local function makeType2Ex(change, key, f)
    if change == 0 then
        return function(v, o, regin, factor)
            o[key] = regin + (v - regin) * factor
            f(o)
        end
    elseif (change == 1) then
        return function(v, o, regin, factor)
            o[key] = regin + v * factor
            f(o)
        end
    elseif (change == 2) then
        return function(v, o, regin, factor)
            o[key] = regin - v * factor
            f(o)
        end
    end
end
for change = 0, 2 do
    Type2Map[0][change] = makeType2Int(change, 'life')
    Type2Map[1][change] = makeType2Int(change, 'type')
    Type2Map[2][change] = makeType2(change, 'wscale')
    Type2Map[3][change] = makeType2(change, 'hscale')
    Type2Map[4][change] = makeType2(change, 'R')
    Type2Map[5][change] = makeType2(change, 'G')
    Type2Map[6][change] = makeType2(change, 'B')
    Type2Map[7][change] = makeType2(change, 'alpha')
    Type2Map[8][change] = makeType2(change, 'head')
    Type2Map[9][change] = makeType2Ex(change, 'speed', _updateSpeed)
    Type2Map[10][change] = makeType2Ex(change, 'speedd', _updateSpeed)
    Type2Map[11][change] = makeType2Ex(change, 'aspeed', _updateASpeed)
    Type2Map[12][change] = makeType2Ex(change, 'aspeedd', _updateASpeed)
    Type2Map[13][change] = makeType2(change, 'xscale')
    Type2Map[14][change] = makeType2(change, 'yscale')
end

--

local TypeBoolMap = {}
TypeBoolMap[1] = function(v, o)
    o.Mist = v > 0
end
TypeBoolMap[2] = function(v, o)
    o.Dispel = v > 0
end
TypeBoolMap[3] = function(v, o)
    o.Blend = v > 0
end
TypeBoolMap[4] = function(v, o)
    o.Afterimage = v > 0
end
TypeBoolMap[5] = function(v, o)
    o.Outdispel = v > 0
end
TypeBoolMap[6] = function(v, o)
    o.Invincible = v > 0
end

function M:update(objects)
    local _change = self.change
    local _changetype = self.changetype
    local _value = self.value
    if (_changetype == 1) then
        local v = self.changevalue
        if v <= 14 then
            Type1Map[v][_change](_value, objects)
        else
            TypeBoolMap[v - 14](_value, objects)
        end
    elseif (_changetype == 0) then
        local v = self.changevalue
        if v <= 14 then
            Type0Map[v][_change](_value, objects, self)
        else
            TypeBoolMap[v - 14](_value, objects)
        end
    elseif (_changetype == 2) then
        local v = self.changevalue
        if v <= 14 then
            local _factor = SinDeg(360 / self.time * (self.time - self.ctime))
            Type2Map[v][_change](_value, objects, self.region, _factor)
        else
            TypeBoolMap[v - 14](_value, objects)
        end
    end
    self.ctime = self.ctime - 1
    if (_changetype == 2 and self.ctime == -1) then
        self.NeedDelete = true
        return
    end
    if (_changetype ~= 2 and self.ctime == 0) then
        self.NeedDelete = true
    end
end

local mt = {
    __call = function()
        local ret = {}
        M.ctor(ret)
        ret.update = M.update
        return ret
    end
}
setmetatable(M, mt)

return M
