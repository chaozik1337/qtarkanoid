#ifndef ARKANOID_H
#define ARKANOID_H

#include "paddle.h"
#include "ball.h"
//#include "block.h"
#include "level.h"
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
  Paddle *paddle;
  Block *block;
  Level *lvl;
  int getGameAreaW();
  int getGameAreaH();
  bool checkCollision();
  bool checkBlockCollision(bool X);
  int hitCount;
  static const double PI = 3.14;
  bool checkVictory(int n);
  bool gameStarted;
  double score;
  int lives;
  int level;

protected:
  void paintEvent(QPaintEvent *event);
  void mouseMoveEvent(QMouseEvent *event);

  void victory();

  void setGameArea(int width, int height);

private:
  int x;
  int timerId;

  bool gameOver;
  bool gameWon;
  bool paused;
  QRect rect;
  int gameAreaWidth;
  int gameAreaHeight;



};

#endif
