#include "types.h"

#include <qpoint.h>

#include <cmath>

qreal crossProduct(const QPointF& p1, const QPointF& p2)
{
    return p1.x() * p2.y() - p1.y() * p2.x();
}

qreal determinant3x3(qreal a11, qreal a12, qreal a13, qreal a21, qreal a22, qreal a23, qreal a31, qreal a32, qreal a33)
{
    return a11 * (a22 * a33 - a23 * a32) - a12 * (a21 * a33 - a23 * a31) + a13 * (a21 * a32 - a22 * a31);
}

Edge::Edge(QPointF p1, QPointF p2) : p1(p1), p2(p2) {}

bool Edge::operator==(const Edge& other) const
{
    return (p1 == other.p1 && p2 == other.p2) || (p1 == other.p2 && p2 == other.p1);
}

bool Edge::contains(const QPointF& point) const
{
    return point == p1 || point == p2;
}

// Ensures the vertices are ordered counter-clockwise
Triangle::Triangle(QPointF p1, QPointF p2, QPointF p3) : p1(p1), p2(p2), p3(p3)
{
    QPointF p12 = p2 - p1;
    QPointF p23 = p3 - p2;

    // Test direction using cross product
    qreal z = crossProduct(p12, p23);
    // Flip if not counter-clockwise
    if (z < 0.0) {
        this->p1 = p2;
        this->p2 = p1;
    }
    edges.emplace_back(p1, p2);
    edges.emplace_back(p2, p3);
    edges.emplace_back(p3, p1);
}

bool Triangle::contains(const Edge& edge) const
{
    return edge == edges[0] || edge == edges[1] || edge == edges[2];
}

// See: https://en.wikipedia.org/wiki/Delaunay_triangulation#Algorithms
bool Triangle::isPointInsideCircumcircle(QPointF p) const
{
    using std::pow;
    QPointF A = p1;
    QPointF B = p2;
    QPointF C = p3;
    QPointF D = p;

    qreal x1 = A.x() - D.x();
    qreal x2 = B.x() - D.x();
    qreal x3 = C.x() - D.x();
    qreal y1 = A.y() - D.y();
    qreal y2 = B.y() - D.y();
    qreal y3 = C.y() - D.y();
    qreal determinant = determinant3x3(x1, y1, pow(x1, 2) + pow(y1, 2), x2, y2, pow(x2, 2) + pow(y2, 2), x3, y3,
                                       pow(x3, 2) + pow(y3, 2));

    return determinant > 0.0;
}

bool Triangle::operator==(const Triangle& other) const
{
    return edges[0] == other.edges[0] && edges[1] == other.edges[1] && edges[2] == other.edges[2];
}
