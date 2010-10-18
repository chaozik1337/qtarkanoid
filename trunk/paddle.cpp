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

void Paddle::movePaddle(int position, int gameAreaWidth)
{
  if (position > 0 && position < gameAreaWidth)
  {
    if (position <= 40)
    {
      rect.moveTo(0, rect.top());
    }
    else if(position > 40 && position < gameAreaWidth-40)
    {
      rect.moveTo(position - 40, rect.top());
    }
    else
    {
      rect.moveTo(gameAreaWidth-80, rect.top());
    }

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
