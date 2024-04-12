#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
        setWindowTitle("CSV Viewer");
        setupMenuBar();
        setupTableWidget();
    }

private slots:
    void openFile()
    {
        QString filePath = QFileDialog::getOpenFileName(this, tr("Open CSV File"), "", tr("CSV Files (*.csv)"));
        if (filePath.isEmpty())
            return;

        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("Error"), tr("Could not open file."));
            return;
        }

        QTextStream in(&file);
        QStringList header = in.readLine().split(',');
        tableWidget->setColumnCount(header.size());
        tableWidget->setHorizontalHeaderLabels(header);

        int row = 0;
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList fields = line.split(',');
            if (fields.size() != header.size())
            {
                QMessageBox::warning(this, tr("Error"), tr("Invalid CSV format."));
                tableWidget->clear();
                return;
            }
            tableWidget->insertRow(row);
            for (int column = 0; column < header.size(); ++column)
                tableWidget->setItem(row, column, new QTableWidgetItem(fields[column]));
            ++row;
        }

        file.close();
    }

private:
    void setupMenuBar()
    {
        QMenu *fileMenu = menuBar()->addMenu(tr("File"));
        QAction *openAction = new QAction(tr("Open File..."), this);
        connect(openAction, &QAction::triggered, this, &MainWindow::openFile);
        fileMenu->addAction(openAction);
    }

    void setupTableWidget()
    {
        tableWidget = new QTableWidget(this);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); // Disable editing
        setCentralWidget(tableWidget);
    }

    QTableWidget *tableWidget;


};

#endif // MAINWINDOW_H
