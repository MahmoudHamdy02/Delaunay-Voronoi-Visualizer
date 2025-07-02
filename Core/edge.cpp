#include "edge.h"

Edge::Edge(QPointF p1, QPointF p2) : p1(p1), p2(p2) {}

bool Edge::operator==(const Edge& other) const
{
    return (p1 == other.p1 && p2 == other.p2) || (p1 == other.p2 && p2 == other.p1);
}

bool Edge::contains(const QPointF& point) const
{
    return point == p1 || point == p2;
}
