#include "system.h"

System::System()
{
    scene = new QGraphicsScene();
}

QList<QGraphicsItem*> System::getItems() const
{
    return scene->items();
}
