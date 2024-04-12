#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow :: MainWindow(QWidget *parent) : QMainWindow(parent)
{
    // UI komponensek létrehozása
    this->window = new QWidget;
    this->label = new QLabel("Hello GUI World!");
    this->button = new QPushButton("Quit!");
    this->welcome_button = new QPushButton("Fordítás");
    this->hide_button = new QPushButton("OFF");
    this->welcome_label = new QLabel;
    this->layout = new QVBoxLayout;
    //set the way
    this->lcd = new QLCDNumber(this);
    this->slider = new QSlider(Qt::Horizontal, this);

    // elemek elrendezése layoutba
    this->layout->addWidget(this->label);
    this->layout->addWidget(this->welcome_label);
    this->layout->addWidget(this->button);
    this->layout->addWidget(this->welcome_button);
    this->layout->addWidget(this->hide_button);
    this->layout->addWidget(this->lcd);
    this->layout->addWidget(this->slider);

    // ha a gombra kattint a felhasználó, akkor az applikáció álljon le
    QObject::connect(this->button, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
    QObject::connect(this->welcome_button,SIGNAL(clicked()),this,SLOT(hungarian_text()));
    QObject::connect(this->hide_button,SIGNAL(clicked()),this,SLOT(hide_hun_text()));
    QObject::connect(slider, &QSlider::valueChanged, this, &MainWindow::change_slider_value);

    // az ablak nevének beállítása
    this->setWindowTitle("Quit Button");

    //slider set number
    this->slider->setRange(0,100);
    this->slider->setValue(0);
    change_slider_value(slider->value());

    // jelenítsük meg az elemeket a felületen
    this->window->setLayout(layout);
    this->setCentralWidget(window);
    this->is_pushed = false;
}

void MainWindow :: hungarian_text()
{
    this->is_pushed = true;
    this->welcome_label->setText("HU : Szia GUI Világ!");
    this->hide_button->setText("ON");
}

/*vezessünk be még egy gombot, melynek segítségével az üzenet láthatóságát tudjuk ki-be
 * kapcsolni. Használjuk az isVisible(), hide(), show() metódusokat.*/
void MainWindow :: hide_hun_text()
{
    if (this->is_pushed) {
        this->welcome_label->hide();
        this->hide_button->setText("OFF");
        this->is_pushed = false;
    }
    else {
        this->welcome_label->show();
        this->hide_button->setText("ON");
        this->is_pushed = true;
    }
}

void MainWindow::change_slider_value(int value)
{
    lcd->display(value);
}
