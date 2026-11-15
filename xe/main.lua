---@class xe.main:ViewBase
local M = class('xe.main', cc.load('mvc').ViewBase)
local glv = cc.Director:getInstance():getOpenGLView()
local im = imgui
local wi = require('imgui.Widget')
---@type xe.main
local _instance
local window_flags = bit.bor(
        im.WindowFlags.MenuBar,
        im.WindowFlags.NoDocking,
        im.WindowFlags.NoTitleBar,
        im.WindowFlags.NoCollapse,
        im.WindowFlags.NoResize,
        im.WindowFlags.NoMove,
        im.WindowFlags.NoBringToFrontOnFocus,
        im.WindowFlags.NoNavFocus,
        im.WindowFlags.NoBackground)
---@return xe.main
function M:getInstance()
    return _instance
end

--function M:onEnter()
function M:onCreate()
    _instance = self
    if self._editor then
        return
    end
    self:setVisible(true)
    ---@type cc.Scene
    local scene = display.newScene('xe.main')
    scene:addChild(self)
    display.runScene(scene)
    local la = im.on(scene)
    self._la = la

    setting.xe = setting.xe or {}
    ChangeVideoMode(
            setting.windowsize_w,
            setting.windowsize_h,
            true,
            setting.vsync)

    cc.Director:getInstance():setDisplayStats(false)

    local bg = cc.Sprite:create('xe/background.png')
    local bg_sz
    if bg then
        bg:addTo(scene):setLocalZOrder(-1)
        bg_sz = bg:getContentSize()
    end

    lstg.loadData()
    SetResourceStatus('global')

    --local la = im.get()
    im.show()
    im.clear()

    local dpiScale = lstg.WindowHelper:getInstance():getDpiScale()
    im.getStyle():scaleAllSizes(dpiScale)
    -- FontGlobalScale will cause blur
    --im.getIO().FontGlobalScale = dpiScale

    local cfg = im.ImFontConfig()
    cfg.OversampleH = 2
    cfg.OversampleV = 2
    if dpiScale >= 1.5 then
        cfg.OversampleH = 2
        cfg.OversampleV = 1
    end
    local font_default = im.addFontTTF('font/WenQuanYiMicroHeiMono.ttf', 14 * dpiScale, cfg, {
        --0x0080, 0x00FF, -- Basic Latin + Latin Supplement
        0x2000, 0x206F, -- General Punctuation
        0x3000, 0x30FF, -- CJK Symbols and Punctuations, Hiragana, Katakana
        0x31F0, 0x31FF, -- Katakana Phonetic Extensions
        0xFF00, 0xFFEF, -- Half-width characters
        0x4e00, 0x9FAF, -- CJK Ideograms
        0,
    })
    self._font_default = font_default
    --
    cfg = im.ImFontConfig()
    cfg.OversampleH = 3
    cfg.OversampleV = 3
    cfg.MergeMode = true
    cfg.DstFont = font_default
    im.addFontTTF('font/NotoSansDisplay-Regular.ttf', 18 * dpiScale, cfg, im.GlyphRanges.Default)
    --
    local fa = require('xe.ifont')
    cfg = im.ImFontConfig()
    cfg.OversampleH = 2
    cfg.OversampleV = 2
    cfg.MergeMode = true
    cfg.DstFont = font_default
    cfg.GlyphMinAdvanceX = 12
    cfg.GlyphMaxAdvanceX = 12
    im.addFontTTF('font/' .. fa.FontIconFileName, 14 * dpiScale, cfg, {
        fa.IconMin, fa.IconMax, 0
    })
    --
    cfg = im.ImFontConfig()
    cfg.OversampleH = 2
    cfg.OversampleV = 2
    cfg.MergeMode = false
    local font_mono = im.addFontTTF('font/JetBrainsMono-Regular.ttf', 14 * dpiScale, cfg, {
        0x0020, 0x00FF, -- Basic Latin + Latin Supplement
        0x2000, 0x206F, -- General Punctuation
        0
    })
    self._font_mono = font_mono

    -- Add a CJK fallback source before drawing; JetBrains Mono keeps priority.
    if font_mono then
        cfg = im.ImFontConfig()
        cfg.OversampleH = 2
        cfg.OversampleV = 2
        cfg.MergeMode = true
        cfg.DstFont = font_mono
        im.addFontTTF('font/WenQuanYiMicroHeiMono.ttf', 14 * dpiScale, cfg, {
            0x3000, 0x30FF,
            0x31F0, 0x31FF,
            0xFF00, 0xFFEF,
            0x4e00, 0x9FAF,
        })
    end

    --
    local dock = wi.wrapper(function()
        local viewport = im.getMainViewport()
        im.setNextWindowPos(viewport.Pos)
        im.setNextWindowSize(viewport.Size)
        im.setNextWindowViewport(viewport.ID)
        im.pushStyleVar(im.StyleVar.WindowRounding, 0)
        im.pushStyleVar(im.StyleVar.WindowBorderSize, 0)
        im.pushStyleVar(im.StyleVar.WindowPadding, im.p(0, 0))
        im.begin('Dock Space', nil, window_flags)
        im.popStyleVar(3)
        im.dockSpace(im.getID('xe.dock_space'), im.p(0, 0), im.DockNodeFlags.PassthruCentralNode)

        if bg then
            im.getStyle().Alpha = 0.85
            local fsz = glv:getFrameSize()
            local dl = im.getBackgroundDrawList()
            local pos = im.getWindowPos()
            local scale = math.max(fsz.x / bg_sz.x, fsz.y / bg_sz.y)
            local w = bg_sz.x * scale
            local h = bg_sz.y * scale
            local a = im.vec2((fsz.x - w) / 2, (fsz.y - h) / 2)
            a = cc.pAdd(a, pos)
            local b = cc.pAdd(a, im.vec2(w, h))
            dl:addImage(bg, a, b)
        end
    end, function()
        im.endToLua()
    end)
    dock:addTo(la)

    local menu_bar = wi.MenuBar()
    dock:addChildChain(menu_bar, M._menu)

    self._editor = require('xe.win.SceneEditor')()
    la:addChild(self._editor)

    self._property = require('xe.win.NodeProperty')()
    la:addChild(self._property)

    self._output = require('xe.win.Output')()
    la:addChild(self._output)

    self._watch = require('imgui.ui.VariableWatch').createWindow('Watch##xe')
    la:addChild(self._watch)

    self._console = require('imgui.ui.Console').createWindow('Console##xe')
    la:addChild(self._console)

    self._assets = require('xe.assets.AssetsManager')()
    la:addChild(self._assets)

    -- dialogs

    self._edit_txt = require('xe.input.EditText')()
    self:_addDialog(self._edit_txt)
    self._setting = require('xe.setting.Setting')()
    self:_addDialog(self._setting)
    self._newproj = require('xe.win.NewProject')()
    self:_addDialog(self._newproj)

    self._game_log = require('imgui.ui.LogWindow')()
    local win = require('imgui.widgets.Window')('Log##xe')
    la:addChild(win:addChild(self._game_log))

    im.styleColorsLight()
    self._setting:_applyTheme(setting.xe.theme)
    im.getStyle().FrameBorderSize = 1

    self._about = require('imgui.ui.About')()
    self:_addDialog(self._about)

    la:addChild(M._handleGlobalKeyboard)

    --la:addChild(im.showDemoWindow)
    --la:addChild(im.showStyleEditor)
    --la:addChild(implot.showDemoWindow)

    local e = cc.EventListenerKeyboard:create()
    e:registerScriptHandler(function(k, ev)
        M._kbCode = k
    end, cc.Handler.EVENT_KEYBOARD_PRESSED)
    e:registerScriptHandler(function(k, ev)
        M._kbCode = nil
    end, cc.Handler.EVENT_KEYBOARD_RELEASED)
    cc.Director:getInstance():getEventDispatcher():addEventListenerWithFixedPriority(e, 1)
