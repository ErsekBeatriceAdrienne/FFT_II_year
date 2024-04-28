#include "mainappwindow.h"

MainAppWindow :: MainAppWindow( QWidget *parent ) : QMainWindow( parent )
{
    //setting the window to same size as previous
    window = new QWidget;
    window->setWindowTitle( tr("TextIt") );
    window->setMinimumSize( 800, 600 );
    window->resize( parentWidget()->size() );
    window->setStyleSheet( tr("background-color: #040404;") );

    //it shows the new window exactly where the parent was
    QPoint position = parentWidget()->pos();
    window->move( position );

    window->show();
}
