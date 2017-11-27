#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <GL/gl.h>
#include <GL/glu.h>
#include "GeometricObject.h"

class MyRectangle : public GeometricObject
{
public:
    MyRectangle();
    MyRectangle(const Vector3& leftTop, const Vector3& rightBottom);
    ~MyRectangle();

    void setLeftTop(const Vector3 &value);
    void setRightBottom(const Vector3 &value);

    virtual void render();
    virtual void setScale(Vector3 newScale);

private:
    Vector3 LeftTop, RightBottom;

    void RectangleBresenham(int x0, int y0, int x1, int y1);
};

#endif // RECTANGLE_H
