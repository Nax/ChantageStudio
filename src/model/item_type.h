#ifndef INCLUDED_MODEL_ITEM_TYPE_H
#define INCLUDED_MODEL_ITEM_TYPE_H

#include <cstdint>
#include <model/item_category.h>

class ItemType
{
public:
    uint8_t         id;
    const char*     name;
    ItemCategory    category;
};

#endif