---
---
--- launcher_ui.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---


local FU = cc.FileUtils:getInstance()
local glv = cc.Director:getInstance():getOpenGLView()
local launcher_reader
---@type cc.Scene
local launcher_scene
local lc

local function enumMods(path)
    SystemLog(string.format('enum MODs in %q', path))
    local ret = {}
    local files = plus.EnumFiles(path)
    for i, v in ipairs(files) do
        if v.isDirectory then
            if plus.FileExists(path .. v.name .. '/root.lua') then
                table.insert(ret, v)
            end
        else
            if string.lower(v.name:match(".+%.(%w+)$") or '') == 'zip' then
                v.name = v.name:sub(1, -5)
                assert(v.name ~= '')
                table.insert(ret, v)
            end
        end
    end
    table.sort(ret, function(a, b)
        if a.isDirectory ~= b.isDirectory then
            return a.isDirectory
        end
        return a.name < b.name
    end)
    return ret
end

local function saveSetting()
    lstg.saveSettingFile()
end

local contents = {
    'mod',
    'sound',
    'graph',
    'input',
    'others',
}
local function hideContents()
    if not lc then
        return
    end
    for _, v in ipairs(contents) do
        lc[v]:setVisible(false)
    end
end
local function unsel_btns()
    for _, v in ipairs(contents) do
        lc['btn_' .. v]:setColor(cc.c3b(51, 51, 51))
    end
end

local getChildrenWithName = require('cc.children_helper').getChildrenWithName
--local getChildrenGraph = require('cc.children_helper').getChildrenGraph
local createItem = require('cc.selectable_item').create

local function createModItem()
    return createItem(cc.size(800, 80), nil, nil, 60)
end

local scene_tasks = {}

--

local function setMod(lc)
    local mod_scv = lc.mod_scv
    mod_scv:setLayoutType(ccui.LayoutType.VERTICAL)
    for i, v in ipairs(enumMods(plus.getWritablePath() .. 'mod/')) do
        local item = createModItem()
        item.mod_name = v.name
        item.mod_info = v
        item.lb:setString(v.name or 'UNKNOWEN')
        if v.isDirectory then
            item.lb:setColor(cc.c3b(255, 255, 127))
        end
        item.btn:addTouchEventListener(function(t, e)
            if e == 0 then
                if not item.is_selected then
                    for _, vv in ipairs(lc.mod_scv:getChildren()) do
                        if vv.setSelected then
                            vv:setSelected(false)
                        end
                    end
                    setting.mod = item.mod_name
                    setting.mod_info = item.mod_info
                    --SystemLog('set setting.mod to ' .. setting.mod)
                end
                --item:setSelected(not item.is_selected)
                item:setSelected(true)
                lc.mod_start_btn:setVisible(true)
            end
        end)

        mod_scv:addChild(item)
        local num = mod_scv:getChildrenCount()
        mod_scv:setInnerContainerSize(cc.size(800, num * 80))
    end

    lc.mod_start_btn:setVisible(false)
    lc.mod_start_btn:addClickEventListener(function()
        -- require here, make it can be overridden
        local scene = require('app.views.GameScene'):create(nil, setting.mod)
        saveSetting()
        lstg.loadMod()
        if lstg._exlauncher then
            SystemLog('use external launcher')
            scene:showWithScene()
        else
            local launcher = require('platform.launcher')()
            launcher:setModLoaded()
            launcher:showWithScene()
        end
    end)
end

local function setSound(lc)
    lc.mute_content:setVisible(false)--TODO
    lc.bgm_sl:setPercent(math.floor(setting.bgmvolume))
    lc.se_sl:setPercent(math.floor(setting.sevolume))
    lc.bgm_lb:setString(string.format('%d%%', setting.bgmvolume))
    lc.se_lb:setString(string.format('%d%%', setting.sevolume))
    lc.bgm_sl:addEventListener(function(t, e)
        if e == 0 then
            setting.bgmvolume = lc.bgm_sl:getPercent()
            lc.bgm_lb:setString(string.format('%d%%', setting.bgmvolume))
        end
    end)
    lc.se_sl:addEventListener(function(t, e)
        if e == 0 then
            setting.sevolume = lc.se_sl:getPercent()
            lc.se_lb:setString(string.format('%d%%', setting.sevolume))
        end
    end)
end

