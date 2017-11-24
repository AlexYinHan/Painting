#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <GL/gl.h>
#include <GL/glu.h>
#include "GeometricObject.h"

class Oval : public GeometricObject
{
public:
    Oval();
    Oval(const Vector3& center, const Vector3& scale);
    ~Oval();

    void setAxisY(int value);
    void setAxisX(int value);
    void setCenter(const Vector3 &value);

    virtual void render();
    virtual void setScale(Vector3 newScale);

private:
    Vector3 Center; //  椭圆中心
    int AxisX, AxisY;   //  长短轴

    void EllipseMidpoint(int xc, int yc, int rx, int ry);
};

#endif // ELLIPSE_H
