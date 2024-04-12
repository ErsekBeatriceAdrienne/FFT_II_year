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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *ax;
    QLineEdit *bx;
    QLineEdit *cx;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *button;
    QLineEdit *result_text;
    QLabel *label_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(293, 475);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        ax = new QLineEdit(centralwidget);
        ax->setObjectName("ax");
        ax->setGeometry(QRect(90, 40, 131, 41));
        bx = new QLineEdit(centralwidget);
        bx->setObjectName("bx");
        bx->setGeometry(QRect(90, 110, 131, 41));
        cx = new QLineEdit(centralwidget);
        cx->setObjectName("cx");
        cx->setGeometry(QRect(90, 180, 131, 41));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 40, 31, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 120, 31, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 190, 31, 31));
        button = new QPushButton(centralwidget);
        button->setObjectName("button");
        button->setGeometry(QRect(100, 260, 100, 32));
        result_text = new QLineEdit(centralwidget);
        result_text->setObjectName("result_text");
        result_text->setGeometry(QRect(90, 340, 121, 51));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 360, 41, 16));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "a :", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "b :", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "c :", nullptr));
        button->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Delta", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
