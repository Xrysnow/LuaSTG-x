---@class x.launcher:cc.ViewBase
local M = class('Launcher', require('cc.ViewBase'))
local im = imgui
local director = cc.Director:getInstance()
local gamepad = require('platform.GamepadActions')
local gp = require('cocos.cocos2d.Gamepad')

local function tr(en, zh)
    return i18n({ en = en, zh = zh })
end

local function copy(value)
    if type(value) ~= 'table' then return value end
    local result = {}
    for k, v in pairs(value) do result[k] = copy(v) end
    return result
end

-- Only edit launcher preferences; preserve MOD/editor/extension data.
local preferences = {
    'bgmvolume', 'sevolume', 'res_ratio', 'resy', 'resx', 'windowsize_w',
    'windowsize_h', 'windowed', 'vsync', 'posteffect', 'render_skip',
    'keys', 'keysys', 'username', 'allowsnapshot',
    'orientation', 'touchkey', 'gamepad_actions', 'gamepad_hardware', 'gamepad_preferred',
}
local pages = {
    { 'mod', 'MOD library', 'MOD 库' },
    { 'graph', 'Display', '画面' },
    { 'sound', 'Audio', '声音' },
    { 'input', 'Input', '输入' },
    { 'others', 'General', '常规' },
    { 'about', 'About', '关于' },
}
local actions = {
    { 'keys', 'up', 'Move up', '上移' },
    { 'keys', 'down', 'Move down', '下移' },
    { 'keys', 'left', 'Move left', '左移' },
    { 'keys', 'right', 'Move right', '右移' },
    { 'keys', 'shoot', 'Shoot / confirm', '射击 / 确定' },
    { 'keys', 'slow', 'Focus', '低速移动' },
    { 'keys', 'spell', 'Spell / cancel', '符卡 / 取消' },
    { 'keys', 'special', 'Special', '特殊操作' },
    { 'keysys', 'menu', 'Pause / menu', '暂停 / 菜单' },
    { 'keysys', 'repfast', 'Replay fast', '回放加速' },
    { 'keysys', 'repslow', 'Replay slow', '回放减速' },
    { 'keysys', 'snapshot', 'Screenshot', '截图' },
    { 'keysys', 'toggle_collider', 'Show hitboxes', '显示碰撞体' },
}
local keyNames = {}
for name, code in pairs(require('keycode')) do keyNames[code] = name end
local accent = im.vec4(0.82, 0.82, 0.82, 1)
local muted = im.vec4(0.62, 0.62, 0.62, 1)

local function text(value)
    im.textUnformatted(tostring(value))
end

local function textHeight(value, wrap)
    local cursor = im.getCursorPos()
    -- Use ImGui's actual text layout and wrapping without drawing the text.
    im.pushClipRect(im.p(0, 0), im.p(0, 0), true)
    if wrap then im.pushTextWrapPos(0) end
    text(value)
    local height = im.getItemRectSize().y
    if wrap then im.popTextWrapPos() end
    im.popClipRect()
    im.setCursorPos(cursor)
    return height
end

local function hint(value)
    im.pushStyleColor(im.Col.Text, muted)
    im.pushTextWrapPos(0)
    text(value)
    im.popTextWrapPos()
    im.popStyleColor()
end

local function heading(en, zh)
    im.textColored(accent, tr(en, zh))
    im.separator()
    im.spacing()
end

local function combo(label, preview, entries, selected, choose)
    im.setNextItemWidth(math.min(320, im.getContentRegionAvail().x))
    if im.beginCombo(label, preview) then
        for i, entry in ipairs(entries) do
            im.pushID(i)
            if im.selectable(entry, selected == i) then choose(i) end
            if selected == i then im.setItemDefaultFocus() end
            im.popID()
        end
        im.endCombo()
    end
end

function M:_readPreferences(source)
    local result = {}
    for _, name in ipairs(preferences) do
        local value = source[name]
        if value == nil then value = default_setting[name] end
        result[name] = copy(value)
    end
    return result
end

function M:onCreate()
    self._page, self._filter = 'mod', ''
    self._mode = 'game'
    self._stages, self._spells, self._replays = {}, {}, {}
    self._draft = self:_readPreferences(setting)
    self._dirty = false
    self._status = tr('Select a MOD to begin.', '选择一个 MOD，开始游戏。')
    self:_refreshMods()
    local listener = cc.EventListenerKeyboard:create()
    listener:registerScriptHandler(function(code)
        if not self._active then return end
        if code == KEY.F5 then
            self:_queue(function() self:_reload() end)
            return
        end
        local capture = self._capture
        if not capture then return end
        if code == KEY.ESCAPE then
            self:_cancelCapture()
        elseif capture.kind == 'keyboard' then
            local keys = self._draft[capture.group]
            local old = keys[capture.name]
            -- Swap duplicate keys to keep game/system bindings exclusive.
            for _, action in ipairs(actions) do
                local group, name = action[1], action[2]
                if self._draft[group][name] == code then self._draft[group][name] = old end
            end
            keys[capture.name] = code
            self._dirty, self._capture = true, nil
        end
    end, cc.Handler.EVENT_KEYBOARD_PRESSED)
    director:getEventDispatcher():addEventListenerWithSceneGraphPriority(listener, self)
    self:scheduleUpdateWithPriorityLua(function()
        if not self._active then return end
        -- onEnter runs inside the parent scene's child traversal. Add the
        -- shared ImGui layer only after that traversal has finished.
        if not self._renderer then self:_initImGui() end
        self:_sampleGamepad()
    end, 0)
