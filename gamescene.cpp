#include "gamescene.h"
#include<stdlib.h>
gameScene::gameScene(QObject *parent) : QGraphicsScene(parent)
{
    int i=0;
    for(i=0;i<16;i++)
    {
        this->item[i] = new myItem;
        this->item[i]->setPos(i/4*this->item[i]->boundingRect().width(),i%4*this->item[i]->boundingRect().height());
        this->addItem(this->item[i]);
    }
    this->p_timer=new QTimer;
    connect(this->p_timer,SIGNAL(timeout()),this,SLOT(showMole()));
}
void gameScene::showMole()
{
    int count = rand()%3+1;
    int i=0;
    for(i=0;i<16;i++)
    {
        this->item[i]->setPic(":/backgroud/pic/mole.png");
        this->item[i]->setMole(false);
    }
    for(i=0;i<count;i++)
    {
        int index = rand()%16;
        this->item[index]->setPic(":/mole/pic/mole_2.png");
        this->item[index]->setMole(true);
    }
}
void gameScene::startGame()
{
    int i=0;
    for(i=0;i<16;i++)
    {
        this->item[i]->setStart(true);
    }
    this->p_timer->start(800);
}

void gameScene::pauseGame()
{
    int i=0;
    for(i=0;i<16;i++)
    {
        this->item[i]->setStart(false);
    }
    this->p_timer->stop();
};


