lstg.quit_flag = false
lstg.paused = false

---一些游戏中的全局变量
lstg.var = { username = setting.username }
lstg.tmpvar = {}

---将k,v存入lstg.var
function SetGlobal(k, v)
    lstg.var[k] = v
end

---从lstg.var取出k对应的值
function GetGlobal(k, v)
    return lstg.var[k]
end

