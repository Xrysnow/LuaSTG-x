local base = require('imgui.Widget')
---@class xe.Setting:im.Widget
local M = class('xe.Setting', base)
local im = imgui
local wi = base

function M:ctor()
    base.ctor(self)
    self._setting = setting.xe
    self:_set()

    self._timer = 1
    self:scheduleUpdateWithPriorityLua(std.bind(self._update, self), 1)
    --
    self:push()

    local data = require('xe.setting.data')
    self._curPage = 1
    self:addChild(function()
        local hh = -im.getFrameHeightWithSpacing()
        local ww = im.getContentRegionAvail().x
        local sz1 = im.vec2(math.max(ww * 0.3, 50), hh)
        local sz2 = im.vec2(-1, hh)

        if im.beginChildFrame(im.getID('xe.setting.group'), sz1) then
            local ret
            for i, v in ipairs(data) do
                ret = im.selectable(i18n(v.name) or 'N/A', i == self._curPage)
                if ret then
                    self._curPage = i
                end
            end
            im.endChildFrame()
        end
        im.sameLine()
        im.pushStyleColor(im.Col.Border, 0)
        if im.beginChildFrame(im.getID('xe.setting.content'), sz2) then
            im.popStyleColor()
            local tmp = self._tmp
            local d = data[self._curPage]
            im.columns(2, 'xe.setting.property')
            for i, v in ipairs(d) do
                if tmp[v.key] == nil then
                    local default = v.default
                    if type(default) == 'function' then
                        default = default()
                    end
                    tmp[v.key] = default
                end
                wi.propertyInput(i18n(v.name), tmp, v.key, v)
            end
            im.endChildFrame()
        else
            im.popStyleColor()
        end
    end)

    local ok = wi.Button('OK', std.bind(self._ok, self))
    local cancel = wi.Button('Cancel', std.bind(self._cancel, self))
    self:addChildren(ok, im.sameLine, cancel)
end

function M:_ok()
    self:pop()
    self:setVisible(false)
end

function M:_cancel()
    self:setVisible(false)
end

function M:push()
    -- push temp values
    self._tmp = table.deepcopy(self._setting)
end

function M:_applyTheme(theme)
    if theme == 'Light' then
        im.styleColorsLight()
    elseif theme == 'Dark' then
        im.styleColorsDark()
    else
        local t = require('imgui.style')
        if t[theme] then
            t[theme]()
        end
    end
end

function M:pop()
    -- pop temp values
    local s = self._setting
    local tmp = self._tmp

    -- apply theme
    local theme = tmp.theme
    if theme ~= s.theme then
        self:_applyTheme(theme)
    end

    for k, v in pairs(self._tmp) do
        s[k] = table.deepcopy(v)
    end
end

function M:_set()
    local setting = self._setting
    --local glv = cc.Director:getInstance():getOpenGLView()
    local fsz = setting.frame_size
    if fsz and require('cocos.framework.device').isDesktop then
        --glv:setFrameSize(fsz[1], fsz[2])
        lstg.WindowHelper:getInstance():setSize(cc.size(fsz[1], fsz[2])):moveToCenter()
    end
end

function M:_update()
    local t = self._timer + 1
    if t > 3600 then
        self._timer = 1
        t = 1
    else
        self._timer = t
    end
    if t % 30 == 0 then
        local s = self._setting
        local glv = cc.Director:getInstance():getOpenGLView()
        local fsz = glv:getFrameSize()
        s.frame_size = { fsz.x, fsz.y }
        setting.windowsize_w = fsz.x
        setting.windowsize_h = fsz.y

        lstg.saveSettingFile()
    end
end

local _id = 'Setting'
function M:_handler()
    im.setNextWindowSize(im.vec2(350, 300), im.Cond.Once)
    im.openPopup(_id)
    if im.beginPopupModal(_id) then
        wi._handler(self)
        im.endPopup()
    end
end

local function get_ins()
    return require('xe.main'):getInstance()._setting
end

function M:show()
    if self == nil or self == M then
        self = get_ins()
    end
    self:push()
    self:setVisible(true)
    return self
end

function M.setVar(k, v)
    local ins = get_ins()
    ins._setting[k] = v
end

function M.getVar(k)
    local ins = get_ins()
    return ins._setting[k]
end

function M.save()
    local path = require('xe.Project').getDir()
    if not path then
        return
    end
    --TODO: save to json
    local ins = get_ins()
end

return M
