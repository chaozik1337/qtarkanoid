#include "mainwindow.h"

mainwindow::mainwindow(QWidget *parent) :
    QWidget(parent)
{
  this->setFixedSize(800, 650);
  arkanoid = new Arkanoid();
  layout = new QHBoxLayout;
  vlayout = new QVBoxLayout;
  timer = new QTimer(this);
  txt = new QTextEdit(this);
  LCDScore = new QLCDNumber(this);
  LCDLives = new QLCDNumber(this);
  LCDLevel = new QLCDNumber(this);
  lblScore = new QLabel(this);
  lblLives = new QLabel(this);
  lblLevel = new QLabel(this);

  txt->setFixedWidth(100);
  lblScore->setText("Score");
  LCDScore->display(100);
  lblLives->setText("Lives");
  lblLevel->setText("Level");

  vlayout->addWidget(lblScore);
  vlayout->addWidget(LCDScore);
  vlayout->addWidget(lblLives);
  vlayout->addWidget(LCDLives);
  vlayout->addWidget(lblLevel);
  vlayout->addWidget(LCDLevel);

  layout->addLayout(vlayout);
  layout->addWidget(arkanoid);
  layout->addWidget(txt);
  setLayout(layout);

  connect(timer,SIGNAL(timeout()), this, SLOT(timerTick()));
}

void mainwindow::keyPressEvent(QKeyEvent *event)
{
  switch (event->key())
  {
  case Qt::Key_P:
    {
      if (arkanoid->isGameStarted())
      {
        arkanoid->pauseGame();
        if (arkanoid->isPaused())
        {
          this->setWindowTitle("qtArkanoid (paused)");
        }
        else
        {
          this->setWindowTitle("qtArkanoid (running)");
        }
      }
    }
    break;
  case Qt::Key_Space:
    {
    }
    break;
  case Qt::Key_Escape:
    {
      qApp->exit();
    }
    break;
  default:
    QWidget::keyPressEvent(event);
  }
}

void mainwindow::mousePressEvent(QMouseEvent *event)
{
  if (event->button() == Qt::LeftButton)
  {
    arkanoid->startGame();
    if (arkanoid->isGameStarted())
    {
      this->setWindowTitle("qtArkanoid (running)");
      timer->start(10);
    }
  }
}

void mainwindow::timerTick()
{
 this->txt->setText(QString::number(arkanoid->hitCount) + "\n" + QString::number(arkanoid->ball->getPosX()) + "," + QString::number(arkanoid->ball->getPosY()) + "\n" + QString::number(arkanoid->ball->speedResultant));
  //this->txt->setText(QString::number(arkanoid->ball->getPosX()) + "," + QString::number(arkanoid->ball->getPosY()));

  if (arkanoid->ball->checkBallPosition())
  {
    if (arkanoid->checkCollision())
    {

    }
    //ball->moveBall(pos.x(), pos.y(), gameAreaWidth, gameAreaHeight);
    arkanoid->ball->moveBall(arkanoid->ball->getPosX(), arkanoid->ball->getPosY(), arkanoid->getGameAreaW(), arkanoid->getGameAreaH());
    arkanoid->repaint();
  }
}