end

function M:_initImGui()
    -- The shared ImGui layer is detached while cocos switches scenes. Reuse it
    -- on return instead of creating a second layer before it is reattached.
    if not self._layer then
        self._layer = im.on()
        im.configFlagDisable(im.ConfigFlags.NavEnableKeyboard)
        im.setGamepadPlayer(self._draft.gamepad_actions.slot or 0)
        im.configFlagEnable(im.ConfigFlags.NavEnableGamepad)
    end
    local layer = self._layer
    layer:setVisible(true)
    if not M._font then
        M._font = im.addFontTTF('font/WenQuanYiMicroHeiMono.ttf', 36)
    end
    if not self._renderer then
        self._renderer = require('imgui.Widget').Widget()
        self._renderer:setHandler(function()
            if self._active then self:_render() end
        end)
        layer:addChild(self._renderer)
    end
end

function M:onEnter()
    self._previousStats = director:isStatsDisplay()
    director:setDisplayStats(false)
    if self._layer then self._layer:setVisible(true) end
    im.setToggleEnable(false)
    self._active = true
    if self._loaded and not lstg._exlauncher then
        self:_queue(function() self:_refreshChoices() end)
    end
end

function M:onExit()
    self._active = false
    self:_cancelCapture()
    if self._rumbleTest then
        gp.stop(self._rumbleTest.device, gp.Channel.Body)
        self._rumbleTest = nil
    end
    director:setDisplayStats(self._previousStats)
    local layer = self._layer
    if layer then layer:setVisible(false) end
end

function M:onCleanup()
    if self._renderer then
        self._renderer:removeSelf()
        self._renderer = nil
    end
    self._layer = nil
end

function M:_queue(action)
    if not self._pending then
        self:_cancelCapture()
        self._error = false
        self._pending = action
        -- Run outside both ImGui's frame and Node::update: reload can destroy
        -- this view, so its native update callback must have returned first.
        local scheduler = director:getScheduler()
        local token
        token = scheduler:scheduleScriptFunc(function()
            scheduler:unscheduleScriptEntry(token)
            self._pending = nil
            if not self._active then return end
            local ok, err = pcall(action)
            if not ok then
                self._error, self._status = true, tostring(err)
                SystemLog('Launcher: ' .. self._status)
            end
        end, 0, false)
    end
end

function M:_cancelCapture()
    if self._capture and self._capture.lease then self._capture.lease:close() end
    self._capture = nil
    if self._active and self._layer then
        im.configFlagEnable(im.ConfigFlags.NavEnableGamepad)
    end
end

function M:_beginCapture(capture)
    self:_cancelCapture()
    if capture.kind ~= 'keyboard' then
        local frame = gp.frame()
        capture.device = self._gamepadDevice
        capture.tick = frame:tick()
        if capture.kind == 'hardware' then
            local err
            capture.lease, err = gp.watchRaw(capture.device)
            if not capture.lease then
                self._status, self._error = tostring(err), true
                return
            end
        end
        im.configFlagDisable(im.ConfigFlags.NavEnableGamepad)
    end
    self._capture = capture
end

function M:_sampleGamepad()
    local frame = gp.frame()
    if self._rumbleTest then
        local test = self._rumbleTest
        for event in gp.events(frame) do
            local payload = event.payload
            if event.kind == gp.EventKind.OutputDone and event.device == test.device and payload.command == test.command then
                self._status = payload.status == gp.Completion.Applied and tr('Vibration sent.', '已发送震动。') or tostring(payload.error)
                self._error = payload.status == gp.Completion.Failed
                self._rumbleTest = nil
                break
            end
        end
    end
    local capture = self._capture
    if not capture or capture.kind == 'keyboard' or capture.tick == frame:tick() then return end
    capture.tick = frame:tick()
    local pad = frame:find(capture.device)
    if not pad then
        self:_cancelCapture()
        return
    end
    local draft = self._draft
    if capture.kind == 'hardware' then
        local identity = gamepad.identity(pad:info())
        local line = gp.mappingFor(capture.device)
        local previous = draft.gamepad_hardware[identity] or (line and line:match('^[^,]*,[^,]*,(.*)$'))
        local fields = gamepad.learnHardware(frame, capture.device, capture.name, previous)
        if not fields then return end
        draft.gamepad_hardware[identity] = fields
    else
        local binding = gamepad.learnAction(frame, capture.device)
        if not binding then return end
        local profile = draft.gamepad_actions
        local previous = profile[capture.group][capture.name]
        for _, action in ipairs(actions) do
            local group, name = action[1], action[2]
            local other = profile[group][name]
            if other == binding or (type(binding) == 'table' and type(other) == 'table'
                    and other.axis == binding.axis and other.sign == binding.sign) then
                profile[group][name] = previous
            end
        end
        profile[capture.group][capture.name] = binding
    end
    self._dirty = true
    self:_cancelCapture()
