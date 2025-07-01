#pragma once

#include <qpoint.h>

class Edge
{
public:
    QPointF p1, p2;

    Edge(QPointF, QPointF);
};

class Triangle
{
public:
    QPointF p1, p2, p3;

    Triangle(QPointF, QPointF, QPointF);

    bool isPointInsideCircumcircle(QPointF) const;
};
