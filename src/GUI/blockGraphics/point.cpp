#include "point.h"

point::point(PortNode *node)
{
    this->node = node;

    setFlag(ItemSendsGeometryChanges);
    setFlag(ItemIsMovable);
}

QRectF point::boundingRect() const
{
    qreal adjust = 2;
    return QRectF( -10 - adjust, -10 - adjust, 23 + adjust, 23 + adjust);
}

QPainterPath point::shape() const
{
    QPainterPath path;
    path.addEllipse(-5, -5, 10, 10);
    return path;
}

void point::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::darkGray);
    painter->drawEllipse(-1, -1, 1, 1);
}

QVariant point::itemChange(GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:

        break;
    default:
        break;
    };
    return QGraphicsItem::itemChange(change, value);
}

void point::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug("Pressed");
    update();
    QGraphicsItem::mousePressEvent(event);
}

void point::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    qDebug("Move");
    update();
    QGraphicsItem::mouseMoveEvent(event);
}

void point::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    qDebug("Release");
    QGraphicsItem::mouseReleaseEvent(event);
}
