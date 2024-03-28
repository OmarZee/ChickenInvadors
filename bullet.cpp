// bullet.cpp
#include "bullet.h"
#include "enemy.h"
#include "player.h"
#include <QTimer>
#include <QList>
#include <QDebug>
#include <QGraphicsScene>

Bullet::Bullet(): QObject(), QGraphicsPixmapItem() {
    QPixmap bullet("C:/Users/omars/OneDrive/Desktop/Uni/AUC/Semester 6/CS II/Lab/Assignments/Assignment 3/Laser.png");
    setPixmap(bullet.scaled(20,50));

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);
}

void Bullet::move() {
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            Player::increaseScore();
            qDebug() << "Bullet hit an enemy!" << Player::getScore();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    setPos(x(), y() - 10);
    if(pos().y() + 50 < 0){
        scene()->removeItem(this);
        delete this;
    }
}
