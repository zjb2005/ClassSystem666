#include "printerclassesresult.h"
#include "ui_printerclassesresult.h"

#include <QTableWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QHeaderView>
#include <QDebug>
#include <QStandardItemModel>
#include <QScrollArea>

PrinterClassesResult::PrinterClassesResult(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PrinterClassesResult)
{
    ui->setupUi(this);

    // 创建主窗口
    QWidget *widget = new QWidget(this);
    // window.setWindowTitle("垂直布局示例");
    //第一个layout内容
    // 创建Label（默认左对齐）
    label1 = new QLabel();
    label1->setStyleSheet("font-size: 50px; font-weight: bold;");
    //设留水平和垂直部恩中
    label1->setFixedHeight(50);
    label1->setAlignment(Qt::AlignCenter);
    // 添加按钮到布局中
    QPushButton *button1 = new QPushButton("打  印");
    button1->setFixedSize(120,50);
    button1->setStyleSheet("font-size: 20px;background-color: #4169E1; color: white;");
    // 第一个创建horizontal布局
    QHBoxLayout *l1 = new QHBoxLayout;
    l1->addWidget(label1,3);
    l1->addWidget(button1,1);
    // 添加horizontal间距
    // l1->addSpacing(20);



    // 第二个layout 添加分隔线
    // 创建水平线 (QFrame)
    QFrame *line1 = new QFrame();
    line1->setFrameShape(QFrame::HLine);  // 水平线
    line1->setFrameShadow(QFrame::Sunken); // 可选：使线条有凹陷效果

    QHBoxLayout *l2 = new QHBoxLayout;
    l2 ->addWidget(line1);

    //第三个layout
    // 创建 TableView 和 Model
    tableView = new QTableView;
    // 获取水平表头并设置
    // QHeaderView* header = tableView->horizontalHeader();
    // header->setSectionResizeMode(QHeaderView::Interactive);  // 所有列可手动调整
    // tableView->horizontalHeader()->setStyleSheet("font-size: 16px; font-weight: bold;");
    // 调整列宽以适应内容
    tableView->resizeColumnsToContents();
    // 调整行高以适应内容
    tableView->resizeRowsToContents();
    //启用/禁用编辑，不可编辑
    // tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // tableView->setStyleSheet(
    //     "QTableView::item {"
    //     "   min-width: 80px;"
    //     "}"
    // );
    model = new QStandardItemModel();
    model->setHorizontalHeaderLabels({"班级名称", "姓名", "性别", "身份证号码","学校名称", "备注"});
    tableView->show();
    //第五个layout
    QHBoxLayout *l3 = new QHBoxLayout;
    l3 ->addWidget(tableView);

    tableView->setModel(model);
    // 设置主布局
    QVBoxLayout *mainLayout = new QVBoxLayout(widget);
    mainLayout->addLayout(l1,3);
    mainLayout->addLayout(l2,1);
    mainLayout->addLayout(l3,6);
    this->setLayout(mainLayout);
    this->setWindowTitle("阳光新生分班系统"); // 设置窗口标题
    this->resize(1000, 700);

    connect(button1, &QPushButton::clicked, this, &PrinterClassesResult::printWindowInfo);


}
//获取项目名称
void PrinterClassesResult::setTitle(const QString &title){
    titleData = title;
}

// 在这个窗口中显示接收到的数据
void PrinterClassesResult::receivePrinterData(QList<Classes> resultLists){
    classesResultLists = resultLists;
    for (Classes c1: classesResultLists){
        QString clName = c1.className;

        std::vector<Student> students = c1.students;
        for (Student st: students){
            qreal grade = st.getGrade();
            QString gender = QString::fromStdString(st.getSex());
            qDebug()<<"PrinterClassesResult"<<"school:"<<st.getSchool()<<"name:" <<clName<<"sex:"<<st.getSex()<<"成绩："<<gender<< grade;
        }
    }

    //显示分班结果列表
    showClassInfo();
    //label1->setText(titleData);
}

