#include <QApplication>
#include<QLabel>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include<QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include<QPixmap>
//#include "player.h"
#include "game.h"
#include <QTimer>
#include <QDebug>
#include <QBrush>
#include <QCoreApplication>
#include "score.h"
#include "bullet.h"

int score = 0;
void incrementScore(){
    score++;
}

int Player::score = 0;
int Player::health = 3;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene scene;

    // *******  Create the View ********
    QGraphicsView view;
    view.setFixedSize(800, 600);

    // *******  Create the Player ********
    Player* player = new Player();
    QPixmap spaceship("C:/Users/omars/OneDrive/Desktop/Uni/AUC/Semester 6/CS II/Lab/Assignments/Assignment 3/space-invaders-ship-png-clip-art-spaceship-340383.png");
    player->setPixmap(spaceship.scaled(200,100));

    // ******* Create the Scene ********
    scene.setSceneRect(0, 0, 800, 600);
    scene.addItem(player);

    // Displaying Score
    QGraphicsTextItem *score_display = new QGraphicsTextItem();

    /*QObject::connect(player, SIGNAL(scoreUpdated(int)), [&](int score){
        score_display->setPlainText(QString("Score: ") + QString::number(player->getScore()));
        scene.addItem(score_display);
        player->collision = false;
    });*/

   /* if(player->collision = true){

    }*/


    // *******  Setting the foucs to the Player ********
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // *******  Adjust the location of the Player (middle of the screen) ********
    player->setPos(view.width()/2-100, view.height()-100);

    // *******   Assign scene to the view   ***************
    view.setScene(&scene);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // *******  Create the Enemies automatically ********
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),player,SLOT(createEnemy()));
    time->start(2000);
    view.show();

    return a.exec();
}
