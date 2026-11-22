---
--- base.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---


require('game.player.common')

---
---@class Player:THlib.player_class
local Player = Class(object)

function Player:init(params)
    table.deploy(self, params, {
        hspeed       = 4,
        lspeed       = 2,
        A            = 0, --|自机判定大小
        B            = 0, --|
        collect_line = 96,
        t_death      = { 100, 90, 84, 50 },
    })
    self.y = -176
    self.group = GROUP_PLAYER
    self.layer = LAYER_PLAYER
    self.slow = 0
    self.lr = 1
    self.lh = 0
    self.fire = 0
    self.lock = false
    self.dialog = false---是否处于对话状态
    self.nextshoot = 0
    self.nextspell = 0
    self.last_move = 0
    --self.nextcollect=0--HZC收点系统
    self.death = 0---miss之后的计时器，100->0
    self.protect = 120
    lstg.player = self
    player = self
    self.grazer = New(grazer)
    if not lstg.var.init_player_data then
        error('Player data has not been initialized.')
    end
    --self.support = int(lstg.var.power / 100)--子机数量
    self.sp = {}
    self.time_stop = false

    self.move = {}
    self.move.dx = 0
    self.move.dy = 0

    self.alpha = 1
    self.imgs = params.imgs or {
        hs = { idle = {}, left = {} },
        ls = { idle = {}, left = {} }
    }
    self.lr_minH = -#self.imgs.hs.left
    self.lr_maxH = -self.lr_minH
    if self.imgs.hs.right then
        self.lr_maxH = #self.imgs.hs.right
    end
    if not self.imgs.hs.left_idle then
        self.imgs.hs.left_idle = { self.imgs.hs.left[#self.imgs.hs.left] }
    end
    if self.imgs.ls then
        self.lr_minL = -#self.imgs.ls.left
        self.lr_maxL = -self.lr_minH
        if self.imgs.ls.right then
            self.lr_maxH = #self.imgs.ls.right
        end
        if not self.imgs.ls.left_idle then
            self.imgs.ls.left_idle = { self.imgs.ls.left[#self.imgs.ls.left] }
        end
    end

    self.ani_itv = params.ani_itv or 6
    self._ani = 0
    self.idle_itv = params.idle_itv or 6
    self._idle = 1

    self._idleH = 1
    self._idleL = 1
    self._idleHL = 1
    self._idleLL = 1
    self._idleHR = 1
    self._idleLR = 1

    --self.findtarget   = Player.findtarget
    --self.make_move    = Player.make_move
    --self._shoot_spell = Player._shoot_spell
    --self.calc_img     = Player.calc_img
    --self.get_img      = Player.get_img
    --for _, v in ipairs({ 'Shoot', 'Spell', 'Special', 'Miss' }) do
    --    self[v] = self.class[v] or Player[v]
    --end
    table.supplement(self, self.class)
    table.supplement(self, Player)
end

function Player:frame()
    --find target
    if ((not IsValid(self.target)) or (not self.target.colli)) then
        self:findtarget()
    end
    if not KeyIsDown 'shoot' then
        self.target = nil
    end
    --
    self.move.dx = 0
    self.move.dy = 0
    if (self.death == 0 or self.death > self.t_death[2]) and (not self.lock) and not (self.time_stop) then
        if KeyIsDown 'slow' then
            self.slow = 1
        else
            self.slow = 0
        end
        self:shoot_spell()
        if self.death == 0 and not self.lock then
            --UpdateInput()
            self:make_move()
        end
        self:calc_fire()
        self:attract()
    elseif self.death == self.t_death[2] then
        if self.time_stop then
            --不受时停影响
            self.death = self.death - 1
        end
        self:Miss()
        self:miss_eff()
    elseif self.death == self.t_death[3] then
        if self.time_stop then
            self.death = self.death - 1
        end
        self.hide = true
    elseif self.death == self.t_death[4] then
        if self.time_stop then
            self.death = self.death - 1
        end
        self.x = 0
        self.y = -236
        self.hide = false
        New(bullet_deleter, self.x, self.y)--消弹
    elseif self.death < self.t_death[4] and not (self.lock) and not (self.time_stop) then
        --此处没有self.death-1，会被时停影响
        self.y = -176 - 1.2 * self.death--从下向上出现
    end
    --img
    --加上time_stop的限制来实现图像时停
    if not (self.time_stop) then
        --设置判定（碰撞盒大小）
        self.a = self.A
        self.b = self.B
        self:calc_slow()
        self:calc_img()
        self:_timer()
        lstg.var.pointrate = item.PointRateFunc(lstg.var)
    end
    ---time_stop
    if self.time_stop then
        self.timer = self.timer - 1
    end
end

local _c_blue = Color(0xFF0000FF)

function Player:render()
    --闪烁蓝色
    --TODO
    if self.imgH then
        if self.protect % 3 == 1 then
            SetImageState(self.imgH, '', _c_blue)
        else
            SetImageState(self.imgH, '', Color(255 * self.alphaH, 255, 255, 255))
        end
        Render(self.imgH, self.x, self.y, 0, self._hscale, 1)
    end
    if self.imgL then
        if self.protect % 3 == 1 then
            SetImageState(self.imgL, '', _c_blue)
        else
            SetImageState(self.imgL, '', Color(255 * self.alphaL, 255, 255, 255))
        end
        Render(self.imgL, self.x, self.y, 0, self._hscale, 1)
    end
end

function Player:colli(other)
    if self.death == 0 and not self.dialog and not cheat then
        if self.protect == 0 then
            --miss
            PlaySound('pldead00', 0.5)
            self.death = self.t_death[1]
        end
        if other.group == GROUP_ENEMY_BULLET then
            Del(other)
        end
    end
end
---追踪功能，以最接近垂直方向的敌人作为目标
function Player:findtarget()
    self.target = nil
    local maxpri = -1
    for i, o in ObjList(GROUP_ENEMY) do
        if o.colli then
            local dx = self.x - o.x
            local dy = self.y - o.y
            local pri = abs(dy) / (abs(dx) + 0.01)
            if pri > maxpri then
                maxpri = pri
                self.target = o
            end
        end
    end
end
--TODO 性能
---根据方向键移动自机
function Player:make_move()
    local v = self.hspeed
    if self.slowlock then
        self.slow = 1
    end
    if self.slow == 1 then
        v = self.lspeed
    end
    if KeyIsDown 'up' then
        self.move.dy = self.move.dy + 1
    end
    if KeyIsDown 'down' then
        self.move.dy = self.move.dy - 1
    end
    if KeyIsDown 'left' then
        self.move.dx = self.move.dx - 1
    end
    if KeyIsDown 'right' then
        self.move.dx = self.move.dx + 1
    end
    if self.move.dx * self.move.dy ~= 0 then
        v = v * SQRT2_2--斜向移动时除以根号2
        self.last_move = self.timer
    end
    self.x = self.x + v * self.move.dx
    self.y = self.y + v * self.move.dy
    --限位
    self.x = math.max(math.min(self.x, lstg.world.pr - 8), lstg.world.pl + 8)
    self.y = math.max(math.min(self.y, lstg.world.pt - 32), lstg.world.pb + 16)
end

function Player:calc_fire()
    if KeyIsDown 'shoot' and not self.dialog then
        self.fire = self.fire + 0.16
    else
        self.fire = self.fire - 0.16
    end
    if self.fire < 0 then
        self.fire = 0
    end
    if self.fire > 1 then
        self.fire = 1
    end
end

function Player:attract()
    if self.y > self.collect_line then
        for i, o in ObjList(GROUP_ITEM) do
            o.attract = 8
        end
    else
        if KeyIsDown 'slow' then
            AttractItem(self, 48)
        else
            AttractItem(self, 24)
        end
    end
end

function Player:miss_eff()
    --反色圆效果
    self.deathee = {}
    self.deathee[1] = New(deatheff, self.x, self.y, 'first')
    self.deathee[2] = New(deatheff, self.x, self.y, 'second')
    --粒子效果
    New(player_death_ef, self.x, self.y)
end

function Player:calc_slow()
    --低速过渡状态，用于子机位置过渡、判定点显示过渡
    self.lh = self.lh + (self.slow - 0.5) * 0.3
    if self.lh < 0 then
        self.lh = 0
    end
    if self.lh > 1 then
        self.lh = 1
    end
end

function Player:shoot_spell()
    if not self.dialog then
        self:_shoot_spell()
    else
        --每隔15帧处理一次shoot，每隔30帧处理一次spell
        self.nextshoot = 15
        self.nextspell = 30
    end
end

function Player:_shoot_spell()
    if KeyIsDown 'shoot' and self.nextshoot <= 0 then
        self:Shoot()
    end
    if self.nextspell <= 0 then
        if KeyIsDown 'spell' and lstg.var.bomb > 0 and not lstg.var.block_spell then
            --spell
            if self.death > self.t_death[2] then
                self:SpellEX()
            else
                self:Spell()
            end
            self.death = 0
        elseif KeyIsPressed 'special' then
            self:Special()
        end
    end
end

function Player:_timer()
    if self.nextshoot > 0 then
        self.nextshoot = self.nextshoot - 1
    end
    if self.nextspell > 0 then
        self.nextspell = self.nextspell - 1
    end
    if self.protect > 0 then
        self.protect = self.protect - 1
    end
    if self.death > 0 then
        self.death = self.death - 1
    end
end

function Player:calc_img()
    if self.imgs.ls then
        self.alphaL = self.alpha * self.lh
        self.alphaH = self.alpha * (1 - self.lh)
    else
        self.alphaH = self.alpha
    end

    if self.lh == 1 then
        self.imgH = nil
    elseif self.lh == 0 then
        self.imgL = nil
    end

    if self.ani_itv > 1 then
        if self._ani < self.ani_itv then
            self._ani = self._ani + 1
            return
        else
            self._ani = 0
        end
    end
    if self.idle_itv > 1 then
        if self._idle < self.idle_itv then
            self._idle = self._idle + 1
        else
            self._idle = 0
        end
    end

    --计算
    local imgs = self.imgs.hs
    local lr_min = self.lr_minH
    local lr_max = self.lr_maxH
    if self.slow == 1 and self.imgs.ls then
        imgs = self.imgs.ls
        lr_min = self.lr_minL
        lr_max = self.lr_maxL
    end
    lr_min = lr_min - 1
    lr_max = lr_max + 1

    self.lr = self.lr + self.move.dx;
    if self.lr > lr_max then
        self.lr = lr_max
    end
    if self.lr < lr_min then
        self.lr = lr_min
    end
    if self.lr == 0 then
        self.lr = self.lr + self.move.dx
    end
    if self.move.dx == 0 then
        if self.lr > 1 then
            self.lr = self.lr - 1
        end
        if self.lr < -1 then
            self.lr = self.lr + 1
        end
    end

    self._hscale = 1
    local idle = false
    if self._idle == 0 then
        idle = true
    end

    if not self.imgs.ls or self.lh < 1 then
        if abs(self.lr) < 2 then
            local img = self:get_img('idle')
            if idle then
                self._idleH = self._idleH % (#img) + 1
            end
            self.imgH = img[self._idleH]
        elseif self.lr == lr_min then
            local img = self:get_img('left_idle')
            if idle then
                self._idleHL = self._idleHL % (#img) + 1
            end
            self.imgH = img[self._idleHL]
        elseif self.lr == lr_max then
            local img = self:get_img('right_idle')
            if idle then
                self._idleHR = self._idleHR % (#img) + 1
            end
            self.imgH = img[self._idleHR]
        elseif self.lr < 0 then
            self.imgH = self:get_img('left')[-self.lr]
        elseif self.lr > 0 then
            self.imgH = self:get_img('right')[self.lr]
        end
    end

    if self.imgs.ls and self.lh > 0 then
        if abs(self.lr) < 2 then
            local img = self:get_img('idle', true)
            if idle then
                self._idleL = self._idleL % (#img) + 1
            end
            self.imgL = img[self._idleL]
        elseif self.lr == lr_min then
            local img = self:get_img('left_idle', true)
            if idle then
                self._idleLL = self._idleLL % (#img) + 1
            end
            self.imgL = img[self._idleLL]
        elseif self.lr == lr_max then
            local img = self:get_img('right_idle', true)
            if idle then
                self._idleLR = self._idleLR % (#img) + 1
            end
            self.imgL = img[self._idleLR]
        elseif self.lr < 0 then
            self.imgL = self:get_img('left', true)[-self.lr]
        elseif self.lr > 0 then
            self.imgL = self:get_img('right', true)[self.lr]
        end
    end
end

function Player:get_img(type, slow)
    if not self.imgs.ls then
        slow = false
    end
    local imgs = self.imgs.hs
    local ret
    if slow then
        imgs = self.imgs.ls or imgs
    end
    if type == 'idle' then
        return imgs.idle
    elseif type == 'left' then
        return imgs.left
    elseif type == 'right' then
        ret = imgs.right
        if not ret then
            ret = imgs.left
            self._hscale = -1
        end
        return ret
    elseif type == 'left_idle' then
        return imgs.left_idle
    elseif type == 'right_idle' then
        ret = imgs.right_idle
        if not ret then
            ret = imgs.left_idle
            self._hscale = -1
        end
        return ret
    end
end

function Player:Shoot()
end

function Player:Spell()
    item.PlayerSpell()
    lstg.var.bomb = lstg.var.bomb - 1
    self.nextspell = 240
    self.protect = 300
end

function Player:SpellEX()
    self:Spell()
    lstg.var.bomb = lstg.var.bomb - 1
end

function Player:Special()
end

function Player:Miss()
    item.PlayerMiss()
end

return Player
