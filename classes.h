#ifndef CLASSES_H
#define CLASSES_H
#include "student.h"
#include <QString>
#include <vector>

// 分班结果结构体
struct Classes {
    int classId;//班级编号
    QString className;//班级名称
    int currentSize = 0; //目前班级人数
    int totalStu; //设置每班级需要分配总人数
    std::vector<Student> students; //实际配学生
    int fMaleCount;//实际分配男生数
    int fFemaleCount;//实际分配女生数
    qreal totalScore; //实际班级总分数
};
#endif // CLASSES_H


