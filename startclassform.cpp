#include "startclassform.h"
#include "classdata.h"
#include "student.h"
#include "ui_startclassform.h"
#include "xlsxdocument.h"
#include "xlsxformat.h"
// #include "QMediaDevices.h"
#include <QCheckBox>
#include <QGraphicsDropShadowEffect>
#include <QLabel>
#include <QLineEdit>
#include <QProgressBar>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextStream>
#include <QPainter>
#include <QSequentialAnimationGroup>
#include <qtimer.h>
#include <qfiledialog.h>
#include <qmessagebox.h>
#include <QDateTime>
#include <qdesktopservices.h>
#include <QApplication>
#include <QPrinter>
#include <QPainter>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QAudioFormat>
#include <QScrollArea>
#include "xlsxdocument.h"


StartClassForm::StartClassForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StartClassForm)
{
    ui->setupUi(this);

    //垂直布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    // 设置布局外边距（左、上、右、下）
    //mainLayout->setContentsMargins(20, 10, 20, 10);
    // 或者分别设置宽度和高度
    //上--------------------------------------------------------------------------
    QWidget *widget1 = new QWidget();
    //widget1->setFixedSize(800, 150);  // 设置固定大小
    //中间布局，创建水平布局
    QHBoxLayout *layout1 = new QHBoxLayout(widget1);
    // 创建标签并设置文本
    // titleLabel = classData.getTitle();
    // 初始创一个label的值
    label1 = new QLabel("分班");
    // 使用样式表设置字体大小
    label1->setStyleSheet("font-size: 80px;color: red;");
    label1->setFixedHeight(150);    // 固定高度
    //水平和垂直都居中
    label1->setAlignment(Qt::AlignCenter);
    layout1->addWidget(label1);
    //中---------------------------------------------------------------------
    QWidget *widget2 = new QWidget();
    //widget2->setFixedSize(800, 550);  // 设置固定大小
    //中间布局，创建水平布局
    QHBoxLayout *layout2 = new QHBoxLayout(widget2);
    //layout2->setAlignment(Qt::AlignHCenter);  // 水平居中
    widget2_1 = new QWidget();
    widget2_2 = new QWidget();
    widget2_3 = new QWidget();
    // 设置固定大小（宽×高）,// 宽度200像素，高度100像素
    widget2_1->setFixedSize(300, 500);
    widget2_2->setFixedSize(300, 500);
    widget2_3->setFixedSize(300, 500);

    // widget2_1->setStyleSheet(
    //     "QWidget {"
    //     "   background-color: white;"
    //     "   border: 2px solid gray;"
    //     "   border-radius: 10px;"
    //     "}"
    //     );

    // widget2_3->setStyleSheet(
    //     "QWidget {"
    //     "   background-color: white;"
    //     "   border: 2px solid gray;"
    //     "   border-radius: 10px;"
    //     "}"
    //     );

    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
    effect->setBlurRadius(10);
    effect->setXOffset(0);
    effect->setYOffset(0);
    effect->setColor(QColor(0, 0, 0, 100));

    widget2_1->setGraphicsEffect(effect);
    widget2_1->setStyleSheet("background: white; border-radius: 10px;");
    widget2_1->setWindowTitle("分班信息总结");
    widget2_3->setGraphicsEffect(effect);
    widget2_3->setStyleSheet("background: white; border-radius: 10px;");

    //layout2_1------------------------------------------------------------------------------
    //中间布局，创建水平布局
    layout2_1 = new QVBoxLayout(widget2_1);

    // 创建 infoLabel 并设置 parent 为 widget2_1
    // schoolLabel = new QLabel("这是一个标签");
    // peopleLabel = new QLabel("这是一个标签");
    // 设置字体大小
    // schoolLabel->move(50, 20);
    // schoolLabel->setStyleSheet("font-size: 15pt;color: black;");
    // peopleLabel->setStyleSheet("font-size: 15pt;color: black;");
    // classLabel->setStyleSheet("font-size: 15pt;color: black;");
    // strateLabel->setStyleSheet("font-size: 15pt;color: black;");
    // 添加label到layout上
    // layout2_1->addWidget(schoolLabel);
    // layout2_1->addWidget(peopleLabel);
    // layout2_1->addWidget(classLabel);
    // layout2_1->addWidget(strateLabel);
    layout2_1->setSpacing(10);  // 设置10像素的间距
    // 示例1：顶部弹簧
    //layout2_1->addStretch();
    //layout2_1 end------------------------------------------------------------------------------


    //layout2_2------------------------------------------------------------------------------
    layout2_2 = new QVBoxLayout(widget2_2);
    //姓名
    QLabel *stuName = new QLabel("姓   名");
    stuName->setStyleSheet("font-size: 18pt;");

    //姓名输入框
    stuNameEdit = new QLineEdit();
    stuNameEdit->setFixedSize(150,40);
    stuNameEdit->setAlignment(Qt::AlignCenter);
    stuNameEdit->setGraphicsEffect(effect);
    stuNameEdit->setStyleSheet("font-size: 14pt;background: white;border-radius: 10px;");


    //编号
    QLabel *stuId = new QLabel("编   号");
    stuId->setStyleSheet("font-size: 18pt;");

    //编号输入框
    stuIdEdit = new QLineEdit();
    stuIdEdit->setFixedSize(250,40);
    stuIdEdit->setAlignment(Qt::AlignCenter);
    //stuIdEdit->setStyleSheet("font-size: 14pt;background: white;");
    stuIdEdit->setGraphicsEffect(effect);
    stuIdEdit->setStyleSheet("font-size: 14pt;background: white;border-radius: 10px;");

    //开始按钮
    startButton = new QPushButton("开  始");
    startButton->setFixedSize(120, 80);
    //startButton->setStyleSheet("font-size: 24pt;background: white;");
    startButton->setStyleSheet(
        // 普通状态样式
        "QPushButton {"
        "   background-color: #4CAF50;"      // 背景色
        "   border: none;"                   // 无边框
        "   color: white;"                   // 文字颜色
        "   padding: 10px 24px;"             // 内边距
        "   text-align: center;"             // 文字居中
        "   text-decoration: none;"          // 无文字装饰
        "   font-size: 24px;"                // 字体大小
        "   margin: 4px 2px;"                // 外边距
        "   border-radius: 8px;"             // 圆角半径
        "}"

        // 鼠标悬停状态
        "QPushButton:hover {"
        "   background-color: #45a049;"      // 悬停时背景色
        "}"

        // 按下状态
        "QPushButton:pressed {"
        "   background-color: #3e8e41;"      // 按下时背景色
        "}"

        // 禁用状态
        "QPushButton:disabled {"
        "   background-color: #cccccc;"      // 禁用时背景色
        "   color: #666666;"                 // 禁用时文字颜色
        "}"
        );

    musicBox = new QCheckBox("音乐");
    musicBox->setStyleSheet(
        // 未选中状态
        "QCheckBox {"
        "   spacing: 8px;"  // 文本和框之间的间距
        "   color: #000000;"  // 文本颜色
        "}"

        "QCheckBox::indicator {"
        "   width: 18px;"
        "   height: 18px;"
        "   border: 1px solid #c8c8c8;"
        "   border-radius: 4px;"  // 稍微圆角
        "   background: #ffffff;"
        "}"

        // 悬停状态
        "QCheckBox::indicator:hover {"
        "   border: 1px solid #007AFF;"
        "}"

        // 选中状态
        "QCheckBox::indicator:checked {"
        "   background: #007AFF;"
        "   border: 1px solid #007AFF;"
        "   image: url(:/icons/checked.png);"  // 使用对勾图标
        "}"

        // 禁用状态
        "QCheckBox::indicator:disabled {"
        "   background: #ebebeb;"
        "   border: 1px solid #d1d1d1;"
        "}"
        );
    // // 2. 设置音频格式
    // QAudioFormat format;
    // format.setSampleRate(44100);
    // format.setChannelCount(2);
    // format.setSampleFormat(QAudioFormat::Int16);

    // // 配置媒体播放器
    // audioOutput = new QAudioOutput(this);
    // player = new QMediaPlayer(this);
    // player->setAudioOutput(audioOutput);
    // audioOutput->setVolume(100); // 50% 音量

    // // 设置音乐文件路径（使用资源文件）
    // player->setSource(QUrl("qrc:/background.mp3"));

    // 连接 CheckBox 信号
    connect(musicBox, &QCheckBox::checkStateChanged, this, &StartClassForm::onMusicToggle);
    // layout2_2->addStretch();  // 上方伸缩空间
    // layout2_2->addStretch();  // 下方伸缩空间


    // 示例1：顶部弹簧
    layout2_2->addStretch();
    layout2_2->addWidget(stuName,0, Qt::AlignBottom | Qt::AlignHCenter);
    layout2_2->addWidget(stuNameEdit,0, Qt::AlignHCenter);
    // 设置控件之间的间距（单位：像素）
    //layout2_2->setSpacing(50);  // 设置10像素的间距
    // 创建固定大小的垂直弹簧,参数：宽度, 高度, 水平策略, 垂直策略
    QSpacerItem *verticalSpacer1 = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);
    layout2_2->addItem(verticalSpacer1);
    layout2_2->addWidget(stuId,0, Qt::AlignBottom | Qt::AlignHCenter);
    layout2_2->addWidget(stuIdEdit,0, Qt::AlignHCenter);
    // 创建固定大小的垂直弹簧,参数：宽度, 高度, 水平策略, 垂直策略
    //QSpacerItem *verticalSpacer2 = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);
    layout2_2->addItem(verticalSpacer1);
    layout2_2->addWidget(startButton,0, Qt::AlignHCenter);
    layout2_2->addWidget(musicBox,0, Qt::AlignHCenter);
    layout2_2->addStretch();
    // 设置控件之间的间距（单位：像素）
    //layout2_2->setSpacing(10);  // 设置10像素的间距
    //layout2_2 end------------------------------------------------------------------------------
    //layout2_3 start------------------------------------------------------------------------------
    //垂直布局
    layout2_3 = new QVBoxLayout(widget2_3);

    //layout2_3 end------------------------------------------------------------------------------
    layout2->addStretch();
    layout2->addWidget(widget2_1);
    layout2->addWidget(widget2_2);
    layout2->addWidget(widget2_3);
    layout2->addStretch();
    //layout2 end---------------------------------------
    //下----------------------------------------------------------------------------
    QWidget *widget3 = new QWidget();
    //widget3->setFixedSize(1000, 100);  // 设置固定大小
    widget3->setFixedHeight(100);    // 固定高度
    // 创建进度条
    progressBar = new QProgressBar;
    progressBar->setFixedSize(700, 25);
    // progressBar->setRange(0, 200);
    // progressBar->setValue(70);
    progressBar->setTextVisible(true);
    progressBar->setFormat("当前进度: %p%");
    QHBoxLayout *layout3 = new QHBoxLayout(widget3);
    layout3->addWidget(progressBar,0, Qt::AlignHCenter);
    // progressBar->setStyleSheet(
    //     "QProgressBar {"
    //     "   border: 2px solid #C4C4C4;"  // 边框
    //     "   border-radius: 5px;"         // 圆角
    //     "   background: #F0F0F0;"        // 背景色
    //     "   text-align: center;"         // 文本居中
    //     "   color: #333333;"             // 文本颜色
    //     "}"

    //     "QProgressBar::chunk {"
    //     "   background-color: #4CAF50;"  // 进度条颜色
    //     "   border-radius: 3px;"         // 进度条圆角
    //     "}"
    //     );

    //渐变颜色进度条
    progressBar->setStyleSheet(
        "QProgressBar {"
        "   border: 1px solid #BDBDBD;"
        "   border-radius: 5px;"
        "   background: #EEEEEE;"
        "   text-align: center;"
        "}"

        "QProgressBar::chunk {"
        "   background: qlineargradient("
        "       spread:pad, x1:0, y1:0.5, x2:1, y2:0.5,"
        "       stop:0 #FF5252, stop:1 #FF4081"
        "   );"
        "   border-radius: 4px;"
        "}"
    );


    //组装上、中、下---------------------------------------------------------------------------------
    mainLayout->addWidget(widget1,0, Qt::AlignHCenter);
    mainLayout->addWidget(widget2,1, Qt::AlignHCenter);
    mainLayout->addWidget(widget3,2, Qt::AlignHCenter);
    mainLayout->addItem(verticalSpacer1);
    mainLayout->addStretch();
    connect(startButton, &QPushButton::clicked, this, &StartClassForm::on_startButton_clicked);

    // 获取组件左上角在屏幕中的绝对位置


}
// 开始分班按钮
void StartClassForm::on_startButton_clicked()
{
    // if(int i=0; i < list1.size();++i){}
    QList<Classes> classeLists;
    QMap classStrate = classData.getClassStrate();
    //男女均衡
    if (classStrate.contains("男女均衡")){
        classeLists = sunshineAssignment();
        startAnimation1(classeLists);
        startAnimation2(classeLists);
    }
    //成绩均衡
    else if(classStrate["成绩均衡"]){
        classeLists = balancedAssignmentByScore();
        startAnimation1(classeLists);
        startAnimation2(classeLists);

    }
    //随机分配
    else if(classStrate["随机分配"]){
        classeLists = randomAssignment();
        startAnimation1(classeLists);
        startAnimation2(classeLists);
    }
    //男女+成绩均衡
    else if(classStrate.contains("男女均衡")&&classStrate.contains("成绩均衡")){
        classeLists = AssignmentByScore_Sex();
        startAnimation1(classeLists);
        startAnimation2(classeLists);
    }
    // 分班成功提示框
    // QMessageBox::information(nullptr, "成功", "恭喜分班成功!");

    for (Classes c1: classeLists){
        QString clName = c1.className;

        std::vector<Student> students = c1.students;
        for (Student st: students){
            qreal grade = st.getGrade();
            QString gender = QString::fromStdString(st.getSex());
            qDebug()<< clName<<gender<< grade;
        }
    }
    // 禁用按钮（默认会变灰）
    startButton->setEnabled(false);
    // 导出数据到excel文件1
    exportToExcelWithQXlsx1(classeLists);
    // 导出数据到excel文件2
    exportToExcelWithQXlsx2(classeLists);

    //发送分班结果到classset.cpp的classesResultLists变量
    emit sendClassesResultData(classeLists);

}


