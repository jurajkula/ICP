#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "portnode.h"

#include <QPen>

class Rectangle : public QGraphicsRectItem
{
public:
    Rectangle(QGraphicsScene *scene, int Ymul, std::vector<PortNode *> *nodes, QPointF Ppos);

    int getX();
    int getY();


    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    enum { Type = UserType + 3 };
    int type() const override;

    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
private:
    QGraphicsScene *scene;

    /**
     * @brief X
     */
    int X = 100;

    /**
     * @brief Y
     */
    int Y = 50;

    int Ymul = 0;

    std::vector<PortNode*> *nodes;

    QPointF Ppos;
};

#endif // RECTANGLE_H
