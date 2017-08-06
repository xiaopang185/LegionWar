#include "Common_cfg.h"
#include <qDebug>

Common_cfg::Common_cfg():
    g_events(new QMap<string, int>())
{

}

Common_cfg::~Common_cfg()
{
    g_events = nullptr;
}

int Common_cfg::get_event(const string& key) const
{
    return g_events->value(key, -1);
}

bool Common_cfg::insertgEventnode(const string& key, const int &value)
{
    if (get_event(key) >= 0)
    {
        qDebug() << key.c_str() << "the key has node";
        return false;
    }

    g_events->insert(key, value);
    return true;
}

QMap<string, int> *Common_cfg::getG_events() const
{
    return g_events;
}
