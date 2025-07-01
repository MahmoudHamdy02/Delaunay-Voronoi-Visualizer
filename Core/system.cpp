#include "system.h"

#include <unordered_set>

SceneController::SceneController()
{
    scene = new QGraphicsScene();
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
    for (Edge e : edges) {
        scene->addLine(e.p1.x(), e.p1.y(), e.p2.x(), e.p2.y());
    }
}

std::vector<Edge> SceneController::getEdges() const
{
    std::unordered_set<Edge> edgeSet;

    for (Triangle t : triangles) {
        std::array<Edge, 3> edges = t.getEdges();
        for (Edge e : edges) edgeSet.insert(e);
    }

    return std::vector<Edge>(edgeSet.begin(), edgeSet.end());
}

void SceneController::addPoint(const QPointF& point)
{
    points.push_back(point);
    redrawScene();
}

void SceneController::resetScene()
{
    scene->clear();
}

// Slots
void SceneController::onAddPoint(const QPointF& point)
{
    addPoint(point);
}
