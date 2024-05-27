#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>
#include <vector>

class WorkerThread : public QThread {
    Q_OBJECT

public:
    WorkerThread(const std::vector<int>& numbers, QObject *parent = nullptr);

signals:
    void progressUpdated(int value);
    void newLongestPathFound(int length, const std::vector<int>& path);

protected:
    void run() override;

private:
    int collatzLength(int n);
    std::vector<int> numbers;
};

#endif // WORKERTHREAD_H
