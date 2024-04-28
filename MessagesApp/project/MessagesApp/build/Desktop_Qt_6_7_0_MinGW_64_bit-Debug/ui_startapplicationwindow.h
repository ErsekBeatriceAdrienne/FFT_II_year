/********************************************************************************
** Form generated from reading UI file 'startapplicationwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTAPPLICATIONWINDOW_H
#define UI_STARTAPPLICATIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartApplicationWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StartApplicationWindow)
    {
        if (StartApplicationWindow->objectName().isEmpty())
            StartApplicationWindow->setObjectName("StartApplicationWindow");
        StartApplicationWindow->resize(800, 600);
        centralwidget = new QWidget(StartApplicationWindow);
        centralwidget->setObjectName("centralwidget");
        StartApplicationWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(StartApplicationWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        StartApplicationWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(StartApplicationWindow);
        statusbar->setObjectName("statusbar");
        StartApplicationWindow->setStatusBar(statusbar);

        retranslateUi(StartApplicationWindow);

        QMetaObject::connectSlotsByName(StartApplicationWindow);
    } // setupUi

    void retranslateUi(QMainWindow *StartApplicationWindow)
    {
        StartApplicationWindow->setWindowTitle(QCoreApplication::translate("StartApplicationWindow", "StartApplicationWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartApplicationWindow: public Ui_StartApplicationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTAPPLICATIONWINDOW_H
