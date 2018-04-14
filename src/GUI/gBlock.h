#ifndef GBLOCK_H
#define GBLOCK_H

#include <QBrush>
#include <QPen>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QDebug>

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
     * @brief sizeX
     */
    int sizeX = 100;

    /**
     * @brief sizeY
     */
    int sizeY = 50;

    /**
     * @brief pos Position
     */
    QPointF pos;

    /**
     * @brief a
     */
    int a = 10;

    /**
     * @brief b
     */
    int b = 10;
};

#endif // GBLOCK_H
