#ifndef INCLUDED_UI_TAB_ITEMS_H
#define INCLUDED_UI_TAB_ITEMS_H

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
    QSpinBox*       _itemEditPalette;
    QSpinBox*       _itemEditSprite;
    QSpinBox*       _itemEditPrice;
    Mod&            _mod;
};

#endif