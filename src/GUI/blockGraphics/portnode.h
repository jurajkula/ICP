#ifndef PORTNODE_H
#define PORTNODE_H

#include "arrow.h"
#include "point.h"
#include <src/LOGIC/Scheme.hpp>

#include <QGraphicsItem>
#include <QObject>
#include <QBrush>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsScene>

class Arrow;
class point;
class PortNode : public QGraphicsItem
{
public:
    explicit PortNode(port *logicPort, Scheme *scheme, QGraphicsScene *scene);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    enum { Type = UserType + 2 };
    int type() const override;

    Scheme *getScheme();
    port *getLogicPort();
    void addArrow(Arrow * arrow);
    Arrow *getArrow();
    void deleteArrowPointer();
    void deleteArrow();
    void deleteInfoDialog();
    void deleteAll();
signals:

public slots:

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    Arrow * arrow;
    QPointF newPos;
    QGraphicsScene *scene;
    point *p;
    Scheme *scheme;
    port *logicPort;
};

#endif // PORTNODE_H
