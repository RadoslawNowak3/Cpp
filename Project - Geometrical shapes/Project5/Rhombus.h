#pragma once
#ifndef Rhombus_h
#define Rhombus_h
#include "Polygon.h"
class Rhombus : public Polygon
{
protected:
	PointXY A, B, C, D;
public:
	Rhombus()
	{
		this->A = PointXY(0, 0);
		this->B = PointXY(0, 0);
		this->C = PointXY(0, 0);
		this->D = PointXY(0, 0);
	}
	Rhombus(PointXY p0, PointXY p1, PointXY p2, PointXY p3)
	{
			this->A = p0;
			this->B = p1;
			this->C = p2;
			this->D = p3;
	};
	bool Draw(double x, double y);
	double circumference();
	void GetType();
	double area();
};
#endif
