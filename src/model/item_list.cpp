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

int ItemList::rowCount(const QModelIndex & parent) const
{
    return _items.size();
}

QVariant ItemList::data(const QModelIndex & index, int role) const
{
    if (role == Qt::DisplayRole && index.row() < _items.size() && index.column() == 0)
    {
        const Item& item = _items[index.row()];
        return QString("%1").arg(item.id, 4, 16, QChar('0')) + " - " + item.name;
    }
    return QVariant();
}
