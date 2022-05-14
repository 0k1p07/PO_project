#pragma once
#include "Trawa.h"

Trawa::Trawa(WspXY wsp, Swiat* uni)
{
	id = gatunek(trawa);
	sila = 0;
	inicjatywa = 0;
	wspolrzedne = wsp;
	uniwersum = uni;
	plodnosc = PLODNOSC_TRAWY;
	wiek = 0;
}

Trawa::~Trawa(){}

void Trawa::rysowanie() const
{
	changeColour(KOLOR_T);
	printf("t");
	changeColour(KOLOR_PODSTAWOWY);
}

inline void Trawa::Wypisz(std::ostream& out) const
{
	out << "Trawa Sila(" << sila << ") Wiek(" << wiek << ") XY" << wspolrzedne << " ";
}

Organizm* Trawa::potomek(WspXY wsp)
{
	return new Trawa(wsp, uniwersum);
}