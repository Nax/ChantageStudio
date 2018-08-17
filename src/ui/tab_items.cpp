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

    _itemEditShieldPhysicalBlock = new QSpinBox;
    _itemEditShieldPhysicalBlock->setSuffix("%");
    _itemEditShieldPhysicalBlock->setFixedWidth(60);
    _itemEditShieldPhysicalBlock->setRange(0, 255);
    blockLayout->addWidget(new QLabel("Physical Block / Evade"), 0, 0);
    blockLayout->addWidget(_itemEditShieldPhysicalBlock, 0, 1);

    _itemEditShieldMagicalBlock = new QSpinBox;
    _itemEditShieldMagicalBlock->setSuffix("%");
    _itemEditShieldMagicalBlock->setFixedWidth(60);
    _itemEditShieldMagicalBlock->setRange(0, 255);
    blockLayout->addWidget(new QLabel("Magical Block / Evade"), 1, 0);
    blockLayout->addWidget(_itemEditShieldMagicalBlock, 1, 1);
    blockGroup->setLayout(blockLayout);

    QGroupBox* armorGroup = new QGroupBox("Armor");
    QGridLayout* armorLayout = new QGridLayout;

    _itemEditArmorHp = new QSpinBox;
    _itemEditArmorHp->setFixedWidth(60);
    _itemEditArmorHp->setRange(0, 255);
    armorLayout->addWidget(new QLabel("HP"), 0, 0);
    armorLayout->addWidget(_itemEditArmorHp, 0, 1);

    _itemEditArmorMp = new QSpinBox;
    _itemEditArmorMp->setFixedWidth(60);
    _itemEditArmorMp->setRange(0, 255);
    armorLayout->addWidget(new QLabel("MP"), 1, 0);
    armorLayout->addWidget(_itemEditArmorMp, 1, 1);
    armorGroup->setLayout(armorLayout);

    QGroupBox* chemistGroup = new QGroupBox("Chemist");
    QGridLayout* chemistLayout = new QGridLayout;

    _itemEditChemistFormula = new QSpinBox;
    _itemEditChemistFormula->setDisplayIntegerBase(16);
    _itemEditChemistFormula->setPrefix("0x");
    _itemEditChemistFormula->setFixedWidth(60);
    _itemEditChemistFormula->setRange(0, 255);
    chemistLayout->addWidget(new QLabel("Formula"), 0, 0);
    chemistLayout->addWidget(_itemEditChemistFormula, 0, 1);

    _itemEditChemistZ = new QSpinBox;
    _itemEditChemistZ->setFixedWidth(60);
    _itemEditChemistZ->setRange(0, 255);
    chemistLayout->addWidget(new QLabel("Z"), 1, 0);
    chemistLayout->addWidget(_itemEditChemistZ, 1, 1);

    _itemEditChemistStatus = new QSpinBox;
    _itemEditChemistStatus->setDisplayIntegerBase(16);
    _itemEditChemistStatus->setPrefix("0x");
    _itemEditChemistStatus->setFixedWidth(60);
    _itemEditChemistStatus->setRange(0, 255);
    chemistLayout->addWidget(new QLabel("Status"), 2, 0);
    chemistLayout->addWidget(_itemEditChemistStatus, 2, 1);
    chemistGroup->setLayout(chemistLayout);

    QGroupBox* weaponGroup = new QGroupBox("Weapon");
    QGridLayout* weaponLayout = new QGridLayout;

    _itemEditWeaponRange = new QSpinBox;
    _itemEditWeaponRange->setFixedWidth(60);
    _itemEditWeaponRange->setRange(0, 255);
    weaponLayout->addWidget(new QLabel("Range"), 0, 0);
    weaponLayout->addWidget(_itemEditWeaponRange, 0, 1);

    _itemEditWeaponFormula = new QSpinBox;
    _itemEditWeaponFormula->setDisplayIntegerBase(16);
    _itemEditWeaponFormula->setPrefix("0x");
    _itemEditWeaponFormula->setFixedWidth(60);
    _itemEditWeaponFormula->setRange(0, 255);
    weaponLayout->addWidget(new QLabel("Formula"), 1, 0);
    weaponLayout->addWidget(_itemEditWeaponFormula, 1, 1);

    _itemEditWeaponPower = new QSpinBox;
    _itemEditWeaponPower->setFixedWidth(60);
    _itemEditWeaponPower->setRange(0, 255);
    weaponLayout->addWidget(new QLabel("Power"), 2, 0);
    weaponLayout->addWidget(_itemEditWeaponPower, 2, 1);

    _itemEditWeaponEvade = new QSpinBox;
    _itemEditWeaponEvade->setSuffix("%");
    _itemEditWeaponEvade->setFixedWidth(60);
    _itemEditWeaponEvade->setRange(0, 255);
    weaponLayout->addWidget(new QLabel("Evade"), 3, 0);
    weaponLayout->addWidget(_itemEditWeaponEvade, 3, 1);

    _itemEditWeaponStatus = new QSpinBox;
    _itemEditWeaponStatus->setDisplayIntegerBase(16);
    _itemEditWeaponStatus->setPrefix("0x");
    _itemEditWeaponStatus->setFixedWidth(60);
    _itemEditWeaponStatus->setRange(0, 255);
    weaponLayout->addWidget(new QLabel("Status"), 4, 0);
    weaponLayout->addWidget(_itemEditWeaponStatus, 4, 1);

    _itemEditWeaponFlags = new WeaponFlagsEditor;
    weaponLayout->addWidget(_itemEditWeaponFlags, 0, 2, 6, 1, Qt::AlignTop);

    _itemEditWeaponElements = new ElementsEditor("Elements");
    weaponLayout->addWidget(_itemEditWeaponElements, 0, 3, 6, 1, Qt::AlignTop);

    weaponGroup->setLayout(weaponLayout);

    _widgetStack = new QStackedWidget;
    _widgetStack->addWidget(new QWidget);
    _widgetStack->addWidget(blockGroup);
    _widgetStack->addWidget(armorGroup);
    _widgetStack->addWidget(chemistGroup);
    _widgetStack->addWidget(weaponGroup);
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
    _mapper->addMapping(_itemEditShieldPhysicalBlock, 9);
    _mapper->addMapping(_itemEditShieldMagicalBlock, 10);
    _mapper->addMapping(_itemEditArmorHp, 11);
    _mapper->addMapping(_itemEditArmorMp, 12);
    _mapper->addMapping(_itemEditChemistFormula, 13);
    _mapper->addMapping(_itemEditChemistZ, 14);
    _mapper->addMapping(_itemEditChemistStatus, 15);
    _mapper->addMapping(_itemEditWeaponRange, 16);
    _mapper->addMapping(_itemEditWeaponFormula, 13);
    _mapper->addMapping(_itemEditWeaponPower, 18);
    _mapper->addMapping(_itemEditWeaponEvade, 9);
    _mapper->addMapping(_itemEditWeaponStatus, 15);
    _mapper->addMapping(_itemEditWeaponFlags, 17);
    _mapper->addMapping(_itemEditWeaponElements, 19);
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
    case ItemCategory::Weapon:
        _widgetStack->setCurrentIndex(4);
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