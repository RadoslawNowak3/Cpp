#include "Hexagon.h"
bool AreSame(double a, double b)
{
	return fabs(a - b) < DBL_EPSILON;
}
Hexagon::Hexagon(PointXY p0, PointXY p1, PointXY p2, PointXY p3, PointXY p4, PointXY p5)
{
int z = 0;
if (p0.GetY() != p5.GetY() || p0.GetX() != p2.GetX() || p1.GetY() != p4.GetY() || p2.GetY() != p3.GetY() || p3.GetX() != p5.GetX())
{
	z = 1;
}
/*double a = 0;
double b = 0;
a = sqrt(pow(p0.GetX() - p5.GetX(), 2) + pow(p0.GetY() - p5.GetY(), 2));
b = sqrt(pow(p1.GetX() - p0.GetX(), 2) + pow(p1.GetY() - p0.GetY(), 2));
if (AreSame(a,b)!=0)
{
	z = 1;
}
b = sqrt(pow(p2.GetX() - p1.GetX(), 2) + pow(p2.GetY() - p1.GetY(), 2));
	if (AreSame(a, b) != 0)
{
	z = 1;
}
b = sqrt(pow(p3.GetX() - p2.GetX(), 2) + pow(p3.GetY() - p2.GetY(), 2));
	if(AreSame(a, b) == 0)
	{
		z = 1;
	}
b = sqrt(pow(p4.GetX() - p3.GetX(), 2) + pow(p4.GetY() - p3.GetY(), 2));
	if (AreSame(a, b) != 0)
	{
			z = 1;
	}
b = sqrt(pow(p5.GetX() - p4.GetX(), 2) + pow(p5.GetY() - p4.GetY(), 2));
	if(AreSame(a, b) != 0)
	{
			z = 1;
	}
*/
if (z == 0)
{
	this->A = p0;
	this->B = p1;
	this->C = p2;
	this->D = p3;
	this->E = p4;
	this->F = p5;
}
if(z==1)
cout << "NOT HEXAGON" << endl;
};
bool Hexagon::Draw(double x, double y)
{
	double x1 = this->A.GetX();
	double x2 = this->B.GetX();
	double x3 = this->C.GetX();
	double x4 = this->D.GetX();
	double x5 = this->E.GetX();
	double x6 = this->F.GetX();
	double y1 = this->A.GetY();
	double y2 = this->B.GetY();
	double y3 = this->C.GetY();
	double y4 = this->D.GetY();
	double y5 = this->E.GetY();
	double y6 = this->F.GetY();
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
	if ((((y - y5)*(x5 - x4) - (y5 - y4)*(x - x4)) == 0) && x >= min(x5, x4) && x <= max(x5, x4) && y >= min(y5, y4) && y <= max(y5, y4))
	{
		return true;
	}
	if ((((y - y6)*(x6 - x5) - (y6 - y5)*(x - x5)) == 0) && x >= min(x6, x5) && x <= max(x6, x5) && y >= min(y6, y5) && y <= max(y6, y5))
	{
		return true;
	}
	if ((((y - y1)*(x1 - x6) - (y1 - y6)*(x - x6)) == 0) && x >= min(x1, x6) && x <= max(x1, x6) && y >= min(y1, y6) && y <= max(y1, y6))
	{
	
		return true;
	}
	return false;
};
double Hexagon::circumference()
{
	double a;
	a = sqrt(pow((this->A.GetX() - this->F.GetX()), 2) + pow((this->A.GetY() - this->F.GetY()), 2));
	return 6*a;
};
double Hexagon::area()
{
	double a;
	a = sqrt(pow((this->A.GetX() - this->F.GetX()), 2) + pow((this->A.GetY() - this->F.GetY()), 2));;
	return (3 * pow(a, 2)*sqrt(3) / 2);
};
void Hexagon::GetType()
{
	cout << "Hexagon" << endl;
};