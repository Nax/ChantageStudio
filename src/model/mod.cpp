#include <model/mod.h>

Mod::Mod()
{
    itemList = new ItemList;
}

Mod::~Mod()
{
    delete itemList;
}