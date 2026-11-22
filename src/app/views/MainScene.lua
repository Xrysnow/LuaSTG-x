---@class MainScene:ViewBase
local MainScene = class("MainScene", cc.load("mvc").ViewBase)

for _, v in ipairs({ 'FocusLoseFunc', 'FocusGainFunc' }) do
    _G[v] = _G[v] or function()
    end
end

local skip_setting
local skip_selection

function MainScene.setSkip(skip_set, skip_sel)
    skip_setting, skip_selection = skip_set, skip_sel
end

function MainScene:onEnter()
    if not skip_setting then
        local ok, ret = pcall(require, 'main_scene')
        if not ok then
            if not LAUNCH_XE then
                require('platform.launcher')():showWithScene()
            else
                require('xe.main')():showWithScene()
            end
        end
    elseif not skip_selection then
        local scene = require('app.views.GameScene'):create(nil, setting.mod)
        lstg.loadMod()
        if lstg._exlauncher then
            SystemLog('use external launcher')
            scene:showWithScene()
        else
            local launcher = require('platform.launcher')()
            launcher:setModLoaded()
            launcher:showWithScene()
        end
    else
        lstg.loadMod()
        local game_content = require('game.content')
        game_content.setRank(1)
        game_content.setPlayer(1)
        lstg.practice = nil
        local scene = require('app.views.GameScene'):create(nil, setting.mod)
        scene:showWithScene()
    end
end

return MainScene
