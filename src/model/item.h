#ifndef INCLUDED_MODEL_ITEM_H
#define INCLUDED_MODEL_ITEM_H

#include <cstdint>
#include <QString>
#include <QJsonObject>
#include <QBitArray>

#include <model/item_type.h>

struct Item
{
    explicit Item(const QJsonObject& obj);

    uint16_t    id;
    QString     name;
    QString     description;
    bool        internal;

    uint8_t     sprite;
    uint8_t     palette;
    uint8_t     level;
    bool        rare;
    uint8_t     type;
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
    uint8_t     pa;
    uint8_t     ma;
    uint8_t     speed;
    uint8_t     move;
    uint8_t     jump;
    uint8_t     elementsAbsorb;
    uint8_t     elementsCancel;
    uint8_t     elementsHalf;
    uint8_t     elementsWeak;
    uint8_t     elementsStrengthen;
    QBitArray   statusPermanent;
    QBitArray   statusImmunity;
    QBitArray   statusStart;        
};

#endif
