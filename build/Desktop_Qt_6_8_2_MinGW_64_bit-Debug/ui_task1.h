/********************************************************************************
** Form generated from reading UI file 'task1.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK1_H
#define UI_TASK1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_task1
{
public:
    QLineEdit *lineEdit_Task1;
    QPushButton *pushButton_Task1_Cancel;
    QPushButton *pushButton_Task1_Ok;
    QLabel *label_test1;

    void setupUi(QDialog *task1)
    {
        if (task1->objectName().isEmpty())
            task1->setObjectName("task1");
        task1->resize(628, 300);
        lineEdit_Task1 = new QLineEdit(task1);
        lineEdit_Task1->setObjectName("lineEdit_Task1");
        lineEdit_Task1->setGeometry(QRect(200, 140, 231, 28));
        pushButton_Task1_Cancel = new QPushButton(task1);
        pushButton_Task1_Cancel->setObjectName("pushButton_Task1_Cancel");
        pushButton_Task1_Cancel->setGeometry(QRect(400, 180, 83, 29));
        pushButton_Task1_Ok = new QPushButton(task1);
        pushButton_Task1_Ok->setObjectName("pushButton_Task1_Ok");
        pushButton_Task1_Ok->setGeometry(QRect(150, 180, 83, 29));
        label_test1 = new QLabel(task1);
        label_test1->setObjectName("label_test1");
        label_test1->setGeometry(QRect(20, 30, 581, 91));

        retranslateUi(task1);

        QMetaObject::connectSlotsByName(task1);
    } // setupUi

    void retranslateUi(QDialog *task1)
    {
        task1->setWindowTitle(QCoreApplication::translate("task1", "Dialog", nullptr));
        pushButton_Task1_Cancel->setText(QCoreApplication::translate("task1", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        pushButton_Task1_Ok->setText(QCoreApplication::translate("task1", "\320\236\320\272", nullptr));
        label_test1->setText(QCoreApplication::translate("task1", "<html><head/><body><p><span style=\" font-size:12pt;\">TextLabel</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class task1: public Ui_task1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK1_H
