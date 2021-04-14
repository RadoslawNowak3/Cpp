#pragma once
#ifndef Line_h
#define Line_h
#include "GeometricObject.h"
class Line : public GeometricObject
{
protected:
	PointXY p0, p1;

public:
	Line()
	{
		this->p0 = PointXY(0, 0);
		this->p1 = PointXY(0, 0);
	}
	Line(PointXY p0, PointXY p1)
	{
		this->p0 = p0;
		this->p1 = p1;
	}
	void GetType();
	bool Draw(double x, double y);
	friend double operator*(Line line1, Line line2);
};

#endif
