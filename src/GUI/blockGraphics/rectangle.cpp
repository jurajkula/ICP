#include "rectangle.h"

Rectangle::Rectangle(QGraphicsScene *scene, int Ymul, std::vector<PortNode *> *nodes, QPointF Ppos, Block *block)
{
    this->scene = scene;
    this->Ymul = Ymul;
    this->nodes = nodes;
    this->Ppos = Ppos;

    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges);
    this->setAcceptHoverEvents(true);

    infoDialog = new rectangleInfoDialog(block);
    //infoDialog->show();
    scene->addWidget(infoDialog);
    infoDialog->hide();
}

int Rectangle::getX() {
    return this->X;
}

int Rectangle::getY() {
    return this->Y;
}

QRectF Rectangle::boundingRect() const
{
    return QRectF(5, 5, X-5, Y*Ymul-5);
}

QPainterPath Rectangle::shape() const
{
    QPainterPath path;
    path.addRect(this->boundingRect());
    return path;
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    QPen blackpen(Qt::black);
    blackpen.setWidth(1);

    painter->setPen(blackpen);
    painter->setBrush(Qt::red);

    painter->setPen(QPen(Qt::black, 0));
    painter->drawRect(this->boundingRect());
}

QVariant Rectangle::itemChange(GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:
        for (PortNode *p : *nodes) {
            p->setPos(this->pos().x() - this->Ppos.x() + p->pos().x(), this->pos().y() - this->Ppos.y() + p->pos().y());
        }
        Ppos = this->pos();
        infoDialog->setPos(this->pos(), this->X);
        break;
    default:
        break;
    };

    return QGraphicsItem::itemChange(change, value);
}

int Rectangle::type() const {
    return Type;
}

void Rectangle::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    qDebug("Enter rectangle");
    this->infoDialog->show();
    update();
}

void Rectangle::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    qDebug("Leave rectangle");
    this->infoDialog->hide();
    update();
}

void Rectangle::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        qDebug("Double click on rectangle");
    }
}

bool Rectangle::containsP(const QPointF &point) const {
    if ((point.x() >= this->pos().x() + this->boundingRect().x()) &&
        (point.x() <= this->pos().x() + this->boundingRect().x() + boundingRect().width()) &&
        (point.y() >= this->pos().y() + this->boundingRect().y()) &&
        (point.y() <= this->pos().y() + this->boundingRect().y() + boundingRect().height()))
    {
        return true;
    }
    return false;
}
