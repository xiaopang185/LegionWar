#ifndef LCONFIG_H
#define LCONFIG_H

extern "C"
{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

static int register_event_cfg(lua_State *L);
LUALIB_API luaopen_config(lua_State *L);

#endif // LCONFIG_H
