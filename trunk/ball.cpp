#include "ball.h"

Ball::Ball()
{
  image.load("ball.png");
  rect = image.rect();
  resetState();
}

Ball::~Ball()
{
}

void Ball::moveBall(int x, int y, int gameAreaWidth, int gameAreaHeight)
{
  //check x position
  if (x > 0 && x < gameAreaWidth)
  {
    posX = x;
  }

  //check y position
  if (y > 0 && y < gameAreaHeight)
  {
    posY = y;
  }

  //move rect to new position
  rect.moveTo(posX, posY);
}

void Ball::resetState()
{
  rect.moveTo(200, 300);
}

QRect Ball::getRect()
{
  return rect;
}

QImage & Ball::getImage()
{
  return image;
}
