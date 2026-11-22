--
local base = require('imgui.Widget')
local wi = require('imgui.Widget')

---@class lstg.CameraSetter:im.Window
local M = class('lstg.CameraSetter', base)

function M:ctor()
    local im = imgui
    self:addChild(function()
        local v = lstg.view3d
        im.text(('Eye : %.2f, %.2f, %.2f'):format(unpack(v.eye)))
        im.text(('At  : %.2f, %.2f, %.2f'):format(unpack(v.at)))
        im.text(('Up  : %.2f, %.2f, %.2f'):format(unpack(v.up)))
        im.text(('FOVY: %.2f'):format(v.fovy))
        im.text(('Z   : %.2f, %.2f'):format(unpack(v.z)))
    end)
        :addChild(wi.Checkbox('roaming', false, function(sender, b)
        self._roaming:setEnable(b)
    end))
        :addChild(wi.Button('save', function()
        self._roaming:saveStatus()
    end))
        :addChild(im.sameLine)
        :addChild(wi.Button('load', function()
        self._roaming:loadStatus()
    end))
    --    :addChild(im.sameLine)
    --    :addChild(wi.Button('refresh', function()
    --    self._roaming:loadFromGame()
    --end))
    local rm = require('game.camera_roaming')()
    self._roaming = rm

    lstg.eventDispatcher:addListener('onFrameFunc',function()
        if not rm:isEnabled() then
            rm:loadFromGame()
        end
    end)
end

return M
