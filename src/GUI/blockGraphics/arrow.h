#ifndef ARROW_H
#define ARROW_H

#include "portnode.h"

#include <QGraphicsItem>
#include <cmath>

class PortNode;
class point;

class Arrow : public QGraphicsItem
{
public:
    Arrow(PortNode *surceNode, PortNode *destNode);
    Arrow(PortNode *sourceNode, point *destPoint);

    void adjust();

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
private:
    PortNode *source, *dest;
    point *destP;
    bool isDestP;

    QPointF sourcePoint;
    QPointF destPoint;
    qreal arrowSize;
};

#endif // ARROW_H
