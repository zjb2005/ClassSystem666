#ifndef WIDGET_H
#define WIDGET_H


#include <QWidget>
#include <QPushButton>
#include <qlineedit.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void onNextButtonClicked();  // 声明槽函数

private:
    Ui::Widget *ui;

    //项目名称，输入框
    QLineEdit *lineEdit;
};
#endif // WIDGET_H




