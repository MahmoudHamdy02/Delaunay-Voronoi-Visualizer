#pragma once

#include <qaction.h>
#include <qactiongroup.h>
#include <qwidget.h>

#include <QActionGroup>
#include <QToolBar>

class Toolbar : public QToolBar
{
    QAction* delaunayAction;
    QAction* voronoiAction;

public:
    Toolbar(QWidget* parent);
    QAction* getDelaunayAction() const;
    QAction* getVoronoiAction() const;
};
