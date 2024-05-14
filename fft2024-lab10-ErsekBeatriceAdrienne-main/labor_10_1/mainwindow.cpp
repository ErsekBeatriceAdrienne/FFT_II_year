#include "mainwindow.h"

MainWindow :: MainWindow(QWidget *parent) : QMainWindow(parent)
{
    linechart();
    piechart();
    columnchart();
}

void MainWindow :: linechart()
{
    QWidget *window = new QWidget;
    QLineSeries *lineSeries = new QLineSeries();
    QSplineSeries *splineSeries = new QSplineSeries();

    // Adatpontok hozzáadása a vonaldiagramhoz és a görbéhez
    lineSeries->append(1, 1);
    lineSeries->append(2, 3);
    lineSeries->append(3, 2);
    lineSeries->append(4, 4);
    lineSeries->append(5, 5);

    splineSeries->append(1, 1);
    splineSeries->append(2, 3);
    splineSeries->append(3, 2);
    splineSeries->append(4, 4);
    splineSeries->append(5, 5);

    QChart *chart = new QChart();
    chart->addSeries(lineSeries);
    chart->addSeries(splineSeries);
    chart->createDefaultAxes();
    chart->setTitle("Line Chart & Spline Chart Example");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *l = new QVBoxLayout(window);

    l->addWidget(chartView);

    window->setLayout(l);
    window->resize(800, 600);
    window->setWindowTitle("Line Chart");
    window->show();
}

void MainWindow :: piechart()
{
    QWidget *window = new QWidget;
    QPieSeries *series = new QPieSeries();
    series->append("Category 1", 10);
    series->append("Category 2", 20);
    series->append("Category 3", 30);
    series->append("Category 4", 40);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Pie Chart Example");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *l = new QVBoxLayout(window);
    l->addWidget(chartView);

    window->setLayout(l);
    window->resize(800, 600);
    window->setWindowTitle("Pie Chart");
    window->show();
}

void MainWindow :: columnchart()
{
    QWidget *window = new QWidget;

    // Adatok
    QVector<QString> categories = {"Category 1", "Category 2", "Category 3", "Category 4", "Category 5"};
    QVector<int> values = {10, 20, 30, 40, 50};

    // Oszlopdiagram létrehozása
    QChart *chart = new QChart();
    chart->setTitle("Bar Chart");

    QBarSeries *series = new QBarSeries();
    for (int i = 0; i < categories.size(); ++i) {
        QBarSet *set = new QBarSet(categories[i]);
        *set << values[i];
        series->append(set);
    }
    chart->addSeries(series);

    // Címkék hozzáadása az X tengelyhez
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Címkék hozzáadása az Y tengelyhez
    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Diagram megjelenítése
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *layout = new QVBoxLayout(window);
    layout->addWidget(chartView);

    window->setLayout(layout);
    window->setWindowTitle("Column Chart");
    window->resize(800, 600);
    window->show();
}
