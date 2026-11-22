--
local M = {}

---@type cc.Scene
local DemoScene = class('fgui.scene', cc.Scene)
M.DemoScene = DemoScene

function DemoScene:ctor()
    local director = cc.Director:getInstance()
    --director:setClearColor(cc.c4f(0x36 / 255, 0x3B / 255, 0x44 / 255, 0xFF / 255))

    if true then
        local sp = cc.Sprite:create('joystick_bg.png')
        self:addChild(sp)
        sp:setPosition(100, 100)
        return
    end

    --cc.Scene.init(self)
    self._groot = fgui.GRoot:create(self)
    self._groot:retain()
    self['.dtor'] = function()
        self._groot:release()
        print('self c dtor')
    end
    self:continueInit()
end

function DemoScene:continueInit()
    fgui.UIPackage:addPackage("FGUI/Package1")
    local view = fgui.UIPackage:createObject("Package1", "Component1"):asGComponent()
    assert(view)
    self._view = view
    self._groot:addChild(self._view)
    local sz = view:getSize()
    local des = cc.Director:getInstance():getOpenGLView():getDesignResolutionSize()
    local scale = math.min(des.x / sz.x, des.y / sz.y)
    view:setScale(scale, scale)
    --
    local lb_note = view:getChild('lb_note'):asGTextField()
    assert(lb_note)
    local inf = 'LuaSTG-x'
    if plus.platform ~= 'unknown' then
        inf = ('%s for %s'):format(inf, plus.platform)
    end
    local ret = lb_note:setText(inf)
    print(ret)
    local pos = lb_note:getPosition()
    print(('%d, %d'):format(pos.x, pos.y))
    print(('%d, %d'):format(lb_note:getWidth(), lb_note:getParent():getWidth()))
end

function M.show()

    local scene = DemoScene()
    display.runScene(scene)
end

return M
