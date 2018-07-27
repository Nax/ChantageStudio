#include <QLabel>
#include <QVBoxLayout>
#include <ui/editor_item.h>

EditorItem::EditorItem(QWidget* parent)
: QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout;

    layout->addWidget(new QLabel("Item Editor"));
    setLayout(layout);
}
