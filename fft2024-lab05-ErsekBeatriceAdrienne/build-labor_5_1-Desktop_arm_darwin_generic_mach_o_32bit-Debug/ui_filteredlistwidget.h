/********************************************************************************
** Form generated from reading UI file 'filteredlistwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTEREDLISTWIDGET_H
#define UI_FILTEREDLISTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilteredListWidget
{
public:
    QWidget *centralwidget;

    void setupUi(QMainWindow *FilteredListWidget)
    {
        if (FilteredListWidget->objectName().isEmpty())
            FilteredListWidget->setObjectName("FilteredListWidget");
        FilteredListWidget->resize(381, 466);
        centralwidget = new QWidget(FilteredListWidget);
        centralwidget->setObjectName("centralwidget");
        FilteredListWidget->setCentralWidget(centralwidget);

        retranslateUi(FilteredListWidget);

        QMetaObject::connectSlotsByName(FilteredListWidget);
    } // setupUi

    void retranslateUi(QMainWindow *FilteredListWidget)
    {
        FilteredListWidget->setWindowTitle(QCoreApplication::translate("FilteredListWidget", "FilteredListWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FilteredListWidget: public Ui_FilteredListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTEREDLISTWIDGET_H
