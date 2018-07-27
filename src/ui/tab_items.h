#ifndef INCLUDED_UI_TAB_ITEMS_H
#define INCLUDED_UI_TAB_ITEMS_H

#include <QWidget>
#include <QListView>

class TabItems : public QWidget
{
    Q_OBJECT

public:
    explicit TabItems(QWidget* parent = nullptr);

private:
    QListView*      _listView;
};

#endif
