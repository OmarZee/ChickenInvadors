#include "gameover.h"
#include "ui_gameover.h"
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include "player.h"
#include <QTimer>
#include <QDebug>
#include <QBrush>


GameOver::GameOver(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GameOver)
{
    //QPixmap pix("C:/Users/omars/OneDrive/Desktop/Uni/AUC/Semester 6/CS II/Lab/Lab 5/Session 05 Game Template/download.jpeg");
    // pix = pix.scaledToWidth(50);
    // pix = pix.scaledToHeight(50);
    // QGraphicsPixmapItem * image = new QGraphicsPixmapItem;
    // image->setPixmap(pix);
    // image->setPos(30,40);

    //ui->label_gameover->setPixmap(pix.scaled(600, 600));
    ui->setupUi(this);
    ui->score_label->setText("Score: " + QString::number(Player::getScore()));
}


GameOver::~GameOver()
{
    delete ui;
}

void GameOver::on_pushButton_clicked()
{
    hide();
    int main(int argc, char *argv[]);

}

