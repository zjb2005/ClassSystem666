#include "classset.h"
#include "classdata.h"
#include "classnumbersetform.h"
#include "startclassform.h"
#include "ui_classset.h"
#include "student.h"
#include "xlsxdocument.h"
#include "printerclassesresult.h"
#include "printapi.h"
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QGroupBox>
#include <QTableView>
#include <QStandardItemModel>
#include <QLine>
#include <QListView>
#include <QStringListModel>
#include <QFileDialog>
#include <iostream>
#include <qmessagebox.h>
#include <QHeaderView>
#include <iostream>
#include <cmath>  // 用于ceil函数
#include <QTableWidgetItem>

ClassSet::ClassSet(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClassSet)
{
    ui->setupUi(this);


    // 创建主窗口
    // QWidget window;
    // window.setWindowTitle("垂直布局示例");
    //第一个layout内容
    // 创建Label（默认左对齐）
    label1 = new QLabel();
    label1->setStyleSheet("font-size: 50px; font-weight: bold;");
    //设留水平和垂直部恩中
    label1->setFixedHeight(150);
    label1->setAlignment(Qt::AlignCenter);
    // 添加按钮到布局中
    QPushButton *button1 = new QPushButton("开始分班");
    // 设置悬停/按下状态的颜色
    button1->setStyleSheet(
        "QPushButton { background-color: #4169E1; color: white;font-size: 50px; }"
        "QPushButton:hover { background-color: #45a049; }"
        "QPushButton:pressed { background-color: #FF0000; }"
        );


    // 创建horizontal布局
    QHBoxLayout *l1 = new QHBoxLayout;
    l1->addWidget(label1,3);
    l1->addWidget(button1,1);
    // 添加horizontal间距
    l1->addSpacing(20);



    // 第二个layout 添加分隔线
    // 创建水平线 (QFrame)
    QFrame *line1 = new QFrame();
    line1->setFrameShape(QFrame::HLine);  // 水平线
    line1->setFrameShadow(QFrame::Sunken); // 可选：使线条有凹陷效果

    QHBoxLayout *l2 = new QHBoxLayout;
    l2 ->addWidget(line1);

    //第三个layout
    // 搜索栏水平布局（嵌套在horizontal布局中）
    QHBoxLayout *l3 = new QHBoxLayout;
    l3_edit1 = new QLineEdit();
    l3_edit1->setPlaceholderText("请输入姓名/身份证号");
    l3_edit1->setMaxLength(18);
    //l3_edit1->setFixedSize(350, 50);  // 宽度 200px，高度 30px
    l3_edit1->setStyleSheet("font-size: 20px;");
    QPushButton *l3_b1 = new QPushButton("搜  索");
    QPushButton *l3_b2 = new QPushButton("导入名单");
    QPushButton *l3_b3 = new QPushButton("清空数据");
    QPushButton *l3_b4 = new QPushButton("打印结果");
    l3_b1->setStyleSheet("font-size: 20px;background-color: #4169E1; color: white;");
    //l3_b1->setFixedSize(120,50);
    l3_b2->setStyleSheet("font-size: 20px;background-color: #4169E1; color: white;");
    //l3_b2->setFixedSize(120,50);
    l3_b3->setStyleSheet("font-size: 20px;background-color: #4169E1; color: white;");
    //l3_b3->setFixedSize(120,50);
    l3_b4->setStyleSheet("font-size: 20px;background-color: #4169E1; color: white;");


    l3->addWidget(l3_edit1,6);
    l3->addWidget(l3_b1,1);
    l3->addWidget(l3_b2,2);
    l3->addWidget(l3_b3,2);
    l3->addWidget(l3_b4,2);
    // 添加分隔线
    // 第四个layout 添加分隔线
    // 创建水平线 (QFrame)
    QFrame *line2 = new QFrame();
    line2->setFrameShape(QFrame::HLine);  // 水平线
    line2->setFrameShadow(QFrame::Sunken); // 可选：使线条有凹陷效果

    QHBoxLayout *l4 = new QHBoxLayout;
    l4 ->addWidget(line2);

    //第五个layout
    // 创建 TableView 和 Model
    tableView1 = new QTableView;
    model1 = new QStandardItemModel();
    model1->setHorizontalHeaderLabels({"学校名称", "姓名", "性别", "身份证号码", "总成绩", "备注"});
    tableView1->horizontalHeader()->setStyleSheet("font-size: 16px; font-weight: bold;");
    tableView1->setModel(model1);
    // 或者让所有列平均拉伸
    tableView1->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // tableView1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    // 可选：调整列宽自适应内容
    tableView1->resizeColumnsToContents();
    //启用/禁用编辑，不可编辑
    tableView1->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableView1->show();

    // 班级信息分组
    QGroupBox *classInfoGroup = new QGroupBox("班级信息：");
    classInfoGroup->setStyleSheet("font-size: 16px;");
    tableView2 = new QTableView();   // 创建列表视图
    // 设置表格为多选模式
    tableView2->setSelectionMode(QAbstractItemView::MultiSelection);
    tableView2->setSelectionBehavior(QAbstractItemView::SelectRows);
    // 使用 QStringListModel 添加数据
    model2 = new QStandardItemModel();
    model2->setHorizontalHeaderLabels({"班级","人数"});
    tableView2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 启用拖拽功能
    tableView2->setDragEnabled(true);
    // 设置拖放模式
    //tableView2->setDragDropMode(QAbstractItemView::DragOnly);  // 只允许拖出
    // 或者
    //tableView2->setDragDropMode(QAbstractItemView::DragDrop);  // 允许拖出和放入

    tableView2->setModel(model2);



    QVBoxLayout *view1 = new QVBoxLayout();   // 使用垂直布局
    view1->addWidget(tableView2);              // 将列表视图添加到布局
    classInfoGroup->setLayout(view1);          // 将布局设置给分组框
    // 班级设置按钮
    QPushButton *classSettingbtn = new QPushButton("添加班级");
    QPushButton *deletebtn1 = new QPushButton("删除");
    classSettingbtn->setStyleSheet("font-size: 16px;background-color: #4169E1; color: white;");
    deletebtn1->setStyleSheet("font-size: 16px;background-color: #4169E1; color: white;");

    QHBoxLayout *l_1 = new QHBoxLayout;
    l_1 -> addWidget(classSettingbtn);
    l_1 -> addWidget(deletebtn1);
    // 分班策略分组
    // QGroupBox *classstrategy = new QGroupBox("分班策略：");
    /*QListView *listView2 = new QListView(); */  // 创建列表视图
    QVBoxLayout *view2 = new QVBoxLayout();   // 使用垂直布局
    /*view2->addWidget(listView2);      */        // 将列表视图添加到布局
    /*classstrategy->setLayout(view2);       */   // 将布局设置给分组框
    // 标题
    QLabel *title = new QLabel("分班策略");
    title->setStyleSheet("font-size: 16px; font-weight: bold;");
    view2->addWidget(title);

    // 复选框选项
    genderBalance = new QCheckBox("男女均衡");
    // nameBalance = new QCheckBox("姓氏均衡");
    scoreBalance = new QCheckBox("成绩均衡");
    randomAssign = new QCheckBox("随机分配");
    genderBalance->setStyleSheet("font-size: 16px");
    // nameBalance->setStyleSheet("font-size: 16px");
    scoreBalance->setStyleSheet("font-size: 16px");
    randomAssign->setStyleSheet("font-size: 16px");



    // 将复选框添加到布局
    view2->addWidget(genderBalance);
    // view2->addWidget(nameBalance);
    view2->addWidget(scoreBalance);
    view2->addWidget(randomAssign);
    // 添加伸缩空间使布局更美观
    view2->addStretch();

    // QVBoxLayout *classstrategy = new QVBoxLayout(classstrategy);
    // 分班策略按钮
    QPushButton *strategybtn = new QPushButton("策略设置");
    QPushButton *deletebtn2 = new QPushButton("删除");

    QHBoxLayout *l_2 = new QHBoxLayout;
    l_2 -> addWidget(strategybtn);
    l_2 -> addWidget(deletebtn2);
    // 创建垂直布局
    QVBoxLayout *l5_1 = new QVBoxLayout;
    l5_1->addWidget(classInfoGroup);
    l5_1->addLayout(l_1);
    l5_1->addLayout(view2);
    // l5_1->addLayout(l_2);

    //第五个layout
    QHBoxLayout *l5 = new QHBoxLayout;
    l5 ->addWidget(tableView1);
    l5 ->addLayout(l5_1);
    l5->setStretch(0, 3);  // leftWidget
    l5->setStretch(1, 1);  // rightWidget

    //第六个layout
    // 人数显示
    QHBoxLayout *l6 = new QHBoxLayout;
    QLabel *countLabel = new QLabel("总人数: ");
    //QString numberStu2 = QString::number(studentList.size());
    numberLabel = new QLabel("0");
    countLabel->setAlignment(Qt::AlignCenter);
    // numberLabel->setAlignment(Qt::AlignCenter);
    numberLabel->setStyleSheet("font-weight: bold;");
    // 添加左侧弹簧
    l6->addStretch();
    l6->addWidget(countLabel);
    l6->addWidget(numberLabel);
    l6->addStretch(); // 右对齐
    // 设置主布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(l1,3);
    mainLayout->addLayout(l2,1);
    mainLayout->addLayout(l3,2);
    mainLayout->addLayout(l4,1);
    mainLayout->addLayout(l5,6);
    mainLayout->addLayout(l6,1);
    this->setLayout(mainLayout);
    this->setWindowTitle("阳光新生分班系统"); // 设置窗口标题
    this->resize(1000, 700);

    // 连接信号和槽,绑定按钮
    connect(button1, &QPushButton::clicked, this, &ClassSet::on_beginButton_clicked);
    connect(l3_b1, &QPushButton::clicked, this, &ClassSet::on_searchButton_clicked);
    connect(l3_b2, &QPushButton::clicked, this, &ClassSet::on_pushB1_clicked);
    connect(l3_b3, &QPushButton::clicked, this, &ClassSet::on_clearButton_clicked);
    connect(l3_b4, &QPushButton::clicked, this, &ClassSet::on_printerClassesResultButton_clicked);
    connect(classSettingbtn, &QPushButton::clicked, this, &ClassSet::on_classSettingbtn_clicked);
    connect(deletebtn1, &QPushButton::clicked, this, &ClassSet::on_deleteBtn_clicked);
    // 三个复选框
    connect(genderBalance, &QCheckBox::checkStateChanged, this, &ClassSet::updateCheckBoxStates);
    connect(scoreBalance, &QCheckBox::checkStateChanged, this, &ClassSet::updateCheckBoxStates);
    connect(randomAssign, &QCheckBox::checkStateChanged, this, &ClassSet::updateCheckBoxStates);


}

