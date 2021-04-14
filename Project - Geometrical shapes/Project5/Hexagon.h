#pragma once
#ifndef Hexagon_h
#define Hexagon_h
#include "Polygon.h"	
class Hexagon : public Polygon
{
protected:
	PointXY A, B, C, D, E, F;
public:
	Hexagon()
	{
		this->A = PointXY(0, 0);
		this->B = PointXY(0, 0);
		this->C = PointXY(0, 0);
		this->D = PointXY(0, 0);
		this->E = PointXY(0, 0);
		this->F = PointXY(0, 0);
	}
	Hexagon(PointXY p0, PointXY p1, PointXY p2, PointXY p3, PointXY p4, PointXY p5);
	bool Draw(double x, double y);
	double circumference();
	void GetType();
	double area();
};
#endif 