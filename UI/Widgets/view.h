#pragma once

#include <qgraphicsview.h>

class View : public QGraphicsView
{
public:
    View(QGraphicsScene *scene, QWidget *parent = nullptr);
};
