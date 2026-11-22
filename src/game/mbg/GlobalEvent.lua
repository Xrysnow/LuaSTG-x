---@class lstg.mbg.GlobalEvent
local M = class('lstg.mbg.GlobalEvent')

function M:ctor()
    self.isgoto = false
    self.gotocondition = 0
    self.gotoopreator = ""
    self.gotocvalue = 0
    self.gototime = 0
    self.gotowhere = 0
    self.gtcount = 0
    self.isquake = false
    self.quakecondition = 0
    self.quakeopreator = ""
    self.quakecvalue = 0
    self.quaketime = 0
    self.quakelevel = 0
    self.qtcount = 0
    self.isstop = false
    self.stopcondition = 0
    self.stopopreator = ""
    self.stopcvalue = 0
    self.stoptime = 0
    self.stcount = 0
    self.stoplevel = 0
end

return M
