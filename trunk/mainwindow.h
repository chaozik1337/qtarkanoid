#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QTimer>
#include <QApplication>
#include <QTextEdit>
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
  QTimer *timer;
  QTextEdit *txt;
signals:

public slots:
  void timerTick();

};

#endif // MAINWINDOW_H
