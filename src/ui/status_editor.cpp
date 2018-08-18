#include <QGridLayout>
#include <QCheckBox>
#include <QLabel>
#include <ui/status_editor.h>

static const char* const kLabels[] = {
    "(None)",
    "Crystal",
    "Dead",
    "Undead",
    "Charging",
    "Jump",
    "Defending",
    "Performing",
    "Stone",
    "Traitor",
    "Blind",
    "Confusion",
    "Silence",
    "Vampire",
    "Evil",
    "Treasure",
    "Oil",
    "Float",
    "Reraise",
    "Invisible",
    "Berserk",
    "Chicken",
    "Toad",
    "Critical",
    "Poison",
    "Regen",
    "Protect",
    "Shell",
    "Haste",
    "Slow",
    "Stop",
    "Wall",
    "Faith",
    "Atheist",
    "Charm",
    "Sleep",
    "Immobilize",
    "Disable",
    "Reflect",
    "Doom"
};

StatusEditor::StatusEditor(const QString& label, QWidget* parent) : QWidget(parent), _flags(40)
{
    setFocusPolicy(Qt::StrongFocus);
    QGridLayout* grid = new QGridLayout;
    grid->setVerticalSpacing(2);
    grid->setHorizontalSpacing(4);
    grid->addWidget(new QLabel(label), 0, 0, 1, 2);
    for (int i = 0; i < 40; ++i)
    {
        QCheckBox* box = new QCheckBox;
        connect(box, SIGNAL(clicked(bool)), this, SLOT(clicked()));
        grid->addWidget(box, (i % 10) + 1, i / 10 * 3);
        grid->addWidget(new QLabel(kLabels[i]), (i % 10) + 1, i / 10 * 3 + 1);
        _checkbox[i] = box;
    }
    for (int i = 0; i < 3; ++i)
        grid->setColumnStretch(i * 3 + 2, 1);
    setLayout(grid);
}

QBitArray StatusEditor::flags() const
{
    return _flags;
}

void StatusEditor::setFlags(QBitArray flags)
{
    _flags = flags;
    for (int i = 0; i < 40; ++i)
    {
        _checkbox[i]->setChecked(flags.testBit((i / 8) * 8 + (7 - (i % 8))));
    }
}

void StatusEditor::clicked()
{
    for (int i = 0; i < 40; ++i)
    {
        _flags.setBit((i / 8) * 8 + (7 - (i % 8)), _checkbox[i]->isChecked());
    }
    setFocus(Qt::NoFocusReason);
    clearFocus();
    emit change(_flags);
}