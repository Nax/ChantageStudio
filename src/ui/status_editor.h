#ifndef INCLUDED_UI_STATUS_EDITOR_H
#define INCLUDED_UI_STATUS_EDITOR_H

#include <QBitArray>
#include <QWidget>

class StatusEditor : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(
        QBitArray flags
        READ flags
        WRITE setFlags
        NOTIFY change
        USER true
    );

public:
    explicit StatusEditor(const QString& label, QWidget* parent = nullptr);
    QBitArray flags() const;
    void setFlags(QBitArray flags);

signals:
    void change(QBitArray flags);

private slots:
    void clicked();

private:
    QBitArray   _flags;
    QCheckBox*  _checkbox[40];
};

#endif