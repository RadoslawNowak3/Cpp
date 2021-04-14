#pragma once
#ifndef Triangle_h
#define Triangle_h
#include "Polygon.h"
class Triangle : public Polygon
{
protected:
	PointXY A, B, C;
public:
	Triangle()
	{
		this->A = PointXY(0, 0);
		this->B = PointXY(0, 0);
		this->C = PointXY(0, 0);
	};
	Triangle(PointXY p0, PointXY p1, PointXY p2)
	{
		this->A = p0;
		this->B = p1;
		this->C = p2;
	};
	bool Draw(double x, double y);
	void GetType();
	double area();
	double circumference();
};
#endif
