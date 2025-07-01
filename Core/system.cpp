#include "system.h"

System::System()
{
    scene = new QGraphicsScene();
    scene->addEllipse(0, 0, pointRadius, pointRadius, pointPen, pointBrush);
}

QGraphicsScene* System::getScene()
{
    return scene;
}

QList<QGraphicsItem*> System::getItems() const
{
    return scene->items();
}

void System::addPoint(QPointF point)
{
    scene->addEllipse(point.x(), point.y(), pointRadius, pointRadius, pointPen, pointBrush);
}

void System::resetScene()
{
    scene->clear();
}

// Slots
void System::onAddPoint(QPointF point)
{
    addPoint(point);
}
