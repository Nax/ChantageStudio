#include <QLineEdit>
#include <QLabel>
#include <QGroupBox>
#include <ui/tab_items.h>
#include <model/mod.h>

TabItems::TabItems(Mod& mod, QWidget* parent) : TabBase("Items", mod.itemList, parent), _mod(mod)
{
    QGridLayout* itemForm = new QGridLayout;
    itemForm->setColumnMinimumWidth(0, 50);
    itemForm->setColumnMinimumWidth(2, 40);

    _itemTypeModel = new ItemTypeList;

    _itemEditName = new QLineEdit;
    _itemEditName->setFixedWidth(200);
    itemForm->addWidget(new QLabel("Name"), 0, 0);
    itemForm->addWidget(_itemEditName, 0, 1, 1, 3);

    _itemEditType = new QComboBox;
    _itemEditType->setFixedWidth(200);
    _itemEditType->setModel(_itemTypeModel);
    _itemEditType->setModelColumn(1);
    itemForm->addWidget(new QLabel("Type"), 1, 0);
    itemForm->addWidget(_itemEditType, 1, 1, 1, 3);
    connect(_itemEditType, SIGNAL(currentIndexChanged(int)), this, SLOT(itemTypeChanged(int)));

    _itemEditSprite = new QSpinBox;
    _itemEditSprite->setDisplayIntegerBase(16);
    _itemEditSprite->setPrefix("0x");
    _itemEditSprite->setFixedWidth(60);
    _itemEditSprite->setRange(0, 255);
    itemForm->addWidget(new QLabel("Sprite"), 2, 0);
    itemForm->addWidget(_itemEditSprite, 2, 1);

    _itemEditPalette = new QSpinBox;
    _itemEditPalette->setDisplayIntegerBase(16);
    _itemEditPalette->setPrefix("0x");
    _itemEditPalette->setFixedWidth(60);
    _itemEditPalette->setRange(0, 255);
    itemForm->addWidget(new QLabel("Palette"), 2, 2);
    itemForm->addWidget(_itemEditPalette, 2, 3);

    _itemEditLevel = new QSpinBox;
    _itemEditLevel->setFixedWidth(60);
    _itemEditLevel->setRange(0, 255);
    itemForm->addWidget(new QLabel("Level"), 3, 0);
    itemForm->addWidget(_itemEditLevel, 3, 1);

    _itemEditRare = new QCheckBox;
    itemForm->addWidget(new QLabel("Rare"), 3, 2);
    itemForm->addWidget(_itemEditRare, 3, 3);

    _itemEditPrice = new QSpinBox;
    _itemEditPrice->setFixedWidth(60);
    _itemEditPrice->setRange(0, 65535);
    itemForm->addWidget(new QLabel("Price"), 4, 0);
    itemForm->addWidget(_itemEditPrice, 4, 1);

    _itemEditShop = new QSpinBox;
    _itemEditShop->setDisplayIntegerBase(16);
    _itemEditShop->setPrefix("0x");
    _itemEditShop->setFixedWidth(60);
    _itemEditShop->setRange(0, 255);
    itemForm->addWidget(new QLabel("Shop"), 4, 2);
    itemForm->addWidget(_itemEditShop, 4, 3);

    _itemEditAttributesId = new QSpinBox;
    _itemEditAttributesId->setDisplayIntegerBase(16);
    _itemEditAttributesId->setPrefix("0x");
    _itemEditAttributesId->setFixedWidth(60);
    _itemEditAttributesId->setRange(0, 255);
    itemForm->addWidget(new QLabel("Attributes ID"), 5, 0);
    itemForm->addWidget(_itemEditAttributesId, 5, 1);

    QGroupBox* blockGroup = new QGroupBox("Block / Evade");
    QGridLayout* blockLayout = new QGridLayout;

    _itemEditPhysicalBlock = new QSpinBox;
    _itemEditPhysicalBlock->setSuffix("%");
    _itemEditPhysicalBlock->setFixedWidth(60);
    _itemEditPhysicalBlock->setRange(0, 255);
    blockLayout->addWidget(new QLabel("Physical Block / Evade"), 0, 0);
    blockLayout->addWidget(_itemEditPhysicalBlock, 0, 1);

    _itemEditMagicalBlock = new QSpinBox;
    _itemEditMagicalBlock->setSuffix("%");
    _itemEditMagicalBlock->setFixedWidth(60);
    _itemEditMagicalBlock->setRange(0, 255);
    blockLayout->addWidget(new QLabel("Magical Block / Evade"), 1, 0);
    blockLayout->addWidget(_itemEditMagicalBlock, 1, 1);
    blockGroup->setLayout(blockLayout);

    QGroupBox* armorGroup = new QGroupBox("Armor");
    QGridLayout* armorLayout = new QGridLayout;

    _itemEditHp = new QSpinBox;
    _itemEditHp->setFixedWidth(60);
    _itemEditHp->setRange(0, 255);
    armorLayout->addWidget(new QLabel("HP"), 0, 0);
    armorLayout->addWidget(_itemEditHp, 0, 1);

    _itemEditMp = new QSpinBox;
    _itemEditMp->setFixedWidth(60);
    _itemEditMp->setRange(0, 255);
    armorLayout->addWidget(new QLabel("MP"), 1, 0);
    armorLayout->addWidget(_itemEditMp, 1, 1);
    armorGroup->setLayout(armorLayout);

    QGroupBox* chemistGroup = new QGroupBox("Chemist");
    QGridLayout* chemistLayout = new QGridLayout;

    _itemEditFormula = new QSpinBox;
    _itemEditFormula->setDisplayIntegerBase(16);
    _itemEditFormula->setPrefix("0x");
    _itemEditFormula->setFixedWidth(60);
    _itemEditFormula->setRange(0, 255);
    chemistLayout->addWidget(new QLabel("Formula"), 0, 0);
    chemistLayout->addWidget(_itemEditFormula, 0, 1);

    _itemEditZ = new QSpinBox;
    _itemEditZ->setFixedWidth(60);
    _itemEditZ->setRange(0, 255);
    chemistLayout->addWidget(new QLabel("Z"), 1, 0);
    chemistLayout->addWidget(_itemEditZ, 1, 1);

    _itemEditStatus = new QSpinBox;
    _itemEditStatus->setDisplayIntegerBase(16);
    _itemEditStatus->setPrefix("0x");
    _itemEditStatus->setFixedWidth(60);
    _itemEditStatus->setRange(0, 255);
    chemistLayout->addWidget(new QLabel("Status"), 2, 0);
    chemistLayout->addWidget(_itemEditStatus, 2, 1);
    chemistGroup->setLayout(chemistLayout);

    _widgetStack = new QStackedWidget;
    _widgetStack->addWidget(new QWidget);
    _widgetStack->addWidget(blockGroup);
    _widgetStack->addWidget(armorGroup);
    _widgetStack->addWidget(chemistGroup);
    itemForm->setRowMinimumHeight(6, 20);
    itemForm->addWidget(_widgetStack, 7, 0, 1, 4);

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
    _mapper->addMapping(_itemEditAttributesId, 8);
    _mapper->addMapping(_itemEditPhysicalBlock, 9);
    _mapper->addMapping(_itemEditMagicalBlock, 10);
    _mapper->addMapping(_itemEditHp, 11);
    _mapper->addMapping(_itemEditMp, 12);
    _mapper->addMapping(_itemEditFormula, 13);
    _mapper->addMapping(_itemEditZ, 14);
    _mapper->addMapping(_itemEditStatus, 15);
    connect(_mapper, SIGNAL(currentIndexChanged(int)), this, SLOT(refreshUi(int)));
    _mapper->toFirst();
}

