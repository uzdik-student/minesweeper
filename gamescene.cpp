#include "gamescene.h"
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include "mainwindow.h"

GameScene::GameScene(QObject *parent)
    : QGraphicsScene{parent}, game(), timer(new QTimer(this)), x(0), y(0)
{
    pixmap.load(":/images/tiles.jpg");
    setSceneRect(0,0, game.RESOLUTION.width(), game.RESOLUTION.width());
    connect(timer, &QTimer::timeout, this, &GameScene::update);
    timer->start(1000.0f/60.0f);
}

void GameScene::update()
{
    clear();
    for (int i = 1;i <= 10; i++)
    {
        for (int j = 1;j <= 10; j++)
        {
            if ( game.sgrid[x][y] == 9)
            {
                game.sgrid[i][j] = game.grid[i][j];
            }
            QGraphicsPixmapItem *gridItem = new QGraphicsPixmapItem(pixmap.copy( game.sgrid[i][j]*game.w, 0, game.w, game.w) );
            gridItem->setPos(i*game.w, j*game.w);
            addItem(gridItem);
        }
    }
}

void GameScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Qt::MouseButton button = event->button();

    QPointF clickedPos =  event->scenePos();
    x = static_cast<int>(clickedPos.x()) / game.w;
    y = static_cast<int>(clickedPos.y()) / game.w;

    qDebug() << "x " << x << " y " << y;

    if (button == Qt::LeftButton)
    {
        game.sgrid[x][y] = game.grid[x][y];
    }
    else if (button == Qt::RightButton)
    {
        game.sgrid[x][y] = 11;
    }
    QGraphicsScene::mousePressEvent(event);
}
