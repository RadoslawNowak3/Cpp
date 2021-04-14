#ifndef PointXY_h
#define PointXY_h
#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <float.h>
using namespace std;
class PointXY
{
protected:
	double x, y;
public:
	PointXY()
	{
		this->x = 0;
		this->y = 0;
	};
	PointXY(double _X, double _Y)
	{
		this->x = _X;
		this->y = _Y;
	};
	double GetX();
	double GetY();
	friend PointXY operator+(const PointXY p1, const PointXY p2);
	friend PointXY operator-(const PointXY p1, const PointXY p2);
	friend PointXY operator*(const PointXY p1, const PointXY p2);
};
#endif