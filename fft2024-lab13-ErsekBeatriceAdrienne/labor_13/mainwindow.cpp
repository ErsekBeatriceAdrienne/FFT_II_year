#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), numThreads(std::thread::hardware_concurrency()) {

    selectFileButton = new QPushButton("Select File", this);
    processButton = new QPushButton("Process", this);
    progressBar = new QProgressBar(this);
    resultLabel = new QLabel("Result will be shown here.", this);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(selectFileButton);
    layout->addWidget(processButton);
    layout->addWidget(progressBar);
    layout->addWidget(resultLabel);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(selectFileButton, &QPushButton::clicked, this, &MainWindow::onSelectFile);
    connect(processButton, &QPushButton::clicked, this, &MainWindow::onProcess);

    resetUI();
}

MainWindow::~MainWindow() {
    for (QThread *thread : threads) {
        thread->quit();
        thread->wait();
        delete thread;
    }
}

void MainWindow::onSelectFile() {
    filePath = QFileDialog::getOpenFileName(this, "Select Number File", "", "Text Files (*.txt)");
    if (!filePath.isEmpty()) {
        // Load numbers from file
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            numbers.clear();
            while (!in.atEnd()) {
                QString line = in.readLine();
                numbers.push_back(line.toInt());
            }
            file.close();
            enableUI(true);
        }
    }
}

void MainWindow::onProcess() {
    enableUI(false);
    progressBar->setValue(0);
    progressBar->setMaximum(numbers.size());

    // Initialize threads and start processing
    int chunkSize = numbers.size() / numThreads;
    for (int i = 0; i < numThreads; ++i) {
        int start = i * chunkSize;
        int end = (i == numThreads - 1) ? numbers.size() : start + chunkSize;
        std::vector<int> chunk(numbers.begin() + start, numbers.begin() + end);

        WorkerThread *thread = new WorkerThread(chunk);
        connect(thread, &WorkerThread::progressUpdated, this, &MainWindow::onProgressUpdated);
        connect(thread, &WorkerThread::newLongestPathFound, this, &MainWindow::onNewLongestPathFound);
        threads.push_back(thread);
        thread->start();
    }
}

void MainWindow::onProgressUpdated(int value) {
    progressBar->setValue(progressBar->value() + value);
}

void MainWindow::onNewLongestPathFound(int length, const std::vector<int>& path) {
    resultLabel->setText("New longest path found with length: " + QString::number(length));
}

void MainWindow::resetUI() {
    progressBar->setValue(0);
    resultLabel->setText("Result will be shown here.");
    enableUI(false);
    selectFileButton->setEnabled(true);
}

void MainWindow::enableUI(bool enable) {
    processButton->setEnabled(enable);
    selectFileButton->setEnabled(true);
}