// 在这个窗口中显示接收到的数据
void StartClassForm::receiveData(ClassData data){
    classData = data;
    qDebug() << classData.getTitle();
    // 传title的Label过来
    QString titleStr = classData.getTitle();
    label1->setText(titleStr);

    //layout2_1放入信息 传studentlist过来取到学校名称
    list1 = classData.getStudentList();
    Student school = list1[1];
    QString schoolName = QString::fromStdString(school.getSchool());
    QLabel *schoolLabel = new QLabel();
    schoolLabel->setText(schoolName);
    layout2_1->addWidget(schoolLabel);
    // 传student总人数过来
    int numStr = classData.getStudentList().size()-1;
    QString numStr1 = QString::number(numStr);
    QLabel *peopleLabel = new QLabel();
    peopleLabel->setText("总人数: "+numStr1);
    layout2_1->addWidget(peopleLabel);
    // 传分班信息过来
    sunClassList = classData.getSunClassList();
    for (int i=0; i<sunClassList.size();i++) {
        QString numPeople = QString::number(sunClassList[i].totalStu);
        QString className= sunClassList[i].className;


        QLabel *classLabel = new QLabel();
        classLabel->setText(className+": "+numPeople+"人");
        //classLabel->setStyleSheet("font-size: 15pt;color: black;");
        layout2_1->addWidget(classLabel);

        qDebug() <<numPeople << ":" << className;
    }
    // 传分班策略过来
    QLabel *strLabel = new QLabel("分班策略:");
    layout2_1->addWidget(strLabel);
    QMap<QString, int> classStrateMap = classData.getClassStrate();
    for (auto it = classStrateMap.begin(); it != classStrateMap.end(); ++it) {
        QString key2= it.key();
        int value2= it.value();
        QString valueStr2 = QString::number(value2);

        QLabel *strateLabel = new QLabel();
        strateLabel->setText("    "+key2);
        //strateLabel->setStyleSheet("font-size: 15pt;color: black;");
        layout2_1->addWidget(strateLabel);

        qDebug() << it.key() << ":" << it.value();
        // 可以修改值：it.value() = 100;
    }
    // 添加左侧弹簧
    layout2_1->addStretch();
}

