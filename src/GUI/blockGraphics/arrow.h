/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul vykreslovanie šípok - inšpirácia z príkladu v QT dokumentácii: http://doc.qt.io/qt-5/qtwidgets-graphicsview-elasticnodes-example.html
*/

#ifndef ARROW_H
#define ARROW_H

#include "portnode.h"

#include <QGraphicsItem>
#include <cmath>

class PortNode;
class point;

/**
 * @brief The Arrow class
 */
class Arrow : public QGraphicsItem
{
public:
    /**
     * @brief Arrow Constructor for the class - arrow between ports
     * @param surceNode Source node
     * @param destNode Destination node
     */
    Arrow(PortNode *surceNode, PortNode *destNode);

    /**
     * @brief Arrow Constructor for the class - arrow between port - point
     * @param sourceNode Source node
     * @param destPoint Destination point
     */
    Arrow(PortNode *sourceNode, point *destPoint);

    /**
     * @brief adjust Function which redraw arrow
     */
    void adjust();

    /**
     * @brief getDestNode Function which returns pointer to Dest node
     * @return
     */
    PortNode *getDestNode();

    /**
     * @brief getSourceNode Function which return pointer to source node
     * @return
     */
    PortNode *getSourceNode();

protected:
    /**
     * @brief boundingRect Default function
     * @return QRectF
     */
    QRectF boundingRect() const override;

    /**
     * @brief paint Default function
     * @param painter QPainter
     * @param option Opiton
     * @param widget Parent widget
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    enum { Type = UserType + 4 };

    /**
     * @brief type Return object type
     * @return New type
     */
    int type() const override;
private:
    PortNode *source, *dest;
    point *destP;
    bool isDestP;

    QPointF sourcePoint;
    QPointF destPoint;
    qreal arrowSize;
};

#endif // ARROW_H
