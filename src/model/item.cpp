#include <model/item.h>

Item::Item(const QJsonObject& obj)
{
    id = obj["id"].toInt();
    name = obj["name"].toString();
    internal = obj["internal"].toBool();
}
