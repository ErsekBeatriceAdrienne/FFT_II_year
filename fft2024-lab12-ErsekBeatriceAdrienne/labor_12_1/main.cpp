#include "weatherapp.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WeatherApp weatherApp;
    weatherApp.show();

    return a.exec();
}
