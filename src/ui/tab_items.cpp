#include <QFormLayout>
#include <QLineEdit>
#include <ui/tab_items.h>
#include <model/mod.h>

TabItems::TabItems(Mod& mod, QWidget* parent) : TabBase("Items", mod.itemList, parent)
{
    QFormLayout* form = new QFormLayout;
    _itemNameEdit = new QLineEdit;
    form->addRow("Name:", _itemNameEdit);
    _layout->addLayout(form, 1, 0);
    _mapper->addMapping(_itemNameEdit, 1);

    connect(_mapper, SIGNAL(currentIndexChanged(int)), this, SLOT(refreshUi(int)));
    _mapper->toFirst();
}

void TabItems::refreshUi(int index)
{
    _itemNameEdit->setDisabled(!(_mapper->model()->flags(_mapper->model()->index(index, 1)) & Qt::ItemIsEditable));
}