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

public slots:
    void showMole();//地鼠探头
    void startGame();//开始游戏
    void pauseGame();//暂停游戏
private:
    myItem * item[16];//设置16个图元对象
    QTimer * p_timer;//计时器
};

#endif // GAMESCENE_H
