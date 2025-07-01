#pragma once

#include <qpoint.h>

class Edge
{
public:
    QPointF p1, p2;

    Edge(QPointF, QPointF);
    Edge(const Edge&) = default;

    bool operator==(const Edge& other) const;
};

inline bool operator<(const QPointF& a, const QPointF& b)
{
    return (a.x() < b.x()) || (a.x() == b.x() && a.y() < b.y());
}

namespace std {
template <>
struct hash<QPointF> {
    size_t operator()(const QPointF& pt) const
    {
        auto h1 = std::hash<int64_t>()(static_cast<int64_t>(pt.x() * 10000));
        auto h2 = std::hash<int64_t>()(static_cast<int64_t>(pt.y() * 10000));
        return h1 ^ (h2 << 1);
    }
};

template <>
struct hash<Edge> {
    size_t operator()(const Edge& edge) const
    {
        // Ensure consistent hash regardless of point order if undirected
        const QPointF& a = edge.p1 < edge.p2 ? edge.p1 : edge.p2;
        const QPointF& b = edge.p1 < edge.p2 ? edge.p2 : edge.p1;

        auto h1 = std::hash<QPointF>()(a);
        auto h2 = std::hash<QPointF>()(b);
        return h1 ^ (h2 << 1);
    }
};
}  // namespace std

class Triangle
{
public:
    QPointF p1, p2, p3;

    Triangle(QPointF, QPointF, QPointF);

    std::array<Edge, 3> getEdges() const;
    bool isPointInsideCircumcircle(QPointF) const;
};
