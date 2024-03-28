#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsRectItem>
#include <QObject>

class Enemy: public QObject , public QGraphicsPixmapItem
{ Q_OBJECT
public:
    Enemy();
    static int health;
    void decrement();

public slots:
    void move();
};

#endif // ENEMY_H
