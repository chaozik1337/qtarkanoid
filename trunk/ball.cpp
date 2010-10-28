#include "ball.h"

Ball::Ball()
{
  image.load("ball.png");
  rect = image.rect();
  resetState();
  this->speedX = 1; //100 pixels per second
  this->speedY = 1;
  this->posX = 200;
  this->posY = 300;
  this->nextPosX = posX;
  this->nextPosY = posY;
  this->hitCount = 0;
}

Ball::~Ball()
{
}

int Ball::getPosX()
{
  return posX;
}

int Ball::getPosY()
{
  return posY;
}

bool Ball::checkCollisions()
{
  bool ret = false;
  if (XChanged)
  {
    if (this->nextPosX > 600 - 4)
    {
      this->speedX = -1 * this->speedX;
      this->posX = 600 - 4;
      this->nextPosX = this->posX;
      ret = true;
    }
    else if (this->nextPosX < 0 + 4)
    {
      this->speedX = -1 * this->speedX;
      this->posX = 0 + 4;
      this->nextPosX = this->posX;
      ret = true;
    }
  }

  if (YChanged)
  {
    if (this->nextPosY < 0 + 4)
    {
      this->speedY = -1 * this->speedY;
      this->posY = 0 + 4;
      this->nextPosY = this->posY;
      ret = true;
    }
    else if (this->nextPosY > 600 + 4)
    {
      this->speedY = -1 * this->speedY;
      this->posY = 600 + 4;
      this->nextPosY = this->posY;
      ret = true;
    }
  }

  return ret;
}

bool Ball::checkBallPosition()
{
  this->XChanged = false;
  this->YChanged = false;
  this->nextPosX = this->nextPosX + (this->speedX / 1000 * 10);
  this->nextPosY = this->nextPosY + (this->nextPosY / 1000 * 10);


  //check if posX has changed
  if (qAbs(floor(this->nextPosX)) != qAbs(this->posX))
  {
    this->XChanged = true;
  }

  //check if posY has changed
  if (qAbs(floor(this->nextPosY)) != qAbs(this->posY))
  {
    this->YChanged = true;
  }

  if (XChanged || YChanged)
  {
    hitCount++;
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
