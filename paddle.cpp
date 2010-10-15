#include "paddle.h"


Paddle::Paddle()
{
  image.load("mela.png");

  rect = image.rect();
  resetState();
}

Paddle::~Paddle()
{
}

void Paddle::moveLeft(int left)
{
  if (rect.left() >= 2)
    rect.moveTo(left, rect.top());
}

void Paddle::moveRight(int right)
{
  if (rect.right() <= 298)
    rect.moveTo(right, rect.top());
}

void Paddle::movePaddle(int position)
{
    if (position > 0 && position < 500)
    {
        rect.moveTo(position, rect.top());
    }
}

void Paddle::resetState()
{
  rect.moveTo(200, 360);
}

QRect Paddle::getRect()
{
  return rect;
}

QImage & Paddle::getImage()
{
  return image;
}
