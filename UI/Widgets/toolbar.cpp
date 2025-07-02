#include "toolbar.h"

#include <qaction.h>
#include <qtoolbar.h>
#include <qwidget.h>

Toolbar::Toolbar(QWidget* parent) : QToolBar(parent)
{
    setMovable(false);
    setFloatable(false);

    // Create an action for each mode
    delaunayAction = new QAction("Delaunay Triangulation", this);
    delaunayAction->setCheckable(true);
    delaunayAction->setChecked(true);
    this->addAction(delaunayAction);

    voronoiAction = new QAction("Voronoi Diagram", this);
    voronoiAction->setCheckable(true);
    this->addAction(voronoiAction);
}

QAction* Toolbar::getDelaunayAction() const
{
    return delaunayAction;
}

QAction* Toolbar::getVoronoiAction() const
{
    return voronoiAction;
}
