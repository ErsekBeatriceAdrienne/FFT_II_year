#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSlider>
#include <QLCDNumber>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    QWidget *window;
    QLabel *label, *welcome_label;
    // egy új gombbal, amelyre ha rákattintunk, akkor magyarul is kiírja
    // a köszöntő üzenetet (használjuk a QLabel setText() metódusát)
    QPushButton *button, *welcome_button, *hide_button;
    QVBoxLayout *layout;
    //to know when button is pushed
    bool is_pushed;
    QSlider *slider;
    QLCDNumber *lcd;

private slots:
    void hungarian_text();
    void hide_hun_text();
    void change_slider_value(int value);
};

#endif // MAINWINDOW_H
