#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>

class handler : public QObject
{
    Q_OBJECT
public:
    static handler *getInstance();//获取hand
    void addScore();//加分函数
private:
    explicit handler(QObject *parent = nullptr);

signals:
    void whackmole();//信号，表示敲到了地鼠
public slots:
private:
    static handler * hand;
};

#endif // HANDLER_H
