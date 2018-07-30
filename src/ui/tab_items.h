#ifndef INCLUDED_UI_TAB_ITEMS_H
#define INCLUDED_UI_TAB_ITEMS_H

#include <ui/tab_base.h>

struct Mod;
class TabItems : public TabBase
{
    Q_OBJECT

public:
    explicit TabItems(Mod& mod, QWidget* parent = nullptr);
};

#endif