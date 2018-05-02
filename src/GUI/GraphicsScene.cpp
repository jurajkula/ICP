/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul pre prepísanie triedy QGraphicsScene
*/

#include "GraphicsScene.h"

GraphicsScene::GraphicsScene(Scheme *s, QObject *parent) :
    QGraphicsScene(parent)
{
    this->setBackgroundBrush(Qt::gray);
    this->scheme = s;
}

void GraphicsScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
    if (mouseEvent->button() == Qt::LeftButton) {
        bool isScene = true;

        for (QGraphicsItem *item : this->items()) {
            Rectangle *r = qgraphicsitem_cast<Rectangle *>(item);
            if(!r)
                continue;

            if(r->containsP(mouseEvent->scenePos())) {
                isScene = false;
            }
        }

        if (isScene) {
            createBlock *bD = new createBlock(this->scheme, this, mouseEvent->scenePos());
            bD->show();
        }
    }
    QGraphicsScene::mouseDoubleClickEvent(mouseEvent);
}

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent) {
    QGraphicsScene::mouseMoveEvent(mouseEvent);
}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent) {
    QGraphicsScene::mousePressEvent(mouseEvent);
}

void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent) {
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}
