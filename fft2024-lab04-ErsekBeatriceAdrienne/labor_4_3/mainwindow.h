#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "magicslider.h"
#include "rewardbagdisplayer.h"
#include <QVBoxLayout>
#include <QWidget>
#include <QRandomGenerator>
#include <QGridLayout>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QWidget *window;
    MagicSlider *s1;
    RewardBagDisplayer *r1,*r2,*r3,*r4,*r5,*r6,*r7,*r8,*r9,*r10,*r11,*r12;
    QVBoxLayout *layout;
    QGridLayout *grid;

private slots:
    void change_value();

};

#endif // MAINWINDOW_H
