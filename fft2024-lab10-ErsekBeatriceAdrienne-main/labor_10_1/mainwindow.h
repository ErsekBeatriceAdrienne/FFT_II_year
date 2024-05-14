#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QtCharts>
#include <QMainWindow>
#include <QLineSeries>
#include <QSplineSeries>
#include <QChart>
#include <QChartView>
#include <QVBoxLayout>
#include <QPainter>
#include <QBarSet>
#include <QBarSeries>
#include <QVector>
#include <QBarCategoryAxis>
#include <QValueAxis>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void linechart();
    void piechart();
    void columnchart();
};

#endif // MAINWINDOW_H
