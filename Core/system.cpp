#include "system.h"

#include <unordered_set>

System::System()
{
    scene = new QGraphicsScene();
}

QGraphicsScene* System::getScene()
{
    return scene;
}

void System::redrawScene()
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

std::vector<Edge> System::getEdges() const
{
    std::unordered_set<Edge> edgeSet;

    for (Triangle t : triangles) {
        std::array<Edge, 3> edges = t.getEdges();
        for (Edge e : edges) edgeSet.insert(e);
    }

    return std::vector<Edge>(edgeSet.begin(), edgeSet.end());
}

void System::addPoint(const QPointF& point)
{
    points.push_back(point);
    redrawScene();
}

void System::resetScene()
{
    scene->clear();
}

// Slots
void System::onAddPoint(const QPointF& point)
{
    addPoint(point);
}
