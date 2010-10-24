#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QApplication>
#include "arkanoid.h"

class mainwindow : public QWidget
{
  Q_OBJECT
public:
  explicit mainwindow(QWidget *parent = 0);
  Arkanoid *arkanoid;

protected:
  void keyPressEvent(QKeyEvent *event);
  void mousePressEvent(QMouseEvent *event);

private:
  QHBoxLayout *layout;
signals:

public slots:

};

#endif // MAINWINDOW_H
