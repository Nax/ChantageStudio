#ifndef INCLUDED_UI_TAB_ITEMS_H
#define INCLUDED_UI_TAB_ITEMS_H

#include <QStackedWidget>
#include <QComboBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QSpinBox>
#include <ui/tab_base.h>
#include <model/item.h>
#include <model/item_type_list.h>
#include <ui/elements_editor.h>
#include <ui/weapon_flags_editor.h>

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
    Item*               _item;
    ItemTypeList*       _itemTypeModel;
    QStackedWidget*     _widgetStack;
    QLineEdit*          _itemEditName;
    QComboBox*          _itemEditType;
    QSpinBox*           _itemEditSprite;
    QSpinBox*           _itemEditPalette;
    QSpinBox*           _itemEditLevel;
    QCheckBox*          _itemEditRare;
    QSpinBox*           _itemEditPrice;
    QSpinBox*           _itemEditShop;
    QSpinBox*           _itemEditAttributesId;
    QSpinBox*           _itemEditShieldPhysicalBlock;
    QSpinBox*           _itemEditShieldMagicalBlock;
    QSpinBox*           _itemEditArmorHp;
    QSpinBox*           _itemEditArmorMp;
    QSpinBox*           _itemEditChemistFormula;
    QSpinBox*           _itemEditChemistZ;
    QSpinBox*           _itemEditChemistStatus;
    QSpinBox*           _itemEditWeaponRange;
    QSpinBox*           _itemEditWeaponFormula;
    QSpinBox*           _itemEditWeaponPower;
    QSpinBox*           _itemEditWeaponEvade;
    QSpinBox*           _itemEditWeaponStatus;
    WeaponFlagsEditor*  _itemEditWeaponFlags;
    ElementsEditor*     _itemEditWeaponElements;
    Mod&                _mod;
};

#endif