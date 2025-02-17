#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include "game.h"

class QTimer;

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GameScene(QObject *parent = nullptr);

signals:

private slots:
    void update();
private:
    Game game;
    QPixmap pixmap;
    QTimer *timer;
    int x, y;
    // QGraphicsScene interface
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // GAMESCENE_H
