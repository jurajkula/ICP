/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul vykreslovanie šípok - inšpirácia z príkladu v QT dokumentácii: http://doc.qt.io/qt-5/qtwidgets-graphicsview-elasticnodes-example.html
*/

#include "arrow.h"

Arrow::Arrow(PortNode *source, PortNode *dest)
    : arrowSize(10)
{
    if (!source || !dest)
        return;

    setAcceptedMouseButtons(0);
    this->source = source;
    this->dest = dest;
    this->isDestP = false;
    source->addArrow(this);
    dest->addArrow(this);
    adjust();
}

Arrow::Arrow(PortNode *sourceNode, point *destPoint)
    : arrowSize(10)
{
    if (!sourceNode || !destPoint)
        return;

    setAcceptedMouseButtons(0);
    this->source = sourceNode;
    this->destP = destPoint;
    this->isDestP = true;
    //source->addArrow(this);
    //destP->addArrow(this);
    adjust();
}

void Arrow::adjust()
{
    QLineF *line;
    if (this->isDestP) {
        if (!source || !destP)
            return;
        line = new QLineF(mapFromItem(source, 0, 0), mapFromItem(destP, 0, 0));
    }
    else {
        if (!source || !dest)
            return;
        line = new QLineF(mapFromItem(source, 0, 0), mapFromItem(dest, 0, 0));
    }

    //QLineF line(mapFromItem(source, 0, 0), mapFromItem(dest, 0, 0));
    qreal length = line->length();

    prepareGeometryChange();

    if (length > qreal(20.)) {
        QPointF edgeOffset((line->dx() * 10) / length, (line->dy() * 10) / length);
        sourcePoint = line->p1() + edgeOffset;
        destPoint = line->p2() - edgeOffset;
    } else {
        sourcePoint = destPoint = line->p1();
    }
}

PortNode *Arrow::getDestNode()
{
    return this->dest;
}

PortNode *Arrow::getSourceNode()
{
    return this->source;
}

QRectF Arrow::boundingRect() const
{
    if (this->isDestP) {
        if (!source || !destP)
            return QRectF();
    }
    else {
        if (!source || !dest)
            return QRectF();
    }

    qreal penWidth = 1;
    qreal extra = (penWidth + arrowSize) / 2.0;

    return QRectF(sourcePoint, QSizeF(destPoint.x() - sourcePoint.x(),
                                      destPoint.y() - sourcePoint.y()))
        .normalized()
        .adjusted(-extra, -extra, extra, extra);
}

void Arrow::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if (this->isDestP) {
        if (!source || !destP)
            return;
    }
    else {
        if (!source || !dest)
            return;
    }

    QLineF line(sourcePoint, destPoint);
    if (qFuzzyCompare(line.length(), qreal(0.)))
        return;

    // Draw the line itself
    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->drawLine(line);

    // Draw the arrows
    double angle = std::atan2(-line.dy(), line.dx());

    QPointF destArrowP1 = destPoint + QPointF(sin(angle - M_PI / 3) * arrowSize,
                                                      cos(angle - M_PI / 3) * arrowSize);
    QPointF destArrowP2 = destPoint + QPointF(sin(angle - M_PI + M_PI / 3) * arrowSize,
                                                      cos(angle - M_PI + M_PI / 3) * arrowSize);

    painter->setBrush(Qt::black);
    painter->drawPolygon(QPolygonF() << line.p2() << destArrowP1 << destArrowP2);
}

int Arrow::type() const {
    return Type;
}
