#include <QTabWidget>
#include <QVBoxLayout>
#include <ui/mod_window.h>
#include <ui/tab_items.h>
#include <ui/tab_base.h>

ModWindow::ModWindow(QWidget* parent)
: QMainWindow(parent)
{
    setWindowTitle("Chantage Studio");
    QVBoxLayout* layout = new QVBoxLayout;

    QTabWidget* tabWidget = new QTabWidget;
    tabWidget->addTab(new TabBase("Items"), "Items");
    tabWidget->addTab(new TabBase("Item Attributes"), "Item Attributes");

    layout->addWidget(tabWidget);
    setCentralWidget(new QWidget);
    centralWidget()->setLayout(layout);
}
