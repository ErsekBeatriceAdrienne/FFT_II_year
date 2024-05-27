#include "downloader.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Downloader downloader;
    downloader.show();

    return app.exec();
}
