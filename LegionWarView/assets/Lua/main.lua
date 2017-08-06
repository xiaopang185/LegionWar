local print     = print
local config    = require "config"
package.path = "./assets/Lua/?.lua";

local event_mgr = require "Event.event_mgr"
local ui_mgr    = require "UI.ui_mgr"
local game_mgr = require "game_mgr"
local g_events = require "config.events"

local function init()
    config.register_event_cfg(g_events)
end

local function dispatch(mode, ...)
    if mode == "UI" then
        ui_mgr.dispatch(...)

    elseif mode == "event" then
        event_mgr.dispatch(...)

    elseif mode == "Net" then
        -- Net_mgr.dispatch(...)

    end
end

function main(mode, n_curr_time, ...)
    game_mgr.n_curr_time = n_curr_time
    game_mgr.n_pass_time = os.clock() * 1000

    dispatch(mode, ...)
    return
end

init()
