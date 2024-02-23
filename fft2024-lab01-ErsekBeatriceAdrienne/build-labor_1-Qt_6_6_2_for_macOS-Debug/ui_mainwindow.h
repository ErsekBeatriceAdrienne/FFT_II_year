/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *number1;
    QLineEdit *number2;
    QPushButton *plusb;
    QPushButton *minusb;
    QPushButton *multiplyb;
    QPushButton *divideb;
    QLineEdit *result;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(413, 331);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        number1 = new QLineEdit(centralwidget);
        number1->setObjectName("number1");
        number1->setGeometry(QRect(10, 50, 171, 51));
        number2 = new QLineEdit(centralwidget);
        number2->setObjectName("number2");
        number2->setGeometry(QRect(230, 50, 171, 51));
        plusb = new QPushButton(centralwidget);
        plusb->setObjectName("plusb");
        plusb->setGeometry(QRect(10, 110, 91, 91));
        minusb = new QPushButton(centralwidget);
        minusb->setObjectName("minusb");
        minusb->setGeometry(QRect(110, 110, 91, 91));
        multiplyb = new QPushButton(centralwidget);
        multiplyb->setObjectName("multiplyb");
        multiplyb->setGeometry(QRect(210, 110, 91, 91));
        divideb = new QPushButton(centralwidget);
        divideb->setObjectName("divideb");
        divideb->setGeometry(QRect(310, 110, 91, 91));
        result = new QLineEdit(centralwidget);
        result->setObjectName("result");
        result->setGeometry(QRect(10, 220, 391, 51));
        result->setReadOnly(true);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 58, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(230, 30, 58, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 200, 58, 16));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        plusb->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        minusb->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        multiplyb->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        divideb->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Number", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Number", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Result", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
