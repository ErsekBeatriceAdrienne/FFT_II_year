#include "workerthread.h"

WorkerThread::WorkerThread(const std::vector<int>& numbers, QObject *parent)
    : QThread(parent), numbers(numbers) {}

void WorkerThread::run() {
    int longestLength = 0;
    std::vector<int> longestPath;
    for (size_t i = 0; i < numbers.size(); ++i) {
        int n = numbers[i];
        std::vector<int> path;
        int length = 0;
        while (n != 1) {
            path.push_back(n);
            if (n % 2 == 0) {
                n /= 2;
            } else {
                n = 3 * n + 1;
            }
            length++;
        }
        path.push_back(1); // add the final 1
        length++;
        if (length > longestLength) {
            longestLength = length;
            longestPath = path;
            emit newLongestPathFound(length, path);
        }
        if (i % 100 == 0) {
            emit progressUpdated(100);
        }
    }
    emit progressUpdated(numbers.size() % 100); // Ensure the last part is also reported
}

int WorkerThread::collatzLength(int n) {
    int length = 1;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
        length++;
    }
    return length;
}
