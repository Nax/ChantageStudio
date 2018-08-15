#include <QList>
#include <model/item_type_list.h>

static const QList<ItemType> kItemTypes = {
    {0, "(None)", ItemCategory::None},
    {34, "Chemist Item", ItemCategory::ChemistItem},
    {1, "Weapon: Dagger", ItemCategory::Weapon}, 
    {2, "Weapon: Ninja Sword", ItemCategory::Weapon},
    {3, "Weapon: Sword", ItemCategory::Weapon},
    {4, "Weapon: Knight Sword", ItemCategory::Weapon},
    {5, "Weapon: Samurai Sword", ItemCategory::Weapon},
    {6, "Weapon: Axe", ItemCategory::Weapon},
    {7, "Weapon: Rod", ItemCategory::Weapon},
    {8, "Weapon: Staff", ItemCategory::Weapon},
    {9, "Weapon: Flail", ItemCategory::Weapon},
    {10, "Weapon: Gun", ItemCategory::Weapon},
    {11, "Weapon: Crossbow", ItemCategory::Weapon},
    {12, "Weapon: Bow", ItemCategory::Weapon},
    {13, "Weapon: Harp", ItemCategory::Weapon},
    {14, "Weapon: Book", ItemCategory::Weapon},
    {15, "Weapon: Spear", ItemCategory::Weapon},
    {16, "Weapon: Pole", ItemCategory::Weapon},
    {17, "Weapon: Bag", ItemCategory::Weapon},
    {18, "Weapon: Cloth", ItemCategory::Weapon},
    {35, "Weapon: Fell Sword", ItemCategory::Weapon},
    {32, "Weapon: Projectile", ItemCategory::Weapon},
    {33, "Weapon: Bomb", ItemCategory::Weapon},
    {19, "Shield", ItemCategory::Shield},
    {20, "Head: Helm", ItemCategory::Helm},
    {21, "Head: Hat", ItemCategory::Helm},
    {22, "Head: Hairpin", ItemCategory::Helm},
    {23, "Body: Armor", ItemCategory::BodyArmor},
    {24, "Body: Clothing", ItemCategory::BodyArmor},
    {25, "Body: Robe", ItemCategory::BodyArmor},
    {26, "Accessory: Boots", ItemCategory::Accessory},
    {27, "Accessory: Glove", ItemCategory::Accessory},
    {28, "Accessory: Ring", ItemCategory::Accessory},
    {29, "Accessory: Bracelet", ItemCategory::Accessory},
    {30, "Accessory: Cape", ItemCategory::Accessory},
    {31, "Accessory: Perfume", ItemCategory::Accessory},
    {36, "Accessory: Lipstick", ItemCategory::Accessory},
};

ItemTypeList::ItemTypeList()
: _filterEnabled(false)
{

}

ItemTypeList::~ItemTypeList()
{

}

int ItemTypeList::columnCount(const QModelIndex & parent) const
{
    return 2;
}

int ItemTypeList::rowCount(const QModelIndex & parent) const
{
    return kItemTypes.size();
}

QVariant ItemTypeList::data(const QModelIndex & index, int role) const
{
    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        const ItemType& type = kItemTypes[index.row()];
        switch (index.column())
        {
        case 0:
            return type.id;
        case 1:
            return type.name;
        default:
            return QVariant();
        }
    }
    return QVariant();
}

Qt::ItemFlags ItemTypeList::flags(const QModelIndex & index) const
{
    const ItemType& type = kItemTypes[index.row()];

    if (_filterEnabled && _filterCategory != type.category)
        return 0;
    return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}

void ItemTypeList::filter(ItemCategory category)
{
    _filterEnabled = true;
    _filterCategory = category;
}

void ItemTypeList::filterOn(const QModelIndex& index)
{
    filter(kItemTypes[index.row()].category);
}

void ItemTypeList::clearFilter()
{
    _filterEnabled = false;
}

const ItemType& ItemTypeList::fromIndex(int index) const
{
    return kItemTypes[index];
}