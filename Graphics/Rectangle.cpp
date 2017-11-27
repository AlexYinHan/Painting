#include "Rectangle.h"

MyRectangle::MyRectangle()
{
    this->LeftTop = Vector3(0, 0, 0);
    this->RightBottom = Vector3(0, 10, 0); //  默认在原点处，边长为10使得其可见

    this->Position = &(this->LeftTop);
}

MyRectangle::MyRectangle(const Vector3 &leftTop, const Vector3 &rightBottom)
{
    this->LeftTop = leftTop;
    this->RightBottom = rightBottom;

    this->Position = &(this->LeftTop);
}

MyRectangle::~MyRectangle()
{

}

void MyRectangle::setLeftTop(const Vector3 &value)
{
    LeftTop = value;
}

void MyRectangle::setRightBottom(const Vector3 &value)
{
    RightBottom = value;
}

void MyRectangle::render()
{
    glPointSize(this->getLineWidth());
    glBegin(GL_POINTS);
    glColor3f(0.0, 0.0, 0.0);
    RectangleBresenham((int)(this->LeftTop.getX()), (int)(this->LeftTop.getY()), (int)(this->RightBottom.getX()), (int)(this->RightBottom.getY()));
    glEnd();
    glFlush();
}

void MyRectangle::setScale(Vector3 newScale)
{
    this->RightBottom = this->LeftTop + newScale;
}

void LineBresenham(int x0, int y0, int x1, int y1)
{
    int dx = x1 - x0;
    int dy = y1 - y0;
    int signX = dx > 0 ? 1 : -1;
    int signY = dy > 0 ? 1 : -1;

    int y = y0, x = x0;	//	(x,y)画点坐标

    if (x0 == x1)	// |k| = INF
    {
        while (y != y1)
        {
            glVertex2i(x, y);
            y += signY;
        }
        glVertex2i(x, y);
        return;
    }

    dx = abs(dx);
    dy = abs(dy);
    int dx2 = dx << 1;
    int dy2 = dy << 1;
    int p;	//	判别式

    if (dx > dy)
    {	//	|k| < 1
        p = -dx;
        for (; x != x1; x += signX)
        {
            glVertex2i(x, y);
            p += dy2;
            if (p > 0)
            {
                y += signY;
                p -= dx2;
            }
        }
    }
    else
    {	//	|k| >= 1
        p = -dy;
        for (; y != y1; y += signY)
        {
            glVertex2i(x, y);
            p += dx2;
            if (p > 0)
            {
                x += signX;
                p -= dy2;
            }
        }
    }
    glVertex2i(x, y);	// 点(x1, y1)
}

void MyRectangle::RectangleBresenham(int x0, int y0, int x1, int y1)
{
    LineBresenham(x0, y0, x1, y0);
    LineBresenham(x0, y0, x0, y1);
    LineBresenham(x1, y0, x1, y1);
    LineBresenham(x0, y1, x1, y1);
}
