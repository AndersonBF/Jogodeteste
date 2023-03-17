#include "janela.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QPen>
#include <QFileDialog>
#include <QPushButton>
#include <QPainter>

Janela::Janela(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("Titulo da Janela");
    //lugar onde ela aparece e tamanho dela
    setGeometry(0,0,800,600);

    QMenuBar *barra = new QMenuBar(this);

    QMenu *menuArquivo = new QMenu("Arquivo", this);
    barra->addMenu(menuArquivo);

    QAction *acaoAbrir = new QAction("Abrir", this);
    menuArquivo->addAction(acaoAbrir);

    QPushButton *botao = new QPushButton("Me clica", this);
    botao->setGeometry(100,100,100,50);
    botao->setText("Outra coisa");

    connect(acaoAbrir, SIGNAL(triggered(bool)), this, SLOT(Abrir()));

    connect(botao, SIGNAL(clicked(bool)), this, SLOT(AcaoAoClicar()));
    //connect(botao, SIGNAL(clicked(bool)), this, SLOT(close()));
}

void Janela::AcaoAoClicar() {
    //o que estiver aqui vai ser executado quando o botao for clicado
    qDebug() << "O botao foi clicado";
}

void Janela::Abrir() {
    QFileDialog::getOpenFileName(this,"Escolha um arquivo");
    qDebug() << "Cliquei com sucesso!";
}

//void Janela::paintEvent(QPaintEvent *event) {
   // qDebug() << "Quero pintar a tela!";
//}

void Janela::paintEvent(QPaintEvent *event) {
    QPainter pintor(this);
    pintor.drawLine(100,100,200,300);
    QPen canetaazul(Qt::blue);
    pintor.setPen(canetaazul);
    pintor.drawRect(200,300,100,100);
}
