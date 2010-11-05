#ifndef BLOCK_H
#define BLOCK_H

#include <QWidget>
#include <QImage>
#include <QRect>

class Block : public QWidget
{
    Q_OBJECT
public:
    explicit Block(QWidget *parent = 0, int num = 1, int lvl = 1, int posX = 0, int posY = 0);
    ~Block();
    QRect getRect();
    QImage & getImage();
    int posX;
    int posY;
    int hitsNeeded;
    double score;
    int blockNum;
    QString color;

private:
    QImage image;
    QRect rect;

signals:

public slots:

};

#endif // BLOCK_H
