#include "mainwindow.h"

MainWindow :: MainWindow(QWidget *parent) : QMainWindow(parent)
{
    Tetraeder *t = new Tetraeder(this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(t);

    this->setLayout(layout);
    setWindowTitle("Tetraeder");

    setFocus();
    show();
}
