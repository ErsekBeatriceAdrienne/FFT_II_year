#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow :: MainWindow(QWidget *parent) : QMainWindow(parent)
{
    notepad = new Notepad(this);
    setCentralWidget(notepad);
}

MainWindow :: ~MainWindow() {}
