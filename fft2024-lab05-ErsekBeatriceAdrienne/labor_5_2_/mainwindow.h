#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QFile>
#include <QPushButton>
#include <QEvent>
#include <QKeyEvent>
#include <QGridLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QLineEdit *name_lineedit, *phone_number_lineedit;
    QVBoxLayout *layout;
    QPushButton *save_button;

    bool eventFilter(QObject *obj, QEvent *event) override {
        if (obj == phone_number_lineedit && event->type() == QEvent::KeyPress) {
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
            if (!keyEvent->text().isEmpty() && !keyEvent->text().at(0).isDigit())
                return true; // Ignore non-digit key presses
        }
        return QObject::eventFilter(obj, event);
    }

private slots:
    void save_data();

};

#endif // MAINWINDOW_H
