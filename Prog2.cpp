#include"Header.h"
int main()
{
	Prog2::Verzera c(2,0);
	Prog2::Point P1;
	Prog2::Point P2;
	Prog2::Point p;
	int fl1 = 1;
	double r;
	char* s = NULL;
	while (fl1) {
		std::cout << "Your Verzera Anyeza is:" << std::endl;
		std::stringstream s = c.frm();
		std::cout << s.str() << std::endl;
		std::cout << "Area: " << c.Area() << std::endl;
		c.Inflection(P1, P2);
		std::cout << "Inflection Points: ( " << P1.x <<" , "<<P1.y<<" ) , ( "<< P2.x << " , " << P2.y <<" )"<< std::endl;
		std::cout << "Volume: " << c.Volume() << std::endl;
		int fl2 = 1;
		while (fl2) {
			std::cout << "Enter x for calculate value y(x) or precc ctrl+Z to quit:" <<std::endl;
			double x;
			double y;
			std::cin >> x;
			fl2 = std::cin.good();
			if (!fl2)
				continue;
			try {
				y = c.CoordY(x);
				std::cout << "y = " << y << std::endl;
			}
			catch (std::exception & ex)
			{
				std::cout << ex.what() << std::endl;
			}
		}
		std::cin.clear();
		std::cout << "Enter new x, y for A to continue or press ctrl+Z to quit:" << std::endl;
		std::cin >> p.x >> p.y;
		if (std::cin.good()) {
			try {
				c.setA(p);
			}
			catch (std::exception & ex)
			{
				std::cout << ex.what() << std::endl;
			}
		}
		else
			fl1 = 0;
	}
	_CrtDumpMemoryLeaks();
	return 0;
}