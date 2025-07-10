/********************************************************************************
** Form generated from reading UI file 'classnumbersetform.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLASSNUMBERSETFORM_H
#define UI_CLASSNUMBERSETFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClassNumberSetForm
{
public:
    QLineEdit *lineEdit1;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit2;
    QPushButton *pushButton;

    void setupUi(QWidget *ClassNumberSetForm)
    {
        if (ClassNumberSetForm->objectName().isEmpty())
            ClassNumberSetForm->setObjectName("ClassNumberSetForm");
        ClassNumberSetForm->resize(515, 384);
        lineEdit1 = new QLineEdit(ClassNumberSetForm);
        lineEdit1->setObjectName("lineEdit1");
        lineEdit1->setGeometry(QRect(230, 90, 111, 31));
        QFont font;
        font.setPointSize(16);
        lineEdit1->setFont(font);
        label = new QLabel(ClassNumberSetForm);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 90, 81, 31));
        QFont font1;
        font1.setPointSize(18);
        label->setFont(font1);
        label_2 = new QLabel(ClassNumberSetForm);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 150, 71, 31));
        label_2->setFont(font1);
        lineEdit2 = new QLineEdit(ClassNumberSetForm);
        lineEdit2->setObjectName("lineEdit2");
        lineEdit2->setGeometry(QRect(230, 149, 111, 31));
        lineEdit2->setFont(font);
        pushButton = new QPushButton(ClassNumberSetForm);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(220, 220, 101, 41));
        pushButton->setFont(font1);

        retranslateUi(ClassNumberSetForm);

        QMetaObject::connectSlotsByName(ClassNumberSetForm);
    } // setupUi

    void retranslateUi(QWidget *ClassNumberSetForm)
    {
        ClassNumberSetForm->setWindowTitle(QCoreApplication::translate("ClassNumberSetForm", "\346\267\273\345\212\240\347\217\255\347\272\247", nullptr));
#if QT_CONFIG(tooltip)
        ClassNumberSetForm->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        lineEdit1->setText(QString());
        label->setText(QCoreApplication::translate("ClassNumberSetForm", "\347\217\255\347\272\247\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("ClassNumberSetForm", "\344\272\272\346\225\260\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("ClassNumberSetForm", "\347\241\256   \345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClassNumberSetForm: public Ui_ClassNumberSetForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASSNUMBERSETFORM_H
