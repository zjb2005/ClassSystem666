#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
{
    ui->setupUi(this);
}
// 示例：使用QVBoxLayout和QHBoxLayout
// QVBoxLayout *mainLayout = new QVBoxLayout;
// QHBoxLayout *topLayout = new QHBoxLayout;

// QPushButton *button1 = new QPushButton("Button 1");
// QPushButton *button2 = new QPushButton("Button 2");

// topLayout->addWidget(button1);
// topLayout->addWidget(button2);

// mainLayout->addLayout(topLayout);
// mainLayout->addWidget(new QTextEdit);

// setLayout(mainLayout);

// setLayout(mainLayout);
Form::~Form()
{
    delete ui;
}
