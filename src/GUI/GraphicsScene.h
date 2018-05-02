/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul pre prepísanie triedy QGraphicsScene
*/

#ifndef GRAPHICS_H
#define GRAPHICS_H


#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QList>
#include <QGraphicsPathItem>
#include <QPainterPath>
#include <QMainWindow>

#include "blockDialogCreate/createblock.h"
#include "../LOGIC/Scheme.hpp"

/**
 * @brief The GraphicsScene class
 */
class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    /**
     * @brief GraphicsScene Cosntructor of class
     * @param scheme Pointer to scheme
     * @param parent Parent window
     */
    explicit GraphicsScene(Scheme *scheme, QObject *parent = 0);

    /**
     * @brief mouseDoubleClickEvent Function, which grab double click event
     * @param mouseEvent Mouse event
     */
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * mouseEvent);

    /**
     * @brief mouseMoveEvent Function, which grab mouse move event
     * @param mouseEvent Mouse event
     */
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);

    /**
     * @brief mousePressEvent Function, which grab mouse Press event
     * @param mouseEvent Mouse event
     */
    virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);

    /**
     * @brief mouseReleaseEvent Function, which grab mouse Release event
     * @param mouseEvent Mouse event
     */
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);
signals:

public slots:

private:
    /**
     * @brief m_points TODO
     */
    QList <QPointF> m_points;

    /**
     * @brief scheme Pointer to logic scheme
     */
    Scheme *scheme;
};
#endif // GRAPHICS_H
