#pragma once

#include <qaction.h>
#include <qwidget.h>

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
