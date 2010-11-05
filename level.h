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

signals:

public slots:

};

#endif // LEVEL_H
