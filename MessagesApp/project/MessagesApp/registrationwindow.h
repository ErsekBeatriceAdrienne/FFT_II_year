#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QPoint>
#include <QLabel>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QLineEdit>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFileDialog>

//file, save account
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>

class RegistrationWindow : public QMainWindow
{
    Q_OBJECT

public:
    RegistrationWindow( QWidget *parent = nullptr );
    void save_account( const QString &filename );

private:
    QWidget     *window;

    QLineEdit   *first_name_text, *last_name_text,
                *email_text, *phone_number_text;

    QVBoxLayout *layout,
                *bottom_layout,
                *top_label_layout;
    QHBoxLayout *top_layout;

    QLabel      *create_account_label,
                *image_label;

    QPushButton *upload_image_button,
                *back_to_main_button,
                *create_account_button;
};

#endif // REGISTRATIONWINDOW_H