// 传输title数据过来
void ClassSet::setData(const QString &titleText){
    //titleData是子窗体的成员变量
    this->titleData = titleText;
    label1->setText(titleData);

}
// 复选框槽函数，三选二限制
void ClassSet::updateCheckBoxStates()
{
    // 情况 1：如果 "随机" 被选中，强制取消 "成绩" 和 "性别" 并禁用
    if (randomAssign->isChecked()) {
        scoreBalance->setChecked(false);
        genderBalance->setChecked(false);
        scoreBalance->setEnabled(false);
        genderBalance->setEnabled(false);
    }
    // 情况 2：如果 "成绩" 或 "性别" 被选中（或同时选中两者），禁用 "随机"
    else if (scoreBalance->isChecked() || genderBalance->isChecked()) {
        randomAssign->setChecked(false);
        randomAssign->setEnabled(false);
    }
    // 情况 3：如果全部取消选中，恢复所有可点击
    else {
        scoreBalance->setEnabled(true);
        genderBalance->setEnabled(true);
        randomAssign->setEnabled(true);
    }
}

//开始按钮
void ClassSet::on_beginButton_clicked(){
    // QMessageBox::information(this, "提示", "按钮被点击，即将进入导入");
    //学生名单 QList<Student> studentList;

    //班级信息处理，读班级信息
    QList<Classes> sunClassList;
    // 读取tableview2数据, 按列读取
    int rowCount = model2->rowCount();
    //设置班级的总人数
    int cNum = 0;
    // 读班级信息，tableview2数据
    if (model2) {
        // 读取所有行和列的数据
        for (int i = 0;i<rowCount; i++) {
            QString data0 = "";
            QString data1 = "";
            //总班级数量
            QStandardItem *item0 = model2->item(i,0);
            if(item0){
                data0 = item0->text();
            }
            //班级人数
            QStandardItem *item1 = model2->item(i,1);
            int data1Num = 0;
            if(item1){
                data1 = item1->text();

                data1Num = data1.toInt();
                cNum = cNum + data1Num;
            }
            //将数据加入Classes结构体
            Classes cl;
            cl.classId = i+1;
            cl.className = data0;
            cl.totalStu = data1Num;
            // 往sunClassList添加结构体数据
            sunClassList.append(cl);
        }
    }
    //班级数不能少于2个
    int num1 = sunClassList.size();
    if (num1 <=1 ){
        QMessageBox::information(this, "提示", "班级数量必须最少为2！");
        return;
    }
    //分班人数需要与总人数一致
    int totalNum = studentList.size()-1;
    if (totalNum != cNum ){
        QMessageBox::information(this, "提示", "班级分配人数与总人数不一致！");
        return;
    }


    //分班策略
    QMap<QString, int> strateMap;
    if(genderBalance->isChecked())strateMap.insert("男女均衡", 1);
    // if(nameBalance->isChecked()) strateMap.insert("姓氏均衡", 2);
    if(scoreBalance->isChecked()) strateMap.insert("成绩均衡", 2);
    if(randomAssign->isChecked()) strateMap.insert("随机分配", 3);

    int num2 = strateMap.size();
    if (num2 == 0){
        QMessageBox::information(this, "提示", "请选择分班策略！");
        return;
    }
    // 导入数据进ClassData封装类
    ClassData classdata;
    classdata.setStudentList(studentList);
    classdata.setSunClassList(sunClassList);
    classdata.setClassStrate(strateMap);
    classdata.setTitle(titleData);

    // new创建子窗口
    StartClassForm *child = new StartClassForm();
    child->show();
    // 连接信号和槽
    connect(this, &ClassSet::sendData, child, &StartClassForm::receiveData);
    qDebug() << "data1:" ;
    // 获取封装类对象内容并发送信号
    emit sendData(classdata);
    // 断开sender和receiver之间的所有连接
    //disconnect(this, nullptr, child, nullptr);

    //连接子窗口的信号到父窗口的槽,接收分班后的结果
    connect(child, &StartClassForm::sendClassesResultData, this, &ClassSet::receiveClassesResultData);
}
//接收startclassform.cpp分班后的结果
void ClassSet::receiveClassesResultData(QList<Classes> resultLists){
    classesResultLists = resultLists;
}

