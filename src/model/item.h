#ifndef INCLUDED_MODEL_ITEM_H
#define INCLUDED_MODEL_ITEM_H

#include <cstdint>
#include <QString>
#include <QJsonObject>

enum class ItemOrigin
{
    PSX,
    PSP,
    Custom
};


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
};

#endif