end

function M:_reload()
    local name = 'platform.launcher'
    local previous = package.loaded[name]
    local replacement
    package.loaded[name] = nil
    local ok, err = pcall(function()
        -- XFileUtils caches script bytes separately from Lua's module cache.
        local path = debug.getinfo(M._reload, 'S').source:match('^@(.+)$')
        if path then
            local resources = lstg.ResourceMgr:getInstance()
            resources:removeLocalFileCache(path)
            for _, pack in ipairs(resources:getResourcePacks()) do pack:removeFileCache(path) end
        end
        local launcher = require(name)
        -- Keep the shared layer and font atlas across reloads.
        launcher._font = M._font
        replacement = launcher(self:getApp(), self:getName())
        replacement._layer = self._layer
        replacement._attempted = self._attempted
        if self._loaded then replacement:setModLoaded() end
    end)
    if not ok then
        package.loaded[name] = previous
        if replacement then replacement:cleanup() end
        error(err, 0)
    end
    if self._attempted and not self._loaded then
        replacement._status, replacement._error = self._status, true
    else
        replacement._status = tr('Launcher reloaded. Unsaved edits discarded.', '启动器已重载，未保存的更改已丢弃。')
    end
    local parent, order = self:getParent(), self:getLocalZOrder()
    -- Exit/cleanup the old view before entering the new one so visibility,
    -- statistics, keyboard listeners and render callbacks stay balanced.
    self:removeSelf()
    parent:addChild(replacement, order)
end

function M:_refreshMods()
    local selected = self._selected or setting.mod_info
    local ok, result = pcall(M.enumMods, plus.getWritablePath() .. 'mod/')
    self._mods, self._selected = ok and result or {}, nil
    if not ok then
        self._status, self._error = tostring(result), true
        SystemLog('Launcher: ' .. self._status)
    end
    for _, mod in ipairs(self._mods) do
        if mod.name == (selected and selected.name or setting.mod)
                and (not selected or mod.isDirectory == selected.isDirectory) then
            self._selected = mod
            break
        end
    end
    self._selected = self._selected or self._mods[1]
end

function M:_apply()
    local draft = self._draft
    assert(draft.username:match('%S'), tr('Player name cannot be empty.', '玩家名称不能为空。'))
    assert(draft.windowsize_w >= 640 and draft.windowsize_w <= 7680
            and draft.windowsize_h >= 360 and draft.windowsize_h <= 4320,
            tr('Window size must be within 640x360 and 7680x4320.', '窗口大小须在 640×360 至 7680×4320 之间。'))
    -- Keep existing custom render dimensions unless ratio/height was edited.
    local changedVideo = draft.windowsize_w ~= setting.windowsize_w
            or draft.windowsize_h ~= setting.windowsize_h or draft.windowed ~= setting.windowed
            or draft.vsync ~= setting.vsync
    if changedVideo then
        local ok, err = ChangeVideoMode(draft.windowsize_w, draft.windowsize_h, draft.windowed, draft.vsync)
        assert(ok, tr('Cannot apply video mode: ', '无法应用显示模式：') .. tostring(err))
    end
    for _, name in ipairs(preferences) do setting[name] = copy(draft[name]) end
    SetBGMVolume(setting.bgmvolume / 100)
    SetSEVolume(setting.sevolume / 100)
    SetFPS(setting.render_skip == 1 and 30 or 60)
    gamepad.loadFromSetting()
    M.saveSetting()
    self._draft = self:_readPreferences(setting)
    self._dirty = false
    self._status = tr('Settings applied and saved.', '设置已应用并保存。')
end

function M:_loadMod()
    if self._attempted or not self._selected then return end
    self:_apply()
    setting.mod, setting.mod_info = self._selected.name, copy(self._selected)
    M.saveSetting()
    -- A failed root.lua can still mutate globals. Never load a second MOD.
    self._attempted = true
    require('app.views.GameScene')
    local ok, err = pcall(lstg.loadMod)
    if not ok then
        error(tr('MOD loading failed; restart the application.\n', 'MOD 加载失败，请重启程序。\n') .. tostring(err))
    end
    self:setModLoaded()
    if lstg._exlauncher then self:_startGame() end
end