end

function M:_addDialog(v)
    v:setVisible(false):addTo(self._la)
end

function M._menu()
    local tool = require('xe.ToolMgr')
    local opened = require('xe.Project').getFile() and true or false
    local data = require('xe.menu.data')
    for _, v in ipairs(data) do
        if v.title and im.beginMenu(v.title) then
            for _, item in ipairs(v.content) do
                local f = tool[item.event or '']
                local enabled = opened or not item.need_proj
                if im.menuItem(i18n(item.title), item.shortcut, false, enabled) and f then
                    f()
                end
            end
            im.endMenu()
        end
    end
    --local fsz = glv:getFrameSize()
    --im.text(('(%d, %d)'):format(fsz.x, fsz.y))
    if require('cocos.framework.device').isMobile then
        local pos = im.getIO().MousePos
        if M._kbCode then
            im.text(('Key(%d)'):format(M._kbCode))
        end
        local dl = im.getForegroundDrawList()
        dl:addCircle(pos, 10, 0xff0000ff)
    end
end

function M.hideProperty()
    M:getInstance()._property:clear()
end

function M.getEditor()
    return M:getInstance()._editor
end

function M.getProperty()
    return M:getInstance()._property
end

---@return xe.SceneTree
function M.getTree()
    return M:getInstance()._editor:getTree()
end

function M.getToolBar()
    return M:getInstance()._editor._toolbar
end

function M.getToolPanel()
    return M:getInstance()._editor._toolpanel
end

function M.getGameLog()
    return M:getInstance()._game_log
end

function M.getGameView()
    return M:getInstance()._editor._game
end

---@return xe.AssetsTree
function M.getAssetsTree()
    return M:getInstance()._assets:getTree()
end

--

local key_event = require('xe.key_event')
M.setKeyEventEnabled = key_event.setKeyEventEnabled
M.backupKeyEvent = key_event.backupKeyEvent
M.restoreKeyEvent = key_event.restoreKeyEvent
M._handleGlobalKeyboard = key_event._handleGlobalKeyboard

--

function M:showWithScene(transition, time, more)
    return self
end

return M
