#include "weatherapp.h"

WeatherApp :: WeatherApp(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout(this);

    temperatureLabel = new QLabel("Temperature: N/A", this);
    layout->addWidget(temperatureLabel);

    timeLabel = new QLabel("Last update: N/A", this);
    layout->addWidget(timeLabel);

    humidityLabel = new QLabel("Humidity: N/A", this);
    layout->addWidget(humidityLabel);

    feelsLikeLabel = new QLabel("Feels like: N/A", this);
    layout->addWidget(feelsLikeLabel);

    weatherIconLabel = new QLabel(this);
    layout->addWidget(weatherIconLabel);

    networkManager = new QNetworkAccessManager(this);

    connect(networkManager, &QNetworkAccessManager::finished, this, &WeatherApp::handleNetworkReply);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &WeatherApp::fetchWeatherData);
    timer->start(600000); // Fetch weather data every 10 minutes

    setLayout(layout);

    fetchWeatherData();
}

void WeatherApp :: fetchWeatherData()
{
    QNetworkRequest request(QUrl("https://wttr.in/?format=j1"));
    networkManager->get(request);
}

void WeatherApp :: handleNetworkReply(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError)
    {
        qDebug() << "Network error:" << reply->errorString();
        return;
    }

    QByteArray jsonData = reply->readAll();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(jsonData);

    if (!jsonResponse.isNull() && jsonResponse.isObject())
    {
        QJsonObject jsonObject = jsonResponse.object();

        QString temperature = jsonObject["current_condition"].toArray()[0].toObject()["temp_C"].toString();
        QString humidity = jsonObject["current_condition"].toArray()[0].toObject()["humidity"].toString();
        QString feelsLike = jsonObject["current_condition"].toArray()[0].toObject()["FeelsLikeC"].toString();
        QString time = jsonObject["current_condition"].toArray()[0].toObject()["observation_time"].toString();

        temperatureLabel->setText("Temperature: " + temperature + "°C");
        humidityLabel->setText("Humidity: " + humidity + "%");
        feelsLikeLabel->setText("Feels like: " + feelsLike + "°C");
        timeLabel->setText("Last update: " + time);

        QString weatherIconUrl = jsonObject["current_condition"].toArray()[0].toObject()["weatherIconUrl"].toArray()[0].toObject()["value"].toString();
        QPixmap weatherIcon(weatherIconUrl);
        weatherIconLabel->setPixmap(weatherIcon);
    }

    reply->deleteLater();
}
