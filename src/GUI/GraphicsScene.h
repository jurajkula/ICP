#ifndef GRAPHICS_H
#define GRAPHICS_H


#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QList>
#include <QGraphicsPathItem>
#include <QPainterPath>
#include <QMainWindow>

#include "blockDialogCreate/createblock.h"

/**
 * @brief The GraphicsScene class
 */
class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    /**
     * @brief GraphicsScene Cosntructor of class
     * @param parent Parent window
     */
    explicit GraphicsScene(QObject *parent = 0);

    /**
     * @brief mouseDoubleClickEvent Function, which grab double click event
     * @param mouseEvent Mouse event
     */
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * mouseEvent);
    /*virtual void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);*/
signals:

public slots:

private:
    /**
     * @brief m_points TODO
     */
    QList <QPointF> m_points;
};
#endif // GRAPHICS_H
