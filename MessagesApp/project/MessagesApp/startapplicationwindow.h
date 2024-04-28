#ifndef STARTAPPLICATIONWINDOW_H
#define STARTAPPLICATIONWINDOW_H

#include <QLabel>
#include <QString>
#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
//dark and light mode
#include <QPalette>
#include "mainappwindow.h"
#include "registrationWindow.h"

class StartApplicationWindow : public QMainWindow
{
    Q_OBJECT

public:

    StartApplicationWindow( QWidget *parent = nullptr );
    ~StartApplicationWindow();

private:
    QWidget     *window;
    QString     backgroundColor;
    QVBoxLayout *layout;
    QPushButton *sign_in_button,
                *registration_text_button;
    QLineEdit   *email_phonenum_textfield,
                *password_textfield;

    //to show
    MainAppWindow       *signed_in_window;
    RegistrationWindow  *registration_window;

};

#endif // STARTAPPLICATIONWINDOW_H
