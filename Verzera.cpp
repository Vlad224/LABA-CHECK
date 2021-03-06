#include"Verzera.h"
namespace Prog2 {
	Verzera::Verzera() : A(0,0) {}
	Verzera::Verzera(double y,double x){
		Point P(x, y);
		setA(P);
	}
	Verzera& Verzera::setA(Point A0){
		if (A0.x != 0)
			throw std::exception("invalid coordinats");
		A = A0;
		return *this;
	}
	void Verzera::Inflection(Point& P1, Point& P2) const{
		P1.x = A.y / sqrt(3);
		P2.x = -A.y / sqrt(3);
		P1.y = 3*(A.y)/4;
		P2.y = P1.y;
	}
	double Verzera::Volume() const { return (3.14159 * 3.14159 * A.y * A.y * A.y) / 2; }
	Point Verzera::getA()const { return A; }
	double Verzera::Area() const { return (3.14159 * (A.y) * (A.y)); }
	std::string Verzera::frm()const {
		std::stringstream s;
	    s << "y = ";
		if (A.y != 0)
			s  << A.y * A.y * A.y << "/( " << A.y * A.y << " + x^2 )";
		else
			s  << A.y<<"; {x!=0}";
		return s.str();
	}
	double Verzera::CoordY(double x) const
	{
		if(A.y==0 && x==0)
			throw std::exception("invalid coordinats");
		return (A.y * A.y * A.y) / (A.y * A.y + x * x);
	}
}