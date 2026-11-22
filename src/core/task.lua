---@type task
task = {}

---@class task
local task = task
task.stack = {}
task.co = {}

local max = math.max
local int = math.floor
local yield = coroutine.yield
local resume = coroutine.resume
local insert = table.insert
local ipairs = ipairs
local pairs = pairs
local status = coroutine.status
local rawget = rawget

--lstg._ntask = 0
-- merge task from ex

---新建任务 添加一个执行f的协程
---@param f function 要执行的函数
function task:New(f)
    if not self.task then
        self.task = {}
        --if not self.task then
        --    error('???')
        --end
    end
    local rt = coroutine.create(f)
    insert(self.task, rt)
    return rt
end

--TODO

---执行（resume）task中的协程
function task:Do()
    local tsk = rawget(self, 'task')
    --if tsk and #tsk > 0 then
    if tsk then
        --local task_stack = task.stack
        --local task_co = task.co
        --for _, co in ipairs(tsk) do
        for _, co in pairs(tsk) do
            if status(co) ~= 'dead' then
                insert(task.stack, self)
                insert(task.co, co)

                local _, errmsg = resume(co)
                if errmsg then
                    error(errmsg)
                end

                task.stack[#task.stack] = nil
                task.co[#task.co] = nil
                --lstg._ntask = lstg._ntask + 1
            end
        end
    end
end

---清空task
function task:Clear(keepself)
    if keepself then
        local flag = false
        local co = task.co[#task.co]
        for i = 1, #self.task do
            if self.task[i] == co then
                flag = true
                break
            end
        end
        self.task = nil
        if flag then
            self.task = {}
            self.task[1] = co
        end
    else
        self.task = nil
    end
end

---延时t帧（挂起协程t次）,t省略则为1
---@param t number
function task.Wait(t)
    t = t or 1
    t = max(1, int(t))
    for i = 1, t do
        yield()
    end
end

---延时至timer达到t（挂起协程）
---@param t number
function task.Until(t)
    t = int(t)
    while task.GetSelf().timer < t do
        yield()
    end
end

---获取当前任务（协程）对应的对象
function task.GetSelf()
    local c = task.stack[#task.stack]
    if c.taskself then
        return c.taskself
    else
        return c
    end
end


--region Move Mode
MOVE_NORMAL = 0
MOVE_ACCEL = 1
MOVE_DECEL = 2
MOVE_ACC_DEC = 3

MOVE_TOWARDS_PLAYER = 0
MOVE_X_TOWARDS_PLAYER = 1
MOVE_Y_TOWARDS_PLAYER = 2
MOVE_RANDOM = 3
--endregion


---直线移动
---x,y：目标点
---t：所需帧数
---mode：缓冲模式 使用二次函数
--->  MOVE_NORMAL=0
--->  MOVE_ACCEL=1
--->  MOVE_DECEL=2
--->  MOVE_ACC_DEC=3
function task.MoveTo(x, y, t, mode)
    local self = task.GetSelf()
    t = int(t)
    t = max(1, t)
    local dx = x - self.x
    local dy = y - self.y
    local xs = self.x
    local ys = self.y
    if mode == 1 then
        for s = 1 / t, 1 + 0.5 / t, 1 / t do
            s = s * s
            self.x = xs + s * dx
            self.y = ys + s * dy
            coroutine.yield()
        end
    elseif mode == 2 then
        for s = 1 / t, 1 + 0.5 / t, 1 / t do
            s = s * 2 - s * s
            self.x = xs + s * dx
            self.y = ys + s * dy
            coroutine.yield()
        end
    elseif mode == 3 then
        for s = 1 / t, 1 + 0.5 / t, 1 / t do
            if s < 0.5 then
                s = s * s * 2
            else
                s = -2 * s * s + 4 * s - 1
            end
            self.x = xs + s * dx
            self.y = ys + s * dy
            coroutine.yield()
        end
    else
        for s = 1 / t, 1 + 0.5 / t, 1 / t do
            self.x = xs + s * dx
            self.y = ys + s * dy
            coroutine.yield()
        end
    end
end

---贝塞尔曲线移动
---t：所需帧数
---mode：缓冲模式 使用二次函数
--->  MOVE_NORMAL=0
--->  MOVE_ACCEL=1
--->  MOVE_DECEL=2
--->  MOVE_ACC_DEC=3
---...：控制点 x1,y1,x2,y2,...
function task.BezierMoveTo(t, mode, ...)

    local arg = { ... }
    local self = task.GetSelf()
    t = int(t)
    t = max(1, t)
    local count = (#arg) / 2
    local x = {}
    local y = {}
    x[1] = self.x
    y[1] = self.y
    for i = 1, count do
        x[i + 1] = arg[i * 2 - 1]
        y[i + 1] = arg[i * 2]
    end
    local com_num = {}
    for i = 0, count do
        com_num[i + 1] = combinNum(i, count)
    end
    if mode == 1 then
        for s = 1 / t, 1 + 0.5 / t, 1 / t do
            s = s * s
            local _x, _y = 0, 0
            for j = 0, count do
                _x = _x + x[j + 1] * com_num[j + 1] * (1 - s) ^ (count - j) * s ^ (j)
                _y = _y + y[j + 1] * com_num[j + 1] * (1 - s) ^ (count - j) * s ^ (j)
            end
            self.x = _x
            self.y = _y
            coroutine.yield()
        end
    elseif mode == 2 then
        for s = 1 / t, 1 + 0.5 / t, 1 / t do
            s = s * 2 - s * s
            local _x, _y = 0, 0
            for j = 0, count do
                _x = _x + x[j + 1] * com_num[j + 1] * (1 - s) ^ (count - j) * s ^ (j)
                _y = _y + y[j + 1] * com_num[j + 1] * (1 - s) ^ (count - j) * s ^ (j)
            end
            self.x = _x
            self.y = _y
            coroutine.yield()
        end
    elseif mode == 3 then
        for s = 1 / t, 1 + 0.5 / t, 1 / t do
            if s < 0.5 then
                s = s * s * 2
            else
                s = -2 * s * s + 4 * s - 1
            end
            local _x, _y = 0, 0
            for j = 0, count do
                _x = _x + x[j + 1] * com_num[j + 1] * (1 - s) ^ (count - j) * s ^ (j)
                _y = _y + y[j + 1] * com_num[j + 1] * (1 - s) ^ (count - j) * s ^ (j)
            end
            self.x = _x
            self.y = _y
            coroutine.yield()
        end
    else
        for s = 1 / t, 1 + 0.5 / t, 1 / t do
            local _x, _y = 0, 0
            for j = 0, count do
                _x = _x + x[j + 1] * com_num[j + 1] * (1 - s) ^ (count - j) * s ^ (j)
                _y = _y + y[j + 1] * com_num[j + 1] * (1 - s) ^ (count - j) * s ^ (j)
            end
            self.x = _x
            self.y = _y
            coroutine.yield()
        end
    end
end

---向自机（随机）移动
---t：所需帧数
---x1,x2,y1,y2：移动区域限制
---dxmin,dxmax,dymin,dymax：移动距离的范围
---mmode：直线移动模式 参考MoveTo
---dmode：整体移动模式
--->  MOVE_TOWARDS_PLAYER = 0
--->  MOVE_X_TOWARDS_PLAYER = 1
--->  MOVE_Y_TOWARDS_PLAYER = 2
--->  MOVE_RANDOM = 3
function task.MoveToPlayer(t, x1, x2, y1, y2, dxmin, dxmax, dymin, dymax, mmode, dmode)
    local dirx, diry = ran:Sign(), ran:Sign()
    local self = task.GetSelf()
    if dmode < 2 then
        if self.x > lstg.player.x then
            dirx = -1
        else
            dirx = 1
        end
    end
    if dmode == 0 or dmode == 2 then
        if self.y > lstg.player.y then
            diry = -1
        else
            diry = 1
        end
    end
    local dx = ran:Float(dxmin, dxmax)
    local dy = ran:Float(dymin, dymax)
    --	local angle = ran:Float(0,90)
    --	local dx, dy = d*cos(angle), d*sin(angle)
    if self.x + dx * dirx < x1 then
        dirx = 1
    end
    if self.x + dx * dirx > x2 then
        dirx = -1
    end
    if self.y + dy * diry < y1 then
        diry = 1
    end
    if self.y + dy * diry > y2 then
        diry = -1
    end
    task.MoveTo(self.x + dx * dirx, self.y + dy * diry, t, mmode)
end
