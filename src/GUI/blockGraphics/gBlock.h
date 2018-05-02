/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul pre obalenie grafických komponent bloku
*/

#ifndef GBLOCK_H
#define GBLOCK_H

#include "rectangle.h"

#include <QGraphicsEllipseItem>
#include <QMouseEvent>
#include <QDebug>

#include <src/LOGIC/block.hpp>

/**
 * @brief The gBlock class
 */
class gBlock
{
public:
    /**
     * @brief gBlock Constructor of the class
     * @param scheme Pointer to logic scheme
     * @param scene Pointer to graphics scene
     * @param pos Position of the click
     * @param block Pointer to logic block
     */
    gBlock(Scheme *scheme, QGraphicsScene *scene, QPointF pos, Block *block);
    ~gBlock();

    /**
     * @brief getLogicBlock Function which returns pointer to logic block
     * @return Pointer to logic block
     */
    Block *getLogicBlock();

private slots:

protected:
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
    Scheme *scheme;
};

#endif // GBLOCK_H
