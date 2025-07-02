#include "scenecontroller.h"

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

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

    for (QPointF p : points) {
        scene->addEllipse(p.x() - pointRadius / 2.0f, p.y() - pointRadius / 2.0f, pointRadius, pointRadius, pointPen,
                          pointBrush);
    }
    edges = getEdges();
    for (Edge e : edges) {
        scene->addLine(e.p1.x(), e.p1.y(), e.p2.x(), e.p2.y());
    }
}

std::vector<Edge> SceneController::getEdges() const
{
    std::unordered_set<Edge> edgeSet;

    for (Triangle t : triangles) {
        for (Edge e : t.edges) {
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

void SceneController::triangulate(const QPointF& point)
{
    // Find triangles that are invalidated by the new point
    std::vector<Triangle> invalidTriangles = {};
    for (Triangle t : triangles) {
        if (t.isPointInsideCircumcircle(point)) {
            invalidTriangles.push_back(t);
        }
    }
    std::cout << "Invalid triangles: " << invalidTriangles.size() << std::endl;

    std::unordered_set<Edge> invalidEdges;
    for (Triangle t : invalidTriangles) {
        for (Edge e : t.edges) {
            invalidEdges.insert(e);
        }
    }
    std::cout << "Invalid edges: " << invalidEdges.size() << std::endl;

    // Find the boundary of the polygon hole
    // The boundary edges are part of only one bad triangle
    // For each edge in the bad triangles, check if it's part of another bad triangle
    std::vector<Edge> polygonEdges;
    for (Edge e : invalidEdges) {
        int num = 0;
        for (Triangle t : invalidTriangles) {
            if (t.contains(e)) num++;
        }
        if (num == 1) polygonEdges.push_back(e);
    }
    std::cout << "Polygon edges: " << polygonEdges.size() << std::endl;

    // Remove the invalid triangles
    for (Triangle t : invalidTriangles) {
        triangles.erase(std::remove(triangles.begin(), triangles.end(), t), triangles.end());
    }

    // Retriangulate the hole
    for (Edge e : polygonEdges) {
        triangles.emplace_back(point, e.p1, e.p2);
    }
}

void SceneController::resetScene()
{
    scene->clear();
    points.clear();
    triangles.clear();
    triangles = {superTriangle};
    edges.clear();
}

// Slots
void SceneController::onAddPoint(const QPointF& point)
{
    addPoint(point);
}
