#pragma once

#ifndef FIGURA
#define FIGURA

#include <string>
#include "Punct2D.h"

class Figura
{
	std::string denumire;
	int nrPuncte;
	Punct2D* P;

public:
	Figura();
	Figura(std::string nume, int nrPct);
	Figura(std::string nume, int nrPct, Punct2D* const puncte);
	Figura(std::string nume, int nrPct, ...);

	Figura& operator=(const Figura& other);
	bool operator==(const Figura& other);
	bool operator!=(const Figura& other);
	Figura& operator+=(const Punct2D& punct);
	Figura& operator-=(int nrPct);

	~Figura();

	friend std::istream& operator>>(std::istream& is, Figura& figura);
	friend std::ostream& operator<<(std::ostream& os, const Figura& figura);

	void detFigName();
};

#endif