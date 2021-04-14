#ifndef Polygon_h
#define Polygon_h
#include "Shape.h"
#pragma once
class Polygon : public Shape
{
public:
	void GetType()
	{
		cout << "Polygon" << endl;
	};
};
#endif
