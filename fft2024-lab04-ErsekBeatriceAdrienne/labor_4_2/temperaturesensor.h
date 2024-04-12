#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include <QCoreApplication>
#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QRandomGenerator>

class TemperatureSensor : public QObject {
    Q_OBJECT
public:
    TemperatureSensor(QObject *parent = nullptr);

private:
    QTimer *timer;

signals:
    void temperatureExceeded(int);

};

#endif // TEMPERATURESENSOR_H
