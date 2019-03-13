#ifndef INCLUDED_UI_WEAPON_ELEMENTS_EDITOR_H
#define INCLUDED_UI_WEAPON_ELEMENTS_EDITOR_H

#include <QWidget>
#include <QCheckBox>

class ElementsEditor : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(
        int flags
        READ flags
        WRITE setFlags
        NOTIFY change
        USER true
    );

public:
    explicit ElementsEditor(const QString& title, QWidget* parent = nullptr);
    int flags() const;
    void setFlags(int flags);

signals:
    void change(int flags);

private slots:
    void clicked();

private:
    int         _flags;
    QCheckBox*  _checkbox[8];
};

#endif