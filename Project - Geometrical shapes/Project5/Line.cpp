#include "Line.h"
void Line::GetType()
{
	cout << "Line" << endl;
};

bool Line::Draw(double x, double y)
{
	double x1 = this->p0.GetX();
	double x2 = this->p1.GetX();
	double y1 = this->p0.GetY();
	double y2 = this->p1.GetY();

	if (((y - y2)*(x2 - x1) - (y2 - y1)*(x - x1)) == 0)
		return true;
	else
		return false;
}; 
double operator*(Line line1, Line line2)
{
	double wynik;
	wynik = (line1.p0.GetX()*line2.p0.GetX() + line1.p1.GetY()*line2.p1.GetY());
	return wynik;
}