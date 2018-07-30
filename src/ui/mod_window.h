#ifndef INCLUDED_UI_MOD_WINDOW_H
#define INCLUDED_UI_MOD_WINDOW_H

#include <QMainWindow>

struct Mod;
class ModWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ModWindow(Mod& mod, QWidget* parent = nullptr);
};

#endif
