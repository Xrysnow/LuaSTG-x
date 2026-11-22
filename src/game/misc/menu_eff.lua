---
--- menu_eff.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---

local task = task

---menu_FadeIn(obj, t)
---菜单淡入
function menu_FadeIn(obj, t)
    t = t or 30
    if t < 2 then
        t = 2
    end
    task.Clear(obj)
    task.New(obj, function()
        obj.hide = false
        for i = 0, (t - 1) do
            obj.alpha = i / (t - 1)
            task.Wait()
        end
        obj.locked = false
    end)
end

---menu_FadeOut(obj, t)
---菜单淡出
function menu_FadeOut(obj, t)
    t = t or 30
    if t < 2 then
        t = 2
    end
    task.Clear(obj)
    if not obj.locked then
        task.New(obj, function()
            obj.locked = true
            for i = (t - 1), 0, -1 do
                obj.alpha = i / (t - 1)
                task.Wait()
            end
            obj.hide = true
        end)
    end
end
