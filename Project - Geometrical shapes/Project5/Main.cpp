#include <iostream>
#define _USE_MATH_DEFINES
#include <cstdlib>
#include "Objects.h"
// Punkty powinny być rownolegle do osi OX i podawane zgodnie z ruchem wskazowek zegara, poczawszy od lewego dolnego.
using namespace std;
int main()
{   // Punkty i linie dla przeciazania operatorow //
	PointXY lpoint1(3, 5);
	PointXY lpoint2(5, 7);
	PointXY point1(2, 4);
	PointXY point2(1, 2);
	Line line1(point1, lpoint1);
	Line line2(point2, lpoint2);
	PointXY point3, point4, point5;
	// Punkty dla figur //
	// Prostokat //
	PointXY rpoint1(0, 0);
	PointXY rpoint2(0, 4);
	PointXY rpoint3(2, 4);
	PointXY rpoint4(2, 0);
	// Trapez //
	PointXY tpoint1(0, 0);
	PointXY tpoint2(1, 4);
	PointXY tpoint3(4, 4);
	PointXY tpoint4(6, 0);
	// Trojkat //
	PointXY trpoint1(0, 0);
	PointXY trpoint2(4, 9);
	PointXY trpoint3(7, 0);
	// Szesciokat foremny //
	PointXY hpoint1(-1, -sqrt(3));
	PointXY hpoint2(-2, 0);
	PointXY hpoint3(-1, sqrt(3));
	PointXY hpoint4(1,sqrt(3));
	PointXY hpoint5(2, 0);
	PointXY hpoint6(1, -sqrt(3));
	// Kolo //
	PointXY kpoint1(0, 5);
	double promien = 10;
	// Romb //
	PointXY rhpoint1(2, -3);
	PointXY rhpoint2(-18, 7);
	PointXY rhpoint3(4, 11);
	PointXY rhpoint4(24, 1);
	int a;
	point3 = point1 * point2;
	cout << "Demonstracja przeciazen operatorow dla PointXY" << endl;
	cout << "Mnozenie" << endl;
	cout << "X = " << point3.GetX() << " , " << "Y= " << point3.GetY() << endl;
	point4 = point1 - point2;
	cout << "Odejmowanie" << endl;
	cout << "X = " << point4.GetX() << " , " << "Y= " << point4.GetY() << endl;
	point5 = point1 + point2;
	cout << "Dodawanie" << endl;
	cout << "X = " <<  point5.GetX() << " , " << "Y= " << point5.GetY() << endl;
	cout << "Demonstracja przeciazenia operatora mnozenia dla ";
	line1.GetType();
	cout << line1 * line2 << endl;

	cout << "Demonstracja dzialania metod dla figur" << endl;

	Rectangle rec1(rpoint1, rpoint2, rpoint3, rpoint4);
	GeometricObject * wskaznik= &rec1;
	wskaznik->GetType();
	cout << "Metoda draw " << endl;
	cout << wskaznik->Draw(6, 4) << endl;
	cout << wskaznik->Draw(1, 0) << endl;
	cout << "Pole figury" << endl;
	cout << rec1.area() << endl;
	cout << "Obwod figury" << endl;
	cout << rec1.circumference() << endl;
	cout << endl;

	Trapeze trap1(tpoint1, tpoint2, tpoint3, tpoint4);
	wskaznik = &trap1;
	wskaznik->GetType();
	cout << "Metoda draw " << endl;
	cout << wskaznik->Draw(2, 4) << endl;
	cout << wskaznik->Draw(3, 0) << endl;
	cout << "Pole figury" << endl;
	cout << trap1.area() << endl;
	cout << "Obwod figury" << endl;
	cout << trap1.circumference() << endl;
	cout << endl;

	Triangle tri1(trpoint1, trpoint2, trpoint3);
	wskaznik = &tri1;
	wskaznik->GetType();
	cout << "Metoda draw " << endl;
	cout << wskaznik->Draw(2, 4) << endl;
	cout << wskaznik->Draw(3, 0) << endl;
	cout << "Pole figury" << endl;
	cout << tri1.area() << endl;
	cout << "Obwod figury" << endl;
	cout << tri1.circumference() << endl;
	cout << endl;

	Hexagon hex1(hpoint1, hpoint2, hpoint3, hpoint4, hpoint5, hpoint6);
	wskaznik = &hex1;
	wskaznik->GetType();
	cout << "Metoda draw " << endl;
	cout << wskaznik->Draw(2, 4) << endl;
	cout << wskaznik->Draw(3, 0) << endl;
	cout << "Pole figury" << endl;
	cout << hex1.area() << endl;
	cout << "Obwod figury" << endl;
	cout << hex1.circumference() << endl;
	cout << endl; 

	Circle cir1(promien, kpoint1);
	wskaznik = &cir1;
	wskaznik->GetType();
	cout << "Metoda draw " << endl;
	cout << wskaznik->Draw(2, 4) << endl;
	cout << wskaznik->Draw(3, 0) << endl;
	cout << "Pole figury" << endl;
	cout << cir1.area() << endl;
	cout << "Obwod figury" << endl;
	cout << cir1.circumference() << endl;
	cout << endl;

	Rhombus rho1(rhpoint1, rhpoint2, rhpoint3, rhpoint4);
	wskaznik = &rho1;
	wskaznik->GetType();
	cout << "Metoda draw " << endl;
	cout << wskaznik->Draw(2, 4) << endl;
	cout << wskaznik->Draw(3, 0) << endl;
	cout << "Pole figury" << endl;
	cout << rho1.area() << endl;
	cout << "Obwod figury" << endl;
	cout << rho1.circumference() << endl;
	cout << endl;
	cin >> a;
	return 0;
}