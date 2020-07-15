#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<gamescene.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void updateScore();

private:
    Ui::MainWindow *ui;
    gameScene * sc;
    int score;
};

#endif // MAINWINDOW_H
