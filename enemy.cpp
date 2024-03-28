#include "enemy.h"
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> to generate really large integer
#include <QTimer>
#include <QDebug>
#include "player.h"
#include "gameover.h"
#include <QGraphicsPixmapItem>
#include <QPixmap>


Enemy::Enemy() {
    // *******  Setting the size of the enemy ********
    QPixmap chicken("C:/Users/omars/OneDrive/Desktop/Uni/AUC/Semester 6/CS II/Lab/Assignments/Assignment 3/Chicken.png");
    setPixmap(chicken.scaled(100,100));
    //setRect(0,0,100,100);

    // *******  Setting the postion of the enemy within the view dimensions ********
    int random_number = rand() % 700;
    setPos(random_number,0);

    // *******  Moving the enemies downwards automatically every 50 milli second ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);

}


int Enemy::health = 3;
// Function move: move the enemy downwards untill the end of the scene then remove it and delete it

void Enemy::decrement(){
    health--;
}

void Enemy:: move()
{
    GameOver* gameover = new GameOver();
    QList<QGraphicsItem*> colliding_items2 = collidingItems();
    for(int i=0;i<colliding_items2.size();i++){
        if(typeid(*(colliding_items2[i])) == typeid(Player)){
            Player::decreaseHealth();
            if(Player::getHealth() > 0){
                scene()->removeItem(this);
                delete this;

            }
            else if(Player::getHealth() == 0){
            scene()->removeItem(colliding_items2[i]);
            scene()->removeItem(this);
            delete colliding_items2[i];
            delete this;
            gameover->show();
            break;
            }
        }
    }


    setPos(x(),y()+5);
    if(pos().y()>600)
    {
        Player::decreaseHealth();
        scene()->removeItem(this);
        delete this;
        if(Player::getHealth()==0){
            gameover->show();
        }
    }
}





