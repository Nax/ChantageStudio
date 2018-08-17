#include <QGridLayout>
#include <QCheckBox>
#include <QLabel>
#include <ui/elements_editor.h>

static const char* const kElementsNames[] = {
    "Fire",
    "Lightning",
    "Ice",
    "Wind",
    "Earth",
    "Water",
    "Holy",
    "Dark"
};

static const char* const kElementsStyles[] = {
    "QLabel { padding-left: 2; background-color: red; color: white; }",
    "QLabel { padding-left: 2; background-color: yellow; color: black; }",
    "QLabel { padding-left: 2; background-color: cyan; color: black; }",
    "QLabel { padding-left: 2; background-color: green; color: white; }",
    "QLabel { padding-left: 2; background-color: chocolate; color: black; }",
    "QLabel { padding-left: 2; background-color: blue; color: white; }",
    "QLabel { padding-left: 2; background-color: white; color: black; }",
    "QLabel { padding-left: 2; background-color: black; color: white; }",
};

ElementsEditor::ElementsEditor(const QString& title, QWidget* parent) : QWidget(parent), _flags(0)
{
    setFocusPolicy(Qt::StrongFocus);
    QGridLayout* grid = new QGridLayout;
    grid->setVerticalSpacing(2);
    grid->setHorizontalSpacing(2);
    grid->addWidget(new QLabel(title), 0, 0, 1, 2);
    for (int i = 0; i < 8; ++i)
    {
        QCheckBox* box = new QCheckBox;
        QLabel* label = new QLabel(kElementsNames[i]);
        label->setStyleSheet(kElementsStyles[i]);
        connect(box, SIGNAL(clicked(bool)), this, SLOT(clicked()));
        grid->addWidget(box, i + 1, 0);
        grid->addWidget(label, i + 1, 1);
        _checkbox[i] = box;
    }
    setLayout(grid);
}

int ElementsEditor::flags() const
{
    return _flags;
}

void ElementsEditor::setFlags(int flags)
{
    _flags = flags & 0xff;
    for (int i = 0; i < 8; ++i)
    {
        _checkbox[i]->setChecked(_flags & (1 << (7 - i)));
    }
}

void ElementsEditor::clicked()
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