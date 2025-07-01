#pragma once

#include <qgraphicsview.h>
#include <qpoint.h>

class View : public QGraphicsView
{
    Q_OBJECT

    void mousePressEvent(QMouseEvent *event) override;

public:
    View(QGraphicsScene *scene, QWidget *parent = nullptr);

signals:
    void emitAddPoint(QPointF point);
};
