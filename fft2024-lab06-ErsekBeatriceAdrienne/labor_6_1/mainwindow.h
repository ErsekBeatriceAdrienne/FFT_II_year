
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFile>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QMainWindow>
#include <QRandomGenerator>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QRandomGenerator>
#include <QPalette>

class MainWindow : public QWidget {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr) : QWidget(parent), attempts(5) {
        setupUi();
        startNewGame();
    }

private slots:
    void checkLetter() {
        QString guess = guessLineEdit->text().toLower();
        guessLineEdit->clear();

        if (guess.isEmpty() || guess.size() > 1) {
            QMessageBox::information(this, "Invalid Input", "Please enter a single letter.");
            return;
        }

        if (usedLetters.contains(guess)) {
            QMessageBox::information(this, "Already Used", "You have already guessed this letter.");
            return;
        }

        usedLetters.append(guess);

        bool found = false;
        for (int i = 0; i < secretWord.size(); ++i) {
            if (secretWord.at(i) == guess.at(0)) {
                displayedWord.replace(i, 1, guess);
                found = true;
            }
        }

        if (!found) {
            attempts--;
            hangmanLabel->setText(hangman.at(5 - attempts));
        }

        updateDisplayedWord();

        if (displayedWord == secretWord) {
            QMessageBox::information(this, "Congratulations!", "You guessed the word: " + secretWord);
            startNewGame();
        } else if (attempts == 0) {
            QMessageBox::information(this, "Game Over", "You ran out of attempts. The word was: " + secretWord);
            startNewGame();
        }
    }

    void startNewGame() {
        secretWord = words.at(QRandomGenerator::global()->bounded(words.size()));
        usedLetters.clear();
        attempts = 5;
        hangmanLabel->setText("");
        displayedWord = QString(secretWord.size(), '_');
        updateDisplayedWord();
    }

private:
    void setupUi() {
        QVBoxLayout *mainLayout = new QVBoxLayout(this);

        hangmanLabel = new QLabel(this);
        hangmanLabel->setAlignment(Qt::AlignCenter);
        hangmanLabel->setStyleSheet("color: red;");
        mainLayout->addWidget(hangmanLabel);

        displayedWordLabel = new QLabel(this);
        displayedWordLabel->setAlignment(Qt::AlignCenter);
        mainLayout->addWidget(displayedWordLabel);

        guessLineEdit = new QLineEdit(this);
        guessLineEdit->setPlaceholderText("Enter a letter");
        mainLayout->addWidget(guessLineEdit);

        QPushButton *guessButton = new QPushButton("Guess", this);
        connect(guessButton, &QPushButton::clicked, this, &MainWindow::checkLetter);
        guessButton->setStyleSheet("backgroundColor: green;");
        mainLayout->addWidget(guessButton);

        setLayout(mainLayout);
    }

    void updateDisplayedWord() {
        QString displayed;
        for (int i = 0; i < displayedWord.size(); ++i) {
            if (displayedWord.at(i) == '_') displayed += "_ ";
            else {
                displayed += displayedWord.at(i);
                displayed += " ";
            }
        }
        displayedWordLabel->setText(displayed);
    }

    QStringList words = {
        "Kutya",
        "Szivar",
        "Paprika",
        "Tó",
        "Lámpa",
        "Eperfagyi",
        "Kalap",
        "Kerék",
        "Tánc",
        "Gyertya",
        "Bicikli",
        "Gömbölyű",
        "Kéz",
        "Kukac",
        "Bakancs",
        "Párna",
        "Hegy",
        "Szék",
        "Könyv",
        "Tükör",
        "Papír",
        "Gyümölcs",
        "Hajó",
        "Macska",
        "Víz",
        "Híd",
        "Szivacs",
        "Fű",
        "Képeslap",
        "Bőr"
    };
    QString secretWord;
    QString displayedWord;
    QStringList hangman = {"", "O\n", "|O\n", "|/\n", "|/|\n", "|/|\\\n"};
    QList<QString> usedLetters;
    int attempts;
    QLabel *hangmanLabel;
    QLabel *displayedWordLabel;
    QLineEdit *guessLineEdit;
};

#endif // MAINWINDOW_H
