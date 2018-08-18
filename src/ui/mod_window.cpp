#include <QTabWidget>
#include <QVBoxLayout>
#include <ui/mod_window.h>
#include <ui/tab_items.h>

ModWindow::ModWindow(Mod& mod, QWidget* parent)
: QMainWindow(parent)
{
    setWindowTitle("Chantage Studio");
    QVBoxLayout* layout = new QVBoxLayout;

    QTabWidget* tabWidget = new QTabWidget;
    tabWidget->addTab(new TabItems(mod), "Items");

    layout->addWidget(tabWidget);
    setCentralWidget(new QWidget);
    centralWidget()->setLayout(layout);
}
