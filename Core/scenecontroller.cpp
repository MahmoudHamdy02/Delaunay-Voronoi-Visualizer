#include "scenecontroller.h"

#include <unordered_set>

SceneController::SceneController()
{
    scene = new QGraphicsScene();
    redrawScene();
}

QGraphicsScene* SceneController::getScene()
{
    return scene;
}

void SceneController::redrawScene()
{
    scene->clear();

    for (QPointF& p : points) {
        scene->addEllipse(p.x() - pointRadius / 2.0f, p.y() - pointRadius / 2.0f, pointRadius, pointRadius, pointPen,
                          pointBrush);
    }

    std::vector<Edge> edges = getEdges();
    if (drawDelaunayTriangles) {
        for (Edge& e : edges) {
            scene->addLine(e.p1.x(), e.p1.y(), e.p2.x(), e.p2.y());
        }
    }
    if (drawVoronoiCells) {
        for (Edge e : edges) {
            // Find the two triangles that share this edge
            std::vector<QPointF> neighborCircumcenters;
            for (Triangle t : triangles) {
                if (t.contains(e)) neighborCircumcenters.push_back(t.circumcircleCenter);
            }
            if (neighborCircumcenters.size() == 2) {
                QPointF c1 = neighborCircumcenters[0];
                QPointF c2 = neighborCircumcenters[1];
                scene->addLine(c1.x(), c1.y(), c2.x(), c2.y(), cellPen);
            }
        }
    }
}

std::vector<Edge> SceneController::getEdges() const
{
    std::unordered_set<Edge> edgeSet;

    for (const Triangle& t : triangles) {
        for (const Edge& e : t.edges) {
            // Only insert edge if it is not connect to super triangle
            if (e.contains(superTriangle.p1) || e.contains(superTriangle.p2) || e.contains(superTriangle.p3)) continue;
            edgeSet.insert(e);
        }
    }

    return std::vector<Edge>(edgeSet.begin(), edgeSet.end());
}

void SceneController::addPoint(const QPointF& point)
{
    points.push_back(point);
    triangulate(point);
    redrawScene();
}

// Bowyer-Watson Delaunay Triangulation
// See: https://en.wikipedia.org/wiki/Delaunay_triangulation
void SceneController::triangulate(const QPointF& point)
{
    // Find triangles that are invalidated by the new point
    std::vector<Triangle> invalidTriangles = {};
    for (const Triangle& t : triangles) {
        if (t.isPointInsideCircumcircle(point)) {
            invalidTriangles.push_back(t);
        }
    }

    std::unordered_set<Edge> invalidEdges;
    for (const Triangle& t : invalidTriangles) {
        for (const Edge& e : t.edges) {
            invalidEdges.insert(e);
        }
    }

    // Find the boundary of the polygon hole
    // The boundary edges are part of only one bad triangle
    // For each edge in the bad triangles, check if it's part of another bad triangle
    std::vector<Edge> polygonEdges;
    for (const Edge& e : invalidEdges) {
        int num = 0;
        for (const Triangle& t : invalidTriangles) {
            if (t.contains(e)) num++;
        }
        if (num == 1) polygonEdges.push_back(e);
    }

    // Remove the invalid triangles
    for (const Triangle& t : invalidTriangles) {
        triangles.erase(std::remove(triangles.begin(), triangles.end(), t), triangles.end());
    }

    // Retriangulate the hole
    for (const Edge& e : polygonEdges) {
        triangles.emplace_back(point, e.p1, e.p2);
    }
}

void SceneController::resetScene()
{
    scene->clear();
    points.clear();
    triangles.clear();
    triangles = {superTriangle};
}

// Slots
void SceneController::onAddPoint(const QPointF& point)
{
    addPoint(point);
}

void SceneController::setDrawDelaunayTriangles(bool b)
{
    drawDelaunayTriangles = b;
    redrawScene();
}

void SceneController::setDrawVoronoiCells(bool b)
{
    drawVoronoiCells = b;
    redrawScene();
}
