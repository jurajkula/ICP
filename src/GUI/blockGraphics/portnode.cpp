/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul pre grafické zobrazenie portu (vykreslenie portu)
*/

#include "portnode.h"

#include <QEvent>
#include <QMouseEvent>

PortNode::PortNode(port *logicPort, Scheme *scheme, QGraphicsScene *scene)
{
    this->scene = scene;
    this->scheme = scheme;
    this->logicPort = logicPort;
    setFlag(ItemSendsGeometryChanges);

    this->scene->addItem(this);
    p = new point(this, scene);
    this->scene->addItem(p);
}

QRectF PortNode::boundingRect() const
{
    qreal adjust = 2;
    return QRectF( -10 - adjust, -10 - adjust, 23 + adjust, 23 + adjust);
}

QPainterPath PortNode::shape() const
{
    QPainterPath path;
    path.addEllipse(-10, -10, 20, 20);
    return path;
}

void PortNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::darkGray);
    painter->drawEllipse(-7, -7, 20, 20);

    QRadialGradient gradient(-3, -3, 10);
    if (option->state & QStyle::State_Sunken) {
        gradient.setCenter(3, 3);
        gradient.setFocalPoint(3, 3);
        gradient.setColorAt(1, QColor(Qt::yellow).light(120));
        gradient.setColorAt(0, QColor(Qt::darkYellow).light(120));
    } else {
        gradient.setColorAt(0, Qt::yellow);
        gradient.setColorAt(1, Qt::darkYellow);
    }
    painter->setBrush(gradient);

    painter->setPen(QPen(Qt::black, 0));
    painter->drawEllipse(-10, -10, 20, 20);
}

QVariant PortNode::itemChange(GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:
        this->p->setPos(this->pos());

        if (this->logicPort->getConnection().connected) {
            arrow->adjust();
        }
        break;
    default:
        break;
    };

    return QGraphicsItem::itemChange(change, value);
}

void PortNode::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug("Pressed");
    update();
    QGraphicsItem::mousePressEvent(event);
}

void PortNode::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    qDebug("Move");
    update();
    QGraphicsItem::mouseMoveEvent(event);
}

void PortNode::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    qDebug("Release");
    QGraphicsItem::mouseReleaseEvent(event);
}

Scheme *PortNode::getScheme() {
    return this->scheme;
}

port *PortNode::getLogicPort() {
    return this->logicPort;
}

int PortNode::type() const {
    return Type;
}

void PortNode::addArrow(Arrow *arrow) {
    this->arrow = arrow;
}

Arrow *PortNode::getArrow()
{
    return this->arrow;
}

void PortNode::deleteArrowPointer()
{
    this->arrow = nullptr;
}

void PortNode::deleteArrow() {
    this->p->removeArrow();
}

void PortNode::deleteInfoDialog() {
    this->p->removeInfoDialog();
}

void PortNode::deleteAll() {
    deleteArrow();
    deleteInfoDialog();
    this->scene->removeItem(p);
    delete(p);
    p = nullptr;
    this->scene->removeItem(this);
}
