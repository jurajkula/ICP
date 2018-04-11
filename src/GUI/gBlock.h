#ifndef GBLOCK_H
#define GBLOCK_H

#include <QBrush>
#include <QPen>
#include <QGraphicsEllipseItem>
#include <qgraphicsscene.h>
#include <QMouseEvent>
#include <QDebug>


class gBlock
{

public:
    explicit gBlock(QGraphicsScene *scene, QPointF pos);
    ~gBlock();

private slots:


private:
    QGraphicsScene *scene;
    QGraphicsRectItem *rectangle;
    int sizeX = 100;
    int sizeY = 50;
    QPointF pos;
    int a = 10;
    int b = 10;
};

#endif // GBLOCK_H
