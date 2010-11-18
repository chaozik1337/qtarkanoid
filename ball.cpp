#include "ball.h"

Ball::Ball()
{
 image.load("ball.png");
 rect = image.rect();
 this->speedX = 0; //100 pixels per second
 this->speedY = -200;
 this->speedResultant = sqrt(pow(this->speedX,2) + pow(this->speedY,2));
 this->posX = 275;
 this->posY = 450;
 this->nextPosX = posX;
 this->nextPosY = posY;
 this->hitCount = 0;
 resetState();
}

Ball::~Ball()
{
}

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
