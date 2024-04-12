#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/*#include <QMainWindow>
#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QTime>
#include <QDebug>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent)
    {
        setWindowTitle("Motivation App");
        resize(400, 200);

        loadQuotes();
        selectRandomQuote();

        quoteLabel = new QLabel(currentQuote, this);
        quoteLabel->setAlignment(Qt::AlignCenter);

        generateButton = new QPushButton("Generate Quote", this);
        connect(generateButton, &QPushButton::clicked, this, &MainWindow::selectRandomQuote);

        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(quoteLabel);
        layout->addWidget(generateButton);

        QWidget *centralWidget = new QWidget(this);
        centralWidget->setLayout(layout);
        setCentralWidget(centralWidget);
    }

private slots:
    void selectRandomQuote()
    {
        // Prevent selecting the same quote consecutively
        int newIndex = currentIndex;
        while (newIndex == currentIndex)
            newIndex = qrand() % quotes.size();
        currentIndex = newIndex;

        currentQuote = quotes[currentIndex];
        quoteLabel->setText(currentQuote);
    }

    void loadQuotes()
    {
        QFile file(":/quotes.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Could not open quotes file.";
            return;
        }

        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine().trimmed();
            if (!line.isEmpty())
                quotes.append(line);
        }

        file.close();
    }

private:
    QList<QString> quotes;
    QString currentQuote;
    int currentIndex = -1;
    QLabel *quoteLabel;
    QPushButton *generateButton;
};*/

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <QTime>
#include <QMessageBox>
#include <QtGlobal>
#include <QFileDialog>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) : QWidget(parent)
    {
        setWindowTitle(tr("Motivational Quotes"));

        QVBoxLayout *layout = new QVBoxLayout(this);

        quoteLabel = new QLabel(this);
        quoteLabel->setAlignment(Qt::AlignCenter);
        quoteLabel->setStyleSheet("color: black");
        layout->addWidget(quoteLabel);

        generateButton = new QPushButton(tr("Generate New Quote"), this);
        connect(generateButton, &QPushButton::clicked, this, &MainWindow::generateNewQuote);
        layout->addWidget(generateButton);

        openFileButton = new QPushButton(tr("Open File..."), this);
        connect(openFileButton, &QPushButton::clicked, this, &MainWindow::openFile);
        layout->addWidget(openFileButton);

        setLayout(layout);

        srand(QTime::currentTime().msec());
    }

private slots:

    void openFile()
    {
        QString filePath = QFileDialog::getOpenFileName(this, tr("Open Quotes File"), "", tr("Text Files (*.txt)"));
        if (filePath.isEmpty())
            return;

        loadQuotesFromFile(filePath);
        generateNewQuote(); // Az alkalmazás indításakor azonnal generálunk egy idézetet
    }

    void generateNewQuote()
    {
        // Ellenőrizzük, hogy az összes idézetet már megjelenítettük-e
        if (usedQuotes.size() == quotes.size())
        {
            QMessageBox::information(this, tr("All quotes used"), tr("You have used all available quotes. Restart the application to use them again."));
            return;
        }

        // Válasszunk egy új idézetet, amelyet még nem használtunk
        QString quote;
        do {
            quote = quotes.at(rand() % quotes.size());
        } while (usedQuotes.contains(quote));

        quoteLabel->setText(quote);
        usedQuotes.insert(quote);
    }

private:

    void loadQuotesFromFile(const QString &filePath)
    {
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("Error"), tr("Could not open quotes file."));
            return;
        }

        QTextStream in(&file);
        quotes.clear(); // Töröljük az előző idézeteket
        usedQuotes.clear(); // Töröljük az előzőleg használt idézeteket
        while (!in.atEnd())
        {
            QString line = in.readLine().trimmed(); // A szóközök eltávolítása a sor végéről
            if (!line.isEmpty())
                quotes.append(line);
        }

        file.close();
    }

    QLabel *quoteLabel;
    QPushButton *generateButton;
    QPushButton *openFileButton;
    QStringList quotes;
    QSet<QString> usedQuotes;
};

#endif // MAINWINDOW_H
