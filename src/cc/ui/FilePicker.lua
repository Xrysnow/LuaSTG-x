---@class ui.FilePicker:ccui.Layout
local M = class('ui.FilePicker', ccui.Layout)
local margin = 6

function M:ctor(filter, default_path, is_save, input_size, btn_size)
    input_size = input_size or cc.size(100, 22)
    btn_size = btn_size or cc.size(72, 22)
    local sz = cc.size(
            input_size.width + btn_size.width + margin * 3,
            math.max(input_size.height, btn_size.height) + margin * 2
    )
    self:setContentSize(sz)
    --self:setBackGroundColorType(1):setBackGroundColor(cc.c3b(2555, 200, 200))

    local input = require('cc.ui.prefab.EditBox').String(input_size)
    input:addTo(self):alignLeft(margin):alignVCenter()
    self._eb = input

    local fd = require('platform.FileDialog')
    self:enableNodeEvents()
    local weak = setmetatable({ self }, { __mode = 'v' })
    local btn = require('cc.ui.button').Button1(btn_size, function()
        if self._request then return end
        local function completed(result)
            local owner = weak[1]
            if not owner or owner._request ~= result.requestId then return end
            owner._request = nil
            if result.status == 'success' then
                if is_save then
                    local name = result.displayName
                    print(name and name ~= '' and 'Exported ' .. name or 'Export complete')
                else owner._eb:setString(0, result.path) end
            elseif result.status ~= 'cancelled' then print(result.message) end
        end
        local id, err
        if is_save then
            id, err = fd.exportPath(self._eb:getString(0), nil, nil, completed)
        else
            id, err = fd.openPaths(filter, default_path, false, completed)
        end
        self._request = id
        if not id then print(err) end
    end, 'Browse')
    btn:addTo(self):alignRight(margin):alignVCenter()
    self._btn = btn
end

function M:onExit()
    local id = self._request
    self._request = nil
    if id then require('platform.FileDialog').cancel(id) end
end

function M:getEditBox()
    return self._eb
end

function M:getButton()
    return self._btn
end

return M