//显示分班结果列表
void PrinterClassesResult::showClassInfo(){
    // 填充数据
    for (Classes cl: classesResultLists){
        QString clName = cl.className;
        std::vector<Student> students = cl.students;

        for (int i = 0; i < students.size(); i++) {
            // 添加一行数据
            QList<QStandardItem*> rowItems;
            // 第一列：班级名称
            rowItems << new QStandardItem(clName);
            // 第二列：姓名
            rowItems << new QStandardItem(QString::fromStdString(students[i].getName()));
            // 第三列：性别
            rowItems << new QStandardItem(QString::fromStdString(students[i].getSex()));
            // 第四列：身份证号码
            //身份证号掩码
            std::string sId = students[i].getId();
            QString qSId = QString::fromStdString(sId);
            if (qSId.length() >= 12) {
                // 将第11-14位（出生日期）替换为*
                qSId = qSId.left(7) + "****" + qSId.right(4);
            }
            rowItems << new QStandardItem(qSId);
            // 第五列：学校名称
            rowItems << new QStandardItem(QString::fromStdString(students[i].getSchool()));
            // 第六列：备注
            rowItems << new QStandardItem(QString::fromStdString(students[i].getNotes()));
            model->appendRow(rowItems);
            // 第一列：班级名称
            // model->setItem(0, new QStandardItem(clName));
            // // 第二列：姓名
            // model->setItem(1, new QStandardItem(QString::fromStdString(students[i].getName())));
            // // 第三列：性别
            // model->setItem(2, new QStandardItem(QString::fromStdString(students[i].getSex())));
            // // 第四列：身份证号码
            // model->setItem(3, new QStandardItem(QString::fromStdString(students[i].getId())));
            // // 第五列：学校名称
            // model->setItem(4, new QStandardItem(QString::fromStdString(students[i].getSchool())));
            // // 第六列：备注
            // model->setItem(5, new QStandardItem(QString::fromStdString(students[i].getNotes())));
        }
    }
}
//打印窗体信息
void PrinterClassesResult::printWindowInfo()
{
    QPrinter printer(QPrinter::HighResolution);
    QPrintDialog printDialog(&printer, this);

    // 获取页面矩形，指定单位（DevicePixel 或 Millimeter 等）
    QRectF pageRect = printer.pageRect(QPrinter::DevicePixel);

    // if (printDialog.exec() == QDialog::Accepted) {
    //     label1
    // }

    // QPrinter printer(QPrinter::HighResolution);
    // QPrintDialog printDialog(&printer, this);

    // // 获取页面矩形，指定单位（DevicePixel 或 Millimeter 等）
    // QRectF pageRect = printer.pageRect(QPrinter::DevicePixel);

    // if (printDialog.exec() == QDialog::Accepted) {
    //     // 创建绘图对象
    //     QPainter painter(&printer);

    //     // 计算缩放比例以适应纸张
    //     double xscale = pageRect.width() / double(this->width());
    //     double yscale = pageRect.height() / double(this->height());
    //     double scale = qMin(xscale, yscale);

    //     // 应用缩放
    //     painter.scale(scale, scale);

    //     // 渲染整个窗口到打印机
    //     this->render(&painter);

    //     painter.end();
    // }
}

//方法3：分页打印大型内容
void PrinterClassesResult::printEntireWidget(QWidget* widget)
{
    // 创建打印机对象
    QPrinter printer(QPrinter::HighResolution);
    QRectF pageRect = printer.pageRect(QPrinter::DevicePixel);
    // 创建打印对话框
    QPrintDialog dialog(&printer, this);
    dialog.setWindowTitle("Print Document");

    // 如果用户点击了"打印"按钮
    if (dialog.exec() == QDialog::Accepted) {
        QPainter painter(&printer);

        // 获取widget的完整大小（对于可滚动区域）
        QSize fullSize = widget->size();
        if (QScrollArea* scrollArea = qobject_cast<QScrollArea*>(widget->parentWidget())) {
            fullSize = scrollArea->widget()->size();
        } else if (QAbstractScrollArea* abstractScrollArea = qobject_cast<QAbstractScrollArea*>(widget)) {
            fullSize = abstractScrollArea->viewport()->size();
            fullSize.setHeight(abstractScrollArea->height());
        }

        // 计算缩放比例以适应页面
        double xscale = pageRect.width() / double(fullSize.width());
        double yscale = pageRect.height() / double(fullSize.height());
        double scale = qMin(xscale, yscale);

        // 设置缩放
        painter.scale(scale, scale);

        // 创建一个足够大的矩形来容纳所有内容
        QRect printRect(0, 0, fullSize.width(), fullSize.height());

        // 渲染完整内容
        widget->render(&painter, QPoint(), QRegion(printRect), QWidget::DrawChildren);

        qDebug() << "Printing completed. Document size:" << fullSize << "Scale:" << scale;
    }
}



PrinterClassesResult::~PrinterClassesResult()
{
    delete ui;
}
