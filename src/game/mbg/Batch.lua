---@class lstg.mbg.Batch
local M = class('lstg.mbg.Batch')
local Center = require('game.mbg.Center')
local Player = require('game.mbg.Player')
local Time = require('game.mbg.Time')
local Main = require('game.mbg.Main')
local Math = require('game.mbg._math')
local MathHelper = Math
local float = { Parse = function(s)
    return tonumber(s)
end }

M.record = 0

---@param data mbg.BulletEmitter
function M:ctor(data)
    self.clcount = 0
    self.clwait = 0
    self.conditions = {} --float[13];
    for i = 1, 13 do
        self.conditions[i - 1] = 0
    end
    self.results = {} --float[33];
    for i = 1, 33 do
        self.results[i - 1] = 0
    end

    self.Selecting = false
    self.Searched = 0
    self.NeedDelete = false

    if data then
        self.id = 0
        self.parentid = 0
        self.parentcolor = 0
        self.Binding = false
        self.bindid = -1
        self.Bindwithspeedd = false
        self.Deepbind = false
        self.Deepbinded = false
        self.x = 0
        self.y = 0
        self.time = 0
        self.begin = 0
        self.life = 0
        self.fx = -99998
        self.fy = -99998
        self.r = 0
        self.rdirection = 0
        self.rdirections = { X = 0, Y = 0 }
        self.tiao = 1
        self.t = 5
        self.fdirection = 0
        self.bfdirection = 0
        self.fdirections = { X = 0, Y = 0 }
        self.range = 360
        self.speed = 0
        self.speedd = 0
        self.speedx = 0
        self.speedy = 0
        self.speedds = { X = 0, Y = 0 }
        self.aspeed = 0
        self.aspeedx = 0
        self.aspeedy = 0
        self.aspeedd = 0
        self.aspeedds = { X = 0, Y = 0 }
        self.sonlife = 200
        self.type = 1
        self.wscale = 1
        self.hscale = 1
        self.colorR = 255
        self.colorG = 255
        self.colorB = 255
        self.alpha = 100
        self.head = 0
        self.heads = { X = 0, Y = 0 }
        self.Withspeedd = true
        self.sonspeed = 5
        self.sonspeedd = 0
        self.sonspeedds = { X = 0, Y = 0 }
        self.sonaspeed = 0
        self.sonaspeedd = 0
        self.bsonaspeedd = 0
        self.sonaspeedds = { X = 0, Y = 0 }
        self.xscale = 1
        self.yscale = 1
        self.Mist = true
        self.Dispel = true
        self.Blend = false
        self.Afterimage = false
        self.Outdispel = true
        self.Invincible = false
        self.Cover = true
        self.Rebound = true
        self.Force = true
    else
        self.id = 0
        self.parentid = 0
        self.parentcolor = 0
        self.Binding = false
        self.bindid = -1
        self.Bindwithspeedd = false
        self.Deepbind = false
        self.Deepbinded = false
        self.x = 0
        self.y = 0
        self.time = 0
        self.begin = 0
        self.life = 0
        self.fx = 0
        self.fy = 0
        self.r = 0
        self.rdirection = 0
        self.rdirections = { X = 0, Y = 0 }
        self.tiao = 0
        self.t = 0
        self.fdirection = 0
        self.bfdirection = 0
        self.fdirections = { X = 0, Y = 0 }
        self.range = 0
        self.speed = 0
        self.speedd = 0
        self.speedx = 0
        self.speedy = 0
        self.speedds = { X = 0, Y = 0 }
        self.aspeed = 0
        self.aspeedx = 0
        self.aspeedy = 0
        self.aspeedd = 0
        self.aspeedds = { X = 0, Y = 0 }
        self.sonlife = 0
        self.type = 0
        self.wscale = 0
        self.hscale = 0
        self.colorR = 0
        self.colorG = 0
        self.colorB = 0
        self.alpha = 0
        self.head = 0
        self.heads = { X = 0, Y = 0 }
        self.Withspeedd = true
        self.sonspeed = 0
        self.sonspeedd = 0
        self.sonspeedds = { X = 0, Y = 0 }
        self.sonaspeed = 0
        self.sonaspeedd = 0
        self.bsonaspeedd = 0
        self.sonaspeedds = { X = 0, Y = 0 }
        self.xscale = 0
        self.yscale = 0
        self.Mist = false
        self.Dispel = false
        self.Blend = false
        self.Afterimage = false
        self.Outdispel = false
        self.Invincible = false
        self.Cover = false
        self.Rebound = false
        self.Force = false
    end
    ---@type lstg.mbg.Event[]
    self.Parentevents = {}
    ---@type lstg.mbg.Execution[]
    self.Eventsexe = {}
    ---@type lstg.mbg.Event[]
    self.Sonevents = {}
    --
    if not data then
        return
    end
    local function base(v)
        return v.BaseValue
    end
    local function rand(v)
        return v.RandValue
    end
    self.rand = M()
    self._data = data
    --
    self.id = data['ID']
    self.parentid = data['层ID']
    if data['绑定状态'].Parent then
        self.Binding = true
        self.bindid = data['绑定状态'].Parent['ID']
        self.Bindwithspeedd = data['绑定状态'].Relative
        self.Deepbind = data['绑定状态'].Depth
    else
        self.Binding = false
        self.bindid = -1
        self.Bindwithspeedd = false
        self.Deepbind = false
    end
    self.x = base(data['位置坐标'].X)
    self.y = base(data['位置坐标'].Y)
    self.begin = data['生命'].Begin
    self.life = data['生命'].LifeTime
    self.fx = data['发射坐标'].X
    self.fy = data['发射坐标'].Y
    self.r = base(data['半径'])
    self.rdirection = base(data['半径方向'])
    self.rdirections.X = data['半径方向_坐标指定'].X
    self.rdirections.Y = data['半径方向_坐标指定'].Y
    self.tiao = base(data['条数'])
    self.t = base(data['周期'])
    self.fdirection = base(data['发射角度'])
    self.fdirections.X = data['发射角度_坐标指定'].X
    self.fdirections.Y = data['发射角度_坐标指定'].Y
    self.range = base(data['范围'])
    --
    local m = data['发射器运动']
    self.speed = base(m.Motion.Speed)
    self.speedd = base(m.Motion.SpeedDirection)
    self.speedds.X = m.SpeedDirectionPosition.X
    self.speedds.Y = m.SpeedDirectionPosition.Y
    self.aspeed = base(m.Motion.Acceleration)
    self.aspeedd = base(m.Motion.AccelerationDirection)
    self.aspeedds.X = m.AccelerationDirectionPosition.X
    self.aspeedds.Y = m.AccelerationDirectionPosition.Y
    m = nil
    --
    self.sonlife = data['子弹生命']
    self.type = data['子弹类型']
    self.wscale = data['宽比']
    self.hscale = data['高比']
    --
    local c = data['子弹颜色']
    self.colorR = c.R
    self.colorG = c.G
    self.colorB = c.B
    self.alpha = c.A
    --
    self.head = base(data['朝向'])
    self.heads.X = data['朝向_坐标指定'].X
    self.heads.Y = data['朝向_坐标指定'].Y
    self.Withspeedd = data['朝向与速度方向相同']
    --
    local m1 = data['子弹运动']
    self.sonspeed = base(m1.Motion.Speed)
    self.sonspeedd = base(m1.Motion.SpeedDirection)
    self.sonspeedds.X = m1.SpeedDirectionPosition.X
    self.sonspeedds.Y = m1.SpeedDirectionPosition.Y
    self.sonaspeed = base(m1.Motion.Acceleration)
    self.sonaspeedd = base(m1.Motion.AccelerationDirection)
    self.sonaspeedds.X = m1.AccelerationDirectionPosition.X
    self.sonaspeedds.Y = m1.AccelerationDirectionPosition.Y
    m1 = nil
    --
    self.xscale = data['横比']
    self.yscale = data['纵比']
    self.Mist = data['雾化效果']
    self.Dispel = data['消除效果']
    self.Blend = data['高光效果']
    self.Afterimage = data['拖影效果']
    self.Outdispel = data['出屏即消']
    self.Invincible = data['无敌状态']
    --
    local Event = require('game.mbg.Event')
    for i, v in ipairs(data['发射器事件组'] or {}) do
        local e = Event(i - 1)
        e.tag = v.Name
        e.t = v.Interval
        e.addtime = v.IntervalIncrement
        e.events = table.clone(v.Events or {})
        table.insert(self.Parentevents, e)
    end
    for i, v in ipairs(data['子弹事件组'] or {}) do
        local e = Event(i - 1)
        e.tag = v.Name
        e.t = v.Interval
        e.addtime = v.IntervalIncrement
        e.events = table.clone(v.Events or {})
        table.insert(self.Sonevents, e)
    end
    --
    self.rand.fx = rand(data['位置坐标'].X)
    self.rand.fy = rand(data['位置坐标'].Y)
    self.rand.r = rand(data['半径'])
    self.rand.rdirection = rand(data['半径方向'])
    self.rand.tiao = rand(data['条数'])
    self.rand.t = rand(data['周期'])
    self.rand.fdirection = rand(data['发射角度'])
    self.rand.range = rand(data['范围'])
    m = data['发射器运动']
    self.rand.speed = rand(m.Motion.Speed)
    self.rand.speedd = rand(m.Motion.SpeedDirection)
    self.rand.aspeed = rand(m.Motion.Acceleration)
    self.rand.aspeedd = rand(m.Motion.AccelerationDirection)
    self.rand.head = rand(data['朝向'])
    m1 = data['子弹运动']
    self.rand.sonspeed = rand(m1.Motion.Speed)
    self.rand.sonspeedd = rand(m1.Motion.SpeedDirection)
    self.rand.sonaspeed = rand(m1.Motion.Acceleration)
    self.rand.sonaspeedd = rand(m1.Motion.AccelerationDirection)
    --
    self.Cover = data['遮罩']
    self.Rebound = data['反弹板']
    self.Force = data['力场']
