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

QList<QGraphicsItem*> System::getItems() const
{
    return scene->items();
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
    scene->addEllipse(point.x() - pointRadius / 2.0f, point.y() - pointRadius / 2.0f, pointRadius, pointRadius,
                      pointPen, pointBrush);
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
