#include <QApplication>
#include "arkanoid.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  Arkanoid::Arkanoid *game = new Arkanoid();
  game->resize(500,500);
  game->show();

  return app.exec();
}
