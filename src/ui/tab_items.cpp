#include <QGridLayout>
#include <QVBoxLayout>
#include <QHboxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QGroupBox>
#include <ui/tab_items.h>
#include <model/mod.h>

TabItems::TabItems(Mod& mod, QWidget* parent) : QWidget(parent), _mod(mod)
{
    QHBoxLayout* tabLayout = new QHBoxLayout;

    _listView = new QListView;
    _listView->setFixedWidth(180);
    _listView->setModel(mod.itemList);
    tabLayout->addWidget(_listView);
    connect(_listView->selectionModel(), SIGNAL(selectionChanged(QItemSelection, QItemSelection)), this, SLOT(selectItem(QItemSelection)));

    QVBoxLayout* leftLayout = new QVBoxLayout;
    QVBoxLayout* rightLayout = new QVBoxLayout;
    tabLayout->addLayout(leftLayout);
    tabLayout->addLayout(rightLayout);
    tabLayout->addStretch(1);
    setLayout(tabLayout);

    QGridLayout* itemForm = new QGridLayout;
    leftLayout->addLayout(itemForm);
    itemForm->setColumnMinimumWidth(0, 50);
    itemForm->setColumnMinimumWidth(2, 40);

    _itemTypeModel = new ItemTypeList;

    _itemEditName = new QLineEdit;
    _itemEditName->setFixedWidth(320);
    itemForm->addWidget(new QLabel("Name"), 0, 0);
    itemForm->addWidget(_itemEditName, 0, 1, 1, 3);

    _itemEditDescription = new QPlainTextEdit;
    _itemEditDescription->setFixedWidth(320);
    _itemEditDescription->setFixedHeight(60);
    itemForm->addWidget(new QLabel("Description"), 1, 0);
    itemForm->addWidget(_itemEditDescription, 1, 1, 1, 3);

    _itemEditType = new QComboBox;
    _itemEditType->setFixedWidth(320);
    _itemEditType->setModel(_itemTypeModel);
    _itemEditType->setModelColumn(1);
    itemForm->addWidget(new QLabel("Type"), 2, 0);
    itemForm->addWidget(_itemEditType, 2, 1, 1, 3);
    connect(_itemEditType, SIGNAL(currentIndexChanged(int)), this, SLOT(itemTypeChanged(int)));

    _itemEditSprite = new QSpinBox;
    _itemEditSprite->setDisplayIntegerBase(16);
    _itemEditSprite->setPrefix("0x");
    _itemEditSprite->setFixedWidth(60);
    _itemEditSprite->setRange(0, 255);
    itemForm->addWidget(new QLabel("Sprite"), 3, 0);
    itemForm->addWidget(_itemEditSprite, 3, 1);

    _itemEditPalette = new QSpinBox;
    _itemEditPalette->setDisplayIntegerBase(16);
    _itemEditPalette->setPrefix("0x");
    _itemEditPalette->setFixedWidth(60);
    _itemEditPalette->setRange(0, 255);
    itemForm->addWidget(new QLabel("Palette"), 3, 2);
    itemForm->addWidget(_itemEditPalette, 3, 3);

    _itemEditLevel = new QSpinBox;
    _itemEditLevel->setFixedWidth(60);
    _itemEditLevel->setRange(0, 255);
    itemForm->addWidget(new QLabel("Level"), 4, 0);
    itemForm->addWidget(_itemEditLevel, 4, 1);

    _itemEditRare = new QCheckBox;
    itemForm->addWidget(new QLabel("Rare"), 4, 2);
    itemForm->addWidget(_itemEditRare, 4, 3);

    _itemEditPrice = new QSpinBox;
    _itemEditPrice->setFixedWidth(60);
    _itemEditPrice->setRange(0, 65535);
    itemForm->addWidget(new QLabel("Price"), 5, 0);
    itemForm->addWidget(_itemEditPrice, 5, 1);

    _itemEditShop = new QSpinBox;
    _itemEditShop->setDisplayIntegerBase(16);
    _itemEditShop->setPrefix("0x");
    _itemEditShop->setFixedWidth(60);
    _itemEditShop->setRange(0, 255);
    itemForm->addWidget(new QLabel("Shop"), 5, 2);
    itemForm->addWidget(_itemEditShop, 5, 3);

    _itemEditPa = new QSpinBox;
    _itemEditPa->setFixedWidth(60);
    _itemEditPa->setRange(0, 255);
    itemForm->addWidget(new QLabel("PA"), 6, 0);
    itemForm->addWidget(_itemEditPa, 6, 1);

    _itemEditMa = new QSpinBox;
    _itemEditMa->setFixedWidth(60);
    _itemEditMa->setRange(0, 255);
    itemForm->addWidget(new QLabel("MA"), 6, 2);
    itemForm->addWidget(_itemEditMa, 6, 3);

    _itemEditMove = new QSpinBox;
    _itemEditMove->setFixedWidth(60);
    _itemEditMove->setRange(0, 255);
    itemForm->addWidget(new QLabel("Move"), 7, 0);
    itemForm->addWidget(_itemEditMove, 7, 1);

    _itemEditJump = new QSpinBox;
    _itemEditJump->setFixedWidth(60);
    _itemEditJump->setRange(0, 255);
    itemForm->addWidget(new QLabel("Jump"), 7, 2);
    itemForm->addWidget(_itemEditJump, 7, 3);

    _itemEditSpeed = new QSpinBox;
    _itemEditSpeed->setFixedWidth(60);
    _itemEditSpeed->setRange(0, 255);
    itemForm->addWidget(new QLabel("Speed"), 8, 0);
    itemForm->addWidget(_itemEditSpeed, 8, 1);
    itemForm->setColumnStretch(4, 1);
    itemForm->setSizeConstraint(QLayout::SetFixedSize);

    QHBoxLayout* elementsLayout = new QHBoxLayout;
    _itemEditElementsAbsorb = new ElementsEditor("Absorb");
    elementsLayout->addWidget(_itemEditElementsAbsorb);
    _itemEditElementsCancel = new ElementsEditor("Cancel");
    elementsLayout->addWidget(_itemEditElementsCancel);
    _itemEditElementsHalf = new ElementsEditor("Half");
    elementsLayout->addWidget(_itemEditElementsHalf);
    _itemEditElementsWeak = new ElementsEditor("Weak");
    elementsLayout->addWidget(_itemEditElementsWeak);
    _itemEditElementsStrengthen = new ElementsEditor("Strengthen");
    elementsLayout->addWidget(_itemEditElementsStrengthen);
    rightLayout->addLayout(elementsLayout);

    _itemEditStatusPermanent = new StatusEditor("Permanent");
    rightLayout->addWidget(_itemEditStatusPermanent);

    _itemEditStatusImmune = new StatusEditor("Immune");
    rightLayout->addWidget(_itemEditStatusImmune);

    _itemEditStatusStart = new StatusEditor("Start");
    rightLayout->addWidget(_itemEditStatusStart);
    rightLayout->addStretch();

    QGroupBox* blockGroup = new QGroupBox("Block / Evade");
    QFormLayout* blockLayout = new QFormLayout;

    _itemEditShieldPhysicalBlock = new QSpinBox;
    _itemEditShieldPhysicalBlock->setSuffix("%");
    _itemEditShieldPhysicalBlock->setFixedWidth(60);
    _itemEditShieldPhysicalBlock->setRange(0, 255);
    blockLayout->addRow("Physical Block / Evade", _itemEditShieldPhysicalBlock);

    _itemEditShieldMagicalBlock = new QSpinBox;
    _itemEditShieldMagicalBlock->setSuffix("%");
    _itemEditShieldMagicalBlock->setFixedWidth(60);
    _itemEditShieldMagicalBlock->setRange(0, 255);
    blockLayout->addRow("Magical Block / Evade", _itemEditShieldMagicalBlock);
    blockGroup->setLayout(blockLayout);

    QGroupBox* armorGroup = new QGroupBox("Armor");
    QFormLayout* armorLayout = new QFormLayout;

    _itemEditArmorHp = new QSpinBox;
    _itemEditArmorHp->setFixedWidth(60);
    _itemEditArmorHp->setRange(0, 255);
    armorLayout->addRow("HP", _itemEditArmorHp);

    _itemEditArmorMp = new QSpinBox;
    _itemEditArmorMp->setFixedWidth(60);
    _itemEditArmorMp->setRange(0, 255);
    armorLayout->addRow("MP", _itemEditArmorMp);
    armorGroup->setLayout(armorLayout);

    QGroupBox* chemistGroup = new QGroupBox("Chemist");
    QFormLayout* chemistLayout = new QFormLayout;

    _itemEditChemistFormula = new QSpinBox;
    _itemEditChemistFormula->setDisplayIntegerBase(16);
    _itemEditChemistFormula->setPrefix("0x");
    _itemEditChemistFormula->setFixedWidth(60);
    _itemEditChemistFormula->setRange(0, 255);
    chemistLayout->addRow("Formula", _itemEditChemistFormula);

    _itemEditChemistZ = new QSpinBox;
    _itemEditChemistZ->setFixedWidth(60);
    _itemEditChemistZ->setRange(0, 255);
    chemistLayout->addRow("Z", _itemEditChemistZ);

    _itemEditChemistStatus = new QSpinBox;
    _itemEditChemistStatus->setDisplayIntegerBase(16);
    _itemEditChemistStatus->setPrefix("0x");
    _itemEditChemistStatus->setFixedWidth(60);
    _itemEditChemistStatus->setRange(0, 255);
    chemistLayout->addRow("Status", _itemEditChemistStatus);
    chemistGroup->setLayout(chemistLayout);

    QGroupBox* weaponGroup = new QGroupBox("Weapon");
    QHBoxLayout* weaponLayout = new QHBoxLayout;
    QGridLayout* weaponForm = new QGridLayout;

    _itemEditWeaponRange = new QSpinBox;
    _itemEditWeaponRange->setFixedWidth(60);
    _itemEditWeaponRange->setRange(0, 255);
    weaponForm->addWidget(new QLabel("Range"), 0, 0);
    weaponForm->addWidget(_itemEditWeaponRange, 0, 1);

    _itemEditWeaponFormula = new QSpinBox;
    _itemEditWeaponFormula->setDisplayIntegerBase(16);
    _itemEditWeaponFormula->setPrefix("0x");
    _itemEditWeaponFormula->setFixedWidth(60);
    _itemEditWeaponFormula->setRange(0, 255);
    weaponForm->addWidget(new QLabel("Formula"), 1, 0);
    weaponForm->addWidget(_itemEditWeaponFormula, 1, 1);

    _itemEditWeaponPower = new QSpinBox;
    _itemEditWeaponPower->setFixedWidth(60);
    _itemEditWeaponPower->setRange(0, 255);
    weaponForm->addWidget(new QLabel("Power"), 2, 0);
    weaponForm->addWidget(_itemEditWeaponPower, 2, 1);

    _itemEditWeaponEvade = new QSpinBox;
    _itemEditWeaponEvade->setSuffix("%");
    _itemEditWeaponEvade->setFixedWidth(60);
    _itemEditWeaponEvade->setRange(0, 255);
    weaponForm->addWidget(new QLabel("Evade"), 3, 0);
    weaponForm->addWidget(_itemEditWeaponEvade, 3, 1);

    _itemEditWeaponStatus = new QSpinBox;
    _itemEditWeaponStatus->setDisplayIntegerBase(16);
    _itemEditWeaponStatus->setPrefix("0x");
    _itemEditWeaponStatus->setFixedWidth(60);
    _itemEditWeaponStatus->setRange(0, 255);
    weaponForm->addWidget(new QLabel("Status"), 4, 0);
    weaponForm->addWidget(_itemEditWeaponStatus, 4, 1);
    weaponLayout->addLayout(weaponForm);

    _itemEditWeaponFlags = new WeaponFlagsEditor;
    weaponLayout->addWidget(_itemEditWeaponFlags);

    _itemEditWeaponElements = new ElementsEditor("Elements");
    weaponLayout->addWidget(_itemEditWeaponElements);

    weaponGroup->setLayout(weaponLayout);

    _widgetStack = new QStackedWidget;
    _widgetStack->addWidget(new QWidget);
    _widgetStack->addWidget(blockGroup);
    _widgetStack->addWidget(armorGroup);
    _widgetStack->addWidget(chemistGroup);
    _widgetStack->addWidget(weaponGroup);
    leftLayout->addWidget(_widgetStack);
    leftLayout->addStretch(1);

    _mapper = new QDataWidgetMapper;
    _mapper->setModel(mod.itemList);
    _mapper->addMapping(_itemEditName,  1);
    _mapper->addMapping(_itemEditDescription, 8);
    _mapper->addMapping(_itemEditSprite, 2);
    _mapper->addMapping(_itemEditPalette, 3);
    _mapper->addMapping(_itemEditLevel, 4);
    _mapper->addMapping(_itemEditRare, 5);
    _mapper->addMapping(_itemEditPrice, 6);
    _mapper->addMapping(_itemEditShop, 7);
    _mapper->addMapping(_itemEditPa, 20);
    _mapper->addMapping(_itemEditMa, 21);
    _mapper->addMapping(_itemEditMove, 23);
    _mapper->addMapping(_itemEditJump, 24);
    _mapper->addMapping(_itemEditSpeed, 22);
    _mapper->addMapping(_itemEditElementsAbsorb, 25);
    _mapper->addMapping(_itemEditElementsCancel, 26);
    _mapper->addMapping(_itemEditElementsHalf, 27);
    _mapper->addMapping(_itemEditElementsWeak, 28);
    _mapper->addMapping(_itemEditElementsStrengthen, 29);
    _mapper->addMapping(_itemEditStatusPermanent, 30);
    _mapper->addMapping(_itemEditStatusImmune, 31);
    _mapper->addMapping(_itemEditStatusStart, 32);
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

void TabItems::selectItem(const QItemSelection& selection)
{
    if (!selection.indexes().isEmpty())
    {
        _mapper->setCurrentIndex(selection.indexes().first().row());
    }
}

void TabItems::refreshUi(int index)
{
    Item& item = _mod.itemList->get(index);
    const ItemType& itemType = _itemTypeModel->fromId(item.type);
    bool disabled = item.internal;

    _item = &item;

    _itemEditName->setDisabled(disabled);
    _itemEditDescription->setDisabled(disabled);
    _itemEditType->setDisabled(disabled);
    _itemEditSprite->setDisabled(disabled);
    _itemEditPalette->setDisabled(disabled);
    _itemEditLevel->setDisabled(disabled);
    _itemEditRare->setDisabled(disabled);
    _itemEditPrice->setDisabled(disabled);
    _itemEditShop->setDisabled(disabled);
    _itemEditPa->setDisabled(disabled);
    _itemEditMa->setDisabled(disabled);
    _itemEditMove->setDisabled(disabled);
    _itemEditJump->setDisabled(disabled);
    _itemEditSpeed->setDisabled(disabled);
    _itemEditElementsAbsorb->setDisabled(disabled);
    _itemEditElementsCancel->setDisabled(disabled);
    _itemEditElementsWeak->setDisabled(disabled);
    _itemEditElementsHalf->setDisabled(disabled);
    _itemEditElementsStrengthen->setDisabled(disabled);
    _itemEditStatusPermanent->setDisabled(disabled);
    _itemEditStatusImmune->setDisabled(disabled);
    _itemEditStatusStart->setDisabled(disabled);

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