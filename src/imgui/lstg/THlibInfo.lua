local base = require('imgui.Widget')

---@class im.lstg.THlibInfo:im.Widget
local M = class('im.lstg.THlibInfo', base)
local im = imgui
local content = require('game.content')

function M:ctor(...)
    base.ctor(self, ...)
    local wi = require('imgui.Widget')
    -- player
    self:addChildChain(
            wi.TreeNode('Players'),
            std.bind(self._renderPlayerInfo, self))
    -- replay slots
    self.repRefreshInterval = 30
    self.rep = nil
    self:addChildChain(
            wi.TreeNode('Replay Slots'),
            std.bind(self._renderRepInfo, self))
    -- spell card
    self.spc = { {} }
    self._setSCColumn = {}
    self:addChildChain(
            wi.TreeNode('Spell Cards'),
            std.bind(self._renderSpellInfo, self))
    -- stage
    self:addChildChain(
            wi.TreeNode('Stages'),
            std.bind(self._renderStageInfo, self))
    --
    self.timer = 0
    self:addChild(function()
        self.timer = self.timer + 1
    end)
end

function M:_renderSpellInfo()
    if not _editor_class then
        -- THlib not loaded
        im.textUnformatted('N/A')
        return
    end
    if #self.spc[1] == 0 then
        -- only get once
        self.spc = { content.enumSpells() }
    end
    local spells, spells_classified, spell_ranks, spell_rank_names = unpack(self.spc)
    for idx, name in pairs(spell_rank_names) do
        if im.treeNode(name) then
            im.columns(2, name, true)
            if not self._setSCColumn[name] then
                im.setColumnWidth(0, 64)
                self._setSCColumn[name] = true
            end
            im.separator()
            im.text("Index")
            im.nextColumn()
            im.text("Name")
            im.nextColumn()
            im.separator()

            if spells_classified[name] then
                for i, v in ipairs(spells_classified[name]) do
                    im.textUnformatted(string.format('%d', v.index))
                    im.nextColumn()
                    im.textUnformatted(v.name)
                    im.nextColumn()
                end
            end
            im.separator()
            im.columns(1)
            im.treePop()
        end
    end
end

function M:_renderRepInfo()
    if not _editor_class then
        im.textUnformatted('N/A')
        return
    end
    if not self.rep or self.timer % self.repRefreshInterval == 0 then
        self.rep = content.enumReplays()
    end
    for i, v in ipairs(self.rep) do
        if im.treeNode(string.format('Slot %d', v.index)) then
            im.columns(2, tostring(i), true)
            for j, vv in ipairs(
                    {
                        { 'Index', string.format('%d', v.index) },
                        { 'User Name', v.user },
                        { 'Date', v.date_str },
                        { 'Time', v.time_str },
                        { 'Player', v.player },
                        { 'Rank', v.rank_str },
                        { 'Stage', string.trim(v.stage_str) },
                        { 'Total Score', tostring(v.total_score) },
                    }) do
                im.textUnformatted(vv[1])
                im.nextColumn()
                im.textUnformatted(vv[2])
                im.nextColumn()
            end
            im.columns(1)
            im.treePop()
        end
    end
end

function M:_renderStageInfo()
    if not _editor_class then
        im.textUnformatted('N/A')
        return
    end
    local ranks, rank_names = content.enumRanks()
    for _, rank in ipairs(ranks) do
        local rank_name = rank_names[rank] or 'N/A'
        local stage_names, stage_origin_names = content.enumStages(rank)
        local group = content.getStageGroup(rank)
        if im.treeNode(rank_name) then
            for i, stage_name in ipairs(stage_names) do
                local ori_name = stage_origin_names[i]
                if im.treeNode(stage_name) then
                    local stage = group[ori_name]
                    if stage then
                        im.columns(2, rank_name .. tostring(i), true)
                        for j, vv in ipairs(
                                {
                                    { 'Name', stage_name },
                                    { 'Original Name', ori_name },
                                    { 'Allow Practice', stage.allow_practice },
                                }) do
                            im.textUnformatted(vv[1])
                            im.nextColumn()
                            im.textUnformatted(tostring(vv[2]))
                            im.nextColumn()
                        end
                        im.columns(1)
                    else
                        im.textUnformatted('N/A')
                    end
                    im.treePop()
                end
            end
            im.treePop()
        end
    end
end

function M:_renderPlayerInfo()
    local players = content.enumPlayers()
    if not players then
        im.textUnformatted('N/A')
        return
    end
    for i, v in ipairs(players) do
        local name, cls, short = v[1], v[2], v[3]
        if im.treeNode(name) then
            im.columns(2, name, true)
            for j, vv in ipairs(
                    {
                        { 'Name', name },
                        { 'Class Name', cls },
                        { 'Short Name', short },
                    }) do
                im.textUnformatted(vv[1])
                im.nextColumn()
                im.textUnformatted(tostring(vv[2]))
                im.nextColumn()
            end
            im.columns(1)
            im.treePop()
        end
    end
end

return M
