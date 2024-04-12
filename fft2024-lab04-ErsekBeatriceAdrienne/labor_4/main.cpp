#include "mainwindow.h"

#include <QApplication>

int main (int argc, char *argv[])
{
    /*
     Készítsünk egy nyomógomb (QPushButton) osztályt, mely csak a jobb egérgomb klikkre reagál (például
     nyisson meg egy felugró ablakot, amelyben kiírja, hogy "Jobb klikk"). Teszteljük a működését.
     */
    QApplication a(argc, argv);

    QWidget window;
    QVBoxLayout layout(&window);

    QIPushButton button(&window);
    button.setText("Right click only");
    layout.addWidget(&button);

    window.setLayout(&layout);
    window.show();

    return a.exec();
}
