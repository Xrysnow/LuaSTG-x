--
local M = {}
local im = imgui

local keyListener = { editor = true, game = false, coding = false }
local keyListenerBak = table.clone(keyListener)
function M.setKeyEventEnabled(name, b)
    if name == true then
        for k, _ in pairs(keyListener) do
            keyListener[k] = true
        end
    elseif name == false then
        for k, _ in pairs(keyListener) do
            keyListener[k] = false
        end
    else
        keyListener[name] = b and true or false
    end
end

function M.backupKeyEvent()
    keyListenerBak = table.clone(keyListener)
end

function M.restoreKeyEvent()
    keyListener = table.clone(keyListenerBak)
end

local keyEditor
local keyGame
function M._handleGlobalKeyboard()
    local xe = require('xe.main')
    keyEditor = keyEditor or require('xe.win.SceneEditor').KeyEvent
    keyGame = keyGame or require('xe.win.GameView').KeyEvent
    for k, enabled in pairs(keyListener) do
        if enabled then
            if k == 'editor' then
                local tool = require('xe.ToolMgr')
                local toolbar = xe.getToolBar()
                for _, v in ipairs(keyEditor) do
                    if toolbar:isEnabled(v[3]) and im.checkKeyboard(v[1], v[2]) then
                        tool[v[3]]()
                        break
                    end
                end
            elseif k == 'game' then
                local game = xe.getGameView()
                if game:isVisible() then
                    for _, v in ipairs(keyGame) do
                        if game:isEnabled(v[3]) and im.checkKeyboard(v[1], v[2]) then
                            game['_' .. v[3]](game)
                            break
                        end
                    end
                end
            else
                --
            end
        end
    end
end

return M
