#include "LuaIntf.h"
#include <QTime>
#include <QDateTime>
#include <QDebug>
#include <assert.h>
#include <string>
#include "Common_cfg.h"
#include "LConfig.h"

extern "C"
{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

#define LUA_GLOBALCONFIG(L, key, val) \
  lua_pushstring(L, key); \
  lua_pushnumber(L, val); \
  lua_settable(L, -3)


LuaIntf::LuaIntf():
    m_context(NULL)
{

}

LuaIntf::~LuaIntf()
{

}

void LuaIntf::loadScript()
{
    m_context = luaL_newstate();
    luaL_openlibs(m_context);
    loadGlobalConfig();
    luaL_loadfile(m_context, "./assets/Lua/main.lua");
    int ret = lua_pcall(m_context, 0, 0, 0);

    if ( ret != 0 )
    {
        const char* err = lua_tostring(m_context, -1);
        qDebug() << "Error: " << err;
        assert(false);
        lua_pop(m_context, 1);
    }
}

bool LuaIntf::loadGlobalConfig()
{
    luaL_requiref(m_context, "config", luaopen_config,1);
    return true;
}

bool LuaIntf::notificationScriptMsg(int n_msg_id, char *s_msg_data)
{
    lua_getglobal(m_context, "main");
    lua_pushstring(m_context, "Net");
    lua_pushnumber(m_context, getCurrTime());
    lua_pushnumber(m_context, n_msg_id);
    lua_pushstring(m_context, s_msg_data);
    int ret = lua_pcall(m_context, 4, 1, 0);
    if ( ret != 0 )
    {
        const char* err = lua_tostring(m_context, -1);
        qDebug() << "Error: " << err;
        lua_pop(m_context, 1);
        return false;
    }
    return true;
}

bool LuaIntf::notificationScriptEvent(int n_event_type)
{
    lua_getglobal(m_context, "main");
    lua_pushstring(m_context, "event");
    lua_pushnumber(m_context, getCurrTime());
    lua_pushnumber(m_context, n_event_type);
    int ret = lua_pcall(m_context, 3, 1, 0);
    if ( ret != 0 )
    {
        const char* err = lua_tostring(m_context, -1);
        qDebug() << "Error: " << err;
        lua_pop(m_context, 1);
        return false;
    }
    return true;
}


bool LuaIntf::notiicationScriptUi(char *s_action)
{
    lua_getglobal(m_context, "main");
    lua_pushstring(m_context, "UI");
    lua_pushnumber(m_context, getCurrTime());
    lua_pushstring(m_context, s_action);
    int ret = lua_pcall(m_context, 3, 1, 0);
    if ( ret != 0 )
    {
        const char* err = lua_tostring(m_context, -1);
        qDebug() << "Error: " << err;
        lua_pop(m_context, 1);
        return false;
    }
    return true;
}

qint64 LuaIntf::getCurrTime()
{
    QTime timer = QTime::currentTime();
    qint64 n_currtime = QDateTime::currentDateTime().toTime_t();
    n_currtime = n_currtime*1000 + timer.msec();
    return n_currtime;
}
