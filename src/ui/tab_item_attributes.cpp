#include <QVBoxLayout>
#include <ui/tab_item_attributes.h>

TabItemAttributes::TabItemAttributes(Mod& mod, QWidget* parent) : TabBase("Item Attributes", parent)
{
    layout()->addWidget(new QWidget);
}