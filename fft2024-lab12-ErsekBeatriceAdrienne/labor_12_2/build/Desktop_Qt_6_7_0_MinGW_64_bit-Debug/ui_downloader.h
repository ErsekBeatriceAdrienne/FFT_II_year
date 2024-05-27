/********************************************************************************
** Form generated from reading UI file 'downloader.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOADER_H
#define UI_DOWNLOADER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Downloader
{
public:

    void setupUi(QWidget *Downloader)
    {
        if (Downloader->objectName().isEmpty())
            Downloader->setObjectName("Downloader");
        Downloader->resize(800, 600);

        retranslateUi(Downloader);

        QMetaObject::connectSlotsByName(Downloader);
    } // setupUi

    void retranslateUi(QWidget *Downloader)
    {
        Downloader->setWindowTitle(QCoreApplication::translate("Downloader", "Downloader", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Downloader: public Ui_Downloader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOADER_H
