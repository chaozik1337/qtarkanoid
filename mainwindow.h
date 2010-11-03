#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTimer>
#include <QApplication>
#include <QTextEdit>
#include <QLCDNumber>
#include <QLabel>
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
  QVBoxLayout *vlayout;
  QTimer *timer;
  QTextEdit *txt;
  QLCDNumber *LCDScore;
  QLCDNumber *LCDLives;
  QLCDNumber *LCDLevel;
  QLabel *lblScore;
  QLabel *lblLives;
  QLabel *lblLevel;

signals:

public slots:
  void timerTick();

};

#endif // MAINWINDOW_H
