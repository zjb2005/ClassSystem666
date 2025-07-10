/********************************************************************************
** Form generated from reading UI file 'printerclassesresult.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINTERCLASSESRESULT_H
#define UI_PRINTERCLASSESRESULT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrinterClassesResult
{
public:

    void setupUi(QWidget *PrinterClassesResult)
    {
        if (PrinterClassesResult->objectName().isEmpty())
            PrinterClassesResult->setObjectName("PrinterClassesResult");
        PrinterClassesResult->resize(400, 300);

        retranslateUi(PrinterClassesResult);

        QMetaObject::connectSlotsByName(PrinterClassesResult);
    } // setupUi

    void retranslateUi(QWidget *PrinterClassesResult)
    {
        PrinterClassesResult->setWindowTitle(QCoreApplication::translate("PrinterClassesResult", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PrinterClassesResult: public Ui_PrinterClassesResult {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTERCLASSESRESULT_H
