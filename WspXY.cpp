#pragma once
#include "WspXY.h"


WspXY::WspXY()
{
	x = -1;
	y = -1;
}

WspXY::WspXY(int y, int x)
{
	this->x = x;
	this->y = y;
}

int WspXY::getwX() const
{
	return x;
}

int WspXY::getwY() const
{
	return y;
}

void WspXY::setX(int x)
{
	this->x = x;
}

void WspXY::setY(int y)
{
	this->y = y;
}

inline void WspXY::Wypisz(std::ostream& out) const
{
	out << "(" << y << "," << x << ") ";
}

std::ostream& operator<<(std::ostream& os,const WspXY& wsp)
{
	os << "(" << wsp.getwY() << "," << wsp.getwX() << ") ";
	return os;
}