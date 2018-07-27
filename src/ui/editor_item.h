#ifndef INCLUDED_UI_EDITOR_ITEM_H
#define INCLUDED_UI_EDITOR_ITEM_H

#include <QWidget>

class EditorItem : public QWidget
{
    Q_OBJECT

public:
    explicit EditorItem(QWidget* parent = nullptr);
};

#endif
