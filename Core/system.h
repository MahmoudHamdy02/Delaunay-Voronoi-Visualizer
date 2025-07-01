#pragma once

#include <qgraphicsscene.h>

// Manages the graphics scene and the geometry entities
class System
{
    QGraphicsScene* scene;

public:
    System();

    QGraphicsScene* getScene();
    QList<QGraphicsItem*> getItems() const;
    void resetScene();
};