void TabItems::refreshUi(int index)
{
    Item& item = _mod.itemList->get(index);
    const ItemType& itemType = _itemTypeModel->fromId(item.type);
    bool disabled = item.internal;

    _item = &item;

    _itemEditName->setDisabled(disabled);
    _itemEditType->setDisabled(disabled);
    _itemEditSprite->setDisabled(disabled);
    _itemEditPalette->setDisabled(disabled);
    _itemEditLevel->setDisabled(disabled);
    _itemEditRare->setDisabled(disabled);
    _itemEditPrice->setDisabled(disabled);
    _itemEditShop->setDisabled(disabled);
    _itemEditAttributesId->setDisabled(disabled);

    QModelIndexList indexList = _itemEditType->model()->match(_itemEditType->model()->index(0, 0), Qt::DisplayRole, item.type, 1, Qt::MatchExactly);
    if (!indexList.empty())
    {
        _itemEditType->setCurrentIndex(indexList.first().row());
        _itemTypeModel->filterOn(indexList.first());
    }

    switch (itemType.category)
    {
    case ItemCategory::Shield:
    case ItemCategory::Accessory:
        _widgetStack->setCurrentIndex(1);
        break;
    case ItemCategory::Head:
    case ItemCategory::Body:
        _widgetStack->setCurrentIndex(2);
        break;
    case ItemCategory::ChemistItem:
        _widgetStack->setCurrentIndex(3);
        break;
    default:
        _widgetStack->setCurrentIndex(0);
    }
}

void TabItems::itemTypeChanged(int index)
{
    const ItemType& type = _itemTypeModel->fromIndex(index);
    _item->type = type.id;
}