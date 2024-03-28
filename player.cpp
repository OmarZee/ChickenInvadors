#include "player.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include <QDebug>
#include "enemy.h"
#include <QList>
#include<QPixmap>
#include <QGraphicsPixmapItem>

Player::Player() {

}


QGraphicsTextItem *score_display = new QGraphicsTextItem();
QGraphicsTextItem *health_display = new QGraphicsTextItem();

int Player::getScore(){
    return score;
}

void Player::keyPressEvent(QKeyEvent *event)
{
        // *******  Event Handling for the Player ********
    if(event->key()== Qt::Key_Left)
    {
        if(x()>0) // to prevent the player from getting out of the screen
        {
        setPos(x()-10,y());
        }
    }
    else if(event->key()== Qt::Key_Right)

    { if(x()+100<800) // to prevent the player from getting out of the screen
        setPos(x()+10,y());
    }
    else if(event->key()== Qt::Key_Space)
    {
        Bullet * bullet = new Bullet;
        bullet->setPos(x()+90.5,y());
        scene()->addItem(bullet);

    }
}

void Player::decreaseHealth(){
    health--;
}


int Player::getHealth(){
    return health;
}

 // CreateEnemy function used to create the eneimes
void Player::createEnemy()
{ Enemy* enemy = new Enemy();
  scene()->addItem(enemy);
  score_display->setPlainText(QString("Score: ") + QString::number(getScore()));
  QFont font("Arial", 16);
  score_display->setFont(font);
  score_display->setDefaultTextColor(Qt::blue);
  scene()->addItem(score_display);
  health_display->setPlainText(QString("Health: ") + QString::number(getHealth()));
  health_display->setFont(font);
  health_display->setDefaultTextColor(Qt::red);
  health_display->setPos(700,0);
  scene()->addItem(health_display);

}

void Player::increaseScore(){
    score++;
}
