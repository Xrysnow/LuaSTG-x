local M = {}

function M.enumRanks()
    local _rank_names = {}
    local _ranks = {}
    for _, sg in ipairs(stage.groups or {}) do
        if sg ~= 'Spell Practice' then
            _rank_names[stage.groups[sg].difficulty] = sg
            table.insert(_ranks, stage.groups[sg].difficulty)
        end
    end
    table.sort(_ranks)
    return _ranks, _rank_names
end

function M.setRank(rank)
    if not stage.groups then
        return false
    end
    local _ranks, _rank_names = M.enumRanks()
    local group_name = _rank_names[rank]
    if not group_name then
        local msg = string.format(
                "can't find rank %q, possible value: %q",
                tostring(rank), tostring(_ranks[1]))
        return false, msg
    end
    scoredata.difficulty_select = rank
    lstg.group_name = group_name
    return true
end

--

function M.enumPlayers()
    return table.clone(player_list)
end

function M.setPlayer(index)
    if not player_list or not player_list[index] then
        return false
    end
    local player_name = player_list[index][2]
    local rep_player = player_list[index][3]
    if not (player_name and rep_player) then
        return false, ("can't find player %d"):format(index)
    end
    scoredata.player_select = index--TODO: may have problem
    lstg.var.player_name = player_name
    lstg.var.rep_player = rep_player
    return true
end

--

local _stage_groups = {}
local _stages = {}
--
local _stage_names = {}
local _stage_origin_names = {}

function M.enumStages(rank)
    local dif = rank or scoredata.difficulty_select or 1
    _stage_names, _stage_origin_names = {}, {}
    for _, name in ipairs(stage.groups or {}) do
        local group = stage.groups[name]
        if name ~= 'Spell Practice' and group.difficulty == dif and group.allow_practice then
            _stage_groups[dif] = name
            for _, origin in ipairs(group) do
                if stage.stages[origin] and stage.stages[origin].allow_practice then
                    table.insert(_stage_names, origin:match('^(.-)@') or origin)
                    table.insert(_stage_origin_names, origin)
                end
            end
            break
        end
    end
    return _stage_names, _stage_origin_names
end

function M.getStageGroup(rank)
    local dif = rank or scoredata.difficulty_select or 1
    local t = stage.groups[_stage_groups[dif]]
    return t
end

function M.getStageGroups()
    return stage.groups
end

function M.setStage(index)
    local dif = scoredata.difficulty_select or 1
    local _, origins = M.enumStages(dif)
    local stage_name = origins[index]
    if not stage_name then
        return false, ("can't find stage %d"):format(index)
    end
    lstg.practice = 'stage'
    lstg.stage_name = stage_name
    return true
end

--

local _spells = {}
local _spells_classified = {}
local _spell_ranks = {}
local _spell_rank_names = {}

function M.enumSpells()
    if type(_sc_table) ~= 'table' or type(_editor_class) ~= 'table' then
        return {}, {}, {}, {}
    end
    local _ranks, _rank_names = M.enumRanks()
    if #_spells == 0 then
        local need_fix = false
        for k, v in pairs(_ranks) do
            _spell_ranks[k] = v
        end
        for k, v in pairs(_rank_names) do
            _spell_rank_names[k] = v
        end
        --_spell_ranks      = table.clone(_ranks)
        --_spell_rank_names = table.clone(_rank_names)
        local _wrong_rank_name
        for idx, sp in ipairs(_sc_table) do
            local rank_name = _editor_class[sp[1]].difficulty
            if not _spells_classified[rank_name] then
                _spells_classified[rank_name] = {}
            end
            table.insert(_spells_classified[rank_name], { index = idx, name = sp[2] })
            if not table.has(_spell_rank_names, rank_name) then
                need_fix = true
                if rank_name ~= _wrong_rank_name then
                    SystemLog('[enumSpells] got wrong difficulty: ' .. rank_name)
                    _wrong_rank_name = rank_name
                end
            end
        end
        if need_fix then
            _spell_ranks = {}
            _spell_rank_names = {}
            for k, _ in pairs(_spells_classified) do
                table.insert(_spell_rank_names, k)
            end
            for i = 1, #_spell_rank_names do
                _spell_ranks[i] = i
            end
        end
        for k, s in pairs(_spells_classified) do
            for _, v in pairs(s) do
                --table.insert(_spells, {
                --    index     = v.index,
                --    name      = v.name,
                --    rank_name = k,
                --    rank      = table.keyof(_spell_ranks, k),
                --})
                _spells[v.index] = {
                    index     = v.index,
                    name      = v.name,
                    rank_name = k,
                    rank      = table.keyof(_spell_ranks, k),
                }
            end
        end
    end

    return _spells, _spells_classified, _spell_ranks, _spell_rank_names
end

