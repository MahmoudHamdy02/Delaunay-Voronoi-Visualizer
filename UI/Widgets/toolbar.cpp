#include "toolbar.h"

#include <qaction.h>
#include <qtoolbar.h>
#include <qwidget.h>

Toolbar::Toolbar(QWidget* parent) : QToolBar(parent)
{
    setMovable(false);
    setFloatable(false);

    // Create action group to contain the two modes
    actionGroup = new QActionGroup(this);
    actionGroup->setExclusive(true);

    // Create an action for each mode
    delaunayAction = new QAction("Delaunay Triangulation", this);
    delaunayAction->setCheckable(true);
    delaunayAction->setChecked(true);
    actionGroup->addAction(delaunayAction);
    this->addAction(delaunayAction);

    voronoiAction = new QAction("Voronoi Diagram", this);
    voronoiAction->setCheckable(true);
    actionGroup->addAction(voronoiAction);
    this->addAction(voronoiAction);
}

QActionGroup* Toolbar::getActionGroup() const
{
    return actionGroup;
}
