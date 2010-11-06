#include "level.h"

Level::Level(QWidget *parent, int num) :
    QWidget(parent)
{
 this->num = num;
 //blocks = new QList<Block>;
 switch (this->num)
 {
 case 1:
  blocks.append(new Block::Block(0, 1, this->num, 0, 5));
  blocks.append(new Block::Block(0, 2, this->num, 1, 5));
  blocks.append(new Block::Block(0, 1, this->num, 2, 5));
  blocks.append(new Block::Block(0, 2, this->num, 3, 5));
  blocks.append(new Block::Block(0, 1, this->num, 4, 5));
  blocks.append(new Block::Block(0, 2, this->num, 5, 5));
  blocks.append(new Block::Block(0, 1, this->num, 6, 5));
  blocks.append(new Block::Block(0, 2, this->num, 7, 5));
  blocks.append(new Block::Block(0, 1, this->num, 8, 5));
  blocks.append(new Block::Block(0, 2, this->num, 9, 5));
  blocks.append(new Block::Block(0, 1, this->num, 10, 5));
  blocks.append(new Block::Block(0, 2, this->num, 11, 5));
  blocks.append(new Block::Block(0, 1, this->num, 12, 5));
  break;
 case 2:
  break;
 case 3:
  break;
 default:
  break;
 }
}
