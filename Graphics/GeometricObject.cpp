#include "GeometricObject.h"


GeometricObject::GeometricObject()
{
    this->Position = NULL;
    //this->Rotation = Vector3(0.0f, 0.0f, 0.0f);
    //this->Scale = Vector3(0.0f, 0.0f, 0.0f);
}
GeometricObject::GeometricObject(Vector3* position)
{
    this->Position = position;
}

GeometricObject::~GeometricObject()
{
}
/*
void GeometricObject::reset()
{
	GeometricObject::resetPosition();
    //GeometricObject::resetRotation();
}
void GeometricObject::resetPosition()
{
	this->Position = Vector3(0.0f, 0.0f, 0.0f);
}
*/
/*
void GeometricObject::resetRotation()
{
	this->Rotation = Vector3(0.0f, 0.0f, 0.0f);
}
*/
Vector3 GeometricObject::getPosition()
{
    return *this->Position;
}

void GeometricObject::render()
{

}

void GeometricObject::setScale(Vector3 newScale)
{
    qDebug() << "Should not call this virtual function : setScale( "
             << newScale.getX() << ", " << newScale.getY() << ", " << newScale.getY()
             << ")" << endl;
}
