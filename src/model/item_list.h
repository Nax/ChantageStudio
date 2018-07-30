#ifndef INCLUDED_MODEL_ITEM_LIST_H
#define INCLUDED_MODEL_ITEM_LIST_H

#include <QList>
#include <QAbstractListModel>
#include <model/item.h>

class ItemList : public QAbstractListModel
{
    Q_OBJECT

public:
    ItemList();

    int         rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant    data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    QList<Item>   _items;
};

#endif