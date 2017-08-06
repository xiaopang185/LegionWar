local g_events  = require "config.events"
local event_mgr = require "Event.event_mgr"

local game_mgr  =
{
    n_pass_time     = 0,
    n_curr_time     = 0,
}

function game_mgr.init_game()

end

function game_mgr.world_time_update(passtime)
    -- print(game_mgr.n_pass_time, game_mgr.n_curr_time)
end

event_mgr.register_event(g_events.SYS_INIT,      game_mgr.init_game)
event_mgr.register_event(g_events.SYS_UPDATE,    game_mgr.world_time_update)

return game_mgr
