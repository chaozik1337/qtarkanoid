#ifndef LEVEL_H
#define LEVEL_H

#include <QWidget>
#include "block.h"

class Level : public QWidget
{
 Q_OBJECT
public:
 explicit Level(QWidget *parent = 0, int num = 0);
 QList<Block*> blocks;
 int num;
 enum colors {WHITE = 1, ORANGE = 2, LBLUE = 3, GREEN = 4, RED = 5, BLUE = 6, PINK = 7, YELLOW = 8, SILVER = 9, SILVER2 = 10, GOLD = 11};

signals:

public slots:

};

#endif // LEVEL_H