end

function M:update()
    local Execution = require('game.mbg.Execution')

    if self.clcount == 1 then
        self.clwait = self.clwait + 1
        if self.clwait > 15 then
            self.clwait = 0
            self.clcount = 0
        end
    end
    local layer = self:getLayer()
    if not Time.Playing then
        self.aspeedx = self.aspeed * Math.Cos(MathHelper.ToRadians(self.aspeedd))
        self.aspeedy = self.aspeed * Math.Sin(MathHelper.ToRadians(self.aspeedd))
        self.speedx = self.speed * Math.Cos(MathHelper.ToRadians(self.speedd))
        self.speedy = self.speed * Math.Sin(MathHelper.ToRadians(self.speedd))
        self.begin = math.floor(MathHelper.Clamp(self.begin, layer.begin, (1 + layer['end'] - layer.begin)))
        self.life = math.floor(MathHelper.Clamp(self.life, 1, (layer['end'] - layer.begin + 2 - self.begin)))
    end
    if self.bindid == self.id then
        self.bindid = -1
        self.Deepbind = false
        self.Bindwithspeedd = false
    end
    if self.bindid ~= -1 and self.bindid >= #layer.BatchArray then
        self.bindid = -1
        self.Deepbind = false
        self.Bindwithspeedd = false
    end
    if Time.Playing then
        if self.Deepbinded then
            self.time = self.time + 1
        end
        local ok = (not self.Deepbinded and Time.now >= self.begin and Time.now <= self.begin + self.life - 1) or (self.Deepbinded and self.time >= self.begin and self.time <= self.begin + self.life - 1) or self.Deepbind
        if not ok then
            return
        end
        if not self.Deepbind and not self.Deepbinded then
            self.time = Time.now - self.begin + 1
        end
        if not self.Deepbind then
            self.speedx = self.speedx + self.aspeedx
            self.speedy = self.speedy + self.aspeedy
            self.x = self.x + self.speedx
            self.y = self.y + self.speedy
            self.fx = self.fx + self.speedx
            self.fy = self.fy + self.speedy
            if self.Deepbinded then
                self.conditions[0] = (self.time - self.begin + 1)
            else
                self.conditions[0] = self.time
            end
            self.conditions[1] = self.fx
            self.conditions[2] = self.fy
            self.conditions[3] = self.r
            self.conditions[4] = self.rdirection
            self.conditions[5] = self.tiao
            self.conditions[6] = self.t
            self.conditions[7] = self.fdirection
            self.conditions[8] = self.range
            self.conditions[9] = self.wscale
            self.conditions[10] = self.hscale
            self.conditions[11] = self.alpha
            self.conditions[12] = self.head
            self.results[0] = self.fx
            self.results[1] = self.fy
            self.results[2] = self.r
            self.results[3] = self.rdirection
            self.results[4] = self.tiao
            self.results[5] = self.t
            self.results[6] = self.fdirection
            self.results[7] = self.range
            self.results[8] = self.speed
            self.results[9] = self.speedd
            self.results[10] = self.aspeed
            self.results[11] = self.aspeedd
            self.results[12] = self.life
            self.results[13] = self.type
            self.results[14] = self.wscale
            self.results[15] = self.hscale
            self.results[16] = self.colorR
            self.results[17] = self.colorG
            self.results[18] = self.colorB
            self.results[19] = self.alpha
            self.results[20] = self.head
            self.results[21] = self.sonspeed
            self.results[22] = self.sonspeedd
            self.results[23] = self.sonaspeed
            self.results[24] = self.sonaspeedd
            self.results[25] = self.xscale
            self.results[26] = self.yscale
            self.results[27] = 0
            self.results[28] = 0
            self.results[29] = 0
            self.results[30] = 0
            self.results[31] = 0
            self.results[32] = 0
            for _, event3 in ipairs(self.Parentevents) do
                if event3.t <= 0 then
                    event3.t = 1
                end
                if self.time % event3.t == 0 then
                    event3.loop = event3.loop + 1
                end
                for _, eventRead in ipairs(event3.results) do
                    repeat
                        if (eventRead.special == 3) then
                            if (eventRead.changevalue == 0) then
                                eventRead.res = self.x - 4
                            end
                            if (eventRead.changevalue == 1) then
                                eventRead.res = self.y + 16
                            end
                            if (eventRead.changevalue == 6) then
                                eventRead.res = MathHelper.ToDegrees(Main.Twopointangle(self.x - 4, self.y + 16, self.fx, self.fy))
                            end
                            if (eventRead.changevalue == 24) then
                                eventRead.res = MathHelper.ToDegrees(Main.Twopointangle(self.x - 4, self.y + 16, self.fx, self.fy))
                            end
                        end
                        if (eventRead.special == 4) then
                            if (eventRead.changevalue == 0) then
                                eventRead.res = Player.position.X
                            end
                            if (eventRead.changevalue == 1) then
                                eventRead.res = Player.position.Y
                            end
                            if (eventRead.changevalue == 3) then
                                eventRead.res = MathHelper.ToDegrees(Main.Twopointangle(Player.position.X, Player.position.Y, self.fx, self.fy))
                            end
                            if (eventRead.changevalue == 6) then
                                eventRead.res = MathHelper.ToDegrees(Main.Twopointangle(Player.position.X, Player.position.Y, self.fx, self.fy))
                            end
                            if (eventRead.changevalue == 9) then
                                eventRead.res = MathHelper.ToDegrees(Main.Twopointangle(Player.position.X, Player.position.Y, self.fx, self.fy))
                            end
                            if (eventRead.changevalue == 11) then
                                eventRead.res = MathHelper.ToDegrees(Main.Twopointangle(Player.position.X, Player.position.Y, self.fx, self.fy))
                            end
                            if (eventRead.changevalue == 24) then
                                eventRead.res = MathHelper.ToDegrees(Main.Twopointangle(Player.position.X, Player.position.Y, self.fx, self.fy))
                            end
                        end
                        if (eventRead.opreator == ">") then
                            if (eventRead.opreator2 == ">") then
                                if (eventRead.collector == "且") then
                                    if (self.conditions[eventRead.contype] > float.Parse(eventRead.condition) + (event3.loop * event3.addtime) and self.conditions[eventRead.contype2] > float.Parse(eventRead.condition2) + (event3.loop * event3.addtime)) then
                                        if (eventRead.special == 1) then
                                            self:recover()
                                        elseif (eventRead.special == 2) then
                                            self:shoot()
                                        else
                                            local execution = Execution()
                                            if (eventRead.noloop) then
                                                --continue
                                                break
                                            end
                                            if (eventRead.time > 0) then
                                                eventRead.time = eventRead.time - 1
                                                if (eventRead.time == 0) then
                                                    eventRead.noloop = true
                                                end
                                            end
                                            execution.parentid = self.parentid
                                            execution.id = self.id
                                            execution.change = eventRead.change
                                            execution.changetype = eventRead.changetype
                                            execution.changevalue = eventRead.changevalue
                                            if (eventRead.rand ~= 0) then
                                                execution.value = eventRead.res + MathHelper.Lerp(-eventRead.rand, eventRead.rand, Main.rand.NextDouble())
                                            else
                                                execution.value = eventRead.res
                                            end
                                            execution.region = tostring(self.results[eventRead.changename])
                                            execution.time = eventRead.times
                                            execution.ctime = execution.time
                                            table.insert(self.Eventsexe, execution)
                                        end
                                    end
                                elseif (eventRead.collector == "或" and (self.conditions[eventRead.contype] > float.Parse(eventRead.condition) + (event3.loop * event3.addtime) or self.conditions[eventRead.contype2] > float.Parse(eventRead.condition2) + (event3.loop * event3.addtime))) then
                                    if (eventRead.special == 1) then
                                        self:recover()
                                    elseif (eventRead.special == 2) then
                                        self:shoot()
                                    else
                                        local execution2 = Execution()
                                        if (eventRead.noloop) then
                                            break
                                        end
                                        if (eventRead.time > 0) then
                                            eventRead.time = eventRead.time - 1
                                            if (eventRead.time == 0) then
                                                eventRead.noloop = true
                                            end
                                        end
                                        execution2.parentid = self.parentid
                                        execution2.id = self.id
                                        execution2.change = eventRead.change
                                        execution2.changetype = eventRead.changetype
                                        execution2.changevalue = eventRead.changevalue
                                        if (eventRead.rand ~= 0) then
                                            execution2.value = eventRead.res + MathHelper.Lerp(-eventRead.rand, eventRead.rand, Main.rand.NextDouble())
                                        else
                                            execution2.value = eventRead.res
                                        end
                                        execution2.region = tostring(self.results[eventRead.changename])
                                        execution2.time = eventRead.times
                                        execution2.ctime = execution2.time
                                        table.insert(self.Eventsexe, execution2)
                                    end
                                end
                            elseif (eventRead.opreator2 == "=") then
                                if (eventRead.collector == "且") then
                                    if (self.conditions[eventRead.contype] > float.Parse(eventRead.condition) + (event3.loop * event3.addtime) and self.conditions[eventRead.contype2] == float.Parse(eventRead.condition2) + (event3.loop * event3.addtime)) then
                                        if (eventRead.special == 1) then
                                            self:recover()
                                        elseif (eventRead.special == 2) then
                                            self:shoot()
                                        else
                                            local execution3 = Execution()
                                            if (eventRead.noloop) then
                                                break
                                            end
                                            if (eventRead.time > 0) then
                                                eventRead.time = eventRead.time - 1
                                                if (eventRead.time == 0) then
                                                    eventRead.noloop = true
                                                end
                                            end
                                            execution3.parentid = self.parentid
                                            execution3.id = self.id
                                            execution3.change = eventRead.change
                                            execution3.changetype = eventRead.changetype
                                            execution3.changevalue = eventRead.changevalue
                                            if (eventRead.rand ~= 0) then
                                                execution3.value = eventRead.res + MathHelper.Lerp(-eventRead.rand, eventRead.rand, Main.rand.NextDouble())
                                            else
                                                execution3.value = eventRead.res
                                            end
                                            execution3.region = tostring(self.results[eventRead.changename])
                                            execution3.time = eventRead.times
                                            execution3.ctime = execution3.time
                                            table.insert(self.Eventsexe, execution3)
                                        end
                                    end
                                elseif (eventRead.collector == "或" and (self.conditions[eventRead.contype] > float.Parse(eventRead.condition) + (event3.loop * event3.addtime) or self.conditions[eventRead.contype2] == float.Parse(eventRead.condition2) + (event3.loop * event3.addtime))) then
                                    if (eventRead.special == 1) then
                                        self:recover()
                                    elseif (eventRead.special == 2) then
                                        self:shoot()
                                    else
                                        local execution4 = Execution()
                                        if (eventRead.noloop) then
                                            break
                                        end
                                        if (eventRead.time > 0) then
                                            eventRead.time = eventRead.time - 1
                                            if (eventRead.time == 0) then
                                                eventRead.noloop = true
                                            end
                                        end
                                        execution4.parentid = self.parentid
                                        execution4.id = self.id
                                        execution4.change = eventRead.change
                                        execution4.changetype = eventRead.changetype
                                        execution4.changevalue = eventRead.changevalue
                                        if (eventRead.rand ~= 0) then
                                            execution4.value = eventRead.res + MathHelper.Lerp(-eventRead.rand, eventRead.rand, Main.rand.NextDouble())
                                        else
                                            execution4.value = eventRead.res
                                        end
                                        execution4.region = tostring(self.results[eventRead.changename])
                                        execution4.time = eventRead.times
                                        execution4.ctime = execution4.time
                                        table.insert(self.Eventsexe, execution4)
                                    end
                                end
                            elseif (eventRead.opreator2 == "<") then
                                if (eventRead.collector == "且") then
                                    if (self.conditions[eventRead.contype] > float.Parse(eventRead.condition) + (event3.loop * event3.addtime) and self.conditions[eventRead.contype2] < float.Parse(eventRead.condition2) + (event3.loop * event3.addtime)) then
                                        if (eventRead.special == 1) then
                                            self:recover()
                                        elseif (eventRead.special == 2) then
                                            self:shoot()
                                        else
                                            local execution5 = Execution()
                                            if (eventRead.noloop) then
                                                break
                                            end
                                            if (eventRead.time > 0) then
                                                eventRead.time = eventRead.time - 1
                                                if (eventRead.time == 0) then
                                                    eventRead.noloop = true
                                                end
                                            end
                                            execution5.parentid = self.parentid
                                            execution5.id = self.id
                                            execution5.change = eventRead.change
                                            execution5.changetype = eventRead.changetype
                                            execution5.changevalue = eventRead.changevalue
                                            if (eventRead.rand ~= 0) then
                                                execution5.value = eventRead.res + MathHelper.Lerp(-eventRead.rand, eventRead.rand, Main.rand.NextDouble())
                                            else
                                                execution5.value = eventRead.res
                                            end
                                            execution5.region = tostring(self.results[eventRead.changename])
                                            execution5.time = eventRead.times
                                            execution5.ctime = execution5.time
                                            table.insert(self.Eventsexe, execution5)
                                        end
                                    end
                                elseif (eventRead.collector == "或" and (self.conditions[eventRead.contype] > float.Parse(eventRead.condition) + (event3.loop * event3.addtime) or self.conditions[eventRead.contype2] < float.Parse(eventRead.condition2) + (event3.loop * event3.addtime))) then
                                    if (eventRead.special == 1) then
                                        self:recover()
                                    elseif (eventRead.special == 2) then
                                        self:shoot()
                                    else
                                        local execution6 = Execution()
                                        if (eventRead.noloop) then
                                            break
                                        end
                                        if (eventRead.time > 0) then
                                            eventRead.time = eventRead.time - 1
                                            if (eventRead.time == 0) then
                                                eventRead.noloop = true
                                            end
                                        end
                                        execution6.parentid = self.parentid
                                        execution6.id = self.id
                                        execution6.change = eventRead.change
                                        execution6.changetype = eventRead.changetype
                                        execution6.changevalue = eventRead.changevalue
                                        if (eventRead.rand ~= 0) then
                                            execution6.value = eventRead.res + MathHelper.Lerp(-eventRead.rand, eventRead.rand, Main.rand.NextDouble())
                                        else
                                            execution6.value = eventRead.res
                                        end
                                        execution6.region = tostring(self.results[eventRead.changename])
                                        execution6.time = eventRead.times
                                        execution6.ctime = execution6.time
                                        table.insert(self.Eventsexe, execution6)
                                    end
                                end
                            elseif (self.conditions[eventRead.contype] > float.Parse(eventRead.condition) + (event3.loop * event3.addtime)) then
                                if (eventRead.special == 1) then
                                    self:recover()
                                elseif (eventRead.special == 2) then
                                    self:shoot()
                                else
                                    local execution7 = Execution()
                                    if (eventRead.noloop) then
                                        break
                                    end
                                    if (eventRead.time > 0) then
                                        eventRead.time = eventRead.time - 1
                                        if (eventRead.time == 0) then
                                            eventRead.noloop = true
                                        end
                                    end
                                    execution7.parentid = self.parentid
                                    execution7.id = self.id
                                    execution7.change = eventRead.change
                                    execution7.changetype = eventRead.changetype
                                    execution7.changevalue = eventRead.changevalue
                                    if (eventRead.rand ~= 0) then
                                        execution7.value = eventRead.res + MathHelper.Lerp(-eventRead.rand, eventRead.rand, Main.rand.NextDouble())
                                    else
                                        execution7.value = eventRead.res
                                    end
                                    execution7.region = tostring(self.results[eventRead.changename])
                                    execution7.time = eventRead.times
                                    execution7.ctime = execution7.time
                                    table.insert(self.Eventsexe, execution7)
                                end
                            end
                        end
                        if (eventRead.opreator == "=") then
                            if (eventRead.opreator2 == ">") then
                                if (eventRead.collector == "且") then
                                    if (self.conditions[eventRead.contype] == float.Parse(eventRead.condition) + (event3.loop * event3.addtime) and self.conditions[eventRead.contype2] > float.Parse(eventRead.condition2) + (event3.loop * event3.addtime)) then
                                        if (eventRead.special == 1) then
                                            self:recover()
                                        elseif (eventRead.special == 2) then
                                            self:shoot()
                                        else
                                            local execution8 = Execution()
                                            if (eventRead.noloop) then
                                                break
                                            end
                                            if (eventRead.time > 0) then
                                                eventRead.time = eventRead.time - 1
                                                if (eventRead.time == 0) then
                                                    eventRead.noloop = true
                                                end
                                            end
                                            execution8.parentid = self.parentid
                                            execution8.id = self.id
                                            execution8.change = eventRead.change
                                            execution8.changetype = eventRead.changetype
                                            execution8.changevalue = eventRead.changevalue
                                            if (eventRead.rand ~= 0) then
                                                execution8.value = eventRead.res + MathHelper.Lerp(-eventRead.rand, eventRead.rand, Main.rand.NextDouble())
                                            else
                                                execution8.value = eventRead.res
                                            end
                                            execution8.region = tostring(self.results[eventRead.changename])
                                            execution8.time = eventRead.times
                                            execution8.ctime = execution8.time
                                            table.insert(self.Eventsexe, execution8)
                                        end
                                    end
                                elseif (eventRead.collector == "或" and (self.conditions[eventRead.contype] == float.Parse(eventRead.condition) + (event3.loop * event3.addtime) or self.conditions[eventRead.contype2] > float.Parse(eventRead.condition2) + (event3.loop * event3.addtime))) then
                                    if (eventRead.special == 1) then
                                        self:recover()
                                    elseif (eventRead.special == 2) then
                                        self:shoot()
                                    else
                                        local execution9 = Execution()
                                        if (eventRead.noloop) then
                                            break
                                        end
                                        if (eventRead.time > 0) then
                                            eventRead.time = eventRead.time - 1
                                            if (eventRead.time == 0) then
                                                eventRead.noloop = true
                                            end
                                        end
                                        execution9.parentid = self.parentid
                                        execution9.id = self.id
                                        execution9.change = eventRead.change
                                        execution9.changetype = eventRead.changetype
                                        execution9.changevalue = eventRead.changevalue
                                        if (eventRead.rand ~= 0) then
                                            execution9.value = eventRead.res + MathHelper.Lerp(-eventRead.rand, eventRead.rand, Main.rand.NextDouble())
                                        else
                                            execution9.value = eventRead.res
                                        end
                                        execution9.region = tostring(self.results[eventRead.changename])
                                        execution9.time = eventRead.times
                                        execution9.ctime = execution9.time
                                        table.insert(self.Eventsexe, execution9)
                                    end
                                end
                            elseif (eventRead.opreator2 == "=") then
                                if (eventRead.collector == "且") then
                                    if (self.conditions[eventRead.contype] == float.Parse(eventRead.condition) + (event3.loop * event3.addtime) and self.conditions[eventRead.contype2] == float.Parse(eventRead.condition2) + (event3.loop * event3.addtime)) then
                                        if (eventRead.special == 1) then
                                            self:recover()
                                        elseif (eventRead.special == 2) then
                                            self:shoot()
                                        else
                                            local execution10 = Execution()
                                            if (eventRead.noloop) then
                                                break
                                            end
                                            if (eventRead.time > 0) then
                                                eventRead.time = eventRead.time - 1
                                                if (eventRead.time == 0) then
                                                    eventRead.noloop = true
                                                end
                                            end
                                            execution10.parentid = self.parentid
                                            execution10.id = self.id
                                            execution10.change = eventRead.change
                                            execution10.changetype = eventRead.changetype
                                            execution10.changevalue = eventRead.changevalue
                                            if (eventRead.rand ~= 0) then
                                                execution10.value = eventRead.res + MathHelper.Lerp(-eventRead.rand, eventRead.rand, Main.rand.NextDouble())
                                            else
                                                execution10.value = eventRead.res
                                            end
                                            execution10.region = tostring(self.results[eventRead.changename])
                                            execution10.time = eventRead.times
                                            execution10.ctime = execution10.time
                                            table.insert(self.Eventsexe, execution10)
                                        end
                                    end
                                elseif (eventRead.collector == "或" and (self.conditions[eventRead.contype] == float.Parse(eventRead.condition) + (event3.loop * event3.addtime) or self.conditions[eventRead.contype2] == float.Parse(eventRead.condition2) + (event3.loop * event3.addtime))) then
                                    if (eventRead.special == 1) then
                                        self:recover()
                                    elseif (eventRead.special == 2) then
                                        self:shoot()
                                    else
                                        local execution11 = Execution()
                                        if (eventRead.noloop) then
                                            break
                                        end
                                        if (eventRead.time > 0) then
                                            eventRead.time = eventRead.time - 1
                                            if (eventRead.time == 0) then
                                                eventRead.noloop = true
                                            end
                                        end
                                        execution11.parentid = self.parentid
                                        execution11.id = self.id
                                        execution11.change = eventRead.change
                                        execution11.changetype = eventRead.changetype
                                        execution11.changevalue = eventRead.changevalue
                                        if (eventRead.rand ~= 0) then
                                            execution11.value = eventRead.res + MathHelper.Lerp(-eventRead.rand, eventRead.rand, Main.rand.NextDouble())
                                        else
                                            execution11.value = eventRead.res
                                        end
                                        execution11.region = tostring(self.results[eventRead.changename])
                                        execution11.time = eventRead.times
                                        execution11.ctime = execution11.time
                                        table.insert(self.Eventsexe, execution11)
                                    end
                                end
                            elseif (eventRead.opreator2 == "<") then
                                if (eventRead.collector == "且") then
                                    if (self.conditions[eventRead.contype] == float.Parse(eventRead.condition) + (event3.loop * event3.addtime) and self.conditions[eventRead.contype2] < float.Parse(eventRead.condition2) + (event3.loop * event3.addtime)) then
                                        if (eventRead.special == 1) then
                                            self:recover()
                                        elseif (eventRead.special == 2) then
                                            self:shoot()
                                        else
                                            local execution12 = Execution()
                                            if (eventRead.noloop) then
                                                break
                                            end
                                            if (eventRead.time > 0) then
                                                eventRead.time = eventRead.time - 1
                                                if (eventRead.time == 0) then
                                                    eventRead.noloop = true
                                                end
                                            end
                                            execution12.parentid = self.parentid
                                            execution12.id = self.id
                                            execution12.change = eventRead.change
                                            execution12.changetype = eventRead.changetype
                                            execution12.changevalue = eventRead.changevalue
                                            if (eventRead.rand ~= 0) then
                                                execution12.value = eventRead.res + MathHelper.Lerp(-eventRead.rand, eventRead.rand, Main.rand.NextDouble())
                                            else
                                                execution12.value = eventRead.res
                                            end
                                            execution12.region = tostring(self.results[eventRead.changename])
                                            execution12.time = eventRead.times
                                            execution12.ctime = execution12.time
                                            table.insert(self.Eventsexe, execution12)
                                        end
                                    end
                                elseif (eventRead.collector == "或" and (self.conditions[eventRead.contype] == float.Parse(eventRead.condition) + (event3.loop * event3.addtime) or self.conditions[eventRead.contype2] < float.Parse(eventRead.condition2) + (event3.loop * event3.addtime))) then
                                    if (eventRead.special == 1) then
                                        self:recover()
                                    elseif (eventRead.special == 2) then
                                        self:shoot()
                                    else
                                        local execution13 = Execution()
                                        if (eventRead.noloop) then
                                            break
                                        end
                                        if (eventRead.time > 0) then
                                            eventRead.time = eventRead.time - 1
                                            if (eventRead.time == 0) then
                                                eventRead.noloop = true
                                            end
                                        end
                                        execution13.parentid = self.parentid
                                        execution13.id = self.id
                                        execution13.change = eventRead.change
                                        execution13.changetype = eventRead.changetype
                                        execution13.changevalue = eventRead.changevalue
                                        if (eventRead.rand ~= 0) then
                                            execution13.value = eventRead.res + MathHelper.Lerp(-eventRead.rand, eventRead.rand, Main.rand.NextDouble())
                                        else
                                            execution13.value = eventRead.res
                                        end
                                        execution13.region = tostring(self.results[eventRead.changename])
                                        execution13.time = eventRead.times
                                        execution13.ctime = execution13.time
                                        table.insert(self.Eventsexe, execution13)
                                    end
                                end
                            elseif (self.conditions[eventRead.contype] == float.Parse(eventRead.condition) + (event3.loop * event3.addtime)) then
                                if (eventRead.special == 1) then
                                    self:recover()
                                elseif (eventRead.special == 2) then
                                    self:shoot()
                                else
                                    local execution14 = Execution()
                                    if (eventRead.noloop) then
                                        break
                                    end
                                    if (eventRead.time > 0) then
                                        eventRead.time = eventRead.time - 1
                                        if (eventRead.time == 0) then
                                            eventRead.noloop = true
                                        end
                                    end
                                    execution14.parentid = self.parentid
                                    execution14.id = self.id
                                    execution14.change = eventRead.change
                                    execution14.changetype = eventRead.changetype
                                    execution14.changevalue = eventRead.changevalue
                                    if (eventRead.rand ~= 0) then
                                        execution14.value = eventRead.res + MathHelper.Lerp(-eventRead.rand, eventRead.rand, Main.rand.NextDouble())
                                    else
                                        execution14.value = eventRead.res
                                    end
                                    execution14.region = tostring(self.results[eventRead.changename])
                                    execution14.time = eventRead.times
                                    execution14.ctime = execution14.time
                                    table.insert(self.Eventsexe, execution14)
                                end
                            end
                        end
                        if (eventRead.opreator == "<") then
                            if (eventRead.opreator2 == ">") then
                                if (eventRead.collector == "且") then
                                    if (self.conditions[eventRead.contype] < float.Parse(eventRead.condition) + (event3.loop * event3.addtime) and self.conditions[eventRead.contype2] > float.Parse(eventRead.condition2) + (event3.loop * event3.addtime)) then
                                        if (eventRead.special == 1) then
                                            self:recover()
                                        elseif (eventRead.special == 2) then
                                            self:shoot()
                                        else
                                            local execution15 = Execution()
                                            if (not eventRead.noloop) then
                                                if (eventRead.time > 0) then
                                                    eventRead.time = eventRead.time - 1
                                                    if (eventRead.time == 0) then
                                                        eventRead.noloop = true
                                                    end
                                                end
                                                execution15.parentid = self.parentid
                                                execution15.id = self.id
                                                execution15.change = eventRead.change
                                                execution15.changetype = eventRead.changetype
                                                execution15.changevalue = eventRead.changevalue
                                                if (eventRead.rand ~= 0) then
                                                    execution15.value = eventRead.res + MathHelper.Lerp(-eventRead.rand, eventRead.rand, Main.rand.NextDouble())
                                                else
                                                    execution15.value = eventRead.res
                                                end
                                                execution15.region = tostring(self.results[eventRead.changename])
                                                execution15.time = eventRead.times
                                                execution15.ctime = execution15.time
                                                table.insert(self.Eventsexe, execution15)
                                            end
                                        end
                                    end
                                elseif (eventRead.collector == "或" and (self.conditions[eventRead.contype] < float.Parse(eventRead.condition) + (event3.loop * event3.addtime) or self.conditions[eventRead.contype2] > float.Parse(eventRead.condition2) + (event3.loop * event3.addtime))) then
                                    if (eventRead.special == 1) then
                                        self:recover()
                                    elseif (eventRead.special == 2) then
                                        self:shoot()
                                    else
                                        local execution16 = Execution()
                                        if (not eventRead.noloop) then
                                            if (eventRead.time > 0) then
                                                eventRead.time = eventRead.time - 1
                                                if (eventRead.time == 0) then
                                                    eventRead.noloop = true
                                                end
                                            end
                                            execution16.parentid = self.parentid
                                            execution16.id = self.id
                                            execution16.change = eventRead.change
                                            execution16.changetype = eventRead.changetype
                                            execution16.changevalue = eventRead.changevalue
                                            if (eventRead.rand ~= 0) then
                                                execution16.value = eventRead.res + MathHelper.Lerp(-eventRead.rand, eventRead.rand, Main.rand.NextDouble())
                                            else
                                                execution16.value = eventRead.res
                                            end
                                            execution16.region = tostring(self.results[eventRead.changename])
                                            execution16.time = eventRead.times
                                            execution16.ctime = execution16.time
                                            table.insert(self.Eventsexe, execution16)
                                        end
                                    end
                                end
                            elseif (eventRead.opreator2 == "=") then
                                if (eventRead.collector == "且") then
                                    if (self.conditions[eventRead.contype] < float.Parse(eventRead.condition) + (event3.loop * event3.addtime) and self.conditions[eventRead.contype2] == float.Parse(eventRead.condition2) + (event3.loop * event3.addtime)) then
                                        if (eventRead.special == 1) then
                                            self:recover()
                                        elseif (eventRead.special == 2) then
                                            self:shoot()
                                        else
                                            local execution17 = Execution()
                                            if (not eventRead.noloop) then
                                                if (eventRead.time > 0) then
                                                    eventRead.time = eventRead.time - 1
                                                    if (eventRead.time == 0) then
                                                        eventRead.noloop = true
                                                    end
                                                end
                                                execution17.parentid = self.parentid
                                                execution17.id = self.id
                                                execution17.change = eventRead.change
                                                execution17.changetype = eventRead.changetype
                                                execution17.changevalue = eventRead.changevalue
                                                if (eventRead.rand ~= 0) then
                                                    execution17.value = eventRead.res + MathHelper.Lerp(-eventRead.rand, eventRead.rand, Main.rand.NextDouble())
                                                else
                                                    execution17.value = eventRead.res
                                                end
                                                execution17.region = tostring(self.results[eventRead.changename])
                                                execution17.time = eventRead.times
                                                execution17.ctime = execution17.time
                                                table.insert(self.Eventsexe, execution17)
                                            end
                                        end
                                    end
                                elseif (eventRead.collector == "或" and (self.conditions[eventRead.contype] < float.Parse(eventRead.condition) + (event3.loop * event3.addtime) or self.conditions[eventRead.contype2] == float.Parse(eventRead.condition2) + (event3.loop * event3.addtime))) then
                                    if (eventRead.special == 1) then
                                        self:recover()
                                    elseif (eventRead.special == 2) then
                                        self:shoot()
                                    else
                                        local execution18 = Execution()
                                        if (not eventRead.noloop) then
                                            if (eventRead.time > 0) then
                                                eventRead.time = eventRead.time - 1
                                                if (eventRead.time == 0) then
                                                    eventRead.noloop = true
                                                end
                                            end
                                            execution18.parentid = self.parentid
                                            execution18.id = self.id
                                            execution18.change = eventRead.change
                                            execution18.changetype = eventRead.changetype
                                            execution18.changevalue = eventRead.changevalue
                                            if (eventRead.rand ~= 0) then
                                                execution18.value = eventRead.res + MathHelper.Lerp(-eventRead.rand, eventRead.rand, Main.rand.NextDouble())
                                            else
                                                execution18.value = eventRead.res
                                            end
                                            execution18.region = tostring(self.results[eventRead.changename])
                                            execution18.time = eventRead.times
                                            execution18.ctime = execution18.time
                                            table.insert(self.Eventsexe, execution18)
                                        end
                                    end
                                end
                            elseif (eventRead.opreator2 == "<") then
                                if (eventRead.collector == "且") then
                                    if (self.conditions[eventRead.contype] < float.Parse(eventRead.condition) + (event3.loop * event3.addtime) and self.conditions[eventRead.contype2] < float.Parse(eventRead.condition2) + (event3.loop * event3.addtime)) then
                                        if (eventRead.special == 1) then
                                            self:recover()
                                        elseif (eventRead.special == 2) then
                                            self:shoot()
                                        else
                                            local execution19 = Execution()
                                            if (not eventRead.noloop) then
                                                if (eventRead.time > 0) then
                                                    eventRead.time = eventRead.time - 1
                                                    if (eventRead.time == 0) then
                                                        eventRead.noloop = true
                                                    end
                                                end
                                                execution19.parentid = self.parentid
                                                execution19.id = self.id
                                                execution19.change = eventRead.change
                                                execution19.changetype = eventRead.changetype
                                                execution19.changevalue = eventRead.changevalue
                                                if (eventRead.rand ~= 0) then
                                                    execution19.value = eventRead.res + MathHelper.Lerp(-eventRead.rand, eventRead.rand, Main.rand.NextDouble())
                                                else
                                                    execution19.value = eventRead.res
                                                end
                                                execution19.region = tostring(self.results[eventRead.changename])
                                                execution19.time = eventRead.times
                                                execution19.ctime = execution19.time
                                                table.insert(self.Eventsexe, execution19)
                                            end
                                        end
                                    end
                                elseif (eventRead.collector == "或" and (self.conditions[eventRead.contype] < float.Parse(eventRead.condition) + (event3.loop * event3.addtime) or self.conditions[eventRead.contype2] < float.Parse(eventRead.condition2) + (event3.loop * event3.addtime))) then
                                    if (eventRead.special == 1) then
                                        self:recover()
                                    elseif (eventRead.special == 2) then
                                        self:shoot()
                                    else
                                        local execution20 = Execution()
                                        if (not eventRead.noloop) then
                                            if (eventRead.time > 0) then
                                                eventRead.time = eventRead.time - 1
                                                if (eventRead.time == 0) then
                                                    eventRead.noloop = true
                                                end
                                            end
                                            execution20.parentid = self.parentid
                                            execution20.id = self.id
                                            execution20.change = eventRead.change
                                            execution20.changetype = eventRead.changetype
                                            execution20.changevalue = eventRead.changevalue
                                            if (eventRead.rand ~= 0) then
                                                execution20.value = eventRead.res + MathHelper.Lerp(-eventRead.rand, eventRead.rand, Main.rand.NextDouble())
                                            else
                                                execution20.value = eventRead.res
                                            end
                                            execution20.region = tostring(self.results[eventRead.changename])
                                            execution20.time = eventRead.times
                                            execution20.ctime = execution20.time
                                            table.insert(self.Eventsexe, execution20)
                                        end
                                    end
                                end
                            elseif (self.conditions[eventRead.contype] < float.Parse(eventRead.condition) + (event3.loop * event3.addtime)) then
                                if (eventRead.special == 1) then
                                    self:recover()
                                elseif (eventRead.special == 2) then
                                    self:shoot()
                                else
                                    local execution21 = Execution()
                                    if (not eventRead.noloop) then
                                        if (eventRead.time > 0) then
                                            eventRead.time = eventRead.time - 1
                                            if (eventRead.time == 0) then
                                                eventRead.noloop = true
                                            end
                                        end
                                        execution21.parentid = self.parentid
                                        execution21.id = self.id
                                        execution21.change = eventRead.change
                                        execution21.changetype = eventRead.changetype
                                        execution21.changevalue = eventRead.changevalue
                                        if (eventRead.rand ~= 0) then
                                            execution21.value = eventRead.res + MathHelper.Lerp(-eventRead.rand, eventRead.rand, Main.rand.NextDouble())
                                        else
                                            execution21.value = eventRead.res
                                        end
                                        execution21.region = tostring(self.results[eventRead.changename])
                                        execution21.time = eventRead.times
                                        execution21.ctime = execution21.time
                                        table.insert(self.Eventsexe, execution21)
                                    end
                                end
                            end
                        end
                    until true
                end
            end
            local Eventsexe = {}
            for _, e in ipairs(self.Eventsexe) do
                if not e.NeedDelete then
                    e:update(self)
                    table.insert(Eventsexe, e)
                end
            end
            self.Eventsexe = Eventsexe
        end
        if self.t > 0 then
            if (self.Deepbind) then
                self:shoot()
                return
            end
            if (self.time % self.t + math.floor(MathHelper.Lerp((-self.rand.t), self.rand.t, Main.rand.NextDouble())) == 0) then
                self:shoot()
            end
        end
    end
