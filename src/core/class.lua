---所有已定义的类
all_class = {}
class_name = {}

---定义类
---@param base object 基类
---@param define table 需要额外继承的表，通常与base相同
---@return object
function Class(base, define)
    base = base or object
    if (type(base) ~= 'table') or not base.is_class then
        error(i18n 'Invalid base class')
    end
    local result = { 0, 0, 0, 0, 0, 0 }
    if define then
        for k, v in pairs(define) do
            if type(k) ~= 'number' then
                result[k] = v
            end
        end
    end
    result.is_class = true
    result.init = base.init
    result.del = base.del
    result.frame = base.frame
    result.render = base.render
    result.colli = base.colli
    result.kill = base.kill
    result.base = base
    table.insert(all_class, result)
    return result
end

---@type object
object = {
    0, 0, 0, 0, 0, 0;
    is_class = true,
    init     = function()
    end,
    del      = function()
    end,
    frame    = function()
    end,
    render   = DefaultRenderFunc,
    colli    = function(other)
    end,
    kill     = function()
    end
}
table.insert(all_class, object)

object3d = Class()
object3d['.3d'] = true

local _class_num = 0
local _class_id = {}
--local sym = require('core_x.symbol')
local callbacks = { 'init', 'del', 'frame', 'render', 'colli', 'kill', }

function RegisterGameClass(v)
    for i = 1, 6 do
        if type(v[i]) ~= 'function' then
            v[i] = v[callbacks[i]]
        end
    end

    if v[3] == object.frame then
        v[3] = nil
    end
    if v[4] == DefaultRenderFunc then
        v[4] = nil
    end

    if _class_id[v] == nil then
        _class_num = _class_num + 1
        _class_id[v] = _class_num
        v[7] = _class_num
    else
        v[7] = _class_id[v]
    end

    --if v['.compile'] then
    --    RegisterClass(v, sym.compile(v.frame))
    --else
    RegisterClass(v)
    --end

    local _class_name
    for k, vv in pairs(_G) do
        if vv == v then
            _class_name = k
            break
        end
    end
    if not _class_name or _class_name == 'last' then
        for k, vv in pairs(_editor_class or {}) do
            if vv == v then
                _class_name = 'editor.' .. k
                break
            end
        end
    end
    v['.classname'] = _class_name

    --if _class_name then
    --    Print(string.format('regist class %d (%s)', _class_id[v], _class_name))
    --else
    --    Print(string.format('regist class %d', _class_id[v]))
    --end
end

function RegisterClasses()
    for _, v in pairs(all_class) do
        RegisterGameClass(v)
    end
end

