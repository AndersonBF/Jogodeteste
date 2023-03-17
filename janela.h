#ifndef JANELA_H
#define JANELA_H

#include <QMainWindow>

class Janela : public QMainWindow
{
    Q_OBJECT
public:
    explicit Janela(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
signals:

public slots:
    void AcaoAoClicar();
    void Abrir();
};

#endif // JANELA_H
