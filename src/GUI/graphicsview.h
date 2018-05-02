/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul pre prepísanie triedy QGraphicsView
*/

#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include <QTimeLine>

/**
 * @brief The GraphicsView class
 */
class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    /**
     * @brief GraphicsView Constructor of the class
     */
    GraphicsView();

protected:
    /**
     * @brief wheelEvent Function which grab wheel event
     * @param event Wheel event
     */
    void wheelEvent(QWheelEvent *event) override;

protected slots:
    /**
     * @brief scalingTime Function which compute scale
     * @param x Value
     */
    void scalingTime(qreal x);

    /**
     * @brief animFinished Scaling ended
     */
    void animFinished();
private:
    int numScheduledScalings;
};

#endif // GRAPHICSVIEW_H
