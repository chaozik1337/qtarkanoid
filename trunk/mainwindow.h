#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QHBoxLayout>
#include "arkanoid.h"

class mainwindow : public QWidget
{
  Q_OBJECT
public:
  explicit mainwindow(QWidget *parent = 0);
  Arkanoid *arkanoid;

private:
  QHBoxLayout *layout;
signals:

public slots:

};

#endif // MAINWINDOW_H
