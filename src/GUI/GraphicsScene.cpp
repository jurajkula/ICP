#include "GraphicsScene.h"
#include "portnode.h"

GraphicsScene::GraphicsScene(Scheme *s, QObject *parent) :
    QGraphicsScene(parent)
{
    this->setBackgroundBrush(Qt::gray);
    this->scheme = s;
}

void GraphicsScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
    if (mouseEvent->button() == Qt::LeftButton) {
        //qDebug() << Q_FUNC_INFO << mouseEvent->scenePos();
        QGraphicsScene::mouseDoubleClickEvent(mouseEvent);
        //new gBlock(this, mouseEvent->scenePos());

        // TODO inside main window
        createBlock *bD = new createBlock(this->scheme, this, mouseEvent->scenePos());
        bD->show();
    }
}
