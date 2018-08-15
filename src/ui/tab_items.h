#ifndef INCLUDED_UI_TAB_ITEMS_H
#define INCLUDED_UI_TAB_ITEMS_H

#include <QComboBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QSpinBox>
#include <ui/tab_base.h>
#include <model/item.h>
#include <model/item_type_list.h>

struct Mod;
class TabItems : public TabBase
{
    Q_OBJECT

public:
    explicit TabItems(Mod& mod, QWidget* parent = nullptr);

private slots:
    void refreshUi(int index);
    void itemTypeChanged(int index);

private:
    Item*           _item;
    ItemTypeList*   _itemTypeModel;
    QLineEdit*      _itemEditName;
    QComboBox*      _itemEditType;
    QSpinBox*       _itemEditSprite;
    QSpinBox*       _itemEditPalette;
    QSpinBox*       _itemEditLevel;
    QCheckBox*      _itemEditRare;
    QSpinBox*       _itemEditPrice;
    QSpinBox*       _itemEditShop;
    QSpinBox*       _itemEditAttributesId;
    Mod&            _mod;
};

#endif