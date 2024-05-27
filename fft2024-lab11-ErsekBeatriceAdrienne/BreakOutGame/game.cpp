#include "game.h"
#include "ball.h"

Game::Game(QWidget *parent) : QGraphicsView(parent)
{
    scene = new QGraphicsScene(0,0,370,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(370, 600);

    restartButton = new QPushButton("Restart", this);
    restartButton->setGeometry(150, 300, 70, 30);
    QObject::connect(restartButton, &QPushButton::clicked, this, &Game::restartGame);
    restartButton->hide();

    setScene(scene);
    setMouseTracking(true);

    // Menüsáv létrehozása és menü hozzáadása
    QMenuBar *menuBar = new QMenuBar(this);
    QMenu *optionsMenu = menuBar->addMenu(tr("&Options"));

    QAction *changeColorsAction = new QAction(tr("&Change Colors..."), this);
    connect(changeColorsAction, &QAction::triggered, this, &Game::changeColors);
    optionsMenu->addAction(changeColorsAction);

    QAction *normalDifficultyAction = new QAction(tr("&Normal Difficulty"), this);
    connect(normalDifficultyAction, &QAction::triggered, this, &Game::setDifficultyNormal);
    optionsMenu->addAction(normalDifficultyAction);

    QAction *hardDifficultyAction = new QAction(tr("&Hard Difficulty"), this);
    connect(hardDifficultyAction, &QAction::triggered, this, &Game::setDifficultyHard);
    optionsMenu->addAction(hardDifficultyAction);

    statusBar = new QStatusBar(this);
    statusBar->setFixedWidth(370);
    remainingBricksLabel = new QLabel(this);
    statusBar->addWidget(remainingBricksLabel);

    destroyedBricksLabel = new QLabel(this);
    statusBar->addWidget(destroyedBricksLabel);

    remainingBricksCount = numOfCols * numOfRows; // Kezdetben az összes tégla megvan
    destroyedBricksCount = 0;

    updateStatusBar();

    // Beállítjuk az ablak méretét
    setFixedSize(370, 620);
}

Game::~Game(){}

void Game::start()
{
    //golyo
    Ball* ball = new Ball();
    ball->setPos(200, 500);
    scene->addItem(ball);
    connect(ball, &Ball::brickDestroyed, this, &Game::updateBrickCounts);

    //csuszka
    Paddle* paddle = new Paddle();
    paddle->setPos(150, 575);
    scene->addItem(paddle);
    paddle->grabMouse();

    //teglak
    generateBlockGrid();
}

void Game::restartGame()
{
    scene->clear();
    restartButton->hide();
    start(); // Indítsuk újra a játékot
}

void Game::victory()
{
    qDebug() << "Victory";
}

void Game::lost()
{
    QGraphicsTextItem *gameOverText = new QGraphicsTextItem("Game Over");
    QFont font;
    font.setPixelSize(30);
    gameOverText->setFont(font);
    int xPos = this->width() / 2 - gameOverText->boundingRect().width() / 2;
    int yPos = this->height() / 2 - gameOverText->boundingRect().height() / 2 - 20;
    gameOverText->setPos(xPos, yPos);
    scene->addItem(gameOverText);

    restartButton->show();
}

void Game::generateBlockGrid()
{
    for(int i=0; i< numOfCols;i++)
    {
        //oszlop szama * (block merete + koztuk levo hely)
        generateBlockCol(i*(widthOfBlocks+3));
    }
}

void Game::generateBlockCol(double x)
{
    for(int i=0; i< numOfRows; i++)
    {
        Block *block = new Block();
        //hanyadik oszlop, hanyadik az oszlopban*(blocknak a magassaga + a hezag merete)
        block->setPos(x, i*(heightOfBlocks+3));
        scene->addItem(block);
    }
}

void Game::changeColors()
{

    QColorDialog dialog;
    QColor newBlockColor = dialog.getColor(blockColor, this, tr("Choose Block Color"));
    QColor newBallColor = dialog.getColor(ballColor, this, tr("Choose Ball Color"));
    QColor newPaddleColor = dialog.getColor(paddleColor, this, tr("Choose Paddle Color"));

    // Színek mentése és alkalmazása a tárgyakra
    blockColor = newBlockColor;
    ballColor = newBallColor;
    paddleColor = newPaddleColor;


    // Színek alkalmazása a tárgyakra
    QList<QGraphicsItem *> allItems = scene->items();
    foreach (QGraphicsItem *item, allItems) {
        // Téglák színe
        Block *block = dynamic_cast<Block *>(item);
        if (block)
            block->setBrush(blockColor);

        // Golyó színe
        Ball *ball = dynamic_cast<Ball *>(item);
        if (ball)
            ball->setBrush(ballColor);

        // Csúszka színe
        Paddle *paddle = dynamic_cast<Paddle *>(item);
        if (paddle)
            paddle->setBrush(paddleColor);
    }
}

void Game::setDifficultyNormal()
{
    // Téglák számának és golyó sebességének visszaállítása normál módba
    numberOfBlocks = 7 * 5;
    xDirection = 0;
    yDirection = -5;
}

void Game::setDifficultyHard()
{
    // Téglák számának és golyó sebességének beállítása nehéz módba
    numberOfBlocks = 10 * 7;
    xDirection = 0;
    yDirection = -7;

    // Golyó sebességének beállítása a nehéz módban
    QList<QGraphicsItem *> allItems = scene->items();
    foreach (QGraphicsItem *item, allItems) {
        Ball *ball = dynamic_cast<Ball *>(item);
        if (ball) {
            ball->setXDirection(xDirection);
            ball->setYDirection(yDirection);
        }
    }
}

void Game::updateBrickCounts()
{
    destroyedBricksCount++;
    remainingBricksCount--;
    updateStatusBar();
}

void Game::updateStatusBar()
{
    remainingBricksLabel->setText(QString("Remaining Bricks: %1").arg(remainingBricksCount));
    destroyedBricksLabel->setText(QString("Destroyed Bricks: %1").arg(destroyedBricksCount));
}




