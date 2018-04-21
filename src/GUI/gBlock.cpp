#include "gBlock.h"
#include "portnode.h"

gBlock::gBlock(QGraphicsScene *scene, QPointF pos)
{
    this->scene = scene;
    this->pos = pos;
    QBrush redBrush(Qt::red);
    QPen blackpen(Qt::black);
    blackpen.setWidth(1);

    int number = 4;
    Y *= number;

    group = new QGraphicsItemGroup();

    PortNode *pn = new PortNode();
    PortNode *pn1 = new PortNode();
    pn->setPos(0,20);
    pn1->setPos(0,60);

    rectangle = scene->addRect(0, 0, X, Y,blackpen, redBrush );
    //rectangle->setFlag(QGraphicsItem::ItemIsMovable);
    //rectangle->setFlag(QGraphicsItem::ItemIsSelectable);
    //rectangle->setPos(pos);

    group->addToGroup(rectangle);
    group->addToGroup(pn);
    group->addToGroup(pn1);

    group->setFlag(QGraphicsItem::ItemIsMovable);
    group->setPos(pos);

    scene->addItem(group);
}

gBlock::gBlock(QGraphicsScene *scene, QPointF pos, Block *block)
{
    this->scene = scene;
    this->pos = pos;
    this->block = block;

    group = new QGraphicsItemGroup();

    QBrush redBrush(Qt::red);
    QPen blackpen(Qt::black);
    blackpen.setWidth(1);

    int sizeY = Y;
    if (block->getPortsInputCount() >= block->getPortsOutputCount()) {
        sizeY *= block->getPortsInputCount();
    }
    else {
        sizeY *= block->getPortsOutputCount();
    }

    rectangle = scene->addRect(0, 0, X, sizeY,blackpen, redBrush );
    /*rectangle->setFlag(QGraphicsItem::ItemIsMovable);
    rectangle->setFlag(QGraphicsItem::ItemIsSelectable);
    rectangle->setPos(pos);*/

    group->addToGroup(rectangle);

    for (int i = 0; i < block->getPortsInputCount(); i++) {
        PortNode *pNode = new PortNode();
        pNode->setPos(0, nodePosStartY + Y * i);
        group->addToGroup(pNode);
    }

    for (int i = 0; i < block->getPortsOutputCount(); i++) {
        PortNode *pNode = new PortNode();
        pNode->setPos(X, nodePosStartY + Y * i);
        group->addToGroup(pNode);
    }

    group->setFlag(QGraphicsItem::ItemIsMovable);
    group->setPos(pos);

    scene->addItem(group);
}
