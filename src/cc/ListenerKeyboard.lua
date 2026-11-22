--
local M = {}
local handlers = {}
local handlers_k = { any = {} }
local lis

function M.start()
    if not lis then
        lis = cc.EventListenerKeyboard:create()
        lis:registerScriptHandler(function(key)
            if handlers_k[key] then
                for k, v in pairs(handlers_k[key]) do
                    if v[1] then
                        v[1](key)
                    end
                end
            end
            for k, v in pairs(handlers_k.any) do
                if v[1] then
                    v[1](key)
                end
            end
        end, cc.Handler.EVENT_KEYBOARD_PRESSED)
        lis:registerScriptHandler(function(key)
            if handlers_k[key] then
                for k, v in pairs(handlers_k[key]) do
                    if v[2] then
                        v[2](key)
                    end
                end
            end
            for k, v in pairs(handlers_k.any) do
                if v[2] then
                    v[2](key)
                end
            end
        end, cc.Handler.EVENT_KEYBOARD_RELEASED)
        cc.Director:getInstance():getEventDispatcher()
          :addEventListenerWithFixedPriority(lis, 1)
    end
end

function M.stop()
    cc.Director:getInstance():getEventDispatcher()
      :removeEventListener(lis)
end

function M.addHandler(name, key, onPress, onRelease)
    if type(key) == 'string' then
        key = require('keycode')[string.upper(key)]
        assert(key)
    end
    if key == nil then
        key = 'any'
    end
    handlers[name] = key
    handlers_k[key] = handlers_k[key] or {}
    handlers_k[key][name] = { onPress, onRelease }
end

function M.removeHandler(name)
    local key = handlers[name]
    handlers[name] = nil
    if handlers_k[key] then
        handlers_k[key][name] = nil
    end
end

M.start()

return M
