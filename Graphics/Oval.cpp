#include "Oval.h"

MyOval::MyOval()
{
    this->Center = Vector3(0, 0, 0);
    this->AxisX = 5;
    this->AxisY = 10;   //  默认在原点处，长轴10短轴5使得其可见

    this->Position = &(this->Center);
}

MyOval::MyOval(const Vector3 &center, const Vector3 &scale)
{
    this->Center = center;
    this->AxisX = scale.getX();
    this->AxisY = scale.getY();

    this->Position = &(this->Center);
}

MyOval::~MyOval()
{

}

void MyOval::setAxisY(int value)
{
    AxisY = value;
}

void MyOval::setAxisX(int value)
{
    AxisX = value;
}

void MyOval::setCenter(const Vector3 &value)
{
    Center = value;
}

void MyOval::render()
{
    glPointSize(this->getLineWidth());
    glBegin(GL_POINTS);
    glColor3f(0.0, 0.0, 0.0);
    EllipseMidpoint((int)(this->Center.getX()), (int)(this->Center.getY()), this->AxisX, this->AxisY);
    glEnd();
    glFlush();
}

void MyOval::setScale(Vector3 newScale)
{
    this->AxisX = abs(newScale.getX());
    this->AxisY = abs(newScale.getY());
}

static void drawSymmetricalPoints(int x, int y, int x0, int y0)    //  依据第一象限中的点的坐标，绘制出对称的椭圆形的点
{
    glVertex2i(x + x0, y + y0);
    glVertex2i(-x + x0, y + y0);
    glVertex2i(x + x0, -y + y0);
    glVertex2i(-x + x0, -y + y0);
}

void MyOval::EllipseMidpoint(int xc, int yc, int rx, int ry)
{
    double rx2 = rx*rx, ry2 = ry*ry;  //  rx的平方和ry的平方
    int x = 0, y = ry;
    double k = ry2*x - rx2*y;   //  斜率绝对值减一，当k>=0进入区域2
    double p = ry2 - rx2*ry + rx2*0.25;    //  判别式
    drawSymmetricalPoints(x, y, xc, yc);
    while(k < 0)
    {
        if(p < 0)
        {
            p += 2*ry2*x + 3*ry2;
        }
        else
        {
            p += 2*ry2*x + 3*ry2 - 2*rx2*y+2*rx2;
            y --;
            k += rx2;
        }
        x ++;
        k += ry2;
        drawSymmetricalPoints(x, y, xc, yc);
    }
    p = ry2*(x+0.5)*(x+0.5) + rx2*(y-1)*(y-1) - rx2*ry2;
    while(y >= 0)
    {

        if(p > 0)
        {
            p += -2*rx2*y + 3*rx2;
        }
        else
        {
            p += 2*ry2*x + 2*ry2 -2*rx2*y + 3*rx2;
            x ++;
        }
        y --;
        drawSymmetricalPoints(x, y, xc, yc);
    }
}
