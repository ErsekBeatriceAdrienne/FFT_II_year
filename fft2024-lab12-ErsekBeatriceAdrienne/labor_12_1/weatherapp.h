#ifndef WEATHERAPP_H
#define WEATHERAPP_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QPixmap>
#include <QTimer>

class WeatherApp : public QWidget
{
    Q_OBJECT
public:
    WeatherApp(QWidget *parent = nullptr);

private slots:
    void fetchWeatherData();
    void handleNetworkReply(QNetworkReply *reply);

private:
    QVBoxLayout *layout;
    QLabel *temperatureLabel;
    QLabel *timeLabel;
    QLabel *humidityLabel;
    QLabel *feelsLikeLabel;
    QLabel *weatherIconLabel;
    QNetworkAccessManager *networkManager;
};

#endif // WEATHERAPP_H
