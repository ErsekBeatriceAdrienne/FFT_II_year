#include "temperaturesensor.h"

TemperatureSensor :: TemperatureSensor (QObject *parent) : QObject(parent) {
    // QTimer az értékek periódikus generálására (1 másodpercenként)
    QTimer *timer = new QTimer(this);
    connect (timer, &QTimer :: timeout, [=]() {
        int value = QRandomGenerator :: global()->bounded(20, 40);
        if (value > 30) emit temperatureExceeded(value);
    });
    timer->start(1000);
}
