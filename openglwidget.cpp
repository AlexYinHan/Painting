#include "openglwidget.h"
#include "ui_openglwidget.h"
#include "Graphics/Line.h"
#include "Graphics/Circle.h"
#include "Graphics/Oval.h"

OpenglWidget::OpenglWidget(QWidget *parent) :
    QOpenGLWidget(parent),
    ui(new Ui::OpenglWidget)
{
    ui->setupUi(this);

    drawingState = completeDrawing;
    drawingContent = EMPTY;
    selectedGeometricObject = NULL;
}

OpenglWidget::~OpenglWidget()
{
    delete ui;
}

void OpenglWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton && drawingContent != EMPTY)
    {
        drawingState = isDrawing;
        switch(drawingContent)
        {
        case LINE:
        {
            Vector3* mousePosition = new Vector3(event->x(), event->y(), 0);
            selectedGeometricObject = new Line(*mousePosition, *mousePosition);
            this->geometricObjectManager.addObject(selectedGeometricObject);
            //qDebug() << selectedGeometricObject->getPosition().getX();
            break;
        }
        case CIRCLE:
        {
            Vector3* mousePosition = new Vector3(event->x(), event->y(), 0);
            selectedGeometricObject = new Circle(*mousePosition, *mousePosition - *mousePosition);
            this->geometricObjectManager.addObject(selectedGeometricObject);
            //qDebug() << selectedGeometricObject->getPosition().getX();
            break;
        }
        case OVAL:
        {
            Vector3* mousePosition = new Vector3(event->x(), event->y(), 0);
            selectedGeometricObject = new Oval(*mousePosition, *mousePosition - *mousePosition);
            this->geometricObjectManager.addObject(selectedGeometricObject);
            //qDebug() << selectedGeometricObject->getPosition().getX();
            break;
        }
        default:
            break;
        }
    }
}

void OpenglWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(drawingState == isDrawing)
    {
        Vector3 newScale = *(new Vector3(event->x(), event->y(), 0)) - this->selectedGeometricObject->getPosition();
        this->selectedGeometricObject->setScale(newScale);
    }
}

void OpenglWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton && drawingState == isDrawing)
    {
        drawingState = completeDrawing;
        selectedGeometricObject = NULL;
    }

    //this->geometricObjectManager.printAll();
}

void OpenglWidget::initializeGL()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

void OpenglWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    this->geometricObjectManager.renderAll();
    QMetaObject::invokeMethod(this,"update",Qt::QueuedConnection);
}

void OpenglWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glOrtho(0, w, h, 0, -10, 10);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}
