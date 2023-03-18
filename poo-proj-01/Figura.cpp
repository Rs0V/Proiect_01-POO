#include "Figura.h"
#include <stdarg.h>

Figura::Figura()
	:
	denumire(""),
	nrPuncte(0),
	P(nullptr)
{
}

Figura::Figura(std::string nume, int nrPct)
	:
	denumire(nume),
	nrPuncte(nrPct),
	P(new Punct2D[nrPct]{})
{
}

Figura::Figura(std::string nume, int nrPct, Punct2D* const puncte)
	:
	denumire(nume),
	nrPuncte(nrPct),
	P(puncte)
{
}

Figura::Figura(std::string nume, int nrPct, ...)
	:
	denumire(nume),
	nrPuncte(nrPct)
{
	va_list coords;
	va_start(coords, nrPct);

	P = new Punct2D[nrPct]{};
	for (int i = 0; i < nrPct; ++i)
		P[i].Set(va_arg(coords, int), va_arg(coords, int));

	va_end(coords);
}

Figura& Figura::operator=(const Figura& other)
{
	denumire = other.denumire;
	nrPuncte = other.nrPuncte;
	delete[] P;
	P = new Punct2D[nrPuncte]{};
	for (int i = 0; i < nrPuncte; ++i)
		P[i] = other.P[i];
	return *this;
}

bool Figura::operator==(const Figura& other)
{
	return (denumire == other.denumire) && (nrPuncte == other.nrPuncte) && (P == other.P);
}

bool Figura::operator!=(const Figura& other)
{
	return !(*this == other);
}

#pragma warning(push)
#pragma warning(disable:6385)
Figura& Figura::operator+=(const Punct2D& punct)
{
	Punct2D* P_copy = P;
	P = new Punct2D[nrPuncte + 1]{};
	for (int i = 0; i < nrPuncte; ++i)
		P[i] = P_copy[i];
	P[nrPuncte] = punct;
	++nrPuncte;
	delete[] P_copy;
	detFigName();
	return *this;
}

Figura& Figura::operator-=(int nrPct)
{
	Punct2D* P_copy = P;
	nrPuncte -= nrPct;
	P = new Punct2D[nrPuncte]{};
	for (int i = 0; i < nrPuncte; ++i)
		P[i] = P_copy[i];
	delete[] P_copy;
	detFigName();
	return *this;
}
#pragma warning(pop)

Figura::~Figura()
{
	delete[] P;
}

void Figura::detFigName()
{
	switch (nrPuncte)
	{
	case 1:
		denumire = "monogon";
		break;

	case 2:
		denumire = "digon";
		break;

	case 3:
		denumire = "triunghi";
		break;

	case 4:
		denumire = "patrat";
		break;

	case 5:
		denumire = "pentagon";
		break;

	case 6:
		denumire = "hexagon";
		break;

	case 7:
		denumire = "heptagon";
		break;

	case 8:
		denumire = "octogon";
		break;

	case 9:
		denumire = "eneagon";
		break;

	case 10:
		denumire = "decagon";
		break;

	case 11:
		denumire = "endecagon";
		break;

	case 12:
		denumire = "dodecagon";
		break;

	default:
		break;
	}
}

std::istream& operator>>(std::istream& is, Figura& figura)
{
	is >> figura.denumire >> figura.nrPuncte;
	delete[] figura.P;
	figura.P = new Punct2D[figura.nrPuncte]{};
	for (int i = 0; i < figura.nrPuncte; ++i)
		is >> figura.P[i];
	return is;
}

std::ostream& operator<<(std::ostream& os, const Figura& figura)
{
	os << "Figura " << figura.denumire << " are " << figura.nrPuncte << " puncte: \n";
	for (int i = 0; i < figura.nrPuncte; ++i)
		os << "\t\t" << figura.P[i] << '\n';
	return os;
}
