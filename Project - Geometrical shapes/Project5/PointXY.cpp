#include "PointXY.h"
using namespace std;
double PointXY::GetX()
{
	return x;
};
double PointXY::GetY()
{
	return y;
};

PointXY operator+(PointXY point1, PointXY point2)
{
	PointXY point3;
	point3.x = (point1.x + point2.x);
	point3.y = (point1.y + point2.y);
	return point3;
}
PointXY operator-(PointXY point1, PointXY point2)
{
	PointXY point3;
	point3.x = (point1.x - point2.x);
	point3.y = (point1.y - point2.y);
	return point3;
}
PointXY operator*(PointXY point1, PointXY point2)
{
	PointXY point3;
	point3.x = (point1.x * point2.x);
	point3.y = (point1.y * point2.y);
	return point3;
}