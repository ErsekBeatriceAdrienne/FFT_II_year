#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_plusb_clicked();

    void on_minusb_clicked();

    void on_multiplyb_clicked();

    void on_divideb_clicked();

private:
    Ui :: MainWindow *ui;
};

#endif // MAINWINDOW_H
