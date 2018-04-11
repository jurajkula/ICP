#include "gBlock.h"

gBlock::gBlock(QGraphicsScene *scene, QPointF pos)
{
    this->scene = scene;
    this->pos = pos;
    QBrush redBrush(Qt::red);
    QPen blackpen(Qt::black);
    blackpen.setWidth(1);

    rectangle = scene->addRect(a,b, sizeX, sizeY,blackpen, redBrush );
    rectangle->setFlag(QGraphicsItem::ItemIsMovable);
    rectangle->setFlag(QGraphicsItem::ItemIsSelectable);
    rectangle->setPos(pos);
}
