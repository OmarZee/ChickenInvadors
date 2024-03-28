#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"


class Game
{
public:
    Game(QWidget * parent=0);
    Score * score;
};

#endif // GAME_H
