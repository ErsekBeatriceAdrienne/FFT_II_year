#ifndef COOLINGSYSTEM_H
#define COOLINGSYSTEM_H

#include <QObject>
#include "temperaturesensor.h"

class CoolingSystem : public QObject
{
    Q_OBJECT

public:
    CoolingSystem(QObject *parent = nullptr);

public slots:
    void handleTemperatureExceeded(int);

};

#endif // COOLINGSYSTEM_H
