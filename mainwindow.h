#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>

class GameScene;

class MainWindow : public QGraphicsView
{
    Q_OBJECT

public:
    explicit MainWindow();


    void init();

signals:
private:
    GameScene *gameScene;
};

#endif // MAINWINDOW_H