//学生信息查询
void ClassSet::on_searchButton_clicked()
{
    // 保存查询到的数据
    QList<Student> sList;
    QString searchText = l3_edit1->text().trimmed();  // 假设你的LineEdit对象名为lineEdit
    std::string sText = searchText.toStdString();
    // 没有输入查询数据,显示所有数据
    if (sText.empty()) {
        //遍历学生名单
        for(int i =1;i<studentList.size();i++){
            Student stu = studentList[i];
            sList.append(stu);
        }
    }else{//已经输入查询数据
        //遍历学生名单
        for(int i =0;i<studentList.size();i++){
            Student stu = studentList[i];
            //取姓名
            std::string name = stu.getName();
            //取身份证号
            std::string sId = stu.getId();
            if ((sText ==name) ||(sText ==sId)){
                sList.append(stu);
            }
        }
    }
    //清空数据
    model1->removeRows(0, model1->rowCount());
    // 提示没有数据
    if (sList.size() == 0){
        QMessageBox::information(this, "提示", "没有数据");
        Student noStu;
        noStu.setSchool("无");
        noStu.setName("无");
        noStu.setSex("无");
        noStu.setId("无");
        noStu.setGrade(0);
        noStu.setNotes("无");
        sList.append(noStu);
    }
    // 显示数据
    for (int i = 0; i < sList.size(); ++i) {
        // 第一列：学校
        model1->setItem(i, 0, new QStandardItem(QString::fromStdString(sList[i].getSchool())));
        // 第二列：姓名
        model1->setItem(i, 1, new QStandardItem(QString::fromStdString(sList[i].getName())));
        // 第三列：性别
        model1->setItem(i, 2, new QStandardItem(QString::fromStdString(sList[i].getSex())));
        // 第四列：身份证号码
        model1->setItem(i, 3, new QStandardItem(QString::fromStdString(sList[i].getId())));
        // 第五列：总成绩
        model1->setItem(i, 4, new QStandardItem(sList[i].getGrade()));
        // 第六列：备注
        model1->setItem(i, 5, new QStandardItem(QString::fromStdString(sList[i].getNotes())));
    }
}
//清空数据
void ClassSet::on_clearButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "确认", "确定要删除数据吗?",QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        // 用户点击了"是"
        // 清除所有学生数据但保留表头
        studentList.clear();
        model1->removeRows(0, model1->rowCount());
        model2->removeRows(0, model2->rowCount());
        //清空班级数据

    } else {
        // 用户点击了"否"
        return;
    }
}
//导入名单
void ClassSet::on_pushB1_clicked()
{

    // QMessageBox::information(this, "提示", "按钮被点击，即将进入导入");
    //QString curPath = QDir::currentPath();
    // 打开文件选择对话框
    QString fileName = QFileDialog::getOpenFileName(nullptr, tr("请选择一个导入.xlsx文件"),"D:\\qtpro\\classsystem",tr("Excel 文件 (*.xlsx)"));
    std::cout << fileName.toStdString() << std::endl;

    if (fileName.isEmpty()){
        return;
    }
    // 第一步：定义xlsw
    QXlsx::Document xlsxR(fileName);
    //QXlsx::Document xlsxR("D:/cpro/untitled/xlsdir/Test.xlsx");

    // 第二步：加载
    if (xlsxR.load()) // load excel file
    {
        xlsxR.selectSheet(xlsxR.sheetNames()[0]);
        QXlsx::CellRange range = xlsxR.dimension();

        // 删除之前list中数据
        studentList.clear();
        // 第三步：遍历，获取数据
        // 取列的数据
        for(int j =1;j<= range.rowCount();++j)
        {
            Student student;
            //QList<QString> rowData;
            // 取每行数据
            for(int i =1;i<= range.columnCount();i++)
            {
                // 遍历行和列，拿到数据 ：xlsxR.cellAt(i,j)->value().toInt()
                // qDebug()<< xlsxR.cellAt(j,i)->value().toString();
                //qDebug()<< i;
                if(xlsxR.cellAt(j,i))
                {
                    // 遍历行和列，拿到数据 ：xlsxR.cellAt(i,j)->value().toInt()
                    // qDebug()<< xlsxR.cellAt(j,i)->value().toString();

                    QString sdata = xlsxR.cellAt(j,i)->value().toString().trimmed();
                    // qDebug()<<sdata;
                    if (i == 1){
                        student.setSchool(sdata.toStdString());
                    }
                    if (i == 2){
                        student.setName(sdata.toStdString());
                    }
                    if (i == 3){
                        student.setSex(sdata.toStdString());
                    }
                    if (i == 4){
                        std::string strId = sdata.toStdString();
                        student.setId(strId);
                    }
                    if (i == 5){
                        student.setGrade(sdata.toDouble());
                    }
                    if (i == 6){
                        student.setNotes(sdata.toStdString());
                    }
                }
            }
            studentList.append(student);
            QString numberStu2 = QString::number(studentList.size()-1);
            numberLabel->setText(numberStu2);

        }
    } else {
        qDebug() << "打开文件失败";
        return;
    }

    // for(int i =0;i<studentList.size();i++){
    //     Student stu = studentList[i];
    //     qDebug() << QString::fromStdString(stu.getSchool())<< QString::fromStdString(stu.getName())<<QString::fromStdString(stu.getSex())<< QString::fromStdString(stu.getId()) << QString::fromStdString(stu.getGrade()) << QString::fromStdString(stu.getNotes());
    //     //qDebug() << QString::fromStdString(stu.getSex());
    //     //qDebug() << stu.getId();
    //     // qDebug() << stu.getGrade();
    //     // qDebug() << stu.getAge();
    // }
    //清空原来显示数据
    model1->removeRows(0, model1->rowCount()); // 清除所有学生数据但保留表头
    model2->removeRows(0, model2->rowCount()); //清空班级数据

    // 创建模型
    // 填充数据
    for (int i = 1; i < studentList.size(); ++i) {
        // 第一列：学校
        model1->setItem(i-1, 0, new QStandardItem(QString::fromStdString(studentList[i].getSchool())));
        // 第二列：姓名
        model1->setItem(i-1, 1, new QStandardItem(QString::fromStdString(studentList[i].getName())));
        // 第三列：性别
        model1->setItem(i-1, 2, new QStandardItem(QString::fromStdString(studentList[i].getSex())));
        // 第四列：身份证号码
        model1->setItem(i-1, 3, new QStandardItem(QString::fromStdString(studentList[i].getId())));
        // 第五列：总成绩
        model1->setItem(i-1, 4, new QStandardItem(QString::number(studentList[i].getGrade())));
        // 第六列：备注
        model1->setItem(i-1, 5, new QStandardItem(QString::fromStdString(studentList[i].getNotes())));
    }
    //学生人数
    int rowNum = studentList.size()-1;
    // 不能少于50人
    if (rowNum <= 50){
        return;
    }
    //班级数
    int numClasses = this->calculateClasses(rowNum);
    //每个班级人数
    QVector vClassCount = this->printDistribution(rowNum,numClasses);

    for (int i = 0; i < vClassCount.size(); i++) {
        // str1:班级数量
        QString str1 = QString("班级( %1 )").arg(i+1);
        model2->setItem(i, 0, new QStandardItem(str1));
        // str2:每个班级人数
        QString str2 = QString::number(vClassCount[i]);
        model2->setItem(i, 1, new QStandardItem(str2));
    }

    //qDebug() << vClassCount;

}
//打印结果按钮
void ClassSet::on_printerClassesResultButton_clicked(){

    QString type = "阳光分班结果";

    QList<QString> columnNames;
    columnNames.append("序号");
    columnNames.append("班级名称");
    columnNames.append("姓名");
    columnNames.append("性别");
    columnNames.append("身份证号码");
    columnNames.append("学校名称");
    // columnNames.append("备注");

    QList<int> columnWidths;
    columnWidths.append(50);//序号
    columnWidths.append(80);//班级名称
    columnWidths.append(80);//姓名
    columnWidths.append(50);//性别
    columnWidths.append(170);//身份证号码
    columnWidths.append(170);//学校名称
    // columnWidths.append(50);//备注

    QStringList content;

    // 填充数据
    //num序号
    int num = 1;
    for (Classes cl: classesResultLists){
        QString clName = cl.className;
        std::vector<Student> students = cl.students;

        for (int i = 0; i < students.size(); i++) {
            // 添加一行数据    // content.append("1;班级(1);赵丰明;360426********4210;1");
            //序号
            QString strNum = QString::number(num);
            // 第一列：班级名称
            // 第二列：姓名
            QString name = QString::fromStdString(students[i].getName());
            // 第三列：性别
            QString sex  = QString::fromStdString(students[i].getSex());
            //第四列：身份证号码,身份证号掩码
            std::string sId = students[i].getId();
            QString qSId = QString::fromStdString(sId);
            if (qSId.length() >= 12) {
                // 将第11-14位（出生日期）替换为*
                qSId = qSId.left(6) + "****" + qSId.right(4);
            }
            // 第五列：学校名称
            QString school = QString::fromStdString(students[i].getSchool());
            // 第六列：备注
            QString notes = QString::fromStdString(students[i].getNotes());
            content.append(strNum+";"+clName+";"+name+";"+sex+";"+qSId+";"+school);
            //content.append(strNum+";"+clName+";"+name+";"+sex+";"+qSId);
            num = num+1;
        }
    }

    //content.append("1;班级(1);赵丰明;男;360426********4210;南昌市第二中学");

    PrintAPI::Instance()->PrintA4(titleData, "", columnNames, columnWidths, content, true, false);





    // if(classesResultLists.isEmpty()){
    //     QMessageBox::information(this, "失败", "没有分班结果数据!");
    //     return;
    // }
    // PrinterClassesResult *pr = new PrinterClassesResult();
    // pr->setTitle(titleData);
    // pr->show();

    // // 连接信号和槽
    // connect(this, &ClassSet::sendPrinterData, pr, &PrinterClassesResult::receivePrinterData);
    // // qDebug() << "data1:" ;

    // //获取封装类对象内容并发送信号
    // emit sendPrinterData(classesResultLists);

    // //断开sender和receiver之间的所有连接
    // disconnect(this, nullptr, pr, nullptr);
}
// 添加班级按钮
void ClassSet::on_classSettingbtn_clicked(){
    // QMessageBox::information(this, "提示", "按钮被点击，即将进入导入");
    ClassNumberSetForm *f = new ClassNumberSetForm();
    f->setClassAndStu(this->model2);
    f->show();
}
// 删除班级按钮
void ClassSet::on_deleteBtn_clicked(){
    QModelIndexList selectedRows = tableView2->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "警告", "请选中要删除的数据行！");
        return;
    }
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "确认", "确定删除特定数据吗?",QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        // 用户点击了"是"
        // model2->removeRows(0, model2->rowCount());
        //清空班级分班数据
        // 4.1 获取需要删除的行号（倒序排序）
        QList<int> rows;
        foreach (const QModelIndex &index, selectedRows) {
            rows.append(index.row());
        }
        std::sort(rows.begin(), rows.end(), std::greater<int>()); // 从大到小排序

        // 4.2 批量删除行
        foreach (int row, rows) {
            model2->removeRow(row);
            // vClassCount.remove(index);
        }
    }
    else {
        // 用户点击了"否"
        return;
    }

}

//返回班级数，总人数：totalStudents
int ClassSet::calculateClasses(int totalStudents) {
    if (totalStudents <= 0) {
        qDebug() << "错误：学生总数必须大于0";
        return -1;
    }
    // 计算最少需要的班级数量（向上取整）
    int numClasses = ceil(static_cast<double>(totalStudents) / 50);
    return numClasses;
}
//返回每个班级人数，总人数：totalStudents，班级数：numClasses
QVector<int> ClassSet::printDistribution(int totalStudents, int numClasses) {
    int base = totalStudents / numClasses;
    int remainder = totalStudents % numClasses;

    // 空向量
    QVector<int> classVector;
    for (int i = 1; i <= numClasses; ++i) {
        if (i <= remainder) {
            // qDebug() << "班级 " << i << ": " << (base + 1) << " 人";
            // 在末尾添加
            classVector.append(base + 1);
        } else {
            //qDebug() << "班级 " << i << ": " << base << " 人";
            // 在末尾添加
            classVector.append(base);
        }
    }
    return classVector;
}

ClassSet::~ClassSet()
{
    delete ui;
}