// 第一个动画
void StartClassForm::startAnimation1(QList<Classes> classLists){
    int j= 0;

    //创建动画组
    QList<QString> sidLists;//掩码后的身份证号码
    QVector<QLabel *> labels;
    for(auto classes: classLists){
        std::vector<Student>stuVector = classes.students;
        for(auto stu: stuVector){
            //姓名
            std::string name = stu.getName();
            QString qname = QString::fromStdString(name);
            //身份证号掩码
            std::string sId = stu.getId();
            QString qSId = QString::fromStdString(sId);

            if (qSId.length() == 18) {
                // 将第11-14位（出生日期）替换为*
                qSId = qSId.left(10) + "****" + qSId.right(4);
            }
            sidLists.append(qSId);

            //qDebug() << qname<<"----"<<j++;
            //stuNameEdit->setText(qname);
            //创建N个动画
            QLabel *l1 = new QLabel(this);
            l1->setStyleSheet("background-color: rgba(0, 0, 0, 100); color: yellow;");
            //l1->setStyleSheet("background-color: rgba(0, 0, 0, 100); color: yellow;font-size: 10pt;");
            l1->setText(qname);
            l1->setAlignment(Qt::AlignCenter);
            //l1->setGeometry(10, 10, 80, 40);
            l1->setFixedSize(100, 40);  // 宽度200像素，高度100像素
            l1->show();
            labels.append(l1);
        }
    }
    // 创建顺序动画组
    QSequentialAnimationGroup *sequence = new QSequentialAnimationGroup;

    // 为每个QLabel添加动画
    int i = 0;
    for (QLabel *lbl : labels) {
        // 获取组件左上角相对于窗体的坐标
        QPoint p1 = stuNameEdit->mapTo(stuNameEdit->window(), QPoint(0, 0));
        int x1 =  p1.x();
        int y1 =  p1.y();
        //qDebug() << "屏幕坐标(X1,Y1):" << p1.x() << p1.y();
        // 获取组件左上角相对于窗体的坐标
        QPoint p2 = widget2_3->mapTo(widget2_3->window(), QPoint(0, 0));
        int x2 =  p2.x();
        int y2 =  p2.y();
        //qDebug() << "屏幕坐标(X1,Y1):" << p2.x() << p2.y();
        QPropertyAnimation *anim = new QPropertyAnimation(lbl, "pos",this);
        // 设置间隔时间
        anim->setDuration(500);
        // 设置从当前位置开始
        //anim1->setStartValue(stuNameEdit->pos());
        anim->setStartValue(QPoint(x1, y1));
        anim->setEndValue(QPoint(x2, y2));
        QObject::connect(anim, &QPropertyAnimation::finished, [lbl]() {
            lbl->deleteLater();
        });
        QString sid = sidLists[i];
        i = i+1;
        // 连接状态变化信号
        connect(anim, &QPropertyAnimation::stateChanged,
                [lbl,sid, this](QAbstractAnimation::State newState, QAbstractAnimation::State oldState) {
                    if (newState == QAbstractAnimation::Running) {
                        //qDebug() << "动画开始执行";
                        // 在这里执行动画开始时的操作
                        QString sName = lbl->text();
                        stuNameEdit->setText(sName);
                        stuIdEdit->setText(sid);
                    }
                    else if (newState == QAbstractAnimation::Stopped) {
                        //qDebug() << "动画停止";
                    }
                });

        // anim->setEasingCurve(QEasingCurve::InOutQuad);
        sequence->addAnimation(anim);
    }
    // 开始动画
    sequence->start();
}

