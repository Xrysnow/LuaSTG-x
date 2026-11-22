--
local M = {}
M._ed = require('core_x.EventDispatcher').create()
local started
local paused
local stepping
---@type cc.Node
local node
local NavEnableKeyboard
local NavEnableGamepad

local _FrameFunc = 'FrameFunc'
local _RenderFunc = 'RenderFunc'
local fvoid = function()
end
local function _saveFunc()
    if FrameFunc ~= fvoid then
        M._FrameFunc = FrameFunc
    end
    if RenderFunc ~= fvoid then
        M._RenderFunc = RenderFunc
    end
end

function M.start(rank, player, stage_, debugStage, debugSC)
    if started then
        if paused then
            M.resume()
        end
        return true
    end

    -- disable keyboard
    local flag = imgui.ConfigFlags.NavEnableKeyboard
    NavEnableKeyboard = imgui.configFlagCheck(flag)
    if NavEnableKeyboard then
        imgui.configFlagDisable(flag)
    end
    flag = imgui.ConfigFlags.NavEnableGamepad
    NavEnableGamepad = imgui.configFlagCheck(flag)
    if NavEnableGamepad then
        imgui.configFlagDisable(flag)
    end

    local xe = require('xe.main')
    -- clear game log
    xe.getGameLog():clear()
    -- show game property
    xe.getProperty():setGame()
    xe.getEditor():setGame()
    xe.setKeyEventEnabled(false)
    xe.setKeyEventEnabled('game', true)

    -- clear tasks
    M._ed:removeAllListeners()
    -- reset frame
    FrameReset()

    lstg.eventDispatcher:removeAllListeners()
    setting.mod = '_editor_'
    setting.resx = 1280
    setting.resy = 720

    --

    local core = {
        'core/include.lua',
        'core_x/__init__.lua',

        'core/const.lua',
        'core/status.lua',
        'core/math.lua',
        --'core/respool.lua',
        --'core/resources.lua',
        'core/screen.lua',
        'core/view.lua',
        'core/class.lua',
        'core/task.lua',
        'core/stage.lua',
        'core/input.lua',
        'core/global.lua',
        'core/corefunc.lua',
        'core/file.lua',
        'core/loading.lua',
        'core/async.lua',
    }
    for _, f in ipairs(core) do
        DoFile(f)
    end
    FileExist = plus.FileExists
    lstg.loadData()
    local gamepad = require('platform.GamepadActions')
    gamepad.init()
    lstg.ResourceMgr:getInstance():clearLocalFileCache()

    --

    local game_util = require('game.util')
    local glv = cc.Director:getInstance():getOpenGLView()
    local dsize = glv:getDesignResolutionSize()
    local stage_name = 'menu'

    local stage_init = stage.New('init', true, true)
    function stage_init:init()
    end
    function stage_init:frame()
        stage.Set('none', stage_name)
    end
    function stage_init:render()
        SetViewMode('ui')
        RenderText('menu', 'stage_init', 320, 240, 1)
    end

    local inited = false
    local stage_menu = stage.New(stage_name, false, true)
    function stage_menu:init()
        local returnToLauncher = function()
            inited = false
            stage.current_stage = nil
            lstg.practice = nil
            game_util.stopAudios()
            -- restore
            glv:setDesignResolutionSize(
                    dsize.width, dsize.height, cc.ResolutionPolicy.SHOW_ALL)
            M._return()
        end
        if inited then
            --if self.save_replay then
            --    local menu_replay_saver
            --    menu_replay_saver = New(replay_saver, self.save_replay, self.finish, function()
            --        menu.FlyOut(menu_replay_saver, 'right')
            --        task.New(stage_menu, function()
            --            task.Wait(30)
            --            task.New(stage_menu, returnToLauncher)
            --        end)
            --    end)
            --    menu.FlyIn(menu_replay_saver, 'left')
            --else
            task.New(stage_menu, returnToLauncher)
            --end
        else
            inited = true
            game_util.enterStage(stage_menu, false)
        end
    end
    function stage_menu:frame()
    end
    function stage_menu:render()
    end

    local ok, msg

    --
    SetResourceStatus('global')
    --lstg.loadPlugins()

    lstg.eventDispatcher:dispatchEvent('load.THlib.before')
    Include('THlib.lua')

    ok, msg = pcall(Include, '_editor_output.lua')
    if not ok then
        M._stop()
        return false, msg
    end

    --M.loadStage()
    lstg.eventDispatcher:dispatchEvent('load.THlib.after')
    DoFile('core/score.lua')
    RegisterClasses()
    --SetTitle(setting.mod)
    SetResourceStatus('stage')
    --
    local e = lstg.eventDispatcher
    e:removeListenerByTag('FrameReset')
    --e:removeListenerByTag('ext.FrameFunc')
    --
    local content = require('game.content')
    content._reset()

    local ranks, rank_names = content.enumRanks()
    for _, v in ipairs(ranks) do
        content.enumStages(v)
    end
    --print(stringify(ranks))
    --print(stringify(rank_names))

    ok, msg = content.setRank(rank or ranks[1])
    if not ok then
        M._stop()
        return false, msg
    end
    ok, msg = content.setPlayer(player or 1)
    if not ok then
        M._stop()
        return false, msg
    end
    --ok, msg = content.setStage(stage_ or 1)
    if debugStage then
        lstg.practice = 'stage'
        lstg.stage_name = debugStage
    elseif debugSC then
        --local spells = content.enumSpells()
        --lstg.practice = 'spell'
        lstg.practice = 'stage'
        M._defineSpellStage()
        lstg.stage_name = 'SC Debugger@SC Debugger'
    else
        ok, msg = content.setStage(stage_ or 1)
        if not ok then
            M._stop()
            return false, msg
        end
        lstg.practice = nil
    end

    -- lstg.loadSetting
    glv:setDesignResolutionSize(
            setting.resx, setting.resy, cc.ResolutionPolicy.SHOW_ALL)
    SetSEVolume(setting.sevolume / 100)
    SetBGMVolume(setting.bgmvolume / 100)
    lstg.calcScreen()
    lstg.loadViewParams()
    _SetBound()

    if setting.xe.cheat then
        cheat = true
    else
        cheat = nil
    end

    if not node then
        node = cc.Node:create()
        node:addTo(imgui.get())
        node:scheduleUpdateWithPriorityLua(M._update, 0)
    end
    stage.next_stage = stage_menu

    _saveFunc()
    started = true
    paused = false
    return true
