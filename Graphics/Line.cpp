#include "Line.h"


MyLine::MyLine()
{
    this->StartPoint = Vector3(0, 0, 0);
    this->EndPoint = Vector3(0, 10, 0); //  默认在原点处，长度为10使得其可见

    this->Position = &(this->StartPoint);
}

MyLine::MyLine(const Vector3& startPoint, const Vector3& endPoint)
{
    this->StartPoint = startPoint;
    this->EndPoint = endPoint;

    this->Position = &(this->StartPoint);
}

MyLine::~MyLine()
{
}

void MyLine::setStartPoint(Vector3 coordinate)
{
    this->StartPoint = coordinate;
}

void MyLine::setEndPoint(Vector3 coordinate)
{
    this->EndPoint = coordinate;
}

void MyLine::render()
{
    glPointSize(this->getLineWidth());
	glBegin(GL_POINTS);
    glColor3f(0.0, 0.0, 0.0);
    LineBresenham((int)(this->StartPoint.getX()), (int)(this->StartPoint.getY()), (int)(this->EndPoint.getX()), (int)(this->EndPoint.getY()));
    glEnd();
	glFlush();
}

void MyLine::setScale(Vector3 newScale)
{
    this->EndPoint = this->StartPoint + newScale;
}

void MyLine::LineBresenham(int x0, int y0, int x1, int y1)
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
