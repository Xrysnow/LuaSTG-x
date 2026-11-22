---del对象的附属，将对象状态置为'del'
function RawDel(o)
    if o then
        o.status = 'del'
        if o._servants then
            _del_servants(o)
        end
    end
end

---kill对象的附属，将对象状态置为'kill'
function RawKill(o)
    if o then
        o.status = 'kill'
        if o._servants then
            _kill_servants(o)
        end
    end
end

---将对象状态置为'normal'
function PreserveObject(o)
    o.status = 'normal'
end

--重写内置的Kill，kill对象的附属
do
    local old = lstg.Kill
    function Kill(o)
        if o then
            if o._servants then
                _kill_servants(o)
            end
            old(o)
        end
    end
end
--重写内置的Del，del对象的附属
do
    local old = lstg.Del
    function Del(o)
        if o then
            if o._servants then
                _del_servants(o)
            end
            old(o)
        end
    end
end
