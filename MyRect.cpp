#include "MyRect.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include "Bullet.h"
#include "Enemy.h"

void MyRect::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left) {
        setPos(x()-100, y());
    }
    else if (event->key() == Qt::Key_Right) {
        setPos(x()+100, y());
    }
    else if (event->key() == Qt::Key_Up) {
        setPos(x(), y()-100);
    }
    else if (event->key() == Qt::Key_Down) {
        setPos(x(), y()+100);
    }
    else if (event->key() == Qt::Key_Space) {
        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        qDebug() << "bullet created";
        scene() ->addItem(bullet);
    }
}

void MyRect::spawn() {
    // criando inimigos
    Enemy *enemy = new Enemy();
    scene()-> addItem(enemy);
}
