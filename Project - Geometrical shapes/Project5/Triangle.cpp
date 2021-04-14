#include "Triangle.h"
double Triangle::area()
{
	double a = abs(this->A.GetX() - this->C.GetX());
	double h = abs(this->A.GetY() - this->B.GetY());
	return ((a*h) / 2);
};
void Triangle::GetType()
{
	cout << "Triangle" << endl;
};
bool Triangle::Draw(double x, double y)
{
	double x1 = this->A.GetX();
	double x2 = this->B.GetX();
	double x3 = this->C.GetX();
	double y1 = this->A.GetY();
	double y2 = this->B.GetY();
	double y3 = this->C.GetY();
	if ((((y - y2)*(x2 - x1) - (y2 - y1)*(x - x1)) == 0) && x >= min(x1, x2) && x <= max(x1, x2) && y >= min(y1, y2) && y <= max(y1, y2))
	{
		return true;
	}
	if ((((y - y3)*(x3 - x2) - (y3 - y2)*(x - x2)) == 0) && x >= min(x2, x3) && x <= max(x2, x3) && y >= min(y2, y3) && y <= max(y2, y3))
	{
		return true;
	}
	if ((((y - y1)*(x1 - x3) - (y1 - y3)*(x - x3)) == 0) && x >= min(x1, x3) && x <= max(x1, x3) && y >= min(y1, y3) && y <= max(y1, y3))
	{
		return true;
	}
	return false;
};

double Triangle::circumference()
{
	double a, b, c;
	a = sqrt(pow((this->A.GetX() - this->B.GetX()), 2) + pow((this->A.GetY() - this->B.GetY()), 2));
	b = sqrt(pow((this->C.GetX() - this->B.GetX()), 2) + pow((this->C.GetY() - this->B.GetY()), 2));
	c = sqrt(pow((this->A.GetX() - this->C.GetX()), 2) + pow((this->A.GetY() - this->C.GetY()), 2));
	return a + b + c;
}
