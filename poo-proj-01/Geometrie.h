#pragma once

#ifndef GEOMETRIE
#define GEOMETRIE

#include "Figura.h"

class Geometrie
{
	int nrFiguri;
	Figura* fig;

public:
	Geometrie();
	Geometrie(int nrFig);
	Geometrie(int nrFig, Figura* const figuri);
	Geometrie(int nrFig, ...);

	void operator=(const Geometrie& other);
	void operator+=(const Punct2D& punct);
	void operator-=(int nrPct);

	~Geometrie();

	friend std::istream& operator>>(std::istream& is, Geometrie& figura);
	friend std::ostream& operator<<(std::ostream& os, const Geometrie& geom);
};

#endif 