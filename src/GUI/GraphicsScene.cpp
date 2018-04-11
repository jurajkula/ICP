#include "GraphicsScene.h"
#include "gBlock.h"

GraphicsScene::GraphicsScene(QObject *parent) :
    QGraphicsScene(parent)
{
    this->setBackgroundBrush(Qt::gray);
}

void GraphicsScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
    if (mouseEvent->button() == Qt::LeftButton) {
        qDebug() << Q_FUNC_INFO << mouseEvent->scenePos();
        QGraphicsScene::mouseDoubleClickEvent(mouseEvent);
        new gBlock(this, mouseEvent->scenePos());
    }
}
