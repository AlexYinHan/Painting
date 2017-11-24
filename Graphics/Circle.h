#ifndef CIRCLE_H
#define CIRCLE_H

#include <GL/gl.h>
#include <GL/glu.h>
#include "GeometricObject.h"

class Circle : public GeometricObject
{
public:
    Circle();
    Circle(const Vector3& center, const Vector3& scale);
    ~Circle();

    void setRadius(int value);
    void setCenter(const Vector3 &value);

    virtual void render();
    virtual void setScale(Vector3 newScale);

private:
    int Radius; //  半径
    Vector3 Center;  //  圆心

    void CircleMidpoint(int x0, int y0, int R);
};

#endif // CIRCLE_H
