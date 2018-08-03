#include <model/item.h>

Item::Item(const QJsonObject& obj)
{
    id = obj["id"].toInt();
    name = obj["name"].toString();
    internal = obj["internal"].toBool();
    palette = obj["palette"].toInt();
    level = obj["level"].toInt();
    sprite = obj["sprite"].toInt();
    price = obj["price"].toInt();
}
