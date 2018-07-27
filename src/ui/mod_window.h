#ifndef INCLUDED_UI_MOD_WINDOW_H
#define INCLUDED_UI_MOD_WINDOW_H

#include <QMainWindow>

class ModWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ModWindow(QWidget* parent = nullptr);
};

#endif
