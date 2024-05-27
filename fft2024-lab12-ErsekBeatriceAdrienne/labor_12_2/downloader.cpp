#include "downloader.h"
#include "ui_downloader.h"

Downloader :: Downloader(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    urlLineEdit = new QLineEdit(this);
    urlLineEdit->setPlaceholderText("Enter download URL");
    layout->addWidget(urlLineEdit);

    downloadButton = new QPushButton("Download", this);
    connect(downloadButton, &QPushButton::clicked, this, &Downloader::startDownload);
    layout->addWidget(downloadButton);

    progressBar = new QProgressBar(this);
    progressBar->setMinimum(0);
    progressBar->setMaximum(100);
    layout->addWidget(progressBar);

    setLayout(layout);

    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, &QNetworkAccessManager::finished, this, &Downloader::downloadFinished);
}

void Downloader :: startDownload()
{
    QString urlString = urlLineEdit->text();
    QUrl url(urlString);
    if (!url.isValid() || !url.scheme().startsWith("http")) {
        QMessageBox::critical(this, "Error", "Invalid URL");
        return;
    }

    QNetworkRequest request(url);
    reply = networkManager->get(request);

    connect(reply, &QNetworkReply::downloadProgress, this, &Downloader::updateProgress);
}

void Downloader :: updateProgress(qint64 bytesRead, qint64 totalBytes)
{
    if (totalBytes <= 0)
        return;

    int progress = static_cast<int>((bytesRead * 100) / totalBytes);
    progressBar->setValue(progress);
}

void Downloader :: downloadFinished(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QMessageBox::information(this, "Success", "Download completed successfully!");
    } else {
        QMessageBox::critical(this, "Error", "Download failed!");
    }

    reply->deleteLater();
}
