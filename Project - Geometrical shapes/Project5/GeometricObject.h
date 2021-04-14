#pragma once
#ifndef GeometricObject_h
#define GeometricObject_h
#include "PointXY.h"
using namespace std;
class GeometricObject
{
public:
	virtual bool Draw(double a, double b) = 0;
	virtual void GetType()
	{
		cout << "Unknown" << endl;
	}
};
#endif 
