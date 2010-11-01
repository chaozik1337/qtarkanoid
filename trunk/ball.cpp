#include "ball.h"

Ball::Ball()
{
 image.load("ball.png");
 rect = image.rect();
 this->speedX = 0; //100 pixels per second
 this->speedY = 200;
 this->posX = 300;
 this->posY = 100;
 this->nextPosX = posX;
 this->nextPosY = posY;
 this->hitCount = 0;
 resetState();
}

Ball::~Ball()
{
}

double Ball::getSpeedResultant()
{
  return sqrt(pow(this->speedX, 2) + pow(this->speedY, 2));
}

int Ball::getPosX()
{
 return posX;
}

int Ball::getPosY()
{
 return posY;
}

/*
bool Ball::checkCollisions()
{
 bool ret = false;
 if (XChanged)
 {
  if (this->nextPosX > 520 - 11)
  {
   this->speedX = -1 * this->speedX;
   this->posX = 520 - 11;
   this->nextPosX = this->posX;
   ret = true;
  }
  else if (this->nextPosX < 0)
  {
   this->speedX = -1 * this->speedX;
   this->posX = 0;
   this->nextPosX = this->posX;
   ret = true;
  }
  else
  {
   this->posX = floor(this->nextPosX);
  }
 }

 if (YChanged)
 {
  //check if ball hit top
  if (this->nextPosY < 0)
  {
   this->speedY = -1 * this->speedY;
   this->posY = 0;
   this->nextPosY = this->posY;
   ret = true;
  }
  else if (floor(this->nextPosY) >= 480 || floor(this->nextPosY) < 485)
  {
   if (floor(this->posX) == 1)
   {

   }
  }

  else if (this->nextPosY > 600 - 12)
  {
   this->speedY = -1 * this->speedY;
   this->posY = 600 - 12;
   this->nextPosY = this->posY;
   ret = true;
  }
  else
  {
   this->posY = floor(this->nextPosY);
  }
 }

 return ret;
}
*/

bool Ball::checkBallPosition()
{
 this->XChanged = false;
 this->YChanged = false;
 this->nextPosX = this->nextPosX + (this->speedX / 1000 * 10);
 this->nextPosY = this->nextPosY + (this->speedY / 1000 * 10);


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
 rect.moveTo(this->posX, this->posY);
}

QRect Ball::getRect()
{
 return rect;
}

QImage & Ball::getImage()
{
 return image;
}
