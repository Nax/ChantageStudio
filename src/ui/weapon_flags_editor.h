#ifndef INCLUDED_UI_WEAPON_FLAGS_EDITOR_H
#define INCLUDED_UI_WEAPON_FLAGS_EDITOR_H

#include <QWidget>

class WeaponFlagsEditor : public QWidget
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
    explicit WeaponFlagsEditor(QWidget* parent = nullptr);
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