#include "Vector3.h"

//MARK: 构造与析构函数

Vector3::Vector3()
{
	x = y = z = 0.0f;
}

Vector3::Vector3(double x, double y)
{
	this->x = x;
	this->y = y;
}

Vector3::Vector3(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3& Vector3::operator= (const Vector3& v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	return *this;
}

Vector3& Vector3::operator+ (const Vector3& v)
{
    Vector3* result = new Vector3(this->x + v.x,
                                 this->y + v.y,
                                 this->z + v.z);
    return *result;
}

Vector3& Vector3::operator- (const Vector3& v)
{
    Vector3* result = new Vector3(this->x - v.x,
                                 this->y - v.y,
                                 this->z - v.z);
    return *result;
}

void Vector3::setValue(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void Vector3::setX(double x)
{
	this->x = x;
}
void Vector3::setY(double y)
{
	this->y = y;
}
void Vector3::setZ(double z)
{
	this->z = z;
}
double Vector3::getX() const
{
	return this->x;
}
double Vector3::getY() const
{
	return this->y;
}
double Vector3::getZ() const
{
    return this->z;
}

double Vector3::getNorm() const
{
    return sqrt(x*x + y*y + z*z);
}
