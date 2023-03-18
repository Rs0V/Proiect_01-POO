#include "Geometrie.h"
#include <stdarg.h>

Geometrie::Geometrie()
	:
	nrFiguri(0),
	fig(nullptr)
{
}

Geometrie::Geometrie(int nrFig)
	:
	nrFiguri(nrFig),
	fig(new Figura[nrFig]{})
{
}

Geometrie::Geometrie(int nrFig, Figura* const figuri)
	:
	nrFiguri(nrFig),
	fig(figuri)
{
}

Geometrie::Geometrie(int nrFig, ...)
	:
	nrFiguri(nrFig)
{
	va_list figuri;
	va_start(figuri, nrFig);

	fig = new Figura[nrFig]{};
	for (int i = 0; i < nrFig; ++i)
		fig[i] = va_arg(figuri, Figura);

	va_end(figuri);
}

void Geometrie::operator=(const Geometrie& other)
{
	nrFiguri = other.nrFiguri;
	delete[] fig;
	fig = new Figura[nrFiguri]{};
	for (int i = 0; i < nrFiguri; ++i)
		fig[i] = other.fig[i];
}

void Geometrie::operator+=(const Punct2D& punct)
{
	fig[nrFiguri - 1] += punct;
}

void Geometrie::operator-=(int nrPct)
{
	fig[nrFiguri - 1] -= nrPct;
}

Geometrie::~Geometrie()
{
	delete[] fig;
}

std::istream& operator>>(std::istream& is, Geometrie& geom)
{
	is >> geom.nrFiguri;
	delete[] geom.fig;
	geom.fig = new Figura[geom.nrFiguri]{};
	for (int i = 0; i < geom.nrFiguri; ++i)
		is >> geom.fig[i];
	return is;
}

std::ostream& operator<<(std::ostream& os, const Geometrie& geom)
{
	os << "Geometria contine " << geom.nrFiguri << " figuri: \n";
	for (int i = 0; i < geom.nrFiguri; ++i)
		os << '\t' << geom.fig[i] << '\n';
	return os;
}
