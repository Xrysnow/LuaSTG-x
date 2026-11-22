--[[

Copyright (c) 2014-2017 Chukong Technologies Inc.
Copyright (c) 2022 Bytedance Inc.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

]]

table.unpack = table.unpack or unpack
math.pow = math.pow or function(x, y) return x ^ y end

-- Legacy method aliases within the directly registered cc table.
cc.Director.setDisplayStats = cc.Director.setStatsDisplay
cc.Sprite3D = cc.MeshRenderer

require "cocos.cocos2d.Cocos2d"
require "cocos.cocos2d.Cocos2dConstants"
require "cocos.cocos2d.functions"
if cc.FileDialog then
    require "cocos.cocos2d.FileDialog"
end

__G__TRACKBACK__ = function(msg)
    msg = debug.traceback(msg, 3)
    print(msg)
    return msg
end

-- ui
if nil ~= ccui then
    require "cocos.ui.GuiConstants"
end

-- extensions
require "cocos.extension.ExtensionConstants"
require "cocos.3d.3dConstants"
-- network
require "cocos.network.NetworkConstants"
-- Spine
if nil ~= sp then
    require "cocos.spine.SpineConstants"
end

-- physics3d
require "cocos.physics3d.physics3d-constants"

if CC_USE_FRAMEWORK then
    require "cocos.framework.init"
end
