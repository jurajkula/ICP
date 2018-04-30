/* Autory : Juraj Kula , Michal Vasko
 * Popis:
 *                                   */

#include "gBlock.h"

gBlock::gBlock(Scheme *scheme, QGraphicsScene *scene, QPointF pos, Block *block)
{
    this->scene = scene;
    this->pos = pos;
    this->block = block;
    this->scheme = scheme;

    if (block->getPortsInputCount() >= block->getPortsOutputCount()) {
        rectangle = new Rectangle(scheme, this->scene, block->getPortsInputCount(), &nodes, pos, block);
    }
    else {
        rectangle = new Rectangle(scheme, this->scene, block->getPortsOutputCount(), &nodes, pos, block);
    }

    rectangle->setPos(pos);
    scene->addItem(rectangle);

    int inPorts = 0;
    int outPorts = 0;
    for (port *p : *(block->getPorts())) {
        PortNode *pNode = new PortNode(p, scheme, scene);
        nodes.push_back(pNode);

        if (p->getStatus() == INPUT) {
            pNode->setPos(pos.x() +  0, pos.y() + nodePosStartY + rectangle->getY() * inPorts);
            inPorts++;
        }
        else {
            pNode->setPos(pos.x() + rectangle->getX(), pos.y() + nodePosStartY + rectangle->getY() * outPorts);
            outPorts++;
        }
    }
}

Block *gBlock::getLogicBlock()
{
    return this->block;
}

void gBlock::redrawPorts() {

}
