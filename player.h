#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QObject>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
public:
    void keyPressEvent(QKeyEvent * event);
    static void decreaseHealth();
    static int score;
    static int health;
public slots:
    void createEnemy();
    static int getHealth();
    static int getScore();
    static void increaseScore();
private:

};



#endif // PLAYER_H
