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
    int x1;
    int x2;
    int y1;
    int y2;
    int hitsNeeded;
    double score;
    int blockNum;
    QString color;
    QImage image;
    QRect rect;

private:


signals:

public slots:

};

#endif // BLOCK_H
