#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QMouseEvent>

#include "Graphics/GeometricObject.h"
#include "GeometricObjectManager.h"

/**
 * 画布
 * 除了负责绘画，接受鼠标事件，还会向GeometricObejectManager传送新的GeometricObeject
 */
namespace Ui {
class OpenglWidget;
}

enum STATE_DRAWING
{
    willDraw, isDrawing, completeDrawing
};



class OpenglWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit OpenglWidget(QWidget *parent = 0);
    ~OpenglWidget();

    CONTENT_DRAWING drawingContent;
    STATE_DRAWING drawingState;

private:
    Ui::OpenglWidget *ui;

    GeometricObjectManager geometricObjectManager;
    GeometricObject* selectedGeometricObject;

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

public slots:
    void lineWidthChanged(const int& lineWidth);
};

#endif // OPENGLWIDGET_H
