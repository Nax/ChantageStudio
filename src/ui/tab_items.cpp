#include <QHBoxLayout>
#include <ui/tab_items.h>
#include <ui/editor_item.h>

TabItems::TabItems(QWidget* parent)
: QWidget(parent)
{
    QHBoxLayout* layout = new QHBoxLayout;

    _listView = new QListView;
    _listView->setFixedWidth(150);
    layout->addWidget(_listView);
    layout->addWidget(new EditorItem);
    setLayout(layout);
}
