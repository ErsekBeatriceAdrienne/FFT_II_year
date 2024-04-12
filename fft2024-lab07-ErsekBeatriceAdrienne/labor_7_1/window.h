#ifndef WINDOW_H
#define WINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QFileDialog>
#include <QDir>
#include <QDirIterator>
#include <QFile>
#include <QTextStream>
#include <QProgressDialog>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>

class Window : public QMainWindow {
public:
    Window(QWidget *parent = nullptr) : QMainWindow(parent) {
        setWindowTitle("File Search");

        centralWidget = new QWidget(this);
        setCentralWidget(centralWidget);

        layout = new QVBoxLayout(centralWidget);

        selectDirectoryButton = new QPushButton("Select Directory", this);
        connect(selectDirectoryButton, &QPushButton::clicked, this, &Window::selectDirectory);
        layout->addWidget(selectDirectoryButton);

        searchLineEdit = new QLineEdit(this);
        searchLineEdit->setPlaceholderText("Search String");
        layout->addWidget(searchLineEdit);

        searchButton = new QPushButton("Search", this);
        connect(searchButton, &QPushButton::clicked, this, &Window::search);
        layout->addWidget(searchButton);

        tableWidget = new QTableWidget(this);
        tableWidget->setColumnCount(2);
        QStringList headers;
        headers << "File Name" << "File Size";
        tableWidget->setHorizontalHeaderLabels(headers);
        layout->addWidget(tableWidget);

        progressDialog = new QProgressDialog("Searching files...", "Cancel", 0, 100, this);
        progressDialog->setWindowModality(Qt::WindowModal);
    }

private slots:
    void selectDirectory() {
        QString directoryPath = QFileDialog::getExistingDirectory(this, "Select Directory", QDir::currentPath());
        if (!directoryPath.isEmpty())
            selectedDirectory = directoryPath;
    }

    void search() {
        QString searchString = searchLineEdit->text();
        tableWidget->clearContents();
        tableWidget->setRowCount(0);

        if (selectedDirectory.isEmpty()) {
            QMessageBox::warning(this, "Warning", "Please select a directory first.");
            return;
        }

        progressDialog->show();
        qApp->processEvents();

        searchFiles(selectedDirectory, searchString);

        progressDialog->hide();
    }

private:
    QWidget *centralWidget;
    QVBoxLayout *layout;
    QPushButton *selectDirectoryButton;
    QLineEdit *searchLineEdit;
    QPushButton *searchButton;
    QTableWidget *tableWidget;
    QProgressDialog *progressDialog;
    QString selectedDirectory;

    /* Ez ha a fajl tartalmaba akarunk keresni szavat
    void searchFiles(const QString& directoryPath, const QString& searchString) {
        QDirIterator it(directoryPath, QDir::Files | QDir::NoSymLinks, QDirIterator::Subdirectories);
        int rowCount = 0;

        while (it.hasNext()) {
            it.next();
            QFile file(it.filePath());
            if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream in(&file);
                QString fileContent = in.readAll();
                if (searchString.isEmpty() || fileContent.contains(searchString)) {
                    tableWidget->insertRow(rowCount);
                    QTableWidgetItem* fileNameItem = new QTableWidgetItem(it.fileName());
                    QTableWidgetItem* fileSizeItem = new QTableWidgetItem(QString::number(file.size()));
                    tableWidget->setItem(rowCount, 0, fileNameItem);
                    tableWidget->setItem(rowCount, 1, fileSizeItem);
                    rowCount++;
                }
                file.close();
            }
        }
    }*/

    void searchFiles(const QString& directoryPath, const QString& searchString) {
        QDirIterator it(directoryPath, QDir::Files | QDir::NoSymLinks, QDirIterator::Subdirectories);
        int rowCount = 0;

        while (it.hasNext()) {
            it.next();
            QString fileName = it.fileName();
            if (searchString.isEmpty() || fileName.contains(searchString, Qt::CaseInsensitive)) {
                tableWidget->insertRow(rowCount);
                QTableWidgetItem* fileNameItem = new QTableWidgetItem(fileName);
                QTableWidgetItem* fileSizeItem = new QTableWidgetItem(QString::number(it.fileInfo().size()));
                tableWidget->setItem(rowCount, 0, fileNameItem);
                tableWidget->setItem(rowCount, 1, fileSizeItem);
                rowCount++;
            }
        }
    }
};


#endif // WINDOW_H
