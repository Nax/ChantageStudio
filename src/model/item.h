#ifndef INCLUDED_MODEL_ITEM_H
#define INCLUDED_MODEL_ITEM_H

#include <cstdint>
#include <QString>
#include <QJsonObject>

#include <model/item_type.h>

struct Item
{
    explicit Item(const QJsonObject& obj);

    uint16_t    id;
    QString     name;
    bool        internal;

    uint8_t     sprite;
    uint8_t     palette;
    uint8_t     level;
    bool        rare;
    uint8_t     type;
    uint8_t     attrID;
    uint16_t    price;
    uint8_t     shop;
    uint8_t     physicalBlock;
    uint8_t     magicalBlock;
    uint8_t     hp;
    uint8_t     mp;
    uint8_t     formula;
    uint8_t     z;
    uint8_t     status;
    uint8_t     range;
    uint8_t     flags;
    uint8_t     power;
    uint8_t     elements;
};

#endif
