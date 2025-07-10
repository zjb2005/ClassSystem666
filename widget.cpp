#include "widget.h"
#include "./ui_widget.h"
#include "classset.h"
#include <Qlabel>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QMessageBox>

Widget::Widget(QWidget *parent): QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(800, 600);

    setWindowTitle("阳光分班系统");  // 设置窗口标题

    // QFrame *frame = new QFrame(this);
    // frame->setFrameShape(QFrame::StyledPanel);  // 设置框架形状
    // frame->setFrameShadow(QFrame::Raised);      // 设置阴影效果
    // frame->setStyleSheet("background: yellow; border-radius: 10bx;");

    QLabel *label = new QLabel("分班名称:");
    QFont labelFont;
    labelFont.setPointSize(18);
    label->setFont(labelFont);


    lineEdit = new QLineEdit(this);
    QFont font;
    font.setPointSize(18);  // 设置字体大小为14磅
    lineEdit->setText("2025年秋季一年级秋季分班");  // 设置初始文本
    lineEdit->setFont(font);

    lineEdit->setMaxLength(40);
    lineEdit->setFixedSize(350,50);//宽度200px，高度30px

    // 按钮行（单独一行）
    QPushButton *submitBtn = new QPushButton("下一步");

    QFont submitBtnFont;
    submitBtnFont.setPointSize(18);
    submitBtn->setFont(submitBtnFont);

    submitBtn->setFixedSize(120, 50);  // 宽度 120px，高度 50px

    // 创建自定义调色板
    // QPalette palette;
    // palette.setColor(QPalette::Window, QColor(240, 240, 240)); // 背景色
    // palette.setColor(QPalette::WindowText, Qt::darkBlue);         // 文字颜色
    // palette.setColor(QPalette::Button, QColor(70, 255, 90));   // 按钮颜色
    // palette.setColor(QPalette::ButtonText, Qt::darkCyan);         // 按钮文字颜色

    // // 应用调色板
    // qApp->setPalette(palette);

    QFormLayout *formLayout = new QFormLayout();
    // 设置表单属性
    formLayout->setSpacing(50);
    formLayout->addRow(label, lineEdit);
    formLayout->addRow(nullptr,submitBtn);  // 没有标签的单独行
    this->setLayout(formLayout);

    formLayout->setFormAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    // 连接信号和槽,绑定按钮
    connect(submitBtn, &QPushButton::clicked, this, &Widget::onNextButtonClicked);

}



void Widget::onNextButtonClicked()
{
    ClassSet *c = new ClassSet();
    QString titleText = this->lineEdit->text().trimmed();
    c->setData(titleText);
    c->show();
    // 关闭当前窗口
    this->close();
    // QMessageBox::information(this, "提示", "按钮被点击，即将进入分班设置");

}

Widget::~Widget()
{
    delete ui;
}
