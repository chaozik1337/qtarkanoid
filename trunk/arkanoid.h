#ifndef ARKANOID_H
#define ARKANOID_H

#include "paddle.h"
#include <QWidget>
#include <QKeyEvent>

class Arkanoid : public QWidget
{
  Q_OBJECT

  public:
    Arkanoid(QWidget *parent = 0);
    ~Arkanoid();

  protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    void startGame();
    void pauseGame();
    void stopGame();
    void victory();

  private:
    int x;
    int timerId;
    Paddle *paddle;
    bool gameOver;
    bool gameWon;
    bool gameStarted;
    bool paused;
    QRect rect;

};

#endif
