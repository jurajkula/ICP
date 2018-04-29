#include "graphicsview.h"

#include <QMouseEvent>

GraphicsView::GraphicsView()
{

}

void GraphicsView::wheelEvent ( QWheelEvent * event )
{
 int numDegrees = event->delta() / 8;
 int numSteps = numDegrees / 15; // see QWheelEvent documentation
 numScheduledScalings += numSteps;
 if (numScheduledScalings * numSteps < 0) // if user moved the wheel in another direction, we reset previously scheduled scalings
 numScheduledScalings = numSteps;

 QTimeLine *anim = new QTimeLine(350, this);
 anim->setUpdateInterval(20);

 connect(anim, SIGNAL (valueChanged(qreal)), SLOT (scalingTime(qreal)));
 connect(anim, SIGNAL (finished()), SLOT (animFinished()));
 anim->start();
}

void GraphicsView::scalingTime(qreal x)
{
 qreal factor = 1.0+ qreal(numScheduledScalings) / 300.0;
 scale(factor, factor);
}

void GraphicsView::animFinished()
{
 if (numScheduledScalings > 0)
 numScheduledScalings--;
 else
 numScheduledScalings++;
 sender()->~QObject();
}
