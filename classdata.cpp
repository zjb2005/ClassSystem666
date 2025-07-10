#include "classdata.h"

// 默认构造函数
ClassData::ClassData()
{
    QList<Student> studentList;//学生名单
    QList<Classes> sunClassList;//班级信息
    QMap<QString, int> classStrate;//分班策略
    QString title = "";
}

// 带参构造函数
ClassData::ClassData(QList<Student> studentList, QList<Classes> sunClassList, QMap<QString, int> classStrate, QString title)
{
    this->studentList = studentList;
    this->sunClassList = sunClassList;
    this->classStrate = classStrate;
    this->title = title;
}

// 析构函数
ClassData::~ClassData()
{
    // 如果类中有动态分配的资源（如指针），需要在此释放
    // 本例中无需额外操作
}

void ClassData::setStudentList(QList<Student> studentList)
{
    this->studentList = studentList;
}
QList<Student> ClassData::getStudentList()
{
    return studentList;
}

void ClassData::setSunClassList(QList<Classes> sunClassList)
{
    this->sunClassList = sunClassList;
}
QList<Classes> ClassData::getSunClassList()
{
    return sunClassList;
}

void ClassData::setClassStrate(QMap<QString, int> classStrate)
{
    this->classStrate = classStrate;
}
QMap<QString, int> ClassData::getClassStrate()
{
    return classStrate;
}

void ClassData::setTitle(QString title)
{
    this->title = title;
}
QString ClassData::getTitle()
{
    return title;
}


