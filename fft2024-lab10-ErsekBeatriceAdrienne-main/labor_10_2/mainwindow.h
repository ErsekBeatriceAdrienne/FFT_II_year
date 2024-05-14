#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtCharts/QChartView>
#include <QMainWindow>
#include <QtWidgets>
#include <QLineSeries>
#include <QtCharts/QChartView>
#include <QRandomGenerator>
#include <random>
#include <QDateTime>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:

private:
    QChart *chart;
    QLineSeries *series;
    QTimer *timer;

    void updateData();
};

#endif // MAINWINDOW_H