end

function M._return()
    --
    M.stop()
end

local function _stop()
    --all_class = {}
    --class_name = {}
    --
    FrameReset()
    -- clear resource pool
    RemoveResource('stage')
    RemoveResource('global')
    -- clear object pool
    ResetPool()
    --
    lstg.included = {}
    lstg.current_script_path = { '' }
    lstg.eventDispatcher:removeAllListeners()
    --
    stage.current_stage = nil
    stage.next_stage = nil
    lstg.var = { username = setting.username }
    lstg.tmpvar = {}
    lstg.paused = false
    lstg.quit_flag = false
    --
    local xe = require('xe.main')
    xe.getEditor():setEditor()
    xe.getProperty():setEditor()
    xe.setKeyEventEnabled(false)
    xe.setKeyEventEnabled('editor', true)
    -- restore
    if NavEnableKeyboard then
        imgui.configFlagEnable(imgui.ConfigFlags.NavEnableKeyboard)
    end
    if NavEnableGamepad then
        imgui.configFlagEnable(imgui.ConfigFlags.NavEnableGamepad)
    end
    started = false
    paused = false
end
M._stop = _stop

function M._stopUpdate()
    _saveFunc()
    _G[_FrameFunc] = fvoid
    _G[_RenderFunc] = fvoid
