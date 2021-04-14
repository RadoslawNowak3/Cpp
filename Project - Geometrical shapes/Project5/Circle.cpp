#include "Circle.h"
bool Circle::Draw(double x, double y)
{
	double x1 = this->p1.GetX();
	double y1 = this->p1.GetY();
	if (sqrt(pow((x - x1), 2) + pow((y - y1), 2)) >= this->r)
		return false;
	else
		return true;
};
void Circle::GetType()
{
	cout << "Circle" << endl;
};
double Circle::area()
{
	return (pow(this->r,2)*M_PI);
}
double Circle::circumference()
{
	return(this->r * 2 * M_PI);
};