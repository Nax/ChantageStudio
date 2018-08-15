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
    return 9;
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
            return item.attrID;
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
            item.attrID = value.toInt();
            emit dataChanged(index, index, roles);
            return true;
        default:
            return false;
    }
}

Qt::ItemFlags ItemList::flags(const QModelIndex & index) const
{
    Qt::ItemFlags flags = Qt::ItemIsSelectable | Qt::ItemIsEnabled;
    const Item& item = _items[index.row()];

    if (!item.internal)
        flags |= Qt::ItemIsEditable;
    return flags;
}
