// student.cpp
#include "student.h"
#include <qtypes.h>

// 默认构造函数
Student::Student()
{
    sSchool = "";
    sName = "";
    sSex = "";
    sId = "";
    sGrade = 0;
    sNotes = "";
}

// 带参构造函数
Student::Student(std::string school, std::string name, std::string sex, std::string id, qreal grade, std::string notes)
{
    sSchool = school;
    sName = name;
    sSex = sex;
    sId = id;
    sGrade = grade;
    sNotes = notes;
}

// 析构函数
Student::~Student()
{
    // 如果类中有动态分配的资源（如指针），需要在此释放
    // 本例中无需额外操作
}

void Student::setSchool(std::string school)
{
    sSchool = school;
}

std::string Student::getSchool()
{
    return sSchool;
}


void Student::setName(std::string name)
{
    sName = name;
}

std::string Student::getName() const
{
    return sName;
}

void Student::setSex(std::string sex)
{
    sSex = sex;
}

std::string Student::getSex() const
{
    return sSex;
}

void Student::setId(std::string id)
{
    sId = id;
}

std::string Student::getId() const
{
    return sId;
}

void Student::setGrade(qreal grade)
{
    sGrade = grade;
}

qreal Student::getGrade() const
{
    return sGrade;
}

void Student::setNotes(std::string notes)
{
    sNotes = notes;
}

std::string Student::getNotes() const
{
    return sNotes;
}
