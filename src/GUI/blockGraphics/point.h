#ifndef POINT_H
#define POINT_H

#include <QGraphicsItem>
#include <QPainterPath>
#include <QRect>
#include <QVariant>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsSceneMouseEvent>

#include "portnode.h"

class PortNode;
class Arrow;

class point : public QGraphicsItem
{
public:
    point(PortNode *node, QGraphicsScene *scene);

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    enum { Type = UserType + 1 };
    int type() const override;
protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
private:
    PortNode *node;
    Arrow *line;
    QGraphicsScene *scene;
};

#endif // POINT_H