end

function M:getLayer()
    local Layer = require('game.mbg.Layer')
    return Layer.LayerArray[self.parentid + 1]
end

function M:shoot()
    local Barrage = require('game.mbg.Barrage')
    local Event = require('game.mbg.Event')

    local num = self.tiao + math.floor(MathHelper.Lerp((-self.rand.tiao), self.rand.tiao, Main.rand.NextDouble()))
    local num2 = math.floor(MathHelper.Lerp(-self.rand.fx, self.rand.fx, Main.rand.NextDouble()))
    local num3 = math.floor(MathHelper.Lerp(-self.rand.fy, self.rand.fy, Main.rand.NextDouble()))
    local num4 = math.floor(MathHelper.Lerp(-self.rand.r, self.rand.r, Main.rand.NextDouble()))
    local num5 = MathHelper.Lerp(-self.rand.rdirection, self.rand.rdirection, Main.rand.NextDouble())
    local num6 = math.floor(MathHelper.Lerp(-self.rand.head, self.rand.head, Main.rand.NextDouble()))
    local num7 = math.floor(MathHelper.Lerp((-self.rand.range), self.rand.range, Main.rand.NextDouble()))
    local num8 = MathHelper.Lerp(-self.rand.sonspeed, self.rand.sonspeed, Main.rand.NextDouble())
    local randfdirection = MathHelper.Lerp(-self.rand.fdirection, self.rand.fdirection, Main.rand.NextDouble())
    local num9 = MathHelper.Lerp(-self.rand.sonaspeed, self.rand.sonaspeed, Main.rand.NextDouble())
    local randsonaspeedd = MathHelper.Lerp(-self.rand.sonaspeedd, self.rand.sonaspeedd, Main.rand.NextDouble())
    local val = MathHelper.Lerp(-self.rand.wscale, self.rand.wscale, Main.rand.NextDouble())
    local val2 = MathHelper.Lerp(-self.rand.hscale, self.rand.hscale, Main.rand.NextDouble())
    if self.bindid == -1 then
        for i = 0, num - 1 do
            local barrage = Barrage()
            if self:getLayer().BatchArray[self.id + 1].rdirection == -99999 then
                self.rdirection = MathHelper.ToDegrees(Main.Twopointangle(Player.position.X, Player.position.Y, self.fx, self.fy))
            end
            local degrees = self.rdirection + (i - (num - 1) / 2) * (self.range + num7) / num + num5
            barrage.x = self.fx + (self.r + num4) * Math.Cos(MathHelper.ToRadians(degrees)) + num2 + Center.ox - Center.x
            barrage.y = self.fy + (self.r + num4) * Math.Sin(MathHelper.ToRadians(degrees)) + num3 + Center.oy - Center.y
            barrage.life = self.sonlife
            barrage.type = math.floor(self.type) - 1
            barrage.wscale = self.wscale + Math.Max(val, val2)
            barrage.hscale = self.hscale + Math.Max(val, val2)
            barrage.head = self.head + num6
            barrage.alpha = self.alpha
            barrage.R = self.colorR
            barrage.G = self.colorG
            barrage.B = self.colorB
            barrage.speed = self.sonspeed + num8
            barrage.aspeed = self.sonaspeed + num9
            barrage.fx = self.x - 4
            barrage.fy = self.y + 16
            if self.bfdirection >= -99997 then
                barrage.fdirection = self.fdirection
            else
                barrage.fdirection = self.bfdirection
            end
            barrage.fdirections = self.fdirections
            barrage.randfdirection = randfdirection
            barrage.g = i
            barrage.tiaos = num
            barrage.range = self.range
            barrage.randrange = num7
            if self.bsonaspeedd >= -99997 then
                barrage.sonaspeedd = self.sonaspeedd
            else
                barrage.sonaspeedd = self.bsonaspeedd
            end
            barrage.sonaspeedds = self.sonaspeedds
            barrage.randsonaspeedd = randsonaspeedd
            barrage.Withspeedd = self.Withspeedd
            barrage.xscale = self.xscale
            barrage.yscale = self.yscale
            barrage.Mist = self.Mist
            barrage.Dispel = self.Dispel
            barrage.Blend = self.Blend
            barrage.Outdispel = self.Outdispel
            barrage.Afterimage = self.Afterimage
            barrage.Invincible = self.Invincible
            barrage.Cover = self.Cover
            barrage.Rebound = self.Rebound
            barrage.Force = self.Force
            for j = 1, #self.Sonevents do
                local e = self.Sonevents[j]
                local event = Event(j - 1)
                event.t = e.t
                event.addtime = e.addtime
                event.events = e.events
                for _, r in ipairs(e.results) do
                    table.insert(event.results, r:copy())
                end
                event.index = e.index
                table.insert(barrage.Events, event)
            end
            barrage.parentid = self.id
            table.insert(self:getLayer().Barrages, barrage)
        end
    end
    local layer = self:getLayer()
    for l = 1, #layer.Barrages do
        local ba = layer.Barrages[l]
        if (not ba.IsLase and ba.parentid == self.bindid and (ba.time > 15 or not ba.Mist) and not ba.NeedDelete) then
            if (self.Deepbind) then
                if (ba.batch) then
                    ba.batch.x = ba.x
                    ba.batch.y = ba.y
                    ba.batch.fx = ba.x
                    ba.batch.fy = ba.y
                    ba.batch:update()
                else
                    ba.batch = self:bindClone()
                    ba.batch.Deepbind = false
                    ba.batch.Deepbinded = true
                    ba.batch.bindid = -1
                    ba.batch.time = 0
                    if (self.Bindwithspeedd) then
                        ba.batch.fdirection = ba.batch.fdirection + ba.fdirection
                    end
                    ba.batch.Bindwithspeedd = false
                end
            else
                for m = 1, num do
                    local barrage2 = Barrage()
                    if (layer.BatchArray[self.id + 1].rdirection == -99999) then
                        self.rdirection = MathHelper.ToDegrees(Main.Twopointangle(Player.position.X, Player.position.Y, ba.x, ba.y))
                    end
                    local degrees2 = self.rdirection + (m - (num - 1) / 2) * (self.range + num7) / num + num5
                    barrage2.x = ba.x + (self.r + num4) * Math.Cos(MathHelper.ToRadians(degrees2)) + num2
                    barrage2.y = ba.y + (self.r + num4) * Math.Sin(MathHelper.ToRadians(degrees2)) + num3
                    barrage2.life = self.sonlife
                    barrage2.type = math.floor(self.type) - 1
                    barrage2.wscale = self.wscale + Math.Max(val, val2)
                    barrage2.hscale = self.hscale + Math.Max(val, val2)
                    if (layer.BatchArray[self.id + 1].head == -100000) then
                        self.head = MathHelper.ToDegrees(Main.Twopointangle(self.heads.X, self.heads.Y, barrage2.x, barrage2.y))
                    end
                    barrage2.head = self.head + num6
                    barrage2.alpha = self.alpha
                    barrage2.R = self.colorR
                    barrage2.G = self.colorG
                    barrage2.B = self.colorB
                    barrage2.speed = self.sonspeed + num8
                    barrage2.aspeed = self.sonaspeed + num9
                    barrage2.fx = self.x - 4
                    barrage2.fy = self.y + 16
                    if (self.bfdirection >= -99997) then
                        barrage2.fdirection = self.fdirection
                    else
                        barrage2.fdirection = self.bfdirection
                    end
                    barrage2.bindspeedd = ba.speedd
                    barrage2.Bindwithspeedd = self.Bindwithspeedd
                    barrage2.fdirections = self.fdirections
                    barrage2.randfdirection = randfdirection
                    barrage2.g = m
                    barrage2.tiaos = num
                    barrage2.range = self.range
                    barrage2.randrange = num7
                    if (self.bsonaspeedd >= -99997) then
                        barrage2.sonaspeedd = self.sonaspeedd
                    else
                        barrage2.sonaspeedd = self.bsonaspeedd
                    end
                    barrage2.sonaspeedds = self.sonaspeedds
                    barrage2.randsonaspeedd = randsonaspeedd
                    barrage2.Withspeedd = self.Withspeedd
                    barrage2.xscale = self.xscale
                    barrage2.yscale = self.yscale
                    barrage2.Mist = self.Mist
                    barrage2.Dispel = self.Dispel
                    barrage2.Blend = self.Blend
                    barrage2.Outdispel = self.Outdispel
                    barrage2.Afterimage = self.Afterimage
                    barrage2.Invincible = self.Invincible
                    barrage2.Cover = self.Cover
                    barrage2.Rebound = self.Rebound
                    barrage2.Force = self.Force
                    for n = 1, #self.Sonevents do
                        local e = self.Sonevents[n]
                        local event2 = Event(n - 1)
                        event2.t = e.t
                        event2.addtime = e.addtime
                        event2.events = e.events
                        for _, r in ipairs(e.results) do
                            table.insert(event2.results, r:copy())
                        end
                        event2.index = e.index
                        table.insert(barrage2.Events, event2)
                    end
                    barrage2.parentid = self.id
                    table.insert(layer.Barrages, barrage2)
                end
            end
        end
    end
