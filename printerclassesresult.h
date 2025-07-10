#ifndef PRINTERCLASSESRESULT_H
#define PRINTERCLASSESRESULT_H

#include "classdata.h"

#include <QLabel>
#include <QStandardItemModel>
#include <QTableWidget>
#include <QWidget>

namespace Ui {
class PrinterClassesResult;
}

class PrinterClassesResult : public QWidget
{
    Q_OBJECT

public:
    explicit PrinterClassesResult(QWidget *parent = nullptr);
    ~PrinterClassesResult();

    // 接收title数据函数
    void setTitle(const QString &title);
    void showClassInfo();

public slots:
    // 接收数据的槽函数
    // 在这个窗口中显示接收到的数据
    void receivePrinterData(QList<Classes> resultLists);

public slots:
    void printWindowInfo();
    void printEntireWidget(QWidget* widget);


private:
    Ui::PrinterClassesResult *ui;

    // 项目标题
    QLabel *label1;
    // 学生名单
    QTableView *tableView;
    // 学生名单
    QStandardItemModel *model;
    //保存title数据
    QString titleData;
    //保存接收到的分班结果
    QList<Classes> classesResultLists;

};

#endif // PRINTERCLASSESRESULT_H
