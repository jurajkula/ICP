#ifndef GBLOCK_H
#define GBLOCK_H

#include "portnode.h"
#include "rectangle.h"

#include <QBrush>
#include <QPen>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QDebug>

#include <src/LOGIC/block.hpp>

/**
 * @brief The gBlock class
 */
class gBlock
{
public:

    gBlock(QGraphicsScene *scene, QPointF pos, Block *block);
    ~gBlock();

private slots:

protected:
    void redrawPorts();
private:
    QGraphicsItemGroup *group;

    /**
     * @brief scene Scene
     */
    QGraphicsScene *scene;

    /**
     * @brief rectangle GUI rectangle
     */
    Rectangle *rectangle;

    int nodePosStartY = 25;
    /**
     * @brief pos Position
     */
    QPointF pos;

    Block *block;
    std::vector<PortNode *> nodes;
};

#endif // GBLOCK_H
