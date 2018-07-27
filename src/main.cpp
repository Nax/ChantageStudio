#include <QApplication>
#include <ui/mod_window.h>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    ModWindow win;

    win.show();

    return app.exec();
}
