#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <model/item_list.h>

ItemList::ItemList()
{
    QFile file(":/data/items.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QJsonDocument json = QJsonDocument::fromJson(file.readAll());
    file.close();
    for (const auto& value : json.array())
    {
        _items.append(Item(value.toObject()));
    }
}

int ItemList::columnCount(const QModelIndex & parent) const
{
    return 33;
}

int ItemList::rowCount(const QModelIndex & parent) const
{
    return _items.size();
}

QVariant ItemList::data(const QModelIndex & index, int role) const
{
    if ((role == Qt::DisplayRole || role == Qt::EditRole) && index.row() < _items.size())
    {
        const Item& item = _items[index.row()];
        switch (index.column())
        {
        case 0:
            return QString("%1").arg(item.id, 4, 16, QChar('0')) + " - " + item.name;
        case 1:
            return item.name;
        case 2:
            return item.sprite;
        case 3:
            return item.palette;
        case 4:
            return item.level;
        case 5:
            return item.rare;
        case 6:
            return item.price;
        case 7:
            return item.shop;
        case 8:
            return item.description;
        case 9:
            return item.physicalBlock;
        case 10:
            return item.magicalBlock;
        case 11:
            return item.hp;
        case 12:
            return item.mp;
        case 13:
            return item.formula;
        case 14:
            return item.z;
        case 15:
            return item.status;
        case 16:
            return item.range;
        case 17:
            return item.flags;
        case 18:
            return item.power;
        case 19:
            return item.elements;
        case 20:
            return item.pa;
        case 21:
            return item.ma;
        case 22:
            return item.speed;
        case 23:
            return item.move;
        case 24:
            return item.jump;
        case 25:
            return item.elementsAbsorb;
        case 26:
            return item.elementsCancel;
        case 27:
            return item.elementsHalf;
        case 28:
            return item.elementsWeak;
        case 29:
            return item.elementsStrengthen;
        case 30:
            return item.statusPermanent;
        case 31:
            return item.statusImmunity;
        case 32:
            return item.statusStart;
        default:
            return QVariant();
        }
    }
    return QVariant();
}

bool ItemList::setData(const QModelIndex & index, const QVariant & value, int role)
{
    QVector<int> roles;
    roles.push_back(role);
    if (role != Qt::EditRole)
        return false;
    Item& item = _items[index.row()];
    switch (index.column())
    {
        case 1:
            item.name = value.toString();
            emit dataChanged(index, index, roles);
            return true;
        case 2:
            item.sprite = value.toInt();
            emit dataChanged(index, index, roles);
            return true;
        case 3:
            item.palette = value.toInt();
            emit dataChanged(index, index, roles);
            return true;
        case 4:
            item.level = value.toInt();
            emit dataChanged(index, index, roles);
            return true;
        case 5:
            item.rare = value.toBool();
            emit dataChanged(index, index, roles);
            return true;
        case 6:
            item.price = value.toInt();
            emit dataChanged(index, index, roles);
            return true;
        case 7:
            item.shop = value.toInt();
            emit dataChanged(index, index, roles);
            return true;
        case 8:
            item.description = value.toString();
            emit dataChanged(index, index, roles);
            return true;
        case 9:
            item.physicalBlock = value.toInt();
            emit dataChanged(index, index, roles);
            return true;
        case 10:
            item.magicalBlock = value.toInt();
            emit dataChanged(index, index, roles);
            return true;
        case 11:
            item.hp = value.toInt();
            emit dataChanged(index, index, roles);
            return true;
        case 12:
            item.mp = value.toInt();
            emit dataChanged(index, index, roles);
            return true;
        case 13:
            item.formula = value.toInt();
            emit dataChanged(index, index, roles);
            return true;
        case 14:
            item.z = value.toInt();
            emit dataChanged(index, index, roles);
            return true;
        case 15:
            item.status = value.toInt();
            emit dataChanged(index, index, roles);
            return true;
        case 16:
            item.range = value.toInt();
            emit dataChanged(index, index, roles);
            return true;
        case 17:
            item.flags = value.toInt();
            emit dataChanged(index, index, roles);
            return true;
        case 18:
            item.power = value.toInt();
            emit dataChanged(index, index, roles);
            return true;
        case 19:
            item.elements = value.toInt();
            emit dataChanged(index, index, roles);
            return true;
        case 20:
            item.pa = value.toInt();
            emit dataChanged(index, index, roles);
            return true;
        case 21:
            item.ma = value.toInt();
            emit dataChanged(index, index, roles);
            return true;
        case 22:
            item.speed = value.toInt();
            emit dataChanged(index, index, roles);
            return true;
        case 23:
            item.move = value.toInt();
            emit dataChanged(index, index, roles);
            return true;
        case 24:
            item.jump = value.toInt();
            emit dataChanged(index, index, roles);
            return true;
        case 25:
            item.elementsAbsorb = value.toInt();
            emit dataChanged(index, index, roles);
            return true;
        case 26:
            item.elementsCancel = value.toInt();
            emit dataChanged(index, index, roles);
            return true;
        case 27:
            item.elementsHalf = value.toInt();
            emit dataChanged(index, index, roles);
            return true;
        case 28:
            item.elementsWeak = value.toInt();
            emit dataChanged(index, index, roles);
            return true;
        case 29:
            item.elementsStrengthen = value.toInt();
            emit dataChanged(index, index, roles);
            return true;
        case 30:
            item.statusPermanent = value.toBitArray();
            emit dataChanged(index, index, roles);
            return true;
        case 31:
            item.statusImmunity = value.toBitArray();
            emit dataChanged(index, index, roles);
            return true;
        case 32:
            item.statusStart = value.toBitArray();
            emit dataChanged(index, index, roles);
            return true;
        default:
            return false;
    }
}

Qt::ItemFlags ItemList::flags(const QModelIndex & index) const
{
    return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}