local function setGraph(lc)
    --note: set selection by togglegroup
    local ratio = setting.res_ratio[1] / setting.res_ratio[2]
    local tgname = 'res_ratio_tg'
    for i, v in ipairs({ { 16, 9 }, { 4, 3 } }) do
        local tg = lc[tgname .. i]
        if ratio == v[1] / v[2] then
            lc[tgname .. 'g']:setSelectedButtonWithoutEvent(tg)
        end
        tg:addEventListener(function(t, e)
            if e == 0 then
                setting.res_ratio = v
                setting.windowsize_w = math.ceil(setting.windowsize_h * ratio / 2) * 2
                if plus.isDesktop() then
                    --glv:setFrameSize(setting.windowsize_w, setting.windowsize_h)
                    ChangeVideoMode(
                            setting.windowsize_w,
                            setting.windowsize_h,
                            setting.windowed,
                            setting.vsync
                    )
                end
            end
        end)
    end

    tgname = 'res_tg'
    for i, v in ipairs({ 960, 720, 480 }) do
        local tg = lc[tgname .. i]
        if setting.resy == v then
            lc[tgname .. 'g']:setSelectedButtonWithoutEvent(tg)
        end
        tg:addEventListener(function(t, e)
            if e == 0 then
                setting.resy = v
            end
        end)
    end

    lc.pe_tg:setSelected(setting.posteffect == true)
    lc.pe_tg:addEventListener(function(t, e)
        if e == 0 then
            setting.posteffect = true
        elseif e == 1 then
            setting.posteffect = false
        end
    end)
    lc.vsync_tg:setSelected(setting.vsync == true)
    lc.vsync_tg:addEventListener(function(t, e)
        if e == 0 then
            setting.vsync = true
        elseif e == 1 then
            setting.vsync = false
        end
    end)

    lc.fps_tg1:setSelected(setting.render_skip == 0)
    lc.fps_tg1:addEventListener(function(t, e)
        if e == 0 then
            lc.fps_tg2:setSelected(false)
            setting.render_skip = 0
            SetFPS(60)
        end
    end)
    lc.fps_tg2:setSelected(setting.render_skip == 1)
    lc.fps_tg2:addEventListener(function(t, e)
        if e == 0 then
            lc.fps_tg1:setSelected(false)
            setting.render_skip = 1
            SetFPS(30)
        end
    end)
end

local ctr_btns = {
    'up',
    'down',
    'left',
    'right',
    'shoot',
    'slow',
    'spell',
    'special',
    'menu',
    'repfast',
    'repslow',
    'snapshot',
}
local gamepad = require('platform.GamepadActions')
local gp = require('cocos.cocos2d.Gamepad')

local function unsel_ctr_btns(lc)
    for _, v in ipairs(ctr_btns) do
        lc['btn_ctr_' .. v]:setSelect(false)
    end
    scene_tasks[1] = nil
end

local function setInput(lc)
    local function current()
        local frame = gp.frame()
        local slot = setting.gamepad_actions.slot or 0
        for _, id in ipairs(frame:devices()) do
            local pad = frame:find(id)
            if pad:player() == slot then return frame, pad, id end
        end
        return frame
    end
    for _, name in ipairs(ctr_btns) do
        local btn = lc['btn_ctr_' .. name]
        local group = setting.keys[name] and 'keys' or 'keysys'
        local _, pad = current()
        local label = cc.Label:createWithSystemFont(
            gamepad.bindLabel(pad, setting.gamepad_actions[group][name]), 'Arial', 36)
        local size = btn:getContentSize()
        label:setPosition(cc.p(size.x / 2, size.y / 2))
        btn:addChild(label)
        btn.setSelect = function(self, selected)
            self._sel = selected
            self:setColor(selected and cc.c3b(127, 127, 0) or cc.c3b(51, 51, 51))
        end
        btn:addClickEventListener(function()
            local wasSelected = btn._sel
            unsel_ctr_btns(lc)
            local frame, _, id = current()
            if wasSelected or not id then return end
            local tick = frame:tick()
            btn:setSelect(true)
            scene_tasks[1] = function()
                local nextFrame, nextPad, nextId = current()
                if nextId ~= id then unsel_ctr_btns(lc); return end
                if nextFrame:tick() == tick then return end
                tick = nextFrame:tick()
                local binding = gamepad.learnAction(nextFrame, id)
                if binding then
                    setting.gamepad_actions[group][name] = binding
                    label:setString(gamepad.bindLabel(nextPad, binding))
                    gamepad.loadFromSetting()
                    unsel_ctr_btns(lc)
                end
            end
        end)
    end
end

