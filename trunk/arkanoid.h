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
  void startGame();
  void pauseGame();
  void stopGame();
  bool isPaused();
  bool isGameStarted();
  Ball *ball;

protected:
  void paintEvent(QPaintEvent *event);
  void mouseMoveEvent(QMouseEvent *event);

  void victory();

  bool setGameArea(int width, int height);

private:
  int x;
  int timerId;
  Paddle *paddle;

  bool gameOver;
  bool gameWon;
  bool gameStarted;
  bool paused;
  QRect rect;
  int gameAreaWidth;
  int gameAreaHeight;

};

#endif
