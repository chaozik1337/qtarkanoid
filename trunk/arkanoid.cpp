#include "arkanoid.h"
#include "mainwindow.h"
#include <QPainter>
//#include <QApplication>

Arkanoid::Arkanoid(QWidget *parent) : QWidget(parent)
{
  x = 0;
  gameOver = FALSE;
  gameWon = FALSE;
  paused = FALSE;
  gameStarted = FALSE;
  paddle = new Paddle();
  ball = new Ball();
  //startGame();
  setWindowTitle("qtArkanoid");
  setMouseTracking(true);
  setGameArea(520, 600);
  this->setFixedSize(gameAreaWidth, gameAreaHeight);
  this->setPalette(QPalette(Qt::black));
  this->setAutoFillBackground(true);
}

Arkanoid::~Arkanoid()
{
  delete paddle;
}

int Arkanoid::getGameAreaW()
{
  return gameAreaWidth;
}

int Arkanoid::getGameAreaH()
{
  return gameAreaHeight;
}

bool Arkanoid::setGameArea(int width, int height)
{
  if (height > 0)
  {
    gameAreaHeight = height;
  }

  if (width > 0)
  {
    gameAreaWidth = width;
  }
}

void Arkanoid::paintEvent(QPaintEvent *event)
{
  QPainter painter(this);

  if (gameOver)
  {
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width("Game Over");

    painter.setFont(font);
    int h = height();
    int w = width();

    painter.translate(QPoint(w/2, h/2));
    painter.drawText(-textWidth/2, 0, "Game Over");
  }

  else if(gameWon)
  {
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width("Victory");

    painter.setFont(font);
    int h = height();
    int w = width();

    painter.translate(QPoint(w/2, h/2));
    painter.drawText(-textWidth/2, 0, "Victory");
  }

  else
  {
    painter.drawImage(paddle->getRect(), paddle->getImage());
    painter.drawImage(ball->getRect(), ball->getImage());
  }
}

void Arkanoid::mouseMoveEvent(QMouseEvent *event)
{
  if (gameStarted == true && paused == false)
  {
    QPoint pos = event->pos();
    paddle->movePaddle(pos.x(), gameAreaWidth);
    //ball->moveBall(pos.x(), pos.y(), gameAreaWidth, gameAreaHeight);
  }

}

void Arkanoid::startGame()
{
  if (!gameStarted)
  {
    paddle->resetState();

    gameOver = FALSE;
    gameWon = FALSE;
    gameStarted = TRUE;
    timerId = startTimer(10);
  }
}

bool Arkanoid::isPaused()
{
  if (paused)
  {
    return true;
  }

  return false;
}

bool Arkanoid::isGameStarted()
{
  if (gameStarted)
  {
    return true;
  }

  return false;
}

void Arkanoid::pauseGame()
{
  if (paused)
  {
    timerId = startTimer(10);
    paused = FALSE;
  }
  else
  {
    paused = TRUE;
    killTimer(timerId);
  }
}

void Arkanoid::stopGame()
{
  killTimer(timerId);
  gameOver = TRUE;
  gameStarted = FALSE;
}

void Arkanoid::victory()
{
  killTimer(timerId);
  gameWon = TRUE;
  gameStarted = FALSE;
}
