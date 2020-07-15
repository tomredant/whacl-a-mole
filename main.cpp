#include "mainwindow.h"
#include <QApplication>
#include<stdlib.h>
#include<time.h>
int main(int argc, char *argv[])
{
    //这行是用来适配我的显示器的，无视就好
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication a(argc, argv);

    srand((unsigned)time(NULL));//随机数种子
    MainWindow w;
    w.show();

    return a.exec();
}
