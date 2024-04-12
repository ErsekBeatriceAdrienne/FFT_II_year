#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QPushButton>
#include <QMessageBox>
#include <QGridLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void handleButtonClick();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    enum class Player { None, X, O };

    Player currentPlayer;
    QVector <QVector <Player >> board;
    QVector <QVector <QPushButton *>> buttons;

    void initializeBoard();
    void checkWinner();
    void restartGame();
};

#endif // MAINWINDOW_H
