#include "block.h"

Block::Block(QWidget *parent, int num, int lvl, int posX, int posY) :
    QWidget(parent)
{
  this->blockNum = num;

  switch (this->blockNum)
  {
  case 1:
    this->score = 50;
    this->color = "White";
    image.load("block_white.png");
    break;
  case 2:
    this->score = 60;
    this->color = "Orange";
    image.load("block_orange.png");
    break;
  case 3:
    this->score = 70;
    this->color = "Light blue";
    break;
  case 4:
    this->score = 80;
    this->color = "Green";
    break;
  case 5:
    this->score = 90;
    this->color = "Red";
    break;
  case 6:
    this->score = 100;
    this->color = "Blue";
    break;
  case 7:
    this->score = 110;
    this->color = "Pink";
    break;
  case 8:
    this->score = 120;
    this->color = "Yellow";
    break;
  case 9:
    this->score = 50 * lvl;
    this->color = "Silver";
    break;
  case 10:
    this->score = 50 * lvl;
    this->color = "Silver beaten";
    break;
  case 11:
    this->score = 0;
    this->color = "Gold";
    break;
  default:
    break;
  }

  rect = image.rect();
  this->x1 = posX;
  this->y1 = posY;
  this->x2 = this->x1 + this->getRect().width();
  this->y2 = this->y1 + this->getRect().height();
  rect.moveTo(this->x1, this->y1);
}

Block::~Block()
{
  delete this;
}

QRect Block::getRect()
{
  return rect;
}

QImage & Block::getImage()
{
  return image;
}
