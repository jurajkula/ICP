#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include <QTimeLine>


class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    GraphicsView();
protected:
    void wheelEvent(QWheelEvent *event) override;

protected slots:
    void scalingTime(qreal x);
    void animFinished();
private:
    int numScheduledScalings;
};

#endif // GRAPHICSVIEW_H
