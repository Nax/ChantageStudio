#include <model/mod.h>

Mod::Mod()
{
    itemList = new ItemList;
    itemTypeList = new ItemTypeList;
}

Mod::~Mod()
{
    delete itemList;
    delete itemTypeList;
}