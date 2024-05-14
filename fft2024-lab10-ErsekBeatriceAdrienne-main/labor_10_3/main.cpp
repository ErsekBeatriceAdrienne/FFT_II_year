#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QTimer>
#include <Windows.h>

static float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks) {
    static unsigned long long _previousTotalTicks = 0;
    static unsigned long long _previousIdleTicks = 0;

    unsigned long long totalTicksSinceLastTime = totalTicks - _previousTotalTicks;
    unsigned long long idleTicksSinceLastTime = idleTicks - _previousIdleTicks;

    float ret = 1.0f - ((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime) / totalTicksSinceLastTime : 0);

    _previousTotalTicks = totalTicks;
    _previousIdleTicks = idleTicks;
    return ret;
}

static unsigned long long FileTimeToInt64(const FILETIME &ft) {
    return (((unsigned long long)(ft.dwHighDateTime)) << 32) | ((unsigned long long)ft.dwLowDateTime);
}

float GetCPULoad() {
    FILETIME idleTime, kernelTime, userTime;
    return GetSystemTimes(&idleTime, &kernelTime, &userTime) ? CalculateCPULoad(FileTimeToInt64(idleTime), FileTimeToInt64(kernelTime) + FileTimeToInt64(userTime)) : -1.0f;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    QVBoxLayout *layout = new QVBoxLayout(&window);

    QProgressBar *cpuProgressBar = new QProgressBar(&window);
    cpuProgressBar->setRange(0, 100); // CPU kihasználtság 0-100%-ig
    cpuProgressBar->setValue(0); // Kezdetben 0%-on

    layout->addWidget(cpuProgressBar);
    window.setLayout(layout);

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&cpuProgressBar]() {
        float cpuLoad = GetCPULoad();
        if (cpuLoad >= 0) {
            int cpuPercentage = static_cast<int>(cpuLoad * 100); // Százalékos érték
            cpuProgressBar->setValue(cpuPercentage); // CPU kihasználtság beállítása
        }
    });
    timer.start(1000); // Minden másodpercben frissítjük

    window.show();
    return app.exec();
}
