--
local M = {}
local Time = require('game.mbg.Time')

-- private

M.alpha = 1
M.guru = 0

-- public

M.position = { X = 316, Y = 401 }
M.Dis = false
M.time = 0
M.add = 0
M.addy = 0

function M.clear()
    M.position = { X = 316, Y = 401 }
    M.alpha = 1
    M.guru = 0
    M.Dis = false
    M.time = 0
end

function M.update()
    if not Time.Playing then
        return
    end
    M.guru = M.guru - 1
    --[[
    if (!Main.WideScreen)
    {
        Player.add = 125;
        Player.addy = 16;
    }
    else
    {
        Player.add = 0;
        Player.addy = 0;
    }
    --]]
    -- player move
    -- ...
    if M.Dis then
        M.time = M.time + 1
        if M.time > 40 then
            M.Dis = false
            return
        end
    else
        M.time = 0
    end
end

return M
