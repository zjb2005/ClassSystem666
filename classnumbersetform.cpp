#include "classnumbersetform.h"
#include "ui_classnumbersetform.h"

#include <qmessagebox.h>

ClassNumberSetForm::ClassNumberSetForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClassNumberSetForm)
{
    ui->setupUi(this);
}

ClassNumberSetForm::~ClassNumberSetForm()
{
    delete ui;
}

void ClassNumberSetForm::setClassAndStu(QStandardItemModel *model){
    this->model2 = model;
}

void ClassNumberSetForm::on_pushButton_clicked()
{
    QString classNum1 = ui->lineEdit1->text().trimmed();  // 你的LineEdit对象名为
    QString stuNum1 = ui->lineEdit2->text().trimmed();
    if ((ui->lineEdit1->text().trimmed().isEmpty())||(ui->lineEdit2->text().trimmed().isEmpty())){
        QMessageBox::information(this, "提示", "未输入班级或者人数");
        return;
    }

    // 添加子项
    this->model2->appendRow({new QStandardItem("班级( "+classNum1+" )"),new QStandardItem(stuNum1)});
    this->close();

}



