/**
	* Line: 直线类
    * 基类的Position即为StartPoint，表示起点，私有成员EndPoint表示终点
	*/
#ifndef LINE_H
#define LINE_H

#include <GL/gl.h>
#include <GL/glu.h>
#include "GeometricObject.h"

class MyLine: public GeometricObject
{
public:
    MyLine();
    MyLine(const Vector3& startPoint, const Vector3& endPoint);
    ~MyLine();
    void setStartPoint(Vector3 coordinate);
    void setEndPoint(Vector3 coordinate);

	virtual void render();
    virtual void setScale(Vector3 newScale);
private:
    Vector3 StartPoint, EndPoint;

	void LineBresenham(int x0, int y0, int x1, int y1);
};

#endif
