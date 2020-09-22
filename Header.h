#pragma once
#include<iostream>
#include<math.h>
#include<sstream>
namespace Prog2 {
	struct Point {
		double x, y;
		Point(double x0 = 0, double y0 = 0) :x(x0), y(y0) {}
	};
	class Verzera {
	private:
		Point A;
	public:
		Verzera();
		Verzera(double y, double x = 0);
		Verzera(const Verzera& r);
		Verzera& setA(Point A0);// сетер
		Point getA()const;
		double CoordY(double x)const;
		void Inflection (Point& P1,Point& P2)const;
		double Area() const;
		double Volume() const;
		std::stringstream frm()const;
	};
}