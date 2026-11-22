local base = require('xe.input.ListBase')
---@class xe.input.ResSound:xe.input.ListBase
local M = class('xe.input.ResSound', base)
local im = imgui
local wi = require('imgui.Widget')
local se_list
local setting_sel_play = 'prop.se.sel_play'

---@param node xe.SceneNode
function M:ctor(node, idx)
    base.ctor(self, node, idx, 'sound_effect')
    -- init se_list
    if not se_list then
        se_list = {}
        local sound = require('xe.node_def._checker').getSoundList()
        for k, v in pairs(sound) do
            table.insert(se_list, k)
        end
        table.sort(se_list)
        for i = 1, #se_list do
            se_list[i] = { se_list[i], sound[se_list[i]] }
        end
    end

    local list = table.clone(se_list)
    local watch = require('xe.TreeHelper').watch.sound
    for k, _ in pairs(watch) do
        local name = k:getAttrValue(2)
        local path = k:getAttrValue(1)
        table.insert(list, { name, path })
    end
    table.sort(list, function(a, b)
        return a[1] < b[1]
    end)
    self._list = list

    local map = {}
    for i, v in ipairs(list) do
        map[v[1]] = { i, v[2] }
    end
    local value = self:getEditValue()
    if not map[value] then
        value = node:getAttrValue(idx)
    end
    if not map[value] then
        value = se_list[1][1]
    end
    self._value = value
    self._sel = map[value][1]
    self._path = map[value][2]

    local sel_play = setting.xe.prop_se_play
    self._sel_play = sel_play == nil and true or sel_play

    local btn, selector
    btn = wi.Button('', function()
        if btn:getDir() == im.Dir.Down then
            btn:setDir(im.Dir.Up)
            selector:setVisible(true)
        else
            btn:setDir(im.Dir.Down)
            selector:setVisible(false)
        end
    end, im.Dir.Down, 'arrow')
    selector = wi.Widget(function()
        self:_render()
    end)
    selector:setVisible(false)
    self:addChild(btn):addChild(im.sameLine):addChild(function()
        im.text(self._value)
    end):addChild(selector)

    self :addChild(wi.Button('Play', function()
        self:_play()
    end)):addChild(im.sameLine):addChild(wi.Button('Stop', function()
        self:_stop()
    end)):addChild(im.sameLine):addChild(wi.Checkbox('Play on select', self._sel_play, function(_, v)
        self._sel_play = v
        setting.xe.prop_se_play = v
    end))
end

function M:_render()
    local last = self._sel
    local lst = {}
    for i, v in ipairs(self._list) do
        lst[i] = v[1]
    end
    self:_renderList(lst)
    local sel = self._sel
    if sel ~= last then
        self._value = self._list[sel][1]
        self._path = self._list[sel][2]
        self:submit()
        -- play on select
        if self._sel_play then
            self:_play()
        end
    end
end

function M:_play()
    self:_stop()
    local dec = audio.Decoder:createFromFile(string.path_uniform(self._path), 4096)
    if not dec then
        return
    end
    local src = audio.Source:createFromDecoder(dec)
    if not src then
        return
    end
    src:play()
end

function M:_stop()
    audio.Engine:stop()
end

return M
