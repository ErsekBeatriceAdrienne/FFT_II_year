#ifndef GAME_H
#define GAME_H

#include <QMenu>
#include <QLabel>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include <QColorDialog>
#include <QStatusBar>
#include "paddle.h"
#include "block.h"

class Game : public QGraphicsView
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game();

    void start();
    void victory();
    void lost();

    void restartGame();

    void generateBlockGrid();
    void generateBlockCol(double);

    QGraphicsScene* scene;
    int numberOfBlocks = 7*5;
    int numOfCols = 7;
    int numOfRows = 5;
    int heightOfBlocks = 25;
    int widthOfBlocks = 50;
    QPushButton *restartButton;

    QColor blockColor;
    QColor ballColor;
    QColor paddleColor;

    double xDirection = 0;
    double yDirection = -5;

private:
    QStatusBar *statusBar;
    QLabel *remainingBricksLabel;
    QLabel *destroyedBricksLabel;
    int remainingBricksCount;
    int destroyedBricksCount;

    QPushButton *easyButton;
    QPushButton *hardButton;
    QPushButton *customSpeedButton;

private slots:
    void changeColors();
    void setDifficultyNormal();
    void setDifficultyHard();

    void updateBrickCounts();
    void updateStatusBar();

};

#endif // GAME_H
