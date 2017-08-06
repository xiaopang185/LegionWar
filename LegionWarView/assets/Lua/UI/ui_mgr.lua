local assert    = assert
local loadfile  = loadfile

local ui_mgr    = {}
local Ui_module = {}

function ui_mgr.dispatch(ui_name, action, ...)
    local ui = Ui_module[ui_name]
    assert(ui)
    return ui[action](...)
end

function ui_mgr.register_ui(ui_name)
    if Ui_module[ui_name] then
        error("ui_name has register")
        return
    end

    Ui_module = loadfile(ui_name)
end

return ui_mgr
