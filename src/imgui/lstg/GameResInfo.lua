local base = require('imgui.Widget')

---@class im.lstg.GameResInfo:im.Widget
local M = class('im.lstg.GameResInfo', base)
local im = imgui

function M:ctor(...)
    base.ctor(self, ...)
    self._selected = -1
    self._refreshInterval = 30
    self._refreshTimer = 0
    self._filter = {
        global       = true,
        stage        = true,

        Texture      = true,
        Sprite       = true,
        Animation    = true,
        Music        = true,
        SoundEffect  = true,
        Particle     = true,
        Font         = true,
        FX           = true,
        RenderTarget = true,
    }
    self._count = {
        global       = 0,
        stage        = 0,

        Texture      = 0,
        Sprite       = 0,
        Animation    = 0,
        Music        = 0,
        SoundEffect  = 0,
        Particle     = 0,
        Font         = 0,
        FX           = 0,
        RenderTarget = 0,
    }
    self._nameFilter = require('imgui.TextFilter')()
    self._curPage = 1
    self._perPage = 20
end

function M:_checkResFilter(t)
    local f = self._filter
    if f[t.poolName] == false then
        return false
    end
    if f[t.typeName] == false then
        return false
    end
    return true
end

function M:_renderResInfo()
    if self._refreshTimer % self._refreshInterval == 0 then
        self._resInfo, self._count = require('game.util').collectResInfo()
    end
    self._refreshTimer = self._refreshTimer + 1
    local info, resCount = self._resInfo, self._count

    local ret
    local filter_changed
    local check_group = {
        { 'global', 'stage' },
        { 'Texture', 'Sprite', 'Animation' },
        { 'Music', 'SoundEffect', 'Particle' },
        { 'Font', 'FX', 'RenderTarget' },
    }
    for _, group in ipairs(check_group) do
        for i, v in ipairs(group) do
            local str = string.format('%s (%d)', string.capitalize(v), resCount[v] or 0)
            ret, self._filter[v] = im.checkbox(str, self._filter[v])
            if ret then
                filter_changed = true
            end
            if i < #group then
                im.sameLine()
            end
        end
    end

    ret = self._nameFilter:inputText('Filter')
    if ret then
        filter_changed = true
    end

    if filter_changed then
        self._curPage = 1
    end

    local ncol = 4
    im.columns(ncol, 'col.resinfo', true)
    im.separator()

    im.text("Pool")
    im.nextColumn()
    im.text("Name")
    im.nextColumn()
    im.text("Type")
    im.nextColumn()
    im.text("Path")
    im.nextColumn()
    --im.text("Info")
    --im.nextColumn()

    im.separator()

    local filtered = {}
    for i, v in ipairs(info) do
        if self:_checkResFilter(v) and self._nameFilter:filter(v.name) then
            table.insert(filtered, v)
        end
    end
    local npage = 1
    if #filtered > 0 then
        npage = math.ceil(#filtered / self._perPage)
    end
    if self._curPage > npage then
        self._curPage = npage
    end
    local lo = (self._curPage - 1) * self._perPage + 1
    local hi = lo + self._perPage - 1
    for i = lo, math.min(#filtered, hi) do
        local v = filtered[i]
        im.pushID(i)
        if im.selectable(v.poolName,
                         self._selected == i,
                         im.SelectableFlags.SpanAllColumns) then
            self._selected = i
        end
        im.popID()
        im.nextColumn()
        for j, k in ipairs({ 'name', 'typeName', 'path' }) do
            im.textUnformatted(v[k] or '')
            if j == 1 and im.isItemHovered() then
                -- preview image
                if v.typeName == 'Sprite' then
                    local res = FindResSprite(v.name)
                    if res then
                        im.beginTooltip()
                        im.image(res:getSprite())
                        im.endTooltip()
                    end
                elseif v.typeName == 'Animation' then
                    local res = FindResAnimation(v.name)
                    if res then
                        local timer = self._refreshTimer
                        local int = res:getInterval()
                        local sp = res:getSprite(math.floor(timer / int) % res:getCount())
                        if sp then
                            im.beginTooltip()
                            im.image(sp)
                            im.endTooltip()
                        end
                    end
                end
            elseif j == 3 and im.isItemHovered() then
                -- preview path (which is usually too long to display)
                if v.path ~= '' then
                    im.beginTooltip()
                    im.textUnformatted(v.path)
                    im.endTooltip()
                end
            end
            im.nextColumn()
        end
    end

    if npage > 1 then
        for i = 1, hi - #filtered do
            for j = 1, ncol do
                im.textUnformatted('')
                im.nextColumn()
            end
        end
    end

    im.separator()
    im.columns(1)
    -- page slider
    if npage > 1 then
        ret, self._curPage = im.sliderInt('Page', self._curPage, 1, npage)
    end
end

function M:_handler()
    self:_renderResInfo()
end

return M
