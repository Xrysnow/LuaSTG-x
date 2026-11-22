local M = {}
local content = require('game.content')

--TODO
function M.getStageHighscore(i_stage, i_player)
    local _, ori_names = content.enumStages()
    local player = i_player and player_list[i_player][2] or lstg.var.player_name or player_list[1][2]
    local idx = ori_names[i_stage] .. '@' .. player
    local score = 0
    if scoredata.hiscore then
        score = scoredata.hiscore[idx] or 0
    end
    return score
end

function M.getSpellHistory(i_player, i_spell)
    i_player = i_player or scoredata.player_select
    local spells, ranks, rank_names = content.enumSpells()
    --local dif = rank_names[ranks[content.getSpellRank(i_spell)]]
    local dif_name = spells[i_spell].rank_name

    local ply_name = player_list[i_player][2]
    --local sc_name  = _sc_table[spells[dif_name][i_spell].index][2]
    local sc_name = _sc_table[i_spell][2]
    local ret = { 0, 0 }
    local h = scoredata.spell_card_hist
    --if h then
    --    if h[ply_name] then
    --        if h[ply_name][dif_name] then
    --            if h[ply_name][dif_name][sc_name] then
    --                ret = h[ply_name][dif_name][sc_name]
    --            end
    --        end
    --    end
    --end
    ret = (h and h[ply_name] and h[ply_name][dif_name] and h[ply_name][dif_name][sc_name]) or ret
    return ret
end

return M
