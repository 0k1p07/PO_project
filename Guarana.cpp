#pragma once
#include "Guarana.h"

Guarana::Guarana(WspXY wsp, Swiat* uni)
{
	id = gatunek(guarana);
	sila = 0;
	inicjatywa = 0;
	wspolrzedne = wsp;
	uniwersum = uni;
	plodnosc = PLODNOSC_GARANY;
	wiek = 0;
}

Guarana::~Guarana() {}

wynik_kolizji Guarana::kolizja(Organizm* wchodzacy)
{
	std::cout << "zjadl " << *this;
	uniwersum->zabijOrganizm(this);
	return wynik_kolizji(bonusDoSily);
}

void Guarana::rysowanie() const
{
	changeColour(KOLOR_G);
	printf("g");
	changeColour(KOLOR_PODSTAWOWY);
}

inline void Guarana::Wypisz(std::ostream& out) const
{
	out << "Guarana Sila(" << sila << ") Wiek(" << wiek << ") XY" << wspolrzedne << " ";
}

Organizm* Guarana::potomek(WspXY wsp)
{
	return new Guarana(wsp, uniwersum);
}