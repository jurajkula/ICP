#ifndef PORTNODE_H
#define PORTNODE_H

#include "arrow.h"

#include <QGraphicsItem>
#include <QObject>
#include <QBrush>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

class Arrow;

class PortNode : public QGraphicsItem
{
public:
    explicit PortNode();

    void addArrow(Arrow *arrow);
    QList<Arrow *> arrows() const;

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
signals:

public slots:

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QList<Arrow *> arrowList;
    QPointF newPos;
};

#endif // PORTNODE_H
