---
--- batch_helper.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---


local task = task

function BatchCreate(ctor, num, ...)
    local ret = {}
    for i = 1, num do
        table.insert(ret, ctor(...))
    end
    return ret
end

---批量设置属性
function BatchSetProperty(t, key, val)
    for _, obj in pairs(t) do
        obj[key] = val
    end
end

---绑定属性
function BindProperty(master, slave, key)
    task.New(slave, function()
        while true do
            slave[key] = master[key]
            task.Wait()
        end
    end)
end

---批量绑定属性
function BindBatchProperty(master, slaves, key)
    for _, slave in pairs(slaves) do
        task.New(slave, function()
            while true do
                slave[key] = master[key]
                task.Wait()
            end
        end)
    end
end

---批量执行函数(self)
function BatchCall(t, f, ...)
    for _, obj in pairs(t) do
        obj[f](obj, ...)
    end
end

---批量执行函数
function BatchCall2(t, f, ...)
    for _, obj in pairs(t) do
        obj[f](...)
    end
end