// 第二个动画
void StartClassForm::startAnimation2(QList<Classes> classLists){
    //滚动条总人数
    int i= 0;
    //创建动画组
    QVector<QLabel*> labels;
    for(auto classes: classLists){
        std::vector<Student> stuVector = classes.students;
        QString className = classes.className;
        for(auto stu: stuVector){
            //startAnimation2("班级( 2 ), 赵丰明, 2604261975985119999");
            std::string name = stu.getName();
            std::string id = stu.getId();
            QString sName = QString::fromStdString(name);
            QString sid = QString::fromStdString(id);

            //身份证号掩码
            if (sid.length() == 18) {
                // 将第11-14位（出生日期）替换为*
                sid = sid.left(10) + "****" + sid.right(4);
            }
            QString str = className+","+sName+","+sid;
            //qDebug() << str<<"----"<<i++;
            //stuNameEdit->setText(qname);
            //创建N个动画
            QLabel *l2 = new QLabel(this);
            //l2->setStyleSheet("background-color: rgba(0, 0, 0, 0);");
            l2->setStyleSheet("background-color: white;");
            l2->setText(str);
            l2->setAlignment(Qt::AlignCenter);
            l2->setAttribute(Qt::WA_TranslucentBackground);  // 关键设置
            l2->setWindowFlags(Qt::FramelessWindowHint);    // 无边框
            // 或者分别设置固定宽度和高度
            l2->setFixedWidth(300);
            l2->setFixedHeight(35);
            // 设置相对字体大小（点）
            //l2->setStyleSheet("font-size: 12pt;");
            l2->show();
            labels.append(l2);
            i++;
        }
    }
    // 创建多个滚动动画
    QList<QPropertyAnimation*> animLists;
    // 为每个QLabel添加动画
    for (QLabel *lbl : labels) {
        // 获取组件左上角相对于窗体的坐标
        QPoint p2 = widget2_3->mapTo(widget2_3->window(), QPoint(0, 0));
        int x2 =  p2.x();
        int y2 =  p2.y();
        //qDebug() << "屏幕坐标(X2,Y2):" << p2.x() << p2.y();

        QPropertyAnimation *anim2 = new QPropertyAnimation(lbl, "pos",this);
        anim2->setDuration(3000);
        anim2->setStartValue(QPoint(x2, y2));
        anim2->setEndValue(QPoint(x2, y2+450));
        anim2->setEasingCurve(QEasingCurve::Linear);
        animLists.append(anim2);

        QObject::connect(anim2, &QPropertyAnimation::finished, [lbl]() {
            lbl->deleteLater();
        });
        //anim2->setEasingCurve(QEasingCurve::InOutQuad);
        // sequence->addAnimation(anim2);
    }
    // 开始动画
    // sequence->start();
    //  设置进度条的范围
    progressBar->setRange(0, i);
    // 使用定时器错开启动
    QTimer *timer = new QTimer(this);
    int currentIndex = 0;
    connect(timer, &QTimer::timeout, [=]() mutable {
        if (currentIndex < animLists.size()) {
            animLists[currentIndex]->start();
            currentIndex++;
            progressBar->setValue(currentIndex);
        } else {
            timer->stop();
        }
    });
    timer->start(500);  // 每个动画间隔500ms启动
}

