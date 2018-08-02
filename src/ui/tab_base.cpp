#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <ui/tab_base.h>

TabBase::TabBase(const QString& name, QAbstractItemModel* model, QWidget* parent)
: QWidget(parent)
{
    QHBoxLayout* tabLayout = new QHBoxLayout;
    QVBoxLayout* leftLayout = new QVBoxLayout;
    QLabel* selectedLabel = new QLabel;
   
    selectedLabel->setMaximumHeight(50);
    _layout = new QGridLayout;
    leftLayout->addWidget(new QLabel(name));
    _listView = new QListView;
    _listView->setFixedWidth(180);
    leftLayout->addWidget(_listView);
    tabLayout->addLayout(leftLayout);
    tabLayout->addLayout(_layout);
    _layout->addWidget(selectedLabel, 0, 0);
    _listView->setModel(model);
    _mapper = new QDataWidgetMapper;
    _mapper->setModel(model);
    _mapper->addMapping(selectedLabel, 0, "text");
    _mapper->toFirst();
    setLayout(tabLayout);
    connect(_listView->selectionModel(), SIGNAL(selectionChanged(QItemSelection, QItemSelection)), this, SLOT(handleSelection(QItemSelection)));
}

void TabBase::handleSelection(const QItemSelection& selection)
{
    if (!selection.indexes().isEmpty())
    {
        _mapper->setCurrentIndex(selection.indexes().first().row());
    }
}