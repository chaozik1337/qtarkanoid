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

int Paddle::getPosX()
{
  return this->posX;
}

void Paddle::movePaddle(int position, int gameAreaWidth)
{
  //mouse pointer is inside the gamearea
  if (position > 0 && position < gameAreaWidth)
  {
    if (position <= 40) //paddle is on leftmost position
    {
      rect.moveTo(0, rect.top());
      this->posX = 40;
    }

    else if(position > 40 && position < gameAreaWidth - 40) //paddle is between left and right wall
    {
      rect.moveTo(position - 40, rect.top());
      this->posX = position;
    }
    else //paddle is on rightmost position
    {
      rect.moveTo(gameAreaWidth - 80, rect.top());
      this->posX = gameAreaWidth - 40;
    }

  }
}

void Paddle::resetState()
{
  rect.moveTo(200, 500);
}

QRect Paddle::getRect()
{
  return rect;
}

QImage & Paddle::getImage()
{
  return image;
}
