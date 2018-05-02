/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul pre grafické zobrazenie bloku (vykreslenie obdĺžnika)
*/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "portnode.h"
#include "rectangleinfodialog.h"

#include <QPen>

/**
 * @brief The Rectangle class
 */
class Rectangle : public QGraphicsRectItem
{
public:
    /**
     * @brief Rectangle Constructor of the class
     * @param scheme Pointer to logic scheme
     * @param scene Pointer to graphics scene
     * @param Ymul Which port in order - for computing size
     * @param nodes Pointer to vector of pointers to PortNodes
     * @param Ppos Position
     * @param block Pointer to block
     */
    Rectangle(Scheme *scheme, QGraphicsScene *scene, int Ymul, std::vector<PortNode *> *nodes, QPointF Ppos, Block *block);

    /**
     * @brief getX Function which returns width
     * @return Width
     */
    int getX();

    /**
     * @brief getY Function which returns height
     * @return Height
     */
    int getY();

    /**
     * @brief boundingRect Default function overrided
     * @return return QRectF
     */
    QRectF boundingRect() const override;

    /**
     * @brief shape Default function overrided
     * @return QPainterPath
     */
    QPainterPath shape() const override;

    /**
     * @brief paint Default function overrided
     * @param painter QPainter
     * @param option Option
     * @param widget Parent widget
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    enum { Type = UserType + 3 };

    /**
     * @brief type Return new type of object
     * @return New type
     */
    int type() const override;

    /**
     * @brief itemChange Default function overrided
     * @param change Item change value
     * @param value QVariant
     * @return
     */
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

    /**
     * @brief containsP Function which find out if port collides with point
     * @param point Point
     * @return TRUE, if objects collide, else FALSE
     */
    bool containsP(const QPointF &point) const;

    /**
     * @brief getLogicBlock Function which return Logic Block
     * @return Logic Block
     */
    Block *getLogicBlock();

    /**
     * @brief removeGBlock Function which remove all components of graphicsal block
     */
    void removeGBlock();

    /**
     * @brief deleteAll Function which remove all components of this block - graphical and logical
     */
    void deleteAll();
protected:

    /**
     * @brief hoverEnterEvent Function which grabs hover enter event
     * @param event Event
     */
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

    /**
     * @brief hoverLeaveEvent Function which grabs hover leave event
     * @param event Event
     */
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

    /**
     * @brief mouseDoubleClickEvent Function which grabs double click event
     * @param event Event
     */
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
private:
    QGraphicsScene *scene;

    /**
     * @brief X
     */
    int X = 100;

    /**
     * @brief Y
     */
    int Y = 50;

    int Ymul = 0;

    std::vector<PortNode*> *nodes;

    QPointF Ppos;

    rectangleInfoDialog *infoDialog;
    Scheme *scheme;
    Block *block;
};

#endif // RECTANGLE_H
