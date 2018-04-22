#ifndef POINT_H
#define POINT_H

#include <QGraphicsItem>
#include <QPainterPath>
#include <QRect>
#include <QVariant>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

class PortNode;
class point : public QGraphicsItem
{
public:
    point(PortNode *node);


    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;


    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    PortNode *node;
};

#endif // POINT_H
