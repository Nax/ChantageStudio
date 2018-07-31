#ifndef INCLUDED_MODEL_ITEM_LIST_H
#define INCLUDED_MODEL_ITEM_LIST_H

#include <QList>
#include <QAbstractTableModel>
#include <model/item.h>

class ItemList : public QAbstractTableModel
{
    Q_OBJECT

public:
    ItemList();

    int             columnCount(const QModelIndex &parent = QModelIndex()) const override;
    int             rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant        data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool            setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags   flags(const QModelIndex &index) const override;

private:
    QList<Item>   _items;
};

#endif