local gp = cc.gamepad
local M = {}

local groups = { 'keys', 'keysys' }
local stickAxes = { [gp.Axis.LeftX] = true, [gp.Axis.LeftY] = true, [gp.Axis.RightX] = true, [gp.Axis.RightY] = true }
local buttons = {
    [gp.Button.South] = 'a', [gp.Button.East] = 'b', [gp.Button.West] = 'x', [gp.Button.North] = 'y', [gp.Button.Back] = 'back', [gp.Button.Start] = 'start',
    [gp.Button.LeftStick] = 'leftstick', [gp.Button.RightStick] = 'rightstick', [gp.Button.LeftShoulder] = 'leftshoulder',
    [gp.Button.RightShoulder] = 'rightshoulder', [gp.Button.DpadUp] = 'dpup', [gp.Button.DpadDown] = 'dpdown',
    [gp.Button.DpadLeft] = 'dpleft', [gp.Button.DpadRight] = 'dpright',
}
M.hardwareButtons = {
    gp.Button.South, gp.Button.East, gp.Button.West, gp.Button.North, gp.Button.LeftShoulder, gp.Button.RightShoulder,
    gp.Button.DpadUp, gp.Button.DpadDown, gp.Button.DpadLeft, gp.Button.DpadRight, gp.Button.Start, gp.Button.Back,
}

local legacyButtons = {
    [4] = gp.Button.South, [5] = gp.Button.East, [7] = gp.Button.West, [8] = gp.Button.North,
    [10] = gp.Button.DpadUp, [11] = gp.Button.DpadDown, [12] = gp.Button.DpadLeft, [13] = gp.Button.DpadRight,
    [15] = gp.Button.LeftShoulder, [16] = gp.Button.RightShoulder,
    [19] = gp.Button.LeftStick, [20] = gp.Button.RightStick, [21] = gp.Button.Start, [22] = gp.Button.Back,
}
local legacyAxes = {
    [0] = gp.Axis.LeftX, [1] = gp.Axis.LeftY, [2] = gp.Axis.RightX, [3] = gp.Axis.RightY,
    [17] = gp.Axis.LeftTrigger, [18] = gp.Axis.RightTrigger,
}

