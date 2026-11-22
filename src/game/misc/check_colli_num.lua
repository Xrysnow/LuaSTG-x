---
--- check_colli_num.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---


GROUP_NEW1 = 13
GROUP_NEW2 = 14
---在DoFrame中添加CollisionCheck(GROUP_NEW1,GROUP_ENEMY_BULLET)
local ColliCounter = Class(object)
function ColliCounter:init(x, y, a, b, rect)
    self.group = GROUP_NEW1
    self.x = x or 0
    self.y = y or 0
    self.a = a or 60
    self.b = b or 60
    self.rect = rect or true
    self.counter = 0
    self.others = {}
end
function ColliCounter:frame()
    self.counter = 0
    for i, v in pairs(self.others) do
        v.group = GROUP_NEW2
    end
    CollisionCheck(GROUP_NEW1, GROUP_NEW2)
    for i, v in pairs(self.others) do
        v.group = GROUP_ENEMY_BULLET
    end
    self.others = {}
    --now we get the counter
end
function ColliCounter:colli(other)
    if other.group == GROUP_ENEMY_BULLET then
        self.others[tostring(other)] = other
    elseif other.group == GROUP_NEW2 then
        self.counter = self.counter + 1
    end
end
function ColliCounter:render()
    --画出自身区域方便查看
    SetImageState('white', '', Color(127, 255, 255, 255))
    Render('white', self.x, self.y, 0, self.a / 8, self.b / 8)
    --显示counter
    RenderText('menu', 'counter=' .. self.counter, 0, 0, 0.5)
end

return ColliCounter
