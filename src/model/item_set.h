#ifndef INCLUDED_MODEL_ITEM_SET_H
#define INCLUDED_MODEL_ITEM_SET_H

#include <QMap>
#include <model/item.h>

class ItemSet
{
public:

private:
    QMap<uint16_t, Item>   _items;
};

#endif
