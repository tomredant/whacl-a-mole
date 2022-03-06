#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QObject>
#include<QGraphicsScene>
#include<myitem.h>
#include<QTimer>
class gameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit gameScene(QObject *parent = nullptr);

signals:
    void notifyGameTime(int gameTime);
public slots:
    void showMole();
    void updateGameTime();
    void startGame();
private:
    myItem * item[16];
    QTimer * p_timer;
    QTimer * p_timerFast;
    qint64 m_startTime;

};

#endif // GAMESCENE_H
