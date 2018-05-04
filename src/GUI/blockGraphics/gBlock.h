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
    /**
     * @brief scene Scene
     */
    QGraphicsScene *scene;

    /**
     * @brief rectangle GUI rectangle
     */
    Rectangle *rectangle;

    /**
     * @brief nodePosStartY Start position of node
     */
    int nodePosStartY = 25;

    /**
     * @brief pos Position
     */
    QPointF pos;

    /**
     * @brief block Pointer to logic block
     */
    Block *block;

    /**
     * @brief nodes Vector of graphics ports
     */
    std::vector<PortNode *> nodes;

    /**
     * @brief scheme Pointer to logic scheme
     */
    Scheme *scheme;
};

#endif // GBLOCK_H
