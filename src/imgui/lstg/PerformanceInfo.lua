local base = require('imgui.Widget')

---@class im.lstg.PerformanceInfo:im.Widget
local M = class('im.lstg.PerformanceInfo', base)
local im = imgui

function M:ctor(...)
    base.ctor(self, ...)
    self.plot = {}
    self.plotTargets = {}
    self.plotBufSize = 60

    local dir = cc.Director:getInstance()
    self:setPlot('Frame Time', {
        label     = '',
        overlay   = function(v)
            return string.format('%.2fms', v)
        end,
        min       = 0,
        max       = 25,
        min_range = { 0, 50 },
        max_range = { 0, 50 },
        buffer    = {},
        offset    = 0,
        size      = cc.p(0, 64),
        source    = function()
            return dir:getDeltaTime() * 1000
        end,
    })
    self:setPlot('FPS', {
        label     = '',
        overlay   = function(v)
            return string.format('%.2f', v)
        end,
        min       = 0,
        max       = 65,
        min_range = { 0, 100 },
        max_range = { 0, 100 },
        buffer    = {},
        offset    = 0,
        size      = cc.p(0, 64),
        source    = function()
            return dir:getFrameRate()
        end,
    })
    self:setPlot('Game Object Count', {
        label     = '',
        overlay   = function(v)
            return string.format('Count: %d', v)
        end,
        min       = 0,
        max       = 3000,
        min_range = { 0, 10000 },
        max_range = { 0, 10000 },
        buffer    = {},
        offset    = 0,
        size      = cc.p(0, 64),
        source    = function()
            return GetnObj()
        end,
    })
    self:setPlot('Game Object Frame Time', {
        label     = '',
        overlay   = function(v)
            return string.format('%.2fms', v)
        end,
        min       = 0,
        max       = 15,
        min_range = { 0, 50 },
        max_range = { 0, 50 },
        buffer    = {},
        offset    = 0,
        size      = cc.p(0, 64),
        source    = function()
            return profiler.getLast('ObjFrame') * 1000
        end,
    })
    self:setPlot('Game Object Render Time', {
        label     = '',
        overlay   = function(v)
            return string.format('%.2fms', v)
        end,
        min       = 0,
        max       = 15,
        min_range = { 0, 50 },
        max_range = { 0, 50 },
        buffer    = {},
        offset    = 0,
        size      = cc.p(0, 64),
        source    = function()
            return profiler.getLast('RenderFunc') * 1000
        end,
    })
    self:setPlot('Render Time', {
        label     = '',
        overlay   = function(v)
            return string.format('%.2fms', v)
        end,
        min       = 0,
        max       = 15,
        min_range = { 0, 50 },
        max_range = { 0, 50 },
        buffer    = {},
        offset    = 0,
        size      = cc.p(0, 64),
        source    = function()
            local t = profiler.getLast('AppFrame::PF_Render') + profiler.getLast('AppFrame::PF_Visit')
            return t * 1000
        end,
    })
    self:setPlot('Lua Memory', {
        label     = '',
        overlay   = function(v)
            return string.format('%.2fMB', v)
        end,
        min       = 0,
        max       = 10,
        min_range = { 0, 50 },
        max_range = { 0, 50 },
        buffer    = {},
        offset    = 0,
        size      = cc.p(0, 64),
        source    = function()
            return collectgarbage('count') / 1024
        end,
    })
    self.plotTargets = {
        'Frame Time',
        'FPS',
        'Game Object Count',
        'Game Object Frame Time',
        'Game Object Render Time',
        'Render Time',
        'Lua Memory',
    }
end

function M:setPlot(key, val)
    self.plot[key] = val
    if #self.plot[key].buffer < self.plotBufSize then
        self:resetPlotBuffer(key)
    end
end

function M:resetPlot(key)
    self.plot[key] = {
        label   = '',
        overlay = '',
        min     = 0,
        max     = 1,
        size    = nil,
        buffer  = {},
        offset  = 0,
        source  = nil,
    }
    self:resetPlotBuffer(key)
end

function M:resetPlotBuffer(key)
    local buf = {}
    for i = 1, self.plotBufSize do
        buf[i] = 0
    end
    local p = self.plot[key]
    p.buffer = buf
    p.offset = 0
end

function M:addPlotPoint(key, val)
    local p = self.plot[key]
    if not p then
        self:resetPlot(key)
        p = self.plot[key]
    end
    p.offset = p.offset + 1
    p.buffer[p.offset] = val
    if p.offset >= self.plotBufSize then
        p.offset = 0
    end
end

function M:_renderPlot(key)
    local p = self.plot[key]
    local src = p.source
    if src then
        self:addPlotPoint(key, src())
    end
    local label = p.label
    local buf = p.buffer
    local offset = p.offset
    if type(label) == 'function' then
        label = label(buf[offset + 1])
    end
    local overlay = p.overlay
    if type(p.overlay) == 'function' then
        overlay = overlay(buf[offset + 1])
    end
    im.pushID(tostring(key))
    im.plotLines(unpack({ label, buf, #buf, offset,
                          overlay, p.min, p.max, p.size }))
    --im.plotLines(unpack({ label, buf, #buf, 0,
    --                      overlay, p.min, p.max, p.size }))
    local ret
    local minr = p.min_range
    local maxr = p.max_range
    local h = 64
    if p.size then
        h = p.size.y
    end
    if minr then
        im.sameLine()
        im.pushID(tostring(key) .. 'min')
        ret, p.min = im.vSliderFloat('', cc.p(16, h), p.min, minr[1], minr[2], '')
        im.popID()
        if ret and p.min > p.max then
            p.max = p.min
        end
    end
    if maxr then
        im.sameLine()
        im.pushID(tostring(key) .. 'max')
        ret, p.max = im.vSliderFloat('', cc.p(16, h), p.max, maxr[1], maxr[2], '')
        im.popID()
        if ret and p.min > p.max then
            p.min = p.max
        end
    end
    im.sameLine()
    im.textUnformatted(string.format('min %.1f\nmax %.1f', p.min, p.max))
    im.popID()
end

function M:_handler()
    for i, key in ipairs(self.plotTargets) do
        if im.treeNode(key) then
            self:_renderPlot(key)
            im.treePop()
        end
    end
end

return M
