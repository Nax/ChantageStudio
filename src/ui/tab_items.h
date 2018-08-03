#ifndef INCLUDED_UI_TAB_ITEMS_H
#define INCLUDED_UI_TAB_ITEMS_H

#include <QCheckBox>
#include <QLineEdit>
#include <QSpinBox>
#include <ui/tab_base.h>

struct Mod;
class TabItems : public TabBase
{
    Q_OBJECT

public:
    explicit TabItems(Mod& mod, QWidget* parent = nullptr);

private slots:
    void refreshUi(int index);

private:
    QLineEdit*      _itemEditName;
    QSpinBox*       _itemEditSprite;
    QSpinBox*       _itemEditPalette;
    QSpinBox*       _itemEditLevel;
    QCheckBox*      _itemEditRare;
    QSpinBox*       _itemEditPrice;
    QSpinBox*       _itemEditShop;
    Mod&            _mod;
};

#endif