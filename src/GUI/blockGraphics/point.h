/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul pre zobrazenie neviditelneho bodu nad portom - vykresľuje sa k nemu šípka
*/

#ifndef POINT_H
#define POINT_H

#include <QGraphicsItem>
#include <QPainterPath>
#include <QRect>
#include <QVariant>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsSceneMouseEvent>

#include "portinfodialog.h"
#include "portnode.h"

class PortNode;
class Arrow;

/**
 * @brief The point class
 */
class point : public QGraphicsItem
{
public:
    /**
     * @brief point Constructor of the class
     * @param node Pointer to PortNode
     * @param scene Pointer to graphics scene
     */
    point(PortNode *node, QGraphicsScene *scene);

    /**
     * @brief mousePressEvent Function which grabs mouse press event
     * @param event Scene mouse event
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

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

    enum { Type = UserType + 1 };
    /**
     * @brief type Funciton which returns object type ID
     * @return ReturnObject type ID
     */
    int type() const override;

    /**
     * @brief removeArrow Function which remove arrow
     */
    void removeArrow();

    /**
     * @brief removeInfoDialog Function which remove info dialog for port
     */
    void removeInfoDialog();
protected:
    /**
     * @brief itemChange Grabs signals Item change
     * @param change Item change signal
     * @param value QVariant
     * @return Qvariant
     */
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

    /**
     * @brief mouseMoveEvent Grabs event mouse move event
     * @param event Scene mouse event
     */
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    /**
     * @brief mouseReleaseEvent Grabs mouse release event
     * @param event Scene mouse event
     */
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    /**
     * @brief mouseDoubleClickEvent Grabs double click
     * @param event
     */
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;

    /**
     * @brief hoverEnterEvent Grabs hover enter event
     * @param event Scene hover event
     */
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

    /**
     * @brief hoverLeaveEvent Grabs hover leave event
     * @param event Scene hover event
     */
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
private:
    PortNode *node;
    Arrow *line;
    QGraphicsScene *scene;
    portInfoDialog *infoDialog;
};

#endif // POINT_H
