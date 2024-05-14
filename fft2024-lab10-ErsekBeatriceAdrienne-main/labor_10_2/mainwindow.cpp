#include "mainwindow.h"

MainWindow :: MainWindow(QWidget *parent) : QMainWindow(parent)
{
    // A vonaldiagram inicializálása
    chart = new QChart();
    series = new QLineSeries();
    chart->addSeries(series);
    chart->legend()->hide();
    chart->setTitle("Élő Vonaldiagram");

    // A ChartView inicializálása és hozzáadása az ablakhoz
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(chartView);

    // Időzítő létrehozása az adatok frissítéséhez
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateData()));
    timer->start(1000); // Frissítési időköz (ms)

    // Tengelyek címkéinek beállítása
    chart->createDefaultAxes();
    chart->axes(Qt::Horizontal).first()->setTitleText("Idő");
    chart->axes(Qt::Vertical).first()->setTitleText("Érték");

    // Háttérszín beállítása
    chart->setBackgroundBrush(QBrush(Qt::darkGray));

    // Vonal színének beállítása
    QPen pen = series->pen();
    pen.setColor(Qt::yellow); // Tetszőleges szín
    series->setPen(pen);
}

void MainWindow :: updateData()
{
    // Véletlenszerű pontok generálása
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> disX(0.0, 100.0);
    std::uniform_real_distribution<> disY(0.0, 100.0);

    qreal x1 = disX(gen);
    qreal y1 = disY(gen);
    qreal x2 = disX(gen);
    qreal y2 = disY(gen);

    // Régi vonal törlése, ha van
    if (chart->series().size() > 1) {
        chart->removeSeries(chart->series().at(1));
    }

    // Új véletlenszerű vonal hozzáadása
    QLineSeries *lineSeries = new QLineSeries();
    lineSeries->append(QPointF(x1, y1));
    lineSeries->append(QPointF(x2, y2));

    // Vonal színének beállítása zöldre
    QPen pen(Qt::green);
    lineSeries->setPen(pen);

    chart->addSeries(lineSeries);

    // Diagram frissítése
    qreal maxX = std::max(x1, x2);
    qreal minX = std::min(x1, x2);
    qreal maxY = std::max(y1, y2);
    qreal minY = std::min(y1, y2);

    chart->axisX()->setRange(minX, maxX); // X tengely tartományának beállítása
    chart->axisY()->setRange(minY, maxY);
}