function M.migration(config)
    local old = config.controller_map
    if type(old) ~= 'table' then return end
    local profile = { version = 3, slot = 0, keys = {}, keysys = {} }
    local missing = {}
    local different = false
    for _, group in ipairs(groups) do
        for name, key in pairs(old[group] or {}) do
            local default = default_setting.controller_map[group][name]
            if type(key) == 'table' and type(key[1]) == 'number' then
                different = different or not default or key[1] ~= default[1] or key[2] ~= default[2]
                local code = key[1] >= 1000 and key[1] - 1000 or key[1]
                -- Offsets below 1000 also came from unmapped devices. Only
                -- explicit Controller::Key codes have an unambiguous origin.
                if key[1] >= 1000 and key[2] == nil and legacyButtons[code] then
                    profile[group][name] = legacyButtons[code]
                elseif key[1] >= 1000 and type(key[2]) == 'boolean' and legacyAxes[code] then
                    profile[group][name] = { axis = legacyAxes[code], sign = key[2] and 1 or -1 }
                else
                    missing[#missing + 1] = name
                end
            end
        end
    end
    if different then
        table.sort(missing)
        return profile, missing
    end
end

-- Match layout as well as model. Same-model units without serials keep separate
-- live IDs and require Start (or explicit selection) when more than one matches.
local layoutsWithLegacyIdentity = {
    ['win-directinput8-v1'] = true, ['win-raw-hid-v1'] = true,
    ['linux-evdev-v1'] = true, ['linux-dualsense-hid-v1'] = true,
    ['macos-iohid-v1'] = true, ['apple-gc-extended-v1'] = true,
}
function M.identity(info)
    -- These layouts acquired an SDL GUID without changing their existing local indices.
    local guid = layoutsWithLegacyIdentity[info.layout:match('^[^/]+')] and '' or info.mappingGuid
    return table.concat({ info.layout, guid, info.name, info.vendor or '',
        info.product or '', info.serial or '' }, '|')
end

local function valueAt(pad, action)
    if action.button then return pad:down(action.button) end
    if not action.axis then return false end
    local value = (pad:axis(action.axis) or 0) * action.sign
    return action.pad and value >= 0.45 or value >= 0.60
end

local function enumName(values, value)
    for name, id in pairs(values) do
        if id == value then return name end
    end
end

local function axisValue(name, value)
    return value / (stickAxes[name] and value < 0 and 32768 or 32767)
end

local profile, configured, selected, tick, lastKey, consumedAt
local actions, codeActions, installed = {}, {}, {}
local edges = {}
local inPause = false
local databaseLoaded = false

local function source(action, key, down, emit)
    if action[key] == down then return end
    action[key] = down
    local held = action.keyboard or action.pad
    if held == action.held then return end
    action.held = held
    if emit then
        edges[#edges + 1] = { action = action.name, down = held }
    end
end

function M.loadFromSetting()
    configured = setting
    profile = configured.gamepad_actions
    if type(profile) ~= 'table' or profile.version ~= 3 then profile = default_setting.gamepad_actions end
    actions, codeActions = {}, {}
    edges = {}
    for _, group in ipairs(groups) do
        local names = {}
        for name in pairs(configured[group]) do names[#names + 1] = name end
        table.sort(names)
        for _, name in ipairs(names) do
            local binding = (profile[group] or {})[name]
            local action = {
                axis = type(binding) == 'table' and binding.axis,
                sign = type(binding) == 'table' and binding.sign == -1 and -1 or 1,
                button = type(binding) == 'number' and binding,
                name = name, code = configured[group][name],
                keyboard = false, pad = false, held = false,
            }
            actions[#actions + 1] = action
            codeActions[action.code] = action
        end
    end
    selected, tick, consumedAt = nil, nil, nil
end

local function install(pad, id, info)
    local identity = M.identity(info)
    local records = configured.gamepad_hardware
    local fields = type(records) == 'table' and records[identity] or nil
    fields = type(fields) == 'string' and fields or ''
    if not installed[id] and fields == '' and pad:mappingStatus() ~= 'Local' then return end
    if installed[id] == fields then return end
    local code = gp.setLocalBindings(id, info.layout, fields)
    if code and code >= 0 then installed[id] = fields end
end

local function observe(frame)
    if configured ~= setting then M.loadFromSetting() end
    local now = frame:tick()
    if tick == now then return end
    local first = tick == nil
    tick = now
    lastKey = nil
    local paused = ext and ext.pause_menu ~= nil
    -- The game can skip up to three Director ticks while simulating at 15 Hz.
    -- A launcher or an inactive scene has no consumer for older actions.
    local emit = not paused and consumedAt ~= nil and now - consumedAt <= 4
    if not emit or inPause then edges = {} end
    inPause = paused

    local pad, id, match, ambiguous
    local ids = frame:devices()
    local live = {}
    local slot = profile.slot or 0
    for _, candidate in ipairs(ids) do
        local view = frame:find(candidate)
        local info = view:info()
        live[candidate] = true
        install(view, candidate, info)
        if view:player() == slot then
            pad, id = view, candidate
        elseif view:mapped() and view:player() == nil and configured.gamepad_preferred == M.identity(info) then
            ambiguous = match ~= nil
            match = candidate
        end
    end
    for old in pairs(installed) do if not live[old] then installed[old] = nil end end
    if not pad and match and not ambiguous then gp.assignPlayer(match, slot) end
    for _, action in ipairs(actions) do
        source(action, 'keyboard', not not lstg.GetKeyState(action.code), not first and emit)
        if selected ~= id then
            source(action, 'pad', false, not first and emit)
        end
    end
    local useEdges = selected == id
    for e in frame:events() do
        if not pad and e.kind == gp.EventKind.Button and e.button == gp.Button.Start and e.down and e.reason == gp.Reason.Physical then
            local candidate = frame:find(e.device)
            if candidate and candidate:mapped() and candidate:player() == nil then
                if gp.assignPlayer(e.device, slot) then break end
            end
        elseif pad and e.device == id and e.kind == gp.EventKind.Device and e.change == gp.Change.PlayerChanged then
            useEdges = true
        elseif pad and useEdges and e.device == id and (e.kind == gp.EventKind.Button or e.kind == gp.EventKind.Axis) then
            for _, action in ipairs(actions) do
                local axis, sign = action.axis, action.sign
                local down
                if e.kind == gp.EventKind.Button and action.button == e.button then
                    down = e.down
                elseif e.kind == gp.EventKind.Axis and axis == e.axis then
                    local value = axisValue(axis, e.value) * sign
                    down = action.pad and value >= 0.45 or value >= 0.60
                end
                if down ~= nil then
                    if down and not action.pad and e.reason == gp.Reason.Physical then lastKey = action.code end
                    source(action, 'pad', down, emit and (not down or e.reason == gp.Reason.Physical))
                end
            end
        end
    end
    if pad then
        for _, action in ipairs(actions) do
            if action.axis or action.button then
                local down = not not valueAt(pad, action)
                source(action, 'pad', down, emit and not down and selected == id)
            end
        end
    end
    selected = id
end

function M.init()
    if not databaseLoaded then
        local path = 'cocos/gamecontrollerdb.txt'
        local files = cc.FileUtils:getInstance()
        if files:isFileExist(path) then
            local report = gp.importMappings(files:getStringFromFile(path), gp.MappingSource.BuiltIn)
            databaseLoaded = report.batchError == gp.Error.None
            SystemLog(('Gamepad database: %d added, %d replaced, %d rejected (%s)'):format(
                report.added, report.replaced, report.failed, report.batchError))
        else
            SystemLog('Gamepad database not found: ' .. path)
        end
    end
    M.loadFromSetting()
    if not M.listener then
        M.listener = cc.Director:getInstance():getEventDispatcher():addCustomEventListener(
            'director_before_update', function() observe(gp.frame()) end)
    end
end

function M.getStatus(code)
    observe(gp.frame())
    local action = codeActions[code]
    return action and action.pad
end

function M.getLastKey()
    observe(gp.frame())
    return lastKey or 0
end

function M.consume()
    local frame = gp.frame()
    if not consumedAt then consumedAt = frame:tick() end
    observe(frame)
    consumedAt = tick
    local current = { held = {}, pressed = {}, released = {}, edges = edges, tick = tick }
    edges = {}
    for _, action in ipairs(actions) do current.held[action.name] = action.held end
    for _, edge in ipairs(current.edges) do
        if edge.down then current.pressed[edge.action] = true else current.released[edge.action] = true end
    end
    return current
end

function M.bindLabel(pad, binding)
    if type(binding) == 'table' then
        local name = enumName(gp.Axis, binding.axis)
        return name and ((binding.sign == -1 and '-' or '+') .. name) or '-'
    end
    if type(binding) ~= 'number' then return '-' end
    local label = pad and pad:label(binding)
    return (label and label ~= '' and label) or enumName(gp.Button, binding) or '-'
end

function M.learnAction(frame, id)
    if not id then return end
    for e in frame:events() do
        if e.device == id and e.reason == gp.Reason.Physical then
            if e.kind == gp.EventKind.Button and e.down then return e.button end
            if e.kind == gp.EventKind.Axis then
                local value = axisValue(e.axis, e.value)
                if math.abs(value) >= 0.60 then return { axis = e.axis, sign = value < 0 and -1 or 1 } end
            end
        end
    end
end

function M.learnHardware(frame, id, target, existing)
    local field = buttons[target]
    if not field then return end
    for e in frame:events() do
        if e.device == id and e.reason == gp.Reason.Physical and e.kind == gp.EventKind.Raw then
            local binding
            if e.control == gp.RawKind.Button and e.value ~= 0 then binding = 'b' .. e.index
            elseif e.control == gp.RawKind.Axis and math.abs(e.value) >= 22000 then
                binding = (e.value < 0 and '-' or '+') .. 'a' .. e.index
            elseif e.control == gp.RawKind.Hat and (e.value == 1 or e.value == 2 or e.value == 4 or e.value == 8) then
                binding = 'h' .. e.index .. '.' .. e.value
            end
            if binding then
                local fields = {}
                for entry in (existing or ''):gmatch('[^,]+') do
                    if entry:match('^([^:]+):') ~= field then fields[#fields + 1] = entry end
                end
                fields[#fields + 1] = field .. ':' .. binding
                return table.concat(fields, ',')
            end
        end
    end
end

return M
