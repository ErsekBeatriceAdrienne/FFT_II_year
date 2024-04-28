#include "mainwindow.h"

MainWindow :: MainWindow(QWidget *parent) : QMainWindow(parent)
{
    Drawer draw = new Drawer(this);
    setWindowTitle("OpenGL");
    resize(800, 600);

    show();
}
