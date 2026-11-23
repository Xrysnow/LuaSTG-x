local native = cc.gamepad
local Gamepad = setmetatable({}, { __index = native })

local function service()
    return cc.Director:getInstance():getGamepads()
end

for _, name in ipairs({
    'frame', 'importMappings', 'mappingFor', 'watchRaw', 'subscribeSensor',
    'rumble', 'triggerRumble', 'rgb', 'playerLights', 'adaptiveTrigger', 'stop',
}) do
    Gamepad[name] = function(...)
        local pads = service()
        return pads[name](pads, ...)
    end
end

local function status(err)
    if err == native.Error.None then return true end
    return nil, err
end

function Gamepad.assignPlayer(id, slot)
    return status(service():assignPlayer(id, slot))
end

function Gamepad.clearPlayer(id)
    return status(service():clearPlayer(id))
end

local function mappingResult(result)
    local change = result.change
    local code = change == native.MappingChange.Added and 1
        or change == native.MappingChange.Error and -1 or 0
    return code, result.diagnostics
end

function Gamepad.addGamepadMapping(...)
    return mappingResult(service():addGamepadMapping(...))
end

function Gamepad.setLocalBindings(...)
    return mappingResult(service():setLocalBindings(...))
end

function Gamepad.createHapticPlayback(id, source)
    if source == nil then return nil, native.Error.InvalidArgument end
    return service():createHapticPlayback(id, source)
end

function Gamepad.events(frame)
    local cursor, err = frame:events()
    if not cursor then return nil, err end
    return function() return cursor:next() end
end

return Gamepad
