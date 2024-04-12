#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow :: MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //1.
    //QObject::connect(ui->convert_button,SIGNAL(clicked()),this,SLOT(convert()));

    //2.
    QStringList bases;
    bases << "10";
    ui->bases_box->addItems(bases);

    ui->result_text->hide();
    ui->label_3->hide();
    QObject::connect(ui->convert_button,SIGNAL(clicked()),this,SLOT(convert_1()));
}

MainWindow :: ~MainWindow()
{
    delete ui;
}

/*Írjunk egy GUI programot, mely egy 10-es számrendszerben megadott számot tetszőleges számrendszerbe alakít át.
 * Karakterlánc -> szám átalakításra használjuk a int QString::toInt(bool *ok = nullptr, int base = 10) const és
 * QString QString::number(int n, int base = 10) függvényeket. Ha az átalakítás nem sikeres, az eredmény mezőben
 *  jelenítsünk meg egy hibaüzenetet. Minta az elkészítendő felületre:*/
void MainWindow :: convert()
{
    QString number1 = ui->number_text->text();
    //int base = ui->base_text->text().toInt();

    bool conversionOK;
    //int number_ = number1.toInt(&conversionOK, base);

    if (conversionOK) {
        //ui->result_text->setText(QString::number(number_, 10));
    }
    else {
        //ui->result_text->setText("Invalid input");
    }
}


/*Módosítsuk az előző programot úgy, hogy a számrendszert egy legördülő menüből (QComboBox, dokumentáció itt)
 * kelljen kiválasztani. Az eredmény címke (label) és mező (field) csak akkor legyen látható, ha van helyes eredmény.
 *  A hibaüzenet egy felugró ablakban jelenjen meg (QMessageBox::critical, dokumentáció itt).*/
void MainWindow::convert_1()
{
    QString number1 = ui->number_text->text();
    int base = ui->bases_box->currentText().toInt();

    bool conversionOK;
    int number_ = number1.toInt(&conversionOK, base);

    if (conversionOK) {
        ui->result_text->setText(QString::number(number_, 10));
        ui->result_text->show();
        ui->label_3->show();
    }
    else {
        QMessageBox::critical(this,"Error","Invalid input");
    }
}
