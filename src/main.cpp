#include <QApplication>
#include <ui/mod_window.h>
#include <model/mod.h>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    Mod mod;
    ModWindow win(mod);

    win.show();

    return app.exec();
}
