#include <iostream>
#include "Geometrie.h"

int main()
{
	Figura f0("triunghi", 3, -1, -1, 1, 1, 0, 1 );
	Figura f1("patrat", 4, 1, 1, 1, -1, -1, -1, -1, 1);
	Geometrie g0(2, f0, f1);
	std::cout << var_name(g0) << ": " << g0;

	return 0;
}