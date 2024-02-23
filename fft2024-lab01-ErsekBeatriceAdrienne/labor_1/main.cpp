#include "mainwindow.h"

#include <QApplication>
#include <QLabel>
#include <QDate>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.setWindowTitle("Calculator");
    w.setStyleSheet("QMainWindow{background:'black';}");

    ///  Hozzunk létre egy Qt Widgets Application típusú projektet,
    ///  amely futtatáskor kiírja az aktuális dátumot
    ///  (ÉÉÉÉ-HH-NN formátumban). Használjuk a QDate osztályt.
    ///this is the date class
    /*QDate date = QDate::currentDate();
    QString sdate = date.toString("yyyy-MM-dd");

    //this is the "window" class
    ///the context of the window
    QLabel label("Aktuális dátum : " + sdate);
    ///align the text in the center
    label.setAlignment(Qt::AlignCenter);
    ///set the size of the window
    label.resize(400,200);
    ///show the window
    label.show();*/

    w.show();
    return a.exec();
}
