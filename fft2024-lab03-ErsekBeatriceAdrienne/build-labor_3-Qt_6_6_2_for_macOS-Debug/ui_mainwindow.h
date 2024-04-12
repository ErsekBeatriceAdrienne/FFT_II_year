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
#include <QtWidgets/QComboBox>
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
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *convert_button;
    QLineEdit *number_text;
    QLineEdit *result_text;
    QComboBox *bases_box;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(414, 273);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 30, 58, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(260, 30, 58, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 130, 58, 16));
        convert_button = new QPushButton(centralwidget);
        convert_button->setObjectName("convert_button");
        convert_button->setGeometry(QRect(260, 120, 100, 32));
        number_text = new QLineEdit(centralwidget);
        number_text->setObjectName("number_text");
        number_text->setGeometry(QRect(50, 60, 131, 41));
        result_text = new QLineEdit(centralwidget);
        result_text->setObjectName("result_text");
        result_text->setGeometry(QRect(50, 160, 171, 51));
        bases_box = new QComboBox(centralwidget);
        bases_box->setObjectName("bases_box");
        bases_box->setGeometry(QRect(252, 61, 111, 41));
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
        label->setText(QCoreApplication::translate("MainWindow", "Number", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "To Base", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Result", nullptr));
        convert_button->setText(QCoreApplication::translate("MainWindow", "Convert", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
