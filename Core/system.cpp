#include "system.h"

System::System()
{
    scene = new QGraphicsScene();
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
    scene->addEllipse(point.x() - pointRadius / 2.0f, point.y() - pointRadius / 2.0f, pointRadius, pointRadius,
                      pointPen, pointBrush);
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
