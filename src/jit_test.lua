---
--- jit_test.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---

--jit.opt.start('sizemcode=1024', 'maxmcode=1024')
--for i = 1, 100 do
--end

local SystemLog = lstg.Print
SystemLog("jit version: " .. jit.version)
local status = { jit.status() }
status[1] = tostring(status[1])
SystemLog('jit status: ' .. table.concat(status, ', '))
SystemLog(string.format('lua memory: %.1fKB', collectgarbage('count')))

local osname = lstg.GetPlatform()
local is_mobile = osname == 'android' or osname == 'ios'
local N = is_mobile and 5e3 or 5e5

local ret = {}
local mode = {
    off = function()
        jit.off()
    end,
    on0 = function()
        jit.on()
        jit.opt.start(0)
    end,
    on1 = function()
        jit.on()
        jit.opt.start(1)
    end,
    on2 = function()
        jit.on()
        jit.opt.start(2)
    end,
    on3 = function()
        jit.on()
        jit.opt.start(3)
    end,
}

mode.off()

local sw = lstg.StopWatch()
local n = 0

local function test()
    local t1, t2, t3
    local test1 = function()
        local t = { 1, 2, 3, 4, 5 }
        return t[5]
    end
    local test2 = function()
        return {}
    end
    local test3 = function(n)
        return ((n - 10) * 2 + 20) / 2
    end

    sw:get()
    for i = 1, N * 0.1 do
        test1()
    end
    t1 = sw:get()

    for i = 1, N * 1 do
        test2()
    end
    t2 = sw:get()

    for i = 1, N * 1 do
        n = test3(n)
    end
    t3 = sw:get()

    return t1, t2, t3, t1 + t2 + t3
end

ret.off = { test() }

for i = 0, 3 do
    mode['on' .. i]()
    ret['on' .. i] = { test() }
end

local info = 'jit test result (ms):'
local ffmt = '%6.2f'
local fmt = '    %s: ' .. ffmt .. string.rep(', ' .. ffmt, #ret.on3 - 2) .. ' | ' .. ffmt
local total = {}
local i_n = #ret.on3
for k, v in pairs(mode) do
    local str = string.format(fmt, k, unpack(ret[k]))
    table.insert(total, { k, ret[k][i_n], str })
end
table.sort(total, function(a, b)
    return a[2] < b[2]
end)
for i, v in ipairs(total) do
    info = info .. '\n' .. v[3]
end

SystemLog(info)

local m = total[1][1]
mode[m]()
SystemLog('switch to jit mode: ' .. m)

