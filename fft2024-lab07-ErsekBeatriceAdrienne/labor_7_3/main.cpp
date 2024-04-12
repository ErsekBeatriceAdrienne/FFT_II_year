#include "mainwindow.h"
#include <QTime>
#include <QApplication>
#include <QtGlobal>

int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    qrand();

    MainWindow w;
    w.show();
    return a.exec();*/

    QApplication app(argc, argv);
    srand(QTime::currentTime().msec()); // Random generátor inicializálása
    MainWindow mainWindow;
    mainWindow.setStyleSheet("QWidget { background-color: #f0f0f0; }" // Ablak háttere
                             "QLabel { font-size: 18px; font-style: italic; margin: 20px; }" // Idézet stílusa
                             "QPushButton { font-size: 14px; padding: 10px; margin: 20px; background-color: #4CAF50; color: white; border: none; border-radius: 5px; }" // Gomb stílusa
                             "QPushButton:hover { background-color: #45a049; }"); // Gomb stílusának hover állapota
    mainWindow.show();
    return app.exec();
}
