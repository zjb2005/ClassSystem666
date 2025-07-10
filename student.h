// student.h
#ifndef STUDENT_H
#define STUDENT_H

#include <qtypes.h>
#include <string>

class Student
{
    private:
        std::string sSchool ;//学校名称
        std::string sName;//姓名
        std::string sSex;//性别
        std::string sId;//身份证号码
        qreal sGrade;
        std::string sNotes;

    public:
        // 构造函数（默认构造函数 + 带参构造函数）
        Student();
        Student(std::string school, std::string name, std::string sex, std::string id, qreal grade, std::string notes);

        // 析构函数
        ~Student();

        void setSchool(std::string school);
        std::string getSchool();

        void setName(std::string name);
        std::string getName()const;

        void setSex(std::string sex);
        std::string getSex()const;

        void setId(std::string id);
        std::string getId()const;

        void setGrade(qreal grade);
        qreal getGrade()const;

        void setNotes(std::string notes);
        std::string getNotes()const;

};

#endif // STUDENT_H
