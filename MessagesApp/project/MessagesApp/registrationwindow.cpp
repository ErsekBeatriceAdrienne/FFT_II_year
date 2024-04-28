#include "registrationwindow.h"

RegistrationWindow :: RegistrationWindow(QWidget *parent) : QMainWindow{parent}
{
    //setting the window to same size as previous
    window = new QWidget;
    window->setWindowTitle( tr("TextIt") );
    window->setMinimumSize( 800, 600 );
    window->resize( parentWidget()->size() );
    window->setStyleSheet( tr("background-color: #040404;") );

    //initializing the textfields for the data collection
    top_label_layout = new QVBoxLayout;
    layout = new QVBoxLayout;
    bottom_layout = new QVBoxLayout;
    top_layout = new QHBoxLayout;

    //showing the image
    image_label = new QLabel;
    image_label->setFixedSize( 200, 200 );

    //buttons
    upload_image_button = new QPushButton;
    back_to_main_button = new QPushButton( tr("< Back") );
    back_to_main_button->setStyleSheet( tr("color: #04D3BB; background-color: none") );
    create_account_button = new QPushButton("Save");
    create_account_button->setStyleSheet( tr("color: #04D3BB; background-color: none") );

    //title of the window
    create_account_label = new QLabel( tr("Create Account") );
    create_account_label->setStyleSheet( tr("color: #04D3BB; font-size: 17") );

    //setting the textfields
    first_name_text = new QLineEdit;
    first_name_text->setPlaceholderText( tr("first name") );
    first_name_text->setFixedWidth( 270 );
    first_name_text->setFixedHeight( 25 );
    first_name_text->setStyleSheet( tr("QLineEdit:focus { border: none; }") );
    first_name_text->setStyleSheet( tr("background-color: #212121; border-radius: 12px;") );

    last_name_text = new QLineEdit;
    last_name_text->setPlaceholderText( tr("last name") );
    last_name_text->setFixedWidth( 270 );
    last_name_text->setFixedHeight( 25 );
    last_name_text->setStyleSheet( tr("QLineEdit:focus { border: none; }") );
    last_name_text->setStyleSheet( tr("background-color: #212121; border-radius: 12px;") );

    email_text = new QLineEdit;
    email_text->setPlaceholderText( tr("email") );
    email_text->setFixedWidth( 270 );
    email_text->setFixedHeight( 25 );
    email_text->setStyleSheet( tr("QLineEdit:focus { border: none; }") );
    email_text->setStyleSheet( tr("background-color: #212121; border-radius: 12px;") );

    phone_number_text = new QLineEdit;
    phone_number_text->setPlaceholderText( tr("phone number") );
    phone_number_text->setFixedWidth( 270 );
    phone_number_text->setFixedHeight( 25 );
    phone_number_text->setStyleSheet( tr("QLineEdit:focus { border: none; }") );
    phone_number_text->setStyleSheet( tr("background-color: #212121; border-radius: 12px;") );

    //adding the textfields to the layout
    top_label_layout->addWidget( back_to_main_button );
    top_label_layout->addWidget( create_account_label, 0, Qt :: AlignCenter );
    top_layout->addWidget( first_name_text );
    top_layout->addWidget( last_name_text );

    QHBoxLayout *emailLayout = new QHBoxLayout;
    emailLayout->addWidget(email_text);

    QHBoxLayout *phoneNumberLayout = new QHBoxLayout;
    phoneNumberLayout->addWidget(phone_number_text);

    bottom_layout->addWidget( email_text, 0, Qt :: AlignCenter );
    bottom_layout->addWidget( phone_number_text, 0, Qt :: AlignCenter );
    bottom_layout->addWidget( upload_image_button );
    bottom_layout->addWidget( image_label );
    bottom_layout->addWidget(create_account_button);

    top_layout->setAlignment( Qt :: AlignCenter );
    bottom_layout->setAlignment( Qt :: AlignCenter );

    QObject :: connect( upload_image_button, &QPushButton :: clicked, [&]() {
        QString fileName = QFileDialog :: getOpenFileName( window, tr("Select Image"), "", tr("Image Files (*.png *.jpg *.bmp)") );
        if ( !fileName.isEmpty() ) {
            QPixmap pixmap( fileName );
            image_label->setPixmap( pixmap.scaledToWidth( image_label->width(), Qt::SmoothTransformation) );
        }
    });

    QObject :: connect( back_to_main_button, &QPushButton::clicked, [&]() {
        window->hide();
        parentWidget()->show();
    });

    QObject :: connect( create_account_button, &QPushButton::clicked, [&]() {
         save_account( "users.txt" );
    });

    //it shows the new window exactly where the parent was
    QPoint position = parentWidget()->pos();
    window->move( position );

    //add multiple layouts to one
    layout->addLayout( top_label_layout );
    layout->addLayout( top_layout );
    layout->addLayout( bottom_layout );

    window->setLayout( layout );
    window->show();
}

void RegistrationWindow :: save_account( const QString &filename )
{
    QFile file( filename );
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);

        QString fname = first_name_text->text(), lname = last_name_text->text();

        stream << fname << ", " << lname ;
        file.close();
        QMessageBox::information(this, "Saved", "Account created");
    } else {
        qDebug() << "Error at saving the account";
    }
}
