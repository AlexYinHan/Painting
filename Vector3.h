/**
	* Vector3： 三维向量，用于传递位置等信息
	*/
#pragma once
#include <cmath>
class Vector3
{
private:
	double x, y, z;
public:
	Vector3();
	Vector3(double x, double y);
	Vector3(double x, double y, double z);

	Vector3& operator= (const Vector3& v);
    Vector3& operator+ (const Vector3& v);
    Vector3& operator- (const Vector3& v);

    void setValue(double x, double y, double z);
	void setX(double x);
	void setY(double y);
	void setZ(double z);
    double getX() const;
    double getY() const;
    double getZ() const;

    double getNorm() const;
};
