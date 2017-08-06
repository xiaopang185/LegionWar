#ifndef COMMON_CFG_H
#define COMMON_CFG_H

#include <QMap>
#include <string>
#include "singleton.h"

using namespace std;

class Common_cfg
{
    SINGLETON(Common_cfg)

public:
    int get_event(const string &key)const;
    bool insertgEventnode(const string &key, const int &value);

    QMap<string, int> *getG_events() const;

private:
    QMap<string, int> *g_events;
};

#endif // COMMON_CFG_H
