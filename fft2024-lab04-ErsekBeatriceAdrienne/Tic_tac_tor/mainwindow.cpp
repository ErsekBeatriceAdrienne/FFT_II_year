#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow :: MainWindow(QWidget *parent) : QMainWindow(parent)
{
    initializeBoard();
}

MainWindow :: ~MainWindow() {}

void MainWindow :: initializeBoard()
{
    currentPlayer = Player :: X;
    board = QVector <QVector <Player>> (3, QVector <Player>(3, Player :: None));
    buttons.clear();

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QGridLayout *gridLayout = new QGridLayout(centralWidget);

    for (int row = 0; row < 3; ++row)
    {
        QVector <QPushButton *> rowButtons;
        for (int col = 0; col < 3; ++col)
        {
            QPushButton *button = new QPushButton();
            button->setFixedSize(100, 100);
            gridLayout->addWidget(button, row, col);
            connect(button, &QPushButton :: clicked, this, &MainWindow :: handleButtonClick);
            rowButtons.push_back(button);
        }
        buttons.push_back(rowButtons);
    }
}

void MainWindow :: handleButtonClick()
{
    QPushButton *clickedButton = qobject_cast <QPushButton *> (sender());
    if (!clickedButton)
        return;

    int row = -1, col = -1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (buttons[i][j] == clickedButton) {
                row = i;
                col = j;
                break;
            }
        }
    }

    if (row == -1 || col == -1 || board[row][col] != Player::None)
        return;

    board[row][col] = currentPlayer;
    clickedButton->setText(currentPlayer == Player::X ? "X" : "O");

    checkWinner();

    currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;
}

void MainWindow :: checkWinner()
{
    // Check rows
    for (int row = 0; row < 3; ++row) {
        if (board[row][0] != Player::None && board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
            QMessageBox::information(this, "Winner", currentPlayer == Player::X ? "Player X wins!" : "Player O wins!");
            restartGame();
            return;
        }
    }

    // Check columns
    for (int col = 0; col < 3; ++col) {
        if (board[0][col] != Player::None && board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
            QMessageBox::information(this, "Winner", currentPlayer == Player::X ? "Player X wins!" : "Player O wins!");
            restartGame();
            return;
        }
    }

    // Check diagonals
    if (board[0][0] != Player::None && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        QMessageBox::information(this, "Winner", currentPlayer == Player::X ? "Player X wins!" : "Player O wins!");
        restartGame();
        return;
    }

    if (board[0][2] != Player::None && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        QMessageBox::information(this, "Winner", currentPlayer == Player::X ? "Player X wins!" : "Player O wins!");
        restartGame();
        return;
    }

    // Check for draw
    bool draw = true;
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (board[row][col] == Player::None) {
                draw = false;
                break;
            }
        }
        if (!draw)
            break;
    }

    if (draw) {
        QMessageBox::information(this, "Draw", "It's a draw!");
        restartGame();
        return;
    }
}

void MainWindow :: restartGame()
{
    // Clear board and reset UI
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            board[row][col] = Player::None;
            buttons[row][col]->setText("");
        }
    }
}