// 随机分班算法
QList<Classes> StartClassForm::randomAssignment(){
    // 接受到班级信息
    QList<Classes> classes = classData.getSunClassList();
    QList<Student> allStudents = classData.getStudentList();

    // 1. 随机打乱分组
    std::random_shuffle(allStudents.begin(), allStudents.end());

    // 2. 按班级容量从大到小排序（这样可以优先填满大班级）
    std::sort(classes.begin(), classes.end(), [](const Classes& a, const Classes& b) {
        return a.totalStu > b.totalStu;
    });

    // 3. 动态分配学生（改进版）
    for(auto& cls : classes) {
        int remainingCapacity = cls.totalStu;
        // 先分配男生
        while(remainingCapacity > 0 && !allStudents.isEmpty()) {
            //cls.students..append(maleStudents.takeFirst());
            cls.students.push_back(allStudents.takeFirst());
            cls.fMaleCount++;
            remainingCapacity--;
        }
    }
    return classes;
}


// 分班男女均衡算法
QList<Classes> StartClassForm::sunshineAssignment(){

    // 接受到班级信息
    QList<Classes> classes = classData.getSunClassList();
    QList<Student> allStudents = classData.getStudentList();

    //QList<Classes> classes = classInfoList;

    // 1. 按性别分组
    QList<Student> maleStudents;
    QList<Student> femaleStudents;


    for(int i=1;i<allStudents.size();i++) {
        Student stu = allStudents[i];
        std::string sex = stu.getSex();
        if(sex=="男") {
            maleStudents.append(stu);
        } else {
            femaleStudents.append(stu);
        }
    }

    // 2. 随机打乱分组
    std::random_shuffle(maleStudents.begin(), maleStudents.end());
    std::random_shuffle(femaleStudents.begin(), femaleStudents.end());

    // 3. 计算整体男女比例
    double globalMaleRatio = maleStudents.size() / static_cast<double>(allStudents.size());

    // 4. 按班级容量从大到小排序
    std::sort(classes.begin(), classes.end(),[](const Classes& a, const Classes& b) { return a.totalStu > b.totalStu; });

    // 5. 动态分配学生（改进版）
    for(auto& cls : classes) {
        int remainingCapacity = cls.totalStu;
        int targetMale = qRound(globalMaleRatio * cls.totalStu);
        int targetFemale = cls.totalStu - targetMale;

        // 先分配男生
        while(targetMale > 0 && !maleStudents.isEmpty()) {
            //cls.students..append(maleStudents.takeFirst());
            cls.students.push_back(maleStudents.takeFirst());
            cls.fMaleCount++;
            targetMale--;
            remainingCapacity--;
        }

        // 再分配女生
        while(targetFemale > 0 && !femaleStudents.isEmpty()) {
            cls.students.push_back(femaleStudents.takeFirst());
            cls.fFemaleCount++;
            targetFemale--;
            remainingCapacity--;
        }

        // 如果某性别不足，用另一性别补充
        while(remainingCapacity > 0) {
            if(!maleStudents.isEmpty()) {
                cls.students.push_back(maleStudents.takeFirst());
                cls.fMaleCount++;
                remainingCapacity--;
            } else if(!femaleStudents.isEmpty()) {
                cls.students.push_back(femaleStudents.takeFirst());
                cls.fFemaleCount++;
                remainingCapacity--;
            } else {
                break; // 没有学生可分配了
            }
        }
    }
    return classes;
}

