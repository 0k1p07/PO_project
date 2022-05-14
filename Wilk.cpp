#pragma once
#include "Wilk.h"

Organizm* Wilk::potomek(WspXY wybrane_pole)
{
	return new Wilk(wybrane_pole, uniwersum);
}

Wilk::Wilk(WspXY wsp, Swiat* uni)
{
	id = gatunek(wilk);
	sila = 9;
	inicjatywa = 5;
	wspolrzedne = wsp;
	uniwersum = uni;
	plodnosc = PLODNOSC_WILKA;
	wiek = 0;
	tura_ostatniego_rozmozenia = -1;
}

Wilk::~Wilk() {}

void Wilk::rysowanie() const
{
	changeColour(KOLOR_W);
	printf("W");
	changeColour(KOLOR_PODSTAWOWY);
}

inline void Wilk::Wypisz(std::ostream& out) const
{
	out << "Wilk Sila(" << sila << ") Wiek(" << wiek << ") Inicjatywa(" << inicjatywa << ") XY"<< wspolrzedne <<" ";
}