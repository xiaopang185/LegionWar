#include "LConfig.h"
#include "Common_cfg.h"
#include <QDebug>

extern "C"
{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

static int register_event_cfg(lua_State *L)
{
    if (!lua_istable(L, -1))
    {
        qDebug() << "arg not is a table";
        lua_pop(L, 1);
        return false;
    }


    int tableIndex = lua_gettop(L);
    // push the first key
    lua_pushnil(L);
    while (0 != lua_next(L, tableIndex))
    {
        if (lua_istable(L, -1))
        {
            qDebug() << "Cannot have nested tables ";
            return -1;
        }
        // stack : table key value
        const char *key = lua_tostring(L, -2);
        const int val    = lua_tonumber(L, -1);
        Singleton<Common_cfg>::getInstance().insertgEventnode(key, val);
        // Done, pop all fields
        lua_pop(L, 1); // stack : table key
    }
    // last key will pop the key, stack : table
    lua_pop(L, 1);

    return 1;
}

LUALIB_API luaopen_config(lua_State *L)
{
    luaL_Reg l[] =
    {
        {"register_event_cfg", register_event_cfg},
        {NULL, NULL}
    };

    luaL_newlib(L, l);
    return 1;
}
