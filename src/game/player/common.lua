---
--- common.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---

local ObjList = ObjList
local Dist = Dist
local max = max

---
---@param player Player
---@param dist number
function AttractItem(player, dist)
    for i, o in ObjList(GROUP_ITEM) do
        if Dist(player, o) < dist then
            o.attract = max(o.attract, 3)
        end
    end
end
