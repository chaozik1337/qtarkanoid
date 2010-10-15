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
  void movePaddle(int);
  QRect getRect();
  QImage & getImage();

private:
  QImage image;
  QRect rect;

};

#endif
