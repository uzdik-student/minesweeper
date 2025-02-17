#include "mainwindow.h"
#include "game.h"
#include "gamescene.h"

MainWindow::MainWindow()
    : QGraphicsView(), gameScene(new GameScene(this))
{
    // Set window title
    setWindowTitle("Minesweeper");

    // Resize window
    resize(Game::RESOLUTION.width(), Game::RESOLUTION.height());

    // Disable scroll bars
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setScene(gameScene);
}