local function setOthers(lc)
    if plus.isMobile() then
        local tg = (setting.orientation == 'landscape') and lc.ori_tg1 or lc.ori_tg2
        lc.ori_tgg:setSelectedButtonWithoutEvent(tg)
        lc.ori_tg1:addEventListener(function(t, e)
            if e == 0 then
                setting.orientation = 'portrait'
            end
        end)
        lc.ori_tg2:addEventListener(function(t, e)
            if e == 0 then
                setting.orientation = 'landscape'
            end
        end)

        lc.touchkey_tg:setSelected(setting.touchkey == true)
        lc.touchkey_tg:addEventListener(function(t, e)
            if e == 0 then
                setting.touchkey = true
            elseif e == 1 then
                setting.touchkey = false
            end
        end)

        lc.winsize_content:setVisible(false)
    else
        local function applyVideoMode()
            local ratio = 16 / 9
            if setting.res_ratio then
                ratio = setting.res_ratio[1] / setting.res_ratio[2]
            end
            setting.windowsize_w = math.ceil(setting.windowsize_h * ratio / 2) * 2
            ChangeVideoMode(
                    setting.windowsize_w,
                    setting.windowsize_h,
                    setting.windowed,
                    setting.vsync)
        end
        local tgname = 'winsize_tg'
        --glv:setFrameSize(setting.windowsize_w, setting.windowsize_h)
        applyVideoMode()
        for i, v in ipairs({ 960, 720, 480 }) do
            local tg = lc[tgname .. i]
            if setting.windowsize_h == v and setting.windowed then
                lc[tgname .. 'g']:setSelectedButtonWithoutEvent(tg)
            end
            tg:addEventListener(function(t, e)
                if e == 0 then
                    --glv:setFrameSize(setting.windowsize_w, v)
                    setting.windowsize_h = v
                    setting.windowed = true
                    applyVideoMode()
                end
            end)
        end
        local tg = lc['winsize_tg4']
        if not setting.windowed then
            lc[tgname .. 'g']:setSelectedButtonWithoutEvent(tg)
        end
        tg:addEventListener(function(t, e)
            if e == 0 then
                --glv:setFrameSize(setting.windowsize_w, v)
                setting.windowed = false
                applyVideoMode()
            end
        end)

        lc.touchkey_content:setVisible(false)
        lc.ori_content:setVisible(false)
    end
    setting.windowsize_h = setting.windowsize_h
    setting.res_ratio = setting.res_ratio
end

local function CreateLauncherUI()
    if launcher_reader then
        return
    end
    assert(setting)
    launcher_reader = creator.CreatorReader:createWithFilename('creator/Scene/launcher.ccreator')
    launcher_reader:setup()
    launcher_scene = launcher_reader:getSceneGraph()
    launcher_scene:setName('launcher_scene')
    lc = getChildrenWithName(launcher_scene)
    hideContents()
    unsel_btns()

    local sel_color = cc.c3b(128, 128, 64)
    for _, v in ipairs(contents) do
        local btn = lc['btn_' .. v]
        btn:addClickEventListener(function()
            hideContents()
            unsel_btns()
            lc[v]:setVisible(true)
            btn:setColor(sel_color)

            unsel_ctr_btns(lc)
        end)
    end

    lc.btn_exit:addClickEventListener(function()
        hideContents()
        if GameExit then
            GameExit()
        else
            saveSetting()
            os.exit()
        end
    end)

    local title_data = require('platform.launcher_ui_data').title
    local label_data = require('platform.launcher_ui_data').label
    for k, v in pairs(lc) do
        if string.starts_with(k, 'button_') then
            local name = k:sub(8)
            local lb = v:getChildren()[2]
            local s = title_data[name]
            if s and lb then
                lb:setString(i18n(s))
            end
        end
        if label_data[k] then
            v:setString(i18n(label_data[k]))
        end
    end

    setMod(lc)

    setSound(lc)

    setGraph(lc)

    setInput(lc)

    setOthers(lc)

    local inf = 'LuaSTG-x Technical Preview'
    if plus.platform ~= 'unknown' then
        inf = string.format('%s for %s', inf, plus.platform)
    end
    ---@type cc.Label
    local inf_label = lc._warning:getChildren()[1]
    inf_label:setString(inf)

    --local ui_layer = cc.Layer:create()
    --ui_layer:setAnchorPoint(cc.p(0, 0))
    --launcher_scene:addChild(ui_layer)
    --require('platform.controller_ui')(ui_layer)

    --[[
    local sp = video.Player:create('[Touhou 3D] Subterranean Stars.mp4')
    sp:addTo(launcher_scene)
    local sz = sp:getContentSize()
    sp:setPosition(sz.x / 2, sz.y / 2)
    sp:vplay()
    ]]

    --lc._warning:setVisible(false)

    --local p = cc.ParticleSystemQuad:create('particle_texture.plist')
    --if not p then
    --    error("can't load")
    --end
    --p:setPosition(cc.p(800,100))
    --launcher_scene:addChild(p)

    --local sp = require('qrcode.helper').sprite('https://github.com/Xrysnow/LuaSTG-x', 1)
    --sp:addTo(launcher_scene):setPosition(800, 500):setScale(20)

    launcher_scene.update = function(self, dt)
        for i, v in pairs(scene_tasks) do
            v()
        end

        --local last = controllerHelper.getLast()
        --local str = 'nil'
        --if last then
        --    str = string.format('id: %d, key: %d', last.id, last.key)
        --end
        --inf_label:setString(str)

        --if 0 < ts and ts < 0.5 then
        --    model:setParameterValue(param.EyeLOpen,1,1)
        --    model:setParameterValue(param.EyeROpen,0,1)
        --    Print('set param')
        --end
        --[[
        local pminfo = ''
        for i, v in ipairs(pmname) do
            local val = model:getParameterValue(v)
            pminfo = string.format('%s\n%s: %.2f', pminfo, v:sub(6, -1), val)
        end
        _lb:setString(pminfo)
        ]]
    end
    launcher_scene:scheduleUpdateWithPriorityLua(function(dt)
        launcher_scene:update(dt)
    end, 100)

    --SystemLog('before pushScene')
    cc.Director:getInstance():pushScene(launcher_scene)
end

return CreateLauncherUI
