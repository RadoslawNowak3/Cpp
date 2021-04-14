#pragma once
#ifndef Circle_h
#define Circle_h
#include "GeometricObject.h"
class Circle : public GeometricObject
{
protected:
	PointXY p1;
	double r;
public:
	Circle() 
	{
		this->r = 0;
		this->p1 = PointXY(0, 0);
	}
	Circle(double radius, PointXY point)
	{
		this->r = radius;
		this->p1 = point;
	}
	bool Draw(double x, double y);
	void GetType();
	double area();
	double circumference();
};
#endif

