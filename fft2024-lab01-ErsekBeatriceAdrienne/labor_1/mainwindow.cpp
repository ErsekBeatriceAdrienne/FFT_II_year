#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow :: MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connecting the button number 1 when pushed
    connect(ui->plusb,SIGNAL(clicked()),this,SLOT(on_plusb_clicked()));
    connect(ui->minusb,SIGNAL(clicked()),this,SLOT(on_minusb_clicked()));
    connect(ui->divideb,SIGNAL(clicked()),this,SLOT(on_divideb_clicked()));
    connect(ui->multiplyb,SIGNAL(clicked()),this,SLOT(on_multiplyb_clicked()));
}

MainWindow :: ~MainWindow()
{
    delete ui;
}


void MainWindow::on_plusb_clicked()
{
    QString n1 = ui->number1->text(),
            n2 = ui->number2->text();
    double dn1 = n1.toDouble(),
           dn2 = n2.toDouble(),
           re = dn1 + dn2;
    ui->result->setText(QString::number(re));
}


void MainWindow::on_minusb_clicked()
{
    QString n1 = ui->number1->text(),
        n2 = ui->number2->text();
    double dn1 = n1.toDouble(),
        dn2 = n2.toDouble(),
        re = dn1 - dn2;
    ui->result->setText(QString::number(re));
}


void MainWindow::on_multiplyb_clicked()
{
    QString n1 = ui->number1->text(),
        n2 = ui->number2->text();
    double dn1 = n1.toDouble(),
        dn2 = n2.toDouble(),
        re = dn1 * dn2;
    ui->result->setText(QString::number(re));
}


void MainWindow::on_divideb_clicked()
{
    QString n1 = ui->number1->text(),
        n2 = ui->number2->text();
    double dn1 = n1.toDouble(),
        dn2 = n2.toDouble(),
        re = dn1 / dn2;
    ui->result->setText(QString::number(re));
}

