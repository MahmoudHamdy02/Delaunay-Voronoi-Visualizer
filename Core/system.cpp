#include "system.h"

System::System()
{
    scene = new QGraphicsScene();
    scene->addEllipse(0, 0, 10, 10, QPen(), QBrush(Qt::BrushStyle::SolidPattern));
}

QGraphicsScene* System::getScene()
{
    return scene;
}

QList<QGraphicsItem*> System::getItems() const
{
    return scene->items();
}

void System::resetScene()
{
    scene->clear();
}
