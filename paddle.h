#ifndef PADDLE_H
#define PADDLE_H

#include <QImage>
#include <QRect>
#include <QWidget>

class Paddle : public QWidget
{
  Q_OBJECT

public:
  Paddle();
  ~Paddle();

public:
  void resetState();
  void movePaddle(int position, int gameAreaWidth);
  QRect getRect();
  QImage & getImage();
  int getPosX();

private:
  QImage image;
  QRect rect;
  int posX;

};

#endif
