#include "startapplicationwindow.h"

StartApplicationWindow :: StartApplicationWindow( QWidget *parent ) : QMainWindow( parent )
{
    //we create the main window object
    window = new QWidget;

    window->setMinimumSize( 800, 600 );

    //this will be the layout for the textfields
    layout = new QVBoxLayout( window );

    //initializing the textfields
    email_phonenum_textfield = new QLineEdit( window );
    password_textfield = new QLineEdit( window );

    //initialize the button
    sign_in_button = new QPushButton( tr("Sign In"), window );

    //when pushed then shows to create an account
    registration_text_button = new QPushButton( tr("Register"), window );

    //spacers for design
    QWidget *sp1 = new QWidget( window ),
            *sp2 = new QWidget( window ),
            *sp3 = new QWidget( window );

    sp1->setFixedSize( 200,200 );
    sp2->setFixedSize( 3,0 );
    sp3->setFixedSize( 3,0 );

    //set the width, the text, and style for the textfields
    email_phonenum_textfield->setFixedWidth( 270 );
    email_phonenum_textfield->setFixedHeight( 25 );
    email_phonenum_textfield->setPlaceholderText( tr(" email or phone number") );
    email_phonenum_textfield->setStyleSheet( tr("QLineEdit:focus { border: none; }") );
    email_phonenum_textfield->setStyleSheet( tr("background-color: #212121; border-radius: 12px;") );

    password_textfield->setFixedWidth( 270 );
    password_textfield->setFixedHeight( 25 );
    password_textfield->setPlaceholderText( tr(" password") );
    password_textfield->setStyleSheet( tr("QLineEdit:focus { border: none; }") );
    password_textfield->setStyleSheet( tr("background-color: #212121; border-radius: 12px;") );

    sign_in_button->setFixedWidth( 70 );
    sign_in_button->setFixedHeight( 30 );
    sign_in_button->setStyleSheet( tr("background-color: #21A8B0; border-radius: 15px; font-size: 13px;") );

    registration_text_button->setStyleSheet( tr("color: #04D3BB; font-size: 13px; border: none") );

    //add the items to the layout, ligning everything in center,sp1 is adding a space to lower the textfields
    layout->addWidget( sp1, 0, Qt :: AlignCenter );
    layout->addWidget( email_phonenum_textfield );
    layout->addWidget( password_textfield );
    layout->addWidget( sign_in_button, 0, Qt :: AlignCenter );
    layout->addWidget( registration_text_button, 0, Qt :: AlignCenter );
    layout->setAlignment( Qt :: AlignCenter );


    //setting the slot for the sign in button
    QObject :: connect( sign_in_button, &QPushButton :: clicked, [&]() {
        QString email      = email_phonenum_textfield->text(),
                password   = password_textfield->text() ;
        if ( email.isEmpty() ) {
            email_phonenum_textfield->setPlaceholderText( "please type in your email" );
        }
        if ( password.isEmpty() ) {
            password_textfield->setPlaceholderText( "please enter your password" );
        }
        else {
            signed_in_window = new MainAppWindow( window );
            window->hide();
        }
    });

    QObject :: connect( registration_text_button, &QPushButton :: clicked, [&]() {
        registration_window = new RegistrationWindow( window );
        window->hide();
    });

    window->setStyleSheet( tr("background-color: #040404;") );
    window->setWindowTitle( tr("TextIt") );
    window->setLayout( layout );
    window->show();
}

StartApplicationWindow :: ~StartApplicationWindow()
{
    //this->deleteLater();
}
