#include "Circle.h"

MyCircle::MyCircle()
{
    this->Center = Vector3(0, 0, 0);
    this->Radius = 5;   //  默认在原点处，半径为5使得其可见

    this->Position = &(this->Center);
}

MyCircle::MyCircle(const Vector3 &center, const Vector3 &scale)
{
    this->Center = center;
    this->Radius = (int)(scale.getNorm());

    this->Position = &(this->Center);
}

MyCircle::~MyCircle()
{

}

void MyCircle::setRadius(int value)
{
    Radius = value;
}

void MyCircle::setCenter(const Vector3 &value)
{
    Center = value;
}

void MyCircle::render()
{
    glPointSize(this->getLineWidth());
    glBegin(GL_POINTS);
    glColor3f(0.0, 0.0, 0.0);
    CircleMidpoint((int)(this->Center.getX()), (int)(this->Center.getY()), this->Radius);
    glEnd();
    glFlush();
}

void MyCircle::setScale(Vector3 newScale)
{
    this->Radius = (int)newScale.getNorm();
}

static void drawSymmetricalPoints(int x, int y, int x0, int y0)    //  依据第一象限中的点的坐标，绘制出对称的圆形的点
{
    glVertex2i(x + x0, y + y0);
    glVertex2i(-x + x0, y + y0);
    glVertex2i(x + x0, -y + y0);
    glVertex2i(-x + x0, -y + y0);

    glVertex2i(y + x0, x + y0);
    glVertex2i(-y + x0, x + y0);
    glVertex2i(y + x0, -x + y0);
    glVertex2i(-y + x0, -x + y0);
}

void MyCircle::CircleMidpoint(int x0, int y0, int R)
{
    int x, y, deltax, deltay, e;    //  e作为判别式
    x = 0;
    y = R;
    deltax = 3;
    deltay = 5 - R - R;
    e = 1 - R;
    drawSymmetricalPoints(x, y, x0, y0);
    while(x < y)
    {
        if(e < 0)
        {
            e += deltax;
            deltax += 2;
            deltay += 2;
            x++;
        }
        else
        {
            e += deltay;
            deltax += 2;
            deltay += 4;
            x ++;
            y --;
        }
        drawSymmetricalPoints(x, y, x0, y0);
    }
}


