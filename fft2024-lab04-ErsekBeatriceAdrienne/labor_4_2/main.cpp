#include <QCoreApplication>
#include <QWidget>
#include "temperaturesensor.h"
#include "coolingsystem.h"
#include <QObject>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TemperatureSensor sensor;
    CoolingSystem system;

    QObject::connect(&sensor, &TemperatureSensor::temperatureExceeded, &system, &CoolingSystem::handleTemperatureExceeded);

    return a.exec();
}
