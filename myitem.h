#ifndef MYITEM_H
#define MYITEM_H
#include<QGraphicsPixmapItem>
#include<QString>
#include<QGraphicsSceneMouseEvent>
class myItem : public QGraphicsPixmapItem
{
public:
    myItem();
    void setPic(QString path);//展示图片
    void mousePressEvent(QGraphicsSceneMouseEvent *event);//鼠标按下
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);//鼠标抬起
    void setMole(bool mole);//设定某地是否有地鼠
    bool isMole();//true表示有地鼠
    void setStart(bool start);//设定游戏进行状态
    bool isStart();//true表示游戏正在进行
private:
    bool mole;
    bool start;
};

#endif // MYITEM_H
