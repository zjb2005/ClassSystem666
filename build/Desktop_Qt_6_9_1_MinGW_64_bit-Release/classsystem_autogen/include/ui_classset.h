/********************************************************************************
** Form generated from reading UI file 'classset.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLASSSET_H
#define UI_CLASSSET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClassSet
{
public:

    void setupUi(QWidget *ClassSet)
    {
        if (ClassSet->objectName().isEmpty())
            ClassSet->setObjectName("ClassSet");
        ClassSet->resize(400, 300);

        retranslateUi(ClassSet);

        QMetaObject::connectSlotsByName(ClassSet);
    } // setupUi

    void retranslateUi(QWidget *ClassSet)
    {
        ClassSet->setWindowTitle(QCoreApplication::translate("ClassSet", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClassSet: public Ui_ClassSet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASSSET_H
