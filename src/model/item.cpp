#include <QJsonArray>
#include <model/item.h>

Item::Item(const QJsonObject& obj)
{
    id = obj["id"].toInt();
    type = obj["type"].toInt();
    name = obj["name"].toString();
    description = obj["description"].toString();
    internal = obj["internal"].toBool();
    palette = obj["palette"].toInt();
    level = obj["level"].toInt();
    sprite = obj["sprite"].toInt();
    price = obj["price"].toInt();
    rare = obj["rare"].toBool();
    shop = obj["shop"].toInt();
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
    pa = obj["pa"].toInt();
    ma = obj["ma"].toInt();
    speed = obj["speed"].toInt();
    move = obj["move"].toInt();
    jump = obj["jump"].toInt();
    elementsAbsorb = obj["eAbsorb"].toInt();
    elementsCancel = obj["eCancel"].toInt();
    elementsHalf = obj["eHalf"].toInt();
    elementsWeak = obj["eWeak"].toInt();
    elementsStrengthen = obj["eStrengthen"].toInt();

    char tmpStatusPermanent[5];
    char tmpStatusImmunity[5];
    char tmpStatusStart[5];
    for (int i = 0; i < 5; ++i)
    {
        tmpStatusPermanent[i] = obj["sPermanent"].toArray()[i].toInt();
        tmpStatusImmunity[i] = obj["sImmunity"].toArray()[i].toInt();
        tmpStatusStart[i] = obj["sStart"].toArray()[i].toInt();
    }
    statusPermanent = QBitArray::fromBits(tmpStatusPermanent, 40);
    statusImmunity = QBitArray::fromBits(tmpStatusImmunity, 40);
    statusStart = QBitArray::fromBits(tmpStatusStart, 40);
}