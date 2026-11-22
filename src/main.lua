--
--lstg.DoFile('jit_test.lua')
local fu = cc.FileUtils:getInstance()
fu:setPopupNotify(true)
-- Create the configured view before the framework and FrameInit use it.
require('config')
require('cocos.init')
setmetatable(_G, nil)
-- package.path may not end with ';'
package.path = package.path .. ';?/__init__.lua;'
-- ';;' will cause error
package.path = package.path:gsub('[;]+', ';')
require('cc.ext')
require('cc.to_string')
require('cc.color')
require('i18n')
require('audio')

local _path = {}
local _path_rec = {}
for _, v in ipairs(fu:getSearchPaths()) do
    local p = string.gsub(v, '\\', '/')
    p = string.gsub(p, '//', '/')
    if not _path_rec[p] then
        table.insert(_path, p)
        _path_rec[p] = true
    end
end
fu:setSearchPaths(_path)

local sp = fu:getSearchPaths()
local _sp = '=== Search Path ===\n{'
for _, v in ipairs(sp) do
    _sp = string.format('%s\n    %q', _sp, v)
end
lstg.SystemLog(_sp .. '\n}')

local function main()
    lstg.SystemLog('start main')
    lstg.FrameInit()
    local platform = lstg.GetPlatform()
    if platform == 'android' then
        -- Keep bundled scripts as the trusted startup source. Shared-storage
        -- data is only read after an explicit document import.
        local native = require('platform.android.native')
        if require('config').setting.orientation == 'portrait' then
            native.setOrientationPortrait()
        else
            native.setOrientationLandscape()
        end
    end
    lstg.DoFile('launch.lua')
    lstg.SystemLog('start app')
    require("app.MyApp"):create():run()
end

local TRACE_MAX_LEVEL = 16
local function traceback(thread, msg, level)
    if type(thread) ~= 'thread' then
        level = msg
        msg = thread
        thread = nil
    end
    local isCurrentThread = not thread or thread == coroutine.running()
    if level == nil then
        level = isCurrentThread and 1 or 0
    end
    -- Match debug.traceback levels without counting this Lua helper.
    if isCurrentThread and level >= 0 then
        level = level + 1
    end
    local ret = {}
    if msg ~= nil then
        local ok, text = pcall(tostring, msg)
        if not ok or type(text) ~= 'string' then
            text = string.format('<%s error object>', type(msg))
        end
        table.insert(ret, text)
    end
    table.insert(ret, 'stack traceback:')
    local frames = {}
    while true do
        local info
        if thread then
            info = debug.getinfo(thread, level, "Slnf")
        else
            info = debug.getinfo(level, "Slnf")
        end
        if not info then
            break
        end
        table.insert(frames, info)
        level = level + 1
    end
    local head = math.floor(TRACE_MAX_LEVEL / 2)
    local tail = TRACE_MAX_LEVEL - head
    local index = 1
    while index <= #frames do
        if #frames > TRACE_MAX_LEVEL and index == head + 1 then
            table.insert(ret, '...')
            index = #frames - tail + 1
        end
        local info = frames[index]
        local msgs = {}
        local source = info.source or ''
        if info.what == 'C' then
            source = '[C]'
        else
            source = string.format('[%s]', source)
        end
        table.insert(msgs, string.format('    %s', source))
        if info.currentline > 0 then
            table.insert(msgs, string.format('%d:', info.currentline))
        end
        if info.what == 'main' then
            table.insert(msgs, ' in main chunk')
        elseif info.namewhat ~= '' and info.name then
            table.insert(msgs, string.format(' in function \'%s\'', info.name))
        elseif info.what == 'C' then
            table.insert(msgs, string.format(' at %s', tostring(info.func)))
        else
            table.insert(msgs, string.format(' in function <%s:%d>', source, info.linedefined))
        end
        table.insert(ret, table.concat(msgs, ''))
        index = index + 1
    end
    return table.concat(ret, '\n')
end

-- note: in app.run, only __G__TRACKBACK__ will take effect

__G__TRACKBACK__ = function(msg)
    --msg = debug.traceback(msg, 3)
    msg = traceback(msg, 3)
    print(msg)
    lstg.SystemLog(msg)
    if plus and plus.isMobile() then
        require('cc.ui.MessageBox').OK('Error', msg, function()
            --ex.OnExit()
            cc.Director:getInstance():endToLua()
        end)
        for _, v in ipairs({ 'FrameFunc' }) do
            _G[v] = function()
            end
        end
    else
        lstg.MessageBox(msg, 'ERROR')
        lstg.FrameEnd()
        os.exit()
    end
    lstg.SystemLog('caught error in main')
    return msg
end

local status, msg = xpcall(main, __G__TRACKBACK__)
if not status then
    lstg.SystemLog('=== Error Message ===\n' .. msg)
end
