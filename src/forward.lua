---
--- forward.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---

local M = {}
local print = lstg.Print
M.Fonts = {}
M.TTFFonts = {}

M.ForwardList = {
    --['PlaySound']         = function(name, ...)
    --    print("PlaySound: " .. name)
    --    lstg.PlaySound(name, ...)
    --end,
    --['StopSound']         = function(name)
    --    print("StopSound: " .. name)
    --    lstg.StopSound(name)
    --end,
    --['PauseSound']        = function(name)
    --    print("PauseSound: " .. name)
    --    lstg.PauseSound(name)
    --end,
    --['ResumeSound']       = function(name)
    --    print("ResumeSound: " .. name)
    --    lstg.ResumeSound(name)
    --end,
    --['PlayMusic']         = function(name, ...)
    --    print("PlayMusic: " .. name)
    --    lstg.PlayMusic(name, ...)
    --end,
    --['StopMusic']         = function(name)
    --    print("StopMusic: " .. name)
    --    lstg.StopMusic(name)
    --end,
    --['PauseMusic']        = function(name)
    --    print("PauseMusic: " .. name)
    --    lstg.PauseMusic(name)
    --end,
    --['ResumeMusic']       = function(name)
    --    print("ResumeMusic: " .. name)
    --    lstg.ResumeMusic(name)
    --end,
    --
    --['LoadTTF']           = function(name, ...)
    --    lstg.LoadTTF(name, ...)
    --    M.TTFFonts[name] = true
    --end,
    --['LoadFont']          = function(name, ...)
    --    lstg.LoadFont(name, ...)
    --    M.Fonts[name] = true
    --end,
    --['SetResourceStatus'] = function(pool_type)
    --    lstg.SetResourceStatus(pool_type)
    --    print('切换当前资源池为: ' .. pool_type)
    --    lstg._pool_type = pool_type
    --end,

    ['']                  = function()
    end,
}

function M.forwardAll()
    for k, v in pairs(M.ForwardList) do
        _G[k] = v
    end
end

function M.unforwardAll()
    for k, _ in pairs(M.ForwardList) do
        _G[k] = lstg[k]
    end
end

function M.forward(fname)
    if M.ForwardList[fname] then
        _G[fname] = M.ForwardList[fname]
    end
end

function M.unforward(fname)
    if lstg[fname] then
        _G[fname] = lstg[fname]
    end
end

return M
