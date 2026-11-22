--碰撞组

GROUP_GHOST           = 0
GROUP_ENEMY_BULLET    = 1
GROUP_ENEMY           = 2
GROUP_PLAYER_BULLET   = 3
GROUP_PLAYER          = 4
GROUP_INDES           = 5
GROUP_ITEM            = 6
GROUP_NONTJT          = 7
GROUP_ALL             = 16
GROUP_NUM_OF_GROUP    = 16

--层次结构

LAYER_BG              = -700
LAYER_ENEMY           = -600
LAYER_PLAYER_BULLET   = -500
LAYER_PLAYER          = -400
LAYER_ITEM            = -300
LAYER_ENEMY_BULLET    = -200
LAYER_ENEMY_BULLET_EF = -100
LAYER_TOP             = 0

--常量

---π
---@type number
PI                    = math.pi
---π*2
---@type number
PIx2                  = math.pi * 2
---π/2
---@type number
PI_2                  = math.pi * 0.5
---π/4
---@type number
PI_4                  = math.pi * 0.25
---√2
SQRT2                 = math.sqrt(2)
---√3
SQRT3                 = math.sqrt(3)
---√2/2
SQRT2_2               = math.sqrt(0.5)
---0.618*360
GOLD                  = 360 * (math.sqrt(5) - 1) / 2
