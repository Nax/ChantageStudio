#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <ui/tab_base.h>

TabBase::TabBase(const QString& name, QWidget* parent)
: QWidget(parent)
{
    QHBoxLayout* layout = new QHBoxLayout;
    QVBoxLayout* leftLayout = new QVBoxLayout;

    leftLayout->addWidget(new QLabel(name));
    _listView = new QListView;
    _listView->setFixedWidth(150);
    leftLayout->addWidget(_listView);
    layout->addLayout(leftLayout);
    setLayout(layout);
}
