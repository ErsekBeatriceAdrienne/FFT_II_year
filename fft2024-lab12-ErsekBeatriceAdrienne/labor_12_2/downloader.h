#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QApplication>
#include <QWidget>
#include <QFileDialog>
#include <QFile>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QProgressBar>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>

class Downloader : public QWidget
{
    Q_OBJECT
public:
    Downloader(QWidget *parent = nullptr);

private slots:
    void startDownload();

    void updateProgress(qint64 bytesRead, qint64 totalBytes);
    void downloadFinished(QNetworkReply *reply);

private:
    QLineEdit *urlLineEdit;
    QPushButton *downloadButton;
    QProgressBar *progressBar;
    QNetworkAccessManager *networkManager;
    QNetworkReply *reply;
};

#endif // DOWNLOADER_H
