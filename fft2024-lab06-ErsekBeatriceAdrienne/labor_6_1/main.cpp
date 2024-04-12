/*#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}*/

#include "mainwindow.h"
#include<QApplication>


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow hangmanGame;
    hangmanGame.setWindowTitle("Hangman Game");
    hangmanGame.show();

    return app.exec();
}


