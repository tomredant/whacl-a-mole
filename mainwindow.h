#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<gamescene.h>
class SoundPlayer;
class QThread;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void clickAbout();
private slots:
    void updateScore();
    void updateScoreNegative();
    void toggleMusic();
    void updateGameTime(int time);
private:
    Ui::MainWindow *ui;
    gameScene * sc;
    int score;
    SoundPlayer* m_player;
    QThread* m_musicThread;
};

#endif // MAINWINDOW_H