end

function M:bindClone()
    local batch = self:copy()
    batch.Parentevents = {}
    for _, e in ipairs(self.Parentevents) do
        table.insert(batch.Parentevents, e:clone())
    end
    batch.Eventsexe = {}
    for _, e in ipairs(self.Eventsexe) do
        table.insert(batch.Eventsexe, e:clone())
    end
    batch.Sonevents = {}
    for _, e in ipairs(self.Sonevents) do
        table.insert(batch.Sonevents, e:clone())
    end
    return batch
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

function M:recover()
    local b = self:getLayer().BatchArray[self.id + 1]
    self.x = b.x
    self.y = b.y
    self.parentcolor = b.parentcolor
    self.begin = b.begin
    self.life = b.life
    self.fx = b.fx
    self.fy = b.fy
    self.r = b.r
    self.rdirection = b.rdirection
    self.tiao = b.tiao
    self.t = b.t
    self.fdirection = b.fdirection
    self.range = b.range
    self.speed = b.speed
    self.speedd = b.speedd
    self.aspeed = b.aspeed
    self.aspeedd = b.aspeedd
    self.sonlife = b.sonlife
    self.type = b.type
    self.wscale = b.wscale
    self.hscale = b.hscale
    self.colorR = b.colorR
    self.colorG = b.colorG
    self.colorB = b.colorB
    self.alpha = b.alpha
    self.head = b.head
    self.Withspeedd = b.Withspeedd
    self.sonspeed = b.sonspeed
    self.sonspeedd = b.sonspeedd
    self.sonaspeed = b.sonaspeed
    self.sonaspeedd = b.sonaspeedd
    self.xscale = b.xscale
    self.yscale = b.yscale
    self.Mist = b.Mist
    self.Dispel = b.Dispel
    self.Blend = b.Blend
    self.Afterimage = b.Afterimage
    self.Outdispel = b.Outdispel
    self.Invincible = b.Invincible
end

return M
