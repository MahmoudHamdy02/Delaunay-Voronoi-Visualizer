#pragma once

#include <qaction.h>
#include <qactiongroup.h>

#include <QActionGroup>
#include <QToolBar>

class Toolbar : public QToolBar
{
    QActionGroup* actionGroup;
    QAction* delaunayAction;
    QAction* voronoiAction;

public:
    Toolbar();
    QActionGroup* getActionGroup() const;
};
