--
if imgui then
    require('imgui.enum')
    require('imgui.helper')

    for _, v in pairs({ imgui.ColorTextEdit }) do
        local mt = getmetatable(v)
        if mt and (v.create or v.new) then
            if v.create then
                mt.__call = function(t, ...)
                    return t:create(...)
                end
            else
                mt.__call = function(t, ...)
                    return t:new(...)
                end
            end
        end
    end
end
