#include "toolbar.h"

#include <qaction.h>

Toolbar::Toolbar()
{
    setMovable(false);
    setFloatable(false);

    // Create action group to contain the two modes
    actionGroup = new QActionGroup(this);
    actionGroup->setExclusive(true);

    // Create an action for each mode
    QAction* delaunayAction = new QAction("Delaunay Triangulation", this);
    delaunayAction->setCheckable(true);
    delaunayAction->setChecked(true);
    actionGroup->addAction(delaunayAction);
    this->addAction(delaunayAction);

    QAction* voronoiAction = new QAction("Voronoi Diagram", this);
    voronoiAction->setCheckable(true);
    actionGroup->addAction(voronoiAction);
    this->addAction(voronoiAction);
}
