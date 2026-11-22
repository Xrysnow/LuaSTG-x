---@class GameScene:cc.Node
local Scene = class("GameScene", cc.load("mvc").ViewBase)

local director = cc.Director:getInstance()
local glv = cc.Director:getInstance():getOpenGLView()
local game_util = require('game.util')

function Scene:onCreate()
    lstg.loadSetting()

    if imgui then
        local listener = cc.EventListenerKeyboard:create()
        listener:registerScriptHandler(function(code)
            if code ~= KEY.F12 then return end
            if not self._imguiTools then
                self._imguiLayer, self._imguiTools = require('imgui.lstg.util').load()
                self._imguiTools:setVisible(false)
            end
            local visible = not self._imguiTools:isVisible()
            self._imguiTools:setVisible(visible)
            imgui.setVisible(visible)
        end, cc.Handler.EVENT_KEYBOARD_PRESSED)
        director:getEventDispatcher():addEventListenerWithSceneGraphPriority(listener, self)
    end

    self:scheduleUpdateWithPriorityLua(function(dt)
        self:update(dt)
    end, 0)

    if setting.touchkey and plus.isMobile() then
        self:addTouchKey()
    end

    local scale = glv:getDesignResolutionSize().y / 480
    SystemLog(string.format(
            'ui scale = %.3f, screen.scale = %.3f', scale, screen.scale))
end

local profiler = profiler
function Scene:onEnter()
    if imgui then imgui.setToggleEnable(false) end
    --ex.Test('test2.mp4')
    if stage.next_stage then
        return
    end
    stage.next_stage = stage_menu

    --local e = cc.EventListenerCustom:create('director_after_visit', function()
    --    profiler.tic('FrameFunc')
    --    FrameFunc()
    --    profiler.toc('FrameFunc')
    --
    --    profiler.tic('RenderFunc')
    --    RenderFunc()
    --    profiler.toc('RenderFunc')
    --end)
    --cc.Director:getInstance():getEventDispatcher():addEventListenerWithFixedPriority(e, 1)
end

function Scene:onExit()
    if self._imguiTools then
        self._imguiTools:setVisible(false)
        self._imguiLayer:setVisible(false)
    end
end

function Scene:showWithScene(transition, time, more)
    --SystemLog('[GameScene] showWithScene')
    self:setVisible(true)
    local scene = display.newScene(self.name_)
    scene:addChild(self)
    if director:getRunningScene() then
        if transition then
            scene = display.wrapScene(scene, transition, time, more)
        end
        --SystemLog('[GameScene] before pushScene')
        director:pushScene(scene)
    else
        director:runWithScene(scene)
    end
    return self
end

function Scene:addTouchKey()
    if not lstg.tmpvar.disableTouchKey then
        --SystemLog('[GameScene] add TouchKey')
        local ui_layer = cc.Layer:create()
        ui_layer:setAnchorPoint(cc.p(0, 0))
        self:addChild(ui_layer)
        require('platform.controller_ui')(ui_layer)
        --SystemLog('[GameScene] TouchKey added')
    end
end

if not GameFrame then
    function GameFrame()
        if FrameFunc then
            FrameFunc()
        end
    end
end
if not GameRender then
    function GameRender()
        if RenderFunc then
            RenderFunc()
        end
    end
end

function Scene:update(dt)
    profiler.tic('FrameFunc')
    GameFrame()
    profiler.toc('FrameFunc')

    profiler.tic('RenderFunc')
    GameRender()
    profiler.toc('RenderFunc')
end

if not stage.next_stage then
    stage_init = stage.New('init', true, true)
    function stage_init:init()
    end
    function stage_init:frame()
        stage.Set('none', 'menu')
    end
    function stage_init:render()
        SetViewMode('ui')
        --RenderText('menu', 'stage_init', 320, 240, 1)
    end

    local inited = false
    stage_menu = stage.New('menu', false, true)
    function stage_menu:init()
        --SetResourceStatus('global')
        --SystemLog('stage_menu:init')
        local returnToLauncher = function()
            -- return to launcher2
            --SystemLog('pop scene')
            inited = false
            stage.current_stage = nil
            lstg.practice = nil
            game_util.stopAudios()
            glv:setDesignResolutionSize(
                    1706, 960, cc.ResolutionPolicy.SHOW_ALL)
            cc.Director:getInstance():popScene()
        end
        if inited then
            if self.save_replay then
                --SystemLog('stage_menu =\n'..stringify(self))
                local menu_replay_saver
                menu_replay_saver = New(replay_saver, self.save_replay, self.finish, function()
                    menu.FlyOut(menu_replay_saver, 'right')
                    task.New(stage_menu, function()
                        task.Wait(30)
                        task.New(stage_menu, returnToLauncher)
                    end)
                end)
                menu.FlyIn(menu_replay_saver, 'left')
            else
                --returnToLauncher()
                task.New(stage_menu, returnToLauncher)
            end
        else
            inited = true
            --SystemLog('before enterStage')
            game_util.enterStage(stage_menu, false)
        end
    end
    function stage_menu:frame()
    end
    function stage_menu:render()
        --SetViewMode('ui')
        --RenderText('menu', 'stage_menu', 320, 240, 1)
        --local size = glv:getDesignResolutionSize()
        --local str=string.format('D res: (%d, %d)', size.width, size.height)
        --RenderText('menu', str, 320, 200, 1)
        --ui.DrawMenuBG()
    end
end

return Scene
