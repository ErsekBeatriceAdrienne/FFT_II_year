#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow :: MainWindow(QWidget *parent) : QMainWindow(parent)
{
    QWidget *window = new QWidget;
    name_lineedit = new QLineEdit(window);
    phone_number_lineedit = new QLineEdit(window);
    layout = new QVBoxLayout(window);

    QLabel *name = new QLabel("Teljes név");
    layout->addWidget(name);
    layout->addWidget(name_lineedit);

    QLabel *phone = new QLabel("Telefonszám");
    layout->addWidget(phone);
    layout->addWidget(phone_number_lineedit);

    save_button = new QPushButton("Save data");
    layout->addWidget(save_button);

    QObject :: connect(save_button, &QPushButton :: clicked, this, &MainWindow :: save_data);
    //event filter
    phone_number_lineedit->installEventFilter(this);

    window->setLayout(layout);
    window->setWindowTitle("Felhasználó");
    window->resize(400, 450);

    window->show();
}

void MainWindow :: save_data()
{
    QString name = name_lineedit->text();
    QString phoneNumber = phone_number_lineedit->text();

    QFile file("contact.txt");
    if (file.open(QIODevice :: WriteOnly | QIODevice :: Append | QIODevice :: Text)) {
        QTextStream out(&file);
        out << "Name : " << name << ", tel : " << phoneNumber << Qt :: endl;
        file.close();
    }
}

MainWindow :: ~MainWindow() {}
