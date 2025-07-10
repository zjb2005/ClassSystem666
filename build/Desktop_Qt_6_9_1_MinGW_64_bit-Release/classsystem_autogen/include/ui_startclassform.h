/********************************************************************************
** Form generated from reading UI file 'startclassform.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTCLASSFORM_H
#define UI_STARTCLASSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartClassForm
{
public:

    void setupUi(QWidget *StartClassForm)
    {
        if (StartClassForm->objectName().isEmpty())
            StartClassForm->setObjectName("StartClassForm");
        StartClassForm->resize(797, 578);
        StartClassForm->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 85, 255);"));

        retranslateUi(StartClassForm);

        QMetaObject::connectSlotsByName(StartClassForm);
    } // setupUi

    void retranslateUi(QWidget *StartClassForm)
    {
        StartClassForm->setWindowTitle(QCoreApplication::translate("StartClassForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartClassForm: public Ui_StartClassForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTCLASSFORM_H
