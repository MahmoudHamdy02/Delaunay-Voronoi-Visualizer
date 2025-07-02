#pragma once

#include "edge.h"

class Triangle
{
    QPointF getCircumcircleCenter(const QPointF&, const QPointF&, const QPointF&);

public:
    QPointF p1, p2, p3;
    std::vector<Edge> edges;
    QPointF circumcircleCenter;

    Triangle(QPointF, QPointF, QPointF);

    bool contains(const Edge& edge) const;
    bool isPointInsideCircumcircle(QPointF) const;

    bool operator==(const Triangle& other) const;
};
