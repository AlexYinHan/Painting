/**
    * EmptyObejct类，作为大多数图形部件的基类
	*/
#pragma once
#include "common.h"

class GeometricObject
{
public:
	GeometricObject();
    GeometricObject(Vector3* position);
	~GeometricObject();

    //void reset();
    //void resetPosition();
    //void resetRotation();
    Vector3 getPosition();

    virtual void render();
    virtual void setScale(Vector3 newScale);    //  when the scale changes, some points' positions should change accordingly, so currently this function is virtual.

protected:
    Vector3* Position;  //  指向图元某一个顶点，用于获取某一个图元的位置
    //Vector3 Rotation, Scale;
};


