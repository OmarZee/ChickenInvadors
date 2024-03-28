// bullet.h
#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet();
    static int score;
    bool collision = false;

signals:
    void bulletHit(); // Declare a signal for bullet hit

public slots:
    void move();
};


#endif // BULLET_H
