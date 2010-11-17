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
  int hitCount;

  int posX;
  int posY;
  double nextPosX;
  double nextPosY;
  double speedX;
  double speedY;
  double speedResultant;
  bool XChanged;
  bool YChanged;

private:
  QImage image;
  QRect rect;


};

#endif // BALL_H
