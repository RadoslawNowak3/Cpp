#pragma once
#ifndef Rectangle_h
#define Rectangle_h
#include "Polygon.h"
class Rectangle : public Polygon
{
protected:
	PointXY A, B, C, D;
public:
	Rectangle() 
	{ 
		this->A = PointXY(0, 0); 
		this->B = PointXY(0, 0); 
		this->C = PointXY(0, 0);  
		this->D = PointXY(0, 0);
	}
	Rectangle(PointXY p0, PointXY p1, PointXY p2, PointXY p3)
	{
		if (p0.GetX() != p1.GetX() || p0.GetY() != p3.GetY() || p1.GetY() != p2.GetY() || p2.GetX() != p3.GetX())
		{
			cout << "NOT RECTANGLE!" << endl;
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


