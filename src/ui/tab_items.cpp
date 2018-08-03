#include <QLineEdit>
#include <QLabel>
#include <ui/tab_items.h>
#include <model/mod.h>

TabItems::TabItems(Mod& mod, QWidget* parent) : TabBase("Items", mod.itemList, parent), _mod(mod)
{
    QGridLayout* itemForm = new QGridLayout;
    itemForm->setColumnMinimumWidth(0, 50);
    itemForm->setColumnMinimumWidth(2, 40);

    _itemEditName = new QLineEdit;
    _itemEditName->setFixedWidth(100);
    itemForm->addWidget(new QLabel("Name"), 0, 0);
    itemForm->addWidget(_itemEditName, 0, 1);

    _itemEditSprite = new QSpinBox;
    _itemEditSprite->setDisplayIntegerBase(16);
    _itemEditSprite->setPrefix("0x");
    _itemEditSprite->setFixedWidth(60);
    _itemEditSprite->setRange(0, 255);
    itemForm->addWidget(new QLabel("Sprite"), 1, 0);
    itemForm->addWidget(_itemEditSprite, 1, 1);

    _itemEditPalette = new QSpinBox;
    _itemEditPalette->setDisplayIntegerBase(16);
    _itemEditPalette->setPrefix("0x");
    _itemEditPalette->setFixedWidth(60);
    _itemEditPalette->setRange(0, 255);
    itemForm->addWidget(new QLabel("Palette"), 1, 2);
    itemForm->addWidget(_itemEditPalette, 1, 3);

    _itemEditLevel = new QSpinBox;
    _itemEditLevel->setFixedWidth(60);
    _itemEditLevel->setRange(0, 255);
    itemForm->addWidget(new QLabel("Level"), 2, 0);
    itemForm->addWidget(_itemEditLevel, 2, 1);

    _itemEditRare = new QCheckBox;
    itemForm->addWidget(new QLabel("Rare"), 2, 2);
    itemForm->addWidget(_itemEditRare, 2, 3);

    _itemEditPrice = new QSpinBox;
    _itemEditPrice->setFixedWidth(60);
    _itemEditPrice->setRange(0, 65535);
    itemForm->addWidget(new QLabel("Price"), 3, 0);
    itemForm->addWidget(_itemEditPrice, 3, 1);

    _itemEditShop = new QSpinBox;
    _itemEditShop->setDisplayIntegerBase(16);
    _itemEditShop->setPrefix("0x");
    _itemEditShop->setFixedWidth(60);
    _itemEditShop->setRange(0, 255);
    itemForm->addWidget(new QLabel("Shop"), 3, 2);
    itemForm->addWidget(_itemEditShop, 3, 3);

    itemForm->setColumnStretch(itemForm->columnCount(), 1);
    itemForm->setRowStretch(itemForm->rowCount(), 1);

    _layout->addLayout(itemForm, 1, 0);

    _mapper->addMapping(_itemEditName,  1);
    _mapper->addMapping(_itemEditSprite, 2);
    _mapper->addMapping(_itemEditPalette, 3);
    _mapper->addMapping(_itemEditLevel, 4);
    _mapper->addMapping(_itemEditRare, 5);
    _mapper->addMapping(_itemEditPrice, 6);
    _mapper->addMapping(_itemEditShop, 7);
    connect(_mapper, SIGNAL(currentIndexChanged(int)), this, SLOT(refreshUi(int)));
    _mapper->toFirst();
}

void TabItems::refreshUi(int index)
{
    const Item& item = _mod.itemList->get(index);
    bool disabled = item.internal;

    _itemEditName->setDisabled(disabled);
    _itemEditSprite->setDisabled(disabled);
    _itemEditPalette->setDisabled(disabled);
    _itemEditLevel->setDisabled(disabled);
    _itemEditRare->setDisabled(disabled);
    _itemEditPrice->setDisabled(disabled);
    _itemEditShop->setDisabled(disabled);
}