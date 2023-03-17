#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <QMediaPlayer>
#include <QtMultimedia>
#include <QAudioOutput>
#include "Button.h"
//#include <QObject>


Game::Game(QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)


    setBackgroundBrush(QBrush(QImage(":/images/bg.png")));

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    // create the player
    player = new Player();
    //player->setRect(0,0,100,100); // change the rect from 0x0 (default) to 100x100 pixels
    player->setPos(400,500); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    // create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    // música de fundo
    //QMediaPlayer * music = new QMediaPlayer();
    //QAudioOutput * music = new QAudioOutput;
    music = new QMediaPlayer;
    music->setLoops(QMediaPlayer::Infinite);
    audioOutput = new QAudioOutput;
    music->setAudioOutput(audioOutput);
    connect(music, &QMediaPlayer::sourceChanged, music, &QMediaPlayer::play);
    music->setSource(QUrl("qrc:/sounds/ojogo.mp3"));

    audioOutput->setVolume(50);
    music->play();
    show();
   // music = new QMediaPlayer;
                //music->setLoops(QMediaPlayer::Infinite);
     //           sfx = new QMediaPlayer;
       //         music->setLoops(QMediaPlayer::Infinite);
            //    audioOutput = new QAudioOutput;
            //    music->setAudioOutput(audioOutput);

                //connect(music, &QMediaPlayer::sourceChanged, music, &QMediaPlayer::play); // Se mudar a musica, começar a tocar ela

                //connect(music, &QMediaPlayer::sourceChanged, [this](){
               //     music->setLoops(QMediaPlayer::Infinite);
              //      music->play();
                //    qDebug() << "play";
               // });

                //music->setSource(QUrl::fromLocalFile("C:\Users\joaop\Documents\Tower-Defense-POO\images\music.mp3"));
             //   music->setSource(QUrl("qrc:/songs/music.mp3"));
            //    sfx->setSource(QUrl("qrc:/songs/wrongbuzzsfx.wav"));
                //audioOutput->setVolume(50);
    //music->play();
}

void Game::displayMainMenu(){
    // create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Hex Warz"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // create the play button
    Button* playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    // create the quit button
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);
}
