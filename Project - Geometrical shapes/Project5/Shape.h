#ifndef Shape_h
#define Shape_h
#include "GeometricObject.h"
class Shape : public GeometricObject
{
public:
	virtual double area() = 0;
	virtual double circumference() = 0;
};
#endif