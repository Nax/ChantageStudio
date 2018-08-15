#ifndef MODEL_MOD_H
#define MODEL_MOD_H

#include <model/item_list.h>
#include <model/item_type_list.h>

struct Mod
{
    Mod();
    ~Mod();

    ItemList*       itemList;
    ItemTypeList*   itemTypeList;
};

#endif