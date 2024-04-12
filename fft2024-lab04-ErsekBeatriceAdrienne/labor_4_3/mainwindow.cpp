#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow :: MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->window = new QWidget;
    this->layout = new QVBoxLayout;
    this->grid = new QGridLayout;

    this->s1 = new MagicSlider;
    this->r1 = new RewardBagDisplayer;
    this->r2 = new RewardBagDisplayer;
    this->r3 = new RewardBagDisplayer;
    this->r4 = new RewardBagDisplayer;
    this->r5 = new RewardBagDisplayer;
    this->r6 = new RewardBagDisplayer;
    this->r7 = new RewardBagDisplayer;
    this->r8 = new RewardBagDisplayer;
    this->r9 = new RewardBagDisplayer;

    this->layout->addWidget(this->s1);
    this->layout->addWidget(this->r1);
    this->layout->addWidget(this->r2);
    this->layout->addWidget(this->r3);
    this->layout->addWidget(this->r4);
    this->layout->addWidget(this->r5);
    this->layout->addWidget(this->r6);
    this->layout->addWidget(this->r7);
    this->layout->addWidget(this->r8);
    this->layout->addWidget(this->r9);

    QObject::connect(this->s1, &QSlider::valueChanged, this, &MainWindow::change_value);


    this->window->setLayout(this->layout);
    this->setCentralWidget(this->window);
}

void MainWindow :: change_value()
{
    int value1 = QRandomGenerator::global()->bounded(0, 101);
    this->r1->display(value1);
    int value2 = QRandomGenerator::global()->bounded(0, 101);
    this->r2->display(value2);
    int value3 = QRandomGenerator::global()->bounded(0, 101);
    this->r3->display(value3);
    int value4 = QRandomGenerator::global()->bounded(0, 101);
    this->r4->display(value4);
    int value5 = QRandomGenerator::global()->bounded(0, 101);
    this->r5->display(value5);
    int value6 = QRandomGenerator::global()->bounded(0, 101);
    this->r6->display(value6);
    int value7 = QRandomGenerator::global()->bounded(0, 101);
    this->r7->display(value7);
    int value8 = QRandomGenerator::global()->bounded(0, 101);
    this->r8->display(value8);
    int value9 = QRandomGenerator::global()->bounded(0, 101);
    this->r9->display(value9);
}

MainWindow :: ~MainWindow() {}
