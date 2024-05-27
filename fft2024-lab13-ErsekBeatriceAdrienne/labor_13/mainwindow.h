#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QProgressBar>
#include <QPushButton>
#include <QThread>
#include <QVBoxLayout>
#include <QLabel>
#include <vector>
#include <thread>
#include "workerthread.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSelectFile();
    void onProcess();
    void onProgressUpdated(int value);
    void onNewLongestPathFound(int length, const std::vector<int>& path);

private:
    void resetUI();
    void enableUI(bool enable);

    QPushButton *selectFileButton;
    QPushButton *processButton;
    QProgressBar *progressBar;
    QLabel *resultLabel;
    QString filePath;
    std::vector<int> numbers;
    int numThreads;
    std::vector<QThread*> threads;
};

#endif // MAINWINDOW_H
