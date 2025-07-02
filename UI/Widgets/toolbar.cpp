#include "toolbar.h"

Toolbar::Toolbar(QWidget* parent) : QToolBar(parent)
{
    setMovable(false);
    setFloatable(false);

    setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
    setIconSize(QSize(48, 48));

    // Create an action for each mode
    delaunayAction = new QAction(QIcon(":UI/Icons/triangles.svg"), "Delaunay\nTriangulation", this);
    delaunayAction->setCheckable(true);
    delaunayAction->setChecked(true);
    this->addAction(delaunayAction);

    voronoiAction = new QAction(QIcon(":UI/Icons/cells.svg"), "Voronoi\nDiagram", this);
    voronoiAction->setCheckable(true);
    this->addAction(voronoiAction);

    setStyleSheet(
        "QToolButton {"
        "width: 100px;"
        "}");
}

QAction* Toolbar::getDelaunayAction() const
{
    return delaunayAction;
}

QAction* Toolbar::getVoronoiAction() const
{
    return voronoiAction;
}
