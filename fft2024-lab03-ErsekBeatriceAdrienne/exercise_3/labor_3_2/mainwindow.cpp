#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->button,SIGNAL(clicked()),this,SLOT(masod_foku()));
    ui->result_text->hide();
    ui->label_4->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*Írjunk egy GUI alkalmazást mely megold egy másodfokú egyenletet. Negatív delta esetében figyelmezteti a felhasználót
 * (QMessageBox::warning segítségével). Minta az elkészítendő felületre:*/
void MainWindow :: masod_foku()
{
    double  a = ui->ax->text().toDouble(),
            b = ui->bx->text().toDouble(),
            c = ui->cx->text().toDouble();

    double delta = (b * b) - (4 * a * c);
    QString d = QString::number(delta);

    if (delta < 0) {
       ui->result_text->setText(d);
        ui->result_text->hide();
        ui->label_4->hide();
       QMessageBox::warning(this,"Error","Not a positive delta");
    }
    else {
        ui->result_text->setText(d);
        ui->result_text->show();
        ui->label_4->show();
    }

}
