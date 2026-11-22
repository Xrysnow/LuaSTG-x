---
--- __init__.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---

Include('core_x/import.lua')

for _, n in ipairs({ 'std', 'table', 'util', 'ext' }) do
    require('core_x.' .. n)
end
require('math.__init__')

lstg.eventDispatcher = require('core_x.EventDispatcher').create()
lstg.fs = require('core_x.fs')

require('core_x.symbol')
