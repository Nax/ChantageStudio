#include <QGridLayout>
#include <QCheckBox>
#include <QLabel>
#include <ui/weapon_flags_editor.h>

static const char* const kLabels[] = {
    "Striking",
    "Lunging",
    "Direct",
    "Arc",
    "Two Swords",
    "Two Hands",
    "Throwable",
    "Forced Two Hands"
};

WeaponFlagsEditor::WeaponFlagsEditor(QWidget* parent) : QWidget(parent), _flags(0)
{
    setFocusPolicy(Qt::StrongFocus);
    QGridLayout* grid = new QGridLayout;
    grid->setVerticalSpacing(2);
    grid->setHorizontalSpacing(4);
    grid->addWidget(new QLabel("Weapon Flags"), 0, 0, 1, 2);
    for (int i = 0; i < 8; ++i)
    {
        QCheckBox* box = new QCheckBox;
        connect(box, SIGNAL(clicked(bool)), this, SLOT(clicked()));
        grid->addWidget(box, i + 1, 0);
        grid->addWidget(new QLabel(kLabels[i]), i + 1, 1);
        _checkbox[i] = box;
    }
    setLayout(grid);
}

int WeaponFlagsEditor::flags() const
{
    return _flags;
}

void WeaponFlagsEditor::setFlags(int flags)
{
    _flags = flags & 0xff;
    for (int i = 0; i < 8; ++i)
    {
        _checkbox[i]->setChecked(_flags & (1 << (7 - i)));
    }
}

void WeaponFlagsEditor::clicked()
{
    _flags = 0;
    for (int i = 0; i < 8; ++i)
    {
        if (_checkbox[i]->isChecked())
            _flags |= (1 << (7 - i));
    }
    setFocus(Qt::NoFocusReason);
    clearFocus();
    emit change(_flags);
}