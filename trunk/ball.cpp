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

bool Ball::checkCollisions()
{
    if (XChanged)
    {
        if (this->nextPosX > 600 - 4)
        {
            this->speedX = -1 * this->speedX;
            this->posX = 600 - 4;
            this->nextPosX = this->posX;
        }
        else if (this->nextPosX < 0 + 4)
        {
            this->speedX = -1 * this->speedX;
            this->posX = 0 + 4;
            this->nextPosX = this->posX;
        }
    }

    if (YChanged)
    {

    }
}

bool Ball::checkBallPosition()
{
    this->XChanged = false;
    this->YChanged = false;
    this->nextPosX = this->nextPosX + (this->speedX / 1000 * 10);
    this->nextPosY = this->nextPosY + (this->nextPosY / 1000 * 10);


    //check if posX has changed
    if (abs(floor(this->nextPosX)) != abs(this->posX)) // || floor(nextPosY) > posY)
    {
        this->XChanged = true;
        ret = true;
    }

    //check if posY has changed
    if (abs(floor(this->nextPosY)) != abs(this->posY))
    {
        this->YChanged = true;
        ret = true;
    }

    if (XChanged || YChanged)
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
