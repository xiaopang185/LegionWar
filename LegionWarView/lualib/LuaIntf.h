#ifndef LUAINTF_H
#define LUAINTF_H

#include <map>
#include <string>
using namespace std;

extern "C"
{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

#include "Singleton.h"

class LuaIntf
{
    SINGLETON(LuaIntf)

public:
    bool notiicationScriptUi(char *s_action, const char* data = "");
    bool notificationScriptMsg(int n_msg_id, char* s_msg_data);
    bool notificationScriptEvent(int n_event_type, const char* data = "");

public:
    void loadScript();

private:
    bool loadGlobalConfig();
    qint64 getCurrTime();

private:
    lua_State *m_context;
};

#endif // LUAINTF_H
