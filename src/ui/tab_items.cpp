#include <QVBoxLayout>
#include <ui/tab_items.h>
#include <model/mod.h>

TabItems::TabItems(Mod& mod, QWidget* parent) : TabBase("Items", parent)
{
    _listView->setModel(mod.itemList);
    layout()->addWidget(new QWidget);
}