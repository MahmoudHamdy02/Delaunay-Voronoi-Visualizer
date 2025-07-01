#pragma once

#include <qbrush.h>
#include <qgraphicsscene.h>
#include <qobject.h>
#include <qpen.h>
#include <qpoint.h>
#include <qtmetamacros.h>

#include <vector>

#include "types.h"

// Manages the graphics scene and the geometry entities
class System : public QObject
{
    Q_OBJECT

    QGraphicsScene* scene;

    // Geometry
    std::vector<QPointF> points = {};
    std::vector<Triangle> triangles = {};
    std::vector<Edge> edges = {};

    // Drawing
    const float pointRadius = 8.0f;
    const QPen pointPen = QPen();
    const QBrush pointBrush = QBrush(Qt::BrushStyle::SolidPattern);

    void redrawScene();
    std::vector<Edge> getEdges() const;
public:
    System();

    QGraphicsScene* getScene();

    void addPoint(const QPointF& point);

    void resetScene();

public slots:
    void onAddPoint(const QPointF& point);
};
