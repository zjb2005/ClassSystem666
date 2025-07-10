#ifndef STARTCLASSFORM_H
#define STARTCLASSFORM_H

#include "classdata.h"
#include "classes.h"
#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QMap>
#include <qcheckbox.h>
#include <qlabel.h>
#include <qmediaplayer.h>
#include <qpushbutton.h>
#include <qprogressbar.h>
#pragma once

namespace Ui {
class StartClassForm;
}

class StartClassForm : public QWidget
{
    Q_OBJECT

public:
    explicit StartClassForm(QWidget *parent = nullptr);

    ~StartClassForm();
    // 第一二的动画
    void startAnimation1(QList<Classes> classLists);
    void startAnimation2(QList<Classes> classLists);

    // 1.男女均衡分班
    QList<Classes> sunshineAssignment();

    // 2.成绩均衡分班
    QList<Classes> balancedAssignmentByScore();

    // 3.随机分班
    QList<Classes> randomAssignment();

    // 4.成绩+男女均衡分班
    QList<Classes> AssignmentByScore_Sex();

    // 随机打乱学生顺序
    QList<Classes> shuffleStudents(std::vector<Student>& students);

    // 导出数据到excel文件1
    void exportToExcelWithQXlsx1(const QList<Classes>& classes);
    // 导出数据到excel文件2
    void exportToExcelWithQXlsx2(const QList<Classes>& classes);
    // 导出excel数据到Pdf文件
    // void exportToPdf(const QString& excelPath, const QString& pdfPath);
    // 打开Pdf文件
    // void openPdf(const QString filePath);
    // 阳光分班list
    QList<Classes> sunClassList;

public slots:
    // 接收数据的槽函数
    // 在这个窗口中显示接收到的数据
    void receiveData(ClassData data);
    //开始窗口按钮
    void on_startButton_clicked();
    // 播放音乐
    void onMusicToggle();

signals:
    //发送分班结果
    void sendClassesResultData(QList<Classes> ClassesResultLists);

private:
    // 音乐按钮
    QCheckBox *musicBox;
    // 创建进度条
    QProgressBar *progressBar;
    //开始按钮
    QPushButton *startButton;
    // 分班数据存,指针
    ClassData classData;
    // title标题
    QLabel *label1;
    //分班信息左边框layout2_1
    QVBoxLayout *layout2_1;
    // 分班信息左边框显示

    // 音乐播放器
    QAudioOutput *audioOutput;
    QMediaPlayer *player;


    //所有学生信息student
    QList<Student> list1;

    // 输入框
    QLineEdit *stuNameEdit;
    QLineEdit *stuIdEdit;

    QWidget *widget2_1;
    QWidget *widget2_2;
    QWidget *widget2_3;

    QVBoxLayout *layout2_2;
    QVBoxLayout *layout2_3;

    // 分班班级信息Map
    // QMap<QString, QString> classInfoMap;
    // 班级数量
    // int class_Num = classInfoMap.size();

    // 结构体保存班级信息
    std::vector<Classes> classes;

    Ui::StartClassForm *ui;
};


#endif // STARTCLASSFORM_H




