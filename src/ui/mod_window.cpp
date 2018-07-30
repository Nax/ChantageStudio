#include <QTabWidget>
#include <QVBoxLayout>
#include <ui/mod_window.h>
#include <ui/tab_items.h>
#include <ui/tab_item_attributes.h>

ModWindow::ModWindow(Mod& mod, QWidget* parent)
: QMainWindow(parent)
{
    setWindowTitle("Chantage Studio");
    QVBoxLayout* layout = new QVBoxLayout;

    QTabWidget* tabWidget = new QTabWidget;
    tabWidget->addTab(new TabItems(mod), "Items");
    tabWidget->addTab(new TabItemAttributes(mod), "Item Attributes");

    layout->addWidget(tabWidget);
    setCentralWidget(new QWidget);
    centralWidget()->setLayout(layout);
}
