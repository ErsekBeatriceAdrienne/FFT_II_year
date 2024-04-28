#ifndef MAINAPPWINDOW_H
#define MAINAPPWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QWidget>

class MainAppWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainAppWindow( QWidget *parent = nullptr );

private:
    QWidget *window;

};

#endif // MAINAPPWINDOW_H
