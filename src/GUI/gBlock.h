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
     * @brief X2
     */
    int X2 = 100;

    /**
     * @brief Y2
     */
    int Y2 = 50;

    /**
     * @brief X1
     */
    int X1 = 10;

    /**
     * @brief Y2
     */
    int Y1 = 10;

    /**
     * @brief pos Position
     */
    QPointF pos;

    Block *block;
};

#endif // GBLOCK_H
