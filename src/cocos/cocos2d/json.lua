-- The engine registers lua-cjson. Keep the names used by existing Lua scripts.
local json = cjson or require("cjson")
_G.json = json
package.loaded.json = json
return json
