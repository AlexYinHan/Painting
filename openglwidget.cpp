#include "openglwidget.h"
#include "ui_openglwidget.h"
#include "Graphics/Line.h"
#include "Graphics/Circle.h"
#include "Graphics/Oval.h"
#include "Graphics/Rectangle.h"

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
            selectedGeometricObject = new MyLine(*mousePosition, *mousePosition);
            this->geometricObjectManager.addObject(selectedGeometricObject);
            //qDebug() << selectedGeometricObject->getPosition().getX();
            break;
        }
        case CIRCLE:
        {
            Vector3* mousePosition = new Vector3(event->x(), event->y(), 0);
            selectedGeometricObject = new MyCircle(*mousePosition, *mousePosition - *mousePosition);
            this->geometricObjectManager.addObject(selectedGeometricObject);
            //qDebug() << selectedGeometricObject->getPosition().getX();
            break;
        }
        case OVAL:
        {
            Vector3* mousePosition = new Vector3(event->x(), event->y(), 0);
            selectedGeometricObject = new MyOval(*mousePosition, *mousePosition - *mousePosition);
            this->geometricObjectManager.addObject(selectedGeometricObject);
            //qDebug() << selectedGeometricObject->getPosition().getX();
            break;
        }
        case RECTANGLE:
        {
            Vector3* mousePosition = new Vector3(event->x(), event->y(), 0);
            selectedGeometricObject = new MyRectangle(*mousePosition, *mousePosition);
            this->geometricObjectManager.addObject(selectedGeometricObject);
            //qDebug() << selectedGeometricObject->getPosition().getX();
            break;
        }
        default:
            qDebug() << "未实现的图元构造函数" << endl;
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
        //selectedGeometricObject = NULL;
    }

    //this->geometricObjectManager.printAll();
}

void OpenglWidget::lineWidthChanged(const int &lineWidth)
{
    if(selectedGeometricObject != NULL)
    {
        selectedGeometricObject->setLineWidth(lineWidth);
    }
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
