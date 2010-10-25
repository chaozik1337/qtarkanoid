#ifndef BALL_H
#define BALL_H

#include <QImage>
#include <QRect>
#include <QWidget>
#include <math.h>

class Ball : public QWidget
{
  Q_OBJECT

public:
  Ball();
  ~Ball();

public:
  void resetState();
  void moveBall(int x, int y, int gameAreaWidth, int gameAreaHeight);
  bool checkBallPosition();
  QRect getRect();
  QImage & getImage();

private:
  QImage image;
  QRect rect;
  int posX;
  int posY;
  double nextPosX;
  double nextPosY;
  int speedX;
  int speedY;

};

#endif // BALL_H
