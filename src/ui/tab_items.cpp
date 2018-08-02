#include <QLineEdit>
#include <QLabel>
#include <ui/tab_items.h>
#include <model/mod.h>

TabItems::TabItems(Mod& mod, QWidget* parent) : TabBase("Items", mod.itemList, parent), _mod(mod)
{
    QGridLayout* itemForm = new QGridLayout;
    itemForm->setColumnMinimumWidth(0, 60);
    itemForm->setColumnMinimumWidth(2, 60);

    _itemEditName = new QLineEdit;
    _itemEditName->setFixedWidth(100);
    itemForm->addWidget(new QLabel("Name"), 0, 0);
    itemForm->addWidget(_itemEditName, 0, 1);

    _itemEditPalette = new QSpinBox;
    _itemEditPalette->setDisplayIntegerBase(16);
    _itemEditPalette->setPrefix("0x");
    _itemEditPalette->setFixedWidth(60);
    _itemEditPalette->setRange(0, 255);
    itemForm->addWidget(new QLabel("Palette"), 1, 0);
    itemForm->addWidget(_itemEditPalette, 1, 1);

    _itemEditSprite = new QSpinBox;
    _itemEditSprite->setDisplayIntegerBase(16);
    _itemEditSprite->setPrefix("0x");
    _itemEditSprite->setFixedWidth(60);
    _itemEditSprite->setRange(0, 255);
    itemForm->addWidget(new QLabel("Sprite"), 1, 2);
    itemForm->addWidget(_itemEditSprite, 1, 3);

    _itemEditPrice = new QSpinBox;
    _itemEditPrice->setFixedWidth(60);
    _itemEditPrice->setRange(0, 65535);
    itemForm->addWidget(new QLabel("Price"), 2, 0);
    itemForm->addWidget(_itemEditPrice, 2, 1);

    itemForm->setColumnStretch(itemForm->columnCount(), 1);
    itemForm->setRowStretch(itemForm->rowCount(), 1);

    _layout->addLayout(itemForm, 1, 0);

    _mapper->addMapping(_itemEditName,  1);
    _mapper->addMapping(_itemEditPalette, 2);
    _mapper->addMapping(_itemEditSprite, 3);
    _mapper->addMapping(_itemEditPrice, 4);
    connect(_mapper, SIGNAL(currentIndexChanged(int)), this, SLOT(refreshUi(int)));
    _mapper->toFirst();
}

void TabItems::refreshUi(int index)
{
    const Item& item = _mod.itemList->get(index);
    bool disabled = item.internal;

    _itemEditName->setDisabled(disabled);
    _itemEditPalette->setDisabled(disabled);
    _itemEditSprite->setDisabled(disabled);
    _itemEditPrice->setDisabled(disabled);
}