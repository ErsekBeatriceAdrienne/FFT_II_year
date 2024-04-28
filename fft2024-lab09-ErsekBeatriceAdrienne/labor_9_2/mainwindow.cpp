#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow :: MainWindow(QWidget *parent) : QMainWindow(parent)
{
    Cube *cube = new Cube(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget());

    setCentralWidget(new QWidget);
    layout->addWidget(cube);

    show();
}
