#include "Punct2D.h"

Punct2D::Punct2D()
	:
	x(0),
	y(0)
{
}

Punct2D::Punct2D(int value)
	:
	x(value),
	y(value)
{
}

Punct2D::Punct2D(int _x, int _y)
	:
	x(_x),
	y(_y)
{
}

Punct2D::Punct2D(const Punct2D& other)
	:
	x(other.x),
	y(other.y)
{
}

Punct2D& Punct2D::operator=(const Punct2D& other)
{
	x = other.x;
	y = other.y;
	return *this;
}

Punct2D::~Punct2D()
{
}

std::istream& operator>>(std::istream& is, Punct2D& punct)
{
	is >> punct.x >> punct.y;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Punct2D& punct)
{
	os << "Punctul are coordonatele: (" << punct.x << ", " << punct.y << ").";
	return os;
}

int Punct2D::GetX()
{
	return x;
}

int Punct2D::GetY()
{
	return y;
}

void Punct2D::SetX(int _x)
{
	x = _x;
}

void Punct2D::SetY(int _y)
{
	y = _y;
}

void Punct2D::Set(int _x, int _y)
{
	x = _x;
	y = _y;
}

void Punct2D::Set(const Punct2D& other)
{
	x = other.x;
	y = other.y;
}