#include <QApplication>
#include "mainwindow.h"
//#include "arkanoid.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  mainwindow::mainwindow *game = new mainwindow();
  game->arkanoid->setVisible(true);
  game->show();

  return app.exec();
}
