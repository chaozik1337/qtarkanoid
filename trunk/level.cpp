#include "level.h"

Level::Level(QWidget *parent, int num) :
    QWidget(parent)
{
 this->num = num;
 int cols = 11;
 switch (this->num)
 {
 case 1:
   for (int n = 0; n < cols; n++)
   {
     blocks.append(new Block::Block(0, SILVER2, 1, this->num, n, 5));
     blocks.append(new Block::Block(0, RED, 1, this->num, n, 6));
     blocks.append(new Block::Block(0, BLUE, 1, this->num, n, 7));
     blocks.append(new Block::Block(0, YELLOW, 1, this->num, n, 8));
     blocks.append(new Block::Block(0, PINK, 1, this->num, n, 9));
     blocks.append(new Block::Block(0, GREEN, 1, this->num, n, 10));
   }
  break;
 case 2:
  break;
 case 3:
  break;
 default:
  break;
 }
}