function M.getSpellRank(index)
    M.enumSpells()
    for i, k in pairs(_spell_rank_names) do
        for _, s in ipairs(_spells_classified[k]) do
            if s.index == index then
                return _spell_ranks[i]
            end
        end
    end
end

function M.setSpell(index)
    local p = scoredata.player_select or 1
    local player_name = player_list[p][2]
    local rep_player = player_list[p][3]
    if not (player_name and rep_player) then
        return false, ("can't find player %d"):format(p)
    end
    local difficulty_select = M.getSpellRank(index) or scoredata.difficulty_select
    if not difficulty_select then
        return false, ("can't find difficulty of spell %d"):format(index)
    end
    lstg.practice = 'spell'
    scoredata.difficulty_select = difficulty_select
    lstg.var.sc_index = index
    lstg.var.player_name = player_name
    lstg.var.rep_player = rep_player
    return true
end

--

local _replays

function M.enumReplays()
    --if not _replays then
    _replays = M._getReplaySlots()
    --end
    return _replays
end

function M._getSlotStages(slot)
    local ret = {}
    for i, v in pairs(slot.stages) do
        --local score = string.format('%09d', v.score)
        local name = string.match(v.stageName, '^(.-)@') or v.stageName
        table.insert(ret, { name, v.score })
    end
    return ret
end

function M._getReplaySlots()
    local ret = {}
    ext.replay.RefreshReplay()
    for i = 1, ext.replay.GetSlotCount() do
        --local text = {}
        local slot = ext.replay.GetSlot(i)
        if slot and slot.stages and #slot.stages > 0 then
            -- use time of the first stage
            local datetime = slot.stages[1].stageDate
            local date_str = os.date("%y/%m/%d", datetime)

            local totalScore = 0
            local diff, stage_num = 0, 0
            local is_cleared, is_spell--TODO: is_stage?
            local tmp
            for i, k in ipairs(slot.stages) do
                totalScore = totalScore + slot.stages[i].score
                diff = string.match(k.stageName, '^.+@(.+)$')
                tmp = string.match(k.stageName, '^(.+)@.+$')
                if string.match(tmp, '%d+') == nil then
                    stage_num = tmp
                else
                    stage_num = 'St' .. string.match(tmp, '%d+')
                end
            end
            if diff == 'Spell Practice' then
                diff = 'SpellPr'
                is_spell = true
            end
            if tmp == 'Spell Practice' then
                local var = DeSerialize(slot.stages[1].stageExtendInfo)
                stage_num = var.sc_index
                is_spell = true
            end
            if slot.group_finish == 1 then
                stage_num = 'All'
                is_cleared = true
            end
            local ply = slot.stages[1].stagePlayer
            local usr = slot.userName
            --local time_str = os.date("!%H:%M", slot.stages[1].stageDate + setting.timezone * 3600)
            local time_str = os.date("%H:%M", slot.stages[1].stageDate)
            -- spaces
            stage_num = tostring(stage_num)
            for _ = 1, 3 - #stage_num do
                stage_num = ' ' .. stage_num
            end
            for _ = 1, 7 - #diff do
                diff = diff .. ' '
            end
            for _ = 1, 8 - #ply do
                ply = ply .. ' '
            end
            for _ = 1, 8 - #usr do
                usr = usr .. ' '
            end

            table.insert(ret, {
                index       = i,
                user        = slot.userName,
                user_str    = usr,
                datetime    = datetime,
                date_str    = date_str,
                time_str    = time_str,
                player      = slot.stages[1].stagePlayer,
                player_str  = ply,
                rank_str    = diff,
                stage_str   = stage_num,
                total_score = totalScore,

                is_cleared  = is_cleared,
                is_spell    = is_spell,
                stages      = M._getSlotStages(slot),
                slot        = slot,
            })
            --text = { string.format('No.%02d', i), usr, date_str, time_str, ply, diff, stage_num }
            --text = { string.format('No.%02d', i), '--------', '--/--/--', '--:--', '--------', '-------', '---' }
        end
    end
    return ret
end

function M.setReplay(replay, i_stage)
    local rep_path = replay.slot.path
    local rep_stage
    if replay.rank_str == 'SpellPr' then
        i_stage = 1
        rep_stage = replay.slot.stages[1].stageName
    else
        rep_stage = replay.slot.stages[i_stage].stageName
    end
    if not (rep_path and rep_stage) then
        return false, ("can't find stage %d in replay"):format(i_stage)
    end
    lstg.practice = 'replay'
    local u = require('game.util')
    u._rep_path = rep_path
    u._rep_stage = rep_stage
    lstg.tmpvar.rep_path = rep_path
    lstg.tmpvar.rep_stage = rep_stage
    return true
end

function M._reset()
    _stage_groups = {}
    _stages = {}
    _stage_names = {}
    _stage_origin_names = {}
    _spells = {}
    _spells_classified = {}
    _spell_ranks = {}
    _spell_rank_names = {}
    _replays = nil
end

return M
