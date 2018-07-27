#ifndef INCLUDED_UI_TAB_BASE_H
#define INCLUDED_UI_TAB_BASE_H

#include <QWidget>
#include <QListView>

class TabBase : public QWidget
{
    Q_OBJECT

public:
    explicit TabBase(const QString& name, QWidget* parent = nullptr);

protected:
    QListView*      _listView;
};

#endif
