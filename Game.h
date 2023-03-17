#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Health.h"
#include <QMediaPlayer>
#include <QAudioOutput>
//#include <QObject>

class Game: public QGraphicsView{
    Q_OBJECT
public:
    //construtores
    Game(QWidget* parent=NULL);


    void displayMainMenu();
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
    QMediaPlayer *music;
    QAudioOutput *audioOutput;

    void start();

};

#endif // GAME_H
