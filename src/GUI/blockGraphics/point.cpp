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
    if ((this->node->getLogicPort()->getStatus() == INPUT) || (this->node->getLogicPort()->isConnected()))
        return;

    update();
    QGraphicsItem::mousePressEvent(event);
}

void point::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if ((this->node->getLogicPort()->getStatus() == INPUT) || (this->node->getLogicPort()->isConnected()))
        return;

    update();
    QGraphicsItem::mouseMoveEvent(event);
}

void point::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if ((this->node->getLogicPort()->getStatus() == INPUT) || (this->node->getLogicPort()->isConnected()))
        return;

    update();
    QGraphicsItem::mouseReleaseEvent(event);

    foreach (QGraphicsItem *item, scene->items()) {
        PortNode *n = qgraphicsitem_cast<PortNode *>(item);
        if(!n)
            continue;

        if (n == this->node)
            continue;

        if(n->collidesWithItem(this)) {
            qDebug("Port to Port");
            if (node->getScheme()->createConnection(this->node->getLogicPort(), n->getLogicPort())) {
                Arrow *portArrow = new Arrow(this->node, n);
                scene->addItem(portArrow);
                portArrow->adjust();
                qDebug("CONNECTED");
            }
            break;
        }
    }

    this->setPos(this->node->pos());
}

void point::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::RightButton) {
        if (!this->node->getLogicPort()->isConnected())
            return;

        qDebug("DELETE");
        Arrow *portArrow = this->node->getArrow();

        if (this->node->getLogicPort()->getStatus() == INPUT) {
            node->getScheme()->destroyConnection(portArrow->getSourceNode()->getLogicPort(), this->node->getLogicPort());
            portArrow->getSourceNode()->deleteArrowPointer();
        }
        else {
            node->getScheme()->destroyConnection(this->node->getLogicPort(), portArrow->getDestNode()->getLogicPort());
            portArrow->getDestNode()->deleteArrowPointer();
        }

        this->node->deleteArrowPointer();
        this->scene->removeItem(portArrow);
        delete(portArrow);
        portArrow = nullptr;

        update();
        QGraphicsItem::mouseDoubleClickEvent(event);
    }
}

int point::type() const {
    return Type;
}
