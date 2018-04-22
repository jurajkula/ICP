#include "gBlock.h"
#include "portnode.h"

gBlock::gBlock(QGraphicsScene *scene, QPointF pos, Block *block)
{
    this->scene = scene;
    this->pos = pos;
    this->block = block;

    if (block->getPortsInputCount() >= block->getPortsOutputCount()) {
        rectangle = new Rectangle(this->scene, block->getPortsInputCount(), &nodes, pos);
    }
    else {
        rectangle = new Rectangle(this->scene, block->getPortsInputCount(), &nodes, pos);
    }

    rectangle->setPos(pos);
    scene->addItem(rectangle);


    for (int i = 0; i < block->getPortsInputCount(); i++) {
        PortNode *pNode = new PortNode(scene);
        pNode->setPos(pos.x() +  0, pos.y() + nodePosStartY + rectangle->getY() * i);
        nodes.push_back(pNode);
        //scene->addItem(pNode);
    }

    for (int i = 0; i < block->getPortsOutputCount(); i++) {
        PortNode *pNode = new PortNode(scene);
        pNode->setPos(pos.x() + rectangle->getX(), pos.y() + nodePosStartY + rectangle->getY() * i);
        nodes.push_back(pNode);
        //scene->addItem(pNode);
    }
}

void gBlock::redrawPorts() {

}