-- Adopt an already loaded MOD without executing root.lua again.
function M:setModLoaded()
    self._attempted = true
    self._draft = self:_readPreferences(setting)
    if lstg._exlauncher then
        self._loaded = true
        return
    end
    local content = require('game.content')
    content._reset()
    self._ranks, self._rankNames = {}, {}
    if stage and stage.groups then self._ranks, self._rankNames = content.enumRanks() end
    self._players = player_list and content.enumPlayers() or {}
    self._rank = self._ranks[1]
    for _, rank in ipairs(self._ranks) do
        if rank == scoredata.difficulty_select then self._rank = rank end
    end
    self._player = math.min(math.max(scoredata.player_select or 1, 1), #self._players)
    self._loaded = true
    self:_refreshChoices()
    self._status = tr('MOD loaded. Choose difficulty and player.', 'MOD 已加载，请选择难度与玩家。')
end

function M:_refreshChoices()
    local content = require('game.content')
    self._stages = content.enumStages(self._rank)
    self._stage = #self._stages > 0 and math.min(self._stage or 1, #self._stages) or nil
    self._spells = content.enumSpells()
    self._spell = #self._spells > 0 and math.min(self._spell or 1, #self._spells) or nil
    if ext and ext.replay then
        self._replays = content.enumReplays()
    else
        self._replays = {}
    end
    self._replay = #self._replays > 0 and math.min(self._replay or 1, #self._replays) or nil
    self._replayStage = 1
end

function M:_canStart()
    if lstg._exlauncher then return true end
    if self._mode == 'replay' then return self._replay ~= nil end
    if not self._player or self._player < 1 then return false end
    if self._mode == 'spell' then return self._spell ~= nil end
    if not self._rank then return false end
    return self._mode ~= 'stage' or self._stage ~= nil
end

function M:_startGame()
    assert(self:_canStart(), tr('Complete the game selection first.', '请先完成游戏内容选择。'))
    self:_apply()
    if not lstg._exlauncher then
        local content = require('game.content')
        local ok, err
        lstg.practice = nil
        cheat = (self._mode == 'stage' or self._mode == 'spell') and self._cheat or false
        if self._mode == 'replay' then
            ok, err = content.setReplay(self._replays[self._replay], self._replayStage)
            assert(ok, err)
        else
            ok, err = content.setPlayer(self._player)
            assert(ok, err or tr('Select a player.', '请选择玩家。'))
            if self._mode == 'spell' then
                ok, err = content.setSpell(self._spells[self._spell].index)
            else
                ok, err = content.setRank(self._rank)
                assert(ok, err or tr('Select a difficulty.', '请选择难度。'))
                if self._mode == 'stage' then ok, err = content.setStage(self._stage) end
            end
            assert(ok, err)
        end
    end
    require('app.views.GameScene'):create(nil, setting.mod):showWithScene()
end

function M:_renderGameSelection()
    local modes = { 'game', 'stage', 'spell', 'replay' }
    local labels = { tr('Full game', '普通游戏'), tr('Stage practice', '关卡练习'),
        tr('Spell practice', '符卡练习'), tr('Watch replay', '回放观看') }
    local current = 1
    for i, mode in ipairs(modes) do if mode == self._mode then current = i end end
    combo(tr('Mode', '游戏模式'), labels[current], labels, current, function(i)
        self._mode = modes[i]
        self:_queue(function() self:_refreshChoices() end)
    end)
    if self._mode == 'game' or self._mode == 'stage' then
        local rankLabels, rankIndex = {}, 0
        for i, rank in ipairs(self._ranks) do
            rankLabels[i] = tostring(self._rankNames[rank])
            if rank == self._rank then rankIndex = i end
        end
        combo(tr('Difficulty', '难度'), rankLabels[rankIndex] or '-', rankLabels, rankIndex, function(i)
            self._rank = self._ranks[i]
            self:_queue(function() self:_refreshChoices() end)
        end)
    end
    if self._mode ~= 'replay' then
        local names = {}
        for i, player in ipairs(self._players) do names[i] = tostring(player[1]) end
        combo(tr('Player', '玩家'), names[self._player] or '-', names, self._player,
                function(i) self._player = i end)
    end
    if self._mode == 'stage' then
        combo(tr('Stage', '关卡'), self._stages[self._stage] or '-', self._stages, self._stage,
                function(i) self._stage = i end)
        if #self._stages == 0 then hint(tr('This difficulty has no practice stages.', '此难度没有开放练习的关卡。')) end
    elseif self._mode == 'spell' then
        local spells = {}
        for i, spell in ipairs(self._spells) do spells[i] = ('No.%d  %s'):format(spell.index, spell.name) end
        combo(tr('Spell card', '符卡'), spells[self._spell] or '-', spells, self._spell,
                function(i) self._spell = i end)
        if #spells == 0 then hint(tr('This MOD has no practice spell cards.', '此 MOD 没有开放练习的符卡。')) end
    elseif self._mode == 'replay' then
        if im.button(tr('Refresh replays', '刷新回放')) then self:_queue(function() self:_refreshChoices() end) end
        local names = {}
        for i, replay in ipairs(self._replays) do
            names[i] = ('No.%02d  %s  %s  %s'):format(replay.index, replay.user, replay.date_str, replay.rank_str)
        end
        combo(tr('Replay', '回放'), names[self._replay] or '-', names, self._replay, function(i)
            self._replay, self._replayStage = i, 1
        end)
        local replay = self._replays[self._replay]
        if replay then
            local stages = {}
            for i, entry in ipairs(replay.stages) do stages[i] = entry[1] end
            combo(tr('Start stage', '起始关卡'), stages[self._replayStage] or '-', stages, self._replayStage,
                    function(i) self._replayStage = i end)
            hint(('%s / %s / %s / %s: %d'):format(replay.player, replay.date_str, replay.time_str,
                    tr('Score', '得分'), replay.total_score))
        else
            hint(tr('No replays yet. Save a replay after a game, then refresh.', '尚无回放。游戏结束后保存录像，再点击刷新。'))
        end
    end
    if self._mode == 'stage' or self._mode == 'spell' then
        local changed, value = im.checkbox(tr('Practice invincibility', '练习无敌'), self._cheat or false)
        if changed then self._cheat = value end
    end
    if not self:_canStart() then hint(tr('Select available game content to start.', '请选择可用的游戏内容后开始。')) end
end

function M:_renderModPage()
    heading(self._loaded and 'Ready to play' or 'Your MOD library', self._loaded and '准备开始' or '选择 MOD')
    if self._attempted then
        text(tr('Loaded MOD: ', '当前 MOD：') .. setting.mod)
        hint(tr('Restart the application to switch MODs.', '切换 MOD 需要重新启动程序。'))
        if not self._loaded then return end
        if not lstg._exlauncher then self:_renderGameSelection() end
        im.spacing()
        im.beginDisabled(not self:_canStart())
        if im.button(tr('Start game', '开始游戏')) then
            self:_queue(function() self:_startGame() end)
        end
        im.endDisabled()
        return
    end
    im.setNextItemWidth(math.max(120, im.getContentRegionAvail().x - 110))
    local changed
    changed, self._filter = im.inputText('##mod_search', self._filter)
    im.sameLine()
    if im.button(tr('Refresh', '刷新'), im.p(94, 0)) then self:_refreshMods() end
    local empty = #self._mods == 0
    local help = empty and tr('Add a MOD to the directory below, then refresh. Folders and ZIP archives are supported.',
            '请将 MOD 放入下方目录，然后刷新。支持包含 root.lua 的目录及 ZIP 压缩包。')
            or tr('Search by name. Folders and ZIP archives are supported.',
                   '输入名称筛选，支持包含 root.lua 的目录及 ZIP 压缩包。')
    -- Keep the footer consistent with its measurements if selection changes below.
    local mod = self._selected
    local path = plus.getWritablePath() .. 'mod/'
    local selection = mod and (tr('Selected: ', '已选择：') .. mod.name) or tr('Nothing selected', '尚未选择')
    local kind = mod and (mod.isDirectory and tr('Folder MOD', '目录 MOD') or tr('ZIP archive', 'ZIP 压缩包'))
    local style = im.getStyle()
    local spacing = style.ItemSpacing.y
    local footerHeight = textHeight(help, true) + textHeight(path, true) + textHeight(selection)
            + im.getFrameHeight() + spacing * 4
    if kind then footerHeight = footerHeight + textHeight(kind, true) + spacing end
    local rowHeight = math.max(36, im.getTextLineHeight())
    local minimumHeight = rowHeight + 2 * (style.WindowPadding.y + style.ChildBorderSize)
    -- Keep one item visible and let the outer page scroll any overflowing footer.
    local height = math.max(minimumHeight, im.getContentRegionAvail().y - footerHeight)
    local count = 0
    if im.beginChild('mod_list', im.p(0, height), true) then
        for i, mod in ipairs(self._mods) do
            if mod.name:lower():find(self._filter:lower(), 1, true) then
                count = count + 1
                im.pushID(i)
                if im.selectable(mod.name .. '###mod', self._selected == mod, 0, im.p(0, rowHeight)) then
                    self._selected = mod
                end
                im.popID()
            end
        end
        if count == 0 then
            hint(empty and tr('No MODs found.', '未发现 MOD。') or tr('No matches.', '没有匹配的 MOD。'))
        end
    end
    im.endChild()
    hint(help)
    hint(path)
    text(selection)
    if kind then hint(kind) end
    im.beginDisabled(not mod)
    if im.button(tr('Load selected MOD', '加载所选 MOD')) then
        self:_queue(function() self:_loadMod() end)
    end
    im.endDisabled()
end

function M:_checkbox(label, name)
    local changed, value = im.checkbox(label, self._draft[name])
    if changed then self._draft[name], self._dirty = value, true end
end

function M:_renderSoundPage()
    heading('Audio levels', '音量设置')
    for _, item in ipairs({ { 'bgmvolume', 'BGM volume', '背景音乐' }, { 'sevolume', 'SE volume', '音效' } }) do
        im.setNextItemWidth(math.min(400, im.getContentRegionAvail().x))
        local changed, value = im.sliderInt(tr(item[2], item[3]), self._draft[item[1]], 0, 100, '%d%%')
        if changed then self._draft[item[1]], self._dirty = value, true end
    end
    hint(tr('Set a volume to 0 to mute it. Save settings to apply audio levels.', '音量设为 0 即可静音；保存设置后应用音量。'))
end

function M:_renderGraphPage()
    heading('Display settings', '画面设置')
    local draft = self._draft
    self:_checkbox(tr('Windowed', '窗口模式'), 'windowed')
    combo(tr('Window preset', '窗口预设'), ('%d x %d'):format(draft.windowsize_w, draft.windowsize_h),
            { '854 x 480', '1280 x 720', '1708 x 960', '1920 x 1080', '2560 x 1440' }, nil, function(i)
                local sizes = { { 854, 480 }, { 1280, 720 }, { 1708, 960 }, { 1920, 1080 }, { 2560, 1440 } }
                draft.windowsize_w, draft.windowsize_h = unpack(sizes[i])
                self._dirty = true
            end)
    for _, item in ipairs({ { 'windowsize_w', 'Width', '窗口宽度' }, { 'windowsize_h', 'Height', '窗口高度' } }) do
        im.setNextItemWidth(200)
        local changed, value = im.inputInt(tr(item[2], item[3]), draft[item[1]], 2, 100)
        if changed then draft[item[1]], self._dirty = value, true end
    end
    hint(tr('Window dimensions are used in windowed mode. Save to apply.', '窗口尺寸用于窗口模式，保存后应用。'))
    im.spacing()
    local ratios = { { 16, 9 }, { 4, 3 }, { 16, 10 } }
    combo(tr('Game aspect ratio', '游戏画面比例'), table.concat(draft.res_ratio, ':'), { '16:9', '4:3', '16:10' }, nil,
            function(i)
                draft.res_ratio = copy(ratios[i])
                draft.resx = math.ceil(draft.resy * ratios[i][1] / ratios[i][2] / 2) * 2
                self._dirty = true
            end)
    combo(tr('Game resolution', '游戏分辨率'), ('%d x %d'):format(draft.resx, draft.resy),
            { '480p', '720p', '960p', '1080p', '1440p' }, nil, function(i)
                draft.resy = ({ 480, 720, 960, 1080, 1440 })[i]
                draft.resx = math.ceil(draft.resy * draft.res_ratio[1] / draft.res_ratio[2] / 2) * 2
                self._dirty = true
            end)
    self:_checkbox(tr('Vertical sync', '垂直同步'), 'vsync')
    self:_checkbox(tr('Post effects', '后处理效果'), 'posteffect')
    combo(tr('Render rate', '渲染帧率'), draft.render_skip == 1 and '30 FPS' or '60 FPS',
            { '60 FPS', '30 FPS' }, draft.render_skip + 1, function(i)
                draft.render_skip, self._dirty = i - 1, true
            end)
    hint(tr('Game resolution and post effects take effect when entering a game. Simulation remains at 60 FPS.',
            '游戏分辨率和后处理在进入游戏时生效。游戏逻辑保持每秒60帧。'))
end

function M:_renderInputPage()
    heading('Keyboard and controller', '键盘与手柄')
    hint(tr('Click a binding, then press a key or move a controller axis. Escape cancels. Duplicate bindings swap.',
            '点击映射后按键，或拨动手柄轴；Esc 取消。重复映射会自动交换。'))
    if self._capture then
        im.textColored(accent, tr('Waiting for input...', '等待输入……'))
        im.sameLine()
        if im.button(tr('Cancel', '取消')) then self:_cancelCapture() end
    end
    local pad = self:_renderGamepadDevices()
    im.spacing()
    im.columns(3, 'bindings', true)
    text(tr('Action', '操作')); im.nextColumn()
    text(tr('Keyboard', '键盘')); im.nextColumn()
    text(tr('Controller', '手柄')); im.nextColumn()
    im.separator()
    for i, action in ipairs(actions) do
        local group, name = action[1], action[2]
        im.pushID(i)
        im.alignTextToFramePadding()
        text(tr(action[3], action[4])); im.nextColumn()
        local code = self._draft[group][name]
        if im.button(keyNames[code] or tostring(code), im.p(-1, 0)) then
            self:_beginCapture({ kind = 'keyboard', group = group, name = name })
        end
        im.nextColumn()
        local logical = self._draft.gamepad_actions[group][name]
        local label = gamepad.bindLabel(pad, logical)
        if pad and pad:mapped() then
            if im.button(label .. '###gamepad', im.p(-1, 0)) then
                self:_beginCapture({ kind = 'controller', group = group, name = name })
            end
        else text(label) end
        im.nextColumn()
        im.popID()
    end
    im.columns(1)
    im.spacing()
    if im.button(tr('Reset input bindings', '恢复默认输入映射')) then
        for _, name in ipairs({ 'keys', 'keysys', 'gamepad_actions' }) do
            self._draft[name] = copy(default_setting[name])
        end
        self._dirty = true
        self:_cancelCapture()
    end
end

function M:_renderGamepadDevices()
    local frame = gp.frame()
    local ids, labels = frame:devices(), {}
    local slot = self._draft.gamepad_actions.slot or 0
    local selected
    for index, id in ipairs(ids) do
        local pad = frame:find(id)
        labels[index] = ('%s #%d'):format(pad:info().name, id)
        if id == self._gamepadDevice then selected = index end
    end
    if not frame:find(self._gamepadDevice or 0) then
        self._gamepadDevice = nil
        for index, id in ipairs(ids) do
            if frame:find(id):player() == slot then
                selected, self._gamepadDevice = index, id
                break
            end
        end
    end
    if #ids == 0 then
        text(tr('No gamepads connected.', '未连接手柄。'))
    else
        combo(tr('Device', '设备'), labels[selected] or tr('Select a gamepad', '选择手柄'), labels, selected, function(index)
            self:_cancelCapture()
            self._gamepadDevice = ids[index]
        end)
    end
    local id = self._gamepadDevice
    local pad = id and frame:find(id)
    if pad then
        local info = pad:info()
        text(pad:mapped() and (info.mappingName ~= '' and info.mappingName or info.name)
            or tr('Raw controls · learn a hardware mapping', '原始输入 · 请学习硬件映射'))
        if pad:mapped() and im.button(tr('Use for player 1', '分配给玩家 1')) then
            if pad:player() == nil or pad:player() == slot then
                for _, other in ipairs(ids) do
                    if other ~= id and frame:find(other):player() == slot then gp.clearPlayer(other) end
                end
                local ok, err = gp.assignPlayer(id, slot)
                if ok then
                    self._draft.gamepad_preferred, self._dirty = gamepad.identity(info), true
                else
                    self._status, self._error = tostring(err), true
                end
            end
        end
        if pad:hasFeature(gp.Feature.BodyRumble) then
            im.sameLine()
            if im.button(tr('Test vibration', '试振')) then
                local command, err = gp.rumble(id, 0.3, 0.5, 200)
                if command then self._rumbleTest = { device = id, command = command }
                else self._status, self._error = tostring(err), true end
            end
        end
        local controls = gamepad.hardwareButtons
        local target = self._hardwareTarget or 1
        local names = {}
        for i, control in ipairs(controls) do names[i] = gamepad.bindLabel(pad, control) end
        combo(tr('Logical button', '逻辑键'), names[target], names, target, function(i) self._hardwareTarget = i end)
        if im.button(tr('Learn raw control', '学习原始控件')) then
            self:_beginCapture({ kind = 'hardware', name = controls[self._hardwareTarget or 1] })
        end
        if self._draft.gamepad_hardware[gamepad.identity(info)] then
            im.sameLine()
            if im.button(tr('Reset hardware mapping', '还原硬件映射')) then
                self._draft.gamepad_hardware[gamepad.identity(info)] = nil
                self._dirty = true
                self:_cancelCapture()
            end
        end
    end
    local profile = self._draft.gamepad_actions
    if not profile.legacyReviewed then
        local preview, missing = gamepad.migration(setting)
        if preview then
            local done = {}
            for _, action in ipairs(actions) do
                local group, name = action[1], action[2]
                local control = preview[group][name]
                if control then done[#done + 1] = tr(action[3], action[4]) .. ' → ' .. gamepad.bindLabel(pad, control) end
            end
            if #done > 0 then text(table.concat(done, ', ')) end
            if #missing > 0 then
                hint(tr('Rebind ambiguous legacy controls for ', '请重新绑定旧设置中的这些动作 ') .. table.concat(missing, ', '))
            end
            if #done > 0 and im.button(tr('Use recognised legacy bindings', '采用已识别的旧映射')) then
                for _, group in ipairs({ 'keys', 'keysys' }) do
                    for name, value in pairs(preview[group]) do profile[group][name] = value end
                end
                profile.legacyReviewed, self._dirty = true, true
            end
        end
    end
    return pad
end

function M:_renderOthersPage()
    heading('General preferences', '常规设置')
    im.setNextItemWidth(math.min(320, im.getContentRegionAvail().x))
    local changed, value = im.inputText(tr('Player name', '玩家名称'), self._draft.username)
    if changed then self._draft.username, self._dirty = value, true end
    self:_checkbox(tr('Allow screenshots', '允许截图'), 'allowsnapshot')
    if plus.isMobile() then
        self:_checkbox(tr('Touch controls', '触摸按键'), 'touchkey')
        combo(tr('Orientation', '屏幕方向'), self._draft.orientation,
                { tr('Landscape', '横屏'), tr('Portrait', '竖屏') }, nil, function(i)
                    self._draft.orientation = i == 1 and 'landscape' or 'portrait'
                    self._dirty = true
                end)
    end
    im.spacing()
    hint(tr('Settings file', '设置文件'))
    text(plus.getWritablePath() .. 'setting')
    hint(tr('Save applies changes. Revert discards unsaved edits. Defaults only resets launcher preferences.',
            '保存将应用更改；撤销将放弃未保存的编辑；恢复默认仅重置启动器设置。'))
end

function M:_renderAboutPage()
    require('imgui.ui.About').renderContent()
end

function M:_render()
    local font = M._font
    local viewport = im.getMainViewport()
    im.setNextWindowPos(viewport.Pos)
    im.setNextWindowSize(viewport.Size)
    im.setNextWindowViewport(viewport.ID)
    if font then im.pushFont(font) end
    im.pushStyleVar(im.StyleVar.WindowPadding, im.p(24, 20))
    im.pushStyleVar(im.StyleVar.ItemSpacing, im.p(12, 10))
    im.pushStyleVar(im.StyleVar.FramePadding, im.p(10, 7))
    im.pushStyleVar(im.StyleVar.FrameRounding, 5)
    im.pushStyleVar(im.StyleVar.WindowRounding, 0)
    im.pushStyleVar(im.StyleVar.SelectableTextAlign, im.p(0, 0.5))
    local colors = {
        { im.Col.Text, im.vec4(0.90, 0.90, 0.90, 1) },
        { im.Col.TextDisabled, muted },
        { im.Col.WindowBg, im.vec4(0.09, 0.09, 0.09, 1) },
        { im.Col.ChildBg, im.vec4(0.12, 0.12, 0.12, 1) },
        { im.Col.PopupBg, im.vec4(0.14, 0.14, 0.14, 1) },
        { im.Col.Border, im.vec4(0.27, 0.27, 0.27, 1) },
        { im.Col.FrameBg, im.vec4(0.18, 0.18, 0.18, 1) },
        { im.Col.FrameBgHovered, im.vec4(0.26, 0.26, 0.26, 1) },
        { im.Col.FrameBgActive, im.vec4(0.32, 0.32, 0.32, 1) },
        { im.Col.Button, im.vec4(0.22, 0.22, 0.22, 1) },
        { im.Col.ButtonHovered, im.vec4(0.30, 0.30, 0.30, 1) },
        { im.Col.ButtonActive, im.vec4(0.38, 0.38, 0.38, 1) },
        { im.Col.Header, im.vec4(0.28, 0.28, 0.28, 1) },
        { im.Col.HeaderHovered, im.vec4(0.34, 0.34, 0.34, 1) },
        { im.Col.HeaderActive, im.vec4(0.40, 0.40, 0.40, 1) },
        { im.Col.CheckMark, accent }, { im.Col.SliderGrab, accent },
        { im.Col.SliderGrabActive, im.vec4(0.94, 0.94, 0.94, 1) },
        { im.Col.ScrollbarBg, im.vec4(0.10, 0.10, 0.10, 1) },
        { im.Col.ScrollbarGrab, im.vec4(0.30, 0.30, 0.30, 1) },
        { im.Col.ScrollbarGrabHovered, im.vec4(0.40, 0.40, 0.40, 1) },
        { im.Col.ScrollbarGrabActive, im.vec4(0.50, 0.50, 0.50, 1) },
        { im.Col.Separator, im.vec4(0.27, 0.27, 0.27, 1) },
        { im.Col.TextSelectedBg, im.vec4(0.45, 0.45, 0.45, 0.55) },
    }
    for _, color in ipairs(colors) do im.pushStyleColor(color[1], color[2]) end
    local flags = bit.bor(im.WindowFlags.NoDecoration, im.WindowFlags.NoMove,
            im.WindowFlags.NoSavedSettings, im.WindowFlags.NoDocking)
    if im.begin('LuaSTG-x Launcher', nil, flags) then
        im.textColored(accent, 'LuaSTG-x')
        im.sameLine()
        hint(tr('GAME LAUNCHER', '游戏启动器'))
        im.separator()
        -- Button actions may change the status; render the text measured this frame.
        local status = self._status
        local footerHeight = im.getFrameHeight() + textHeight(status, true) + im.getStyle().ItemSpacing.y * 3
        local height = math.max(4, im.getContentRegionAvail().y - footerHeight)
        local sidebar = math.min(180, viewport.Size.x * 0.24)
        if im.beginChild('navigation', im.p(sidebar, height), true) then
            im.spacing()
            for _, page in ipairs(pages) do
                if im.selectable(tr(page[2], page[3]) .. '###' .. page[1], self._page == page[1], 0, im.p(0, 40)) then
                    self._page = page[1]
                    self:_cancelCapture()
                end
            end
        end
        im.endChild()
        im.sameLine()
        if im.beginChild('page', im.p(0, height), true) then
            local render = { mod = self._renderModPage, graph = self._renderGraphPage,
                sound = self._renderSoundPage, input = self._renderInputPage,
                others = self._renderOthersPage, about = self._renderAboutPage }
            render[self._page](self)
        end
        im.endChild()
        im.separator()
        im.beginDisabled(self._pending ~= nil)
        if im.button(tr('Save settings', '保存设置')) then self:_queue(function() self:_apply() end) end
        im.sameLine()
        if im.button(tr('Revert', '撤销更改')) then
            self._draft = self:_readPreferences(setting)
            self._dirty = false
            self:_cancelCapture()
            self._status, self._error = tr('Unsaved edits discarded.', '已撤销未保存的更改。'), false
        end
        im.sameLine()
        if im.button(tr('Defaults', '恢复默认')) then
            self._draft = self:_readPreferences(default_setting)
            self._dirty = true
            self:_cancelCapture()
        end
        im.sameLine()
        if im.button(tr('Exit', '退出')) then self:_queue(GameExit) end
        im.endDisabled()
        if self._dirty then
            im.sameLine()
            im.textColored(accent, tr('Unsaved changes', '有未保存的更改'))
        end
        im.pushStyleColor(im.Col.Text, self._error and im.vec4(1, 0.52, 0.42, 1) or muted)
        im.pushTextWrapPos(0)
        text(status)
        im.popTextWrapPos()
        im.popStyleColor()
    end
    im.endToLua()
    im.popStyleColor(#colors)
    im.popStyleVar(6)
    if font then im.popFont() end
end

function M.enumMods(path)
    return require('platform.util').enumMods(path)
end

function M.saveSetting()
    return lstg.saveSettingFile()
end

return M
