#include "arkanoid.h"
#include "mainwindow.h"
#include <QPainter>
//#include <QApplication>

Arkanoid::Arkanoid(QWidget *parent) : QWidget(parent)
{
  x = 0;
  this->score = 0;
  this->lives = 3;
  this->level = 1;
  gameOver = FALSE;
  gameWon = FALSE;
  paused = FALSE;
  gameStarted = FALSE;
  paddle = new Paddle();
  ball = new Ball();
  //block = new Block(this, 1, this->level, 0, 0);
  lvl = new Level(this, this->level);
  //startGame();
  setWindowTitle("qtArkanoid");
  setMouseTracking(true);
  setGameArea(440, 570);
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

    if (ball->nextPosX > gameAreaWidth - 6) //ball hits right wall
    {
      ball->speedX = -1 * ball->speedX;
      ball->posX = gameAreaWidth - 6;
      ball->nextPosX = ball->posX;
      ret = true;
    }

    else if (ball->nextPosX < 6) //ball hits left wall
    {
      ball->speedX = -1 * ball->speedX;
      ball->posX = 6;
      ball->nextPosX = ball->posX;
      ret = true;
    }

    else //ball doesn't hit walls
    {
      for (int n = 0; n < this->lvl->blocks.count(); n++) //loop all remaining blocks for hit
      {
        //check if ball nextPosX is between blocks x1 and x2 coordinates
        bool XHit = false;
        if (this->ball->speedX < 0) //ball is going left
        {
          if (floor(this->ball->nextPosX) - 6 >= this->lvl->blocks[n]->x1 && floor(this->ball->nextPosX) - 6 <= this->lvl->blocks[n]->x2)
            XHit = true;
        }
        else //ball is going right
        {
          if (floor(this->ball->nextPosX) + 6 >= this->lvl->blocks[n]->x1 && floor(this->ball->nextPosX) + 6 <= this->lvl->blocks[n]->x2)
            XHit = true;
        }

        if (XHit)
        {
          //check if ball posY is between y1 and y2 coordinates
          bool YHit = false;

          if (floor(this->ball->posY) <= this->lvl->blocks[n]->y2 + 6 && floor(this->ball->posY) >= this->lvl->blocks[n]->y1 - 6)
            YHit = true;

          if (XHit && YHit)
          {
            if (checkVictory(n))
            {
              this->victory();
            }
            else
            {
              this->ball->speedX = -1 * this->ball->speedX;
              this->ball->posX = floor(ball->nextPosX);
            }
            ret = true;
          }
        }

      }
      ball->posX = floor(ball->nextPosX);
    }
  }

  if (ball->YChanged)
  {
    //check if ball hit top
    if (ball->nextPosY < 6)
    {
      ball->speedY = -1 * ball->speedY;
      ball->posY = 6;
      ball->nextPosY = ball->posY;
      ret = true;
    }

    //if ball hit paddle
    //hoplaa
    else if (floor(ball->nextPosY) >= 500 - 12 && floor(ball->nextPosY) < 500 - 12 + 5)
    {
      hitCount++;
      if (floor(ball->posX) >= paddle->getPosX() - 40 - 12 && floor(ball->posX) <= paddle->getPosX() + 40)
      {
        if (ball->speedY > 0)
        {
          double dif = paddle->getPosX() - (floor(ball->posX) + 6.0);
          if (dif > 0) //ball hits left side of paddle
          {
            if (dif > 40)
            {
              ball->speedX = -1 * ball->speedResultant / sqrt(1 + pow(tan((90.0 - 80.0) / 180.0 * PI),2));
              ball->speedY = -1 * sqrt(pow(ball->speedResultant,2) - pow(ball->speedX,2));
            }
            else
            {
              ball->speedX = -1 * ball->speedResultant / sqrt(1 + pow(tan((90.0 - dif * 2.0) / 180.0 * PI),2));
              ball->speedY = -1 * sqrt(pow(ball->speedResultant,2) - pow(ball->speedX,2));
            }
            ball->posY = floor(ball->nextPosY);
            ret = true;
          }

          if (dif < 0) //ball hits right side of paddle
          {
            if (dif < -40)
            {
              ball->speedX = ball->speedResultant / sqrt(1 + pow(tan((90.0 - 80.0) / 180.0 * PI),2));
              ball->speedY = -1 * sqrt(pow(ball->speedResultant,2) - pow(ball->speedX,2));
            }
            else
            {
              ball->speedX = ball->speedResultant / sqrt(1 + pow(tan((90.0 - qAbs(dif) * 2) / 180.0 * PI),2));
              ball->speedY = -1 * sqrt(pow(ball->speedResultant,2) - pow(ball->speedX,2));
            }
          }

          if (dif == 0) //ball hits center of paddle
          {
            ball->speedX = 0;
            ball->speedY = ball->speedResultant;
          }
        }
      }
    }

    //testing only
    else if (ball->nextPosY > 570 - 12)
    {
      lives = lives - 1;
      if (lives == 0)
      {
        this->stopGame();
      }
      ball->speedY = -1 * ball->speedY;
      ball->posY = 570 - 12;
      ball->nextPosY = ball->posY;
      ret = true;
    }

    //check if ball hits blocks
    //hoplaa
    else
    {
      for (int n = 0; n < this->lvl->blocks.count(); n++)
      {
        bool XHit = false;
        if (this->ball->speedX < 0) //ball is going left
        {
          if (floor(this->ball->posX) >= this->lvl->blocks[n]->x1 && floor(this->ball->posX) <= this->lvl->blocks[n]->x2)
            XHit = true;
        }
        else //ball is going right
        {
          if (floor(this->ball->posX) + 12 >= this->lvl->blocks[n]->x1 && floor(this->ball->posX) <= this->lvl->blocks[n]->x2)
            XHit = true;
        }

        if (floor(this->ball->posX) >= this->lvl->blocks[n]->x1 && floor(this->ball->posX) <= this->lvl->blocks[n]->x2)
        {
        }

        bool YHit = false;
        if (this->ball->speedY < 0) //ball is going upwards
        {
          if (floor(this->ball->nextPosY) <= this->lvl->blocks[n]->y2 && floor(this->ball->nextPosY) >= this->lvl->blocks[n]->y1)
            YHit = true;
        }
        else //ball is going downwards
        {
          if (floor(this->ball->nextPosY + 12) <= this->lvl->blocks[n]->y2 && floor(this->ball->nextPosY + 12) >= this->lvl->blocks[n]->y1)
            YHit = true;
        }

        if (XHit && YHit)
        {
          if (checkVictory(n))
          {
            this->victory();
          }
          else
          {
            this->ball->speedY = -1 * this->ball->speedY;
            this->ball->posY = floor(this->ball->nextPosY);
          }
          ret = true;
        }

      }
      ball->posY = floor(ball->nextPosY);
    }
  }

  return ret;
}

bool Arkanoid::checkVictory(int n)
{
  this->score = this->score + this->lvl->blocks[n]->score;
  this->lvl->blocks.removeAt(n);
  if (this->lvl->blocks.count() == 0)
  {
    return true;
  }
  return false;
}

int Arkanoid::getGameAreaW()
{
  return gameAreaWidth;
}

int Arkanoid::getGameAreaH()
{
  return gameAreaHeight;
}

void Arkanoid::setGameArea(int width, int height)
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

  else if(!paused)
  {
    painter.drawImage(paddle->getRect(), paddle->getImage());
    painter.drawImage(ball->posX - 6, ball->posY - 6, ball->getImage());
    //painter.drawImage(block->getRect(), block->getImage());
    for (int n = 0; n < this->lvl->blocks.count(); n++)
    {
      painter.drawImage(this->lvl->blocks[n]->getRect(), this->lvl->blocks[n]->getImage());
    }
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
