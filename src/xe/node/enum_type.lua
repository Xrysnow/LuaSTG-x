--
local M = {
    movetomode = { 'MOVE_NORMAL', 'MOVE_ACCEL', 'MOVE_DECEL', 'MOVE_ACC_DEC' },
    directmode = { "MOVE_X_TOWARDS_PLAYER", "MOVE_Y_TOWARDS_PLAYER", "MOVE_TOWARDS_PLAYER", "MOVE_RANDOM" },
    --bulletstyle      = {
    --    'arrow_big', 'arrow_mid', 'arrow_small', 'gun_bullet', 'butterfly', 'square', 'ball_small', 'ball_mid',
    --    'ball_mid_c', 'ball_big', 'ball_huge', 'ball_light', 'star_small', 'star_big', 'grain_a',
    --    'grain_b', 'grain_c', 'kite', 'knife', 'knife_b', 'water_drop', 'mildew', 'ellipse', 'heart', 'money',
    --    'music', 'silence',
    --    'water_drop_dark', 'ball_huge_dark', 'ball_light_dark'
    --},
    --bulletshow       = {
    --    'scale', 'arrow', 'chain', 'bullet', 'butterfly', 'ofuda', 'point', 'smallball',
    --    'circle', 'middleball', 'bigball', 'lightball', 'smallstar', 'bigstar', 'grain',
    --    'needle', 'blackgrain', 'drip', 'sword', 'knife', 'fire', 'mildew', 'ellipse', 'heart', 'money',
    --    'music', 'silence',
    --    'fire_dark', 'bigball_dark', 'lightball_dark'
    --},
    --color            = {
    --    'COLOR_RED', 'COLOR_DEEP_RED', 'COLOR_PURPLE', 'COLOR_DEEP_PURPLE',
    --    'COLOR_BLUE', 'COLOR_DEEP_BLUE', 'COLOR_ROYAL_BLUE', 'COLOR_CYAN',
    --    'COLOR_DEEP_GREEN', 'COLOR_GREEN', 'COLOR_CHARTREUSE', 'COLOR_YELLOW',
    --    'COLOR_GOLDEN_YELLOW', 'COLOR_ORANGE', 'COLOR_DEEP_GRAY', 'COLOR_GRAY'
    --},
    --object           = { "player", "_boss", "self", "nil" },
    --calculus         = { "RECTANGULAR", "POLAR" },
    --direct           = { "clockwise", "anticlockwise" },
    difficulty = { '1', '2', '3', '4', '5' },
    stagegroup = { 'Easy', 'Normal', 'Hard', 'Lunatic', 'Extra' },
    --selectenemystyle = {},
    event      = { 'frame', 'render', 'colli', 'kill', 'del' },
    leftright  = { 'left', 'right' },
    item       = { 'item_power', 'item_faith', 'item_point', 'item_power_large', 'item_power_full', 'item_faith_minor',
                   'item_extend', 'item_chip', 'item_bomb', 'item_bombchip' },
    layer      = {
        'LAYER_BG', 'LAYER_BG+1', 'LAYER_BG-1',
        'LAYER_ENEMY', 'LAYER_ENEMY+1', 'LAYER_ENEMY-1',
        'LAYER_PLAYER_BULLET', 'LAYER_PLAYER_BULLET+1', 'LAYER_PLAYER_BULLET-1',
        'LAYER_PLAYER', 'LAYER_PLAYER+1', 'LAYER_PLAYER-1',
        'LAYER_ITEM', 'LAYER_ITEM+1', 'LAYER_ITEM-1',
        'LAYER_ENEMY_BULLET', 'LAYER_ENEMY_BULLET+1', 'LAYER_ENEMY_BULLET-1',
        'LAYER_ENEMY_BULLET_EF', 'LAYER_ENEMY_BULLET_EF+1', 'LAYER_ENEMY_BULLET_EF-1',
        'LAYER_TOP', 'LAYER_TOP+1', 'LAYER_TOP-1',
    },
    group      = {
        'GROUP_GHOST',
        'GROUP_ENEMY_BULLET',
        'GROUP_ENEMY',
        'GROUP_PLAYER_BULLET',
        'GROUP_PLAYER',
        'GROUP_INDES',
        'GROUP_ITEM',
        'GROUP_NONTJT',
    },
    bgstage    = {
        'temple', 'magic_forest', 'bamboo', 'bamboo2', 'cube', 'gensokyosora',
        'hongmoguanB', 'icepool', 'lake', 'le03_5', 'magic_forest_fast', 'redsky',
        'river', 'skyandcloud', 'starlight', 'temple2', 'woods', 'world',
        --'',
    },
    blend      = {
        '',
        'mul+add', 'mul+alpha', 'add+add', 'add+alpha', 'mul+sub', 'mul+rev', 'add+sub', 'add+rev',
    },
}

local tween_type = {}
for k, v in pairs(math.tween) do
    if k ~= 'linear' then
        table.insert(tween_type, k)
    end
end
table.sort(tween_type)
table.insert(tween_type, 1, 'linear')
M.tween_type = tween_type

return M
