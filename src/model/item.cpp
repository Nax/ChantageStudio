#include <model/item.h>

Item::Item(const QJsonObject& obj)
{
    id = obj["id"].toInt();
    type = obj["type"].toInt();
    name = obj["name"].toString();
    internal = obj["internal"].toBool();
    palette = obj["palette"].toInt();
    level = obj["level"].toInt();
    sprite = obj["sprite"].toInt();
    price = obj["price"].toInt();
    rare = obj["rare"].toBool();
    shop = obj["shop"].toInt();
    attrID = obj["attributes_id"].toInt();
    physicalBlock = obj["pBlock"].toInt();
    magicalBlock = obj["mBlock"].toInt();
    hp = obj["hp"].toInt();
    mp = obj["mp"].toInt();
    formula = obj["formula"].toInt();
    z = obj["z"].toInt();
    status = obj["status"].toInt();
    range = obj["range"].toInt();
    flags = obj["flags"].toInt();
    power = obj["power"].toInt();
    elements = obj["elements"].toInt();
}