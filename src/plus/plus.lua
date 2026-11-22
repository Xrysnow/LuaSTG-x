---luastg+ 专用强化脚本库
---该脚本库完全独立于lstg的老lua代码
---所有功能函数暴露在全局plus表中
---by CHU

plus         = {}

local DoFile = DoFile or lstg.DoFile
DoFile("plus/Utility.lua")
DoFile("plus/NativeAPI.lua")
DoFile("plus/IO.lua")
DoFile("plus/Replay.lua")
DoFile("plus/ReplayCompat.lua")
