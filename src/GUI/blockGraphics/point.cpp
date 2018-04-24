#include "point.h"

point::point(PortNode *node, QGraphicsScene *scene)
{
    this->node = node;
    this->scene = scene;

    setFlag(ItemSendsGeometryChanges);
    setFlag(ItemIsMovable);

    line = new Arrow(node, this);
    scene->addItem(line);
    line->adjust();
}

QRectF point::boundingRect() const
{
    qreal adjust = 2;
    return QRectF( -10 - adjust, -10 - adjust, 23 + adjust, 23 + adjust);
}

QPainterPath point::shape() const
{
    QPainterPath path;
    path.addEllipse(this->boundingRect());
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
        this->line->adjust();
        break;
    default:
        break;
    };
    return QGraphicsItem::itemChange(change, value);
}

void point::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //qDebug("Pressed");
    update();
    QGraphicsItem::mousePressEvent(event);
}

void point::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    //qDebug("Move");
    update();
    QGraphicsItem::mouseMoveEvent(event);
}

void point::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    //qDebug("Release");
    QGraphicsItem::mouseReleaseEvent(event);

    //TODO kontorla, ci sa nenamapovalo na iny port, ak ano, kontrola +

    this->setPos(this->node->pos());
}
