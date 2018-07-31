#ifndef INCLUDED_UI_TAB_BASE_H
#define INCLUDED_UI_TAB_BASE_H

#include <QListView>
#include <QItemSelection>
#include <QDataWidgetMapper>
#include <QGridLayout>

class TabBase : public QWidget
{
    Q_OBJECT

public:
    explicit TabBase(const QString& name, QAbstractItemModel* model, QWidget* parent = nullptr);

protected:
    QListView*          _listView;
    QGridLayout*        _layout;
    QDataWidgetMapper*  _mapper;

private slots:
    void handleSelection(const QItemSelection& selection);
};

#endif
