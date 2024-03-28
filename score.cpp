#include "score.h"
#include<QFont>

Score::Score(QGraphicsTextItem *parent): QGraphicsTextItem(parent){
    score = 0;
    setPlainText(QString("Score: ") + QString::number(score));
    setFont(QFont("times", 16));
    setDefaultTextColor(Qt::blue);
}

void Score::increase(){
    score++;
}

int Score::getScore(){
    return score;
}
