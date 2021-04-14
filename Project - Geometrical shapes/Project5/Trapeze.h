#pragma once
#ifndef Trapeze_h
#define Trapeze_h
#include "Polygon.h"
class Trapeze : public Polygon
{
protected:
	PointXY A, B, C, D;
public:
	Trapeze()
	{
		this->A = PointXY(0, 0);
		this->B = PointXY(0, 0);
		this->C = PointXY(0, 0);
		this->D = PointXY(0, 0);
	}
	Trapeze(PointXY p0, PointXY p1, PointXY p2, PointXY p3)
	{
		if (p0.GetY() != p3.GetY() || p1.GetY() != p2.GetY())
		{
			cout << "NOT TRAPEZE" << endl;
		}
		else
		{
			this->A = p0;
			this->B = p1;
			this->C = p2;
			this->D = p3;
		}
	};
	bool Draw(double x, double y);
	double circumference();
	void GetType();
	double area();
};
#endif

