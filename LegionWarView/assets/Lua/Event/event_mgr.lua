local assert = assert
local event_mgr = {}
local events_func = {}

function event_mgr.dispatch(n_event_type, ...)
    local EVENT_FUNC = events_func[n_event_type]
    assert(EVENT_FUNC)
    return EVENT_FUNC(...)
end

function event_mgr.register_event(n_event_type, EVENT_FUNC)
    assert(type(EVENT_FUNC) == "function")
    if events_func[n_event_type] then
        print("n_event_type has register func")
        return
    end

    events_func[n_event_type] = EVENT_FUNC
end

return event_mgr
