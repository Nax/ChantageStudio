#ifndef INCLUDED_UI_TAB_ITEM_ATTRIBUTES_H
#define INCLUDED_UI_TAB_ITEM_ATTRIBUTES_H

#include <ui/tab_base.h>

struct Mod;
class TabItemAttributes : public TabBase
{
    Q_OBJECT

public:
    explicit TabItemAttributes(Mod& mod, QWidget* parent = nullptr);
};

#endif