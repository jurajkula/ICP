#ifndef GBLOCK_H
#define GBLOCK_H

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
    /**
     * @brief gBlock Construcotr of class
     * @param scene Scene
     * @param pos Position
     */
    explicit gBlock(QGraphicsScene *scene, QPointF pos);

    gBlock(QGraphicsScene *scene, QPointF pos, Block *block);
    ~gBlock();

private slots:


private:
    /**
     * @brief scene Scene
     */
    QGraphicsScene *scene;

    /**
     * @brief rectangle GUI rectangle
     */
    QGraphicsRectItem *rectangle;

    /**
     * @brief X
     */
    int X = 100;

    /**
     * @brief Y
     */
    int Y = 50;

    /**
     * @brief pos Position
     */
    QPointF pos;

    Block *block;
};

#endif // GBLOCK_H