//分班成绩均衡算法
QList<Classes> StartClassForm::balancedAssignmentByScore() {
    // 获取班级信息和学生列表
    QList<Classes> classes = classData.getSunClassList();
    QList<Student> allStudents = classData.getStudentList();

    // 1. 按学生成绩从高到低排序
    std::sort(allStudents.begin(), allStudents.end(), []( Student& a, Student& b) {
        return a.getGrade() > b.getGrade(); // 假设Student类有getGrade()方法

    });

    // 2. 按班级容量从大到小排序
    std::sort(classes.begin(), classes.end(), [](const Classes& a, const Classes& b) {
        return a.totalStu > b.totalStu;
    });

    // 3. 蛇形分配学生（确保成绩均衡）
    bool forwardDirection = true; // 分配方向标志
    int classIndex = 0;

    for (const Student& student : allStudents) {
        // 将学生分配到当前班级
        classes[classIndex].students.push_back(student);

        // 更新班级索引（蛇形分配）
        if (forwardDirection) {
            classIndex++;
            if (classIndex >= classes.size()) {
                classIndex = classes.size() - 1;
                forwardDirection = false;
            }
        } else {
            classIndex--;
            if (classIndex < 0) {
                classIndex = 0;
                forwardDirection = true;
            }
        }
    }

    return classes;
}

//阳光分班男女+成绩均衡算法
QList<Classes> StartClassForm::AssignmentByScore_Sex() {
    // 接收到班级信息
    QList<Classes> classes = classData.getSunClassList();
    QList<Student> allStudents = classData.getStudentList();

    //QList<Classes> classes = classInfoList;

    // 1. 按学生成绩从高到低排序
    std::sort(allStudents.begin(), allStudents.end(), []( Student& a, Student& b) {
        return a.getGrade() > b.getGrade(); // 假设Student类有getGrade()方法

    });

    // 2. 按性别分组,放入student封装
    QList<Student> maleStudents;
    QList<Student> femaleStudents;


    for(int i=1;i<allStudents.size();i++) {
        Student stu = allStudents[i];
        std::string sex = stu.getSex();
        if(sex=="男") {
            maleStudents.append(stu);
        } else {
            femaleStudents.append(stu);
        }
    }

    // 3. 计算整体男女比例
    double globalMaleRatio = maleStudents.size() / static_cast<double>(allStudents.size());

    // 4. 按班级容量从大到小排序
    std::sort(classes.begin(), classes.end(),[](const Classes& a, const Classes& b) { return a.totalStu > b.totalStu; });

    // 5. 动态分配学生（改进版）
    // 6. 蛇形分配
    bool forwardDirection = true;
    int classIndex = 0;

    // 分配男生
    for (int i = 0; i < maleStudents.size(); ) {
        int targetMale = qRound(globalMaleRatio * classes[classIndex].totalStu);

        while (i < maleStudents.size() && classes[classIndex].students.size() < targetMale && classes[classIndex].students.size() < classes[classIndex].totalStu) {
            classes[classIndex].students.push_back(maleStudents[i]);
            classes[classIndex].fMaleCount++;
            classes[classIndex].totalScore += maleStudents[i].getGrade();
            i++;
        }

        // 更新班级索引（蛇形）
        if (forwardDirection) {
            classIndex++;
            if (classIndex >= classes.size()) {
                classIndex = classes.size() - 1;
                forwardDirection = false;
            }
        } else {
            classIndex--;
            if (classIndex < 0) {
                classIndex = 0;
                forwardDirection = true;
            }
        }
    }

    // 重置方向，分配女生
    forwardDirection = true;
    classIndex = 0;

    for (int i = 0; i < femaleStudents.size(); ) {
        int remainingCapacity = classes[classIndex].totalStu - classes[classIndex].students.size();

        while (i < femaleStudents.size() && remainingCapacity > 0) {
            classes[classIndex].students.push_back(femaleStudents[i]);
            classes[classIndex].fFemaleCount++;
            classes[classIndex].totalScore += femaleStudents[i].getGrade();
            i++;
            remainingCapacity--;
        }

        // 更新班级索引（蛇形）
        if (forwardDirection) {
            classIndex++;
            if (classIndex >= classes.size()) {
                classIndex = classes.size() - 1;
                forwardDirection = false;
            }
        } else {
            classIndex--;
            if (classIndex < 0) {
                classIndex = 0;
                forwardDirection = true;
            }
        }
    }

    return classes;
}

