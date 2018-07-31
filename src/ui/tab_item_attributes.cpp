#include <QVBoxLayout>
#include <ui/tab_item_attributes.h>
#include <model/mod.h>

TabItemAttributes::TabItemAttributes(Mod& mod, QWidget* parent) : TabBase("Item Attributes", mod.itemList, parent)
{

}