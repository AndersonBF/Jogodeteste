#include "Score.h"
#include <QFont>


Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
   score = 0;


    //desenhar  o texto
    setPlainText (QString("Score:") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
}

    void Score::increase()
{
        score++;
           setPlainText(QString("Score: ") + QString::number(score)); // Score: 1

    };

    int Score::getScore(){
        return score;
    }
