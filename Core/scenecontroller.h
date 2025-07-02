#pragma once

#include <qbrush.h>
#include <qgraphicsscene.h>
#include <qobject.h>
#include <qpen.h>
#include <qpoint.h>

#include <vector>

#include "edge.h"
#include "triangle.h"

// Manages the graphics scene and the geometry entities
class SceneController : public QObject
{
    Q_OBJECT

    QGraphicsScene* scene;

    // Geometry
    const Triangle superTriangle = Triangle({0.0, -2000.0}, {2000.0, 1000.0}, {-2000.0, 1000.0});

    std::vector<QPointF> points = {};
    std::vector<Triangle> triangles = {superTriangle};

    // Drawing
    const float pointRadius = 8.0f;
    const QPen pointPen = QPen(Qt::blue);
    const QPen cellPen = QPen(Qt::red);
    const QBrush pointBrush = QBrush(Qt::BrushStyle::SolidPattern);

    bool drawDelaunayTriangles = true;
    bool drawVoronoiCells = false;

    void triangulate(const QPointF& point);

    void redrawScene();
    std::vector<Edge> getEdges() const;

public:
    SceneController();

    QGraphicsScene* getScene();

    void addPoint(const QPointF& point);

    void resetScene();

public slots:
    void onAddPoint(const QPointF& point);
    void setDrawDelaunayTriangles(bool);
    void setDrawVoronoiCells(bool);
};
