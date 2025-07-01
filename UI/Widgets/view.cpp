#include "view.h"

#include <qevent.h>
#include <qpoint.h>

#include <QOpenGLWidget>

View::View(QGraphicsScene *scene, QWidget *parent) : QGraphicsView(scene, parent)
{
    QOpenGLWidget *gl = new QOpenGLWidget();

    // Enable anti-aliasing
    setRenderHint(QPainter::Antialiasing, true);
    QSurfaceFormat format;
    format.setSamples(8);
    gl->setFormat(format);
    setViewport(gl);

    setBackgroundBrush(Qt::white);

    setSceneRect(-width() / 2.0, -height() / 2.0, width(), height());
}

void View::mousePressEvent(QMouseEvent *event)
{
    emit emitAddPoint(mapToScene(event->pos()));
}
