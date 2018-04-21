#include "gBlock.h"

gBlock::gBlock(QGraphicsScene *scene, QPointF pos)
{
    this->scene = scene;
    this->pos = pos;
    QBrush redBrush(Qt::red);
    QPen blackpen(Qt::black);
    blackpen.setWidth(1);

    int number = 4;
    Y *= number;

    rectangle = scene->addRect(0, 0, X, Y,blackpen, redBrush );
    rectangle->setFlag(QGraphicsItem::ItemIsMovable);
    rectangle->setFlag(QGraphicsItem::ItemIsSelectable);
    rectangle->setPos(pos);
}

gBlock::gBlock(QGraphicsScene *scene, QPointF pos, Block *block)
{
    this->scene = scene;
    this->pos = pos;
    this->block = block;

    QBrush redBrush(Qt::red);
    QPen blackpen(Qt::black);
    blackpen.setWidth(1);

    if (block->getPortsInputCount() >= block->getPortsOutputCount()) {
        Y *= block->getPortsInputCount();
    }
    else {
        Y *= block->getPortsOutputCount();
    }

    rectangle = scene->addRect(0, 0, X, Y,blackpen, redBrush );
    rectangle->setFlag(QGraphicsItem::ItemIsMovable);
    rectangle->setFlag(QGraphicsItem::ItemIsSelectable);
    rectangle->setPos(pos);
}
