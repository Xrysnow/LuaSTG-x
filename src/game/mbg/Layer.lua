---@class lstg.mbg.Layer
local M = class('lstg.mbg.Layer')

-- private
M.clcount = 0
M.clwait = 0
M.form = nil
-- public
M.total = 0
M.selection = 0
M.oldcolor = 0
---@type lstg.mbg.Layer[]
M.LayerArray = {} -- List<Layer>

function M:ctor(nm, bg, ed)
    assert(nm and bg and ed)
    self.name = nm
    self.Visible = true
    self.sort = #M.LayerArray
    M.selection = 0
    self.color = M.oldcolor
    M.oldcolor = M.oldcolor + 1
    if M.oldcolor > 6 then
        M.oldcolor = 0
    end
    self.begin = bg
    self['end'] = ed
    M.total = M.total + 1
    self.NeedDelete = false
    --
    ---@type lstg.mbg.Batch[]
    self.BatchArray = {} -- List<Batch>
    self.LaseArray = {} -- List<Lase>
    self.CoverArray = {} -- List<Cover>
    self.ReboundArray = {} -- List<Rebound>
    ---@type lstg.mbg.Force[]
    self.ForceArray = {} -- List<Force>
    ---@type lstg.mbg.Barrage[]
    self.Barrages = {} -- List<Barrage>
    table.insert(M.LayerArray, self)
end

function M:clear()
    M.total = 0
    M.selection = 0
    M.oldcolor = 0
    M.clcount = 0
    M.clwait = 0
    M.LayerArray = {}
end

function M:update()
    local Time = require('game.mbg.Time')
    local Main = require('game.mbg.Main')
    local sw = lstg.StopWatch()
    local tt = 0

    if not Main.Available then
        return
    end
    if self.Visible then
        for i, v in ipairs(self.ForceArray) do
            v.id = i - 1
            v.parentid = self.sort
            if (not Time.Playing) then
                v:update()
            else
                v.copys:update()
            end
        end
        for i, v in ipairs(self.ReboundArray) do
            v.id = i - 1
            v.parentid = self.sort
            if (not Time.Playing) then
                v:update()
            else
                v.copys:update()
            end
        end
        for i, v in ipairs(self.CoverArray) do
            v.id = i - 1
            v.parentid = self.sort
            if (not Time.Playing) then
                v:update()
            else
                v.copys:update()
            end
        end
        for i, v in ipairs(self.LaseArray) do
            v.id = i - 1
            v.parentid = self.sort
            if (not Time.Playing) then
                v:update()
            else
                v.copys:update()
            end
        end
        for i, v in ipairs(self.BatchArray) do
            v.id = i - 1
            v.parentid = self.sort
            if (not Time.Playing) then
                v:update()
            else
                v.copys:update()
            end
        end
        if Time.Playing then
            sw:reset()
            for i, v in ipairs(self.Barrages) do
                v.id = i - 1
                v:update()
                v:lupdate()
            end
            self._Tb = sw:get() * 1000
        end
    end
end

function M.aupdate()
    if (M.clcount == 1) then
        M.clwait = M.clwait + 1
        if (M.clwait > 15) then
            M.clwait = 0
            M.clcount = 0
        end
    end
end

return M
