#ifndef INCLUDED_MODEL_ITEM_TYPE_LIST
#define INCLUDED_MODEL_ITEM_TYPE_LIST

#include <QAbstractTableModel>

class ItemTypeList : public QAbstractTableModel
{
    Q_OBJECT

public:
    ItemTypeList();
    ~ItemTypeList();

    int             columnCount(const QModelIndex &parent = QModelIndex()) const override;
    int             rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant        data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags   flags(const QModelIndex &index) const override;
};

#endif