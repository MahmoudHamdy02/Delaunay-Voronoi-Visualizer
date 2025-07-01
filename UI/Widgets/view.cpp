#include "view.h"

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
}
