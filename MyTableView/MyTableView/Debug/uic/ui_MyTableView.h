/********************************************************************************
** Form generated from reading UI file 'MyTableView.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYTABLEVIEW_H
#define UI_MYTABLEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyTableViewClass
{
public:

    void setupUi(QWidget *MyTableViewClass)
    {
        if (MyTableViewClass->objectName().isEmpty())
            MyTableViewClass->setObjectName(QStringLiteral("MyTableViewClass"));
        MyTableViewClass->resize(600, 400);

        retranslateUi(MyTableViewClass);

        QMetaObject::connectSlotsByName(MyTableViewClass);
    } // setupUi

    void retranslateUi(QWidget *MyTableViewClass)
    {
        MyTableViewClass->setWindowTitle(QApplication::translate("MyTableViewClass", "MyTableView", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyTableViewClass: public Ui_MyTableViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYTABLEVIEW_H
