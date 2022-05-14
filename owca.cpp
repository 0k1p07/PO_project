#pragma once
#include "owca.h"


Organizm* Owca::potomek(WspXY wybrane_pole)
{
	return new Owca(wybrane_pole, uniwersum);
}

Owca::Owca(WspXY wsp, Swiat* uni)
{
	id = gatunek(owca);
	sila = 4;
	inicjatywa = 4;
	wspolrzedne = wsp;
	uniwersum = uni;
	plodnosc = PLODNOSC_OWCY;
	wiek = 0;
	tura_ostatniego_rozmozenia = -1;
}

Owca::~Owca() {}

void Owca::rysowanie() const
{
	changeColour(KOLOR_O);
	printf("O");
	changeColour(KOLOR_PODSTAWOWY);
}

inline void Owca::Wypisz(std::ostream& out) const
{
	out << "Owca Sila(" << sila << ") Wiek(" << wiek << ") Inicjatywa(" << inicjatywa << ") XY" << wspolrzedne << " ";
}
