#include <iostream>
#include "Geometrie.h"

int main()
{
	Punct2D p1(1, -1), p2(2), p3[4], p4[2];
	for (int x = 0; x < 4; x++)
		std::cin >> p3[x];
	p4[0] = p1;
	p4[1] = p2;
	Figura f1("triunghi dreptunghic", 3), f2("Segment", 2, p4), f3[2];
	std::cin >> f3[0];
	f3[1] = f3[0];
	f3[1] += p1;
	if (f1 != f3[1])
		std::cout << f1 << "difera de " << f3[1] << '\n';
	Geometrie g1, g2(2, f3), g3(1, "patrat", 4, 0, 0, 0, 1, 1, 1, 1, 0), g4 = g3;
	std::cin >> g1;
	g3 -= 1;
	std::cout << g3 << g4;

	return 0;
}