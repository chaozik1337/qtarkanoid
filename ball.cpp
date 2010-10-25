#include "ball.h"

Ball::Ball()
{
  image.load("ball.png");
  rect = image.rect();
  resetState();
  this->speedX = 100; //100 pixels per second
  this->speedY = 100;
  this->posX = 100;
  this->posY = 100;
  this->nextPosX = posX;
  this->nextPosY = posY;
}

Ball::~Ball()
{
}

bool Ball::checkBallPosition()
{
  this->nextPosX = this->nextPosX + (this->speedX / 1000 * 10);
  this->nextPosY = this->nextPosY + (this->nextPosY / 1000 * 10);

  if (floor(nextPosX) > posX || floor(nextPosY) > posY)
  {
    return true;
  }

  return false;
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
