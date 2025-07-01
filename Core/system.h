#pragma once

#include <qbrush.h>
#include <qgraphicsscene.h>
#include <qobject.h>
#include <qpen.h>
#include <qpoint.h>
#include <qtmetamacros.h>

// Manages the graphics scene and the geometry entities
class System : public QObject
{
    Q_OBJECT

    QGraphicsScene* scene;

    // Drawing
    const int pointRadius = 8;
    const QPen pointPen = QPen();
    const QBrush pointBrush = QBrush(Qt::BrushStyle::SolidPattern);

public:
    System();

    QGraphicsScene* getScene();
    QList<QGraphicsItem*> getItems() const;

    void addPoint(QPointF point);

    void resetScene();

public slots:
    void onAddPoint(QPointF point);
};
