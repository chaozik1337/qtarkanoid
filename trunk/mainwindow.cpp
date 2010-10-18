#include "mainwindow.h"

mainwindow::mainwindow(QWidget *parent) :
    QWidget(parent)
{
  this->setFixedSize(800, 650);
  arkanoid = new Arkanoid();
  layout = new QHBoxLayout;

  layout->addWidget(arkanoid);
  setLayout(layout);
  //arkanoid->setVisible(false);
}
