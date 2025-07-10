#ifndef CLASSDATA_H
#define CLASSDATA_H

#include "classes.h"
#include "student.h"
#include <QWidget>

class ClassData
{

private:
    QList<Student> studentList;//学生名单
    QList<Classes> sunClassList;//班级信息
    QMap<QString, int> classStrate;//分班策略
    QString title;//分班标题

public:
    // 构造函数（默认构造函数 + 带参构造函数）
    ClassData();
    ClassData(QList<Student> studentList, QList<Classes> sunClassList, QMap<QString, int> classStrate,QString title);
    // 析构函数
    ~ClassData();

    void setStudentList(QList<Student> studentList);
    QList<Student> getStudentList();

    void setSunClassList(QList<Classes> sunClassList);
    QList<Classes> getSunClassList();

    void setClassStrate(QMap<QString, int> classStrate);
    QMap<QString, int> getClassStrate();

    void setTitle(QString title);
    QString getTitle();
};




#endif // CLASSDATA_H
