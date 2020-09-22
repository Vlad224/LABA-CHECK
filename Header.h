#pragma once
#include<iostream>
#include<math.h>
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#include<string>
#include<sstream>
#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif
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
		//void frm(char* &s)const;
		//std::string frm()const;
		std::stringstream frm()const;
	};
}