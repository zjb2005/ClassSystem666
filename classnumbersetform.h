#ifndef CLASSNUMBERSETFORM_H
#define CLASSNUMBERSETFORM_H

#include "classes.h"

#include <QStandardItemModel>
#include <QWidget>

namespace Ui {
class ClassNumberSetForm;
}

class ClassNumberSetForm : public QWidget
{
    Q_OBJECT

public:
    explicit ClassNumberSetForm(QWidget *parent = nullptr);
    ~ClassNumberSetForm();

    void setClassAndStu(QStandardItemModel *model);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ClassNumberSetForm *ui;
    // 班级数
    QString classNum;
    //班级人数
    QString stuNum;
    QStandardItemModel *model2;
    //保存接收到的分班结果
    //QList<Classes> classesResultLists;


};

#endif // CLASSNUMBERSETFORM_H
