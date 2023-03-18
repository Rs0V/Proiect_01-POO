#pragma once

#ifndef PUNCT2D
#define PUNCT2D

#define var_name(var) (#var)

#include <iostream>

class Punct2D
{
	int x, y;
	
public:
	Punct2D();
	Punct2D(int value);
	Punct2D(int _x, int _y);
	Punct2D(const Punct2D& other);

	Punct2D& operator=(const Punct2D& other);

	~Punct2D();

	friend std::istream& operator>>(std::istream& is, Punct2D& punct);
	friend std::ostream& operator<<(std::ostream& os, const Punct2D& punct);

	int GetX();
	int GetY();
	void SetX(int _x);
	void SetY(int _y);
	void Set(int _x, int _y);
	void Set(const Punct2D& other);
};

#endif