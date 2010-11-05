#include "level.h"

Level::Level(QWidget *parent, int num) :
    QWidget(parent)
{
 this->num = num;
 //blocks = new QList<Block>;
 switch (this->num)
 {
 case 1:
  blocks.append(new Block::Block(0, 1, this->num, 0, 0));
  blocks.append(new Block::Block(0, 2, this->num, 300, 0));
  break;
 case 2:
  break;
 case 3:
  break;
 default:
  break;
 }
}
