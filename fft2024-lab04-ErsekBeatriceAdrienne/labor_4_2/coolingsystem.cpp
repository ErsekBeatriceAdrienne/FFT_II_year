#include "coolingsystem.h"

CoolingSystem :: CoolingSystem(QObject *parent) : QObject(parent)
{

}

void CoolingSystem :: handleTemperatureExceeded(int temperature)
{
    qDebug() << "Hőmérséklet túllépte a küszöbértéket:" << temperature << "°C!";
}
