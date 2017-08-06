local UI_Prepare_battle = {}
local ui_mgr = require "UI.ui_mgr"
ui_mgr.register_ui("UI_Prepare_battle")

function UI_Prepare_battle.OnStartBattle()
    print("OnStartBattle")
end

return UI_Prepare_battle
