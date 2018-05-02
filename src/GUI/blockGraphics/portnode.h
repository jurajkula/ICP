/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul pre grafické zobrazenie portu (vykreslenie portu)
*/

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

/**
 * @brief The PortNode class
 */
class PortNode : public QGraphicsItem
{
public:
    /**
     * @brief PortNode Constructor of the class
     * @param logicPort Pointer to logic port
     * @param scheme Pointer to logic scheme
     * @param scene Pointer to graphics scene
     */
    explicit PortNode(port *logicPort, Scheme *scheme, QGraphicsScene *scene);

    /**
     * @brief boundingRect Default function
     * @return QRectF
     */
    QRectF boundingRect() const override;

    /**
     * @brief shape Default function
     * @return QPainterPath
     */
    QPainterPath shape() const override;

    /**
     * @brief paint Default function
     * @param painter QPainter
     * @param option Option
     * @param widget Parent widget
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    enum { Type = UserType + 2 };

    /**
     * @brief type Return new type of object
     * @return New type
     */
    int type() const override;

    /**
     * @brief getScheme Function which return pointer to scheme
     * @return Pointer to scheme
     */
    Scheme *getScheme();

    /**
     * @brief getLogicPort Function which return pointer to logic port
     * @return Pointer to logic port
     */
    port *getLogicPort();

    /**
     * @brief addArrow Function which add arrow to this object
     * @param arrow Pointer to arrow
     */
    void addArrow(Arrow * arrow);

    /**
     * @brief getArrow Function which returns pointer to arrow
     * @return Pointer to arrow
     */
    Arrow *getArrow();

    /**
     * @brief deleteArrowPointer Function which delete arrow pointer
     */
    void deleteArrowPointer();

    /**
     * @brief deleteArrow Function which delete arrow
     */
    void deleteArrow();

    /**
     * @brief deleteInfoDialog Function which delete info dialog
     */
    void deleteInfoDialog();

    /**
     * @brief deleteAll Function which deletes all about ports
     */
    void deleteAll();
signals:

public slots:

protected:

    /**
     * @brief itemChange Default function
     * @param change Item change
     * @param value Value
     * @return Return QVariant
     */
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

    /**
     * @brief mousePressEvent Function which grabs mouse press event
     * @param event Scene mouse event
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    /**
     * @brief mouseMoveEvent Function which grabs mouse move event
     * @param event Scene mouse event
     */
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    /**
     * @brief mouseReleaseEvent Function which grabs mouse release event
     * @param event Scene mouse event
     */
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