end

function M.stop()
    if not started then
        return
    end
    --
    M._stopUpdate()
    audio.Engine:stop()

    -- resources should be cleared after render
    M._ed:addListener('update', function()
        _stop()
        M._ed:removeListenerByTag('stop')
    end, 10, 'stop')
end

local function _pause()
    _saveFunc()
    _G[_FrameFunc] = fvoid
    _pause_music()
    paused = true
end
M._pause = _pause

function M.pause()
    if not started then
        return
    end
    if paused then
        return
    end
    _pause()

    paused = true
end

local function _resume()
    if M._FrameFunc then
        _G[_FrameFunc] = M._FrameFunc
    end
    if M._RenderFunc then
        _G[_RenderFunc] = M._RenderFunc
    end
    _resume_music()
    paused = false
end

function M.resume()
    if not started then
        return
    end
    if not paused then
        return
    end
    _resume()

    paused = false
end

function M.step(n, onFinish)
    if n < 1 or not paused then
        return
    end
    local ii = 1
    stepping = true
    M._ed:addListener('update', function()
        if ii <= n then
            ii = ii + 1
            _resume()
        else
            stepping = false
            _pause()
            if onFinish then
                onFinish()
            end
            M._ed:removeListenerByTag('step')
        end
        if ii > n + 1 then
            error('should not be here')
        end
    end, 1, 'step')
end

function M._getState()
    return started, paused, stepping
end

function M.addTask(f, priority, tag)
    M._ed:addListener('update', f, priority, tag)
end

function M._update(dt)
    local _, ok, msg
    _ = profiler and profiler.tic('FrameFunc')
    ok, msg = pcall(FrameFunc)
    if not ok then
        print('error in FrameFunc')
    end
    _ = profiler and profiler.toc('FrameFunc')

    _ = profiler and profiler.tic('RenderFunc')
    if ok then
        ok, msg = pcall(RenderFunc)
        if not ok then
            print('error in RenderFunc')
        end
    end
    _ = profiler and profiler.toc('RenderFunc')

    if not ok then
        M._stopUpdate()
        audio.Engine:stop()

        M._ed:removeAllListeners()
        require('xe.logger').log(msg, 'error')
        M._stop()

        local win = require('xe.win.Message')('Error', msg)
        win:addHandler('OK')
        imgui.get():addChild(win)
        return
    end

    M._ed:dispatchEvent('update')
end

function M._defineSpellStage()
    stage.group.New('menu', {}, "SC Debugger",
                    { lifeleft = 7, power = 400, faith = 50000, bomb = 2 }, false)
    stage.group.AddStage('SC Debugger', 'SC Debugger@SC Debugger',
                         { lifeleft = 7, power = 400, faith = 50000, bomb = 2 }, false)
    stage.group.DefStageFunc('SC Debugger@SC Debugger', 'init', function(self)
        _init_item(self)
        New(mask_fader, 'open')
        New(_G[lstg.var.player_name])
        task.New(self, function()
            do
                LoadMusic('spellcard', music_list.spellcard[1], music_list.spellcard[2], music_list.spellcard[3])
                New(bamboo_background)
            end
            task._Wait(60)
            _play_music("spellcard")
            local _boss_wait = true
            local _ref
            if setting.xe.debug_sc_current_only then
                _ref = New(_editor_class[_boss_class_name], _debug_cards)
            else
                _ref = New(_editor_class[_boss_class_name], _editor_class[_boss_class_name].cards)
            end
            last = _ref
            if _boss_wait then
                while IsValid(_ref) do
                    task.Wait()
                end
            end
            task._Wait(180)
        end)
        task.New(self, function()
            while coroutine.status(self.task[1]) ~= 'dead' do
                task.Wait()
            end
            _stop_music()
            --task.Wait(30)
            stage.group.FinishStage()
        end)
    end)
end

return M
