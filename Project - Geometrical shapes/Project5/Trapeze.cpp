#include "Trapeze.h"

bool Trapeze::Draw(double x, double y)
{
		double x1 = this->A.GetX();
		double x2 = this->B.GetX();
		double x3 = this->C.GetX();
		double x4 = this->D.GetX();
		double y1 = this->A.GetY();
		double y2 = this->B.GetY();
		double y3 = this->C.GetY();
		double y4 = this->D.GetY();
		if ((((y - y2)*(x2 - x1) - (y2 - y1)*(x - x1)) == 0) && x >= min(x1, x2) && x <= max(x1, x2) && y >= min(y1, y2) && y <= max(y1, y2))
		{
			return true;
		}
		if ((((y - y3)*(x3 - x2) - (y3 - y2)*(x - x2)) == 0) && x >= min(x2, x3) && x <= max(x2, x3) && y >= min(y2, y3) && y <= max(y2, y3))
		{
			return true;
		}
		if ((((y - y4)*(x4 - x3) - (y4 - y3)*(x - x3)) == 0) && x >= min(x3, x4) && x <= max(x3, x4) && y >= min(y3, y4) && y <= max(y3, y4))
		{
			return true;
		}
		if ((((y - y1)*(y1 - y4) - (y1 - y4)*(x - x4)) == 0) && x >= min(x1, x4) && x <= max(x1, x4) && y >= min(y1, y4) && y <= max(y1, y4))
		{
			return true;
		}
		return false;
};
double Trapeze::circumference()
{
	double a, b, c,d;
	a = sqrt(pow((this->A.GetX() - this->B.GetX()), 2) + pow((this->A.GetY() - this->B.GetY()), 2));
	b = sqrt(pow((this->B.GetX() - this->C.GetX()), 2) + pow((this->B.GetY() - this->C.GetY()), 2));
	c = sqrt(pow((this->C.GetX() - this->D.GetX()), 2) + pow((this->C.GetY() - this->D.GetY()), 2));
	d = sqrt(pow((this->D.GetX() - this->A.GetX()), 2) + pow((this->D.GetY() - this->A.GetY()), 2));
	return a+b+c+d;
};
double Trapeze::area()
{
	double a, b, h;
	a = sqrt(pow((this->A.GetX() - this->D.GetX()), 2) + pow((this->A.GetY() - this->D.GetY()), 2));
	b = sqrt(pow((this->B.GetX() - this->C.GetX()), 2) + pow((this->B.GetY() - this->C.GetY()), 2));
	h = abs(this->A.GetY() - this->B.GetY());
	return (a + b)*h;
};
void Trapeze::GetType()
{
	cout << "Trapeze" << endl;
};