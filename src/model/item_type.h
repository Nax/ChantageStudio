#ifndef INCLUDED_MODEL_ITEM_TYPE_H
#define INCLUDED_MODEL_ITEM_TYPE_H

#include <cstdint>

enum class ItemCategory
{
    None,
    ChemistItem,
    Weapon,
    Shield,
    Helm,
    BodyArmor,
    Legs,
    Accessory
};

class ItemType
{
public:
    uint8_t         id;
    const char*     name;
    ItemCategory    category;
};

#endif