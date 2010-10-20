#ifndef BALL_H
#define BALL_H

#include <QImage>
#include <QRect>
#include <QWidget>

class Ball : public QWidget
{
  Q_OBJECT

public:
  Ball();
  ~Ball();

public:
  void resetState();
  void moveBall(int x, int y, int gameAreaWidth, int gameAreaHeight);
  QRect getRect();
  QImage & getImage();

private:
  QImage image;
  QRect rect;
  int posX;
  int posY;

};

#endif // BALL_H
