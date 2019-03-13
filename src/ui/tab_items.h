#ifndef INCLUDED_UI_TAB_ITEMS_H
#define INCLUDED_UI_TAB_ITEMS_H

#include <QStackedWidget>
#include <QComboBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QSpinBox>
#include <QDataWidgetMapper>
#include <QListView>
#include <model/item.h>
#include <model/item_type_list.h>
#include <ui/elements_editor.h>
#include <ui/status_editor.h>
#include <ui/weapon_flags_editor.h>

struct Mod;
class TabItems : public QWidget
{
    Q_OBJECT

public:
    explicit TabItems(Mod& mod, QWidget* parent = nullptr);

private slots:
    void selectItem(const QItemSelection& selection);
    void refreshUi(int index);
    void itemTypeChanged(int index);

private:
    Item*               _item;
    ItemTypeList*       _itemTypeModel;
    QDataWidgetMapper*  _mapper;
    QListView*          _listView;
    QStackedWidget*     _widgetStack;
    QLineEdit*          _itemEditName;
    QPlainTextEdit*     _itemEditDescription;
    QComboBox*          _itemEditType;
    QSpinBox*           _itemEditSprite;
    QSpinBox*           _itemEditPalette;
    QSpinBox*           _itemEditLevel;
    QCheckBox*          _itemEditRare;
    QSpinBox*           _itemEditPrice;
    QSpinBox*           _itemEditShop;
    QSpinBox*           _itemEditPa;
    QSpinBox*           _itemEditMa;
    QSpinBox*           _itemEditMove;
    QSpinBox*           _itemEditJump;
    QSpinBox*           _itemEditSpeed;
    ElementsEditor*     _itemEditElementsAbsorb;
    ElementsEditor*     _itemEditElementsCancel;
    ElementsEditor*     _itemEditElementsHalf;
    ElementsEditor*     _itemEditElementsWeak;
    ElementsEditor*     _itemEditElementsStrengthen;
    StatusEditor*       _itemEditStatusPermanent;
    StatusEditor*       _itemEditStatusImmune;
    StatusEditor*       _itemEditStatusStart;
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