// 导出数据到excel表格1(无掩码）
void StartClassForm::exportToExcelWithQXlsx1(const QList<Classes>& classes) {
    QXlsx::Document xlsx;

    // 设置表头格式
    // QXlsx::Format headerFormat;
    // headerFormat.setFontBold(true);
    // headerFormat.setFontSize(14);
    //headerFormat.setPatternBackgroundColor(Qt::yellow);

    // 写入表头
    xlsx.write(1, 1, "班级ID");
    xlsx.write(1, 2, "班级名称");
    xlsx.write(1, 3, "学生姓名");
    xlsx.write(1, 4, "性别");
    xlsx.write(1, 5, "身份证号码");
    xlsx.write(1, 6, "成绩");
    xlsx.write(1, 7, "备注");


    // 填充数据
    int row = 2;
    for(const Classes& cls : classes) {
        // 直接遍历 Student 对象
        for(const Student& stu : cls.students) {
            xlsx.write(row, 1, cls.classId);
            xlsx.write(row, 2, cls.className);
            xlsx.write(row, 3, QString::fromStdString(stu.getName()));
            xlsx.write(row, 4, QString::fromStdString(stu.getSex()));
            xlsx.write(row, 5, QString::fromStdString(stu.getId()));
            xlsx.write(row, 6, stu.getGrade());
            xlsx.write(row, 7, QString::fromStdString(stu.getNotes()));
            row++;
        }
    }

    // 自动调整列宽
    for(int col = 1; col <= 5; ++col) {
        xlsx.setColumnWidth(col, 15);
    }

    // 保存文件
    QString currentPath = "D:/qtpro/classsystem";
    //获取当前工作目录
    //QString currentPath = QDir::currentPath();
    //qDebug() << "currentPath1:" << QDir::currentPath();
    //qDebug() << "currentPath:" << currentPath;
    QString subDir = "exportFile";
    QString timestamp = QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss");
    // 生成excel文件名
    QString fileName  = QString("f1_%1.xlsx").arg(timestamp);
    //获取当前时间并格式化为字符串（例如：20231120_153045）
    QString filePath = QString("%1/%2/%3").arg(currentPath).arg(subDir).arg(fileName);

    //qDebug() << "filePath:" << filePath;

    if (!filePath.endsWith(".xlsx")) {
        filePath += ".xlsx";
    }
    if(!filePath.isEmpty()) {
        if(xlsx.saveAs(filePath)) {
            qDebug() << filePath<<"成功,Excel文件(1)保存成功!";
            //QMessageBox::information(nullptr, "成功", "Excel文件(1)保存成功!");
        } else {
            qDebug() << filePath<<"错误,保存Excel(1)文件失败!";
            //QMessageBox::warning(nullptr, "错误", "保存Excel(1)文件失败!");
        }
    }
}

