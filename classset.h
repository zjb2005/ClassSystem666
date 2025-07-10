#ifndef CLASSSET_H
#define CLASSSET_H

#include "classdata.h"
#include "student.h"
#include <QWidget>
#include <qcheckbox.h>
#include <qlabel.h>
#include <qstandarditemmodel.h>
#include <qtableview.h>

namespace Ui {
class ClassSet;
}

class ClassSet : public QWidget
{
    Q_OBJECT

public:
    explicit ClassSet(QWidget *parent = nullptr);
    ~ClassSet();

    // 接收title数据函数
    void setData(const QString &titleText);

    // 总人数，返回班级数
    int calculateClasses(int totalStudents);
    //返回每个班级人数
    QVector<int> printDistribution(int totalStudents, int numClasses);
signals:
    // 定义信号，用于发送数据
    void sendData(ClassData data);
    void sendPrinterData(QList<Classes> classesResultLists);

//声明槽函数
public slots:
    void on_beginButton_clicked();
    void on_pushB1_clicked();
    void on_clearButton_clicked();
    void on_printerClassesResultButton_clicked();
    void on_searchButton_clicked();
    void on_classSettingbtn_clicked();
    void on_deleteBtn_clicked();
    void updateCheckBoxStates();
    //接收分别结果信息
    void receiveClassesResultData(QList<Classes> classesResultLists);

private:
    Ui::ClassSet *ui;

    // 项目标题
    QLabel *label1;
    // 搜索框
    QLineEdit *l3_edit1;
    // 学生名单
    QTableView *tableView1;
    // 班级设置名单
    QTableView *tableView2;
    // 学生名单
    QStandardItemModel *model1;
    // 班级人数设置
    QStandardItemModel *model2;
    // l6班级人数标签
    QLabel *numberLabel;
    // l6班级人数标签
    QString numberStu2;
    //保存导入的学生名单
    QList<Student> studentList;
    //保存title数据
    QString titleData;
    //保存接收到的分班结果
    QList<Classes> classesResultLists;

    //四个复选框
    QCheckBox *genderBalance;
    QCheckBox *nameBalance;
    QCheckBox *scoreBalance;
    QCheckBox *randomAssign;

};

#endif // CLASSSET_H
