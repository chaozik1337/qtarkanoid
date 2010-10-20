#ifndef ARKANOID_H
#define ARKANOID_H

#include "paddle.h"
#include "ball.h"
#include <QWidget>
#include <QKeyEvent>
#include <QPalette>

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

  bool setGameArea(int width, int height);

private:
  int x;
  int timerId;
  Paddle *paddle;
  Ball *ball;
  bool gameOver;
  bool gameWon;
  bool gameStarted;
  bool paused;
  QRect rect;
  int gameAreaWidth;
  int gameAreaHeight;

};

#endif