// 导出数据到excel表格2(掩码）
void StartClassForm::exportToExcelWithQXlsx2(const QList<Classes>& classes) {
    QXlsx::Document xlsx;

    // 设置表头格式
    // QXlsx::Format headerFormat;
    // headerFormat.setFontBold(true);
    // headerFormat.setFontSize(14);
    // headerFormat.setPatternBackgroundColor(Qt::yellow);

    // 写入表头
    xlsx.write(1, 1, "班级名称");
    xlsx.write(1, 2, "学生姓名");
    xlsx.write(1, 3, "性别");
    xlsx.write(1, 4, "身份证号码");

    // 填充数据
    int row = 2;
    for(const Classes& cls : classes) {
        // 直接遍历 Student 对象
        for(const Student& stu : cls.students) {
            xlsx.write(row, 1, cls.className);
            xlsx.write(row, 2, QString::fromStdString(stu.getName()));
            xlsx.write(row, 3, QString::fromStdString(stu.getSex()));
            QString id = QString::fromStdString(stu.getId());
            if (id.length() == 18) { //身份证号掩码
                // 将第11-14位（出生日期）替换为*
                id = id.left(10) + "****" + id.right(4);
            }
            xlsx.write(row, 4, id);
            row++;
        }
    }

    // 自动调整列宽
    for(int col = 1; col <= 5; ++col) {
        xlsx.setColumnWidth(col, 15);
    }

    // 保存文件
    QString currentPath = "D:/qtpro/classsystem";
    //获取当前工作目录
    //QString currentPath = QDir::currentPath();
    qDebug() << "currentPath1:" << QDir::currentPath();
    qDebug() << "currentPath:" << currentPath;
    QString subDir = "exportFile";
    QString timestamp = QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss");
    // 生成excel文件名
    QString fileName  = QString("f2_%1.xlsx").arg(timestamp);
    //获取当前时间并格式化为字符串（例如：20231120_153045）
    QString filePath = QString("%1/%2/%3").arg(currentPath).arg(subDir).arg(fileName);

    qDebug() << "filePath:" << filePath;

    if (!filePath.endsWith(".xlsx")) {
        filePath += ".xlsx";
    }
    if(!filePath.isEmpty()) {
        if(xlsx.saveAs(filePath)) {
            qDebug() << filePath<<"成功,Excel文件(2)保存成功!";
            //QMessageBox::information(nullptr, "成功", "Excel文件(2)保存成功!");
        } else {
            qDebug() << filePath<<"错误,保存Excel(2)文件失败!";
            //QMessageBox::warning(nullptr, "错误", "保存Excel(2)文件失败!");
        }
    }
    // 生成excel文件名
    QString fileName_pdf  = QString("title_%1.pdf").arg(timestamp);
    //获取当前时间并格式化为字符串（例如：20231120_153045）
    QString filePath_pdf = QString("%1/%2/%3").arg(currentPath).arg(subDir).arg(fileName_pdf);
    // 调用excel转Pdf函数
    // exportToPdf(filePath,filePath_pdf);

}
// excel转Pdf(掩码）
// void StartClassForm::exportToPdf(const QString& excelPath, const QString& pdfPath) {
//     // 1. 加载Excel文件
//     QXlsx::Document xlsx(excelPath);
//     if (!xlsx.load()) {
//         qWarning("无法加载Excel文件");
//         //return false;
//     }

//     // 2. 设置PDF打印机
//     QPrinter printer(QPrinter::HighResolution);
//     printer.setOutputFormat(QPrinter::PdfFormat);
//     printer.setOutputFileName(pdfPath);

//     // 3. 创建绘制器
//     QPainter painter(&printer);
//     if (!painter.isActive()) {
//         qWarning("无法创建PDF文件");
//         //return false;
//     }

//     // 4. 获取当前工作表
//     QXlsx::Worksheet* sheet = dynamic_cast<QXlsx::Worksheet*>(xlsx.currentWorksheet());
//     if (!sheet) {
//         qWarning("无法获取工作表");
//         //return false;
//     }

//     // 5. 设置基本绘制参数
//     const int margin = 40;          // 页边距
//     const int rowHeight = 25;       // 行高
//     const int colWidth = 80;        // 列宽
//     int yPos = margin;              // 当前Y位置

//     // 6. 获取数据范围
//     QXlsx::CellRange range = sheet->dimension();

//     // 7. 绘制表格内容
//     for (int row = 1; row <= range.lastRow(); ++row) {
//         int xPos = margin; // 每行开始时重置X位置

//         for (int col = 1; col <= range.lastColumn(); ++col) {
//             auto cell = sheet->cellAt(row, col);  // 使用 auto 接收智能指针
//             if (cell) {
//                 // 绘制单元格文本
//                 painter.drawText(
//                     xPos, yPos, colWidth, rowHeight,
//                     Qt::AlignLeft | Qt::AlignVCenter,
//                     cell->value().toString()
//                     );
//                 // 绘制单元格边框
//                 painter.drawRect(xPos, yPos - rowHeight + 5, colWidth, rowHeight);
//             }
//             xPos += colWidth;
//         }

//         yPos += rowHeight;

//         // 分页检查
//         // if (yPos > printer.pageRect().height() - margin && row < range.lastRow()) {
//         //     printer.newPage();  // 或使用 printer.newPage(QPrinter::A4);
//         //     yPos = margin;
//         // }
//     }

// }
// 打开pdf文件
// void StartClassForm::openPdf(const QString filePath) {

//     QString currentPath = "file:///D:/qpro/pdftest";
//     //获取当前工作目录
//     //QString currentPath = QDir::currentPath();
//     qDebug() << "currentPath:" << currentPath;
//     QString subDir = "exportFile";
//     QString file = "aa.pdf";
//     QString path = QString("%1/%2/%3").arg(currentPath).arg(subDir).arg(file);

//     qDebug() << "访问pdf文件路径:" << path;
//     //调用第三方软件打开aa.pdf文件
//     QDesktopServices::openUrl(QUrl(path));
//     //QDesktopServices::openUrl(QUrl("file:///D:/qpro/pdftest/aa.pdf"));
// }
// 音乐播放
void StartClassForm::onMusicToggle(){
    if (musicBox->isChecked()) {
        player->play();
        qDebug() << "Music started playing";
    } else {
        player->stop();
        qDebug() << "Music stopped";
    }
}


StartClassForm::~StartClassForm()
{
    delete ui;
}
