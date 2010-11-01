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
 hitCount = 0;
}

Arkanoid::~Arkanoid()
{
 delete paddle;
}

bool Arkanoid::checkCollision()
{
 bool ret = false;

 if (ball->XChanged)
 {
  if (ball->nextPosX > 520 - 11)
  {
   ball->speedX = -1 * ball->speedX;
   ball->posX = 520 - 11;
   ball->nextPosX = ball->posX;
   ret = true;
  }
  else if (ball->nextPosX < 0)
  {
   ball->speedX = -1 * ball->speedX;
   ball->posX = 0;
   ball->nextPosX = ball->posX;
   ret = true;
  }
  else
  {
   ball->posX = floor(ball->nextPosX);
  }
 }

 if (ball->YChanged)
 {
  //check if ball hit top
  if (ball->nextPosY < 0)
  {
   ball->speedY = -1 * ball->speedY;
   ball->posY = 0;
   ball->nextPosY = ball->posY;
   ret = true;
  }

  //if ball hit paddle
  else if (floor(ball->nextPosY) >= 500 - 12 && floor(ball->nextPosY) < 500 - 12 + 5)
  {
   hitCount++;
   if (floor(ball->posX) >= paddle->getPosX() - 40 - 12 && floor(ball->posX) <= paddle->getPosX() + 40)
   {
    if (ball->speedY > 0)
    {
      double dif = paddle->getPosX() - floor(ball->posX) + 6;
      if (dif > 0) //ball hits left side of paddle
      {
        if (dif > 40)
        {
          ball->speedX = -1 * ball->getSpeedResultant() / sqrt(1 + pow(tan((90 - 80) / 180 * PI),2));
          ball->speedY = -1 * sqrt(pow(ball->getSpeedResultant(),2) - pow(ball->speedX,2));
        }
        else
        {
          ball->speedX = -1 * ball->getSpeedResultant() / sqrt(1 + pow(tan((90 - dif * 2) / 180 * PI),2));
          ball->speedY = -1 * sqrt(pow(ball->getSpeedResultant(),2) - pow(ball->speedX,2));
        }
        ball->posY = floor(ball->nextPosY);
        ret = true;
      }

      if (dif < 0) //ball hits right side of paddle
      {
        if (dif < -40)
        {
          ball->speedX = ball->getSpeedResultant() / sqrt(1 + pow(tan((90 - 80) / 180 * PI),2));
          ball->speedY = -1 * sqrt(pow(ball->getSpeedResultant(),2) - pow(ball->speedX,2));
        }
        else
        {
          ball->speedX = ball->getSpeedResultant() / sqrt(1 + pow(tan((90 - qAbs(dif) * 2) / 180 * PI),2));
          ball->speedY = -1 * sqrt(pow(ball->getSpeedResultant(),2) - pow(ball->speedX,2));
        }
      }

      if (dif == 0) //ball hits center of paddle
      {
        ball->speedX = 0;
        ball->speedY = ball->getSpeedResultant();
      }
    }
   }
  }

  //testing only
  else if (ball->nextPosY > 600 - 12)
  {
   ball->speedY = -1 * ball->speedY;
   ball->posY = 600 - 12;
   ball->nextPosY = ball->posY;
   ret = true;
  }

  else
  {
   ball->posY = floor(ball->nextPosY);
  }
 }

 return ret;
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
